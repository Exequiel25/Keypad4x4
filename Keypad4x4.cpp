/*
    FILE: I2CKeyPad.h
    AUTHOR: Exequiel Magni
    VERSION: 0.0.2
    PURPOSE: Arduino Library for 4x4 Keypad connected to I2C PCF8574
    URL: https://github.com/Exequiel25/I2CKeypad.git
*/

#include "Keypad4x4.h"

Keypad::Keypad(uint8_t *pinesFilas, uint8_t *pinesColumnas, uint8_t filas, uint8_t columnas){
    this->nL = filas;
    this->nC = columnas;
    this->pL = new uint8_t [nL];
    this->pC = new uint8_t [nC];

    for(uint8_t i=0; i<nL; i++) *(pL+i) = *(pinesFilas+i);
    for(uint8_t i=0; i<nC; i++) *(pC+i) = *(pinesColumnas+i);
}

void Keypad::setKeypad(){
    for(uint8_t f=0; f<nL; f++){
        pinMode(pL[f], OUTPUT);
        digitalWrite(pL[f], HIGH);
    }
    for(uint8_t c=0; c<nC; c++) {
        pinMode(pC[c], INPUT_PULLUP);
    } 
}

char Keypad::getKey(){
  static unsigned long t_previo;
  static unsigned long t_hold;
  char key = '\0';
  keyState = "";

  if(millis() - t_previo > 20){
    t_previo = millis();
    //Barrido por las filas
    for(uint8_t i=0; i<nL; i++){
      digitalWrite(pL[i], LOW);
      
      //Barrido en columnas buscando un LOW
      for(uint8_t j=0; j<nC; j++){
        if(digitalRead(pC[j]) == LOW){
          t_hold = t_previo;
          key = keys[i][j];
          keyState = PRESSED;
          while(digitalRead(pC[j]) == LOW){
            if(millis() - t_hold >= 1000){
              keyState = HOLDED;
            }
          }
        }
      }
      digitalWrite(pL[i], HIGH);
    }

    return (key)? key : NO_KEY_PRESSED;
  }
}

char Keypad::getKeyState(){
  if(keyState != PRESSED && keyState != HOLDED) keyState = NO_KEY_PRESSED;
  return keyState;
}
