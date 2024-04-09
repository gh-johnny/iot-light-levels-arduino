int ldr_value;
int ldr_good = 790;
int ldr_critic = 870;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(8, OUTPUT); 
}

void loop() {
  ldr_value = analogRead(0);
   	
    if(ldr_value<=ldr_good)
    {
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    }
    else if((ldr_value > ldr_good) && (ldr_value < ldr_critic))
    {
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      
      // 3 seconds alert beep
      tone(8, 440);
      delay(3000);
      noTone(8);
      delay(2000);
    }
    else
    { 
       digitalWrite(12, HIGH);
       digitalWrite(11, LOW);
       digitalWrite(10, LOW);
     }
}
