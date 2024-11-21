#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void BAWP(){
    //blue side
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
}

void RAWP(){
    //red side
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    TurnMaxTimePID(Test, -140, 0.7, 0); // Turn to face allyence steak
    MoveEncoderPID(Test, 75, 6, 0.2, 139.7, 0); // Drive into allyence steak
    wait(150, msec);
    RunLift(100);
    wait(250, msec);
    RunLift(-100);

}