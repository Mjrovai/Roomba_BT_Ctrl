
#define clamp(value, min, max) (value < min ? min : value > max ? max : value)

#define ON 1
#define OFF 0

//Motor Drive
# define MAX_SPEED 220 // 70% of top speed ==> 256
# define MIN_SPEED 70 

int motorSpeed = 100;

char command = 0; // variable to store command received from IR or BT remote control
char state = 0;

int buttonPin = 12;
int ledPin=13;
int ddPin=5; //device detect

bool debrisLED;
bool spotLED;
bool dockLED;
bool warningLED;
byte color;
byte intensity;

char digit1;
char digit2;
char digit3;
char digit4;

//blocking sensor functions - these will request data and wait until a response is recieved, then return the response

int getSensorData(byte sensorID);
int * getSensorData(byte numOfRequests, byte requestIDs[]);

bool getSensorData(byte * buffer, byte bufferLength);

byte single_byte_packets[22] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 18, 21, 24, 34, 35, 36, 37, 38, 45, 52, 53, 58};
bool is_in_array(byte val);



