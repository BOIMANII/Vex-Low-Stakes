#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AllAWP(){
    //blue side
    PIDDataSet p={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(p, 60, 36, 0.2, 0, false);
    Clamp.set(false);    
}