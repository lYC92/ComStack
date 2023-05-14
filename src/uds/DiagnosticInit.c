#include <stdlib.h>
#include "DiagnosticInit.h"
#include "Diagnostic.h"
#include "DiagnosticIf.h"

#include "Cpu.h"

void Diagnostic_Init_Config(void)
{
	Diagnostic_Init(0x721, 0x728 , 0x7DF, 0xA00 , 1024 , SendFrame,0x0032,0x00C8);
   	//********************************** service 10*****************************************//
   	//Diagnostic_Set2ndReqAndResID(0x18DA19F9, 0x18DAF919 , 0x18DBFFF9);

	InitSetSessionSupportAndSecurityAccess(TRUE,0x10,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO);
	InitSetSessionControlParam(TRUE , TRUE , TRUE , FALSE , FALSE , TRUE);

	//********************************** service 27*****************************************//

	InitAddSecurityAlgorithm(LEVEL_ONE,SeedToKeyDemo,0x01,0x02, NULL ,3 , 10000, SUB_PROGRAM | SUB_EXTENDED,4);
	InitFactorySecuriyAlgorithm();
	//InitAddSecurityAlgorithm(LEVEL_THREE,HD10SeedToKey,0x07,0x08, NULL ,3 , 10000, SUB_PROGRAM);
	InitSetSessionSupportAndSecurityAccess(TRUE,0x27,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_UNSUPPORT,LEVEL_UNSUPPORT);

	//********************************** service 3E*****************************************//

	InitSetSessionSupportAndSecurityAccess(TRUE,0x3E,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO);
	InitSetTesterPresentSupress(TRUE);
	  //********************************** service 11*****************************************//


	InitSetSessionSupportAndSecurityAccess(TRUE,0x11,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO);
	InitSetSysResetParam(TRUE , FALSE , FALSE , FALSE , FALSE , SystemReset , TRUE);

	   //********************************** service 28*****************************************//

	InitSetSessionSupportAndSecurityAccess(TRUE,0x28,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO);
	InitSetCommControlParam(TRUE , TRUE , TRUE , TRUE , TRUE , TRUE , TRUE , CommulicatonControl , TRUE);
	 //********************************** service 85*****************************************//

	InitSetSessionSupportAndSecurityAccess(TRUE,0x85,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO);
	InitSetDTCControlSupress(TRUE);
	  //********************************** service 22  2E  2F*****************************************//

	InitAddDID(0xF180, 2 , NULL ,  EEPROM_DID , NULL , READONLY , 0 ,TRUE);//ֻ�ܶ���DID,�洢��EEPROM�У�������������ʱд
	InitAddDID(0xF190, 17, NULL , EEPROM_DID , NULL , READWRITE , 0 , FALSE);//�ɶ�д��DID���洢��EEPROM��
	InitAddDID(0x9816,1 , &TestCurrentTemp , REALTIME_DID , NULL , READONLY , 0 ,FALSE);//ֻ��DID��ʵʱ����(�籨�����ݵ�)��
	InitAddDID(0x9823,1 , &IO9826_MixMtrCtrl , IO_DID , IoControl_9826 , READWRITE , 0 ,FALSE);//�ɶ�д��IO DID���ȿ���ͨ��22�����ȡ��Ҳ����ͨ��2F�������
	InitAddDID(0x9826,1 , NULL , IO_DID , IoControl_9826 , WRITEONLY , 0 , FALSE);//ֻ��ͨ��2F���Ƶ�IO DID��
	InitSetCanDriverVersionDID(0x0A01);
	InitSetCanNMVersionDID(0x0A02);
	InitSetCanDiagnosticVersionDID(0x0A03);
	InitSetCanDataBaseVersionDID(0x0A04);
	InitSetCurrentSessionDID(0xF186);

	InitSetSessionSupportAndSecurityAccess(TRUE,0x22,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO,LEVEL_ZERO);

	InitSetSessionSupportAndSecurityAccess(TRUE,0x2F,LEVEL_UNSUPPORT,LEVEL_UNSUPPORT,LEVEL_ONE,LEVEL_UNSUPPORT,LEVEL_UNSUPPORT,LEVEL_UNSUPPORT);

	InitSetSessionSupportAndSecurityAccess(TRUE,0x2E,LEVEL_UNSUPPORT,LEVEL_ONE,LEVEL_ONE,LEVEL_UNSUPPORT,LEVEL_UNSUPPORT,LEVEL_UNSUPPORT);

	//********************************** service 19*****************************************//
 	InitSetSessionSupportAndSecurityAccess(TRUE,0x19,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_ZERO);

	InitSetDTCAvailiableMask(0x09);             //  ֧�ֵĹ���״̬����
	InitAddDTC(0x910223,NMGetLimpHome,10, 1 ,LEVEL_C);			//limphome
	//********************************** service 14*****************************************//

	InitSetSessionSupportAndSecurityAccess(TRUE,0x14,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_ZERO,LEVEL_ZERO,LEVEL_UNSUPPORT,LEVEL_ZERO);
	InitAddDTCGroup(0x00FFFFFF);

	//**********************************snaptshot*****************************************//
	InitAddDTCSnapShot(0x01 , 0x9102 , &CurrentSpeed , 2);
	InitAddDTCSnapShot(0x01 , 0x9103 , &CurrentVoltage , 1);
	InitAddDTCSnapShot(0x02 , 0x9105 , &CurrentVoltage , 3);
	InitAddDTCSnapShot(0x04 , 0x9106 , &CurrentVoltage , 1);
	InitAddDTCSnapShot(0x04 , 0x9108 , &CurrentVoltage , 1);

	InitSetAgingCounterRecordNumber(3);
	InitSetAgedCounterRecordNumber(4);
	InitSetOccurrenceCounterRecordNumber(1);
	InitSetPendingCounterRecordNumber(2);

	Diagnostic_LoadAllData();

	Diagnostic_SetNLParam(70, 150, 150, 70, 70, 70, 8, 20, 0xFF);
}
