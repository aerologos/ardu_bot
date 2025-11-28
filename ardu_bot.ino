#include "moments.h"
#include "profiler.h"

#include "movement_algorithm_straight.h" //1. First algorithm to test right after assembly
//#include "movement_algorithm_turner.h"  //2. Second algorithm allowing to check the vehicle's ability to turn
//#include "movement_algorithm_finder.h" //3. Third algorithm allowing the vehicle to decide where to go by itself

movement_algorithm_straight _movement_algorithm;
//movement_algorithm_turner _movement_algorithm;
//movement_algorithm_finder _movement_algorithm;

profiler _profiler;

void setup()
{
  _profiler.init();

  _movement_algorithm.init();
}

void loop()
{
  _movement_algorithm.move();
}
