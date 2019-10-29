#include "MorseCode.h"
#include "UserLED.h"

#define BUFFER_SIZE 256
#define SLEEP_UNIT 800000

void blinkSentence(const char* buffer);

void blinkDot();

void blinkDash();

void blinkSpaceLetter();

void blinkSpaceWord();

void sleepForNUnits(const int n);

int main() {

    const char* myName = "Josh";
    char morseCodeBuffer[BUFFER_SIZE] = "\0";
    
    convertTextToMorseCode(myName, morseCodeBuffer);
    
    setupUserLED();
    
    while(1) {
        blinkSentence(morseCodeBuffer);
    }

    return 0;
}

void blinkSentence(const char* buffer) {
    int i = 0;
    while(buffer[i] != '\0') {
        switch(buffer[i]) {
            case '.':
                blinkDot();
                break;
            case '-':
                blinkDash();
                break;
            case '_':
                blinkSpaceLetter();
                break;
            case ' ':
                blinkSpaceWord();
                break;
            default:
                break;
        }
        i++;
    }
    blinkSpaceWord();
}

void blinkDot() {
    turnOnUserLED();
    sleepForNUnits(1);
    turnOffUserLED();
    sleepForNUnits(1);
}

void blinkDash() {
    turnOnUserLED();
    sleepForNUnits(3);
    turnOffUserLED();
    sleepForNUnits(1);
}

void blinkSpaceLetter() {
    sleepForNUnits(2);
}

void blinkSpaceWord() {
    sleepForNUnits(6);
}

void sleepForNUnits(const int n) {
    int i = 0;
    while (i < n * SLEEP_UNIT) {
        i++;
    }
}