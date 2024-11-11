#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red_4Ring(){
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    MoveEncoderPID(Test, 75, 32.5, 0.3, 0, 1); // Move to mogo v as well
    MoveEncoderPID(Test, 60, 1.5, 0.3, 0, 1); // Move to mogo
    wait(250, msec);
    Clamp.set(true);// Clamp mogo
    wait(300, msec);
    RunRoller(100);// Intake preload, prepare to intake center
    wait(300, msec);
    TurnMaxTimePID(Test, 139.6, 0.7, 0); // Turn to face center rings
    MoveEncoderPID(Test, -75, 16, 0.2, 139.6, 0); // Drive into center rings
    wait(400, msec);// debug wait
    MoveEncoderPID(Test, 75, 9, 0.1, 147, 0); // Drive back
    TurnMaxTimePID(Test, 127.53, 0.7, 0); // Turn to face other center ring
    MoveEncoderPID(Test, -60, 11.9, 0.2, 127.53, 0); // Dive into other center ring
    wait(500, msec);//wait for ring to enter
    MoveEncoderPID(Test, 75, 17, 0.2, 105, 0); // Dive back
    wait(50, msec);
    TurnMaxTimePID(Test, 80, 0.7, 0); // Turn to face mid 2 stack
    MoveEncoderPID(Test, -100, 10, 0.2, 80, 0); // Dive into 2 mid stack
    wait(150, msec);
    MoveEncoderPID(Test, 100, 10, 0.2, 81, 0); // Dive back
    TurnMaxTimePID(Test, 40, 0.8, 0); // Turn to face corner
    MoveEncoderPID(Test, -90, 67, 0.2, 40, 10); // Dive into corner
    wait(5, sec);
    //TurnMaxTimePID(Test, 361, 50, 1);
   

 
    
}  