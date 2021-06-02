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
	printtoconsole
}Sender_OutType;

typedef enum{
	FileInputType
}Sender_InType;

/*
 **********************************************************************************************************************
 * TypeDef handling Section
 **********************************************************************************************************************
*/

Sender_State ReadData(float Temperature[],float ChargeRate[]);
Sender_State outputtoconsole(float Temperature[],float ChargeRate[]);
Sender_State inputvalue(Sender_InType inputvalue);
Sender_State outputvalue(Sender_OutType outputvalue);


/*
 **********************************************************************************************************************
 *Extern Declarations
 **********************************************************************************************************************
*/

extern float Temperature[MAX_VAL];
extern float ChargeRate[MAX_VAL];
