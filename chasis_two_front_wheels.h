/* 
 * Encapsulates the control of the chasis based on 2 independent front wheels.
 * Front wheels are spinning to the oposite sides, therefore we can go in different directions.
 */
#include "chasis.h"
#include "motor.h"

class chasis_two_front_wheels : public chasis {
public:
  // Sets up the used pins for motors and for their speed.
  void init() {
    front_left_motor.init(front_left_motor_pin1, front_left_motor_pin2);
    front_right_motor.init(front_right_motor_pin1, front_right_motor_pin2);
    
    pinMode(Left_motor_speed_pin, OUTPUT);
    pinMode(Right_motor_speed_pin, OUTPUT);

    set_normal_speed();
  }

  void stand_still() {
    front_left_motor.idle();
    front_right_motor.idle();
  }
  
  void go_forward(double distance) {    
    int time_for_move = calculate_time_for_direct_move(distance);
    forward();
    delay(time_for_move);
  }
  
  void go_backward(double distance) {
    int time_for_move = calculate_time_for_direct_move(distance);
    backward();
    delay(time_for_move);
  }
  
  void go_left() {
    left();
    delay(Time_for_10cm);
  }
  
  void go_right() {
    right();
    delay(Time_for_10cm);
  }
  
  void go_forward_left() {
    forward_left();
    delay(Time_90 / 9);
  }
  
  void go_forward_right() {
    forward_right();
    delay(Time_90 / 9);
  }
  
  void turn_left() {
    left();
    delay(Time_90);
  }
  
  void turn_right() {
    right();
    delay(Time_90);
  }

  void turn_around() {
    front_left_motor.spinForward();
    front_right_motor.spinBackward();
    delay(1000);
  }

  void set_normal_speed() {
    analogWrite(Left_motor_speed_pin, Normal_speed);
    analogWrite(Right_motor_speed_pin, Normal_speed + 13);// for some reason right motor is spinning slower
  }

  void set_max_speed() {
    analogWrite(Left_motor_speed_pin, Max_speed);
    analogWrite(Right_motor_speed_pin, Max_speed + 18);// for some reason right motor is spinning slower
  }

private:
  // The pins our motors are connected to.
  const int front_left_motor_pin1 = 2, front_left_motor_pin2 = 4;
  const int front_right_motor_pin1 = 7, front_right_motor_pin2 = 8;
  
  // The speed of the motor depends on the value that was passed to the analogWrite function.
  // Remember the value of 'Normal_speed' can be between 0 and 255. 
  // If you pass 0, then the motors will stop and if you pass 255 then they will run at full speed.
  const int Left_motor_speed_pin = 3;
  const int Right_motor_speed_pin = 6;
  const int Normal_speed = 90;//180 for two wheels is to much. Tests showed that 90 is good.
  const int Max_speed = 200;//180 for two wheels is to much. Tests showed that 90 is good.

  const int Time_for_start_moving = 100;
  const int Time_for_1cm = 5;
  const int Time_for_10cm = 220;
  
  motor front_left_motor, front_right_motor;

  int calculate_time_for_direct_move(double distance) {
    return Time_for_start_moving + distance * Time_for_1cm;
  }
  
  void forward() {
    front_left_motor.spinForward();
    front_right_motor.spinForward();
  }
  
  void forward_left() {
    front_left_motor.idle();
    front_right_motor.spinForward();
  }
  
  void forward_right() {
    front_left_motor.spinForward();
    front_right_motor.idle();
  }
  
  void left() {
    front_left_motor.spinBackward();
    front_right_motor.spinForward();
  }
  
  void right() {
    front_left_motor.spinForward();
    front_right_motor.spinBackward();
  }
  
  void backward() {
    front_left_motor.spinBackward();
    front_right_motor.spinBackward();
  }
  
  void backward_left() {
    front_left_motor.spinBackward();
    front_right_motor.idle();
  }
  
  void backward_right() {
    front_left_motor.idle();
    front_right_motor.spinBackward();
  }
};
