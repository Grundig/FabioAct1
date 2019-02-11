#ifndef HE_SENSOR_h
#define HE_SENSOR_h

#ifdef COMPILE_CPP_NOT_ARDUINO
#include "..\All_Arduino_or_Cpp_symboldefines\All_Arduino_or_Cpp_symboldefines.h"
#else
#include <Arduino.h>
#endif

#include<Basic_Input.h>

//  ==== sensor ====

class he_sensor{
private:
	
	in_analog input_1, input_2;
	bool enabled;
	int input_A, input_B;
	int input_A_pin, input_B_pin;
	
public:
	// default constructor
	he_sensor() {enabled = false;}
		
	//checks if the unit is enabled
	bool is_enabled() {return enabled;}
	
	void setup_he_sensor(int input_1_pin,int input_2_pin)  // declare the input pins, needed once
	{
		if(!is_enabled())
		{
			if(!input_1.isInitialized())
				input_1.setup_in_analog(input_1_pin);
				input_A_pin= input_1_pin;
			
			if(!input_2.isInitialized())
				input_2.setup_in_analog(input_2_pin);
				input_B_pin= input_2_pin;
				
			if(input_1.isInitialized() && input_2.isInitialized())
				enabled=true;
		}
		
	}
	
	void read_inputs(int input_1_pin, int input_2_pin)   // read the values from the pin
	{
		// assign values to the variables that are going to be used in the next 2 functions.(return_input_1, return_input_2)
		input_A=analogRead(input_1_pin);
		input_B=analogRead(input_2_pin);
	}
	
	bool return_input_1()
	{
		input_A=analogRead(input_A_pin);
		Serial.println(input_A);
		if(input_A <= 500)
		{
			Serial.println("Input 1 high");
			return true;  //input_1 - Magnet detected
		}
			
		else
		{
			Serial.println("Input 1 low");
		 return false;  // input_1 - No magnet
		} 
			
	}
	
	bool return_input_2()
	{
		input_B=analogRead(input_B_pin);
		Serial.println(input_B);
		if(input_B <= 500)
		{
			Serial.println("Input 2 high");
			return true;  //input_2 - Magnet detected
		}
		else
		{
			Serial.println("Input 2 low");
			return false;  //input_2 - No magnet
		 } 
			
	}
	
};


#endif
