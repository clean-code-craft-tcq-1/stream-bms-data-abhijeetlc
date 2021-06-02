#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "Sender_Header.h"

float Temperature[MAX_VAL] = {};
float ChargeRate[MAX_VAL] = {};


Sender_State (*SenderDataRead[])(float Temperature[],float ChargeRate[])={ReadData};
Sender_State(*SenderOutput[])(float Temperature[],float ChargeRate[])={OutToConsole};

Sender_State ReadData(float Temperature[],float ChargeRate[])
{

    float TempVal,ChargeRateVal;

    Sender_State ReadStatus= FAIL;
    FILE * file=fopen( "Sender_Text.txt" , "r");
	
    if (file==NULL) 
    {
      	
		printf("\t\t**DATA READ FAILURE**\t\t\n");
		ReadStatus= FAIL;  
    }
	
    else 
    {
		for(int linecount=1;fscanf(file, "%f\t\t%f\n", &TempVal,&ChargeRateVal)!=EOF ;linecount++)
        	   {
          	
            		Temperature[linecount]=TempVal;
            		ChargeRate[linecount]=ChargeRateVal;
       		    }
	    
        printf("\t\t**DATA READ PASS**\t\t\n");
        ReadStatus= PASS;
      }
    fclose(file);
    return ReadStatus;

}


Sender_State InputValue(Sender_InType InVal)
{

    Sender_State FileReadSuccess = FAIL;
    FileReadSuccess=(*SenderDataRead[InVal])(Temperature,ChargeRate);
    return FileReadSuccess;


}

Sender_State OutputValue(Sender_OutType OutVal)
{

    Sender_State WriteStatus = FAIL;
    WriteStatus=(*SenderOutput[OutVal])(Temperature,ChargeRate);
    return WriteStatus;

}

Sender_State OutToConsole(float Temperature[],float ChargeRate[])
{
    for(int index=0;index<20;index++)
    {
        printf("Temperature value == %f \t ChargeRate value == %f \t\n",Temperature[index],ChargeRate[index]);
    }
    return PASS;
}
