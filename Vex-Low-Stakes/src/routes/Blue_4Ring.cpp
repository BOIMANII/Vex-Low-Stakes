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
    wait(900, msec);
    RunRoller(100);// Intake preload, prepare to intake center
    wait(300, msec);
    TurnMaxTimePID(Test, -140, 0.7, 0); // Turn to face center rings
    MoveEncoderPID(Test, -75, 16.1, 0.2, -140, 0); // Drive into center rings
    wait(400, msec);// debug wait
    MoveEncoderPID(Test, 75, 9, 0.1, -147, 0); // Drive back
    TurnMaxTimePID(Test, -127, 0.7, 0); // Turn to face other center ring
    MoveEncoderPID(Test, -60, 12.75, 0.2, -127, 0); // Dive into other center ring
    wait(600, msec);//wait for ring to enter
    MoveEncoderPID(Test, 75, 17, 0.2, -126, 0); // Dive back
    wait(150, msec);
    TurnMaxTimePID(Test, -83, 0.7, 0); // Turn to face mid 2 stack
    MoveEncoderPID(Test, -75, 3, 0.2, -83, 0); // Dive into 2 mid stack
    wait(250, msec);
    TurnMaxTimePID(Test, -22.15, 0.8, 0); // Turn to face corner
    MoveEncoderPID(Test, -90, 45, 0.2, -22.15, 0); // Dive into corner
    wait(5, sec);
    //TurnMaxTimePID(Test, 361, 50, 1);
   

 
    
}