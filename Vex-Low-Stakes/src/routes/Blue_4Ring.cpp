#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Blue_4Ring(){
    //both sides
    //Gyro.setHeading(0,degrees);
    PIDDataSet Test={1.5,0.1,0.15}; //initialize
    TurnMaxTimePID(Test, 0, 0.2, true);
    MoveEncoderPID(Test, 75, 35, 0.3, 0, 1);
    wait(250, msec);
    Clamp.set(true);
    wait(750, msec);
    MoveEncoderPID(Test, 70, 1, 0.2, 0, 0);
    RunRoller(100);
    wait(500, msec);
    TurnMaxTimePID(Test, -90, 0.7, 0);
    MoveEncoderPID(Test, -75, 13, 0.1, -90, 0);
    wait(250, msec);
    RunRoller(-100);
    wait(400, msec);
    TurnMaxTimePID(Test, -95, 0.7, 0);
    MoveEncoderPID(Test, -75, 3, 0.2, -95, 0);
    wait(250, msec);
    RunRoller(-100);
   

 
    
}