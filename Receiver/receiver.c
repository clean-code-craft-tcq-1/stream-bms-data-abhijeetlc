#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "receive.h"

bool  readDataFromConsole(char *valuefromsender) {
  int i=0; //Length of string
  if (valuefromsender != NULL)
  {
    scanf("%s",valuefromsender);
    i = strlen(valuefromsender);
    valuefromsender[i] = '\n';
    valuefromsender[i + 1] = '\0';
       return true; 
  }
  return false;
}

void getvalueFromsender(char *valuefromsender_get, float *tempValue)
{
  
  int i = 0, j = 0; 
  char par[lengthofParm]; 
  int parNum = 0;  //count of parameters

     par[j] = valuefromsender_get[i];
    par[j] = '\0'; //Adding end of string
    
    /* Convert string to float number to evaluate further */
    tempValue[parNum] = atof(par);
    
    printf("Paramter value = %f\n", tempValue[parNum]); //for debug purpose

    /* Iterate to next parameter in the buffer*/ 
    parNum++; 

    /*Escape Comma separated character*/
    i++;
    
  
  }
}

void Receiver_Read()
{
  char valuefromsender[lengthofParm];
  float paramMin[lengthofParm] = {TemperatureMin,SocMAX };
  float paramMax[lengthofParm] = {TemperatureMax,SOcMin };
  int paramSetCounter = 0;
  /* Reading the input stream */
  for (paramSetCounter; paramSetCounter < NoOfParamterSet; paramSetCounter++) {
    
    /* Read one input set if the read is successful process parameters further*/
    bool TestActive = readDataFromConsole(valuefromsender);
    if (TestActive)
    {
      /* Initialize individual parameter buffer to zero */
      float tempValue[lengthofParm] ;
      /*Converts data stream to individual parameter data*/
      getvalueFromsender(valuefromsender, tempValue);
      /* Running loop for each parameter evaluation */
      for (int parameterCount = 0; parameterCount< lengthofParm; parameterCount++) {
        
        calculateMinValue(&tempValue[parameterCount], &paramMin[parameterCount]);
        calculateMaxValue(&tempValue[parameterCount], &paramMax[parameterCount]);
    }
      printf(" Current Min value of Temp : %f, ChargeRate : %f \n ", paramMin[Temperature], paramMin[SOC]);
      printf(" Current Max value of Temp : %f, ChargeRate : %f \n ", paramMin[Temperature], paramMin[SOC]);
    }

  }
  
}

void calculateMinValue(float *paramValue, float *paramValueMin) {
   
     /* Update the min value if current value is less */
    if (*paramValueMin > *paramValue)
    {
      *paramValueMin = *paramValue;

    }
}

void calculateMaxValue(float *paramValue, float *paramValueMax) {
  /* Update the maximum value if current value is more */
  if (*paramValueMax < *paramValue)
  {
    *paramValueMax = *paramValue;
  }
}
int main()
{
    Receiver_Read();
    return 0;
}
