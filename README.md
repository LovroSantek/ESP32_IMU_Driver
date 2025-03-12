# IMU Driver for ICM-20948

## Overview
This project provides a driver for the ICM-20948 Inertial Measurement Unit (IMU) sensor. The driver enables SPI communication with the sensor and includes functions to initialize the IMU, read acceleration, and read gyroscopic data.

## Features
- **IMU Initialization**: Configures SPI communication and wakes up the sensor.
- **Acceleration Data Reading**: Reads acceleration values from the sensor.
- **Gyroscope Data Reading**: Reads angular velocity values from the sensor.
- **SPI Communication**: Handles low-level SPI transactions to interact with the IMU.

## Hardware Requirements
- ESP32 microcontroller
- ICM-20948 IMU sensor
- SPI interface with the following pin configuration:
  - MISO: GPIO 19
  - MOSI: GPIO 23
  - SCLK: GPIO 18
  - CS: GPIO 5

## Software Requirements
- ESP-IDF framework
- SPI driver library from ESP-IDF

## Installation
1. Clone or download the repository.
2. Include the `imu_driver.h` and `imu_driver.c` files in your ESP-IDF project.
3. Configure the SPI interface according to the provided pin definitions.

## Usage
### Initialization
Before using the driver, initialize the IMU with:
```c
IMU_status_t status = IMU_init();
if (status != IMU_INIT_SUCCESS) {
    printf("IMU initialization failed!\n");
}
```

### Reading Accelerometer Data
To read acceleration values from a specific axis:
```c
float accel_x = IMU_read_accel(ACCEL_XOUT_H);
float accel_y = IMU_read_accel(ACCEL_YOUT_H);
float accel_z = IMU_read_accel(ACCEL_ZOUT_H);
```

### Reading Gyroscope Data
To read angular velocity values from a specific axis:
```c
float gyro_x = IMU_read_gyro(GYRO_XOUT_H);
float gyro_y = IMU_read_gyro(GYRO_YOUT_H);
float gyro_z = IMU_read_gyro(GYRO_ZOUT_H);
```

## API Reference
### `IMU_status_t IMU_init()`
Initializes the IMU sensor and SPI communication.

### `float IMU_read_accel(uint8_t accel_out_address)`
Reads and returns the acceleration value (g units) from the specified register.

### `float IMU_read_gyro(uint8_t gyro_out_address)`
Reads and returns the angular velocity (degrees per second) from the specified register.


## Author
Lovro Šantek, March, 2025.

