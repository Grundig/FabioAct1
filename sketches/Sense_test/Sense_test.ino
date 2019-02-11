#include <Beginner_LED.h>
#include <he_sensor.h>

// global-scope variable

dig_LED led1, led2;
he_sensor sense, an_inp;

void setup()
{  
  // initialize as input pin (only needed once).
  sense.setup_he_sensor(A0,A1);
  
  led1.setup_LED(13);  
  led2.setup_LED(12);
  
  Serial.begin(9600);
}

void loop()
{
    int inp1, inp2;
    
    inp1=analogRead(A0);
    inp2=analogRead(A1);

    Serial.println("Input_1:");

    Serial.println(inp1);

    Serial.println("Input_2:");

    Serial.println(inp2);
    
  sense.read_inputs(A0,A1);

  if(sense.return_input_1() == true)
  {
    led1.switch_on();
  }
  else
  {
    led1.switch_off();
  }

  if(sense.return_input_2() == true)
  {
    led2.switch_on();
    }
  else
  {
    led2.switch_off();
  }
  delay(2000);
}
