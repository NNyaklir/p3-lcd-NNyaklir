/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define SW1 BIT0




typedef enum{
  stateInitial,stateOne,stateTwo,
}State;

  State currentState=stateInitial;


/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  state0();

  int prevB1State = 1; // Previous state of button 1

  while(1)
  {
    

    while(1)
    {
      //read current button press
      int b1State = (P2IN & SW1) ? 1 : 0;

      //check for button press
      if(b1State==0 && prevB1State==1)
      {

        if(currentState==stateInitial)

        {
          currentState = stateOne;
          state1();

        }

        if(currentState==stateOne)
        {
          currentState =stateTwo;
          state2();
        }

        if(currentState==stateTwo)
        {
          currentState=stateOne;
          state1();

        }
      }

      prevB1State=b1State;

      // Add a delay to avoid button bounce issues
      __delay_cycles(200000);

    }
  }

  state0()
  {
  clearScreen(COLOR_BLUE);

  drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  drawPixel(0,0,COLOR_WHITE); //bit (0,0) is in the top left
  drawPixel(129,159,COLOR_WHITE); //upper range is 129,159

  }

  state1()
  {
    clearScreen(COLOR_PURPLE);
  }

  state2()
  {
    clearScreen(COLOR_GREEN);
  }

  
}
