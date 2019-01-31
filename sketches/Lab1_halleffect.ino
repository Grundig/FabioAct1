#include <Basic_Input.h>
#include <Beginner_LED.h>
#include <IntervalCheckTimer.h>

// global-scope variable
in_analog an_inp[2];
ana_LED led[5];

// variable brightness led
//ana_LED variable_LED;

void setup()
{  
  // initialize as input pin (only needed once).
  an_inp[0].setup_in_analog(A0);
  an_inp[1].setup_in_analog(A1);
  
  led[0].setup_LED(3);  
  led[1].setup_LED(5);
  led[2].setup_LED(6);
  led[3].setup_LED(10);  
  led[4].setup_LED(11);
  Serial.begin(9600);
}

void loop()
{
  int waiting_ms=500;
  int inp0, inp1;
  int set_val;
  int led_on;
  if( an_inp[0].read_input(inp0)== true || an_inp[1].read_input(inp1))
  {
    Serial.println("input val");
    Serial.print(inp1);
    Serial.println();
    
   if(inp0<500 || inp1<500){ 
    led[4].switch_off();
    for(int i=0; i<4; i++){
      led[i].switch_on();
      //led[i].set_brightness(set_val);
      };
    delay(waiting_ms);
    
    for(int i=0; i<4; i++){
      led[i].switch_off();
      };
     delay(waiting_ms);
    } else {led[4].switch_on();}
  }
     
}
