#include <Arduino.h>
#include "config.h"
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

uint8_t DHTPin = DEVICE_SENSOR_PIN;
long lastSendTime1=0;
int  interval1=DEVICE_SENSOR_READ_INTERVAL;
long lastSendTime2=0;
int  interval2=DEVICE_SEND_INTERVAL;

DHT dht(DHTPin, DEVICE_SENSOR_TYPE);
float Temperature;
float Humidity;

void UpdateStatus(void);
void SendCommand(String);
void InitModule(void);
void CheckModule(void);
String fetch_sensor_data(void);
float get_temp(void);
float get_hum(void);
String prepData(float,float);
void send_data(String);
void blink_led(int);

void setup()  
{
  
  Serial.begin(DEVICE_UART1_BAUD_RATE);
  rakUart.begin(DEVICE_UART2_BAUD_RATE);
  pinMode(DEVICE_STATUS_LED_PIN,OUTPUT);
  dht.begin();
  blink_led(10);
  InitModule();
  CheckModule();
}

void loop()  
{ 
  if (millis() - lastSendTime1 > interval1)
 {
   Temperature = get_temp();
   Humidity = get_hum();
   lastSendTime1 = millis();
   //UpdateStatus();
 }
 if (millis() - lastSendTime2 > interval2)
 {
   String in_data = prepData(Temperature, Humidity);
   Serial.println(in_data);
   send_data(in_data);
   lastSendTime2 = millis();
 }
}

void InitModule()
{ 
  SendCommand(LORAWAN_SET_DEV_EUI + String(LORAWAN_DEV_EUI));
  blink_led(1);
  delay(LORAWAN_INIT_MODULE_DELAY);
  SendCommand(LORAWAN_SET_APP_EUI+String(LORAWAN_APP_EUI));
  blink_led(1);
  delay(LORAWAN_INIT_MODULE_DELAY);
  SendCommand(LORAWAN_SET_APP_KEY+String(LORAWAN_APP_KEY));
  blink_led(1);
  delay(LORAWAN_INIT_MODULE_DELAY);
  SendCommand(LORAWAN_SET_BAND_TYPE +String(LORAWAN_BAND_TYPE));
  blink_led(1);
  delay(LORAWAN_INIT_MODULE_DELAY);
  SendCommand(LORAWAN_SET_JOIN_SERVER + String(LORAWAN_JOIN_SERVER));
  blink_led(1);
  delay(LORAWAN_INIT_JOIN_MODULE_DELAY);
}

void CheckModule()
{ 
  SendCommand(LORAWAN_GET_DEV_EUI);
  blink_led(1);
  delay(LORAWAN_CHECK_MODULE_DELAY);
  SendCommand(LORAWAN_GET_APP_EUI);
  blink_led(1);
  delay(LORAWAN_CHECK_MODULE_DELAY);
  SendCommand(LORAWAN_GET_APP_KEY);
  blink_led(1);
  delay(LORAWAN_CHECK_MODULE_DELAY);
  SendCommand(LORAWAN_GET_BAND_TYPE);
  blink_led(1);
  delay(LORAWAN_CHECK_MODULE_DELAY);
  SendCommand(LORAWAN_GET_JOIN_STATUS);
  blink_led(1);
  delay(LORAWAN_CHECK_MODULE_DELAY);
  SendCommand(LORAWAN_GET_JOIN_CONFIG);
  blink_led(1);
  delay(LORAWAN_CHECK_MODULE_DELAY);
}

void UpdateStatus()
{ 
  Serial.print("Recv event from Module-:");
  while(rakUart.available()>0)
  {
    Serial.write(rakUart.read());
  }
  delay(100);
}

void SendCommand(String cmd)
{
 Serial.print("Command Sent to Module-:");
 Serial.println(cmd);
 rakUart.println(cmd);
 delay(100);
 UpdateStatus();
}

void send_data(String in_data)
{
  SendCommand(LORAWAN_SET_DATA_SEND +String(in_data));
  blink_led(2);
}

float get_temp()
{
  float Temperature_temp = dht.readTemperature();
  //Serial.println(Temperature_temp);
  if (String(Temperature_temp) == "nan")
  {
    return Temperature;
  }
  Temperature = Temperature_temp;
  //Serial.println(Temperature);
  return Temperature;
}
float get_hum()
{
  float Humidity_temp = dht.readHumidity();
  //Serial.println(Humidity_temp);
  if (String(Humidity_temp) == "nan")
  {
    return Humidity;
  }
  Humidity = Humidity_temp;
  //Serial.println(Humidity);
  return Humidity;
}

String prepData(float t, float h)
{
  int t1 = t*100;
  int h1 = h*100;
  String out_data  = String(t1)+ String(h1);
  return out_data;
}

void blink_led(int in_data)
{
  for(int i=0; i<in_data+1;i++)
  {
  digitalWrite(DEVICE_STATUS_LED_PIN,HIGH);
  delay(DEVICE_STATUS_LED_BLINK_TIME);
  digitalWrite(DEVICE_STATUS_LED_PIN,LOW);
  delay(DEVICE_STATUS_LED_BLINK_TIME);
}
}