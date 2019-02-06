#ifndef SENSOR_h
#define SENSOR_h

#ifdef COMPILE_CPP_NOT_ARDUINO
#include "..\All_Arduino_or_Cpp_symboldefines\All_Arduino_or_Cpp_symboldefines.h"
#else
#include <Arduino.h>
#endif

// ==== analog input ===
class in_analog{
private:	
	int AnalogPin;
	boolean initialized;
	//		
public:
	in_analog(){AnalogPin=-1; initialized=false;}
	in_analog(int in_Pin) {AnalogPin=-1; initialized=false; setup_in_analog(in_Pin);} 
	void setup_in_analog(int in_Pin)
	{
		if(in_Pin>=0)
		{
			AnalogPin=in_Pin;
			initialized=true;
		}
	}
	inline boolean isInitialized() {return initialized;}
	inline boolean read_input(int& val)
	{
		boolean success=false;
		val=-1;
		if(initialized)
		{
			val=analogRead(AnalogPin);// range is: [0 , 1023]
			success=true;
		}
		return success;
	}
};

//  ==== sensor ====

class he_sensor{
private:
	
	in_analog input_1, input_2;
	boolean enabled;
	
public:
	// default constructor
	he_sensor() {enabled = false;}
		
	//checks if the unit is enabled
	boolean isEnabled() {return enabled;}
	
	void setup_he_sensor(int input_1_pin, int input_2_pin)  // declare the input pins
	{
		if(!isEnabled())
		{
			if(!input_1.isInitialized())
				input_1.setup_in_analog(input_1_pin);
			
			if(!input_2.isInitialized())
				input_2.setup_in_analog(input_2_pin);
				
			if(input_1.isInitialized() && input_2.isInitialized())
				enabed=true;
		}
	}
	
	boolean read_inputs(int& input_A, int& input_B)   // read the values from the pin
	{
		boolean success_input_1=input_1.read_input(input_A);
		boolean success_input_2=input_2.read_input(input_B);
		
		return (success_input_1 && success_input_2);  // used to assign the values to the variables
	}
	
	boolean return_input_1()
	{
		input_A1=success_input_1;
		if(input_A1<= 500)
			return true;  //input_1 - Magnet detected
		else 
			return false;  // input_1 - No magnet
	}
	
	boolean return_input_2()
	{
		input_B2=success_input_2;
		if(input_B2<= 500)
			return true;  //input_2 - Magnet detected
		else 
			return false;  //input_2 - No magnet
	}
	
};


#endif