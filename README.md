# Cat Detection Project

A C++ project for detecting when a cat is near a camera, capturing an image, and optionally sending a notification when activity is detected. This project is designed to run on a Raspberry Pi with a PiCamera and uses the **libcamera** library for camera control, as well as **OpenCV** for image processing.

---

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Future Enhancements](#future-enhancements)

---

## Project Overview

The Cat Detection Project captures images using a PiCamera whenever it detects motion or a trigger, processes the image for cat detection, and sends a notification if a cat is detected. This setup is ideal for pet monitoring and can be customized for various types of detection and notification systems.

---

## Features

- **Image Capture**: Uses the `libcamera-still` command-line tool for capturing images with a PiCamera.
- **Cat Detection Logic**: Processes captured images to detect the presence of a cat (or other objects).
- **Notification System**: Sends a notification when a cat is detected (placeholder logic provided, with options for email or push notification).

---

## Project Structure

The project is organized into the following structure:

CatDetectionProject/ │ ├── src/ │ ├── main.cpp # Main program file, initializes camera, detection, and notification │ ├── detection.cpp # Cat detection functionality │ └── notification.cpp # Notification functionality (e.g., send email or push notification) │ ├── include/ │ ├── detection.h # Header for detection functionality │ └── notification.h # Header for notification functionality │ ├── data/ │ └── captures/ # Directory for storing captured images │ ├── CMakeLists.txt # CMake configuration file └── README.md # Project README with setup and usage instructions


---

## Requirements

- **Raspberry Pi** (preferably with Raspberry Pi OS Bullseye or later)
- **PiCamera** (with `libcamera` support)
- **C++17** or later
- **Libraries**:
  - **libcamera**: For accessing the PiCamera.
  - **OpenCV**: For image processing.
  - **CMake**: For building the project.

---

## Installation

1. **Update System**:
   ```bash
   sudo apt-get update
2. Install Dependencies: Install CMake, libcamera, and OpenCV:
    ```bash
    sudo apt-get install cmake libcamera-dev libopencv-dev
3. Navigate to the project directory and create a build folder:
    ```bash
    mkdir build
    cd build
4. Run CMake and compile:
    ```bash
    cmake ..
    make

---

## Usage

1. Run the Program: Once compiled, you can run the program as follows:
    ```bash
    ./CatDetectionProject
2. Image Capture:
- The program will use the libcamera-still command to capture an image and save it to data/captures/cat_capture.jpg.
3. Detection:
- The program will run a basic detection on the captured image. Customize the detect_cat function in detection.cpp for specific detection logic.
4. Notification:
- If a cat is detected, the program will send a placeholder notification. Modify notification.cpp to integrate with an actual notification service (e.g., email or Pushover).

---

## Future Enhancements

- Advanced Cat Detection: Implement a machine learning model for improved cat detection.
- Real-Time Monitoring: Use libcamera and OpenCV for real-time monitoring and detection.
- Enhanced Notifications: Integrate a service like Pushover or SMTP email for real-time alerts.
- Web Interface: Develop a web-based dashboard for remote monitoring and viewing captured images.

---

## Troubleshoot

- Cannot find libcamera: Ensure that libcamera-dev is installed and try running sudo ldconfig.
- "Fatal error: detection.h": Ensure that the correct file path, including parent folders
- OpenCV Errors: Check that libopencv-dev is installed and that CMakeLists.txt includes ${OpenCV_INCLUDE_DIRS} and ${OpenCV_LIBS}.
