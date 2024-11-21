#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red_5(){
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    MoveEncoderPID(Test, 75, 30, 0.3, 0, 1); // Move to mogo v as well
    MoveEncoderPID(Test, 60, 1.5, 0.3, 0, 1); // Move to mogo
    
    Clamp.set(true);// Clamp mogo
    wait(200, msec);
    
    
    TurnMaxTimePID(Test, 139.7, 0.7, 0); // Turn to face center rings
    RunRoller(100);// Intake preload, prepare to intake center
    MoveEncoderPID(Test, -75, 18.3, 0.2, 139.7, 0); // Drive into center rings
    wait(300, msec);// debug wait
    MoveEncoderPID(Test, 75, 9, 0.1, 147, 0); // Drive back
    TurnMaxTimePID(Test, 127.53, 0.7, 0); // Turn to face other center ring
    MoveEncoderPID(Test, -60, 11.915, 0.2, 127.53, 0); // Dive into other center ring
    wait(400, msec);//wait for ring to enter
    MoveEncoderPID(Test, 75, 17, 0.2, 105, 0); // Dive back
    wait(150, msec);
    TurnMaxTimePID(Test, 79, 0.7, 0); // Turn to face mid 2 stack
    MoveEncoderPID(Test, -100, 10, 0.2, 79, 0); // Dive into 2 mid stack
    wait(250, msec);
    MoveEncoderPID(Test, 100, 13, 0.2, 81, 0); // Dive back
    wait(550, msec);
    TurnMaxTimePID(Test, -35.65, 0.8, 0); // Turn to face 2 stack
    IntakeLift.set(false); //lift intake
    MoveEncoderPID(Test, -90, 35.7, 0.2, -35.65, 10); // Dive into 2 stack
    wait(500, msec);
    MoveEncoderPID(Test, 100, 18, 0.2, -35.4, 0); // Dive back
    TurnMaxTimePID(Test, 220, 0.8, 0); // Turn to face middle
    RunLift(100);
    MoveEncoderPID(Test, -50, 5, 0.2, 220, 10); // into middle
    
    wait(5, sec);
    //TurnMaxTimePID(Test, 361, 50, 1);
   

 
    
}

void Blue_5(){
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    

    MoveEncoderPID(Test, 75, 26, 0.3, 0, 1); // Move to mogo v as well
    TurnMaxTimePID(Test, 30, 0.2, false);
    MoveEncoderPID(Test, 60, 6, 0.3, 45, 1); // Move to mogo
    wait(200, msec);
    Clamp.set(true);// Clamp mogo
    wait(100, msec);

    TurnMaxTimePID(Test, -90, 0.2, false);
    MoveEncoderPID(Test, 70, 5, 0.2, -90, false);
    

    TurnMaxTimePID(Test, -139.7, 0.7, 0); // Turn to face center rings
    RunRoller(100);// Intake preload, prepare to intake center
    MoveEncoderPID(Test, -75, 21, 0.2, -139.7, 0); // Drive into center rings
    wait(300, msec);// debug wait
    MoveEncoderPID(Test, 75, 9, 0.1, -147, 0); // Drive back
    TurnMaxTimePID(Test, -127.5, 0.7, 0); // Turn to face other center ring
    MoveEncoderPID(Test, -60, 14.5, 0.2, -127.5, 0); // Dive into other center ring
    wait(200, msec);//wait for ring to enter
    MoveEncoderPID(Test, 75, 17, 0.2, -105, 0); // Dive back
    wait(150, msec);
    TurnMaxTimePID(Test, -70, 0.7, 0); // Turn to face mid 2 stack
    MoveEncoderPID(Test, -100, 10, 0.2, -70, 0); // Dive into 2 mid stack
    wait(250, msec);

    TurnMaxTimePID(Test, -45, 0.2, false);
    


    /*
    MoveEncoderPID(Test, 100, 6, 0.2, -81, 0); // Dive back
    wait(100, msec);
    TurnMaxTimePID(Test, 42, 0.8, 0); // Turn to face 2 stack
    IntakeLift.set(false); //lift intake
    MoveEncoderPID(Test, -90, 36, 0.2, 42, 10); // Dive into 2 stack
    wait(550, msec);
    IntakeLift.set(true);
    wait(550, msec);
    MoveEncoderPID(Test, 100, 18, 0.2, 35.2, 0); // Dive back
    TurnMaxTimePID(Test, -220, 0.8, 0); // Turn to face middle
    RunLift(100);
    MoveEncoderPID(Test, -50, 6, 0.2, -220, 10); // into middle
    
    */
    wait(5, sec);
    
}