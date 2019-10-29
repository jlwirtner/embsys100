#include <string.h>

#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define ENABLE_AHB1 0x1

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ODR5 0x20

#define MODE5_OUTPUT 0x400

#define BUFFER_SIZE 256
#define SLEEP_UNIT 800000

const char morseA[] = ".-";

const char morseB[] = "-...";

const char morseC[] = "-.-.";

const char morseD[] = "-..";

const char morseE[] = ".";

const char morseF[] = "..-.";

const char morseG[] = "--.";

const char morseH[] = "....";

const char morseI[] = "..";

const char morseJ[] = ".---";

const char morseK[] = "-.-";

const char morseL[] = ".-..";

const char morseM[] = "--";

const char morseN[] = "-.";

const char morseO[] = "---";

const char morseP[] = ".--.";

const char morseQ[] = "--.-";

const char morseR[] = ".-.";

const char morseS[] = "...";

const char morseT[] = "-";

const char morseU[] = "..-";

const char morseV[] = "...-";

const char morseW[] = ".--";

const char morseX[] = "-..-";

const char morseY[] = "-.--";

const char morseZ[] = "--..";

const char morseSpaceLetter[] = "_";

const char morseSpaceWord[] = " ";

void convertTextToMorseCode(const char* str, char* buffer);

void setupUserLED();

void turnOnUserLED();

void turnOffUserLED();

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

void setupUserLED(){
  RCC_AHB1ENR |= ENABLE_AHB1;
  GPIOA_MODER |= MODE5_OUTPUT;
}

void turnOnUserLED() {
  GPIOA_ODR |= ODR5;
}

void turnOffUserLED() {
  GPIOA_ODR &= ~ODR5;
}

void convertTextToMorseCode(const char* str, char* buffer) {
    int length = strlen(str);
    int current_len = 0;
    for(int i = 0; i < length; i++) {
        switch(str[i]) {
            case 'A':
            case 'a':
                strcat(buffer, morseA);
                break;
            case 'B':
            case 'b':
                strcat(buffer, morseB);
                break;
            case 'C':
            case 'c':
                strcat(buffer, morseC);
                break;
            case 'D':
            case 'd':
                strcat(buffer, morseD);
                break;
            case 'E':
            case 'e':
                strcat(buffer, morseE);
                break;
            case 'F':
            case 'f':
                strcat(buffer, morseF);
                break;
            case 'G':
            case 'g':
                strcat(buffer, morseG);
                break;
            case 'H':
            case 'h':
                strcat(buffer, morseH);
                break;
            case 'I':
            case 'i':
                strcat(buffer, morseI);
                break;
            case 'J':
            case 'j':
                strcat(buffer, morseJ);
                break;
            case 'K':
            case 'k':
                strcat(buffer, morseK);
                break;
            case 'L':
            case 'l':
                strcat(buffer, morseL);
                break;
            case 'M':
            case 'm':
                strcat(buffer, morseM);
                break;
            case 'N':
            case 'n':
                strcat(buffer, morseN);
                break;
            case 'O':
            case 'o':
                strcat(buffer, morseO);
                break;
            case 'P':
            case 'p':
                strcat(buffer, morseP);
                break;
            case 'Q':
            case 'q':
                strcat(buffer, morseQ);
                break;
            case 'R':
            case 'r':
                strcat(buffer, morseR);
                break;
            case 'S':
            case 's':
                strcat(buffer, morseS);
                break;
            case 'T':
            case 't':
                strcat(buffer, morseT);
                break;
            case 'U':
            case 'u':
                strcat(buffer, morseU);
                break;
            case 'V':
            case 'v':
                strcat(buffer, morseV);
                break;
            case 'W':
            case 'w':
                strcat(buffer, morseW);
                break;
            case 'X':
            case 'x':
                strcat(buffer, morseX);
                break;
            case 'Y':
            case 'y':
                strcat(buffer, morseY);
                break;
            case 'Z':
            case 'z':
                strcat(buffer, morseZ);
                break;
            case ' ':
                current_len = strlen(buffer);
                buffer[current_len-1] = '\0';
                strcat(buffer, morseSpaceWord);
                break;
            default:
                break;
                
        }
        if (i != length - 1 && str[i] != ' ') strcat(buffer, morseSpaceLetter);
    }
}