#include "MorseCode.h"
#include <string.h>

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

const char* convertTextToMorseCode(const char* str, char* buffer) {
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
    return buffer;
}