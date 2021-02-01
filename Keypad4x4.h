/*
    FILE: I2CKeyPad.h
    AUTHOR: Exequiel Magni
    VERSION: 0.0.1
    PURPOSE: Arduino Library for 4x4 Keypad connected to I2C PCF8574
    URL: https://github.com/Exequiel25/Keypad.git
*/

#ifndef I2CKeypad_h
#define I2CKeypad_h

#include "Arduino.h"

const char PRESSED = 'P';
const char HOLDED = 'H';
const char NO_KEY_PRESSED = 'N';

class Keypad{
    public:
        Keypad(uint8_t *pinesFilas, uint8_t *pinesColumnas, uint8_t filas, uint8_t columnas);

        void setKeypad();
        char getKey();
        char getKeyState();
    
    private:
        uint8_t nL,nC;
        uint8_t *pL,*pC;
        const char keys[4][4] = {
            {'1','2','3','A'}, 
            {'4','5','6','B'}, 
            {'7','8','9','C'}, 
            {'*','0','#','D'}
        };
        char keyState;
};

#endif
