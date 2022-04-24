//Coded By: Angelo Casimiro (4/27/14)
//Voice Activated Arduino (Bluetooth + Android)
//Feel free to modify it but remember to give credit

String voice;
int 
led1 = 2, //Connect LED 1 To Pin #2 
led2 = 3, //Connect LED 2 To Pin #3 
led3 = 4, //Connect LED 3 To Pin #4 
led4 = 5, //Connect LED 4 To Pin #5 
//--------------------------Call A Function-------------------------------//  
void allon(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     digitalWrite(led3, HIGH); 
     digitalWrite(led4, HIGH); 
}
void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     digitalWrite(led3, LOW); 
     digitalWrite(led4, LOW); 
}
//-----------------------------------------------------------------------//  
void setup() {
  Serial.begin(38400);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
}
//-----------------------------------------------------------------------//  
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  //----------Control Multiple Pins/ LEDs----------//  
       if(voice == "*turn on all") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*turn off all"){alloff();} //Turn On  All Pins (Call Function)
  
  //----------Turn On One-By-One----------// 
  else if(voice == "*turn on TV") {digitalWrite(led1, HIGH);} 
  else if(voice == "*turn on AC") {digitalWrite(led2, HIGH);}
  else if(voice == "*turn on fan") {digitalWrite(led3, HIGH);}
  else if(voice == "*turn on light") {digitalWrite(led4, HIGH);}
  //----------Turn Off One-By-One----------// 
  else if(voice == "*turn off TV") {digitalWrite(led1, LOW);} 
  else if(voice == "*turn off AC") {digitalWrite(led2, LOW);}
  else if(voice == "*turn off fan") {digitalWrite(led3, LOW);}
  else if(voice == "*turn off light") {digitalWrite(led4, LOW);}
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating
