/* 
 * "INDUCTANCE METER using Arduino"
 * Authur : MUJAHID ABDULLAH
 * mujahidabdullah8@gmail.com
 * Subject : do it your self project
 * objectives : give a cheapest way to measure the unknown inductance.
 */

  //import libraries
  #include <Wire.h> 
  #include <inductance.h> 

  //define GPIO pins to be used
    #define pulse_in 3                // pin 3 is used to capture pulse signals from external circuit's output
    #define pulse_out 12              // pin 12 is used to send pulse signal as external circuit's input
  //initiallize some global variabels

  double mH_induct ;
  cap = 1.0E-6 ;                // to find inductance capacitance must be fixed i use 1uF capatance in proj.
                                       // if you use another capacitor , change the value of cap in code
                                       
   void setup()
      {
        Serial.begin(9600);           // Serial communication for serial print of the output values
//        lcd.begin();                  // lcd communication for output display
//        lcd.backlight();              // make the lcd light On
        //initiallize GPIO pins
        pinMode(pulse_in , INPUT);    // output of lc circuit as input to arduino
        pinMode(pulse_out , OUTPUT);  // output of arduino to input of lc circuit
        // serial and lcd printing
        Serial.println("INDUCTANCE METER powered by Arduino");
        delay(1000);
      }
    
    void loop() 
      {
        // generation of pulse for 5 ms through pulse_out pin
        digitalWrite(pulse_out, HIGH);
        delay(5);                                    //time to charge inductor.
        digitalWrite(pulse_out,LOW);

        delayMicroseconds(100);                     //make sure resination is measured
        // capturing of pulse from lc external ckt
        pulse = pulseIn(pulse_in,HIGH,5000);        //checking the High pulse upto 5 msec to measure & returns 0 if timeout
        pulse = 24.5;
        
        inductance ();
      }
/*
 *  Special thanks to Mr. M.Tanveer Khan     mtanveerkhan7@gmail.com
 *                    Mr. M Ahmed Khan 
 *                    http://www.electronoobs.com
 */
