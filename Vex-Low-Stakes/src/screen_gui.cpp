#include "screen_gui.hpp"
#include "vex.h"
void DisplayColors(void)
{
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(3, 3);
  Brain.Screen.setPenColor("#3E92CC");
  Brain.Screen.print("Blue");

  Brain.Screen.setCursor(3, 10);
  Brain.Screen.setPenColor("#FF1B1C");
  Brain.Screen.print("Red");

  Brain.Screen.setCursor(3, 15);
  Brain.Screen.setPenColor("#ffffff");
  Brain.Screen.print("Confirm");

  // Selection Below

  while (int q = 0)
  {
    if (Brain.Screen.yPosition() > 6 && Brain.Screen.yPosition() < 9)
    {

      if (Brain.Screen.xPosition() > 0 && Brain.Screen.xPosition() < 6)
      {
        Brain.Screen.setCursor(6, 10);
        Brain.Screen.print("Blue");
        if (Brain.Screen.pressing() == true)
        {
          RingColor = 1;
        }
      }

      else if (Brain.Screen.xPosition() > 7 && Brain.Screen.xPosition() < 13)
      {
        Brain.Screen.setCursor(6, 10);
        Brain.Screen.print("Red");
        if (Brain.Screen.pressing() == true)
        {
          RingColor = 2;
        }
      }
      else if (Brain.Screen.xPosition() > 12 && Brain.Screen.xPosition() < 18)
      {
        Brain.Screen.setCursor(6, 10);
        Brain.Screen.print("CONFIRMED");
        if (Brain.Screen.pressing() == true)
        {
          q = 1;
        }
      }
    }
  }
}

void DisplayAutoSelector(void)
{

  Brain.Screen.clearScreen();

  // auton selector
  Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor(black);
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.setPenWidth(3);
  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(1, 25, 100, 50);

  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(375, 25, 100, 50);

  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(1, 100, 100, 50);

  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(375, 100, 100, 50);

  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(1, 175, 100, 50);

  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(375, 175, 100, 50);

  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(187, 5, 100, 50);

  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.drawRectangle(187, 175, 100, 50);
}

void DisplayWords(void)
{
  Brain.Screen.setPenColor("#FEFFEA");
  Brain.Screen.setFont(monoM);
  Brain.Screen.setCursor(3, 3);
  Brain.Screen.print("Right");

  Brain.Screen.setCursor(7, 3);
  Brain.Screen.print("BlueMogo");

  Brain.Screen.setCursor(11, 3);
  Brain.Screen.print("Blue_S_AWP");

  Brain.Screen.setCursor(3, 40);
  Brain.Screen.print("Left");

  Brain.Screen.setCursor(7, 40);
  Brain.Screen.print("RedMogo");

  Brain.Screen.setCursor(11, 40);
  Brain.Screen.print("Blue_S_AWP");

  Brain.Screen.setCursor(11, 22);
  Brain.Screen.print("Skills");
}

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int AutoSelectorVal;
int RingColor = 0;
void UpdateDynamic(void)
{
  DisplayAutoSelector();
  DisplayWords();
  Brain.Screen.setFillColor("#FEFFEA");
  Brain.Screen.setPenColor(black);
  if (AutoSelectorVal == 1)
  {
    Brain.Screen.drawRectangle(1, 25, 100, 50);
    Brain.Screen.setCursor(3, 3);
    Brain.Screen.print("Blue 5");

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FEFFEA");
    Brain.Screen.setCursor(3, 10);
    Brain.Screen.print("2 Rings");
    Brain.Screen.setCursor(4, 10);
    Brain.Screen.print("2 Stakes");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FEFFEA");
  }
  Brain.Screen.setFillColor("#FEFFEA");
  if (AutoSelectorVal == 2)
  {
    Brain.Screen.drawRectangle(375, 25, 100, 50);
    Brain.Screen.setCursor(3, 40);
    Brain.Screen.print("Red5");

    Brain.Screen.setFillColor(black);

    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FEFFEA");
    Brain.Screen.setCursor(3, 10);
    Brain.Screen.print("MATCHLOAD");
    Brain.Screen.setCursor(4, 10);
    Brain.Screen.print("StealAWP");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FEFFEA");
  }
  Brain.Screen.setFillColor("#4BA3C3");
  if (AutoSelectorVal == 3)
  {
    Brain.Screen.drawRectangle(1, 100, 100, 50);
    Brain.Screen.setCursor(7, 3);
    Brain.Screen.print("Blue Mogo");

    Brain.Screen.setFillColor(black);

    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FEFFEA");
    Brain.Screen.setCursor(3, 10);
    Brain.Screen.print("Mogo Side");
    Brain.Screen.setCursor(4, 10);
    Brain.Screen.print("2 Ring");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FEFFEA");
  }

  Brain.Screen.setFillColor("#DA2C38");
  if (AutoSelectorVal == 4)
  {
    Brain.Screen.drawRectangle(375, 100, 100, 50);
    Brain.Screen.setCursor(7, 40);
    Brain.Screen.print("Red Mogo");

    Brain.Screen.setFillColor(black);

    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FEFFEA");
    Brain.Screen.setCursor(3, 10);
    Brain.Screen.print("Mogo Side");
    Brain.Screen.setCursor(4, 10);
    Brain.Screen.print("2 Ring");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FEFFEA");
  }

  Brain.Screen.setFillColor("#4BA3C3");
  if (AutoSelectorVal == 5)
  {
    Brain.Screen.drawRectangle(1, 175, 100, 50);
    Brain.Screen.setCursor(11, 3);
    Brain.Screen.print("GS-AWP");

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FEFFEA");
    Brain.Screen.setCursor(3, 10);
    Brain.Screen.print("GOAL SIDE");
    Brain.Screen.setCursor(4, 10);
    Brain.Screen.print("GS-AWP");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FEFFEA");
  }
  Brain.Screen.setFillColor("#DA2C38");
  if (AutoSelectorVal == 6)
  {
    Brain.Screen.drawRectangle(375, 175, 175, 50);
    Brain.Screen.setCursor(11, 40);
    Brain.Screen.print("ML-AWP");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#FEFFEA");
    Brain.Screen.setCursor(3, 10);
    Brain.Screen.print("MATCHLOAD");
    Brain.Screen.setCursor(4, 10);
    Brain.Screen.print("ONLY AWP");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FEFFEA");
  }
  Brain.Screen.setFillColor("#FEFFEA");
  if (AutoSelectorVal == 7)
  {
    Brain.Screen.drawRectangle(187, 175, 100, 50);
    Brain.Screen.setCursor(11, 22);
    Brain.Screen.print("Skills");

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoM);
    Brain.Screen.setPenColor("#FEFFEA");
    Brain.Screen.setCursor(6, 16);
    Brain.Screen.print("Center Channel");
    Brain.Screen.setCursor(8, 14);
    Brain.Screen.print("Behind the Center Line");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#FEFFEA");
  }
}