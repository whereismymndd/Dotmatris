byte din=7,cs=6,clk=5,x,y;
float z;
uint16_t i;//xxxx(x)1111(adress)00000001(data)
void setup() {
pinMode(din,OUTPUT);
pinMode(cs,OUTPUT);
pinMode(clk,OUTPUT);
digitalWrite(din,LOW);
digitalWrite(cs,HIGH);
digitalWrite(clk,LOW);
//Serial.begin(9600);
dotinit();
dotclear();
dotyak(1,4);
delay(1000);
}
void loop() {
  dotyak(1,8);
  dotyak(2,0);
  dotyak(3,8);
  dotyak(4,0);
  dotyak(5,8);
  dotyak(6,0);
  dotyak(7,8);
  dotyak(8,0);
  delay(500);
  dotyak(1,7);
  dotyak(2,1);
  dotyak(3,7);
  dotyak(4,1);
  dotyak(5,7);
  dotyak(6,1);
  dotyak(7,7);
  dotyak(8,1);
  delay(500);
  dotyak(1,6);
  dotyak(2,3);
  dotyak(3,6);
  dotyak(4,3);
  dotyak(5,6);
  dotyak(6,3);
  dotyak(7,6);
  dotyak(8,3);
  delay(500);
  dotyak(1,5);
  dotyak(2,4);
  dotyak(3,5);
  dotyak(4,4);
  dotyak(5,5);
  dotyak(6,4);
  dotyak(7,5);
  dotyak(8,4);
  delay(500);
  dotyak(1,4);
  dotyak(2,5);
  dotyak(3,4);
  dotyak(4,5);
  dotyak(5,4);
  dotyak(6,5);
  dotyak(7,4);
  dotyak(8,5);
  delay(500);
  dotyak(1,3);
  dotyak(2,6);
  dotyak(3,3);
  dotyak(4,6);
  dotyak(5,3);
  dotyak(6,6);
  dotyak(7,3);
  dotyak(8,6);
  delay(500);
  dotyak(1,1);
  dotyak(2,7);
  dotyak(3,1);
  dotyak(4,7);
  dotyak(5,1);
  dotyak(6,7);
  dotyak(7,1);
  dotyak(8,7);
  delay(500);
  dotyak(1,0);
  dotyak(2,8);
  dotyak(3,0);
  dotyak(4,8);
  dotyak(5,0);
  dotyak(6,8);
  dotyak(7,0);
  dotyak(8,8);
  delay(500);
}
void dotM(uint16_t dta){
digitalWrite(cs,LOW);
for (i=16;i>0;i=i-1){
  x=((dta>>(i-1))&0x0001);// 
  digitalWrite(din,x);
//  Serial.print(x);
  digitalWrite(clk,1);
  digitalWrite(clk,0);
}
//Serial.println();
digitalWrite(cs,HIGH);
}
void dotyak(byte sutun,byte dt){
  //Serial.print("dt1. = ");
  //Serial.println(dt,BIN);
 z = pow(2,dt-1);
  //Serial.print("z = ");
  //Serial.println(z,BIN);
  dt = char(z)+1;
  //Serial.print("dt2 = ");
  //Serial.println(dt,BIN);
  
uint16_t y = ((sutun)<<8) + dt;
dotM(y);
//Serial.println(y,BIN);
}
/*void dotsondur(byte sutn,byte dte){
  dte=!byte(pow(2,dte-1))+1;
uint16_t y = ((sutn)<<8) + dte;
dotM(y);
}*/
void dotinit(){
dotM(0x0b07);// scan limit digits 0,1,2,3,4,5,6,7
dotM(0x0900);// decode mode 0-7
dotM(0x0a0f);// intensity 15
dotM(0x0C01);// shutdown normal mode
dotM(0x0F01);// displaytest mode
delay(1000);
dotM(0x0F00);// displaytest normal
}
void dotclear(){
dotM(0x0100);
dotM(0x0200); 
dotM(0x0300);
dotM(0x0400);
dotM(0x0500);
dotM(0x0600);
dotM(0x0700);
dotM(0x0800);
}


