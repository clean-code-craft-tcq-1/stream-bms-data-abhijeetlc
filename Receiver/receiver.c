#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "receive.h"

bool  readDataFromConsole(char *valuefromsender) {
  int i=0; 
  int j= 0;
  if (valuefromsender != NULL)
  {
    scanf("%s",valuefromsender);
    i = strlen(valuefromsender);
    j = strtod(valuefromsender);
    valuefromsender[j] = '\n';
    valuefromsender[j + 1] = '\0';
    printf("valuefromsender = %f\n", valuefromsender); //for debug purpose
       return true; 
  }
  return false;
}

void getvalueFromsender(char *valuefromsender_get, float *tempValue)
{
  int i = 0, j = 0; 
  char par[lengthofParm]; 
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
