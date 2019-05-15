int dataIn = 2;
int CS = 3;
int clock = 4;
int e = 0;           


                    
byte max7219_reg_noop        = 0x00; //ASCII(0)
byte max7219_reg_digit0      = 0x01; //ASCII(1)
byte max7219_reg_digit1      = 0x02; //ASCII(2)
byte max7219_reg_digit2      = 0x03; //ASCII(3)
byte max7219_reg_digit3      = 0x04; //ASCII(4)
byte max7219_reg_digit4      = 0x05; //ASCII(5)
byte max7219_reg_digit5      = 0x06; //ASCII(6)
byte max7219_reg_digit6      = 0x07; //ASCII(7)
byte max7219_reg_digit7      = 0x08; //ASCII(8)
byte max7219_reg_decodeMode  = 0x09; //ASCII(9)
byte max7219_reg_intensity   = 0x0a; //ASCII(10)
byte max7219_reg_scanLimit   = 0x0b; //ASCII(11)
byte max7219_reg_shutdown    = 0x0c; //ASCII(12)
byte max7219_reg_displayTest = 0x0f; //ASCII(13)

void putByte(byte data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);      
    digitalWrite( clock, LOW);   
    if (data & mask){            
      digitalWrite(dataIn, HIGH);
    }else{
      digitalWrite(dataIn, LOW); 
    }
    digitalWrite(clock, HIGH);   
    --i;                         
  }
}

void led_matrix( byte reg, byte col) {    

  digitalWrite(CS, LOW);            
  putByte(reg);                  
  putByte(col);   
  digitalWrite(CS, LOW);       
  digitalWrite(CS,HIGH); 
}


void setup () {


  pinMode(dataIn, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(CS,   OUTPUT);
  
  digitalWrite(13, HIGH);  

  led_matrix(max7219_reg_scanLimit, 0x07);      
  led_matrix(max7219_reg_decodeMode, 0x00);  
  led_matrix(max7219_reg_shutdown, 0x01);    
  led_matrix(max7219_reg_displayTest, 0x00); 
   for (e=1; e<=8; e++) {     
    led_matrix(e,0);
  }
  led_matrix(max7219_reg_intensity, 0x0f & 0x0f);    
}  

void loop () {
  
   led_matrix(1,255);                     //+ + + + + + + +
   led_matrix(2,129);                    // + - - - - - - +
   led_matrix(3,129);                    // + - - - - - - +
   led_matrix(4,255);                    // + + + + + + + +                 // 9
   led_matrix(5,1);                      // - - - - - - - +
   led_matrix(6,1);                      // - - - - - - - +
   led_matrix(7,1);                      // - - - - - - - +
   led_matrix(8,255);                   //  + + + + + + + +
 
  delay(1000);

   led_matrix(1,255);                    //  + + + + + + + +
   led_matrix(2,129);                    // + - - - - - - +
   led_matrix(3,129);                    // + - - - - - - +
   led_matrix(4,255);                    // + + + + + + + +                //8
   led_matrix(5,129);                  //   + - - - - - - +
   led_matrix(6,129);                  //   + - - - - - - +
   led_matrix(7,129);                  //   + - - - - - - +
   led_matrix(8,255);                   //  + + + + + + + +
 
  delay(1000);
  
   led_matrix(1,255);                   //+ + + + + + + +
   led_matrix(2,1);                    // - - - - - - - +
   led_matrix(3,1);                    // - - - - - - - +
   led_matrix(4,1);                    // - - - - - - - +                  //7
   led_matrix(5,1);                    // - - - - - - - +
   led_matrix(6,1);                    // - - - - - - - +
   led_matrix(7,1);                    // - - - - - - - +
   led_matrix(8,1);                   //  - - - - - - - +
 
  delay(1000);

   led_matrix(1,255);                    // + + + + + + + +
   led_matrix(2,128);                   // + - - - - - - -
   led_matrix(3,128);                   // + - - - - - - -
   led_matrix(4,255);                   // + + + + + + + +                /6/
   led_matrix(5,129);                  //  + - - - - - - +
   led_matrix(6,129);                  //  + - - - - - - +
   led_matrix(7,129);                  //  + - - - - - - +
   led_matrix(8,255);                   // + + + + + + + +
 
  delay(1000);

   led_matrix(1,255);                    // + + + + + + + +
   led_matrix(2,128);                   // + - - - - - - -
   led_matrix(3,128);                   // + - - - - - - -
   led_matrix(4,255);                   // + + + + + + + +              //5
   led_matrix(5,1);                     // - - - - - - - +
   led_matrix(6,1);                     // - - - - - - - +
   led_matrix(7,1);                     // - - - - - - - +
   led_matrix(8,255);                   // + + + + + + + +
 
  delay(1000);

   led_matrix(1,129);                    // + - - - - - - +
   led_matrix(2,129);                   // + - - - - - - +
   led_matrix(3,129);                   // + - - - - - - +
   led_matrix(4,255);                   // + + + + + + + +              //4
   led_matrix(5,1);                     // - - - - - - - +
   led_matrix(6,1);                     // - - - - - - - +
   led_matrix(7,1);                     // - - - - - - - +
   led_matrix(8,1);                     // - - - - - - - +
   
  delay(1000);

   led_matrix(1,255);                     // + + + + + + + +
   led_matrix(2,1);                      // - - - - - - - +
   led_matrix(3,1);                      // - - - - - - - +
   led_matrix(4,255);                    // + + + + + + + +              //3
   led_matrix(5,1);                      // - - - - - - - +
   led_matrix(6,1);                      // - - - - - - - +
   led_matrix(7,1);                      // - - - - - - - +
   led_matrix(8,255);                    // + + + + + + + +
 
  delay(1000);

   led_matrix(1,255);                      //+ + + + + + + +
   led_matrix(2,1);                      // - - - - - - - +
   led_matrix(3,1);                      // - - - - - - - +
   led_matrix(4,255);                    // + + + + + + + +            //2
   led_matrix(5,128);                    // + - - - - - - -
   led_matrix(6,128);                    // + - - - - - - -
   led_matrix(7,128);                    // + - - - - - - -
   led_matrix(8,255);                   //  + + + + + + + +
 
  delay(1000);

   led_matrix(1,1);                      //- - - - - - - +
   led_matrix(2,1);                    // - - - - - - - +
   led_matrix(3,1);                    // - - - - - - - +
   led_matrix(4,1);                    // - - - - - - - +
   led_matrix(5,1);                    // - - - - - - - +
   led_matrix(6,1);                    // - - - - - - - +
   led_matrix(7,1);                    // - - - - - - - +
   led_matrix(8,1);                   //  - - - - - - - +
 
  delay(1000);

   led_matrix(1,255);                      //+ + + + + + + +
   led_matrix(2,129);                    // + - - - - - - +
   led_matrix(3,129);                    // + - - - - - - +
   led_matrix(4,129);                    // + - - - - - - +
   led_matrix(5,129);                    // + - - - - - - +
   led_matrix(6,129);                    // + - - - - - - +
   led_matrix(7,129);                    // + - - - - - - +
   led_matrix(8,255);                   //  + + + + + + + +
 
  delay(10000);

}
