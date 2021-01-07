#include <stdio.h>
#include "morse.h"
#include "string.h"


int main() {


    const char* textToMorse = "Marcin";
    char morseResultBuffer[100];

    MorseCode m_code;
    m_code.morse = morseResultBuffer;

    Morse_TranscriptTextToMorse(textToMorse, morseResultBuffer);

    printf("\nTranscripted: %s", morseResultBuffer);
    printf("\nLength %i", strlen(morseResultBuffer));


    LED_PerformMorseCode(&m_code);


    return 0;
}
