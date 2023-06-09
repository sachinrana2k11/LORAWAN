#define LORAWAN_DEV_EUI "AC1F09FFFE0B8944"
//test
#define LORAWAN_APP_EUI "9B85780465B7C51C"
#define LORAWAN_APP_KEY "2DAC6E63280D0818D75CAD5048D607BD"
#define LORAWAN_BAND_TYPE "3"
#define LORAWAN_SEND_PORT "2"
#define LORAWAN_LINK_CHECK_MODE "1"
#define LORAWAN_JOIN_SERVER "1:1:10:8"
#define LORAWAN_INIT_MODULE_DELAY 90000
#define LORAWAN_INIT_JOIN_MODULE_DELAY 10000
#define LORAWAN_CHECK_MODULE_DELAY 2000

//------LORAWAN-SETUP-COMMAND----//
#define LORAWAN_SET_DEV_EUI "AT+DEVEUI="
#define LORAWAN_SET_APP_EUI "AT+APPEUI="
#define LORAWAN_SET_APP_KEY "AT+APPKEY="
#define LORAWAN_SET_BAND_TYPE "AT+BAND="
#define LORAWAN_SET_JOIN_SERVER "AT+JOIN="
#define LORAWAN_SET_APP_KEY "AT+APPKEY="
#define LORAWAN_SET_DATA_SEND "AT+SEND=2:"
#define LORAWAN_SET_LINK_CHECK "AT+LINKCHECK="
//------LORAWAN-GET-COMMAND----//
#define LORAWAN_GET_AT "AT"
#define LORAWAN_GET_AT_VER "AT+VER=?"
#define LORAWAN_GET_DEV_EUI "AT+DEVEUI=?"
#define LORAWAN_GET_APP_EUI "AT+APPEUI=?"
#define LORAWAN_GET_APP_KEY "AT+APPKEY=?"
#define LORAWAN_GET_BAND_TYPE "AT+BAND=?"
#define LORAWAN_GET_JOIN_STATUS "AT+NJS=?"
#define LORAWAN_GET_JOIN_CONFIG "AT+JOIN=?"
#define LORAWAN_GET_DATA_RCV "AT+RECV=?"
#define LORAWAN_GET_LINK_CHECK "AT+LINKCHECK=?"
//------DEVICE-CONFIG----//
#define DEVICE_SEND_INTERVAL 20000
#define DEVICE_SENSOR_TYPE DHT11
#define DEVICE_SENSOR_PIN 4
#define DEVICE_SENSOR_READ_INTERVAL 5000
#define DEVICE_STATUS_LED_PIN 2
#define DEVICE_STATUS_LED_BLINK_TIME 100
//------DEVICE-SERIAL-UART-CONFIG----//
#define DEVICE_UART1_BAUD_RATE 115200
#define DEVICE_UART2_BAUD_RATE 115200
#define rakUart Serial2
