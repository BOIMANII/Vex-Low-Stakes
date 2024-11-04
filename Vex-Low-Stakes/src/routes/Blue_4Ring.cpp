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
    MoveEncoderPID(Test, 80, 26.5, 0.2, 0, false);
    wait(250, msec);
    Clamp.set(false);
    wait(750, msec);
    RunRoller(-100);
    wait(500, msec);
    TurnMaxTimePID(Test, -90, 0.7, 0);
    MoveEncoderPID(Test, -75, 20, 0.2, -90, 0);
    wait(250, msec);
    RunRoller(0);
    MoveEncoderPID(Test, 80, 10, 0.2, -90, false);
    RunRoller(-100);
    wait(1, seconds);
    TurnMaxTimePID(Test, -180 , 0.2, 0);

    MoveEncoderPID(Test, -50, 10, 0.5, -150, 0);
    wait(0.5, seconds);
    TurnMaxTimePID(Test, -90, 0.2, 0);
    MoveEncoderPID(Test, -70, 10, 0.2, -90, 0);
    
}