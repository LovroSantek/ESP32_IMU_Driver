#include <stdio.h>
#include <IMU_driver.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

#define SAMPLE_FREQUENCY (50.f)
#define SAMPLE_PERIOD (1.f / SAMPLE_FREQUENCY)

void app_main(void)
{
    IMU_init();
    while(1)
    { 
        float gx = IMU_read_gyro(GYRO_XOUT_H);
        float gy = IMU_read_gyro(GYRO_YOUT_H);
        float gz = IMU_read_gyro(GYRO_ZOUT_H);
        float ax = IMU_read_accel(ACCEL_XOUT_H);
        float ay = IMU_read_accel(ACCEL_YOUT_H);
        float az = IMU_read_accel(ACCEL_ZOUT_H);

        printf("%f, %f, %f\n", ax, ay, az);
        //ESP_LOGI("Acceleration: ", "x = %.3f  y = %.3f  z = %.3f", ax, ay, az);
        //ESP_LOGI("Gyroscope: ", "x = %.3f  y = %.3f  z = %.3f", gx, gy, gz);

        vTaskDelay((int) (1000 * SAMPLE_PERIOD) / portTICK_PERIOD_MS);
    }
    return;
}
