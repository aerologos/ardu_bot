/* 
 * Encapsulates the distance measurements based on the ultro-sound distance meter HC-SR04 (Vally eyes) which is installed in front of the vehicle.
 * The distance the HC-SR04 is able to measure is limited by 400 cm.
 */
#include "distance_meter.h"
#include "sonar.h"

class distance_meter_sonar : public distance_meter {
public:
  void init() {
    _sonar.init(Sonar_trig_pin, Sonar_echo_pin);
  }
  
  int get_front() {
    int dist = measure_dist();
    return (dist > Min_dist && dist <= Max_dist)
      ? dist
      : 0;
  }
  
  int get_left() {
    return -1; //invalid call. This distance meter cannot be rotated.
  }
  
  int get_right() {
    return -1; //invalid call. This distance meter cannot be rotated.
  }

  int get_max_distance() {
    return Max_dist;
  }

private:
  int measure_dist() {
    return _sonar.measure_dist(Max_dist);
  }

  sonar _sonar;

  const int Sonar_trig_pin = 13;
  const int Sonar_echo_pin = 12;

  const int Min_dist = 0;
  const int Max_dist = 400;
};
