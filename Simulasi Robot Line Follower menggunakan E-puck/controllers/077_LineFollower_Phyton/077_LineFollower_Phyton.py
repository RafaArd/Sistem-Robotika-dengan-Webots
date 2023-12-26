"""077_LineFollower_Phyton controller."""

from controller import Robot
def run_robot(robot):
    time_step=32
    max_speed=6.28
    
    #motors
    motor_kiri=robot.getMotor('left wheel motor')
    motor_kanan=robot.getMotor('right wheel motor')
    motor_kiri.setPosition(float('inf'))
    motor_kanan.setPosition(float('inf'))
    motor_kiri.setVelocity(0.0)
    motor_kanan.setVelocity(0.0)
    
    #enable_sensor
    ir_kiri=robot.getDistanceSensor('sen_kiri')
    ir_kiri.enable(time_step)
    ir_kanan=robot.getDistanceSensor('sen_kanan')
    ir_kanan.enable(time_step)

while robot.step(timestep) != -1:

  #read_sensor
  ir_kiri_value=ir_kiri.getValue()
  ir_kanan_value=ir_kanan.getValue()
  print("kiri: {} kanan: {}".format(ir_kiri_value, ir_kanan_value))
  
    left_speed = max_speed*0.25
    right_speed = max_speed*0.25
    
  if (ir_kiri_value)>(ir_kanan_value) and (6<ir_kiri_value 15):
      print("Belok kiri")
      left_speed=-max_speed*0.25
      
      elif (ir_kiri_value)<(ir_kanan_value) and (6<ir_kanan_value 15):
          print("Belok kanan")
          right_speed=-max_speed*0.25
    
    motor_kiri.setVelocity(left_speed)
    motor_kanan.setVelocity(right_speed)
    
if __name_ == "__main__":
    my_robot = Robot()
    run_robot(my_robot)
    
pass    