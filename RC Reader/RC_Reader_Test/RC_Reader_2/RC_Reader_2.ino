/*
 RC PulseIn Serial Read out
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */
 
int ch1; // Here's where we'll keep our channel values
int Ch1_Pos;
int ch3;

void setup() {

  pinMode(3, INPUT); // Set our input pins as such
//  pinMode(6, INPUT);
//  pinMode(7, INPUT);

  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() {

  ch1 = pulseIn(3, HIGH, 25000); // Read the pulse width of 
 // ch2 = pulseIn(6, HIGH, 25000); // each channel
 // ch3 = pulseIn(7, HIGH, 25000);

ch1=ch1-1100;
ch1=ch1/2;

Ch1_Pos=1;
if (ch1 < 100)
  Ch1_Pos=2;
if (ch1 >300) 
  Ch1_Pos=0;

  Serial.print("Channel 1:"); // Print the value of 
  Serial.println(Ch1_Pos);        // each channel

 // Serial.print("Channel 2:");
 // Serial.println(ch2);

 // Serial.print("Channel 3:");
 // Serial.println(ch3);

  delay(100); // I put this here just to make the terminal 
              // window happier
}
