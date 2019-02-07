#ifndef system_h
#define system_h

#include <Arduino.h>
#include <buzzer.h>
#include <controller.h> //Joshua's function
#include <he_sensor.h> //Gabriel's function

class system{
protected:
	buzzer action_unit;
	controller controll_unit;
	he_sensor sensing_unit;
	bool check_all_enabled() {
		bool all_enabled = ((sensing_unit.is_enabled()) && (action_unit.is_enabled()))
		return all_enabled;
		}

public:
	void setup_sensing(int right_in_pin, int left_in_pin){
		sensing_unit.setup_he_sensor(right_in_pin, left_in_pin);
	}

	void setup_action(int buzzer_pin){
		action_unit.setup_buzzer(buzzer_pin);
	}

	void setup_control(int in_delta_input, int in_check_interval_ms){
		contor_unit.setup_controller(in_delta_input, in_check_interval_ms);
	}



};
