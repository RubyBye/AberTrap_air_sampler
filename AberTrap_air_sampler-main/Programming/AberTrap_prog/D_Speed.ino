 // SPEED CONTROL SUBROUTINE. regulates motor speed by adjusting pulse width
 void Speed()
 {
  // Read the motor's backEMF to measure current speed
 delayMicroseconds (ReadDelay);                                       // Brief wait before sampling backEMF
  CurrentSpeed = analogRead(BackEMF);                                 // Read current speed from the backEMF sensor (analogue input)
  delayMicroseconds(120);                                             // Wait for A/D converter to finish the converson before proceeding

// Calculate speed error
int speedError = SpeedRef - CurrentSpeed;                             // Calculate speed error; difference between the desired speed (SpeedRef) and current speed (CurrentSpeed)

// Proportional control (kP) to adjust the Pulse_Width based on the speed error
float kP = 0.9;                                                       // Define a proportional constant (kP) for adjusting Pulse_Width
Pulse_Width += speedError * kP;                                       // Adjust the Pulse_Width based on the speed error (using proportional control)

// Ensure that Pulse_Width stays within reasonable limits
if (Pulse_Width < 0) Pulse_Width = 0;                                 // Prevent Pulse_Width from going negative
if (Pulse_Width > FASTrpm * 5) Pulse_Width = FASTrpm * 5;       // Cap Pulse_Width at a maximum value based on RPM,

// Motor control
if (CurrentSpeed < SpeedRef)                                          // If CurrentSpeed is less than desired speed (SpeedRef)
  {
   digitalWrite(MOTOR,ON);                                            // Turn the motor ON (apply power)
   digitalWrite(LED,1);                                               // Turn on LED to show motor activity        
   delayMicroseconds(Pulse_Width);                                    // Apply power for the duration of the Pulse_Width
   digitalWrite(MOTOR,OFF);                                           // Turn the motor OFF (cut power after pulse duration) 
   digitalWrite(LED,0);                                               // Turn off LED
  }

 }
