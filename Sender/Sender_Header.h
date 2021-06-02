/*
 **********************************************************************************************************************
 * Includes and Definition Section
 **********************************************************************************************************************
*/

#define MAX_VAL 50

/*
 **********************************************************************************************************************
 * TypeDef handling Section
 **********************************************************************************************************************
*/


typedef enum
{   FAIL,
	PASS
}Sender_State;

typedef enum{
	PrintToConsole
}Sender_OutType;

typedef enum{
	FileInput
}Sender_InType;

/*
 **********************************************************************************************************************
 * TypeDef handling Section
 **********************************************************************************************************************
*/

Sender_State ReadData(float Temperature[],float ChargeRate[]);
Sender_State OutToConsole(float Temperature[],float ChargeRate[]);
Sender_State InputValue(Sender_InType InVal);
Sender_State OutputValue(Sender_OutType OutVal);


/*
 **********************************************************************************************************************
 *Extern Declarations
 **********************************************************************************************************************
*/

extern float Temperature[MAX_VAL];
extern float ChargeRate[MAX_VAL];
