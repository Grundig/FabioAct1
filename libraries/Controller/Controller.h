#ifndef Controller
#define Controller

#include <buzzer.h>
#include <he_sensor.h>


class controller {

protected:
	//Default value for the interval between measurements (in millisec)
	static const int default_check_interval_ms = 1000;
	static const int detection_interval = 200;
	//Now we need variables for the length of time between when we check the Hall Effect Sensor outputs.
	unsigned long check_interval_ms, last_check_time, last_detection_time,current_time;
	//Creates two separate "play_commands" from Kamil's code, which are the case options
	//which define which tone the buzzer plays.
	play_commands command_after_last_check, command_after_current_check;
	he_sensor sensing_unit;
	buzzer action_unit;
	int counter;


public:
	//Default Constructor
	//Sets the values for the current controller input and timers values.

	controller()
	{
		check_interval_ms = default_check_interval_ms;
		last_check_time = 0;
		command_after_last_check = do_nothing;
		command_after_current_check = do_nothing;
	//Defining the current commands to be the do_nothing from Kamil's switch options.
	}

	//Controller with arguments:
	controller(int in_check_interval_ms)
	{
		setup_controller(in_check_interval_ms);
		last_check_time = 0;
		command_after_last_check = do_nothing;
		command_after_current_check = do_nothing;
	}
	
	//Setup with arguments for the system.h that Kamil is doing.
	void setup_controller(int in_check_interval_ms)
	{
		check_interval_ms = abs(in_check_interval_ms);
		last_detection_time = 0;
		counter = 0;
	}

	//Verify if it's time to take a new input measurement.
	bool is_time_to_take_measurement()
	{
		//Checks the current time
		unsigned long current_time = millis();
		if ((current_time - last_check_time) >= check_interval_ms)
		{
			last_check_time = current_time;
			return true;
		}
		else
		{
			return false;
		}
	}
	//Now we begin to issue the actions, depending on the value of the two inputs
	//Our inputs are from the Hall Effect sensors, so we need to include the same names
	//used in the he_sensor.h file. TALK TO GABRIEL!
	int count_detection(int input_A_pin, int input_B_pin)
	{
	
		
		while ((current_time - last_check_time) <= check_interval_ms)
		{
			if ((current_time - last_detection_time) >= detection_interval)
			{
				last_detection_time = current_time;
					bool input_1 = sensing_unit.return_input_1(input_A_pin);
					bool input_2 = sensing_unit.return_input_2(input_B_pin);
				if (input_1 || input_2)
				{
					counter++;

				}
			}
		}
		return counter;
	}
	play_commands issueCommand(int input_A_pin, int input_B_pin)
	{
		//Now we need to avoid making decisions if the time is too early.
		if (is_time_to_take_measurement())
		{
			int counter = count_detection(input_A_pin, input_B_pin);
			//Take the current time as the most recent when a successful measurement was take
			last_check_time = millis();
			//Now we decide which action to take;
			//referring to Kamils switch options based upon the input_1 and input_2 from Gabriels code.
			bool input_1 = sensing_unit.return_input_1(input_A_pin);
			bool input_2 = sensing_unit.return_input_2(input_B_pin);
			
			if (input_1 && !input_2)
			{
				action_unit.detection_signal(detection_left, counter);
				Serial.println("sense input 1");
				return detection_left;
			}
			else if (input_2 && !input_1)
			{
				action_unit.detection_signal(detection_right, counter);
				Serial.println("sense input 2");
				return detection_right;
			}
			else if (input_1 && input_2)
			{
				action_unit.detection_signal(detection_both, counter);
				Serial.println("sense both");
				return detection_both;
			}
			else if (!input_1 && !input_2)
			{
				action_unit.detection_signal(do_nothing);
				Serial.println("sense none");
				return do_nothing;
			}
		}
	}

};

#endif
