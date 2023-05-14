#ifndef UDS_DIAGNOSTICIF_H_
#define UDS_DIAGNOSTICIF_H_

#include "Cpu.h"
#include "Diagnostic.h"


void ForceReset();
void SystemReset(EcuResetType resetType);
void CommulicatonControl(CommulicationType type, communicationParam param);
uint32_t SeedToKeyDemo(uint32_t seed);
byte SendFrame(uint32_t ID, byte *array, byte length, byte priority , uint8_t rtr ,uint8_t ide);
uint8_t IoControl_9826(uint8_t ctrl, uint8_t param);
uint8_t NMGetLimpHome(void);
extern uint8_t IO9826_MixMtrCtrl;
extern uint8_t TestCurrentTemp;
extern uint16_t CurrentSpeed;
extern uint8_t CurrentVoltage;

#endif /* UDS_DIAGNOSTICIF_H_ */
