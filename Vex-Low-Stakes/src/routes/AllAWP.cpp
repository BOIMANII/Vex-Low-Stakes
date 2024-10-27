#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AllAWP(){
    //both sides
    //Gyro.setHeading(0,degrees);
    PIDDataSet Test={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(Test, 60, 36, 0.2, 0, false);
    wait(1500, msec);
    Clamp.set(false);
    wait(500, msec);
    RunRoller(-100);
    wait(500, msec);
    TurnMaxTimePID(Test, 90, 0.2, 0);
    MoveEncoderPID(Test, 75, 10, 0.2, 90, 0);
}