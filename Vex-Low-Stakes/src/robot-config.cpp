#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT1, ratio6_1, false);
motor LM = motor(PORT4, ratio6_1, false);
motor LB = motor(PORT5, ratio6_1, false);;
motor RF = motor(PORT2, ratio6_1, true);
motor RM = motor(PORT3, ratio6_1, true);
motor RB = motor(PORT6, ratio6_1, true);
motor In1 = motor(PORT8, ratio6_1, false);
motor In2 = motor(PORT7, ratio6_1, true);

//Motor Groups
motor_group Roller = motor_group(In1,In2);

//Pistons
digital_out Pistake = digital_out(Brain.ThreeWirePort.C);
digital_out Tilt = digital_out(Brain.ThreeWirePort.B);
digital_out Clamp = digital_out(Brain.ThreeWirePort.A);
digital_out OPMECH = digital_out(Brain.ThreeWirePort.D);

//Gyro and stuff for PID
inertial Gyro = inertial(PORT10);
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