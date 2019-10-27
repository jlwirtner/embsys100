#include <stdio.h>
#include "MorseCode.h"

#define BUFFER_SIZE 256
#define SLEEP_UNITS 100000000

void blinkSentence(const char* buffer);

void blinkDot();

void blinkDash();

void blinkSpaceLetter();

void blinkSpaceWord();

void sleepForNUnits(const int n);

int main() {

    const char* myName = "Joshua Lee Wirtner";
    char morseCodeBuffer[BUFFER_SIZE];

    convertTextToMorseCode(myName, morseCodeBuffer);

    while(1) {
        blinkSentence(morseCodeBuffer);
    }

    return 0;
}

void blinkSentence(const char* buffer) {
    size_t i = 0;
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
    printf(".");
    fflush(stdout);
    sleepForNUnits(1);
}

void blinkDash() {
    printf("-");
    fflush(stdout);
    sleepForNUnits(1);
}

void blinkSpaceLetter() {
    printf(" ");
    fflush(stdout);
    sleepForNUnits(2);
}

void blinkSpaceWord() {
    printf("\n");
    fflush(stdout);
    sleepForNUnits(6);
}

void sleepForNUnits(const int n) {
    int i = 0;
    while (i < n * SLEEP_UNITS) {
        i++;
    }
}