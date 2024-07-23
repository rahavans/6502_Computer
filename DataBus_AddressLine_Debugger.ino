const char addressLine[] = {22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52};
#define CLOCK 2
#define READ_WRITE_SELECT 3
const char dataBus[] = {39,41,43,45,47,49,51,53};

volatile bool dataReady = false;

void setup() {
  for (int i = 0; i < 16; i++) {
    pinMode(addressLine[i], INPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(dataBus[i], INPUT);
  }
  pinMode(CLOCK, INPUT);
  pinMode(READ_WRITE_SELECT, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING);
  Serial.begin(57600);
}

void onClock() {
    unsigned int address = 0;
    for (int i = 0; i < 16; i ++) {
      int bit = digitalRead(addressLine[i]) ? 1 : 0;
      Serial.print(bit);
      address = (address << 1) + bit;
    }
    Serial.print("    ");

    unsigned int data = 0;
    for (int j = 0; j < 8; j++) {
      int bit = digitalRead(dataBus[j]) ? 1 : 0;
      Serial.print(bit);
      data = (data << 1) + bit;
    }
    char output[36];
    sprintf(output, "  %04x %c %02x", address, digitalRead(READ_WRITE_SELECT) ? 'R' : 'W', data);
    Serial.println(output);
  }

void loop(){}
