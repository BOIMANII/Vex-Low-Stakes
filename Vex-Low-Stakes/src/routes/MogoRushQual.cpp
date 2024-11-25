#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void MogoRushQual() {
    PIDDataSet Test={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(Test, 100, 58, 0.4, 0, true);//Grab mogo rush angled
    //OPMECH.set(true);
    MoveEncoderPID(Test, -100, 25, 0.4, 0, true );
    TurnMaxTimePID(Test, 30, 0.5, true);
    MoveEncoderPID(Test,-100,  36, 0.4, 30, true);
    TurnMaxTimePID(Test, 120, 0.5, true);
    //OPMECH.set(false);
   

    MoveEncoderPID(Test, -100, 6, 0.4, 120, true);
    
    TurnMaxTimePID(Test, -22, 0.7, true);
    MoveEncoderPID(Test, 100, 29, 0.4, -22, false);
     //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(400,msec);
    MoveEncoderPID(Test, 100, 2, 0.4,-22, true); //move back to let goal sit in
    //Tilt.set(false); // tilt mogo
    wait(100,msec);
    TurnMaxTimePID(Test, -90,  0.6, true);
    Pistake.set(false);
    RunRoller(-100);

    MoveEncoderPID(Test, -100, 30, 0.4, -90, true);
    wait(1800,msec);
    RunRoller(0);

}

void RedMogoRush()
{
    PIDDataSet Test={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(Test, -50, 1, 0.3, 0, 0); //move too alleynce steak
    TurnMaxTimePID(Test, 0, 0.3, 0);// turn 0 too alleynce steak
    TurnMaxTimePID(Test, 0, 0.3, 0);// turn 0 too alleynce steak
    MoveEncoderPID(Test, -50, 2.5, 0.3, 0, 0); // move intoo alleynce steak
    wait(250, msec);
    RunLift(100); // secore unto alleynce steak
    wait(500, msec);
    RunLift(-100);
    MoveEncoderPID(Test, 50, 3, 0.5, 0, 0); // moove bacc form alleynce steak


}