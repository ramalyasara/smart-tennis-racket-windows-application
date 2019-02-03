//#include <SoftwareSerial.h>
#include <CapacitiveSensor.h>
//SoftwareSerial mySerial(1,0);
#define hor2 26
#define hor3 28
#define hor4 30
#define ver5 32
#define ver6 34
#define ver7 36
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);       
CapacitiveSensor   cs_2_4= CapacitiveSensor(2,4);
CapacitiveSensor   cs_2_5= CapacitiveSensor(2,5);
CapacitiveSensor   cs_2_6= CapacitiveSensor(2,6);
CapacitiveSensor   cs_2_7= CapacitiveSensor(2,7);
CapacitiveSensor   cs_2_8= CapacitiveSensor(2,8);
CapacitiveSensor   cs_2_9= CapacitiveSensor(2,9);
CapacitiveSensor   cs_2_10= CapacitiveSensor(2,10);
CapacitiveSensor   cs_2_11= CapacitiveSensor(2,11);

int pos=0;
char grip;
void setup(){
  pinMode(hor2,INPUT);
  pinMode(hor3,INPUT);
  pinMode(hor4,INPUT);
  pinMode(ver5,OUTPUT);
  pinMode(ver6,OUTPUT);
  pinMode(ver7,OUTPUT);
 // pinMode(22,OUTPUT);
 // pinMode(23,OUTPUT);
 // pinMode(24,OUTPUT);
 // digitalWrite(22,HIGH);
 // digitalWrite(23,HIGH);
 // digitalWrite(24,HIGH);
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_2_11.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
 // Serial.println("START");
  //mySerial.begin(9600);
  //mySerial.println("start");

// Serial1.begin(9600);
  
}
void loop(){
 // if(Serial.available()) {
  digitalWrite(ver5,LOW);
  digitalWrite(ver6,LOW);
  digitalWrite(ver7,LOW);
  
//  mySerial.println(pos);
//  mySerial.println(grip);

//   mySerial.print(pos);
//    mySerial.print(" ");
//  mySerial.print(grip);
//      mySerial.println();

   Serial.print(pos);
   Serial.print(",");
  Serial.print(grip);
  Serial.print("\n");



  
  while((digitalRead(hor2)==HIGH && digitalRead(hor3)==HIGH && digitalRead(hor4)==HIGH) || (digitalRead(hor2)==LOW && digitalRead(hor3)==LOW && digitalRead(hor4)==LOW))
  {
  }
  pos=position();
  grip=griptype();

//position();
//Serial.print(",");
//griptype();
//Serial.print("\n");
  
//  }
}
int position(){
  if(digitalRead(hor2)==LOW){
  //  Serial.println("Working first");
      delay(5);
    digitalWrite(ver5,HIGH);
    if(digitalRead(hor2)==HIGH){
    //  Serial.print("1");
    return 1;
    }
    digitalWrite(ver5,LOW);
    delay(5);
    digitalWrite(ver6,HIGH);
    if(digitalRead(hor2)==HIGH){
    //Serial.print("2");
    return 2;
    }
    digitalWrite(ver6,LOW);
    delay(5);
    digitalWrite(ver7,HIGH);
    if(digitalRead(hor2)==HIGH){
   // Serial.print("3");
    return 3;
    }
    digitalWrite(ver7,LOW);
    delay(5);
  }
  else if(digitalRead(hor3)==LOW){
   //Serial.println("Working second");
      delay(5);
    digitalWrite(ver5,HIGH);
    if(digitalRead(hor3)==HIGH){
   // Serial.print("4");
    return 4;
    }
    digitalWrite(ver5,LOW);
    delay(5);
    digitalWrite(ver6,HIGH);
    if(digitalRead(hor3)==HIGH){
   // Serial.print("5");
    return 5;
    }
    digitalWrite(ver6,LOW);
    delay(5);
    digitalWrite(ver7,HIGH);
    if(digitalRead(hor3)==HIGH){
   // Serial.print("6");
    return 6;
    }
    digitalWrite(ver7,LOW);
    delay(5);
  }
  else if(digitalRead(hor4)==LOW){
  //Serial.println("Working third");
      delay(5);
    digitalWrite(ver5,HIGH);
    if(digitalRead(hor4)==HIGH){
   // Serial.print("7");
    return 7;
    }
    digitalWrite(ver5,LOW);
    delay(5);
    digitalWrite(ver6,HIGH);
    if(digitalRead(hor4)==HIGH){
   // Serial.print("8");
    return 8;
    }
    digitalWrite(ver6,LOW);
    delay(5);
    digitalWrite(ver7,HIGH);
    if(digitalRead(hor4)==HIGH){
   // Serial.print("9");
    return 9;
    }
    digitalWrite(ver7,LOW);
      delay(5);
  }

}
  char griptype()
  {
    long total1 =  cs_2_3.capacitiveSensor(30);
    long total2 =  cs_2_4.capacitiveSensor(30);
    long total3 =  cs_2_5.capacitiveSensor(30);
    long total4 =  cs_2_6.capacitiveSensor(30);
    long total5 =  cs_2_7.capacitiveSensor(30);
    long total6 =  cs_2_8.capacitiveSensor(30);
    long total7 =  cs_2_9.capacitiveSensor(30);
    long total8 =  cs_2_10.capacitiveSensor(30);
    long total9 =  cs_2_11.capacitiveSensor(30);

    //Serial.println(total1);
    //Serial.println(total2);
    //Serial.println(total3);
    //Serial.println(total4);
    //Serial.println(total5);
    //Serial.println(total6);
    //Serial.println(total7);
    //Serial.println(total8);
    //Serial.println(total9);

    
    if(total1<20 && total3>150 && total6<60)
   // Serial.print("A");
    return 'A'; // eastern forehand
    else if(total1<20 && total4>150 && total6<80)
    //Serial.print("B");
    return 'B'; // western backhand
    else if(total1<20 && total5>150 && total7<80)
    //Serial.print("C");
    return 'C'; // western forehand
    else if(total1<20 && total2>150 && total5<100)
  //Serial.print("D");
    return 'D'; //continental grip
    //else if(total1>100 && total2>100 && total3>40)//one hand back
 //Serial.print("E");
    //return 'E';
    //else if(total1<30 && total2>140 && total3>130)//serve
 //Serial.print("F");
    //return 'F';
    //else 
  //  (total1<30 && total2>80 && total3>80)
 //Serial.print("G");
    //return 'G';  
  }
  
