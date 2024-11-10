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
    MoveEncoderPID(Test, 75, 34, 0.3, 0, 1); // move to mogo
    wait(250, msec);
    Clamp.set(true);// clamp mogo
    wait(1500, msec);
    RunRoller(100);//intakepreload, prepare to intake center
    wait(250, msec);
    TurnMaxTimePID(Test, -140, 0.7, 0); // turn to face center rings
    MoveEncoderPID(Test, -75, 13.1, 0.2, -140, 0); // drive into center rings
    wait(500, msec);// debug wait
    MoveEncoderPID(Test, 60, 9, 0.1, -147, 0); // drive back
    TurnMaxTimePID(Test, -125, 0.7, 0); // turn to face other center ring
    MoveEncoderPID(Test, -50, 8, 0.2, 50, 0); // dive into other center ring
    MoveEncoderPID(Test, 50, 5, 0.2, 50, 0); // dive back
    wait(500, msec);
    TurnMaxTimePID(Test, 50, 0.8, 0); // turn to face mid 2 stack
    MoveEncoderPID(Test, -50, 9, 0.2, 50, 0); // dive into 2 stack
    wait(5, sec);

   

 
    
}