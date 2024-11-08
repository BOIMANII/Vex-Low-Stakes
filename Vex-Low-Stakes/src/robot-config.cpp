#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT14, ratio6_1, false);
motor LM = motor(PORT16, ratio6_1, false);
motor LB = motor(PORT11, ratio6_1, false);; 
motor RF = motor(PORT13, ratio6_1, true);
motor RM = motor(PORT18, ratio6_1, true);
motor RB = motor(PORT11, ratio6_1, true);
motor Lift = motor(PORT10, ratio36_1, true);
motor In1 = motor(PORT20, ratio6_1, false);


//Pistons
digital_out Clamp = digital_out(Brain.ThreeWirePort.H);
digital_out Sorter = digital_out(Brain.ThreeWirePort.C);
digital_out IntakeLift = digital_out(Brain.ThreeWirePort.E);

//Gyro and stuff for PID
inertial Gyro = inertial(PORT3);
rotation LiftSensor = rotation(PORT6);
//Naming convention: 
// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 48.0/36;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}