typedef struct
{
unsigned char header1;
unsigned char header2;
unsigned char header3;
int rspd;
int lspd;
}Cmd_t;

Cmd_t rxCmd;

typedef struct
{
unsigned char header1;
unsigned char header2;
unsigned char hb;
int time;
}Hbt_t;

Hbt_t rxHbt;

typedef struct
{
unsigned char header1;
unsigned char header2;
unsigned char header3;
unsigned char cmd;
}BladeCmd_t;

BladeCmd_t rxBladeCmd;

unsigned char rxBuffer[180];
const int maxBufSize = 180;
int bufSize;
int bufPos;
DualMC33926MotorShield md;

const int BLADEMOWER1PIN =  2;
const int BLADEMOWER2PIN =  3;

short HBcounter;

const float CURRENTLIMIT = 3.0;
