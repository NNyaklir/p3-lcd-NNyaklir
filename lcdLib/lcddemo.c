/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
typedef enum{
  stateInitial,stateOne,stateTwo,
}State;
  int state1=0;
  int state2=0;

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
  drawPixel(100,100,COLOR_WHITE); //upper range is 150,750




  //sudocode for my project
  /*
    if(state==state1){
      button press x
      state==state2
    }
    if(state==state2){
      button pressy 
      state==state3
    }
    if(state==state3){
      button press z
      state==state2
    }
  */
}
