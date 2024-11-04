using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LF;
extern motor LM;
extern motor RF;
extern motor RM;
extern motor LB;
extern motor RB;
extern motor In1;
extern motor Lift;
extern digital_out Clamp;
extern digital_out Sorter;
extern digital_out RightBackWing;
extern digital_out Pistake;
extern motor PU;
extern inertial Gyro;
extern digital_out LeftBackWing;
extern digital_out IntakeLift;
extern rotation LiftSensor;

extern const double wheelDiam;
extern const double wheelToMotorRatio;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );