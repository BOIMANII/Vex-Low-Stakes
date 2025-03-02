#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
\
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red_5(){
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize right side!
    TurnMaxTimePID(Test, -50, 0.3, 0); // turn to alleyence steak
    RunLift(100); // secore unto alleynce steak
    wait(600, msec);
    MoveEncoderPID(Test, 70, 10.5, 0.3, -50, 0); //move bacc a bit
    RunLift(-100);
    wait(250, msec);
    TurnMaxTimePID(Test, 0, 0.3, 0); // turn to face mogo
    MoveEncoderPID(Test, 40, 19, 0.3, 0, 0); // back up into mogo
    wait(300, msec);
    Clamp.set(true);
    wait(250, msec);
    TurnMaxTimePID(Test, 90, 0.4, 0); // turn to face ring stack
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 9.5, 0.3, 90, 0); //intake ring
    wait(500, msec);
    TurnMaxTimePID(Test, -110, 1.0, 0); // turn to face ladder
    wait(500, msec);
    RunRoller(0); // stop roller
    MoveEncoderPID(Test, -50, 40, 0.3, -110, 0); //ladder
    RunLift(100); // touch ladder
    wait(1000, msec);
    RunLift(0); // touch ladder

}
    /*
    MoveEncoderPID(Test, 50, 5.0, 0.3, 0, 0); //leave line
    TurnMaxTimePID(Test, 60, 0.2, 0); // turn to mogo
    TurnMaxTimePID(Test, 60, 0.2, 0); // turn to mogo
    RunLift(0);
    MoveEncoderPID(Test, 100, 27, 0.3, 60, 0); //move to mogo
    MoveEncoderPID(Test, 50, 3, 0.3, 60, 0); // move/bump into mogo
    wait(400, msec);
    Clamp.set(true);
    wait(250, msec);
    RunRoller(-100); // start roller
    TurnMaxTimePID(Test, 150, 0.2, 0); // turn to face ring stack
    TurnMaxTimePID(Test, 150, 0.2, 0); // turn to face ring stack
    MoveEncoderPID(Test, -60, 9.5, 0.3, 150, 0); //intake ring
    wait(500, msec);
    TurnMaxTimePID(Test, -27, 1.0, 0); // turn to face ladder
    RunRoller(0); // stop roller
    MoveEncoderPID(Test, -50, 28, 0.3, -27, 0); //ladder
    */

    /* middle rings:
    TurnMaxTimePID(Test, 210, 0.2, 0); // turn to face ring stack
    TurnMaxTimePID(Test, 210, 0.2, 0); // turn to face ring stack
    
    MoveEncoderPID(Test, -100, 12, 0.3, 190, 0); //move to rings
    MoveEncoderPID(Test, -50, 3, 0.3, 190, 0); // move to rings
    TurnMaxTimePID(Test, 143, 0.2, 0); // turn to face other ring
    TurnMaxTimePID(Test, 143, 0.2, 0); // 
    MoveEncoderPID(Test, -100, 12, 0.2, 155, 0); //intake rings
    wait(250, msec);

    MoveEncoderPID(Test, 75, 30, 0.3, 0, 1); // Move to mogo v as well
    MoveEncoderPID(Test, 60, 1.5, 0.3, 0, 1); // Move to mogo
    
    Clamp.set(true);// Clamp mogo
    wait(200, msec);
    
    
    TurnMaxTimePID(Test, 139.7, 0.7, 0); // Turn to face center rings
    RunRoller(100);// Intake preload, prepare to intake center
    MoveEncoderPID(Test, -75, 18.4, 0.2, 139.7, 0); // Drive into center rings
    wait(300, msec);// debug wait
    MoveEncoderPID(Test, 75, 9, 0.1, 147, 0); // Drive back
    TurnMaxTimePID(Test, 131.5, 0.7, 0); // Turn to face other center ring
    MoveEncoderPID(Test, -60, 12.1, 0.2, 131.5, 0); // Dive into other center ring
    wait(400, msec);//wait for ring to enter
    MoveEncoderPID(Test, 75, 17, 0.2, 105, 0); // Dive back
    wait(150, msec);
    TurnMaxTimePID(Test, 93, 0.7, 0); // Turn to face mid 2 stack
    MoveEncoderPID(Test, -100, 10, 0.2, 93, 0); // Dive into 2 mid stack
    wait(250, msec);
    MoveEncoderPID(Test, 100, 13, 0.2, 81, 0); // Dive back
    //wait(600, msec);
    TurnMaxTimePID(Test, -35.7, 0.8, 0); // Turn to face 2 stack
    IntakeLift.set(false); //lift intake
    MoveEncoderPID(Test, -60, 30.2, 0.2, -35.7, 10); // Dive into 2 stack
    wait(500, msec);
    MoveEncoderPID(Test, 100, 18, 0.2, -35.4, 0); // Dive back
    IntakeLift.set(true); //lift intake
    TurnMaxTimePID(Test, 220, 0.8, 0); // Turn to face middle
    RunLift(100);
    MoveEncoderPID(Test, -50, 5, 0.2, 220, 10); // into middle
    
    wait(5, sec);
    //TurnMaxTimePID(Test, 361, 50, 1);
    */

 
    


void Blue_5(){
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize left side
    TurnMaxTimePID(Test, 50, 0.3, 0); // turn to alleyence steak
    RunLift(100); // secore unto alleynce steak
    wait(600, msec);
    MoveEncoderPID(Test, 70, 10.2, 0.3, 50, 0); //move bacc a bit
    RunLift(-100);
    wait(250, msec);
    TurnMaxTimePID(Test, 0, 0.3, 0); // turn to face mogo
    MoveEncoderPID(Test, 40, 19, 0.3, 0, 0); // back up into mogo
    Clamp.set(true);
    wait(250, msec);
    TurnMaxTimePID(Test, -90, 0.4, 0); // turn to face ring stack
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 9.5, 0.3, -90, 0); //intake ring
    wait(500, msec);
    TurnMaxTimePID(Test, 110, 1.0, 0); // turn to face ladder
    wait(500, msec);
    RunRoller(0); // stop roller
    MoveEncoderPID(Test, -50, 40, 0.3, 110, 0); //ladder
    RunLift(100); // touch ladder
    wait(1000, msec);
    RunLift(0); // touch ladder





    /*
    MoveEncoderPID(Test, 75, 38, 0.3, 0, 1); // Move to mogo v as well
    MoveEncoderPID(Test, 60, 1.5, 0.3, 0, 1); // Move to mogo
    
    Clamp.set(true);// Clamp mogo
    wait(200, msec);
    
    
    TurnMaxTimePID(Test, -139.7, 0.7, 0); // Turn to face center rings
    RunRoller(-100);// Intake preload, prepare to intake center
    MoveEncoderPID(Test, -75, 21, 0.2, -139.7, 0); // Drive into center rings
    wait(300, msec);// debug wait
    MoveEncoderPID(Test, 75, 10, 0.1, -147, 0); // Drive back
    TurnMaxTimePID(Test, -131.5, 0.7, 0); // Turn to face other center ring
    MoveEncoderPID(Test, -60, 12.2, 0.2, -131.5, 0); // Dive into other center ring
    wait(400, msec);//wait for ring to enter
    MoveEncoderPID(Test, 75, 17, 0.2, -105, 0); // Dive back
    wait(150, msec);
    TurnMaxTimePID(Test, -70, 0.7, 0); // Turn to face mid 2 stack
    MoveEncoderPID(Test, -100, 10, 0.2, -70, 0); // Dive into 2 mid stack
    wait(250, msec);
    MoveEncoderPID(Test, 100, 8, 0.2, -81, 0); // Dive back
    //wait(600, msec);
    TurnMaxTimePID(Test, 35, 0.8, 0); // Turn to face 2 stack
    IntakeLift.set(false); //lift intake
    MoveEncoderPID(Test, -60, 42, 0.2, 35, 10); // Dive into 2 stack
    wait(500, msec);
    MoveEncoderPID(Test, 100, 18, 0.2, 35.4, 0); // Dive back
    IntakeLift.set(true); //lift intake
    TurnMaxTimePID(Test, -220, 0.8, 0); // Turn to face middle
    RunLift(-100);
    MoveEncoderPID(Test, -50, 5, 0.2, -220, 10); // into middle
    
    wait(5, sec);
       
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
}