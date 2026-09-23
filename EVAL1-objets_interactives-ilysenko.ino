#include <Arduino.h> 
#include <Bounce2.h> 
#include <Chrono.h> 

Bounce2::Button bouton1; 
Bounce2::Button bouton2; 

#define BROCHE_BTN1 6
#define BROCHE_BTN2 8
#define BROCHE_DEL1 5
#define BROCHE_DEL2 7

Chrono chrono1;
Chrono chrono2;

bool etatDel = LOW;
bool etatDel2 = LOW;

void setup()
{
  Serial.begin(115200);

  bouton1.setPressedState(LOW);               
  bouton1.attach(BROCHE_BTN1, INPUT_PULLUP);   
  bouton1.interval(5);                         

  bouton2.setPressedState(LOW);
  bouton2.attach(BROCHE_BTN2, INPUT_PULLUP);
  bouton2.interval(5);

  pinMode(BROCHE_DEL1, OUTPUT);
  digitalWrite(BROCHE_DEL1, etatDel);

  pinMode(BROCHE_DEL2, OUTPUT);
  digitalWrite(BROCHE_DEL2, etatDel2);
}

void loop()
{
  bouton1.update();
  bouton2.update();

  if (bouton1.isPressed())
  {
    etatDel = !etatDel;
    
    Serial.print("bouton1 ");
    if (etatDel == true) {
      Serial.print(1);
    } else {
      Serial.print(0);
    }
    Serial.println();

    digitalWrite(BROCHE_DEL1, etatDel);
  }

  if (bouton2.pressed()) {
    etatDel2 = !etatDel2; 
    
    Serial.print("bouton2 ");
    if (etatDel2 == true) {
      Serial.print(1);
    } else {
      Serial.print(0);
    }
    Serial.println();

    digitalWrite(BROCHE_DEL2, etatDel2);
  }
}
