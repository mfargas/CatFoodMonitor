#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace dnn;
using namespace std;

bool detectPets(const Mat &frame)
{
    // Load YOLO model
    String modelConfiguration = "/home/marjipi/Projects/CatFoodMonitor/models/yolov3.cfg";
    String modelWeights = "/home/marjipi/Projects/CatFoodMonitor/models/yolov3.weights";
    Net net = readNetFromDarknet(modelConfiguration, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    // Prepare input blob
    Mat blob;
    blobFromImage(frame, blob, 1 / 255.0, Size(416, 416), Scalar(0, 0, 0), true, false);
    net.setInput(blob);

    // Run forward pass
    vector<Mat> outs;
    net.forward(outs, net.getUnconnectedOutLayersNames());

    // Process detections
    bool petDetected = false;
    for (size_t i = 0; i < outs.size(); ++i)
    {
        float *data = (float *)outs[i].data;
        for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols)
        {
            Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            Point classIdPoint;
            double confidence;
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > 0.5)
            {
                int centerX = (int)(data[0] * frame.cols);
                int centerY = (int)(data[1] * frame.rows);
                int width = (int)(data[2] * frame.cols);
                int height = (int)(data[3] * frame.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                // Draw bounding box
                rectangle(frame, Point(left, top), Point(left + width, top + height), Scalar(0, 255, 0), 3);
                petDetected = true;
            }
        }
    }
    return petDetected;
}