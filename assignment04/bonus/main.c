#include "UserLed.h" // For Nucleo
// #include <stdio.h> // For non-embedded systems

int main(void) {

	int x = 0x21;
	char test;

	int* pint = &x;
	test = *((char *)pint);

	setupUserLED();

	if (test == 0x0) {

		// Turn LED on if big endian

                turnOnUserLED();

                // For non-embedded systems
		// printf("Current Endian-ness: Big\n");

	} else {

		// Blink LED if little endian

                int counter;

                while(1) {

                    turnOnUserLED();

                    counter = 0;
		    while(counter < 1000000) {
                        counter++;
                    }

                    turnOffUserLED();

                    counter = 0;
		    while(counter < 1000000) {
                        counter++;
                    }

                }

                // For non-embedded systems
		// printf("Current Endian-ness: Little\n");
	}

	return 0;
}