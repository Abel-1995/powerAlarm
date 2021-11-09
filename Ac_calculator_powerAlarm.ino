//int acSensor = A0;
int acValue = A0;
#define sink_1  11
#define sink_2  12
#define sink_3  13
int digit;

#define segment_a  4
#define segment_b  5
#define segment_c  6
#define segment_d  7
#define segment_e  8
#define segment_f  9
#define segment_g  10

byte segmentPin [] = {// 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
  0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98};
byte segmentpattern [] = {segment_a, segment_b, segment_c, segment_d, segment_e, segment_f, segment_g};


void setup(){
 pinMode(sink_1, OUTPUT);
 pinMode(sink_2, OUTPUT);
 pinMode(sink_3, OUTPUT);
 pinMode(segment_a, OUTPUT);
 pinMode(segment_b, OUTPUT);
 pinMode(segment_c, OUTPUT);
 pinMode(segment_d, OUTPUT);
 pinMode(segment_e, OUTPUT);
 pinMode(segment_f, OUTPUT);
 pinMode(segment_g, OUTPUT);
 pinMode(acValue, INPUT);

 for(int i=0; i<1000; i++){
  for(int j=0; j<10; j++){
    
  digit = ((i/100)%10);
  digitalWrite(sink_1, LOW);
  digitalWrite(sink_2, HIGH);
  digitalWrite(sink_3, HIGH);
  setSegment(digit);
  delay(5);
  
  digit = ((i/10)%10);
  digitalWrite(sink_1, HIGH);
  digitalWrite(sink_2, LOW);
  digitalWrite(sink_3, HIGH);
  setSegment(digit);
  delay(5);

  digit = (i%10);
  digitalWrite(sink_1, HIGH);
  digitalWrite(sink_2, HIGH);
  digitalWrite(sink_3, LOW);
  setSegment(digit);
  delay(5);
  
// Serial.begin(9600);
 
}
 }
}
void loop(){
  acValue = analogRead(A0);
  /*acValue = (acValue) / 1023;
  acValue = acValue * 5;
  acValue = acValue * 10.55;*/
  acValue =(acValue * 0.2608);
  Serial.println(acValue);
  

  for(int j=0; j<50; j++){
    digit == (acValue / 100)%10;
    digitalWrite(sink_1, LOW);
    digitalWrite(sink_2, HIGH);
    digitalWrite(sink_3, HIGH);
    setSegment(digit);
    delay(5);
    
  
    digit = (acValue / 10) % 10;
    digitalWrite(sink_1, HIGH);
    digitalWrite(sink_2, LOW);
    digitalWrite(sink_3, HIGH);
    setSegment(digit);
    delay(5);
    

    digit = acValue % 10;
    digitalWrite(sink_1, HIGH);
    digitalWrite(sink_2, HIGH);
    digitalWrite(sink_3, LOW);
    setSegment(digit);
    delay(5);

}
}

 void setSegment(byte digit){
  byte mask = 1;
  for(int i=0; i<8; i++){
    if((segmentpattern[digit] & mask) == 0)
    digitalWrite(segmentPin[i], LOW);
    else digitalWrite(segmentPin[i], HIGH);
    mask = mask<<1;
  }
 }

