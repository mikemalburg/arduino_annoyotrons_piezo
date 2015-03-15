/******************************* 
* Name    : annoy_piezo_capt_planet.ino
* Author  : Mike Malburg
* Purpose : Plays the Captain Planet theme song at random intervals (Annoy-o-tron style)
*******************************/

/*************************************************
 * Public Constants
 *************************************************/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

const int DPIN_PIEZO = 0;
const long ANNOY_MIN_SEC = (60 * 4);
const long ANNOY_MAX_SEC = (60 * 20);

int Melody_01[] = 
{
  NOTE_C4, NOTE_C4, NOTE_B3, NOTE_C4, //cap-tain pla-net
  0, NOTE_C4, NOTE_A3, NOTE_B3, NOTE_C4, // he's our he-ro
  0, NOTE_C4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4, // go-nna take po-lu-tion

  NOTE_E4, NOTE_C4, NOTE_B3, NOTE_C4, // down to ze-ro
  
  0, NOTE_C4, NOTE_G3, NOTE_B3, NOTE_C4, // he's our pow-ers
  NOTE_C4, NOTE_G3, NOTE_B3, NOTE_B3, NOTE_B3, // mag-ni-fi-ied, and he's

  NOTE_C4, NOTE_G3, NOTE_B3, NOTE_D4, // fight-ing on the
  NOTE_C4, NOTE_G3, NOTE_FS3, NOTE_G3, // pla-net si-de!
};

int NoteDurations_01[] = 
{
  4, 4, 4, 4, //cap-tain pla-net
  8, 4, 8, 4, 4, //he's our he-ro
  8, 8, 8, 4, 8, 8, 8, //gon-na take po-lu-tion

  4, 4, 4, 4, // down to ze-ro

  8, 4, 8, 4, 4, //he's our pow-ers
  4, 8, 4, 8, 8, // mag-ni-fi-ied, and he's

  4, 8, 4, 4, // fight-ing on the
  4, 8, 4, 2, //  pla-net si-de!
};


// Play a melody
void playMelody(int pin, int* melody, int* noteDurations, int numNotes)
{
  int iTotalNotes;
  int iNoteDurationMs;
  int iPauseBetweenNotesMs;
  
  for (int thisNote = 0; thisNote < numNotes; thisNote++) 
  {
    iNoteDurationMs = (1000 / noteDurations[thisNote]);
    iPauseBetweenNotesMs = (iNoteDurationMs * 1.30);

    tone(pin, melody[thisNote], iNoteDurationMs);
    delay(iPauseBetweenNotesMs);
    noTone(pin);
  }
}

void setup() 
{
  //Serial.begin(9600);
  pinMode(DPIN_PIEZO, OUTPUT);
}

void loop() {
  int iNumNotes;
  long nDelay;
  
  // Play main melody
  iNumNotes = (sizeof(Melody_01) / sizeof(Melody_01[0]));
  playMelody(DPIN_PIEZO, Melody_01, NoteDurations_01, iNumNotes);
  
  randomSeed(analogRead(0));
  
  nDelay = random(ANNOY_MIN_SEC, ANNOY_MAX_SEC) * 1000;
  //Serial.println(nDelay);
  
  delay(nDelay);
}
