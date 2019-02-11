#ifndef system_h
#define system_h

#include <Arduino.h>
#include "..\Buzzer\buzzer.h"
#include "..\Controller\Controller.h" //Joshua's function
#include "..\he_sensor\he_sensor.h" //Gabriel's function
#endif
class the_system{
protected:
	buzzer action_unit;
	controller control_unit;
	he_sensor sensing_unit;
	bool check_all_enabled() {
		bool all_enabled = ((sensing_unit.is_enabled()) && (action_unit.is_enabled()));
		return all_enabled;
		}

public:
	the_system(){  bool all_enabled = check_all_enabled();	}
	//default constructor
	
	void setup_sensing(int right_in_pin, int left_in_pin){
		sensing_unit.setup_he_sensor(right_in_pin, left_in_pin);
	} //runs the setup from sensing unit

	void setup_action(int buzzer_pin){
		action_unit.setup_buzzer(buzzer_pin);
	} //runs the setup from action unit

	void setup_control(int in_delta_input, int in_check_interval_ms){
		control_unit.setup_controller(in_check_interval_ms);
	} //runs the setup from controller unit

	// this is the main function that the system performs
	void execute_system_task(){
		if(control_unit.is_time_to_take_measurement()){
			
			control_unit.issueCommand();
			//runs the main function from the controll
			
			
		}
	}


};
