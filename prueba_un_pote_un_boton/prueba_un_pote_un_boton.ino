int ent_pote = A1;
int ent_boton = 8;

int pote = 0;
int boton = 0;
int lastboton = 0;

void setup() {

  
  Serial.begin(9600);
  pinMode(ent_pote, INPUT);
  pinMode(ent_boton, INPUT);
}

void loop() {

  pote = analogRead(ent_pote);
  boton = digitalRead(ent_boton);

  if (pote >= 0 and pote < 255) {
    Serial.write(28);
  };
  if (pote >= 255 and pote < 511) {
    
    Serial.write(29);
  };
  if (pote >= 511 and pote < 767) {
    Serial.write(30);
  };
  if (pote >= 767 and pote <= 1023) {
    Serial.write(31);
  };
    if (boton != lastboton) {
    // if the state has changed, increment the counter
    if (boton == HIGH) {
      // if the current state is HIGH then the button went from off to on:

      Serial.println(32);

    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println(0);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  };
