byte i=0;
int lmf=8;
int rmf=13;
int lmr=7;
int rmr=12;
int ir1=2;
int ir2=3;
int s1=5;
int s2=6;
int s3=9;
int s4=11;
int duration;
int dist;
#define echo 10
#define trigger 4 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(lmr,OUTPUT);
pinMode(rmr,OUTPUT);
pinMode(rmf,OUTPUT);
pinMode(lmf,OUTPUT);
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(s1,OUTPUT);
pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(s4,OUTPUT);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigger,LOW);
  delay(10);
  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger,LOW);
  duration = pulseIn(echo,HIGH);
  dist = (duration/2) / 29.1;
  /*Serial.print(dist);
    Serial.println(" cm");*/ //use only when serial.read is not being used...dist is the data from the hcsr05
while(Serial.available()==0) {}
  i=Serial.read();
  if(i==119)
  {
    Serial.println("full forward");
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmr,LOW);
    digitalWrite(rmr,LOW);
  }
  else if(i==97)
  {
    Serial.println("Left Rotate");
    digitalWrite(lmf,LOW);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmr,HIGH);
    digitalWrite(rmr,LOW);
  }
  else if(i==100)
  {
    Serial.println("Right Rotate");
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,LOW);
    digitalWrite(lmr,LOW);
    digitalWrite(rmr,HIGH);
  }
  else if(i==115)
  {
    Serial.println("Full Backward");
    digitalWrite(lmf,LOW);
    digitalWrite(rmf,LOW);
    digitalWrite(lmr,HIGH);
    digitalWrite(rmr,HIGH);
  }
  else if(i==113)
  {
    Serial.println("Left Turn");
    digitalWrite(lmf,LOW);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmr,LOW);
    digitalWrite(rmr,LOW);
  }
  else if(i==101)
  {
    Serial.println("Right Turn");
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,LOW);
    digitalWrite(lmr,LOW);
    digitalWrite(rmr,LOW);
  }
   else if(i==32)
  {
    Serial.println("All Stop");
    digitalWrite(lmf,LOW);
    digitalWrite(rmf,LOW);
    digitalWrite(lmr,LOW);
    digitalWrite(rmr,LOW);
  }
  }
