#ifndef BLINKY_H
#define BLINKY_H

#include "main.h"


typedef struct{
    uint8_t LedState;
    uint32_t elapsed;
    uint32_t prevTick;
    uint32_t currTick;
    uint16_t onTime;
    uint16_t offTime;
    GPIO_TypeDef *GpioPort;
    uint16_t GpioNum;
} BlinkyStruct;


typedef struct{
    uint8_t LedState;
    uint32_t elapsed;
    uint32_t prevTick;
    uint32_t currTick;
    uint8_t vecLen;
    uint8_t currVecItem;
    GPIO_TypeDef *GpioPort;
    uint16_t GpioNum;
    uint16_t *TimeVec;
} BlinkyVecStruct;


void BlinkyInit(BlinkyStruct *structIn, uint16_t onTime, uint16_t offTime, GPIO_TypeDef *GpioPort, uint16_t GpioNum);
void BlinkyUpdate(BlinkyStruct *structIn);
void BlinkyVecInit(BlinkyVecStruct *structIn, uint16_t *TimeVec, uint8_t vecLen, GPIO_TypeDef *GpioPort, uint16_t GpioNum);
void BlinkyVecUpdate(BlinkyVecStruct *structIn);


// SOS signal ... --- ...
/*
static uint16_t MorseShort = 100;
static uint16_t MorseLong = 3 * MorseShort;
static uint16_t MorseIntra = MorseShort;
static uint16_t MorseInter = 4 * MorseShort;
static uint16_t MorseSpace = 8 * MorseShort;
static uint16_t BlinkySVec[] = {MorseShort, MorseIntra, MorseShort, MorseIntra, MorseShort};
static uint16_t BlinkyOVec[] = {MorseLong, MorseIntra, MorseLong, MorseIntra, MorseLong};
static uint16_t BlinkySosVec[] = {BlinkySVec, MorseInter, BlinkyOVec, MorseInter, BlinkySVec, MorseInter};
*/

// S O S
static uint16_t BlinkySosVec[] = {
		100, 100, 100, 100, 100, 400,
		300, 100, 300, 100, 300, 400,
		100, 100, 100, 100, 100, 1500
};

static uint16_t BlinkyDoubleTap[] = {
		200, 100, 200, 800
};

static uint16_t BlinkyTripleTap[] = {
		200, 100, 200, 100, 200, 800
};

static uint16_t BlinkyQuadTap[] = {
		200, 100, 200, 100, 200, 100, 200, 800
};

#endif
