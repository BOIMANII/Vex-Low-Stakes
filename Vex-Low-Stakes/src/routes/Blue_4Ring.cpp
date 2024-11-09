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
    wait(750, msec);
    RunRoller(100);//intakepreload, prepare to intake center
    TurnMaxTimePID(Test, -147, 0.7, 0); // turn to face center rings
    MoveEncoderPID(Test, -75, 12.9, 0.2, -147, 0); // drive into center rings
    wait(500, msec);// debug wait
    TurnMaxTimePID(Test, -90, 0.7, 0); // turn to face other ring   
    MoveEncoderPID(Test, -45, 13, 0.1, -90, 0); // drive into other ring
    wait(250, msec);
    TurnMaxTimePID(Test, 37, 0.7, 0);
    MoveEncoderPID(Test, -50, 10, 0.2, 40, 0);
    wait(5, sec);

   

 
    
}