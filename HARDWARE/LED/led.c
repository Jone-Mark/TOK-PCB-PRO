#include "led.h"
/*
 * ��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��
 * LED IO��ʼ��
 */
void LED_Init( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE );  /* ʹ��PB,PE�˿�ʱ�� */

	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP;         /* ������� */
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz;         /* IO���ٶ�Ϊ50MHz */

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                 /* NET_LED-->PB.3�˿�����, ������� */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;                 /* LED0-->PB.7�˿�����, ������� */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;                 /* LED1-->PB.4�˿�����, ������� */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                 /* LED2-->PB.5 �˿�����, ������� */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;                  /* ESP RESET */
	GPIO_Init( GPIOA, &GPIO_InitStructure );                   /* ������� ��IO���ٶ�Ϊ50MHz */
}


