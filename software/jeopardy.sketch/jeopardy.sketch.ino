const int userCount = 4;

const int resetButton = 0;

int winner = -1;

const int buttonUsers[] = {
  3, 5, 7, 9
}; 

const int buttonLEDUser[] = {
  2, 4, 6, 8
};

const int ledUser[] = {
  10, 11, 12, 13
};

void initialisePINs() {
  pinMode( resetButton, INPUT);
  for(int i=0; i < userCount; i++){
    pinMode( buttonUsers[i],   INPUT);
    pinMode( buttonLEDUser[i], OUTPUT);
    pinMode( ledUser[i],       OUTPUT);
  }
}

void flashAllLEDs() {
  for(int i=0; i < userCount; i++) { 
    digitalWrite( buttonLEDUser[i], HIGH ); 
    digitalWrite( ledUser[i], HIGH );
  }
  delay(300);
  for(int i=0; i < userCount; i++) { 
    digitalWrite( buttonLEDUser[i], LOW ); 
    digitalWrite( ledUser[i], LOW );
  }
}


void startRound() {
  //Serial.println("GO GO GO!");
  flashAllLEDs();
  winner = -1;
}

void setup() {
  Serial.begin(9600);
  //Serial.println("Setup");
  pinMode( resetButton, INPUT );
  initialisePINs();
  flashAllLEDs();
  delay(140);
  flashAllLEDs();
  startRound();
}

void loop() {
  for(int i=0; i < userCount; i++){
    if(winner == -1){
      if(digitalRead(buttonUsers[i])){
        winner = i;
        Serial.println(winner);
	      digitalWrite(buttonLEDUser[i], HIGH);
		    digitalWrite(ledUser[i], HIGH);
      }
    }
  }
}
