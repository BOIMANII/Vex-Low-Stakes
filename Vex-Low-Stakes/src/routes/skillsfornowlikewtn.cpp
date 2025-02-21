#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
void SkillsMacro() {
    while(LiftSensor.position(degrees) > 342){
        RunLift(40);
    }
    Lift.setStopping(hold);
    Lift.stop();
}
void RMogo() {
    Zeroing(true,true);
    LiftSensor.setPosition(359.9, degrees);
    PIDDataSet Test={1.5,0.1,0.15};
    RunRoller(-100);
    wait(500, msec);
    MoveEncoderPID(Test, -50, 5, 0.4, 0, 0);//move bacc
    RunRoller(0);
    TurnMaxTimePID(Test, -90, 0.3, 0);//turn to face mogo
    MoveEncoderPID(Test, 100, 20, 0.4, -90, 0);//go to mogo
    MoveEncoderPID(Test, 30, 16, 0.3, -90, 1);
    Clamp.set(true);
    wait(500, msec);
    TurnMaxTimePID(Test, 0, 0.3, 1);//turn to face ring
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 20, 0.7, 0, 1);//get ring
    TurnMaxTimePID(Test, 22, 0.1, 1 );//turn to line
    MoveEncoderPID(Test, -70, 75, 0.7, 22, 1);//move to far ring
    wait(300, msec);
    TurnMaxTimePID(Test, 13, 0.1, 1);//turn to wall steak
    MoveEncoderPID(Test, 70, 19.5, 0.7, 13, 1);//move to line
    TurnMaxTimePID(Test, 90, 0.3, 1);//turn to wall steak
    SkillsMacro();
    MoveEncoderPID(Test, -70, 19, 0.7, 90, 1); // move towards wall stake
    wait(1100, msec);
    RunRoller(0); // stop running lift
    RunLift(100); // run wall stakes mech
    MoveTimePID(Test, 30, 0.5, 0.2, 90, 0); // score stake
    RunLift(-100);
    wait(750, msec);
    MoveEncoderPID(Test, 70, 4.2, 0.2, 90, 0); // move back from wall steak
    RunLift(0);
    RunRoller(-150);
    TurnMaxTimePID(Test, 180, 0.4, 0); // turn to face rings
    MoveEncoderPID(Test, -50, 69, 0.2, 180, 0); // intake rings
    wait(1250, msec);
    TurnMaxTimePID(Test, 58, 0.4, 0); // turn to face ring
    MoveEncoderPID(Test, -60, 10, 0.2, 58, 0); // get ring
    wait(250, msec);
    MoveEncoderPID(Test, 60, 1.8, 0.2, 55, true); // back up
    TurnMaxTimePID(Test, -30, 0.3, 0); // turn to face pos corner
    MoveTimePID(Test, -70, 1.0, 0.2, -30, 0); // move into corner
    RunRoller(0);
    wait(250, msec);
    Clamp.set(false);
    wait(500, msec);
    MoveEncoderPID(Test, -50, 3, 0.2, -45, 0); // move out of corner
    TurnMaxTimePID(Test, 90, 0.6, 0); // turn to face mogo
    MoveEncoderPID(Test, 90, 85, 0.2, 90, 0); // move to mogo
    MoveEncoderPID(Test, 30, 36, 0.3, 90, 1); // Move to mogo
    wait(250, msec);
    Clamp.set(true);
    wait(500, msec);
    TurnMaxTimePID(Test, 0, 0.3, 1);//turn to face ring
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 20, 0.7, 0, 1);//get ring
    TurnMaxTimePID(Test, -22, 0.1, 1 );//turn to line
    MoveEncoderPID(Test, -70, 78, 0.7, -22, 1);//move to far ring
    wait(600, msec);
    TurnMaxTimePID(Test, -17, 0.1, 1);//turn to wall steak
    MoveEncoderPID(Test, 70, 19.5, 0.7, -17, 1);//move to line
    TurnMaxTimePID(Test, -90, 0.3, 1);//turn to wall steak
    SkillsMacro();
    MoveEncoderPID(Test, -70, 26, 2, -90, 1); // move towards wall stake
    wait(1300, msec);
    RunRoller(0); // stop running lift
    RunLift(100); // run wall stakes mech
    MoveTimePID(Test, 30, 0.6, 0.2, -90, 0); // score stake
    wait(250, msec);
    RunLift(-100);
    wait(400, msec);
    MoveEncoderPID(Test, 70, 5.5, 0.2, -90, 0); // move back from wall steak
    RunLift(0);
    RunRoller(-150);
    TurnMaxTimePID(Test, -180, 0.3, 0); // turn to face rings
    MoveEncoderPID(Test, -45, 69, 0.2, -180, 0); // intake rings
    wait(1250, msec);
    TurnMaxTimePID(Test, -60, 0.4, 0); // turn to face ring
    MoveEncoderPID(Test, -60, 12, 0.2, -60, 0); // get ring
    MoveEncoderPID(Test, 60, 1.8, 0.2, -60, true); // back up
    wait(500, msec);
    TurnMaxTimePID(Test, 30, 0.3, 0); // turn to face pos corner
    MoveTimePID(Test, -70, 1.0, 0.2, 30, 0); // move into corner
    RunRoller(0);
    wait(250, msec);
    Clamp.set(false);
    wait(400, msec);
    MoveEncoderPID(Test, -50, 1.5, 0.2, 47, 0); // move out of corner
    TurnMaxTimePID(Test, 0, 0.3, 0); // turn to face other side
    MoveEncoderPID(Test, -90, 99, 0.2, 0, 0); // move move to other side
    
    TurnMaxTimePID(Test, 90, 0.3, 0);//turn to face ring
    
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 15, 0.2, 90, 0); // move forward
    wait(500, msec);
    TurnMaxTimePID(Test, 0, 0.3, 0);//turn to face mogo with blue ring
    RunRoller(0);
    MoveEncoderPID(Test, -70, 32, 0.2, 0, 0); // move to mogo w blue ring
    TurnMaxTimePID(Test, -80, 0.3, 0);//turn to face neg corner
    MoveEncoderPID(Test, -70, 67, 0.2, -80, 0); // push into corner
    MoveEncoderPID(Test, 70, 51, 0.2, -80, 0); // move back towards mogo
    TurnMaxTimePID(Test, -45, 0.2, 0);//turn to face mogo
    MoveEncoderPID(Test, 50, 15, 0.2, -45, 0); // move back into mogo
    Clamp.set(true);
    wait(400, msec);
    TurnMaxTimePID(Test, 130, 0.5, 0);//turn to red rings
    RunRoller(-100);
    MoveEncoderPID(Test, -70, 11, 0.2, 130, 0); // pick up ring
    wait(700, msec);
    TurnMaxTimePID(Test, 45, 0.2, 0);//turn to other red ring
    MoveEncoderPID(Test, -70, 21, 0.2, 45, 0); // pick up ring
    wait(400, msec);
    TurnMaxTimePID(Test, 90, 0.2, 0);//turn to other red ring
    MoveEncoderPID(Test, -50, 7, 0.2, 90, 0); // pick up ring
    wait(400, msec);
    MoveEncoderPID(Test, 70, 4, 0.2, 75, 0); // pick up ring
    TurnMaxTimePID(Test, 10, 0.3, 0);//turn to other red ring
    wait(250, msec);
    MoveEncoderPID(Test, -50, 6, 0.2, 10, 0); // pick up ring
    wait(400, msec);
    MoveEncoderPID(Test, 60, 3, 0.2, -60, 0); // back 
    TurnMaxTimePID(Test, -130, 0.5, 0);//turn to corner
    MoveTimePID(Test, -70, 1.0, 0.2, -130, 0); // move into corner
    RunRoller(0);
    Clamp.set(false);
    wait(400, msec);
    MoveEncoderPID(Test, -70, 6, 0.2, -130, 0); // out of corner
    TurnMaxTimePID(Test, 37, 0.5, 0);//turn to climb
    RunLift(100); // run wall stakes mech
    wait(400, msec);
    RunLift(-100);
    RunLift(0);
    MoveEncoderPID(Test, 70, 45, 0.2, 37, 0); // out of corner
    MoveEncoderPID(Test, 50, 35, 0.2, 37, 0); // out of corner
}
        
