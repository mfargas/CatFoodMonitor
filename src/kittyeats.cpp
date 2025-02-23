#include <cstdlib>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <thread>
#include <chrono>
#include "../include/detection.h"
#include "../include/notification.h"
#include "yolo.h" // Include the header for yolo.cpp

using namespace cv;

int main()
{
    std::cout << "Cat Detection Project Initialized" << std::endl;

    // Open the camera using libcamera-vid
    std::string command = "libcamera-vid --inline --width 640 --height 480 -t 0 --codec yuv420 --output -";
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Error: Could not open camera" << std::endl;
        return -1;
    }

    // Create a window to display the frames
    namedWindow("Live Feed", WINDOW_AUTOSIZE);

    Mat yuv_frame(Size(640, 480), CV_8UC2);
    Mat bgr_frame;
    while (true)
    {
        // Read a frame from the pipe
        size_t bytes_read = fread(yuv_frame.data, 1, 640 * 480 * 2, pipe);
        if (bytes_read != 640 * 480 * 2)
        {
            std::cerr << "Error: Could not read frame from pipe" << std::endl;
            break;
        }

        // Convert YUV420 to BGR
        cvtColor(yuv_frame, bgr_frame, COLOR_YUV2BGR_YUY2);

        // Perform detection on the captured frame
        if (detectPets(bgr_frame))
        {
            // Save the image with detections
            std::string image_path = "/home/pi/data/cat_capture.jpg";
            imwrite(image_path, bgr_frame);
            std::cout << "Pet detected! Image saved: " << image_path << std::endl;

            // Send notification
            send_notification("Pet detected in the frame!");

            // Break the loop after detection
            break;
        }

        // Display the frame
        imshow("Live Feed", bgr_frame);

        // Check for 'q' key press to stop the program
        if (waitKey(1) == 'q')
        {
            std::cout << "Program terminated by user." << std::endl;
            break;
        }
    }

    // Close the pipe and destroy the window
    pclose(pipe);
    destroyWindow("Live Feed");

    return 0;
}