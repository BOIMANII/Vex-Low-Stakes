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
void w25() {
    wait(250, msec);
}

void RAWP(){
    //red side
    IntakeLift.set(false);
    PIDDataSet Test={1.5,0.1,0.15}; //initialize
    TurnMaxTimePID(Test, 85, 0.2, 0); // turn to alliance stake.
    MoveEncoderPID(Test, -70, 15, 0.7, 87, 0); // move to alliance stake
    TurnMaxTimePID(Test, 5, 0.5, 0); // face alliance stake
    wait(250, msec);
    MoveEncoderPID(Test, -50, 10, 0.2, 0, 0); // bump the wall
    RunLift(100); //raise wall stake
    wait(500, msec);
    RunLift(-100); // drop wall stake
    wait(250, msec);
    //RunRoller(100);
    MoveEncoderPID(Test, 70, 5, 0.3, 0, 0); // leave ring on alliance stake
    w25();
    TurnMaxTimePID(Test, 180, 0.4, 1);
    while(true) {
        w25();
    }
    



}