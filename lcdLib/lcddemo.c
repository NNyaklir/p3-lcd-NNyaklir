#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define SW1 BIT0

typedef enum {
    stateInitial, stateOne, stateTwo,
} State;

State currentState = stateInitial;

int prevB1State = 1; // Previous state of button 1
int debounceFlag = 0; // Flag to indicate a stable button press

void debounce() {
    // Read the button state
    int b1State = (P2IN & SW1) ? 1 : 0;

    if (b1State != prevB1State) {
        __delay_cycles(2000); // Add a small delay for debounce
        if (b1State == (P2IN & SW1)) {
            debounceFlag = 1;
            prevB1State = b1State;
        }
    }
}

/** Initializes everything, clears the screen, draws "hello" and a square */
int main() {
    configureClocks();
    lcd_init();
    u_char width = screenWidth, height = screenHeight;

    clearScreen(COLOR_BLUE);

    drawString5x7(20, 20, "hello", COLOR_GREEN, COLOR_RED);

    fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
    drawPixel(0, 0, COLOR_WHITE);       // bit (0,0) is in the top left
    drawPixel(129, 159, COLOR_WHITE); // upper range is 129,159

    while (1) {
        // Update the debounce flag
        debounceFlag = 0;

        // Check for a stable button press
        debounce();

        if (debounceFlag) {
            // Handle state transitions based on the button press
            if (currentState == stateInitial) {
                currentState = stateOne;
                clearScreen(COLOR_PURPLE);
            } else if (currentState == stateOne) {
                currentState = stateTwo;
                clearScreen(COLOR_GREEN);
            } else if (currentState == stateTwo) {
                currentState = stateOne;
                clearScreen(COLOR_PURPLE);
            }
        }

        // Add a delay to avoid button bounce issues
        __delay_cycles(200000); // Adjust the delay as needed
    }

    return 0;
}