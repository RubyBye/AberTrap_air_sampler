// CONSTANTS
const int MOTOR = 0;                     // Motor drive pin. HIGH = on
const int LED = 1;                       // Red LED shows motor activity
const int BackEMF = 1;                   // Analog input pin used to measure the motor's backEMF, for determining current motorspeed
boolean  ON = 1, OFF = 0;                // Boolean flags to represent true (ON) and false (OFF)

// VARIABLES
float SpeedRef = 0;                      // Speed reference value for the motor. used to set or compare the desired speed
float correction = 0;                    // Correction value, to adjust speed after feedback
unsigned int Pulse_Width = 0;            // Length of Motor Pulse in microSeconds.
int CurrentSpeed = 0;                    // Current motor Speed (as read from the BackEMF)
int ReadDelay = 300;                     // Delay between motor pulse and reading of the BackEMF (in microseconds)
int PrevSpeed = 0;

// TIME VARIABLES
long previousMillis = 0;               	 // Milli-second counter used for timings
int oldsec = 0;                          // Variable used for counting seconds from milliseconds
int newsec;                              // Variable used for counting seconds from milliseconds
int Intoldsec = 0;                       // Variable used for counting seconds from milliseconds
int Intnewsec;                           // Variable used for counting seconds from milliseconds

unsigned long milliseconds;              // Counter for total elapsed time in milliseconds
unsigned long seconds;                   // Counter for total elapsed time in seconds
unsigned long minutes;                   // Counter for total elapsed time in minutes 
unsigned long hours;                     // Counter for total elapsed time in hours
unsigned long Intseconds;                // Interval seconds counter, used for a specific timed interval
unsigned long Intminutes;                // Interval minutes counter, used for a specific timed interval

int cycletimesecs = 0;                   // Stores the length of the cycle time (in seconds)  
int seconds_last = 0;                    // Stores the last recorded second to compare against for cycle timing

// CONTROL FLAGS
int End = false;                         // A logic variable used by the timer. Changes to 'True' once the runtime is finished.
int SlowInterval = false;                // A logic variable that indicates whether the motor is running slowly
int Run = true;                          // A logic variable that indicates whether the motor is running
