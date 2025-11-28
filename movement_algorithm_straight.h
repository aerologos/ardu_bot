/* 
 * Encapsulates the algorithm of the robot that simply goes straight forward to the wall and then backward.
 */
#include "movement_algorithm.h"
#include "distance_meter_sonar.h"
#include "chasis_two_front_wheels.h"

class movement_algorithm_straight : public movement_algorithm {
public:
  void init() {
    _distance_meter.init();
    _chasis.init();

    Max_distance = _distance_meter.get_max_distance();
    _chasis.stand_still();//CRITICAL! used to stop last chasis move command when board is reloaded by itself.
  }
  
  void move() {
    //delay(500); //simplifies debugging
    _chasis.stand_still();//CRITICAL! used to stop last chasis move command.

    int front_distance = _distance_meter.get_front();
    _profiler.print_status("front_distance", front_distance);
    _profiler.print_status("Prev_front_distance", Prev_front_distance);

    int dist_to_move = front_distance * 0.5; // 50% of measured distance to prevent collisions
    if (dist_to_move > 10) {
      _profiler.print_status("go_forward", dist_to_move);
      _chasis.go_forward(dist_to_move);
    }
    else {
      _profiler.print_status("go_backward", Backward_distance);
      _chasis.go_backward(dist_to_move);
    }
}

private:
  int Min_distance = 10;
  int Max_distance = -1; // evaluated on init
  int Backward_distance = 50;

  distance_meter_sonar _distance_meter;
  chasis_two_front_wheels _chasis;
  profiler _profiler;
};