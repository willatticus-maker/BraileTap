x #include <HijelHID_BLEKeyboard.h>

HijelHID_BLEKeyboard bleKeyboard;

#define DOT1 34
#define DOT2 35
#define DOT3 32
#define DOT4 33
#define DOT5 25

#define THRESHOLD 3000

char chordLookup(int chord) {
  switch(chord) {
    case 0b00001: return 'a';
    case 0b00010: return 'b';
    case 0b00100: return 'c';
    case 0b01000: return 'd';
    case 0b10000: return 'e';
    case 0b00011: return 'f';
    case 0b00101: return 'g';
    case 0b01001: return 'h';
    case 0b10001: return 'i';
    case 0b00110: return 'j';
    case 0b01010: return 'k';
    case 0b10010: return 'l';
    case 0b01100: return 'm';
    case 0b10100: return 'n';
    case 0b11000: return 'o';
    case 0b00111: return 'p';
    case 0b01011: return 'q';
    case 0b10011: return 'r';
    case 0b01101: return 's';
    case 0b10101: return 't';
    case 0b11001: return 'u';
    case 0b01110: return 'v';
    case 0b10110: return 'w';
    case 0b11010: return 'x';
    case 0b11100: return 'y';
    case 0b01111: return 'z';
    case 0b11110: return ' ';
    case 0b11111: return '\b';  e
    case 0b00000: return 0;
    default: return 0;
  }
}

bool isPressed(int pin) {
  return analogRead(pin) > THRESHOLD;
}

int buildingChord = 0;
unsigned long windowStart = 0;
bool windowOpen = false;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  Serial.println("BrailleGlove starting...");
}

void loop() {
  int chord = 0;
  if (isPressed(DOT1)) chord |= 0b00001;
  if (isPressed(DOT2)) chord |= 0b00010;
  if (isPressed(DOT3)) chord |= 0b00100;
  if (isPressed(DOT4)) chord |= 0b01000;
  if (isPressed(DOT5)) chord |= 0b10000;

  if (chord != 0) {
    if (!windowOpen) {
      windowOpen = true;
      windowStart = millis();
      buildingChord = chord;
    } else {
      buildingChord |= chord;
    }
  }

  if (windowOpen && millis() - windowStart > 150) {
    char letter = chordLookup(buildingChord);
    if (letter != 0 && bleKeyboard.isConnected()) {
      bleKeyboard.print(letter);
      Serial.println(letter);
    }
    buildingChord = 0;
    windowOpen = false;
  }

  delay(10);
}

