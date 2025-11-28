/* 
 * Encapsulates the algorithm of the robot that allows to check the vehicle's ability to turn
 */
#include "movement_algorithm.h"
#include "distance_meter_sonar.h"
#include "chasis_two_front_wheels.h"

class movement_algorithm_turner : public movement_algorithm {
public:
  void init() {
    _chasis.init();

    _chasis.stand_still();//CRITICAL! used to stop last chasis move command when board is reloaded by itself.
  }
  
  void move() {
    //delay(500); //simplifies debugging
    _chasis.stand_still();//CRITICAL! used to stop last chasis move command.

    _chasis.go_forward(dist_to_move);
    
    if (turn_flag < 4) {
      _chasis.turn_right();
    }
    else {
      _chasis.turn_left();
    }

    turn_flag++;
    if (turn_flag > 7) {
      turn_flag = 0;
    }
}

private:
  chasis_two_front_wheels _chasis;
  const int dist_to_move = 30;
  int turn_flag = 0;
};