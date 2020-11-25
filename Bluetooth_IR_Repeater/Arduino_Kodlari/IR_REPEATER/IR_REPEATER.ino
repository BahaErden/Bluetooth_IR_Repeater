/*
  bluetooth commands:
  1 --> power
  2 --> mute
  3 --> up
  4 --> left
  5 --> ok
  6 --> right
  7 --> back
  8 --> down
  9 --> vol up
  a --> play
  b --> ch up
  c --> vol down
  d --> pause
  e --> ch down
  mode1 --> switch on
  mode0 --> swithc off
*/

// Transmitter leds pin --> 3
#include <EEPROM.h>

#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;


unsigned long e_oku;


unsigned long tus1;
unsigned long tus2;
unsigned long tus3;
unsigned long tus4;
unsigned long tus5;
unsigned long tus6;
unsigned long tus7;
unsigned long tus8;
unsigned long tus9;
unsigned long tus10;
unsigned long tus11;
unsigned long tus12;
unsigned long tus13;
unsigned long tus14;

int bit1;
int bit2;
int bit3;
int bit4;
int bit5;
int bit6;
int bit7;
int bit8;
int bit9;
int bit10;
int bit11;
int bit12;
int bit13;
int bit14;

int mode1;
int mode2;
int mode3;
int mode4;
int mode5;
int mode6;
int mode7;
int mode8;
int mode9;
int mode10;
int mode11;
int mode12;
int mode13;
int mode14;

byte led = 13;
byte state_pin = 5;
int state;

int mod;
int bit;

int c = 0;

int t_mode;
int key = 0;

int yuz;

byte st = 0;

#include <SoftwareSerial.h>
SoftwareSerial bt(2, 4); // 2 > bt TX , 3 > bt RX
String cumle = "";

#include "reset.h";
#include "bluetooth.h"
#include "functions.h"

void setup()
{
  bt.begin(9600);
  Serial.begin(9600);

  irrecv.enableIRIn(); // Start the receiver
  pinMode(led, OUTPUT);



  tus1 = Read(4);
  mode1 = EEPROM.read(4);
  bit1 = EEPROM.read(5);
  Serial.println(tus1, HEX);

  tus2 = Read(10);
  mode2 = EEPROM.read(10);
  bit2 = EEPROM.read(11);

  Serial.println(tus2, HEX);

  tus3 = Read(16);
  mode3 = EEPROM.read(16);
  bit3 = EEPROM.read(17);

  Serial.println(tus3, HEX);
  tus4 = Read(22);
  mode4 = EEPROM.read(22);
  bit4 = EEPROM.read(23);

  Serial.println(tus4, HEX);
  tus5 = Read(28);
  mode5 = EEPROM.read(28);
  bit5 = EEPROM.read(29);//

  Serial.println(tus5, HEX);
  tus6 = Read(34);
  mode6 = EEPROM.read(34);
  bit6 = EEPROM.read(35);

  Serial.println(tus6, HEX);
  tus7 = Read(40);
  mode7 = EEPROM.read(40);
  bit7 = EEPROM.read(41);

  tus8 = Read(46);
  mode8 = EEPROM.read(46);
  bit8 = EEPROM.read(47);

  tus9 = Read(52);
  mode9 = EEPROM.read(52);
  bit9 = EEPROM.read(53);

  tus10 = Read(58);
  mode10 = EEPROM.read(58);
  bit10 = EEPROM.read(59);

  tus11 = Read(64);
  mode11 = EEPROM.read(64);
  bit11 = EEPROM.read(65);

  tus12 = Read(70);
  mode12 = EEPROM.read(70);
  bit12 = EEPROM.read(71);
  Serial.println(tus12, HEX);
  tus13 = Read(76);
  mode13 = EEPROM.read(76);
  bit13 = EEPROM.read(77);

  tus14 = Read(82);
  mode14 = EEPROM.read(82);
  bit14 = EEPROM.read(83);

  t_mode = EEPROM.read(100);
  /*
    Serial.print("Tus 1: ");
    Serial.print(tus1, HEX);
    Serial.print(" - ");
    Serial.print("Mode 1: ");
    Serial.print(mode1);
    Serial.print(" - ");
    Serial.print("Bit 1: ");
    Serial.println(bit1);
  */
  digitalWrite(led, 1);
  delay(500);
  digitalWrite(led, 0);
  delay(100);
}

void loop() {
  state = digitalRead(state_pin);
  if (state == 1) {
    if(st == 1){
      digitalWrite(led, 0);
      delay(100);
      digitalWrite(led, 1);
      delay(100);
      digitalWrite(led, 0);
      delay(100);

      digitalWrite(led, 1);
      delay(100);
      digitalWrite(led, 0);
      delay(100);

      digitalWrite(led, 1);
      delay(100);
      digitalWrite(led, 0);
   
      st = 0;
      
    }
  }
  else{
    if(st == 0){
      digitalWrite(led, 1);
      st = 1;
      
    }
  }
    if (irrecv.decode(&results) != 0 && t_mode == 1 && c == 0) {
      dump(&results);
      e_oku = results.value;


      digitalWrite(led, 1);
      delay(50);
      digitalWrite(led, 0);

      irrecv.resume();

      EEPROM.write(100, 0);
      c = 1;
    }

    bt_data();
    if (t_mode == 1 && key == 1 && c == 1) {
      Write_clear(6);
      delay(50);
      Write(e_oku, mod, bit, 6);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 2 && c == 1) {
      Write_clear(12);
      delay(100);
      Write(e_oku, mod, bit, 12);
      delay(100);
      RESET();
    }
    else if (t_mode == 1 && key == 3 && c == 1) {
      Write_clear(18);
      delay(50);
      Write(e_oku, mod, bit, 18);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 4 && c == 1) {
      Write_clear(24);
      delay(50);
      Write(e_oku, mod, bit, 24);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 5 && c == 1) {
      Write_clear(30);
      delay(50);
      Write(e_oku, mod, bit, 30);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 6 && c == 1) {
      Write_clear(36);
      delay(50);
      Write(e_oku, mod, bit, 36);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 7 && c == 1) {
      Write_clear(42);
      delay(50);
      Write(e_oku, mod, bit, 42);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 8 && c == 1) {
      Write_clear(48);
      delay(50);
      Write(e_oku, mod, bit, 48);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 9 && c == 1) {
      Write_clear(54);
      delay(50);
      Write(e_oku, mod, bit, 54);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 10 && c == 1) {
      Write_clear(60);
      delay(50);
      Write(e_oku, mod, bit, 60);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 11 && c == 1) {
      Write_clear(66);
      delay(50);
      Write(e_oku, mod, bit, 66);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 12 && c == 1) {
      Write_clear(72);
      delay(50);
      Write(e_oku, mod, bit, 72);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 13 && c == 1) {
      Write_clear(78);
      delay(50);
      Write(e_oku, mod, bit, 78);
      delay(50);
      RESET();
    }
    else if (t_mode == 1 && key == 14 && c == 1) {
      Write_clear(84);
      delay(50);
      Write(e_oku, mod, bit, 84);
      delay(50);
      RESET();
    }
    //*********************************************************************************************************************
    if (t_mode == 0 && key == 1) {
      ir_send(tus1, bit1, mode1);
      key = 0;
    }
    else if (t_mode == 0 && key == 2) {
      ir_send(tus2, bit2, mode2);
      key = 0;
    }
    else if (t_mode == 0 && key == 3) {
      ir_send(tus3, bit3, mode3);
      key = 0;
    }
    else if (t_mode == 0 && key == 4) {
      ir_send(tus4, bit4, mode4);
      key = 0;
    }
    else if (t_mode == 0 && key == 5) {
      ir_send(tus5, bit5, mode5);
      key = 0;
    }
    else if (t_mode == 0 && key == 6) {
      ir_send(tus6, bit6, mode6);
      key = 0;
    }
    else if (t_mode == 0 && key == 7) {
      ir_send(tus7, bit7, mode7);
      key = 0;
    }
    else if (t_mode == 0 && key == 8) {
      ir_send(tus8, bit8, mode8);
      key = 0;
    }
    else if (t_mode == 0 && key == 9) {
      ir_send(tus9, bit9, mode9);
      key = 0;
    }
    else if (t_mode == 0 && key == 10) {
      ir_send(tus10, bit10, mode10);
      key = 0;
    }
    else if (t_mode == 0 && key == 11) {
      ir_send(tus11, bit11, mode11);
      key = 0;
    }
    else if (t_mode == 0 && key == 12) {
      ir_send(tus12, bit12, mode12);
      key = 0;
    }
    else if (t_mode == 0 && key == 13) {
      ir_send(tus13, bit13, mode13);
      key = 0;
    }
    else if (t_mode == 0 && key == 14) {
      ir_send(tus14, bit14, mode14);
      key = 0;
    }
  
  
}
void Write(unsigned long gelen, int moddd, int bittt, int b1) {

  EEPROM.write(b1 - 6, gelen & 0xFF);
  EEPROM.write(b1 - 5, (gelen & 0xFF00) >> 8);
  EEPROM.write(b1 - 4, (gelen & 0xFF0000) >> 16);
  EEPROM.write(b1 - 3, (gelen & 0xFF000000) >> 24);

  EEPROM.write(b1 - 2, moddd);
  EEPROM.write(b1 - 1, bittt);
}
void Write_clear(int b1) {

  EEPROM.write(b1 - 6, 0);
  EEPROM.write(b1 - 5, 0);
  EEPROM.write(b1 - 4, 0);
  EEPROM.write(b1 - 3, 0);

  EEPROM.write(b1 - 2, 0);
  EEPROM.write(b1 - 1, 0);
}
unsigned long Read(int a1) {
  byte val = EEPROM.read(a1 - 1);
  unsigned long ir_code = val;
  val = EEPROM.read(a1 - 2);
  ir_code = (ir_code << 8) | val;
  val = EEPROM.read(a1 - 3);
  ir_code = (ir_code << 8) | val;
  val = EEPROM.read(a1 - 4);
  ir_code = (ir_code << 8) | val;
  return ir_code;
}
