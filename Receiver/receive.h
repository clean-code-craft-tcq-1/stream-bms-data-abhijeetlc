
#define NoOfParamterSet 20 
#define lengthofParm 15 // As reference from the sender

#define TemperatureMax  45.f
#define TemperatureMin  0.f

#define SocMAX  0.8f
#define SOcMin  0.f

typedef enum MinMaxRet
{
  Temperature,
  SOC
}MinMaxRet;


void calculateMaxValue(float *paramValue, float *paramValueMax);
void calculateMinValue(float *paramValue, float *paramValueMin);

void Receiver_Read();
bool readDataFromConsole(char *valuefromsender);
void getvalueFromsender(char *valuefromsender_get, float *tempValue);


