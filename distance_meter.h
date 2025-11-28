/*
 * Describes the baseline contract for measuring the distance from the robot to it's front, left and right obstacles.
 */
class distance_meter {
public:
  virtual void init();
  virtual int get_front();
  virtual int get_left();
  virtual int get_right();
  virtual int get_max_distance();
};
