#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK��ӢSTM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PBout(7)// PB5
#define NET_LED PBout(4)// PB3

#define ESP8266_LOW  GPIO_ResetBits(GPIOA,GPIO_Pin_1); 				
#define ESP8266_HIGH  GPIO_SetBits(GPIOA,GPIO_Pin_1); 			

void LED_Init(void);//��ʼ��

		 				    
#endif
