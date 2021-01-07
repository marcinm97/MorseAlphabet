#ifndef MORSEALPHABET_MORSE_H
#define MORSEALPHABET_MORSE_H

typedef enum MorseOperationResultType{
    ERROR,
    SUCCESS
}MorseOperationResult;

/* Alphabet text to Morse code transcription */
MorseOperationResult Morse_TranscriptTextToMorse(const char* text, char* resultBuffer);

/* Using strong types */
typedef struct MorseCodeType{
    const char* morse;
}MorseCode;

/* LED coding */
void LED_PerformMorseCode(MorseCode* morseCode);

#endif //MORSEALPHABET_MORSE_H
