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
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    MoveEncoderPID(Test, 75, 32.5, 0.3, 0, 1); // Move to mogo v as well
    MoveEncoderPID(Test, 60, 1.5, 0.3, 0, 1); // Move to mogo
    wait(250, msec);
    Clamp.set(true);// Clamp mogo
    wait(1500, msec);
    RunRoller(100);// Intake preload, prepare to intake center
    wait(250, msec);
    TurnMaxTimePID(Test, -140, 0.7, 0); // Turn to face center rings
    MoveEncoderPID(Test, -75, 13.1, 0.2, -140, 0); // Drive into center rings
    wait(500, msec);// debug wait
    MoveEncoderPID(Test, 40, 9, 0.1, -147, 0); // Drive back
    TurnMaxTimePID(Test, -125, 0.7, 0); // Turn to face other center ring
    MoveEncoderPID(Test, -50, 9, 0.2, -125, 0); // Dive into other center ring
    wait(500, msec);//wait for ring to enter
    MoveEncoderPID(Test, 50, 12, 0.2, 50, 0); // Dive back
    wait(500, msec);
    TurnMaxTimePID(Test, 0, 0.8, 0); // Turn to face mid 2 stack
    MoveEncoderPID(Test, -50, 9, 0.2, 0, 0); // Dive into 2 stack
    wait(5, sec);
    TurnMaxTimePID(Test, 361, 50, 1);
   

 
    
}