#ifndef __UDB_H_
#define __UDB_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "startup_main.h"

#define UDB_BOOL_NUM 	0
#define UDB_INT8_NUM 	0
#define UDB_INT16_NUM 	0
#define UDB_INT32_NUM 	0
#define UDB_FP32_NUM 	0
#define UDB_TOTAL_SIZE  (((UDB_BOOL_NUM + 7) / 8) + \
                        (UDB_INT8_NUM * 1) + \
                        (UDB_INT16_NUM * 2) + \
                        (UDB_INT32_NUM * 4) + \
                        (UDB_FP32_NUM * 4))

class UDB
{
	public:
	class RX
	{
		public:
		class DATA
		{
			public:
			uint8_t buffer[UDB_TOTAL_SIZE + 3];
		}data;

		bool Data_Analysis(uint8_t *msg_data,int16_t bool_num = UDB_BOOL_NUM,int16_t int8_num = UDB_INT8_NUM,int16_t int16_num = UDB_INT16_NUM,int16_t int32_num = UDB_INT32_NUM,int16_t fp32_num = UDB_FP32_NUM,int16_t total_size = UDB_TOTAL_SIZE);

	}rx;

	class CHECKSUM
	{
		public:
		uint8_t __SUMCRC(uint8_t *puchMsg, uint16_t usDataLen);
	}checksum;

	class CONVERT
	{
		public:
		int16_t Bytes2Short(uint8_t DH,uint8_t DL);
	}convert;

}udb;


typedef struct
{
	int16_t ch[2];
}Udp_rc_t;


#ifdef __cplusplus
}
#endif
	
#endif
