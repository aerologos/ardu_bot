/*
 * Encapsulates the control of the motor connected to the passing pin.
 */
class motor {
public:
  void init(int in1, int in2) {
    _in1 = in1;
    _in2 = in2;

    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
  }

  void spinForward() {
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
  }

  void spinBackward() {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
  }

  void idle() {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
  }
private:
  int _in1, _in2;
};
