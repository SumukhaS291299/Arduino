String num1="";
int c1=10,c2=11,c3=12,c4=13,d=9;
int sus=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);

   //         2 3 4 5 6 7 8              10 11 12 13
   //pins for A B C D E F G and deci and C1 C2 C3 C4 

  //Segment up   10 2 7 11 12 3
  //Segment down 6  5 D 4  8  13
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  pinMode(d,OUTPUT);
  
  pinMode(c1,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(c3,OUTPUT);
  pinMode(c4,OUTPUT);
  
  Serial.println("Connected");
  delay(10); //Delay to make it stable
  Serial.println("Initalize Done.... ");
  digitalWrite(LED_BUILTIN, HIGH);    //Led ON
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Switch on the system 3 Ard quick blinks (INIT_START)
//  digitalWrite(LED_BUILTIN, LOW);
//  delay(50);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(30);
//  digitalWrite(LED_BUILTIN, LOW);
//  delay(50);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(30);
  
              //Conduct a serial read

//  int number=num1.toInt();
//  Serial.println("Number was "+number); 
//  
  //Set perticular bit from right to left
  //Get number from sensor
  
//  while (Serial.available() == 0){}    //Loop till there's a serial input
//  num1 = Serial.readString();            //Conduct a serial read
// 

  Serial.println("Type a 4 digit number !");    //Print

  
  while (Serial.available() == 0){}    //Loop till there's a serial input
  num1 = Serial.readString();
  int x=num1.toInt();
  displayAll(x);
  Serial.println();
  Serial.println("Next Number !");
  Serial.println();
  sus=0;
}

void displayAll(int x){
if(sus<10 || sus>=0{
  
  digitalWrite(c4,LOW);
  digitalWrite(c2,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(c3,HIGH);
  
  int first=x%10;
  x=x/10;
  SelectDigit(first);  
  String f=String(first);
  Serial.println("XXX"+f);

  delay(5);


  digitalWrite(c3,LOW);
  digitalWrite(c4,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c1,HIGH);
  int second=x%10;
  x=x/10;
  SelectDigit(second);
  String s=String(second);
  Serial.println("XX"+s+f);
//  Serial.println();
//  digitalWrite(c3,HIGH);

  delay(5);
  
  digitalWrite(c2,LOW);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  digitalWrite(c1,HIGH);
  int third=x%10;
  x=x/10;
  SelectDigit(third);
  String t=String(third);
  Serial.println("X"+t+s+f);
//  digitalWrite(c2,HIGH);

  delay(5);

  digitalWrite(c1,LOW);
  digitalWrite(c3,HIGH);
  digitalWrite(c4,HIGH);
  digitalWrite(c2,HIGH);
//  digitalWrite(c1,HIGH);
  int fourth=x%10;
  x=x/10;
  SelectDigit(fourth);
  String fo=String(fourth);
  Serial.println(fo+t+s+f);
//  digitalWrite(c1,HIGH);
  sus++;
}
}

void reset(){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
}

void SelectDigit(int n){
  reset();
  switch(n){
    case 0:
    Serial.println("Procedure to print 0");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
//    digitalWrite(8,HIGH);
    break;
    
    case 1:
    Serial.println("Procedure to print 1");
//    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
//    digitalWrite(5,HIGH);
//    digitalWrite(6,HIGH);
//    digitalWrite(7,HIGH);
//    digitalWrite(8,HIGH);
    break;
    
    case 2:
    Serial.println("Procedure to print 2");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
//    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
//    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    
    case 3:
    Serial.println("Procedure to print 3");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
//    digitalWrite(6,HIGH);
//    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    
    case 4:
    Serial.println("Procedure to print 4");
//    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
//    digitalWrite(5,HIGH);
//    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    
    case 5:
    Serial.println("Procedure to print 5");
    digitalWrite(2,HIGH);
//    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
//    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    
    case 6:
    Serial.println("Procedure to print 6");
    digitalWrite(2,HIGH);
//    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    
    case 7:
    Serial.println("Procedure to print 7");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
//    digitalWrite(5,HIGH);
//    digitalWrite(6,HIGH);
//    digitalWrite(7,HIGH);
//    digitalWrite(8,HIGH);
    break;
    
    case 8:
    Serial.println("Procedure to print 8");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    
    case 9:
    Serial.println("Procedure to print 9");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
//    digitalWrite(5,HIGH);
//    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
  }
}
