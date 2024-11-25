#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RMogo() {
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    int t = 0;
    if (t == 1) {
        RunRoller(100); // start roller

        MoveEncoderPID(Test, 50, 5, 0.3, 0, 0); //leave line
        TurnMaxTimePID(Test, 90, 0.3, 0); // turn 90 to move to mogo
        TurnMaxTimePID(Test, 90, 0.3, 0); // turn 90 to move to mogo
        MoveEncoderPID(Test, -100, 12, 0.2, 90, 0);
        MoveEncoderPID(Test, -30, 12, 0.3, 90, 0);
        TurnMaxTimePID(Test, 0, 0.3, 0);
        TurnMaxTimePID(Test, 0, 0.3, 0);
        MoveEncoderPID(Test, -100, 10, 0.3, 0, 0);
        MoveEncoderPID(Test, -50, 2.5, 0.3, 0, 0);
        wait(250, msec);
        RunLift(100);
        wait(500, msec);
        RunLift(-100);
        MoveEncoderPID(Test, 50, 3, 0.5, 0, 0);
        RunLift(0);
        TurnMaxTimePID(Test, 37, 0.3, 0);
        TurnMaxTimePID(Test, 37, 0.3, 0);
        MoveEncoderPID(Test, 100, 18, 0.5, 37, 0);
        MoveEncoderPID(Test, 50, 18, 0.3, 37, 0);
        Clamp.set(true);// Clamp mogo
        wait(250, msec);
        TurnMaxTimePID(Test, -90, 0.3, 0);
        TurnMaxTimePID(Test, -90, 0.3, 0);
        MoveEncoderPID(Test, -75, 7, 0.5, -90, 0);
        wait(500, msec);
        TurnMaxTimePID(Test, -45, 0.4, 0);
        TurnMaxTimePID(Test, -45, 0.4, 0);
        RunLift(100);
        wait(250, msec);
        RunLift(0);
        MoveEncoderPID(Test, 100, 36, 0.3, -45, 1);
        wait(100000, seconds);
    }
    else if (t == 0) {
        MoveEncoderPID(Test, 100, 30 , 0.3, 0, 0); //move too alleynce steak
        TurnMaxTimePID(Test, -45, 0.3, 0);// turn 90 too alleynce steak
        TurnMaxTimePID(Test, -45, 0.3, 0);// turn 90 too alleynce steak
        MoveEncoderPID(Test, 35, 5 , 0.3, 0, 0); //move too alleynce steak
        /*
        MoveEncoderPID(Test, -50, 2.5, 0.3, -90, 0); // move intoo alleynce steak
        wait(250, msec);
        RunLift(100); // secore unto alleynce steak
        wait(500, msec);
        MoveEncoderPID(Test, 50, 3, 0.5, -90, 0); // moove bacc form alleynce steak
        RunLift(-100);
        TurnMaxTimePID(Test, -45, 0.3, 0);// turn 90 too alleynce steak
        RunLift(0);
        TurnMaxTimePID(Test, -45, 0.3, 0);// turn 90 too alleynce steak
        MoveEncoderPID(Test, 100, 25, 0.5, -45, 0); // moove bacc form alleynce steak
        MoveEncoderPID(Test, 50, 25, 0.5, -45, 0); // moove bacc form alleynce steak
        /*
        MoveEncoderPID(Test, 75, 26, 0.3, 0, 0); // move to mogo
        MoveEncoderPID(Test, 50, 2, 0.2, 0, 0); // move little more
        wait(200, msec);
        Clamp.set(true);// Clamp mogo
        wait(100, msec);
        TurnMaxTimePID(Test, -87, 0.3, 0); // turn to ring
        TurnMaxTimePID(Test, -87, 0.3, 0); // turn to ring
        wait(250, msec);
        RunRoller(100);
        wait(250, msec);   
        MoveEncoderPID(Test, -70, 13, 0.2, -90, 0); // move to ring stack
        wait(400, msec);
        MoveEncoderPID(Test, 70, 12, 0.2, -90, 0); // move away from ring stack
        wait(1.8, seconds);
        TurnMaxTimePID(Test, -200, 0.3, 0); // turn to mid
        RunLift(100);
        wait(500, msec);
        MoveEncoderPID(Test, -70, 12, 0.2, -200, 0); // move to mid
        wait(1, seconds);
        RunLift(100);
        
        RunLift(0);

        
        wait(500, msec);
        RunRoller(0);
        wait(100, seconds);
        */

    
    }
}

void BMogo() {
    PIDDataSet Test={1.5,0.1,0.15}; // Initialize
    int n = 1;
    if (n == 1) {
        

        //MoveEncoderPID(Test, 50, 5, 0.3, 0, 0);
        //RunRoller(100); // start roller

        //MoveEncoderPID(Test, 50, 1, 0.3, 0, 0); //leave line
        TurnMaxTimePID(Test, -90, 0.3, 0); // turn 90 to move to mogo
        TurnMaxTimePID(Test, -90, 0.3, 0); // turn 90 to move to mogo
        MoveEncoderPID(Test, -100, 12, 0.2, -90, 0);
        MoveEncoderPID(Test, -30, 14.5, 0.3, -90, 0);
        TurnMaxTimePID(Test, 0, 0.3, 0);
        TurnMaxTimePID(Test, 0, 0.3, 0);
        //MoveEncoderPID(Test, -100, 2, 0.3, 0, 0);//drive in to alleynce steak
        MoveEncoderPID(Test, -50, 2.5, 0.3, 0, 0);
        wait(250, msec);
        RunLift(100);
        
        wait(500, msec);
        MoveEncoderPID(Test, 50, 2.5, 0.3, 0, 0);
        RunLift(-100);
        MoveEncoderPID(Test, 50, 3, 0.5, 0, 0);
        RunLift(0);
        RunRoller(100); // start roller
        TurnMaxTimePID(Test, -42, 0.3, 0);// turn to mogo
        TurnMaxTimePID(Test, -42, 0.3, 0);
        MoveEncoderPID(Test, 100, 21, 0.5, -42, 0);
        MoveEncoderPID(Test, 50, 21, 0.3, -42, 0);
        Clamp.set(true);// Clamp mogo
        wait(250, msec);
        TurnMaxTimePID(Test, 90, 0.3, 0);
        TurnMaxTimePID(Test, 90, 0.3, 0);
        MoveEncoderPID(Test, -75, 8.5, 0.5, 90, 0);
        wait(500, msec);
        MoveEncoderPID(Test, 75, 4, 0.5, 90, 0);
        TurnMaxTimePID(Test, 45, 0.4, 0);
        TurnMaxTimePID(Test, 45, 0.4, 0);
        //RunLift(100);
        //wait(250, msec);
        //RunLift(0);
        //TurnMaxTimePID(Test, -120, 0.4, 0);
        //TurnMaxTimePID(Test, -120, 0.4, 0);
        //MoveEncoderPID(Test, -100, 36, 0.3, -250, 1);

        wait(100000, seconds);
    
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
    }
    else if (n == 0) {
    
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
}