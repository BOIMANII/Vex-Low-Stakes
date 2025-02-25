#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
// are we cooked? are we cooking?
/*
    while (fabs(LiftSensor.position(degrees)) < 19)//marco
        RunLift(40);
    Lift.setStopping(hold);
    Lift.stop();
*/
///*
void SkillsMacro() {
    while(LiftSensor.position(degrees) > 342){
        RunLift(40);
    }
    Lift.setStopping(hold);
    Lift.stop();
}
//*/
void Skills(){
        
    Zeroing(true,true);
    LiftSensor.setPosition(359.9, degrees);
    PIDDataSet Test={1.5,0.1,0.15};
    RunRoller(-100);
    wait(400, msec);
    MoveEncoderPID(Test, -50, 4, 0.4, 0, 0);//move bacc
    RunRoller(0);
    TurnMaxTimePID(Test, -90, 0.3, 0);//turn to face mogo
    MoveEncoderPID(Test, 100, 11, 0.4, -90, 0);//go to mogo
    MoveEncoderPID(Test, 50, 23, 0.3, -90, 1);
    Clamp.set(true);
    wait(400, msec);
    TurnMaxTimePID(Test, 0, 0.3, 1);//turn to face ring
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 21, 0.7, 0, 1);//get ring
    TurnMaxTimePID(Test, 22, 0.1, 1 );//turn to line
    MoveEncoderPID(Test, -70, 75, 0.7, 22, 1);//move to far ring
    wait(250, msec);
    TurnMaxTimePID(Test, 18, 0.1, 1);//turn to wall steak
    MoveEncoderPID(Test, 70, 23, 0.7, 18, 1);//move to line
    TurnMaxTimePID(Test, 90, 0.3, 1);//turn to wall steak
    SkillsMacro();
    MoveTimePID(Test, 50, 1, 0.2, 90, 0); // move to wall steak
    wait(1000, msec);
    RunRoller(0); // stop running lift
    RunLift(100); // run wall stakes mech
    MoveEncoderPID(Test, -50, 3, 0.2, 90, 0); // score steak
    wait(250, msec);
    RunLift(-100);
    wait(250, msec);
    MoveEncoderPID(Test, 70, 2.8, 0.2, 90, 0); // move back from wall steak
    TurnMaxTimePID(Test, 180, 0.4, 0); // turn to face rings
    RunLift(0);
    RunRoller(-150);
    MoveEncoderPID(Test, -50, 75, 0.2, 180, 0); // intake rings
    wait(500, msec);
    MoveEncoderPID(Test, 70, 8, 0.2, 130, 0); // back up
    TurnMaxTimePID(Test, 90, 0.4, 0); // turn to face ring
    MoveEncoderPID(Test, -70, 12, 0.2, 90, 0); // get ring
    wait(250, msec);
    MoveEncoderPID(Test, 60, 2.0, 0.2, 55, true); // back up
    TurnMaxTimePID(Test, -30, 0.3, 0); // turn to face pos corner
    MoveTimePID(Test, -70, 1.0, 0.2, -30, 0); // move into corner
    RunRoller(0);
    wait(250, msec);
    Clamp.set(false);
    wait(400, msec);
    MoveEncoderPID(Test, -50, 2.5, 0.2, -45, 0); // move out of corner
    TurnMaxTimePID(Test, 90, 0.6, 0); // turn to face mogo
    MoveEncoderPID(Test, 90, 85, 0.2, 90, 0); // move to mogo
    MoveEncoderPID(Test, 30, 38, 0.3, 90, 1); // Move to mogo
    wait(250, msec);
    Clamp.set(true);
    wait(400, msec);
    TurnMaxTimePID(Test, 0, 0.3, 1);//turn to face ring
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 20, 0.7, 0, 1);//get ring
    TurnMaxTimePID(Test, -24, 0.1, 1 );//turn to line
    MoveEncoderPID(Test, -60, 78, 0.7, -24, 1);//move to far ring
    wait(400, msec);
    TurnMaxTimePID(Test, -12, 0.1, 1);//turn to wall steak
    MoveEncoderPID(Test, 70, 22, 0.7, -12, 1);//move to line
    TurnMaxTimePID(Test, -90, 0.3, 1);//turn to wall steak
    SkillsMacro();
    MoveTimePID(Test, 50, 1, 0.2, -90, 0); // move to wall steak
    wait(1000, msec);
    RunRoller(0); // stop running lift
    RunLift(100); // run wall stakes mech
    MoveEncoderPID(Test, -50, 3, 0.2, -90, 0); // score steak
    wait(250, msec);
    RunLift(-100);
    wait(250, msec);
    MoveEncoderPID(Test, 70, 5.2, 0.2, -90, 0); // move back from wall steak
    TurnMaxTimePID(Test, -180, 0.3, 0); // turn to face rings
    RunLift(0);
    RunRoller(-150);
    MoveEncoderPID(Test, -45, 71, 0.2, -180, 0); // intake rings
    wait(1250, msec);
    MoveEncoderPID(Test, 70, 8, 0.2, -130, 0); // back up
    TurnMaxTimePID(Test, -90, 0.4, 0); // turn to face ring
    MoveEncoderPID(Test, -70, 12, 0.2, -90, 0); // get ring
    wait(250, msec);
    MoveEncoderPID(Test, 60, 2.0, 0.2, -60, true); // back up
    wait(250, msec);
    TurnMaxTimePID(Test, 30, 0.3, 0); // turn to face pos corner
    MoveTimePID(Test, -70, 1.0, 0.2, 30, 0); // move into corner
    RunRoller(0);
    wait(250, msec);
    Clamp.set(false);
    wait(400, msec);
    TurnMaxTimePID(Test, 0, 0.1, 0); // turn to face other side
    MoveEncoderPID(Test, -100, 110, 0.2, 0, 1); // move move to other side
    TurnMaxTimePID(Test, 90, 0.3, 0);//turn to face ring
    SkillsMacro();
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 16, 0.2, 90, 0); // move forward get red ring for steak
    wait(400, msec);
    TurnMaxTimePID(Test, 0, 0.3, 0);//turn to face mogo with blue ring
    MoveEncoderPID(Test, -70, 37, 0.2, 0, 0); // move to mogo w blue ring
    TurnMaxTimePID(Test, -80, 0.3, 0);//turn to face neg corner
    MoveEncoderPID(Test, -70, 66, 0.2, -80, 0); // push into corner
    MoveEncoderPID(Test, 70, 51, 0.2, -80, 0); // move back towards mogo
    TurnMaxTimePID(Test, -55, 0.2, 0);//turn to face mogo
    MoveEncoderPID(Test, 50, 11, 0.2, -55, 0); // move back into mogo
    Clamp.set(true);
    wait(250, msec);
    TurnMaxTimePID(Test, -15, 0.3, 0);//turn to alleynce steak
    MoveEncoderPID(Test, -70, 20, 0.2, -15, 1); // move towards alleynce steak
    wait(200, msec);
    MoveEncoderPID(Test, 70, 5.5, 0.3, 0, 1);
    RunRoller(0);
    RunLift(100); // run wall stakes mech
    wait(750, msec);
    MoveEncoderPID(Test, 70, 4, 0.3, -10, 1);
    RunLift(-100);
    TurnMaxTimePID(Test, 130, 0.5, 0);//turn to red rings
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 13, 0.2, 130, 0); // pick up single ring
    RunLift(0);
    wait(400, msec);
    TurnMaxTimePID(Test, 45, 0.2, 0);//turn to other red ring
    MoveEncoderPID(Test, -70, 22, 0.2, 45, 0); // pick up ring
    wait(400, msec);
    TurnMaxTimePID(Test, 90, 0.2, 0);//turn to other red ring
    MoveEncoderPID(Test, -50, 8, 0.2, 90, 0); // pick up ring
    wait(400, msec);
    
    MoveEncoderPID(Test, 70, 5, 0.2, 50, 0); // back up
    TurnMaxTimePID(Test, 10, 0.3, 0);//turn to other red ring
    wait(250, msec);
    MoveEncoderPID(Test, -60, 9, 0.2, 10, 0); // pick up ring
    wait(400, msec);
    MoveEncoderPID(Test, 60, 3, 0.2, -60, 0); // back
    Doinker.set(true);
    TurnMaxTimePID(Test, 60, 0.5, 0);//turn to clear
    TurnMaxTimePID(Test, -130, 0.5, 0);//turn to corner
    Doinker.set(false);
    MoveTimePID(Test, -70, 1.0, 0.2, -130, 0); // move into corner
    RunRoller(0);
    Clamp.set(false);
    wait(400, msec);
    MoveEncoderPID(Test, -70, 6, 0.2, -130, 0); // out of corner
    TurnMaxTimePID(Test, 42, 0.6, 0);//turn to climb
    RunLift(100); // run wall stakes mech
    wait(400, msec);
    RunLift(-100);
    RunLift(0);
    MoveEncoderPID(Test, 70, 45, 0.2, 42, 0); // out of corner
    MoveEncoderPID(Test, 50, 35, 0.2, 42, 0); // out of corner

}
        /*
        TurnMaxTimePID(Test, 0, 0.3, 0);//turn to alleynce steak
        MoveEncoderPID(Test, -55, 10, 0.2, 0, 1); // move towards alleynce steak
        wait(200, msec);
        MoveEncoderPID(Test, 55, 4, 0.3, 0, 1);
        RunRoller(-100);
        wait(200, msec);
        RunRoller(0);
        RunLift(80); // run wall stakes mech
        wait(750, msec);
        RunLift(-100);
        wait(400, msec);
        RunLift(0);
        

        
        
        RunRoller(-100);
        wait(500, msec);
        MoveEncoderPID(Test, -40, 4, 0.3, 0, 0); // move forward
        RunRoller(0);
        wait(250, msec);
        TurnMaxTimePID(Test, -90, 0.8, 0); // turn to face mogo
        MoveEncoderPID(Test, 50, 25, 0.2, -90, 0); // move mogo
        MoveEncoderPID(Test, 30, 10, 0.3, -90, 1); // Move to mogo
        Clamp.set(true);
        wait(750, msec);
        TurnMaxTimePID(Test, -0, 1.0, 0); // turn to face ring
        RunRoller(-100);
        MoveEncoderPID(Test, -70, 16, 0.2, 0, 0); // move to ring
        MoveEncoderPID(Test, -30, 2.5, 0.3, 0, 1); // Move to ring
        TurnMaxTimePID(Test, 40, 0.5, 0); // turn to face line
        MoveEncoderPID(Test, -60, 50.5, 0.2, 40, 0); // move to line
        TurnMaxTimePID(Test, 90, 0.5, 0); // turn to face wall steak
        SkillsMacro();
        MoveEncoderPID(Test, -70, 4, 0.2, 90, 0); // move to wall steak
        wait(1300, msec);
        RunRoller(0);
        RunLift(100);
        wait(500, msec);
        MoveEncoderPID(Test, 70, 2.5, 0.2, 90, 0); // move back from wall steak
        RunLift(-100);
        wait(350, msec);
        RunLift(0);
        RunRoller(-150);
        TurnMaxTimePID(Test, 180, 1.0, 0); // turn to face rings
        MoveEncoderPID(Test, -50, 90, 0.2, 180, 0); // intake rings
        wait(1000, msec);
        MoveEncoderPID(Test, 50, 35, 0.4, 180, 0); // move back from wall 
        TurnMaxTimePID(Test, 145, 0.4, 0); // turn to face ring
        MoveEncoderPID(Test, -50, 10, 0.2, 145, 0); // get ring
        wait(500, msec);
        TurnMaxTimePID(Test, -47, 1.0, 0); // turn to face pos corner
        MoveTimePID(Test, -30, 1.2, 0.2, -47, 0); // move into corner
        RunRoller(0);
        wait(250, msec);
        Clamp.set(false);
        MoveEncoderPID(Test, -50, 2, 0.2, -45, 0); // move out of corner
        TurnMaxTimePID(Test, 90, 1.5, 0); // turn to face mogo

 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


        MoveEncoderPID(Test, 70, 115, 0.2, 90, 0); // move to mogo
        MoveEncoderPID(Test, 30, 10, 0.3, 90, 1); // Move to mogo
        Clamp.set(true);
        wait(500, msec);
        TurnMaxTimePID(Test, -0, 1.0, 0); // turn to face ring
        RunRoller(-100);
        MoveEncoderPID(Test, -70, 4, 0.2, 0, 0); // move to ring
        wait(250, msec);
        TurnMaxTimePID(Test, -40, 0.5, 0); // turn to face line
        MoveEncoderPID(Test, -60, 50.5, 0.2, -40, 0); // move to line
        TurnMaxTimePID(Test, -90, 0.5, 0); // turn to face wall steak
        SkillsMacro();
        MoveEncoderPID(Test, -70, 4, 0.2, -90, 0); // move to wall steak
        wait(1300, msec);
        RunRoller(0);
        RunLift(100);
        wait(500, msec);
        RunLift(-100);
        wait(350, msec);
        RunLift(0);
        MoveEncoderPID(Test, 70, 2.5, 0.2, -90, 0); // move back from wall steak
        RunRoller(-150);
        TurnMaxTimePID(Test, -180, 1.0, 0); // turn to face rings
        MoveEncoderPID(Test, -50, 90, 0.2, -180, 0); // intake rings
        wait(1000, msec);
        MoveEncoderPID(Test, 50, 35, 0.4, -180, 0); // move back from wall 
        TurnMaxTimePID(Test, -145, 0.4, 0); // turn to face ring
        MoveEncoderPID(Test, -50, 10, 0.2, -145, 0); // get ring
        wait(500, msec);
        TurnMaxTimePID(Test, 47, 1.0, 0); // turn to face pos corner
        MoveTimePID(Test, -30, 1.2, 0.2, 47, 0); // move into corner
        RunRoller(0);
        wait(250, msec);
        Clamp.set(false);
        MoveEncoderPID(Test, -50, 2, 0.2, 45, 0); // move out of corner
*/
