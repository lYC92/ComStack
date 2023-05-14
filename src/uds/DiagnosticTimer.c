#include "Cpu.h"
#include "DiagnosticTimer.h"
#include "time.h"

static uint32_t SystemTickCount = 0;

void sleepNs(uint32_t ns) {
	struct timespec timeout, timerem;
	assert(ns < 1000000000UL);
	timeout.tv_sec = 0;
	timeout.tv_nsec = (int32_t) ns;
	nanosleep(&timeout, &timerem);
}

void sleepMs(uint32_t ms) {
	struct timespec timeout, timerem;
	timeout.tv_sec = (int32_t) ms / 1000;
	timeout.tv_nsec = (int32_t) (ms % 1000) * 1000000;
	nanosleep(&timeout, &timerem);
}

void DiagTimer_Init(void) {

}

void DiagTimer_Set(DiagTimer *STimer, uint32_t TimeLength) {
	STimer->TimerCounter = SystemTickCount + TimeLength;
	STimer->valid = TRUE;
}

void DiagTimer_Stop(DiagTimer *STimer) {
	STimer->valid = FALSE;
}

bool DiagTimer_HasStopped(DiagTimer *STimer) {
	return (STimer->valid == FALSE);
}

bool DiagTimer_HasExpired(DiagTimer *STimer) {
	if (STimer->valid == TRUE) {
		if (STimer->TimerCounter == 0) {
			STimer->valid = FALSE;
			return TRUE;
		} else if ((SystemTickCount - STimer->TimerCounter) <= 0x7fffffff) {
			STimer->TimerCounter = 0;	//set timer to stop
			STimer->valid = FALSE;
			return TRUE;
		} else {
			return FALSE;
		}
	} else {
		return FALSE;
	}
}

void DiagTimer_WaitExpired(DiagTimer *STimer) {
	while (1) {
		if (DiagTimer_HasExpired(STimer))
			break;
		//WatchDog_Feed();
	}
}

void DiagTimer_DelayMs(uint32_t ms) {
	sleepMs(ms);
}

void DiagTimer_DelayUs(uint32_t us) {
	sleepNs(us * 1000);
}

uint32_t DiagTimer_GetTickCount(void) {
	return (SystemTickCount);
}

/**
 * @brief  1ms interval.
 * @param  None.
 * @retval None.
 */
void DiagTimer_ISR_Proc(void) {
	SystemTickCount++;
}

