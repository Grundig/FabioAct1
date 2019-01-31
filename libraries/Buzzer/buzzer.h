
enum play_commands{detection_left, detection_right, detection_both, no_detections, do_nothing};

class buzzer{
protected:
	int reset = -1; //buzzer off
	int tone0 = 261; //sound frequency in Hz
	int tone1 = 523;
	int tone2 = 466;
	int tone3 = 349;
	int play_time = 250; //sound length in ms
	bool enabled;
	
public:
	buzzer_setup(){ enabled = false; }
	
	buzzer_setup(int buzzer_pin){
	//set up pin mode as well as initialize flag
		pinMode(buzzer_pin, OUTPUT);
		enabled = true;	
	}
	
	bool is_enabled(){ return enabled; }
	
	//action function
	void play_tone(out_tone, int detections = 1){
		if ( is_enabled() ){	
			int duration = play_time * detections;
			tone(buzzer_pin, out_tone, duration);
		}
	}
	
	// this is the main function you call to signal detections.
	// it can be called with just command type (detection_left for part one)
	// for part two you count the number of detections and put it as the second argument.
	 
	void detection_signal(play_commands detection, int detections = 1){
		if ( is_enabled() ){
			switch(detection){
				case detection_left:
					play_tone(tone1, detections);
					play_tone(tone0);				
					play_tone(reset);
					break;
				case detection_right:
					play_tone(tone2, detections);
					play_tone(tone0);
					play_tone(reset);
					break;
				case detection_both:
					play_tone(tone3, detections);
					play_tone(tone0);
					play_tone(reset);
					break;
				case no_detections:
					play_tone(tone0);
					play_tone(reset);
					break;
				case do_nothing:
					play_tone(reset);
				default:
					break;
			}
		}
	}

};

