#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT1, ratio6_1, false);
motor LM = motor(PORT9, ratio6_1, false);
motor LB = motor(PORT17, ratio6_1, false);; 
motor RF = motor(PORT2, ratio6_1, true);
motor RM = motor(PORT19, ratio6_1, true);
motor RB = motor(PORT18, ratio6_1, true);
motor In1 = motor(PORT6, ratio6_1, false);
motor Lift = motor(PORT4, ratio6_1, true);

//Pistons
digital_out Pistake = digital_out(Brain.ThreeWirePort.E);
digital_out Clamp = digital_out(Brain.ThreeWirePort.E);
digital_out Sorter = digital_out(Brain.ThreeWirePort.C);
digital_out OPMECH = digital_out(Brain.ThreeWirePort.H);

//Gyro and stuff for PID
inertial Gyro = inertial(PORT1);
rotation LiftSensor = rotation(PORT3);
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