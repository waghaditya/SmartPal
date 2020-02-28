#define UpperThreshold 542//545
#define LowerThreshold 536//530

int BPM1=0;
int BPM2=0;
int count=0;

int LastTime=0;
int ThisTime;
bool BPMTiming=false;
bool BeatComplete=false;
int BPM=0;

void read_BPM();

#define TRIG_PIN 12

boolean bpm_measure = false;
int bpm_val = 0;
