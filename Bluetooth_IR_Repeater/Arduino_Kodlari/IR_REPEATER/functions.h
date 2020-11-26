void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");
    mod = 1;
  }
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
    mod = 2;
  }
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
    mod = 3;
  }
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
    mod = 4;
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    //Serial.print(results->panasonicAddress, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  bit = results->bits;
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

}

//*******************************************************************
/*
  void ir_send() {
  if (mod == 1) {
    irsend.sendNEC(okunan, bit);
  }
  else if (mod == 2) {
    irsend.sendSony(okunan, bit);
  }
  else if (mod == 3) {
    irsend.sendRC5(okunan, bit);
  }
  else if (mod == 4) {
    irsend.sendRC6(okunan, bit);
  }
   //irsend.sendRC5(0x810, 12);
    ir_send();
    //delay(1000);
    // kod2 = strtoul(kod, 0, 16);
    //kod2 = strtoul(kod, 0, 16);
    // irsend.sendNEC(kod2, 32);
  }
*/

void ir_send(unsigned long hex_code, int bitt, int modd) {
  /*
    Serial.println("");
    Serial.println(hex_code, HEX);
    Serial.println(bitt);
    Serial.println(modd);
    Serial.println("");
    Serial.print("c: ");
    Serial.print(c);
    Serial.print(" - ");
    Serial.print("t_mode: ");
    Serial.print(t_mode);
    Serial.print(" - ");
    Serial.print("key: ");
    Serial.print(key);
    Serial.println("");
  */
  if (modd == 1) {
    irsend.sendNEC(hex_code, bitt);
  }
  else if (modd == 2) {
    irsend.sendSony(hex_code, bitt);
  }
  else if (modd == 3) {
    irsend.sendRC5(hex_code, bitt);
  }
  else if (modd == 4) {
    irsend.sendRC6(hex_code, bitt);
  }

}
