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
bool clignotementActif = false;

void setup()
{
  Serial.begin(115200);

  // Configuration de la DEL1
  pinMode(BROCHE_DEL1, OUTPUT);
  digitalWrite(BROCHE_DEL1, LOW);

  // Configuration de la DEL2
  pinMode(BROCHE_DEL2, OUTPUT);
  digitalWrite(BROCHE_DEL2, LOW);

  // Configuration du bouton1
  bouton1.attach(BROCHE_BTN1, INPUT_PULLUP);
  bouton1.setPressedState(LOW);                      

  // Configuration du bouton2
  bouton2.attach(BROCHE_BTN2, INPUT_PULLUP);
  bouton2.setPressedState(LOW);
  
}

void loop()
{
  bouton1.update();
  bouton2.update();

  if (bouton1.isPressed())
  {
    digitalWrite(BROCHE_DEL1, HIGH);
  }
  else
    {
        digitalWrite(BROCHE_DEL1, LOW);
    }

  if (bouton2.pressed()) {
    if(clignotementActif == 0){
            clignotementActif = 1;
            etatDel2 = 1;
        } else {
            clignotementActif = 0;
            etatDel2 = 0;
        }
    digitalWrite(BROCHE_DEL2, etatDel2);
  }
}
