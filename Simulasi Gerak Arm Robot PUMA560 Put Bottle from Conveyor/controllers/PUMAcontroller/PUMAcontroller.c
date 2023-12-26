/*
 * File:          PUMAcontroller.c
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
/*  WbDeviceTag l1 = wb_robot_get_device("joint1");
  WbDeviceTag l2 = wb_robot_get_device("joint2");
  WbDeviceTag l3 = wb_robot_get_device("joint3");
  WbDeviceTag l4 = wb_robot_get_device("joint4");
  WbDeviceTag l5 = wb_robot_get_device("joint5");*/
  WbDeviceTag l6 = wb_robot_get_device("joint6");

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
   
  int counter = 0; 
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
     
   /*  if (counter<30){
       wb_motor_set_position(l1,INFINITY);
         wb_motor_set_velocity(l1,2.0);
       }
       if (counter>=30 && counter<50){
         wb_motor_set_position(l2,INFINITY);
           wb_motor_set_velocity(l2,2.0);
         }
         if (counter>=50 && counter<70){
           wb_motor_set_position(l3,INFINITY);
             wb_motor_set_velocity(l3,2.0);
           }
           if (counter>=70 && counter<90){
             wb_motor_set_position(l4,INFINITY);
               wb_motor_set_velocity(l4,2.0);
             }
             if (counter>=90 && counter<110){
               wb_motor_set_position(l5,INFINITY);
                 wb_motor_set_velocity(l5,2.0);
               }*/
               if (counter>=110 && counter<130){
                 wb_motor_set_position(l6,INFINITY);
                   wb_motor_set_velocity(l6,2.0);
                 }
                 
    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
     counter=counter+1;
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
