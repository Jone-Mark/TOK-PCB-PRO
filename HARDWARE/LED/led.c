#include "led.h"
/*
 * 初始化PB5和PE5为输出口.并使能这两个口的时钟
 * LED IO初始化
 */
void LED_Init( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE );  /* 使能PB,PE端口时钟 */

	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP;         /* 推挽输出 */
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz;         /* IO口速度为50MHz */

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                 /* NET_LED-->PB.3端口配置, 推挽输出 */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;                 /* LED0-->PB.7端口配置, 推挽输出 */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;                 /* LED1-->PB.4端口配置, 推挽输出 */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                 /* LED2-->PB.5 端口配置, 推挽输出 */
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;                  /* ESP RESET */
	GPIO_Init( GPIOA, &GPIO_InitStructure );                   /* 推挽输出 ，IO口速度为50MHz */
}


