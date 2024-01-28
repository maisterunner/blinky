#include "blinky.h"
#include "main.h"


void BlinkyInit(BlinkyStruct *structIn, uint16_t onTime, uint16_t offTime, GPIO_TypeDef *GpioPort, uint16_t GpioNum){
	structIn->LedState = 0;
	structIn->elapsed = 0;
	structIn->prevTick = 0;
	structIn->currTick = 0;
	structIn->onTime = onTime;
	structIn->offTime = offTime;
	structIn->GpioPort = GpioPort;
	structIn->GpioNum = GpioNum;
}


void BlinkyUpdate(BlinkyStruct *structIn){
	structIn->currTick = HAL_GetTick();
    structIn->elapsed = structIn->currTick - structIn->prevTick;

	if(structIn->LedState == 0 && structIn->elapsed >= structIn->onTime){
		structIn->LedState = 1;
		structIn->prevTick = structIn->currTick;
		HAL_GPIO_WritePin(structIn->GpioPort, structIn->GpioNum, GPIO_PIN_SET);
	}
	else if(structIn->LedState == 1 && structIn->elapsed >= structIn->offTime){
		structIn->LedState = 0;
		structIn->prevTick = structIn->currTick;
		HAL_GPIO_WritePin(structIn->GpioPort, structIn->GpioNum, GPIO_PIN_RESET);;
	}
}

void BlinkyVecInit(BlinkyVecStruct *structIn, uint16_t *TimeVec, uint8_t vecLen, GPIO_TypeDef *GpioPort, uint16_t GpioNum){
	structIn->LedState = 0;
	structIn->elapsed = 0;
	structIn->prevTick = 0;
	structIn->currTick = 0;
	structIn->vecLen = vecLen;
	structIn->currVecItem = 0;
	structIn->GpioPort = GpioPort;
	structIn->GpioNum = GpioNum;
	structIn->TimeVec = TimeVec;
}


void BlinkyVecUpdate(BlinkyVecStruct *structIn){
	structIn->currTick = HAL_GetTick();
    structIn->elapsed = structIn->currTick - structIn->prevTick;

	if(structIn->LedState == 0 && structIn->elapsed >= *(structIn->TimeVec+structIn->currVecItem) ){
		structIn->LedState = 1;
		structIn->prevTick = structIn->currTick;
		HAL_GPIO_WritePin(structIn->GpioPort, structIn->GpioNum, GPIO_PIN_SET);
		if(structIn->currVecItem >= structIn->vecLen){
			structIn->currVecItem = 0;
		}else{
			structIn->currVecItem++;
		}
	}
	else if(structIn->LedState == 1 && structIn->elapsed >= *(structIn->TimeVec+structIn->currVecItem) ){
		structIn->LedState = 0;
		structIn->prevTick = structIn->currTick;
		HAL_GPIO_WritePin(structIn->GpioPort, structIn->GpioNum, GPIO_PIN_RESET);
		if(structIn->currVecItem >= structIn->vecLen){
			structIn->currVecItem = 0;
		}else{
			structIn->currVecItem++;
		}
	}
}
