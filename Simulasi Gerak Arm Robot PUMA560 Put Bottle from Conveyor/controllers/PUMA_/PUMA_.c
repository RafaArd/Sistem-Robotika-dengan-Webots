/*
 * File:          PUMA_.c
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
#include <stdio.h>
#include <webots/distance_sensor.h>
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
    WbDeviceTag l1 = wb_robot_get_device("joint1");
    WbDeviceTag l2 = wb_robot_get_device("joint2");
    WbDeviceTag l3 = wb_robot_get_device("joint3");
    WbDeviceTag l4 = wb_robot_get_device("joint4");
    WbDeviceTag l5 = wb_robot_get_device("joint5");
    WbDeviceTag l6 = wb_robot_get_device("joint6");
    
    WbDeviceTag bottle = wb_robot_get_device("IR");
    wb_distance_sensor_enable(bottle,TIME_STEP);

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
  int counter=0;
  int status=0;
  while (wb_robot_step(TIME_STEP) != -1) {
    wb_motor_set_position(l1,INFINITY);
    wb_motor_set_position(l2,INFINITY);
    wb_motor_set_position(l3,INFINITY);
    wb_motor_set_position(l4,INFINITY);
    wb_motor_set_position(l5,INFINITY);
    wb_motor_set_position(l6,INFINITY);
    
    wb_motor_set_velocity(l1,0.0);
    wb_motor_set_velocity(l2,0.0);
    wb_motor_set_velocity(l3,0.0);
    wb_motor_set_velocity(l4,0.0);
    wb_motor_set_velocity(l5,0.0);
    wb_motor_set_velocity(l6,0.0);
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
    double sensor = wb_distance_sensor_get_value(bottle);
    printf("%f\n",sensor);
    
    if(sensor<800){
      printf("bottle present");
      status=1;}
      
      if(status==1){
        if(counter<5){
          wb_motor_set_velocity(l1,0.2);
          }        
            if(counter>5 && counter<15){
              wb_motor_set_velocity(l1,0.0);
              wb_motor_set_velocity(l2,-1.0);
              }
                if(counter>15 && counter<40){
                  wb_motor_set_velocity(l2,0.0);
                  wb_motor_set_velocity(l3,1.5);                  
                  }
                    if(counter>40 && counter<45){
                      wb_motor_set_velocity(l3,0.0);
                      wb_motor_set_velocity(l5,1.0);
                      }
                        if(counter>45){
                          wb_motor_set_velocity(l5,0.0);
                          }
          counter=counter+1;                     
    }
        
    /* Process sensor data here */

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
