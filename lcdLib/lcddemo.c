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


int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  
  //state 1
  fillRectangle(0,0,128,92,COLOR_LIGHT_BLUE);
  fillRectangle(0,92,128,159,COLOR_LIME_GREEN);
  
  fillRectangle(39,92,44,159,COLOR_RED);
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
  drawPixel(28,75,COLOR_DARK_GREEN);
  drawPixel(28,76,COLOR_DARK_GREEN);
  drawPixel(29,76,COLOR_DARK_GREEN);
  drawPixel(14,88,COLOR_DARK_GREEN);
  drawPixel(15,88,COLOR_DARK_GREEN);
  drawPixel(15,89,COLOR_DARK_GREEN);
  drawPixel(28,89,COLOR_DARK_GREEN);
  drawPixel(28,88,COLOR_DARK_GREEN);
  drawPixel(29,88,COLOR_DARK_GREEN);

  fillRectangle(89,81,17,5,COLOR_ORANGE);
  fillRectangle(93,76,9,14,COLOR_ORANGE);
  fillRectangle(90,79,3,2,COLOR_ORANGE);
  fillRectangle(102,79,3,2,COLOR_ORANGE);
  fillRectangle(90,86,3,2,COLOR_ORANGE);
  fillRectangle(102,86,3,2,COLOR_ORANGE);
  drawPixel(91,78,COLOR_ORANGE);
  drawPixel(92,78,COLOR_ORANGE);
  drawPixel(92,77,COLOR_ORANGE);
  drawPixel(102,77,COLOR_ORANGE);
  drawPixel(102,78,COLOR_ORANGE);
  drawPixel(103,78,COLOR_ORANGE);
  drawPixel(91,88,COLOR_ORANGE);
  drawPixel(92,87,COLOR_ORANGE);
  drawPixel(92,89,COLOR_ORANGE);
  drawPixel(102,89,COLOR_ORANGE);
  drawPixel(102,88,COLOR_ORANGE);
  drawPixel(103,88,COLOR_ORANGE);

  //words
  drawString5x7(7,106,"Why couldn't the watermelon and");
  drawString5x7(18,106,"the melon get married?");

  

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
          //state 2
          fillRectangle(0,0,128,92,COLOR_LIGHT_BLUE);
          fillRectangle(0,92,128,159,COLOR_LIME_GREEN);
  
          fillRectangle(39,92,44,159,COLOR_RED);
          fillRectangle(57,65,15,26,COLOR_BROWN);
          fillRectangle(31,35,6,56,COLOR_WHITE);
          fillRectangle(85,35,7,56,COLOR_WHITE);
          fillRectangle(32,30,58,4,COLOR_WHITE);
          fillRectangle(37,25,49,4,COLOR_WHITE);

            //cantelope
            fillRectangle(54,70,16,1,COLOR_BLACK);
            fillRectangle(77,77,1,7,COLOR_BLACK);
            fillRectangle(54,91,16,1,COLOR_BLACK);
            fillRectangle(47,77,1,7,COLOR_BLACK);
            drawPixel(71,71,COLOR_BLACK);
            drawPixel(72,72,COLOR_BLACK);
            drawPixel(73,73,COLOR_BLACK);
            drawPixel(74,74,COLOR_BLACK);
            drawPixel(75,75,COLOR_BLACK);
            drawPixel(76,76,COLOR_BLACK);
            drawPixel(53,71,COLOR_BLACK);
            drawPixel(52,72,COLOR_BLACK);
            drawPixel(51,73,COLOR_BLACK);
            drawPixel(50,74,COLOR_BLACK);
            drawPixel(49,75,COLOR_BLACK);
            drawPixel(48,76,COLOR_BLACK);
            drawPixel(48,85,COLOR_BLACK);
            drawPixel(49,86,COLOR_BLACK);
            drawPixel(50,87,COLOR_BLACK);
            drawPixel(51,88,COLOR_BLACK);
            drawPixel(52,89,COLOR_BLACK);
            drawPixel(53,90,COLOR_BLACK);
            drawPixel(71,90,COLOR_BLACK);
            drawPixel(72,89,COLOR_BLACK);
            drawPixel(73,88,COLOR_BLACK);
            drawPixel(74,87,COLOR_BLACK);
            drawPixel(75,86,COLOR_BLACK);
            drawPixel(76,85,COLOR_BLACK);

            //color
            fillRectangle(48,77,29,8,COLOR_BEIGE);
            fillRectangle(54,71,17,20,COLOR_BEIGE);
            fillRectangle(50,75,4,2,COLOR_BEIGE);
            fillRectangle(52,73,2,2,COLOR_BEIGE);
            fillRectangle(71,73,2,4,COLOR_BEIGE);
            fillRectangle(73,73,2,2,COLOR_BEIGE);
            fillRectangle(50,85,4,2,COLOR_BEIGE);
            fillRectangle(52,87,2,2,COLOR_BEIGE);
            fillRectangle(71,85,2,4,COLOR_BEIGE);
            fillRectangle(73,85,2,2,COLOR_BEIGE);
            drawPixel(49,76,COLOR_BEIGE);
            drawPixel(51,74,COLOR_BEIGE);
            drawPixel(53,72,COLOR_BEIGE);
            drawPixel(71,72,COLOR_BEIGE);
            drawPixel(73,74,COLOR_BEIGE);
            drawPixel(75,76,COLOR_BEIGE);
            drawPixel(49,85,COLOR_BEIGE);
            drawPixel(51,87,COLOR_BEIGE);
            drawPixel(53,89,COLOR_BEIGE);
            drawPixel(71,89,COLOR_BEIGE);
            drawPixel(73,87,COLOR_BEIGE);
            drawPixel(75,85,COLOR_BEIGE);

            drawString5x7(7,106,"Because they cantaloupe");
          __delay_cycles(200000);
        }

        if(currentState==stateOne)
        {
          currentState =stateTwo;
          //state 1
          fillRectangle(0,0,128,92,COLOR_LIGHT_BLUE);
          fillRectangle(0,92,128,159,COLOR_LIME_GREEN);
          
          fillRectangle(39,92,44,159,COLOR_RED);
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
          drawPixel(28,75,COLOR_DARK_GREEN);
          drawPixel(28,76,COLOR_DARK_GREEN);
          drawPixel(29,76,COLOR_DARK_GREEN);
          drawPixel(14,88,COLOR_DARK_GREEN);
          drawPixel(15,88,COLOR_DARK_GREEN);
          drawPixel(15,89,COLOR_DARK_GREEN);
          drawPixel(28,89,COLOR_DARK_GREEN);
          drawPixel(28,88,COLOR_DARK_GREEN);
          drawPixel(29,88,COLOR_DARK_GREEN);

          fillRectangle(89,81,17,5,COLOR_ORANGE);
          fillRectangle(93,76,9,14,COLOR_ORANGE);
          fillRectangle(90,79,3,2,COLOR_ORANGE);
          fillRectangle(102,79,3,2,COLOR_ORANGE);
          fillRectangle(90,86,3,2,COLOR_ORANGE);
          fillRectangle(102,86,3,2,COLOR_ORANGE);
          drawPixel(91,78,COLOR_ORANGE);
          drawPixel(92,78,COLOR_ORANGE);
          drawPixel(92,77,COLOR_ORANGE);
          drawPixel(102,77,COLOR_ORANGE);
          drawPixel(102,78,COLOR_ORANGE);
          drawPixel(103,78,COLOR_ORANGE);
          drawPixel(91,88,COLOR_ORANGE);
          drawPixel(92,87,COLOR_ORANGE);
          drawPixel(92,89,COLOR_ORANGE);
          drawPixel(102,89,COLOR_ORANGE);
          drawPixel(102,88,COLOR_ORANGE);
          drawPixel(103,88,COLOR_ORANGE);

          //words
          drawString5x7(7,106,"Why couldn't the watermelon and");
          drawString5x7(18,106,"the melon get married?");

          __delay_cycles(200000);
        }

        if(currentState==stateTwo)
        {
          currentState=stateOne;
          //state 2
          fillRectangle(0,0,128,92,COLOR_LIGHT_BLUE);
          fillRectangle(0,92,128,159,COLOR_LIME_GREEN);
          
          fillRectangle(39,92,44,159,COLOR_RED);
          fillRectangle(57,65,15,26,COLOR_BROWN);
          fillRectangle(31,35,6,56,COLOR_WHITE);
          fillRectangle(85,35,7,56,COLOR_WHITE);
          fillRectangle(32,30,58,4,COLOR_WHITE);
          fillRectangle(37,25,49,4,COLOR_WHITE);

          //cantelope
          fillRectangle(54,70,16,1,COLOR_BLACK);
          fillRectangle(77,77,1,7,COLOR_BLACK);
          fillRectangle(54,91,16,1,COLOR_BLACK);
          fillRectangle(47,77,1,7,COLOR_BLACK);
          drawPixel(71,71,COLOR_BLACK);
          drawPixel(72,72,COLOR_BLACK);
          drawPixel(73,73,COLOR_BLACK);
          drawPixel(74,74,COLOR_BLACK);
          drawPixel(75,75,COLOR_BLACK);
          drawPixel(76,76,COLOR_BLACK);
          drawPixel(53,71,COLOR_BLACK);
          drawPixel(52,72,COLOR_BLACK);
          drawPixel(51,73,COLOR_BLACK);
          drawPixel(50,74,COLOR_BLACK);
          drawPixel(49,75,COLOR_BLACK);
          drawPixel(48,76,COLOR_BLACK);
          drawPixel(48,85,COLOR_BLACK);
          drawPixel(49,86,COLOR_BLACK);
          drawPixel(50,87,COLOR_BLACK);
          drawPixel(51,88,COLOR_BLACK);
          drawPixel(52,89,COLOR_BLACK);
          drawPixel(53,90,COLOR_BLACK);
          drawPixel(71,90,COLOR_BLACK);
          drawPixel(72,89,COLOR_BLACK);
          drawPixel(73,88,COLOR_BLACK);
          drawPixel(74,87,COLOR_BLACK);
          drawPixel(75,86,COLOR_BLACK);
          drawPixel(76,85,COLOR_BLACK);

          //color
          fillRectangle(48,77,29,8,COLOR_BEIGE);
          fillRectangle(54,71,17,20,COLOR_BEIGE);
          fillRectangle(50,75,4,2,COLOR_BEIGE);
          fillRectangle(52,73,2,2,COLOR_BEIGE);
          fillRectangle(71,73,2,4,COLOR_BEIGE);
          fillRectangle(73,73,2,2,COLOR_BEIGE);
          fillRectangle(50,85,4,2,COLOR_BEIGE);
          fillRectangle(52,87,2,2,COLOR_BEIGE);
          fillRectangle(71,85,2,4,COLOR_BEIGE);
          fillRectangle(73,85,2,2,COLOR_BEIGE);
          drawPixel(49,76,COLOR_BEIGE);
          drawPixel(51,74,COLOR_BEIGE);
          drawPixel(53,72,COLOR_BEIGE);
          drawPixel(71,72,COLOR_BEIGE);
          drawPixel(73,74,COLOR_BEIGE);
          drawPixel(75,76,COLOR_BEIGE);
          drawPixel(49,85,COLOR_BEIGE);
          drawPixel(51,87,COLOR_BEIGE);
          drawPixel(53,89,COLOR_BEIGE);
          drawPixel(71,89,COLOR_BEIGE);
          drawPixel(73,87,COLOR_BEIGE);
          drawPixel(75,85,COLOR_BEIGE);

          drawString5x7(7,106,"Because they cantaloupe");
          __delay_cycles(200000);

        }
      }

      prevB1State=b1State;

      // Add a delay to avoid button bounce issues
      

    }
  }

  

  }
