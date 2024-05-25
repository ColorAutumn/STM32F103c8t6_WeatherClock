#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "usart3.h"
#include "esp8266.h"
#include "string.h"
#include "timer.h"
#include "led.h"
#include "exti.h"
#include "oled.h"
#include "lcd.h"
#include "bmp.h"

/*
项目的主要内容：STM32配合ESP8266模块与服务器数据交互
当开发板上电后，可在串口助手上查看现象。
按下按键（PA0）后，可以再次获取当前天气并通过串口打印。

MCU     ESP8266
3.3V	   VCC
GND	     GND
PB10	   RXD
PB11	   TXD
3.3V	   IO
3.3V	   RST
--------------------------------
MCU     USB转TTL
5V			 VCC
GND			 GND
PA9			 RXD
PA10		 TXD
--------------------------------
MCU     OLED
5V			 VCC
GND			 GND
PB15		 SDA
PB13		 SCL
*/

u8 flag = 0;
char t;
extern Results results[];
extern nt_calendar_obj nwt;			   // 定义结构体变量
int year, month, date, hour, min, sec; // 时间变量

int main(void)
{

	delay_init();									// 延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 设置中断优先级分组2
	EXTIX_Init();									// 外部中断初始化
	uart_init(115200);								// 串口初始化为115200
	usart3_init(115200);							// 串口初始化为115200
	LED_Init();										// LED初始化
	//	OLED_Init();										//OLED初始化
	Lcd_Init();				   // LCD init
	TIM3_Int_Init(9999, 7199); // 10Khz的计数频率，计数到10000为1s
	BACK_COLOR = WHITE;
	LCD_Clear(BACK_COLOR);

	LCD_ShowPicture(180, 180, 238, 238, gImage_yun);

	LCD_ShowChineses(15, 10, 0, 32, BLACK);
	LCD_ShowChineses(50, 10, 1, 32, BLACK);
	LCD_ShowChineses(85, 10, 2, 32, BLACK);
	LCD_ShowChineses(120, 10, 3, 32, BLACK);
	LCD_ShowChineses(155, 10, 4, 32, BLACK);
	LCD_ShowChineses(190, 10, 5, 32, BLACK);

	esp8266_start_trans(); // esp8266进行初始化，连接wifi

	delay_ms(3000);

	get_current_weather(); // 获取天气
	delay_ms(200);
	get_beijing_time(); // 获取时间

	delay_ms(1000);
	year = nwt.year;
	month = nwt.month;
	date = nwt.date;
	hour = nwt.hour;
	min = nwt.min;
	sec = nwt.sec;

	TIM_Cmd(TIM3, ENABLE); // 使能TIMx外设

	while (1)
	{

		/*******************************************
		按键中断触发，改变LED状态以及flag的值，
		当按键按下时，flag = 1,开始更新数据。
		******************************************/
		if (flag == 1)
		{
			get_current_weather(); // 获取天气
			delay_ms(200);
			get_beijing_time(); // 获取时间
			flag = 0;

			hour = nwt.hour;
			min = nwt.min;
			sec = nwt.sec;
		}

		/*******************************************
		时间计数判断，其中秒的自加在中断3实现。
		******************************************/

		if (sec >= 60)
		{
			sec = 0;
			min++;
		}

		if (min >= 60)
		{
			min = 0;
			hour++;
		}

		if (hour >= 24)
		{
			hour = 0;
		}

		LCD_ShowChineses(15, 48, 16, 32, BLACK);
		LCD_ShowChineses(50, 48, 17, 32, BLACK);
		LCD_ShowString(90, 48, ":", BLACK);
		LCD_ShowNum(120, 48, hour, 2, BLACK);
		LCD_ShowString(145, 48, ":", BLACK);
		LCD_ShowNum(150, 48, min, 2, BLACK);
		LCD_ShowString(175, 48, ":", BLACK);
		LCD_ShowNum(180, 48, sec, 2, BLACK);
		LCD_ShowNum(120, 75, year, 4, BLACK);
		LCD_ShowString(155, 75, "/", BLACK);
		LCD_ShowNum(163, 75, month, 2, BLACK);
		LCD_ShowString(178, 75, "/", BLACK);
		LCD_ShowNum(190, 75, date, 2, BLACK);

		LCD_ShowChineses(15, 96, 2, 32, BLACK);
		LCD_ShowChineses(50, 96, 3, 32, BLACK);
		LCD_ShowString(87, 96, ":", BLACK);
		LCD_ShowString(120, 96, (u8 *)results[0].now.text, BLACK);

		LCD_ShowChineses(15, 144, 20, 32, BLACK);
		LCD_ShowChineses(50, 144, 21, 32, BLACK);
		LCD_ShowString(87, 144, ":", BLACK);
		LCD_ShowString(120, 144, (u8 *)results[0].now.temperature, BLACK);
		LCD_ShowChineses(155, 144, 22, 32, BLACK);
	}
}
