class buzzer{
protected:
	int tone0, tone1, tone2, tone3;
	bool enabled;
public:
	setup(int buzzerPin){
	//set up tone values and pin mode as well as initialize flag
		int tone0 = 261;
		int tone1 = 523;
		int tone2 = 466;
		int tone3 = 349;
	
		pinMode(buzzerPin, OUTPUT);
	
	}

};

