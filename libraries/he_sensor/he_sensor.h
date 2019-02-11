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
protected:
	
	in_analog input_1, input_2;
	bool enabled;
	int input_A, input_B;
	
	
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
		
			
			if(!input_2.isInitialized())
				input_2.setup_in_analog(input_2_pin);
		
			if(input_1.isInitialized() && input_2.isInitialized())
				enabled=true;
		}
		
	}

	
	bool return_input_1(int input_A_pin)
	{	
		input_A = analogRead(input_A_pin);
		Serial.print("input A: ");
		Serial.print(input_A_pin);
		Serial.print(" ");
		
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
	
	bool return_input_2(int input_B_pin)
	{
		input_B_pin = 15;
		input_B=analogRead(input_B_pin);
		Serial.print("input B: ");
		Serial.print(input_B_pin);
		Serial.print(" ");
		
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
