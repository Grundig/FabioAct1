#ifndef Controller
#define Controller

#include <buzzer.h>
#include <he_sensor.h>
#endif

class controller {

protected:
	//Default value for the interval between measurements (in millisec)
	static const int default_check_interval_ms = 1000;
	//Now we need variables for the length of time between when we check the Hall Effect Sensor outputs.
	unsigned long check_interval_ms, last_check_time, last_detection_time;
	//Creates two separate "play_commands" from Kamil's code, which are the case options
	//which define which tone the buzzer plays.
	play_commands command_after_last_check, command_after_current_check;
	he_sensor sensing_unit;
	buzzer action_unit;

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
		detection_interval = 200;
		last_detection_time = 0;
		counter = 0;
	}

	//Verify if it's time to take a new input measurement.
	boolean is_time_to_take_measurement()
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
	int count_detection()
	{
		while ((current_time - last_check_time) <= check_interval_ms)
		{
			if ((current_time - last_detection_time) >= detection_interval)
			{
				last_detection_time = current_time;
				if (sensing_unit.return_input_1() || sensing_unit.return_input_2())
				{
					counter++;

				}
			}
		}
		return counter;
	}
	play_commands issueCommand()
	{
		//Now we need to avoid making decisions if the time is too early.
		if (is_Time_To_Take_Measurement())
		{
			int counter = count_detection();
			//Take the current time as the most recent when a successful measurement was take
			last_check_time = millis();
			//Now we decide which action to take;
			//referring to Kamils switch options based upon the input_1 and input_2 from Gabriels code.

			if (sensing_unit.return_input_1())
			{
				if (!sensing_unit.return_input_2)
				{
					action_unit.detection_signal(detection_left,counter)
				}
			}
			else if (sensing_unit.return_input_2())
			{
				if (!sensing_unit.return_input_1())
				{
					action_unit.detection_signal(detection_right,counter)
				}
			}
			else if (sensing_unit.return_input_1() && sensing_unit.return_input_2())
			{
				action_unit.detection_signal(detection_both,counter)
			}
			else if (!sensing_unit.return_input_1() && !sensing_unit.return_input_2())
			{
				action_unit.detection_signal(do_nothing)
			}
		}
	}

};