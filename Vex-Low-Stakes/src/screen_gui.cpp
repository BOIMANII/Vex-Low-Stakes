#include "screen_gui.hpp"
#include "vex.h"
#include <utility> // Include utility for std::pair

bool isColorRed = false; // Renamed boolean


bool colorSelected = false; // Boolean to check if a color is selected

// Function to handle touch events
void onTouch() {
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(2, 1);
  Brain.Screen.print("Tap Blue or Red, then press Confirm");

  // Draw buttons
  Brain.Screen.setPenColor(blue);
  Brain.Screen.drawRectangle(50, 100, 100, 50);
  Brain.Screen.setPenColor(red);
  Brain.Screen.drawRectangle(250, 100, 100, 50);
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(150, 200, 100, 50);
  Brain.Screen.setCursor(6, 8);
  Brain.Screen.print("Confirm");

  while (true) {
    if (Brain.Screen.pressing()) {
      int x = Brain.Screen.xPosition();
      int y = Brain.Screen.yPosition();

      if (x > 50 && x < 150 && y > 100 && y < 150) {
        isColorRed = false;
        colorSelected = true;
        Brain.Screen.clearScreen();
        Brain.Screen.setPenColor(white);
        Brain.Screen.drawRectangle(250, 100, 100, 50); // Clear previous highlight
        Brain.Screen.setPenColor(blue);
        Brain.Screen.drawRectangle(50, 100, 100, 50);
        Brain.Screen.setPenColor(white);
        Brain.Screen.drawRectangle(150, 200, 100, 50);
        Brain.Screen.setCursor(6, 8);
        Brain.Screen.print("Confirm");

      } else if (x > 250 && x < 350 && y > 100 && y < 150) {
        isColorRed = true;
        colorSelected = true;
        Brain.Screen.clearScreen();
        Brain.Screen.setPenColor(white);
        Brain.Screen.drawRectangle(50, 100, 100, 50); // Clear previous highlight
        Brain.Screen.setPenColor(red);
        Brain.Screen.drawRectangle(250, 100, 100, 50);
        Brain.Screen.setPenColor(white);
        Brain.Screen.drawRectangle(150, 200, 100, 50);
        Brain.Screen.setCursor(6, 8);
        Brain.Screen.print("Confirm");

      } else if (x > 150 && x < 250 && y > 200 && y < 250 && colorSelected) {
        Brain.Screen.clearScreen();
        if (isColorRed) {
          Brain.Screen.setCursor(2, 1);
          Brain.Screen.print("Confirmed! Color: Red");
        } else {
          Brain.Screen.setCursor(2, 1);
          Brain.Screen.print("Confirmed! Color: Blue");
        }
        break;
      }
      vex::task::sleep(200); // Debounce touch event
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