// INTERVAL TIMER SUBROUTINE. tracks interval timing to decide when to switch between the FAST and SLOW intervals 
void IntTimer(){                                       // Starts the IntervalTimer subroutine
  milliseconds = millis();                             // Counts the number of millisecondselapsed since the program started
  Intnewsec = (milliseconds/1000);                     // Converts milliseconds to seconds (as 'newsec' is an integer it can only be a whole number and so will only increment with every 1000 milliseconds)

  if (Intnewsec != Intoldsec){                         // Checks if a full second has passed  since the last check 
    Intseconds = (Intseconds + 1);                     // If so, adds '1' to the seconds counter
    }
  if (Intseconds == 60){                               // Checks if there has been 60 seconds since the last check
    Intminutes = (Intminutes + 1);                     // If so, adds '1' to the minutes counter
    Intseconds = 0;                                    // and then re-sets seconds counter to zero
    }
  Intoldsec = Intnewsec;                               // stores the current second count for ready the next loop iteration
 }
