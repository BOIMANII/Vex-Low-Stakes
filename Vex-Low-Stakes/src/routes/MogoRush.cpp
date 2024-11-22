#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RMogo() {
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    MoveEncoderPID(Test, 100, 26, 0.3, 0, 0); // move to mogo
    MoveEncoderPID(Test, 50, 2, 0.2, 0, 0); // move little more
    wait(200, msec);
    Clamp.set(true);// Clamp mogo
    wait(100, msec);
    TurnMaxTimePID(Test, -90, 0.3, 0); // turn to ring
    TurnMaxTimePID(Test, -90, 0.3, 0); // turn to ring
    wait(250, msec);
    RunRoller(100);
    wait(250, msec);   
    MoveEncoderPID(Test, -70, 12, 0.2, -90, 0); // move to ring stack
    wait(250, msec);
    MoveEncoderPID(Test, 70, 12, 0.2, -90, 0); // move away from ring stack
    wait(1, seconds);
    RunLift(100);
    wait(500, msec);
    RunLift(0);
    MoveEncoderPID(Test, 100, 20, 0.3, -90, 0); // touch ladder
    wait(500, msec);
    RunRoller(0);
    wait(100, seconds);
}

void BMogo() {
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    /*
    RunRoller(100);
    MoveEncoderPID(Test, 50, 5, 0.3, 0, 0);
    TurnMaxTimePID(Test, 85, 0.2, 0); // turn to alliance stake.
    MoveEncoderPID(Test, -70, 14, 0.7, 87, 0); // move to alliance stake
    TurnMaxTimePID(Test, 5, 0.5, 0); // face alliance stake
    wait(250, msec);
    MoveEncoderPID(Test, -50, 14, 0.2, 0, 1); // bump the wall
    wait(200, msec);
    RunLift(100); //raise wall stake
    wait(500, msec);
    RunLift(-100); // drop wall stake
    wait(250, msec);
    MoveEncoderPID(Test, 70, 5, 0.3, 0, 0); // leave ring on alliance stake
    wait(500, msec);
    TurnMaxTimePID(Test, 180, 0.4, 1);
    wait(100, seconds);
    */

    
    MoveEncoderPID(Test, 100, 26, 0.3, 0, 0); // move to mogo
    MoveEncoderPID(Test, 50, 2, 0.2, 0, 0); // move little more
    wait(200, msec);
    Clamp.set(true);// Clamp mogo
    wait(100, msec);
    TurnMaxTimePID(Test, -90, 0.3, 0); // turn to ring
    TurnMaxTimePID(Test, -90, 0.3, 0); // turn to ring
    wait(250, msec);
    RunRoller(100);
    wait(250, msec);   
    MoveEncoderPID(Test, -70, 12, 0.2, -90, 0); // move to ring stack
    wait(250, msec);
    MoveEncoderPID(Test, 70, 12, 0.2, -90, 0); // move away from ring stack
    wait(1, seconds);
    RunLift(100);
    wait(500, msec);
    RunLift(0);
    MoveEncoderPID(Test, 100, 20, 0.3, -90, 0); // touch ladder
    wait(500, msec);
    RunRoller(0);
    wait(100, seconds);
    
}