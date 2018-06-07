#include <SPI.h>

#include <SdFatConfig.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <BlockDriver.h>
#include <SysCall.h>

#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shield.h>
#include <SFEMP3Shieldmainpage.h>




// mp3 shield
//#include <SPI.h>
//#include <SdFat.h>
////#include <SdFatUtil.h> 
//#include <SFEMP3Shield.h>
//
//
//#include<>
#include <SoftwareSerial.h>
//SoftwareSerial mySerial(A1, A2); // RX, TX


SdFat sd;
SFEMP3Shield MP3player;

String inString = ""; 



int randomnizer = 1;

long previousMillis = 0;
long interval = 60000;


void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  

   // RS485: set the data rate for the SoftwareSerial port
//   mySerial.begin(115200);

  //start the mp3 shield first to stop buzz sound
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
  MP3player.setVolume(0, 0); // set maximum volume (amplified in negative dB, so high number is high negative dB is low volume, 0 is pass through

  //MP3player.playMP3("track100.mp3"); // play applause
  //MP3player.playTrack(10); // play track 1 for 5 seconds
  //delay(5000);
 
 // MP3player.stopTrack();
 // MP3player.playTrack(2); // play track 2 for 2 seconds
 // delay(2000);
 
 // MP3player.stopTrack();
 // MP3player.playMP3("track003.mp3"); // play track by file name.

}
 
//do something else now
void loop() {
  unsigned long currentMillis = millis();
  
  // Read serial input:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    //if the end char ';' is read:
    if (inChar == ';') {

      MP3player.stopTrack();
      playSound(inString.toInt());
      
      // clear the string for new input:
      inString = "";
    }

    if(inChar == '0'){
      MP3player.stopTrack();
      delay(1000);
    }

    if(inChar == 'r'){
      MP3player.stopTrack();
      previousMillis = currentMillis;
    }
  }
  
  
//  if (currentMillis - previousMillis < interval) {
//    if (!MP3player.isPlaying()){
//      playRandom();
//    }
//  }

} // end loop

void playSound(int n){
  

  //if (!MP3player.isPlaying()){
      switch (n) {
        case 1:
          MP3player.playMP3("track001.mp3"); // play 
          break;
        case 2:
          MP3player.playMP3("track002.mp3"); // play 
          break;
        case 3:
          MP3player.playMP3("track003.mp3"); // play 
          break;
        case 4:
          MP3player.playMP3("track004.mp3"); // play 
          break;
        case 5:
          MP3player.playMP3("track005.mp3"); // play 
          break;
        case 6:
          MP3player.playMP3("track006.mp3"); // play 
          break;
        case 7:
          MP3player.playMP3("track007.mp3"); // play 
          break;
        default: 
          // if nothing else matches, do the default
          // default is optional
        break;
      }
   //}
}

//void playRandom(){
//  int d = random(2000,5000);
//
//  delay(d);
//
//  if (!MP3player.isPlaying()){
//      
//      switch (randomnizer) {
//        case 1:
//          MP3player.playMP3("track001.mp3"); // play 
//          break;
//        case 2:
//          MP3player.playMP3("track002.mp3"); // play 
//          break;
//        case 3:
//          MP3player.playMP3("track003.mp3"); // play 
//          break;
//        case 4:
//          MP3player.playMP3("track004.mp3"); // play 
//          break;
//        case 5:
//          MP3player.playMP3("track005.mp3"); // play 
//          break;
//        case 6:
//          MP3player.playMP3("track006.mp3"); // play 
//          break;
//        case 7:
//          MP3player.playMP3("track007.mp3"); // play 
//          break;
//        default: 
//          // if nothing else matches, do the default
//          // default is optional
//        break;
//      }
//      randomnizer ++;
//      if (randomnizer > 7){
//        int var = random(1,8);
//        randomnizer = var;
//      }
//   }
// }
