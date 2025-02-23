#ifndef YOLO_H
#define YOLO_H

#include <opencv2/opencv.hpp>

bool detectPets(const cv::Mat &frame);

#endif // YOLO_H