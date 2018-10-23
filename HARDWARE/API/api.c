#include "main.h"
#include "usart2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

u8	size = 0;
u8	GET_TCP_DATA[300];

u8 DATA[] = "";
/*
 * ���ܣ��ϴ�POST���ݵ�������
 * ������ID  VALUE
 */
extern u8 DATA1[];
extern u8 DATA2[];
void POST_value(void)
{
	
	size = strlen( (char *) DATA1 );
	sprintf( (char *) GET_TCP_DATA, "POST /api HTTP/1.1\r\n"
		 "HOST:47.106.209.211:8888\r\n"
		 "Accept: */*\r\n"
		 "Content-Length: %d\r\n"
		 "Content-Type: application/x-www-form-urlencoded\r\n"
		 "\r\n"
		 "%s", size, DATA1 );
	//memset( DATA1, 0, size );
	//printf((char *)GET_TCP_DATA); */
	send_8266_cmd( GET_TCP_DATA, (u8 *) "OK", 200 ); /* ����TCP */
	memset( GET_TCP_DATA, 0, sizeof(GET_TCP_DATA) );
}


/*
 * ���ܣ���ȡ������һ����ʷ��
 * ������start��ʼʱ��   end ����ʱ��
 * ʵ�����岻������һ�㲻��
 */
void GET_value( u8 start, u8 end )
{
	sprintf( (char *) DATA, "start=%d&end=%d", start, end );
	size = strlen( (char *) DATA );

	sprintf( (char *) GET_TCP_DATA, "GET /btn HTTP/1.1\r\n"
		 "HOST:47.106.209.211:8888\r\n"
		 "\r\n"
		 "Accept: */*\r\n" );
	printf( (char *) GET_TCP_DATA );
	send_8266_cmd( GET_TCP_DATA, (u8 *) "OK", 200 ); /* ����TCP */
	printf( (char *) USART2_RX_BUF );
}


/*
 * ���ܣ��ն˻�ȡ�����
 * ��������
 */
void GET_btn( void )
{
	sprintf( (char *) GET_TCP_DATA, "GET /btn HTTP/1.1\r\n"
		 "HOST:47.106.209.211:8888\r\n"
		 "\r\n"
		 "Accept: */*\r\n" );
	/* printf((char *)GET_TCP_DATA); */
	send_8266_cmd( GET_TCP_DATA, (u8 *) "OK", 200 ); /* ����TCP */
}


/*
 * ���ܣ��ϴ�POST��ͼ���ݵ�������
 * ������LAT  long
 */
extern u8 DATA2[];
void POST_map( void )
{
	/*
	 * sprintf((char *)DATA,"long=%lf&lat=%lf",longitude,latitude);
	 * printf(DATA);
	 */
	size = strlen( (char *) DATA2 );
	sprintf( (char *) GET_TCP_DATA, "POST /map HTTP/1.1\r\n"
		 "HOST:47.106.209.211:8888\r\n"
		 "Accept: */*\r\n"
		 "Content-Length: %d\r\n"
		 "Content-Type: application/x-www-form-urlencoded\r\n"
		 "\r\n"
		 "%s", size, DATA2 );
	/* printf((char *)GET_TCP_DATA); */
	send_8266_cmd( GET_TCP_DATA, (u8 *) "OK", 200 ); /* ����TCP */
}


