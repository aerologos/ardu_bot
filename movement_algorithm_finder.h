/* 
 * Encapsulates the algorithm allowing the vehicle to decide where to go by itself using a distance meter
 */
#include "movement_algorithm.h"
#include "distance_meter_sonar.h"
#include "chasis_two_front_wheels.h"

class movement_algorithm_finder : public movement_algorithm {
public:
  void init() {
    _distance_meter.init();
    _chasis.init();

    Max_distance = _distance_meter.get_max_distance();
    Prev_front_distance = Max_distance / 2;//to avoid rotations on start
    _chasis.stand_still();//CRITICAL! used to stop last chasis move command when board is reloaded by itself.
  }
  
  void move() {
    //delay(500); //simplifies debugging
    _chasis.stand_still();//CRITICAL! used to stop last chasis move command.

    int front_distance = _distance_meter.get_front();
    _profiler.print_status("front_distance", front_distance);
    _profiler.print_status("Prev_front_distance", Prev_front_distance);

    if (potentially_stuck(front_distance, Min_distance, Max_distance)) {
      Stuck_counter++;
      _profiler.print_status("Stuck_counter", Stuck_counter);
    }
    else {
      Stuck_counter = 0;
    }

    if (Stuck_counter == 2) {
      int backward_distance = 20;
      _profiler.print_status("go_backward", backward_distance);

      _chasis.go_backward(backward_distance);
      _chasis.turn_around();

      Stuck_counter = 0;
      return;
    }

    if (front_distance >= Min_distance) {
      int dist_to_move = front_distance * 0.5; // 50% of measured distance to prevent collisions
      _profiler.print_status("go_forward", dist_to_move);
      _chasis.go_forward(dist_to_move);
    }
    else {
      _profiler.print_status("turn_left", 1);
      _chasis.turn_left();
    }

    Prev_front_distance = front_distance;
}

private:
  int Stuck_counter = 0;
  int Min_distance = 10;
  int Max_distance = -1; // evaluated on init

  distance_meter_sonar _distance_meter;
  chasis_two_front_wheels _chasis;
  profiler _profiler;
};