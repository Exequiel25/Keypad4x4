#include "Keypad4x4.h"

const byte pinesFilas[] = {9,8,7,6}; 
const byte pinesColumnas[] = {5,4,3,2};

Keypad keypad = Keypad(pinesFilas, pinesColumnas, sizeof(pinesFilas), sizeof(pinesColumnas));

void setup(){
    Serial.begin(9600);

    keypad.setKeypad();
}

void loop(){
    char key = keypad.getKey();
    
    if(key)
    {
    Serial.print("TECLA: ");
    Serial.println(key);
    }
}
