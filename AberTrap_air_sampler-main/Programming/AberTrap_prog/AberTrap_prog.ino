// USER INPUT. modify values of the parameters below to set the AberTrap run program
/*
Speed range 200 - 1600 RPM


*/
int RunMinutes = 0;                      // USER INPUT. Sets the desired total runtime in minutes (0 - 59). This determines how long the program will run (in minutes). set to 0 if timing in hours
int RunHours = 730;                      // USER INPUT. Sets the desired total runtime in hours (no max value). This determines how long the program will run (in hours)
int DelayMinutes = 0;                    // USER INPUT. Sets the desired time delay (in minutes) before rotation starts.
int CycleSeconds = 600;                  // USER INPUT. Sets the number of seconds in a 600-second cycle that the motor will be running. For example, if CycleSeconds = 300, the motor would run for 300s and stay off for the remaining 300s of the cycle

//set duration and rpm for the "FAST/SLOW" intervals. The sampler will keep cycling between these intervals until the total Run time is reached
int FASTrpm = 1600;                 	   // USER INPUT. Sets the desired motor speed (in revolutions per minute; rpm) for FAST speed intervals 
int FASTmin = 1;                         // USER INPUT. Sets the duration (in minutes) of FAST speed intervals. 
int SLOWrpm = 10;                        // USER INPUT. Sets the motor speed for SLOW speed intervals. Meant to be in RPM but not, "10" seems to be approx 400rpm needs work to slow it down. Set to "0" for a complete PAUSE.
int SLOWmin = 1;                         // USER INPUT. Sets the duration (in minutes) of SLOW speed intervals. Set to "0" for continuous FAST.
