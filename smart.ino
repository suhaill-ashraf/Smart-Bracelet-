const int TEMPERATURE_THRESHOLD = 38; // Temperature at which the buzzer will sound
const int BUZZER_PIN = 9; // Pin that the buzzer is connected to
int ThermistorPin = 0;
const int motorPin = 3; // Vibrator Pin
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
// Set the buzzer pin to be an output pin
  pinMode(BUZZER_PIN, OUTPUT);
// Set the Vibrator pin to be an output pin
  pinMode(motorPin, OUTPUT);

}

void loop() {
  
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 

  Serial.print(Tc);
  Serial.println(" C");   
   
  if (Tc > TEMPERATURE_THRESHOLD) {
    
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
    digitalWrite(motorPin, HIGH);
    
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(motorPin, LOW);
  }

  delay(500);
}