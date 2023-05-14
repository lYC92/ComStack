#include "DiagnosticIf.h"
#include "Diagnostic.h"


void ForceReset(){

}

void SystemReset(EcuResetType resetType)
{
	if(resetType == 1)
	{
		ForceReset();
	}
	else if(resetType == 2)
	{
		//ForceReset();
	}
	else if(resetType == 3)
	{
		ForceReset();
	}
}

void CommulicatonControl(CommulicationType type, communicationParam param)
{
	bool rxenable = ((type & 0x02) == 0x00);
	bool txenable = ((type & 0x01) == 0x00);
	bool CtrlNmMessage = ((param & 0x02) == 0x02);
	bool CtrlAppMessage = ((param & 0x01) == 0x01);

	if(CtrlNmMessage)
	{
		//NMSetCommulicationEnable(txenable, rxenable);

	}

	if(CtrlAppMessage)
	{
		//AppSetMsgEnable(txenable, rxenable);
	}
}

uint32_t SeedToKeyDemo(uint32_t seed)
{
	return 0x12345678;
}

byte SendFrame(uint32_t ID, byte *array, byte length, byte priority , uint8_t rtr ,uint8_t ide)
{

}

uint16_t TestF180Data = 0xF180;
uint8_t TestCurrentTemp = 0x40;
uint16_t CurrentSpeed = 0x0895;
uint8_t CurrentVoltage = 135;

uint8_t IO9826_MixMtrCtrl;
uint8_t IoControl_9826(uint8_t ctrl, uint8_t param) {
	if(ctrl == 0) {
		IO9826_MixMtrCtrl = 2;
	}
	else if(ctrl == 1)
	{
		IO9826_MixMtrCtrl = 2;
	} else if(ctrl == 2)
	{

	}else if(ctrl == 3)
	{
		if(param == 0)
		{
			IO9826_MixMtrCtrl = 0;
		}
		else if(param == 1)
		{
			IO9826_MixMtrCtrl = 1;
		}
	}
	return IO9826_MixMtrCtrl;
}

uint8_t NMGetLimpHome(void)
{
	 if (1)
	 {
		return 2;//failed
	 }
	 else
	 {
		return 0;//passed
	 }
}

//ISR(Can_Rx_Interrupt)
//{
//	uint8_t tmp;
//	uint8_t canData[8];
//	uint8_t canDlc;
//	uint8_t canRtr;
//	uint8_t canIde;
//	uint32_t canId;
//
//
//	Diagnostic_RxFrame(canId , canData , canIde , canDlc , canRtr);
//
//}
//
//ISR(RTI_Interrupt)
//{
//	// NOTE: The routine should include the following actions to obtain
//	//       correct functionality of the hardware.
//	//
//	//      The ISR is invoked by RTIF flag. The RTIF flag is cleared
//	//      if a "1" is written to the flag in CPMUFLG register.
//	//      Example: CPMUFLG = 128;
//
//	Diagnostic_1msTimer();
//}
