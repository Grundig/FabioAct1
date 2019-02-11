#include <the_system.h>
//#include <buzzer.h>
//#include <he_sensor.h>
//#include <Controller.h>
the_system system_unit;
int right_in_pin = A0;
int left_in_pin = A1;


void setup() {
  Serial.begin(9600);
  int out_pin = 3;

  int in_delta_input = 250;
  int in_check_interval_ms = 1000;

  system_unit.setup_sensing(right_in_pin, left_in_pin);
  system_unit.setup_action(out_pin);
  system_unit.setup_control(in_delta_input, in_check_interval_ms);

  
}

void loop() {
  Serial.println(right_in_pin);
  Serial.println(left_in_pin);
  int inp1, inp2;
    
    inp1=analogRead(right_in_pin);
    inp2=analogRead(left_in_pin);
  
  // put your main code here, to run repeatedly:
  Serial.println("Input_1:");

    Serial.println(inp1);

    Serial.println("Input_2:");

    Serial.println(inp2);
  system_unit.execute_system_task(right_in_pin, left_in_pin);
  
  Serial.println("============");
  Serial.println();
}
