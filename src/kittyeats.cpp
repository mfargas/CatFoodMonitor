#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/detection.h"
#include "../include/notification.h"

// Function to capture an image using libcamera-still
bool capture_image(const std::string &filename)
{
    std::string command = "libcamera-still -o " + filename + " --width 640 --height 480 --nopreview";
    int result = std::system(command.c_str());
    return (result == 0); // Return true if the command succeeded
}

int main()
{
    std::cout << "Cat Detection Project Initialized" << std::endl;

    // Define the file path where the captured image will be saved
    std::string image_path = "/home/pi/data/captures/cat_capture.jpg";

    // Capture an image
    if (capture_image(image_path))
    {
        std::cout << "Image captured successfully: " << image_path << std::endl;

        // Perform detection on the captured image
        if (detect_cat(image_path))
        {
            std::cout << "Cat detected! Sending notification..." << std::endl;
            send_notification("Cat detected in the frame!");
        }
        else
        {
            std::cout << "No cat detected in the frame." << std::endl;
        }
    }
    else
    {
        std::cerr << "Failed to capture image!" << std::endl;
    }

    return 0;
}