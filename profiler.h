class profiler {
public:
  void init() {
     Serial.begin(9600); // used for debugging
  }

  void print_status(String name, int value) {
    name.concat(": ");
    name.concat(value);
    Serial.println(name);
  }
};
