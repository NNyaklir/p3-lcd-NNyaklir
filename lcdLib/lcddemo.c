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
  fillRectangle(0,0,128,92,COLOR_LIGHT_BLUE);
  fillRectangle(0,92,128,159,COLOR_LIME_GREEN);
  
  fillRectangle(39,92,44,159,COLOR_FIREBRICK);
  fillRectangle(57,65,15,26,COLOR_BROWN);
  fillRectangle(31,35,6,56,COLOR_WHITE);
  fillRectangle(85,35,7,56,COLOR_WHITE);
  fillRectangle(32,30,58,4,COLOR_WHITE);
  fillRectangle(37,25,49,4,COLOR_WHITE);

  fillRectangle(16,73,11,1,COLOR_BLACK);
  drawPixel(28,74,COLOR_BLACK);
  drawPixel(29,75,COLOR_BLACK);
  drawPixel(30,76,COLOR_BLACK);
  fillRectangle(31,77,1,2,COLOR_BLACK);
  fillRectangle(32,79,1,7,COLOR_BLACK);
  drawPixel(30,88,COLOR_BLACK);
  drawPixel(29,89,COLOR_BLACK);
  drawPixel(28,90,COLOR_BLACK);
  fillRectangle(16,91,11,1,COLOR_BLACK);
  fillRectangle(12,77,1,2,COLOR_BLACK);
  fillRectangle(12,86,1,2,COLOR_BLACK);
  fillRectangle(11,79,1,7,COLOR_BLACK);
  fillRectangle(31,86,1,2,COLOR_BLACK);
  drawPixel(15,74,COLOR_BLACK);
  drawPixel(14,75,COLOR_BLACK);
  drawPixel(13,76,COLOR_BLACK);
  drawPixel(13,88,COLOR_BLACK);
  drawPixel(14,89,COLOR_BLACK);
  drawPixel(15,90,COLOR_BLACK);

  fillRectangle(12,79,19,6,COLOR_DARK_GREEN);
  fillRectangle(16,74,11,16,COLOR_DARK_GREEN);
  fillRectangle(13,77,4,3,COLOR_DARK_GREEN);
  fillRectangle(27,77,4,3,COLOR_DARK_GREEN);
  fillRectangle(13,85,4,3,COLOR_DARK_GREEN);
  fillRectangle(27,85,4,3,COLOR_DARK_GREEN);
  drawPixel(14,76,COLOR_DARK_GREEN);
  drawPixel(15,76,COLOR_DARK_GREEN);
  drawPixel(15,75,COLOR_DARK_GREEN);
  drawpixel(28,75,COLOR_DARK_GREEN);
  drawPixel(28,76,COLOR_DARK_GREEN);
  drawPixel(29,76,COLOR_DARK_GREEN);
  drawPixel(14,88,COLOR_DARK_GREEN);
  drawPixel(15,88,COLOR_DARK_GREEN);
  drawPixel(15,89,COLOR_DARK_GREEN);
  drawPixel(28,89,COLOR_DARK_GREEN);
  drawPixel(28,88,COLOR_DARK_GREEN);
  drawPixel(29,88,COLOR_DARK_GREEN);

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
