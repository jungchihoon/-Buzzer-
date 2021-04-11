#define NOTE_C4 262
#define NOTE_C5 523

int inches = 0;

int cm = 0;
int buzzer = 8;

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT); // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HiGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microsecons
  return pulseIn(pin, HIGH);
}

void setup()
{
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // measure the pint time in cm
    cm = 0.01723 * readUltrasonicDistance(7);
    // convert to inches by dividing by 2.54
    Serial.print(cm);
    Serial.print("cm distance\n");
    if (cm < 150){
        digitalWrite(buzzer, NOTE_C4);
    }
    else if(cm < 50){
        digitalWrite(buzzer, NOTE_C5);
    }
    else {
        digitalWrite(buzzer, 0);
    }
    delay(l000); // Wait for 100 millisecond(s)
}