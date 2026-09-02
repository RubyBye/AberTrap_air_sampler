// INITIALISATION
void setup() {                        	                    // The setup routine runs once when you press reset or apply power
  delay(DelayMinutes * 60000);                              // Pause the sketch for the desired time (in minutes) before the air sampler starts
  analogReference(AR_INTERNAL1V0);                          // Analogue to Digital Converter 10 bit (0 - 1024). 1.0v reference for the M0 (instead of 1.1V for the V3 board)
  
// PIN SETUP.
 
  pinMode(MOTOR, OUTPUT);                                   // Sets the motor pin as output
  pinMode (LED, OUTPUT);                                    // Sets the LED pin as output
  pinMode(BackEMF, INPUT);                                  // Sets the backEMF pin as input
  digitalWrite(MOTOR,OFF);                                  // Ensures the motor is initially off
  
// SET SPEED CORRECTION SETUP.  
// set speed correction factor. we are measuring back-EMF not speed directly and there is some non-linearity.
  if (FASTrpm < 1500)
    {
      correction = 3.4;
    }
  else
    {
      correction = 2.0;
    }  
  SpeedRef = FASTrpm / correction;                          // Set the reference speed after applying the correction factor

//SET MOTOR PULSE WIDTH, depending on desired RPM.

  if (FASTrpm < 400)                                        // Increase the pulse width at low speeds
    {
      Pulse_Width = FASTrpm * 1.2;
    }
   else
   {
      Pulse_Width = FASTrpm * 4;                            // At higher speeds, increase the pulse width to 5 times the user-defined rpm
   }  
 }

//MAIN LOOP EXECUTION. The loop routine runs over and over again forever
void loop() {
  // CHECK IF OPERATION IS ONGOING

  	if (End == false)
   		{                                                     // Checks if it is still within the designated run time, if so (End=false), moves on to the rest of the loop.
    		Timer();                                            // Runs the 'Timer' subroutine to track total run time.
		    IntTimer();                                         // Runs the 'IntTimer' subroutine to track time spent in the current FAST/SLOW interval

        // CYCLE TIME COUNTING
    		if(seconds != seconds_last)
      			cycletimesecs++;                                // Increase cycle counter every time a second passes
    		seconds_last = seconds;                             // Update last recorded second
    		if(cycletimesecs == 600)                            // Reset cycle counter after 600 seconds (10 mins)
             		cycletimesecs = 0;
        	
          // MOTOR CONTROL
          if (Run == true)                                  // If the motor is running...
          		{	
    		  	if(cycletimesecs < CycleSeconds)                //...and cycle time is still within the specified CycleSeconds
    			  	{
         		  	Speed();                                    // Calls the 'Speed' subroutine to set the desired pwm (power to the motor) to maintain RPM
    			  	} 
    		  	else
    			  	{
         		  	digitalWrite (MOTOR,0);                     // Otherwise, if cycle time exceeded, turns off motor
    			  	} 
          		}
 		  }
  // CHECK IF THE TOTAL RUNTIME LIMIT HAS BEEN REACHED 
 	if (minutes >= RunMinutes)
   		{                                                     // Checks to see if we have reached the user-defined runtime.
     		if (hours >= RunHours)
     			{
      			End = true;                                     // If so, changes the value of 'End' to True to stop the main loop completing next time. End the loop after reaching desired runtime
      			digitalWrite (MOTOR,0);                         // Turns off the motor
     			}
  		}

//FAST/SLOW INTERVAL SWITCHING
	if (SlowInterval == false)                                // If currently in a 'FAST interval'
		{
		if (Intminutes >= FASTmin)				                      // checks if user-defined 'FAST interval' duration has been reached 
			{
			SlowInterval = true;                                  // If yes, switch to the 'SLOW interval'
			Intseconds = 0;
			Intminutes = 0;
      digitalWrite (MOTOR,0);                               // Slow or pause the motor
			PrevSpeed = SpeedRef;                                 // Stores the previous speed reference
			SpeedRef = SLOWrpm;                                   // Set motor speed to the user-defined 'SLOW interval' speed (in rpm) 
			}
		}
	else                                                      // If currently in a 'SLOW interval'
		{
		if (Intminutes >= SLOWmin)			                       	// Checks if user-defined 'SLOW interval' duration has been reached  
			{
			SlowInterval = false;                                 // If so, switch back to 'FAST interval' 
			Run = true;
			SpeedRef = PrevSpeed;                                 // Restore the previous 'FAST interval' speed ; re-starts spinning at full speed
			Intseconds = 0;                                       // Resets the interval counter 
			Intminutes = 0;
			}
		}
   	}
