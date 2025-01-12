#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
\
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Skills() {
    //red side
    PIDDataSet Test={1.5,0.1,0.15}; //initialize
        RunRoller(-100);
        wait(250, msec);
        MoveEncoderPID(Test, -70, 10.4, 0.2, 0, 0); // move forward
        MoveEncoderPID(Test, -30, 1.5, 0.3, 0, 1); // Move to forawrd
        TurnMaxTimePID(Test, -90, 0.2, 0); // turn to face mogo
        TurnMaxTimePID(Test, -90, 0.2, 0); // turn to face mogo
        MoveEncoderPID(Test, 70, 28, 0.2, -90, 0); // move mogo
        MoveEncoderPID(Test, 30, 1.5, 0.3, -90, 1); // Move to mogo
        Clamp.set(true);
        wait(150, msec);
        TurnMaxTimePID(Test, -0, 0.2, 0); // turn to face ring
        TurnMaxTimePID(Test, -0, 0.2, 0); // turn to face ring
        MoveEncoderPID(Test, -70, 16, 0.2, 0, 0); // move to ring
        MoveEncoderPID(Test, -30, 1.5, 0.3, 0, 1); // Move to ring
        TurnMaxTimePID(Test, 45, 0.2, 0); // turn to face line
        TurnMaxTimePID(Test, 45, 0.2, 0); // turn to face line
        MoveEncoderPID(Test, -90, 45, 0.2, 45, 0); // move to line
        MoveEncoderPID(Test, -30, 13, 0.3, 45, 1); // Move to line
        
        TurnMaxTimePID(Test, 90, 0.2, 0); // turn to face wall steak
        TurnMaxTimePID(Test, 90, 0.2, 0); // turn to face wall steak
        MoveEncoderPID(Test, -70, 2, 0.2, 90, 0); // move to wall steak
        MoveEncoderPID(Test, -30, 1.5, 0.3, 90, 1); // Move to wall steak
        wait(500, msec);
        RunLift(50);
        wait(500, msec);
        RunLift(-50);
}