#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "receive.h"



bool  readDataFromConsole(char *valuefromsender) {
  int i=0; 

  if (valuefromsender != NULL)
  {
    
    scanf("%s",valuefromsender);
    i = strlen(valuefromsender);
  
    valuefromsender[i] = '\n';
    valuefromsender[i + 1] = '\0';
   printf("valuefromsender = %f\n", valuefromsender); 
    return true; 
     }
 
  return false;
}

void getvalueFromsender(char *valuefromsender_get, float *tempValue)
{
  int i = 0, j = 0; 
  char par[60]; 
  int parNum = 0;  //count of parameters
    for (j = 0;valuefromsender_get[i] != NULL;j++, i++)
    {
    par[j] = valuefromsender_get[i];
    par[j] = '\0'; 
    }
    /* Convert string to float number to evaluate further */
    tempValue[parNum] = atof(par);
    printf("Paramter value = %f\n", tempValue[parNum]); 

 }

void Receiver_Read()
{
  //char valuefromsender_get[lengthofParm];

  float valuefromsender[lengthofParm];
  float paramMin[lengthofParm] = {TemperatureMin,SocMAX };
  float paramMax[lengthofParm] = {TemperatureMax,SOcMin };
  
  /* Reading the input stream */
  
    
    /* Read one input set if the read is successful process parameters further*/
    bool TestActive = readDataFromConsole(valuefromsender);
    if (TestActive)
    {
     
      float tempValue[lengthofParm] ;
      getvalueFromsender(valuefromsender, tempValue);
     
      for (int parameterCount = 0; parameterCount< lengthofParm; parameterCount++) {
        calculateMinValue(&tempValue[parameterCount], &paramMin[parameterCount]);
        calculateMaxValue(&tempValue[parameterCount], &paramMax[parameterCount]);
    }
      printf(" Minumum Temperature : %f, Minimum SOC : %f \n ", paramMin[Temperature], paramMin[SOC]);
      printf(" Maximum Temperature : %f, Maximum SOC : %f \n ", paramMax[Temperature], paramMax[SOC]);
    

  }
  
}

void calculateMinValue(float *paramValue, float *paramValueMin) {
   
   
    if (*paramValueMin > *paramValue)
    {
      *paramValueMin = *paramValue;

    }
}

void calculateMaxValue(float *paramValue, float *paramValueMax) {
 
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
