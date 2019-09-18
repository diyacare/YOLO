/*************** motor defintions *******************/

//motors 2 gpios settings
#define MTR1_DRI 		3
#define MTR1_STEP		4

#define MTR2_DRI		5
#define MTR2_STEP		6

#define STEPS_FOR_ROUND			200
#define ON_CHANGE_FOR_ROUND		8

// Our motors params handling
typedef struct MOTOR_PARAMS
{
	unsigned char numOfStep;
	unsigned char driGpio;
	unsigned char stepGpio;

}MOTOR_PARMS;

MOTOR_PARMS motorParam[] =
{
 	{3, MTR1_DRI, MTR1_STEP},/*MTR1*/
 	{2, MTR2_DRI, MTR2_STEP} /*MTR2*/
};



/************* motors prototypes ********************/

void motorSteps(void *param);
void motorsInit();
void homing_state(void *param);
