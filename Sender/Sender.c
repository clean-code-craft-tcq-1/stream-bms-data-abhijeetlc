/* **************************************************************************************************
* File Name   : Sender.c
* Author      : Abhijeet Chitagubbi
* Objective   :Stream Temperature and Chargerate value to console after reading from a file.
* * ************************************************************************************************** */


/* **************************************** Standard Header Files **************************************************** */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* **************************************** Local Header Files **************************************************** */
#include "Sender_Header.h"

/* **************************************** Declarations **************************************************** */
float Temperature[MAX_VAL] = {};
float ChargeRate[MAX_VAL] = {};
int linecount = 0;


/* **************************************** Function Pointer Array **************************************************** */
Sender_State (*SenderDataRead[])(float Temperature[],float ChargeRate[])={ReadData};
Sender_State(*SenderOutput[])(float Temperature[],float ChargeRate[])={OutToConsole};


/* **************************************** Read Values from File **************************************************** */
Sender_State ReadData(float Temperature[],float ChargeRate[])
{

    float TempVal,ChargeRateVal = 0;
    int Index = 0;
    int Line_Identifier = 1;

    Sender_State ReadStatus= FAIL;
    FILE * file=fopen( "./Sender/Sender_Data.txt","r");
	
    if (file==NULL) 
    { 	
	printf("\t\t**DATA READ FAILURE**\t\t\n");
	ReadStatus= FAIL;  
    }
    else 
    {
        while(Line_Identifier != EOF)
         {
        	Line_Identifier = fscanf(file, "%f\t\t%f\n", &TempVal,&ChargeRateVal);
            	Temperature[Index]=TempVal;
            	ChargeRate[Index]=ChargeRateVal;
		Index++;
		linecount=Index;
          }
	    
        printf("\t\t**DATA READ PASS**\t\t\n");
        ReadStatus= PASS;
      }
    fclose(file);
    return ReadStatus;
}


/* **************************************** Input BMS Values  **************************************************** */
Sender_State InputValue(Sender_InType InVal)
{
    Sender_State FileReadSuccess = FAIL;
    FileReadSuccess=(*SenderDataRead[InVal])(Temperature,ChargeRate);
    return FileReadSuccess;
}


/* **************************************** Output BMS Values **************************************************** */
Sender_State OutputValue(Sender_OutType OutVal)
{

    Sender_State WriteStatus = FAIL;
    WriteStatus=(*SenderOutput[OutVal])(Temperature,ChargeRate);
    return WriteStatus;

}

/* **************************************** Output to Console **************************************************** */

Sender_State OutToConsole(float Temperature[],float ChargeRate[])
{
    for(int Index=0;Index<linecount;Index++)
    {
        printf("Temperature value == %f \t ChargeRate value == %f \t\n",Temperature[Index],ChargeRate[Index]);
    }
    return PASS;
}
