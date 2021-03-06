#include "morse.h"
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

static const char* const MorseLookupTable[] = {
        "*- ",
        "-*** ",
        "-*-* ",
        "-** ",
        "* ",
        "**-* ",
        "--* ",
        "**** ",
        "** ",
        "*--- ",
        "-*- ",
        "*-** ",
        "-- ",
        "-* ",
        "--- ",
        "*--* ",
        "--*- ",
        "*-* ",
        "*** ",
        "- ",
        "**- ",
        "***- ",
        "*-- ",
        "-**- ",
        "-*-- ",
        "--** "
};

static const char* MorseHelper_GetMorseCodeByLetter(char letter);

MorseOperationResult Morse_TranscriptTextToMorse(const char* text, char* resultBuffer){

    if(text == NULL || resultBuffer == NULL)
    {
        return ERROR;
    }

    for(int i = 0; i < strlen(text); i++)
    {
        const char* morse = MorseHelper_GetMorseCodeByLetter(text[i]);
        strcpy(resultBuffer, morse);

        resultBuffer += strlen(morse);
    }
    return SUCCESS;
}

static const char* MorseHelper_GetMorseCodeByLetter(char letter){

    if(!isalpha(letter))
        return "";

    if(!isupper(letter))
    {
        letter = toupper(letter);
    }

    int lookupIndex = (int)(letter - 64 - 1);

    return (lookupIndex >= 0 && lookupIndex < ALPHABET_SIZE) ? MorseLookupTable[lookupIndex] : "";
}


/* LED section - coding text */

static void LEDHelper_LitDelay(int delay);
static void LEDHelper_SpecialDelay(int delay);
typedef void (*Action)(int);

typedef struct MorseLEDPredicateType{
    char sign;
    Action LEDAction;
    int delay;
}MorseLEDPredicate;

// - , 1
// * , 2
// ' ' , 3

static const MorseLEDPredicate MorseLEDActionTable[3] = {
        {.sign = ' ', .LEDAction = LEDHelper_SpecialDelay, .delay = 100},
        {.sign = '-', .LEDAction = LEDHelper_LitDelay,     .delay = 300},
        {.sign = '*', .LEDAction = LEDHelper_LitDelay,     .delay = 50}
};


void LED_PerformMorseCode(MorseCode* morseCode){

    if(morseCode == NULL || morseCode->morse == NULL) return;

    if(morseCode->morse[0] == '\0') return;

    for(int index; *morseCode->morse != '\0'; morseCode->morse++)
    {
        index = (int)(*morseCode->morse % 4);
        //printf("\n%i", index);
        MorseLEDActionTable[index].LEDAction(MorseLEDActionTable[index].delay);

        //here delay
    }

    //(*morse == '*') ? 0 : (*morse == '-') ? 1 : 2
}

static void LEDHelper_LitDelay(int delay){
    /* toggle led with right delay */

    //printf("\n%i", delay);
    /*
    GPIO_PinOutSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN);
    Delay(delay);
    GPIO_PinOutClear(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN);
    */
}

static void LEDHelper_SpecialDelay(int delay){
    //printf("\n%i", delay);
}