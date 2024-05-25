#include "esp8266.h"
#include "string.h"
#include "usart.h"
#include "usart3.h"
#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "stdlib.h"
#include "malloc.h"
#include "cJSON.h"

nt_calendar_obj nwt; // ����ṹ�����

const u8 *wifista_ssid = "7654321";		  // ·����SSID��
const u8 *wifista_password = "123456789"; // ��������

#define WEATHER_PORTNUM "80"				 // �������Ӷ˿ں�:80
#define WEATHER_SERVERIP "api.seniverse.com" // ����������IP

#define TIME_PORTNUM "80"					 // ʱ��˿ں�
#define TIME_SERVERIP			"quan.suning.com" // ʱ�������IP

// �·����ݱ�
u8 const table_week[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}; // ���������ݱ�
// ƽ����·����ڱ�
const u8 mon_table[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

u8 *p;
Results results[] = {{0}};

/*********************************************************************************
 * Function Name    �� esp8266_start_trans,ESP8266��ʼ������
 * Parameter		   ��
 * Return Value     ��
 * Function Explain �� ����wifi
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
void esp8266_start_trans(void)
{
	u8 *p;
	p = mymalloc(SRAMIN, 50); // ����32�ֽ��ڴ棬���ڴ�wifista_ssid��wifista_password
	printf("send:AT\r\n");
	while (esp8266_send_cmd("AT", "OK", 20)) // ���WIFIģ���Ƿ�����
	{
	}
	// ���ù���ģʽ 1��stationģʽ   2��APģʽ  3������ AP+stationģʽ
	printf("send:AT+CWMODE=1\r\n");
	esp8266_send_cmd("AT+CWMODE=1", "OK", 50);
	// Wifiģ������
	printf("send:AT+RST\r\n");
	esp8266_send_cmd("AT+RST", "OK", 20);
	delay_ms(1000); // ��ʱ3S�ȴ������ɹ�
	delay_ms(1000);
	delay_ms(1000);

	// �������ӵ���WIFI��������/���ܷ�ʽ/����,�⼸��������Ҫ�������Լ���·�������ý����޸�!!
	printf("send:AT+CIPMUX=0\r\n");
	esp8266_send_cmd("AT+CIPMUX=0", "OK", 20); // 0�������ӣ�1��������

	sprintf((char *)p, "AT+CWJAP=\"%s\",\"%s\"", wifista_ssid, wifista_password); // �������߲���:ssid,����
	printf("send:AT+CWJAP=\"%s\",\"%s\"\r\n", wifista_ssid, wifista_password);

	while (esp8266_send_cmd(p, "WIFI GOT IP", 300))
		; // ����Ŀ��·����,���һ��IP
	myfree(SRAMIN, p);
}

/*********************************************************************************
 * Function Name    �� esp8266_send_cmd,��ESP8266��������
 * Parameter		   �� cmd:���͵������ַ���;ack:�ڴ���Ӧ����,���Ϊ��,���ʾ����Ҫ�ȴ�Ӧ��;waittime:�ȴ�ʱ��(��λ:10ms)
 * Return Value     �� ����ֵ:0,���ͳɹ�(�õ����ڴ���Ӧ����);1,����ʧ��
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 esp8266_send_cmd(u8 *cmd, u8 *ack, u16 waittime)
{
	u8 res = 0;
	USART3_RX_STA = 0;
	u3_printf("%s\r\n", cmd); // ��������
	if (ack && waittime)	  // ��Ҫ�ȴ�Ӧ��
	{
		while (--waittime) // �ȴ�����ʱ
		{
			delay_ms(10);
			if (USART3_RX_STA & 0X8000) // ���յ��ڴ���Ӧ����
			{
				if (esp8266_check_cmd(ack))
				{
					printf("receive:%s\r\n", (u8 *)ack);
					break; // �õ���Ч����
				}
				USART3_RX_STA = 0;
			}
		}
		if (waittime == 0)
			res = 1;
	}
	return res;
}

/*********************************************************************************
 * Function Name    �� esp8266_check_cmd,ESP8266���������,�����յ���Ӧ��
 * Parameter		   �� str:�ڴ���Ӧ����
 * Return Value     �� ����ֵ:0,û�еõ��ڴ���Ӧ����;����,�ڴ�Ӧ������λ��(str��λ��)
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 *esp8266_check_cmd(u8 *str)
{
	char *strx = 0;
	if (USART3_RX_STA & 0X8000) // ���յ�һ��������
	{
		USART3_RX_BUF[USART3_RX_STA & 0X7FFF] = 0; // ���ӽ�����
		strx = strstr((const char *)USART3_RX_BUF, (const char *)str);
	}
	return (u8 *)strx;
}

/*********************************************************************************
 * Function Name    �� esp8266_quit_trans,ATK-ESP8266�˳�͸��ģʽ
 * Parameter		   ��
 * Return Value     �� ����ֵ:0,�˳��ɹ�;1,�˳�ʧ��
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 esp8266_quit_trans(void)
{
	while ((USART3->SR & 0X40) == 0)
		; // �ȴ����Ϳ�
	USART3->DR = '+';
	delay_ms(15); // ���ڴ�����֡ʱ��(10ms)
	while ((USART3->SR & 0X40) == 0)
		; // �ȴ����Ϳ�
	USART3->DR = '+';
	delay_ms(15); // ���ڴ�����֡ʱ��(10ms)
	while ((USART3->SR & 0X40) == 0)
		; // �ȴ����Ϳ�
	USART3->DR = '+';
	delay_ms(500);							 // �ȴ�500ms
	return esp8266_send_cmd("AT", "OK", 20); // �˳�͸���ж�.
}

/*********************************************************************************
 * Function Name    �� get_current_weather,��ȡһ��ʵʱ����
 * Parameter		   ��
 * Return Value     �� ���أ�0---��ȡ�ɹ���1---��ȡʧ��
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 get_current_weather(void)
{
	u8 res;

	p = mymalloc(SRAMIN, 40); // ����40�ֽ��ڴ�

	sprintf((char *)p, "AT+CIPSTART=\"TCP\",\"%s\",%s", WEATHER_SERVERIP, WEATHER_PORTNUM); // ����Ŀ��TCP������
	printf("send:AT+CIPSTART=\"TCP\",\"%s\",%s\r\n", WEATHER_SERVERIP, WEATHER_PORTNUM);
	res = esp8266_send_cmd(p, "OK", 200); // ���ӵ�Ŀ��TCP������
	if (res == 1)
	{
		myfree(SRAMIN, p);

		return 1;
	}
	delay_ms(300);

	printf("send:AT+CIPMODE=1\r\n");
	esp8266_send_cmd("AT+CIPMODE=1", "OK", 100); // ����ģʽΪ��͸��

	USART3_RX_STA = 0;
	printf("send:AT+CIPSEND\r\n");
	esp8266_send_cmd("AT+CIPSEND", "OK", 100); // ��ʼ͸��
	printf("start trans...\r\n");

	u3_printf("GET https://api.seniverse.com/v3/weather/now.json?key=API_Key&location=shenzhen&language=en&unit=c\n\n"); // TODO API key
	delay_ms(20);	   // ��ʱ20ms���ص���ָ��ͳɹ���״̬
	USART3_RX_STA = 0; // ���㴮��3����
	delay_ms(1000);
	if (USART3_RX_STA & 0X8000) // ��ʱ�ٴνӵ�һ�����ݣ�Ϊ����������
	{
		USART3_RX_BUF[USART3_RX_STA & 0X7FFF] = 0; // ���ӽ�����
	}
	printf("USART3_RX_BUF=%s\r\n", USART3_RX_BUF);

	cJSON_WeatherParse(USART3_RX_BUF, results); // ������������
	// ��ӡ�ṹ��������
	printf("��ӡ�ṹ�����������£� \r\n");
	printf("%s \r\n", results[0].now.text);
	printf("%s \r\n", results[0].now.temperature);

	esp8266_quit_trans(); // �˳�͸��

	printf("send:AT+CIPCLOSE\r\n");
	esp8266_send_cmd("AT+CIPCLOSE", "OK", 50); // �ر�����
	return 0;
}

/*********************************************************************************
 * Function Name    �� cJSON_WeatherParse,������������
 * Parameter		   �� JSON���������ݰ�  results�����������õ������õ�����
 * Return Value     �� 0���ɹ� ����:����
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
int cJSON_WeatherParse(char *JSON, Results *results)
{
	cJSON *json, *arrayItem, *object, *subobject, *item;

	json = cJSON_Parse(JSON); // ����JSON���ݰ�
	if (json == NULL)		  // ���JSON���ݰ��Ƿ�����﷨�ϵĴ��󣬷���NULL��ʾ���ݰ���Ч
	{
		printf("Error before: [%s] \r\n", cJSON_GetErrorPtr()); // ��ӡ���ݰ��﷨�����λ��
		return 1;
	}
	else
	{
		if ((arrayItem = cJSON_GetObjectItem(json, "results")) != NULL)
			; // ƥ���ַ���"results",��ȡ��������
		{
			int size = cJSON_GetArraySize(arrayItem); // ��ȡ�����ж������
			printf("cJSON_GetArraySize: size=%d \r\n", size);

			if ((object = cJSON_GetArrayItem(arrayItem, 0)) != NULL) // ��ȡ����������
			{
				/* ƥ���Ӷ���1 */
				if ((subobject = cJSON_GetObjectItem(object, "location")) != NULL)
				{
					printf("---------------------------------subobject1-------------------------------\r\n");
					if ((item = cJSON_GetObjectItem(subobject, "id")) != NULL) // ƥ���Ӷ���1��Ա"id"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].location.id, item->valuestring, strlen(item->valuestring));
					}
					if ((item = cJSON_GetObjectItem(subobject, "name")) != NULL) // ƥ���Ӷ���1��Ա"name"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].location.name, item->valuestring, strlen(item->valuestring));
					}
					if ((item = cJSON_GetObjectItem(subobject, "country")) != NULL) // ƥ���Ӷ���1��Ա"country"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].location.country, item->valuestring, strlen(item->valuestring));
					}
					if ((item = cJSON_GetObjectItem(subobject, "path")) != NULL) // ƥ���Ӷ���1��Ա"path"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].location.path, item->valuestring, strlen(item->valuestring));
					}
					if ((item = cJSON_GetObjectItem(subobject, "timezone")) != NULL) // ƥ���Ӷ���1��Ա"timezone"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].location.timezone, item->valuestring, strlen(item->valuestring));
					}
					if ((item = cJSON_GetObjectItem(subobject, "timezone_offset")) != NULL) // ƥ���Ӷ���1��Ա"timezone_offset"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].location.timezone_offset, item->valuestring, strlen(item->valuestring));
					}
				}
				/* ƥ���Ӷ���2 */
				if ((subobject = cJSON_GetObjectItem(object, "now")) != NULL)
				{
					printf("---------------------------------subobject2-------------------------------\r\n");
					if ((item = cJSON_GetObjectItem(subobject, "text")) != NULL) // ƥ���Ӷ���2��Ա"text"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].now.text, item->valuestring, strlen(item->valuestring));
					}
					if ((item = cJSON_GetObjectItem(subobject, "code")) != NULL) // ƥ���Ӷ���2��Ա"code"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].now.code, item->valuestring, strlen(item->valuestring));
					}
					if ((item = cJSON_GetObjectItem(subobject, "temperature")) != NULL) // ƥ���Ӷ���2��Ա"temperature"
					{
						printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", item->type, item->string, item->valuestring);
						memcpy(results[0].now.temperature, item->valuestring, strlen(item->valuestring));
					}
				}
				/* ƥ���Ӷ���3 */
				if ((subobject = cJSON_GetObjectItem(object, "last_update")) != NULL)
				{
					printf("---------------------------------subobject3-------------------------------\r\n");
					printf("cJSON_GetObjectItem: type=%d, string is %s,valuestring=%s \r\n", subobject->type, subobject->string, subobject->valuestring);
					memcpy(results[0].last_update, item->valuestring, strlen(subobject->valuestring));
				}
			}
		}
	}

	cJSON_Delete(json); // �ͷ�cJSON_Parse()����������ڴ�ռ�

	return 0;
}

/*********************************************************************************
 * Function Name    �� get_beijing_time,��ȡʱ��
 * Parameter		   ��
 * Return Value     �� ���أ�0---��ȡ�ɹ���1---��ȡʧ��
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
void get_beijing_time(void)
{

	//	u8 p[100];
	//	u8 p_end[100];
	//	u8 resp[100];

	u8 *p;
	u8 res;

	u8 *resp;
	u8 *p_end;
	u8 ipbuf[16];			  // IP����
	p = mymalloc(SRAMIN, 40); // ����40�ֽ��ڴ�
	resp = mymalloc(SRAMIN, 10);
	p_end = mymalloc(SRAMIN, 40);

	sprintf((char *)p, "AT+CIPSTART=\"TCP\",\"%s\",%s", TIME_SERVERIP, TIME_PORTNUM); // ����Ŀ��TCP������
	printf("%s", p);
	res = esp8266_send_cmd(p, "OK", 200); // ���ӵ�Ŀ��TCP������
	if (res == 1)
	{
		myfree(SRAMIN, p);
	}
	delay_ms(300);
	esp8266_send_cmd("AT+CIPMODE=1", "OK", 100); // ����ģʽΪ��͸��
	//	atk_8266_get_wanip(ipbuf);//��ȡWAN IP
	////
	//	sprintf((char*)p,"IP��ַ:%s �˿�:%s",ipbuf,(u8*)TIME_PORTNUM);
	//
	//	//Show_Str(30,65,200,12,p,12,0);				//��ʾIP��ַ�Ͷ˿�
	//	 printf("�豸 %s\r\n",p);
	//
	//	USART3_RX_STA=0;
	esp8266_send_cmd("AT+CIPSEND", "OK", 100); // ��ʼ͸��
	printf("start trans...\r\n");

//	u3_printf("GET /time15.asp HTTP/1.1Host:www.beijing-time.org\n\n");
	u3_printf("GET http://quan.suning.com/getSysTime.do\n\n");
	delay_ms(1500);
	u3_printf("+++\n\n");

	delay_ms(20);	   // ��ʱ20ms���ص���ָ��ͳɹ���״̬
	USART3_RX_STA = 0; // ���㴮��3����
	delay_ms(1000);
	if (USART3_RX_STA & 0X8000) // ��ʱ�ٴνӵ�һ�����ݣ�Ϊ����������
	{
		USART3_RX_BUF[USART3_RX_STA & 0X7FFF] = 0; // ���ӽ�����
	}

	printf("USART3_RX_BUF=%s\r\n", USART3_RX_BUF);
	// USART3_RX_BUF Ϊʱ����Ϣ
	if (USART3_RX_STA & 0x8000)
	{
		printf("test my log");
		resp = "Date";

		USART3_RX_BUF[USART3_RX_STA & 0x7ff] = 0;
		printf("get_tim_srt��%s\r\n", USART3_RX_BUF);
		if (strstr((char *)USART3_RX_BUF, (char *)resp))
		{
			resp = "GMT";
			p_end = (u8 *)strstr((char *)USART3_RX_BUF, (char *)resp);
			p = p_end - 9;

			printf("get_net_str %s\r\n", p);
			nwt.hour = ((*p - 0x30) * 10 + (*(p + 1) - 0x30) + 8) % 24; // GMT0-->GMT8

			nwt.min = ((*(p + 3) - 0x30) * 10 + (*(p + 4) - 0x30)) % 60;

			nwt.sec = ((*(p + 6) - 0x30) * 10 + (*(p + 7) - 0x30)) % 60;

			nwt.year = ((*(p - 5) - 0x30) * 1000 + (*(p - 4) - 0x30) * 100 + (*(p - 3) - 0x30) * 10 + (*(p - 2) - 0x30));

			nwt.date = ((*(p - 12) - 0x30) * 10 + (*(p - 11) - 0x30));

			if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Jan"))
				nwt.month = 1;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Feb"))
				nwt.month = 2;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Mar"))
				nwt.month = 3;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Apr"))
				nwt.month = 4;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"May"))
				nwt.month = 5;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Jun"))
				nwt.month = 6;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Jul"))
				nwt.month = 7;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Aug"))
				nwt.month = 8;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Sep"))
				nwt.month = 9;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Oct"))
				nwt.month = 10;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Nov"))
				nwt.month = 11;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Dec"))
				nwt.month = 12;

			printf("nwt.year = %d\r\n", nwt.year);
			printf("nwt.month = %d\r\n", nwt.month);
			printf("nwt.date = %d\r\n", nwt.date); // ��ȡdata 28��

			printf("nwt.hour = %d\r\n", nwt.hour);
			printf("nwt.min = %d\r\n", nwt.min);
			printf("nwt.sec = %d\r\n", nwt.sec);

			USART3_RX_STA = 0;

			printf("uddate:nettime!!!");
			//				RTC_Set(nwt.year,nwt.month ,nwt.date ,nwt.hour ,nwt.min,nwt.sec);
		}
		USART3_RX_STA = 0;
		myfree(SRAMIN, resp);
		myfree(SRAMIN, p_end);
	}
	printf("\r\n\r\n");

	esp8266_quit_trans(); // �˳�͸��

	esp8266_send_cmd("AT+CIPCLOSE", "OK", 50); // �ر�����
	myfree(SRAMIN, p);
	printf("zzzzzzzzzzesp");
}
void get_beijing_time_another(void)
{

	//	u8 p[100];
	//	u8 p_end[100];
	//	u8 resp[100];

	u8 *p;
	u8 res;

	u8 *resp;
	u8 *p_end;
	u8 ipbuf[16];			  // IP����
	p = mymalloc(SRAMIN, 40); // ����40�ֽ��ڴ�
	resp = mymalloc(SRAMIN, 10);
	p_end = mymalloc(SRAMIN, 40);

	sprintf((char *)p, "AT+CIPSTART=\"TCP\",\"%s\",%s", TIME_SERVERIP, TIME_PORTNUM); // ����Ŀ��TCP������
	printf("%s", p);
	res = esp8266_send_cmd(p, "OK", 200); // ���ӵ�Ŀ��TCP������
	if (res == 1)
	{
		myfree(SRAMIN, p);
	}
	delay_ms(300);
	esp8266_send_cmd("AT+CIPMODE=1", "OK", 100); // ����ģʽΪ��͸��
	USART3_RX_STA = 0;
	esp8266_send_cmd("AT+CIPSEND", "OK", 100); // ��ʼ͸��
	printf("start trans...\r\n");

	//	u3_printf("GET /time15.asp HTTP/1.1Host:www.beijing-time.org\n\n");
	u3_printf("GET http://quan.suning.com/getSysTime.do\n\n");
	delay_ms(1500);
	u3_printf("+++\n\n");

	delay_ms(20);	   // ��ʱ20ms���ص���ָ��ͳɹ���״̬
	USART3_RX_STA = 0; // ���㴮��3����
	delay_ms(1000);
	if (USART3_RX_STA & 0X8000) // ��ʱ�ٴνӵ�һ�����ݣ�Ϊ����������
	{
		USART3_RX_BUF[USART3_RX_STA & 0X7FFF] = 0; // ���ӽ�����
	}

	printf("USART3_RX_BUF=%s\r\n", USART3_RX_BUF);
	// USART3_RX_BUF Ϊʱ����Ϣ
	if (USART3_RX_STA & 0x8000)
	{
		resp = "Date";
		//			strcpy(resp,"Date");
		USART3_RX_BUF[USART3_RX_STA & 0x7ff] = 0;
		printf("get_tim_srt��%s\r\n", USART3_RX_BUF);
		if (strstr((char *)USART3_RX_BUF, (char *)resp))
		{
			resp = "GMT";
			p_end = (u8 *)strstr((char *)USART3_RX_BUF, (char *)resp);
			p = p_end - 9;
			printf("get_net_str %s\r\n", p);
			nwt.hour = ((*p - 0x30) * 10 + (*(p + 1) - 0x30) + 8) % 24; // GMT0-->GMT8

			nwt.min = ((*(p + 3) - 0x30) * 10 + (*(p + 4) - 0x30)) % 60;

			nwt.sec = ((*(p + 6) - 0x30) * 10 + (*(p + 7) - 0x30)) % 60;

			nwt.year = ((*(p - 5) - 0x30) * 1000 + (*(p - 4) - 0x30) * 100 + (*(p - 3) - 0x30) * 10 + (*(p - 2) - 0x30));

			nwt.date = ((*(p - 12) - 0x30) * 10 + (*(p - 11) - 0x30));

			if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Jan"))
				nwt.month = 1;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Feb"))
				nwt.month = 2;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Mar"))
				nwt.month = 3;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Apr"))
				nwt.month = 4;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"May"))
				nwt.month = 5;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Jun"))
				nwt.month = 6;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Jul"))
				nwt.month = 7;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Aug"))
				nwt.month = 8;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Sep"))
				nwt.month = 9;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Oct"))
				nwt.month = 10;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Nov"))
				nwt.month = 11;
			else if ((u8 *)strstr((char *)USART3_RX_BUF, (char *)"Dec"))
				nwt.month = 12;

			printf("nwt.year = %d\r\n", nwt.year);
			printf("nwt.month = %d\r\n", nwt.month);
			printf("nwt.date = %d\r\n", nwt.date); // ��ȡdata 28��

			printf("nwt.hour = %d\r\n", nwt.hour);
			printf("nwt.min = %d\r\n", nwt.min);
			printf("nwt.sec = %d\r\n", nwt.sec);

			USART3_RX_STA = 0;

			printf("uddate:nettime!!!");
			//				RTC_Set(nwt.year,nwt.month ,nwt.date ,nwt.hour ,nwt.min,nwt.sec);
		}
		USART3_RX_STA = 0;
		myfree(SRAMIN, resp);
		myfree(SRAMIN, p_end);
	}
	printf("\r\n\r\n");

	esp8266_quit_trans(); // �˳�͸��

	esp8266_send_cmd("AT+CIPCLOSE", "OK", 50); // �ر�����
	myfree(SRAMIN, p);
	printf("zzzzzzzzzzesp");
}
/*********************************************************************************
 * Function Name    �� atk_8266_get_wanip,��ȡClient ip��ַ��������δʹ��
 * Parameter		   �� ipbuf:ip��ַ���������
 * Return Value     ��
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
void atk_8266_get_wanip(u8 *ipbuf)
{
	u8 *p, *p1;
	if (esp8266_send_cmd("AT+CIFSR", "OK", 50)) // ��ȡWAN IP��ַʧ��
	{
		ipbuf[0] = 0;
		return;
	}
	p = atk_8266_check_cmd("\"");
	p1 = (u8 *)strstr((const char *)(p + 1), "\"");
	*p1 = 0;
	sprintf((char *)ipbuf, "%s", p + 1);
}

/*********************************************************************************
 * Function Name    �� RTC_Set,RTC���ã�������δʹ��
 * Parameter		   �� syear,smon,sday,hour,min,sec
 * Return Value     ��
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 RTC_Set(u16 syear, u8 smon, u8 sday, u8 hour, u8 min, u8 sec)
{
	u16 t;
	u32 seccount = 0;
	if (syear < 1970 || syear > 2099)
		return 1;
	for (t = 1970; t < syear; t++) // ��������ݵ��������
	{
		if (Is_Leap_Year(t))
			seccount += 31622400; // �����������
		else
			seccount += 31536000; // ƽ���������
	}
	smon -= 1;
	for (t = 0; t < smon; t++) // ��ǰ���·ݵ����������
	{
		seccount += (u32)mon_table[t] * 86400; // �·����������
		if (Is_Leap_Year(syear) && t == 1)
			seccount += 86400; // ����2�·�����һ���������
	}
	seccount += (u32)(sday - 1) * 86400; // ��ǰ�����ڵ����������
	seccount += (u32)hour * 3600;		 // Сʱ������
	seccount += (u32)min * 60;			 // ����������
	seccount += sec;					 // �������Ӽ���ȥ

	//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);	//ʹ��PWR��BKP����ʱ��
	//	PWR_BackupAccessCmd(ENABLE);	//ʹ��RTC�ͺ󱸼Ĵ�������
	//	RTC_SetCounter(seccount);	//����RTC��������ֵ

	//	RTC_WaitForLastTask();	//�ȴ����һ�ζ�RTC�Ĵ�����д�������
	return 0;
}

/*********************************************************************************
 * Function Name    �� atk_8266_check_cmd,ATK-ESP8266���������,�����յ���Ӧ��
 * Parameter		   �� str:�ڴ���Ӧ����
 * Return Value     �� ����ֵ:0,û�еõ��ڴ���Ӧ����������,�ڴ�Ӧ������λ��(str��λ��)
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 *atk_8266_check_cmd(u8 *str)
{

	char *strx = 0;
	if (USART3_RX_STA & 0X8000) // ���յ�һ��������
	{
		USART3_RX_BUF[USART3_RX_STA & 0X7FFF] = 0; // ���ӽ�����
		strx = strstr((const char *)USART3_RX_BUF, (const char *)str);
	}
	return (u8 *)strx;
}

/*********************************************************************************
 * Function Name    �� atk_8266_send_cmd,��ATK-ESP8266��������
 * Parameter		   �� cmd:���͵������ַ�����ack:�ڴ���Ӧ����,���Ϊ��,���ʾ����Ҫ�ȴ�Ӧ��waittime:�ȴ�ʱ��(��λ:10ms)
 * Return Value     �� ����ֵ:0,���ͳɹ�(�õ����ڴ���Ӧ����)��1,����ʧ��
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 atk_8266_send_cmd(u8 *cmd, u8 *ack, u16 waittime)
{
	u8 res = 0;
	USART3_RX_STA = 0;
	u3_printf("%s\r\n", cmd); // ��������
	if (ack && waittime)	  // ��Ҫ�ȴ�Ӧ��
	{
		while (--waittime) // �ȴ�����ʱ
		{
			delay_ms(10);
			if (USART3_RX_STA & 0X8000) // ���յ��ڴ���Ӧ����
			{
				if (atk_8266_check_cmd(ack))
				{
					printf("%s ack:%s\r\n", cmd, (u8 *)ack);
					break; // �õ���Ч����
				}
				USART3_RX_STA = 0;
			}
		}
		if (waittime == 0)
			res = 1;
	}
	return res;
}

/*********************************************************************************
 * Function Name    �� Is_Leap_Year,�ж��Ƿ�����
 * Parameter		   �� year���
 * Return Value     �� 1�����꣬0����������
 * Function Explain ��
 * Create Date      �� 2021/6/5 by zzh
 **********************************************************************************/
u8 Is_Leap_Year(u16 year)
{
	if (year % 4 == 0) // �����ܱ�4����
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return 1; // �����00��β,��Ҫ�ܱ�400����
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}
