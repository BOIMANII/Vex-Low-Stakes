#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
    //blue side
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    wait(0.2, seconds);
    MoveEncoderPID(TestPara, 60, 36.5, 0.2, 0, true);//Drive to mogo
    MoveEncoderPID(TestPara, 10, .5, 0.2, 0, true);
    wait(0.5, seconds);
    Clamp.set(false);//clamp onto mogo
    wait(0.5, seconds);
    TurnMaxTimePID(TestPara, -90, 0.5, false);//turn towards stack
    RunRoller(-100);
    wait(0.5, seconds);
    MoveEncoderPID(TestPara, -60, 36.5, 0.2, Gyro.angle(), true);//Drive to mogo


}