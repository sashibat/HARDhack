
// defines pins numbers
const int trigPin = 10;
const int echoPin = 9;
const int streetlight2 = 3;

const int trigPin0 = 5;
const int echoPin0 = 6;
const int streetlight = 11 ;

const int dangerlight = 13;
const int button = 4;
int brightness = 255;    // how bright the LED is
int fadeAmount = 3;

const int buzzer = 8;
bool happenedOnce = false;
// defines variables

long duration;
int distance;

int buttonio=0;

long duration0;
int distance0;
void setup() {



Serial.begin(9600);
pinMode(buzzer,OUTPUT);  
pinMode(button,INPUT_PULLUP);
pinMode(dangerlight,OUTPUT);

pinMode(streetlight2,OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(streetlight,OUTPUT);
pinMode(trigPin0, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin0, INPUT); // Sets the echoPin as an Input

}

void loop() {

//ULTRASONIC SENSOR
// Clears the trigPin
digitalWrite(trigPin,LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration*0.034/2;


Serial.print("Distance: ");
Serial.println(distance);

//ULTRASONIC SENSOR 
digitalWrite(trigPin0, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin0, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin0, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration0 = pulseIn(echoPin0, HIGH);
// Calculating the distance
distance0= duration0*0.034/2;


// Prints the distance on the Serial Monitor
Serial.print("     Distance0: ");
Serial.println(distance0);


delay(300);

//EMERGENCY BUTTON ALARM (Light and Buzzer)
  delay(100);
  buttonio = digitalRead(button);
  
  if (buttonio == LOW) {

    //Loop 1 times
    for (int i = 0; i < 3; i++){
    delay(1000);
    digitalWrite(dangerlight, HIGH);
    tone(buzzer,1000);
    delay(100);
    noTone(buzzer);
    digitalWrite(dangerlight, LOW);
    Serial.print(i);
    Serial.println(" nth Beep");
    }
  }

//ULTRASONIC SENSOR 1

  while (distance > 30 and distance < 70 and brightness > 10) {   // FOR PEDESTRIANS

  analogWrite(streetlight2, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;

     if (brightness < 15) {
        analogWrite(streetlight2, 0);

    
     }
 
  delay(100);
    
  } 

   brightness = 255;
//--------------------------------------------------------------------------------------------
   
   while (distance > 70 and distance < 125 and brightness > 10) {  // FOR BIKES
   
      analogWrite(streetlight2, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;
     if (brightness < 15) {
        
        analogWrite(streetlight2, 0);
     }
 
  delay(60);
    
  }

   brightness = 255;

   //--------------------------------------------------------------------------------------------
   while (distance > 125 and distance < 1500 and brightness > 10 ) {  // FOR CARS
      analogWrite(streetlight2, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;

     if (brightness < 15) {
        analogWrite(streetlight2,0);
     }
 
  delay(30);
    
  }
  brightness = 255;
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

  while (distance0 > 30 and distance0 < 70 and brightness > 10) {   // FOR PEDESTRIANS

  analogWrite(streetlight, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;

     if (brightness < 15) {
        analogWrite(streetlight, 0);
     }
 
  delay(100);
 
  } 

   brightness = 255;
//--------------------------------------------------------------------------------------------
   
   while (distance0 > 70 and distance0 < 125 and brightness > 10) {  // FOR BIKES
   
      analogWrite(streetlight, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;
     if (brightness < 0) {
        analogWrite(streetlight, 0);
     }
 
  delay(60);
  
  }

   brightness = 255;

   //--------------------------------------------------------------------------------------------
   while (distance0 > 125 and distance0 < 1500 and brightness > 10 ) {  // FOR CARS
    
      analogWrite(streetlight, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;

     if (brightness < 15) {
        analogWrite(streetlight, 0);
     
 
  delay(30);
    
  }
  brightness = 255;

}


}
