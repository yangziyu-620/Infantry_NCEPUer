#ifndef _VISION2_H
#define _VISION2_H

#include <stdint.h>
#include "system.h"

#define VISION_RECV_LENGTH 10
#define VISION_SEND_LENGTH 6

//长度根据协议定义,数据段长度为n需要根据帧头第二字节来获取
#define    VISION_LEN_HEADER    1        //帧头长
#define    VISION_LEN_DATA_RECV 8       //收到的数据段长度
#define    VISION_LEN_DATA_SEND 4  // 发送的数据段长度
#define    VISION_LEN_TAIL      1

//起始字节,协议固定为0xFF
#define    VISION_SOF         (0xFF)
#define    VISION_EOF         (0xFE)
// 装甲板类型
#define NO_ARMOR    (0x00)
#define SMALL_ARMOR (0x01)
#define BIG_ARMOR (0x02)
// 射击频率类型
#define DIAN_SHOOT (0x00)
#define LIAN_SHOOT (0x01)
#define TRI_SHOOT  (0x02)

typedef __packed struct {
	/* 头校验 */
	uint8_t SOF;
	
	int16_t pitch;
	int16_t yaw;
	uint16_t distance;
	uint8_t armor_type;
	uint8_t shoot_freq;  // 射频
	
	/* 尾校验 */
	uint8_t EOF;
} VisionRecvData_t;

typedef __packed struct {
	/* 头校验 */
	uint8_t SOF;
	
	int16_t pitch;
	int16_t yaw;
	
	/* 尾校验 */
	uint8_t EOF;
} VisionSendData_t;
