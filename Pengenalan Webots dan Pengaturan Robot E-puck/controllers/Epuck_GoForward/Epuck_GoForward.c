/*
 * File:          Epuck_GoForward.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>
#include <stdio.h>
/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define MAX_SPEED 6.28

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();
   WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
   WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
    WbDeviceTag sensor0 = wb_robot_get_device("ps0");
    WbDeviceTag sensor1 = wb_robot_get_device("ps1");
    WbDeviceTag sensor2 = wb_robot_get_device("ps2");
    WbDeviceTag sensor3 = wb_robot_get_device("ps3");
    WbDeviceTag sensor4 = wb_robot_get_device("ps4");
    WbDeviceTag sensor5 = wb_robot_get_device("ps5");
    WbDeviceTag sensor6 = wb_robot_get_device("ps6");
    WbDeviceTag sensor7 = wb_robot_get_device("ps7");
    WbDeviceTag sensor8 = wb_robot_get_device("ps8");
    
    wb_motor_set_position(left_motor, INFINITY);
    wb_motor_set_position(right_motor, INFINITY);
    
    wb_distance_sensor_enable(sensor0, TIME_STEP);
    wb_distance_sensor_enable(sensor1, TIME_STEP);
    wb_distance_sensor_enable(sensor2, TIME_STEP);
    wb_distance_sensor_enable(sensor3, TIME_STEP);
    wb_distance_sensor_enable(sensor4, TIME_STEP);
    wb_distance_sensor_enable(sensor5, TIME_STEP);
    wb_distance_sensor_enable(sensor6, TIME_STEP);
    wb_distance_sensor_enable(sensor7, TIME_STEP);
    wb_distance_sensor_enable(sensor8, TIME_STEP);
    
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
     double sensor0_value = wb_distance_sensor_get_value(sensor0);
     double sensor1_value = wb_distance_sensor_get_value(sensor1);
     double sensor2_value = wb_distance_sensor_get_value(sensor2);
     double sensor3_value = wb_distance_sensor_get_value(sensor3);
     double sensor4_value = wb_distance_sensor_get_value(sensor4);
     double sensor5_value = wb_distance_sensor_get_value(sensor5);
     double sensor6_value = wb_distance_sensor_get_value(sensor6);
     double sensor7_value = wb_distance_sensor_get_value(sensor7);
     double sensor8_value = wb_distance_sensor_get_value(sensor8);
     double velo_left_motor;
     double velo_right_motor;
  
    /* Process sensor data here */
    if(sensor0_value<80 && sensor1_value<80 && sensor2_value<80 && 
    sensor3_value<80 && sensor4_value<80 && sensor5_value<80 && 
    sensor6_value<80 && sensor7_value<80 && sensor8_value<80) {
      velo_left_motor = 5;
      velo_right_motor = 5; }
    else {
      velo_left_motor = 0;
      velo_right_motor = 0;
    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
     //kecepatan motor menggunakan 10% dari kecepatan maksimal
     wb_motor_set_velocity(left_motor, velo_left_motor);
     wb_motor_set_velocity(right_motor, velo_right_motor);
     }
  }

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
