#include <the_system.h>
//#include <buzzer.h>
//#include <he_sensor.h>
//#include <Controller.h>
the_system system_unit;
int right_in_pin = A0;
int left_in_pin = A1;
void setup() {
  // put your setup code here, to run once:
//  int right_in_pin = A1;
 // int left_in_pin = A2;
  int out_pin = 3;

  int in_delta_input = 250;
  int in_check_interval_ms = 1000;

  system_unit.setup_sensing(right_in_pin, left_in_pin);
  system_unit.setup_action(out_pin);
  system_unit.setup_control(in_delta_input, in_check_interval_ms);

  Serial.begin(9600);
}

void loop() {
  
  int inp1, inp2;
    
    inp1=analogRead(right_in_pin);
    inp2=analogRead(left_in_pin);
  
  // put your main code here, to run repeatedly:
  Serial.println("Input_1:");

    Serial.println(inp1);

    Serial.println("Input_2:");

    Serial.println(inp2);
  system_unit.execute_system_task();
  delay(2000);
}
