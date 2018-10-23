#include "timer.h"
#include "led.h"
#include "usart.h"
#include "usart2.h"
#include "main.h"

TIM_INFO timInfo = { 0 };

extern vu16 USART3_RX_STA;


/* ��ʱ��7�жϷ������ */
void TIM4_IRQHandler( void )
{
	if ( TIM_GetITStatus( TIM4, TIM_IT_Update ) != RESET )  /* �Ǹ����ж� */
	{
		USART2_RX_STA |= 1 << 15;                       /* ��ǽ������ */
		TIM_ClearITPendingBit( TIM4, TIM_IT_Update );   /* ���TIM7�����жϱ�־ */
		TIM_Cmd( TIM4, DISABLE );                       /* �ر�TIM7 */
	}
}

/*
 * ͨ�ö�ʱ��7�жϳ�ʼ��
 * ����ʱ��ѡ��ΪAPB1��2������APB1Ϊ42M
 * arr���Զ���װֵ��
 * psc��ʱ��Ԥ��Ƶ��
 * ��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
 * Ft=��ʱ������Ƶ��,��λ:Mhz
 * ͨ�ö�ʱ���жϳ�ʼ��
 * ����ʼ��ѡ��ΪAPB1��2������APB1Ϊ36M
 * arr���Զ���װֵ��
 * psc��ʱ��Ԥ��Ƶ��
 */
void TIM4_Int_Init( u16 arr, u16 psc )
{
	NVIC_InitTypeDef	NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM4, ENABLE );                  /* TIM7ʱ��ʹ�� */

	/* ��ʱ��TIM7��ʼ�� */
	TIM_TimeBaseStructure.TIM_Period	= arr;                          /* ��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ */
	TIM_TimeBaseStructure.TIM_Prescaler	= psc;                          /* ����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ */
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 /* ����ʱ�ӷָ�:TDTS = Tck_tim */
	TIM_TimeBaseStructure.TIM_CounterMode	= TIM_CounterMode_Up;           /* TIM���ϼ���ģʽ */
	TIM_TimeBaseInit( TIM4, &TIM_TimeBaseStructure );                       /* ����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ */

	TIM_ITConfig( TIM4, TIM_IT_Update, ENABLE );                            /* ʹ��ָ����TIM7�ж�,��������ж� */

	TIM_Cmd( TIM4, ENABLE );                                                /* ������ʱ��7 */

	NVIC_InitStructure.NVIC_IRQChannel			= TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 0;            /* ��ռ���ȼ�0 */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		= 2;            /* �����ȼ�2 */
	NVIC_InitStructure.NVIC_IRQChannelCmd			= ENABLE;       /* IRQͨ��ʹ�� */
	NVIC_Init( &NVIC_InitStructure );                                       /* ����ָ���Ĳ�����ʼ��VIC�Ĵ��� */
}


/*
 * ͨ�ö�ʱ��3�жϳ�ʼ��
 * ����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
 * arr���Զ���װֵ��
 * psc��ʱ��Ԥ��Ƶ��
 * ����ʹ�õ��Ƕ�ʱ��3!
 */
void TIM3_Int_Init( u16 arr, u16 psc )
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef	NVIC_InitStructure;

	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE );                  /* ʱ��ʹ�� */

	/* ��ʱ��TIM3��ʼ�� */
	TIM_TimeBaseStructure.TIM_Period	= arr;                          /* ��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ */
	TIM_TimeBaseStructure.TIM_Prescaler	= psc;                          /* ����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ */
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 /* ����ʱ�ӷָ�:TDTS = Tck_tim */
	TIM_TimeBaseStructure.TIM_CounterMode	= TIM_CounterMode_Up;           /* TIM���ϼ���ģʽ */
	TIM_TimeBaseInit( TIM3, &TIM_TimeBaseStructure );                       /* ����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ */

	TIM_ITConfig( TIM3, TIM_IT_Update, ENABLE );                            /* ʹ��ָ����TIM3�ж�,��������ж� */

	/* �ж����ȼ�NVIC���� */
	NVIC_InitStructure.NVIC_IRQChannel			= TIM3_IRQn;    /* TIM3�ж� */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 1;            /* ��ռ���ȼ�0�� */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		= 3;            /* �����ȼ�3�� */
	NVIC_InitStructure.NVIC_IRQChannelCmd			= ENABLE;       /* IRQͨ����ʹ�� */
	NVIC_Init( &NVIC_InitStructure );                                       /* ��ʼ��NVIC�Ĵ��� */


	TIM_Cmd( TIM3, ENABLE );                                                /* ʹ��TIMx */
}


/* ��ʱ��3�жϷ������ */

u16 flag = 0;
void TIM3_IRQHandler( void )                                                    /* TIM3�ж� */
{
	if ( TIM_GetITStatus( TIM3, TIM_IT_Update ) != RESET )                  /* ���TIM3�����жϷ������ */
	{
		if ( ++timInfo.timer3Out >= 4294967290UL )
			timInfo.timer3Out = 0;
		TIM_ClearITPendingBit( TIM3, TIM_IT_Update );                   /* ���TIMx�����жϱ�־ */
		/* LED1=!LED1; */
	}
}


