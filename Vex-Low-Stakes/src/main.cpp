/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

//#include "STDLib.cpp"
#include "vex.h"
#include <iostream>

#include "screen_gui.hpp"
#include "movement.hpp"
#include "routes/routes.hpp"

using namespace vex;

// A global instance of competition
competition Competition;


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

bool SP;
bool EXIT;
void pre_auton(void) { // prepare for auto, by setting default pneu states and zeroing gyro
  //ATaskActiv = 1;
   EXIT=false;
  Clamp.set(true);
  Doinker.set(false);
  IntakeLift.set(false);
  PX=0;
  JX=0;
  AutoSelectorVal=0;
  SP=false;
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Gyro.calibrate();
  Gyro.setHeading(0, degrees);


  if(LiftSensor.position(degrees) != 359) { //Set degrees to 359, due to macro issues (runs in wrong way if zeroed to 0 or above.)
    LiftSensor.setPosition(359.99999999999, degrees);
  }
  

//Ensure Robot Launch Position is set before auto proceeds, once plugged into field control,
//start program and do not temper bot under all circumstances

//1. IF ANY ADJUSTMENT IS NEEDED, QUIT PROGRAM, THEN ADJUST, RESTART PROGRAM AFTER ADJUSTMENTS COMPLETED
//2. DO NOT START PROGRAM BEFORE PLUGGING IN FIELD CONTROL, THIS MAY DISABLE AUTO
//3. ONLY SIGNAL JUDGES TO BEGIN MATCH AFTER THE ZEROING PROMPT ON SCREEN HAS CLEARED

//Print precautionary message
Brain.Screen.drawRectangle(0,0,500,500);

Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(2,10);
Brain.Screen.print("FLIR TIMEOUT");


waitUntil(!Gyro.isCalibrating());

//DisplayColors();


//waitUntil(not RingColor == 0);
Zeroing(true,true);
DisplayAutoSelector();
DisplayWords();

//task AutoSelTask=task(ScreenSelMain);
  while(!EXIT)
{
if(Brain.Screen.xPosition()<100)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=1;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=3;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=5;
}
else if(Brain.Screen.xPosition()>375)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=2;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=4;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=6;
}

if(Brain.Screen.xPosition()>187&&Brain.Screen.xPosition()<287)
{
if(Brain.Screen.yPosition()<55&&Brain.Screen.yPosition()>5) EXIT=true;
else if(Brain.Screen.yPosition()>125&&Brain.Screen.yPosition()<225)AutoSelectorVal=7;
}

if(Brain.Screen.pressing()&&!SP) UpdateDynamic();

SP=Brain.Screen.pressing();

}

Brain.Screen.clearScreen();
if(AutoSelectorVal==1){
  Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("skill");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("Risky");
Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor("#f8b195");

}

if(AutoSelectorVal==2){
Brain.Screen.setFillColor(black);

Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("ALLAWP");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("AllAWP");
Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor("#f8b195");
}

if(AutoSelectorVal==3){

Brain.Screen.setFillColor(black);

    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("BLUESIDE");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("RISKY");
Brain.Screen.setFont(monoM);  
  Brain.Screen.setFillColor("#f8b195");
}

if(AutoSelectorVal==4){

Brain.Screen.setFillColor(black);

  Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("BLUESIDE");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("RISKY AWP");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#f8b195");

}

if(AutoSelectorVal==5){

Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("GOAL SIDE");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("GS-AWP");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#f8b195");

}

if(AutoSelectorVal==6){
  
  Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("MATCHLOAD");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("ONLY AWP");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#f8b195");

  }

if(AutoSelectorVal==7){

Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("xu");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("SKILLS");
Brain.Screen.setFont(monoM); 
Brain.Screen.setFillColor("#f8b195");

}

Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(5,10);
Brain.Screen.print("AUTO CONFIRMED");



  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

//Do not change the below
PIDDataSet TestPara={1.5,0.1,0.15};
Zeroing(true,true);

//can start editing if nessary
//Put Auto route function into if statements to use autoselector
if(AutoSelectorVal==1)//Normal
{
  Blue_5();
}

if(AutoSelectorVal==2)// Left side either red/blue
{
  Red_5();
}

if(AutoSelectorVal==3)//Risky
{
  
} 

if(AutoSelectorVal==4)// risky AWP
{
  RMogo();
}

if(AutoSelectorVal==5)// 
{
    //Blue_MogoRush();
}


if(AutoSelectorVal==6)//AWP only
{
  //Red_MogoRush();
}


if(AutoSelectorVal==7)//temporary prog skills
{ 
 Skills();

}
//MoveTimePID(TestPara, -100, 0.5,0.1,-40,true);//score 2nd triball
//(PID Parameters, motor speed -100 - 100, time for travel 0 - inf, time to accelerate to full speed, Absolute Heading, Braking?)

    // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
CStop();
}
int RV;
int LV;
int DriveTask(void){
  while(true)
  {
    EXIT=true;

    RV=-Controller1.Axis3.position(percent)+Controller1.Axis1.position(percent); 
    LV=-Controller1.Axis3.position(percent)-Controller1.Axis1.position(percent); 
    //Find the Forward/Backward to calculate velocity of left/right side
    //Allows for us to move diagonally
    Move(LV,RV);
    //uses the values of Lv and Rv as velocity %s to move the left/right side of the motors at said %.
  }

return 0;
}




/*
int ITask(void) {
  double pow;
  pow = ((Controller1.ButtonR2.pressing() - Controller1.ButtonR1.pressing()) * 100);
  RunRoller(-pow);

  return 0;  

}
  */

int hue = Csen.hue();
bool isBlue = (Csen.hue() >= 200 && Csen.hue() <= 230);


int Eject = 0;
double olddegree = 0.0;
double pow2;
int ITask(void) {
    //Initialize variables
    
    
    

    while (true) {
        

        // Improved color detection logic with red hue range check
        int hue = Csen.hue();
        bool isRed = (hue >= 0 && hue <= 30) || (hue >= 330 && hue <= 360);
        
        // Check if an object is detected and it's the desired color
        if (isRed && Csen.isNearObject() == 1) {
          olddegree = abs(In1.position(degrees)) + 21;
          Eject = 1;
          RunRoller(0);  // Immediately stop the roller to prepare for ejection
          Brain.Timer.clear();  // Clear the timer
        }

        if (Eject == 0) {
          // Calculate intake power
          pow2 = ((Controller1.ButtonR2.pressing() - Controller1.ButtonR1.pressing()) * 100);
          RunRoller(-pow2);
        }



        // Eject mechanism to "yeet" the ring
        while (Eject == 1) {
          while (abs(In1.position(degrees)) < olddegree) {
              RunRoller(-100);  // Increase roller speed to maximize ejection force
          }
          RunRoller(0); 
          olddegree = abs(In1.position(degrees)) - 83;
          while (abs(In1.position(degrees)) > olddegree && Eject == 1)
          {
            RunRoller(80);
            if (abs(In1.position(degrees)) <= olddegree){
              RunRoller(0);
              Eject = 0;
            }
          }
          
           
          
          
      }



        // Only run the roller if not in ejection mode

        // Small delay to prevent CPU overload
        wait(10, msec);
    }
    return 0;
}






int ButtonPressingX,XTaskActiv; //Defines the toggle and pressing variables for Clamping
int ButtonPressingY,YTaskActiv; //Defines the toggle and pressing variables for Doinker
int ButtonPressingA,ATaskActiv; //Defines the toggle and pressing variables for Wall Stake Macro.
int ButtonPressingB,BTaskActiv; //Defines the toggle and pressing variables for Intake Lift
int XTask(void)
{
    while(true)
    {
      //Toggles Tilt
    if(XTaskActiv==0&&Controller1.ButtonX.pressing()&&ButtonPressingX==0)//Finding if ButtonX is pressing and if it was held down before.
    {
      ButtonPressingX=1;//Button is now pressed
      XTaskActiv=1;//Task is now active
      Clamp.set(true);
    }

    else if(!Controller1.ButtonX.pressing())ButtonPressingX=0; //Checks if the botton isn't being held down

    else if(XTaskActiv==1&&Controller1.ButtonX.pressing()&&ButtonPressingX==0)//Finding if task is active and if ButtonX wasn't pressed before
    {
      ButtonPressingX=1;//Button is now pressed
      XTaskActiv=0;//Task is now NOT running
      Clamp.set(false);
    }
    //----------------------
      //Toggles Clamp

    }

  return 0;
  }
  int YTask(void)
{
    while(true)
    {
      //Toggles Tilt
    if(YTaskActiv==0&&Controller1.ButtonY.pressing()&&ButtonPressingY==0)//Finding if ButtonY is pressing and if it was held down before.
    {
      ButtonPressingY=1;//Button is now pressed
      YTaskActiv=1;//Task is now active
      Doinker.set(false);
    }

    else if(!Controller1.ButtonY.pressing())ButtonPressingY=0; //Checks if the botton isn't being held down

    else if(YTaskActiv==1&&Controller1.ButtonY.pressing()&&ButtonPressingY==0)//Finding if task is active and if ButtonX wasn't pressed before
    {
      ButtonPressingY=1;//Button is now pressed
      YTaskActiv=0;//Task is now NOT running
      Doinker.set(true);
    }
    //----------------------
      //Toggles Doinky doinker

    }

  return 0;
  }

int BTask(void)
{
    while(true)
    {
      //Toggles Tilt
    if(BTaskActiv==0&&Controller1.ButtonB.pressing()&&ButtonPressingB==0)//Finding if ButtonY is pressing and if it was held down before.
    {
      ButtonPressingB=1;//Button is now pressed
      BTaskActiv=1;//Task is now active
      IntakeLift.set(false);
    }

    else if(!Controller1.ButtonB.pressing())ButtonPressingB=0; //Checks if the botton isn't being held down

    else if(BTaskActiv==1&&Controller1.ButtonB.pressing()&&ButtonPressingB==0)//Finding if task is active and if ButtonX wasn't pressed before
    {
      ButtonPressingB=1;//Button is now pressed
      BTaskActiv=0;//Task is now NOT running
      IntakeLift.set(true);
    }
    //----------------------
      //Toggles Intake lift
      //allows to get rings on top of others

    }

  return 0;
  }


  int ATask(void) {
    int pow1 = 0;
    int targetPosition = 342;  // Desired position between 324 and 342 degrees
    double integral = 0.0;     // Integral term
    double previousError = 0.0; // Previous error for derivative calculation
    double Kp = -0.5;           // Proportional gain (adjust as needed)
    double Ki = 0.1;            // Integral gain (adjust as needed)
    double Kd = 0.1;            // Derivative gain (adjust as needed)

    while (true) {
        if (ATaskActiv == 1) {
            int currentPos = abs(LiftSensor.position(degrees));
            double error = targetPosition - currentPos;

            // Calculate integral term
            integral += error;

            // Calculate derivative term
            double derivative = error - previousError;

            // PID calculation
            double liftPower = Kp * error + Ki * integral + Kd * derivative;

            // Limit the power to within motor capabilities
            if (liftPower > 100) liftPower = 100;
            if (liftPower < -100) liftPower = -100;

            // Ensure minimum power to overcome static friction
            if (liftPower > 0 && liftPower < 40) liftPower = 40;
            if (liftPower < 0 && liftPower > -40) liftPower = -40;

            RunLift(liftPower);

            // Stop the lift when close enough to the target
            if (abs(error) <= 2) {
                RunLift(0);
                ATaskActiv = 0;
            }

            // Update previous error
            previousError = error;

        } else {
            // Invert manual control power
            pow1 = (Controller1.ButtonL1.pressing() - Controller1.ButtonL2.pressing()) * -100;

            if (pow1 == 0) {
                Lift.setStopping(hold);
                Lift.stop();
            } else {
                RunLift(-pow1);
            }
        }

        // Handle Button A presses
        if (Controller1.ButtonA.pressing() && ButtonPressingA == 0) {
            ButtonPressingA = 1;
            ATaskActiv = 1;
        } else if (!Controller1.ButtonA.pressing()) {
            ButtonPressingA = 0;
        }

        // Override if BTaskActiv is active
        if (BTaskActiv == 1 && Controller1.ButtonA.pressing() && ButtonPressingA == 0) {
            ButtonPressingA = 1;
            ATaskActiv = 0;
            RunLift(0);
        }

        // Prevent CPU overload
        wait(10, msec);
    }
    return 0;
}







/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  EXIT=true;//Force Exit Autosel once drivercontrol began.
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    

//Runs all the tasks, helps with organizing each and every function of the robot
    task Dtask=task(DriveTask); 
    task Atask=task(ATask);
    task Xtask=task(XTask);
    task Ytask=task(YTask);    
    task Btask=task(BTask);
    task Itask=task(ITask);


    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//


int main() {
  // Reset pos below for Macro to function better.
  //LiftSensor.setPosition(-2, degrees);

  // Set up callbacks for autonomous and driver control periods.
//Runs autonomous before drivercontrol, allowing for the controller to 
//function with a field controller or a smart field
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Run the pre-autonomous function.
  pre_auton();







   
// Prevent main from exiting with an infinite loop.
// Incorporates printing in log, for troubleshooting whilst controller is connected to the coding device.
  while (true) {
    Csen.setLight(ledState::on);
  
    using std::cout;
    using std::endl;
    wait(500, msec);
    cout << "CurrentLift" << endl; // Prints the angle of the wall stake linear rotations sensor
    cout << LiftSensor.angle() << endl; //LiftSensor is the defined name for the rotation sensor
    cout << "Current" << endl; // This is the angle of the intake, used to troubleshoot color sorting
    cout << In1.position(degrees) << endl; //In1 is the name of the intake motor, from ^, uses Rotation
/*
Dump Pit, This is where all the unused print statements are stored, being taken out from time to time
for their individual uses, with many for either checking the gyro rotation, Color sensor, etc. 
    cout << "blue" << endl;
    cout << isBlue << endl;
    cout << "Hue" << endl;
    cout << Csen.hue() << endl;
    cout << "Press" << endl;
    cout << Csen.isNearObject() << endl;
    cout << "Desired" << endl;
    cout << CurrentDegree << endl;
    cout << "CurrentLift" << endl;
    cout << LiftSensor.angle() << endl;
    cout << "Current" << endl;
    cout << In1.position(degrees) << endl;
    cout << "Gyro" << endl;
    cout << Gyro.angle() << endl;



*/
    
    //--------------------------------------------------------------------------------


}
}

