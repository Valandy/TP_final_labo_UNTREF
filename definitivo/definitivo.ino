// declaracion de pines

int pote1 = A0;
int pote2 = A1;
int pote3 = A2;
int pote4 = A3;

int poteTempo = A5;

int boton1 = 2;
int boton2 = 3;
int boton3 = 4;
int boton4 = 5;

int boton0 = 7;

// valores iniciales

int pote_1 = 0;
int pote_2 = 0;
int pote_3 = 0;
int pote_4 = 0;

int pote_tempo = 0;

// variables para el debounce de los botones (boton 0 = boton de encendido)

int lastButtonState0 = LOW;

int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
int lastButtonState3 = LOW;
int lastButtonState4 = LOW;

int buttonState0;

int buttonState1;
int buttonState2;
int buttonState3;
int buttonState4;

unsigned long debounceDelay0 = 50;

unsigned long debounceDelay1 = 50;
unsigned long debounceDelay2 = 50;
unsigned long debounceDelay3 = 50;
unsigned long debounceDelay4 = 50;

unsigned long lastDebounceTime0 = 0;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(pote1, INPUT);
  pinMode(pote2, INPUT);
  pinMode(pote3, INPUT);
  pinMode(pote4, INPUT);
  
  pinMode(poteTempo, INPUT);
  
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  
  pinMode(boton0, INPUT);

}

void loop() {
    
  int boton_1 = digitalRead(boton1);
  int boton_2 = digitalRead(boton2);
  int boton_3 = digitalRead(boton3);
  int boton_4 = digitalRead(boton4);

  int boton_0 = digitalRead(boton0);

  int ant_pote_1 = pote_1;
  int ant_pote_2 = pote_2; 
  int ant_pote_3 = pote_3;
  int ant_pote_4 = pote_4;

  int ant_pote_tempo = pote_tempo;

  pote_1 = analogRead(pote1);
  pote_2 = analogRead(pote2);
  pote_3 = analogRead(pote3);
  pote_4 = analogRead(pote4);

  pote_tempo = analogRead(poteTempo);

  pote_1 = map(pote_1,0,1023,4,9);
  pote_2 = map(pote_2,0,1023,11,16);
  pote_3 = map(pote_3,0,1023,18,23);
  pote_4 = map(pote_4,0,1023,24,29);

  pote_tempo = map(pote_tempo, 0, 1023, 60 ,250);


// POTES

  if (pote_1 != ant_pote_1) {
    Serial.write(pote_1);
  }
  if (pote_2 != ant_pote_2) {
    Serial.write(pote_2);
  }  
  if (pote_3 != ant_pote_3) {
    Serial.write(pote_3);
  }
  if (pote_4 != ant_pote_4) {
    Serial.write(pote_4);
  }
  if (pote_tempo != ant_pote_tempo) {
    Serial.write(pote_tempo);
  } 


// BOTON DE ENCENDIDO

  if (boton_0 != lastButtonState0) {
    lastDebounceTime0 = millis();
  }

  if ((millis() - lastDebounceTime0) > debounceDelay0) {
   
    if (boton_0 != buttonState0) {
      buttonState0 = boton_0;
      
      if (buttonState0 == HIGH) {
        Serial.write(1);
      }
    }
  }

// MODULO 1

  if (boton_1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay1) {
   
    if (boton_1 != buttonState1) {
      buttonState1 = boton_1;
      
      if (buttonState1 == HIGH) {
        Serial.write(3);
      }
    }
  }

// MODULO 2
  
    if (boton_2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay2) {
   
    if (boton_2 != buttonState2) {
      buttonState2 = boton_2;
      
      if (buttonState2 == HIGH) {
        Serial.write(10);
      }
    }
  }

// MODULO 3
  
    if (boton_3 != lastButtonState3) {
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime3) > debounceDelay3) {
   
    if (boton_3 != buttonState3) {
      buttonState3 = boton_3;
      
      if (buttonState3 == HIGH) {
        Serial.write(17);
      }
    }
  }

// MODULO 4
  
  if (boton_4 != lastButtonState4) {
    lastDebounceTime4 = millis();
  }

    if ((millis() - lastDebounceTime4) > debounceDelay4) {
   
      if (boton_4 != buttonState4) {
        buttonState4 = boton_4;
      
        if (buttonState4 == HIGH) {
          Serial.write(24);
      }
    }
  }

  
  lastButtonState0 = boton_0;
  lastButtonState1 = boton_1;
  lastButtonState2 = boton_2;
  lastButtonState3 = boton_3;
  lastButtonState4 = boton_4;
  
}
