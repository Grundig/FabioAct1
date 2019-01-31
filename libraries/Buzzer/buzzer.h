
enum play_commands{detectionLeft, detectionRight, detectionBoth, doNothing};

class buzzer{
protected:
	int reset = -1;
	int tone0 = 261;
	int tone1 = 523;
	int tone2 = 466;
	int tone3 = 349;
	int duration;
	bool enabled;
	
public:
	buzzer_setup(){ enabled = false; }
	
	buzzer_setup(int buzzerPin){
	//set up pin mode as well as initialize flag
		pinMode(buzzerPin, OUTPUT);
		enabled = true;	
	}
	
	play_tone(outTone){
		tone(buzzerPin, outTone, duration)
	}
	
	detection_signal(play_commands detection){
		switch(detection){
			case detectionLeft:
				play_tone(tone1);
				play_tone(tone0);				
				play_tone(reset);
			case detectionRight:
				play_tone(tone2);
				play_tone(tone0);
				play_tone(reset);
			case detectionBoth:
				play_tone(tone3);
				play_tone(tone0);
				play_tone(reset);
			case doNothing:
				play_tone(reset);
		}
		
	}

};

