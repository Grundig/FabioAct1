#include <Basic_Input.h>

#include <Beginner_LED.h>

#include <he_sensor.h>


// global-scope variable

in_analog an_inp[2];

ana_LED led[5];

he_sensor sense;

// variable brightness led

//ana_LED variable_LED;



void setup()

{  

  // initialize as input pin (only needed once).

  an_inp[0].setup_in_analog(A0);

  an_inp[1].setup_in_analog(A1);


  led[0].setup_LED(13);  
  led[1].setup_LED(11);
  
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

    
  if(sense.return_input_1()== true)
  {
    led[0].switch_on();
    }
  else
  {
    led[0].switch_off();
  }
  if(sense.return_input_2()== true)
  {
    led[1].switch_on();
    }
  else
  {
    led[1].switch_off();
  }
  delay(2000);
  }
