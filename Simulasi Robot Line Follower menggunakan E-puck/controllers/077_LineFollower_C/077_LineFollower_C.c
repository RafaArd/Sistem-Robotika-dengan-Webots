/*
 * File:          077_LineFollower_C.c
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
#include <webots/distance_sensor.h>
#include <stdio.h>
/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
  WbDeviceTag motor_kanan = wb_robot_get_device("right wheel motor");
  WbDeviceTag motor_kiri = wb_robot_get_device("left wheel motor");
  WbDeviceTag sensor_kanan = wb_robot_get_device("sen_kanan");
  WbDeviceTag sensor_kiri = wb_robot_get_device("sen_kiri");
  wb_distance_sensor_enable(sensor_kanan,TIME_STEP);
  wb_distance_sensor_enable(sensor_kiri,TIME_STEP);
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
   wb_motor_set_position(motor_kanan,INFINITY);
   wb_motor_set_position(motor_kiri,INFINITY);
   
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
     double ir_kanan=wb_distance_sensor_get_value(sensor_kanan);
     double ir_kiri=wb_distance_sensor_get_value(sensor_kiri);

    /* Process sensor data here */
    if (ir_kiri>ir_kanan){
      wb_motor_set_velocity(motor_kanan, 2.0);
      wb_motor_set_velocity(motor_kiri, 1.0);}
        if (ir_kiri<ir_kanan){
          wb_motor_set_velocity(motor_kanan, 1.0);
          wb_motor_set_velocity(motor_kiri, 2.0);}

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
