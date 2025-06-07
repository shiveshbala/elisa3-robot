# elisa3-robot

This project contains Arduino code for the Elisa-3 robot. The code enables the robot to perform various autonomous tasks, including:

* **Line Following:** The robot can detect and follow lines on the ground.
* **Obstacle Avoidance:** The robot can sense and navigate around obstacles in its path.
* **Staying in a Box:** The robot can be programmed to stay within a defined area.

## Hardware

The project utilizes the following key hardware components:

* Elisa-3 robot
* Arduino (or compatible microcontroller)
* Ground sensors (for line following)
* Proximity sensors (for obstacle avoidance)

## Software

The robot's control software is developed for the Arduino platform using C/C++. The project consists of the following `.ino` files:

* `final_code.ino`: This is the main operational code. It likely integrates various functionalities of the robot, potentially selectable via a switch or a predefined sequence, enabling behaviors like line following, obstacle avoidance, or staying in a box.
* `Active_Sensing.ino`: This file probably contains code related to active sensor control, such as emitting infrared signals and processing the received data for obstacle detection or environmental sensing.
* `Line_detection.ino`: This file is dedicated to the logic required for line detection, including reading ground sensor values and determining the line's position relative to the robot.
* `MotorRun.ino`: This file handles the low-level control of the robot's motors, providing functions to move forward, backward, turn, and stop.
* `ObstacleAvoid.ino`: This file implements the obstacle avoidance behavior, using data from proximity sensors to navigate around objects.
* `Proximity.ino`: This file likely deals with reading and processing data from the proximity sensors to detect nearby objects.
* `linevalues.ino`: This file may be used for calibrating the ground sensors, reading raw line sensor values, or storing threshold values for line detection.

## Setup and Usage

### Uploading the Code

1.  **Connect the Elisa-3 robot** to your computer via USB.
2.  Open the Arduino IDE (or a compatible alternative like PlatformIO).
3.  Ensure you have the correct **board selected** in the IDE (usually an Arduino Leonardo or compatible ATmega32U4-based board).
4.  Select the correct **serial port** that the robot is connected to.
5.  Open the `final_code.ino` file (or your main project file if you've structured it differently). The IDE should automatically open other `.ino` files in the same directory as tabs.
6.  Click the **Upload** button in the Arduino IDE. This will compile the code and flash it to the robot's microcontroller.

### Operating the Robot

The robot's behavior is controlled by a physical selector switch. The `SelectorPosition()` function in `final_code.ino` reads the state of this switch. Based on the switch's position, the robot will execute one of the following routines:

*   **Position 1:** Activates the `Linefollow()` function. The robot will attempt to follow a line on the ground using its ground sensors. This function uses ground sensors `line[0]` and `line[3]`.
*   **Position 2:** Activates the `StayBox()` function. The robot will try to stay within a defined area (a "box") presumably marked by lines, using ground sensors `line[1]` and `line[2]`. If it detects a boundary, it will turn to stay inside.
*   **Position 3:** Activates the `Linefollow2()` function. This appears to be an alternative line following routine, possibly using different sensors or logic (it uses ground sensors `line[1]` and `line[2]`).

Refer to the comments in `final_code.ino` and the specific logic within each function (`Linefollow()`, `StayBox()`, `Linefollow2()`) for more detailed operational characteristics.

## Contributing

Contributions to this project are welcome. Please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the terms of the MIT License. See the `LICENSE` file for details.