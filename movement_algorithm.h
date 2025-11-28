/*
 * Describes the baseline contract for moving the robot.
 */
class movement_algorithm {
public:
  virtual void init();
  virtual void move();

protected:
  int Prev_front_distance = -1;// not initialized

  bool between(int a, int b, int accuracy) {
    return a - accuracy <= b && b <= a + accuracy;
  }

  bool potentially_stuck(int dist_front, int min_dist, int max_dist) {
    return
      dist_front < min_dist
      || between(dist_front, Prev_front_distance, 5)
      || between(Prev_front_distance, dist_front, 5);
  }
};
