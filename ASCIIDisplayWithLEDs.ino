const char* words = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz !.,";
size_t lengthOfWords = strlen(words);
size_t wordsIndex = 0;
unsigned long debounceDelay = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, INPUT);
}

void loop() {
  showACharatecerWithLeds(&words[wordsIndex]);

  int reading = digitalRead(8);
  if (reading == HIGH){
    wordsIndex++;
    if (wordsIndex > lengthOfWords -1) {
      wordsIndex = 0;
    }
    delay(debounceDelay);
  }
}



void showACharatecerWithLeds(const char* character) {
  shutAllLeds();
  for (int i = 7; 0 <= i; i --)
    if ((*character >> i) & 0x01) {
      digitalWrite(i, HIGH);
    }
}

void testButton()
{
  int value = digitalRead(8);
  digitalWrite(7, value);
}

void ledTest() {
  for (int i = 0; i < 3; i++) {
    shutAllLeds();
    delay(500);
    lightAllLeds();
    delay(500);
  }

  shutAllLeds();

  for (int i = 0; i < 8; i++) {
    digitalWrite(i, HIGH);
    delay(250);
  }
}

void shutAllLeds() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void lightAllLeds() {
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}
