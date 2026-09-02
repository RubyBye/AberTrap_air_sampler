// TIMER SUBROUTINE. tracks total sampler runtime in seconds, minutes and hours
void Timer(){                                       // Starts the Timer subroutine
  milliseconds = millis();                          // Counts the number of milliseconds elapsed since the program started
  newsec = (milliseconds/1000);                     // Converts milliseconds to seconds (as 'newsec' is an integer it can only be a whole number and so will only increment with every 1000 milliseconds)

// Converts milliseconds into seconds
  if (newsec != oldsec){                            // Checks if a full second has passed  since the last check
    seconds = (seconds + 1);                        // If so, adds '1' to the seconds counter
    }

// Converts seconds into minutes
  if (seconds == 60){                               // Checks if there has been 60 seconds since the last check
    minutes = (minutes + 1);                        // If so, adds '1' to the minutes counter
    seconds = 0;                                    // and then re-sets 'seconds counter' to zero
    }

// Converts minutes into hours
  if (minutes == 60){                               // Checks if there has been 60 minutes since the last check
    hours = (hours + 1);                            // If so, adds '1' to the hours counter
    minutes = 0;                                    // and then re-sets 'minutes' counter to zero
    seconds = 0;                                    // and also re-sets 'seconds' seconds to zero
    }

// update old second ctracker
  oldsec = newsec;                                  // stores the current second count for ready the next loop iteration
 }
