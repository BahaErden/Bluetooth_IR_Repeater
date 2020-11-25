void bt_data() {
  while (bt.available()) {
    char c = (char)bt.read();
    cumle += c;
  }


  if (cumle.length() > 0) { // komut var ise
    //Serial.println(cumle);

    if (cumle.indexOf("mode1") >= 0) {
      EEPROM.write(100, 1);
      delay(100);
      RESET();
    }
    else if (cumle.indexOf("mode0") >= 0) {
      t_mode = 0;
    }
    else if (cumle.indexOf("1") >= 0) {
      key = 1;
    }
    else if (cumle.indexOf("2") >= 0) {
      key = 2;
    }
    else if (cumle.indexOf("3") >= 0) {
      key = 3;
    }
    else if (cumle.indexOf("4") >= 0) {
      key = 4;
    }
    else if (cumle.indexOf("5") >= 0) {
      key = 5;
    }
    else if (cumle.indexOf("6") >= 0) {
      key = 6;
    }
    else if (cumle.indexOf("7") >= 0) {
      key = 7;
    }
    else if (cumle.indexOf("8") >= 0) {
      key = 8;
    }
    else if (cumle.indexOf("9") >= 0) {
      key = 9;
    }
    else if (cumle.indexOf("a") >= 0) {
      key = 10;
    }
    else if (cumle.indexOf("b") >= 0) {
      key = 11;
    }
    else if (cumle.indexOf("c") >= 0) {
      key = 12;
    }
    else if (cumle.indexOf("d") >= 0) {
      key = 13;
    }
    else if (cumle.indexOf("e") >= 0) {
      key = 14;
    }
  }
  delay(50);
  cumle = "";

}
