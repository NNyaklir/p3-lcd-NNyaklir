/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define SW1 BIT2




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

  clearScreen(COLOR_BLUE);

  drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  drawPixel(0,0,COLOR_WHITE); //bit (0,0) is in the top left
  drawPixel(127,159,COLOR_WHITE); //upper range is 128,159
  

  //state 1
  fillRectangle(0,0,128,91,COLOR_LIGHT_BLUE);
  fillRectangle(0,92,128,159,COLOR_LIME_GREEN);
  
  fillRectangle(39,92,44,159,COLOR_FIREBRICK);
  //fillRectangle(57,65,72,91,COLOR_BROWN);
  //fillRectangle(31,35,37,91,COLOR_WHITE);
  //fillRectangle(85,35,92,91,COLOR_WHITE);
  //fillRectangle(32,30,90,34,COLOR_WHITE);
  //fillRectangle(37,25,86,29,COLOR_WHITE);

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
          clearScreen(COLOR_PURPLE);
          __delay_cycles(200000);
        }

        if(currentState==stateOne)
        {
          currentState =stateTwo;
          clearScreen(COLOR_GREEN);
          __delay_cycles(200000);
        }

        if(currentState==stateTwo)
        {
          currentState=stateOne;
          clearScreen(COLOR_PURPLE);
          __delay_cycles(200000);

        }
      }

      prevB1State=b1State;

      // Add a delay to avoid button bounce issues
      

    }
  }

  

  }
