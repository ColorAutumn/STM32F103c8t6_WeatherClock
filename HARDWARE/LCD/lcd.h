#ifndef __LCD_H
#define __LCD_H
#include "sys.h"
#include "stdlib.h"

#define USE_HORIZONTAL 0 // ���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����

#if USE_HORIZONTAL == 0 || USE_HORIZONTAL == 1
#define LCD_W 240
#define LCD_H 240

#else
#define LCD_W 240
#define LCD_H 240
#endif

#define u8 unsigned char
#define u16 unsigned int
#define u32 unsigned long

//-----------------OLED�˿ڶ���----------------
#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOA, GPIO_Pin_5) // CLK
#define OLED_SCLK_Set() GPIO_SetBits(GPIOA, GPIO_Pin_5)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOA, GPIO_Pin_7) // DIN
#define OLED_SDIN_Set() GPIO_SetBits(GPIOA, GPIO_Pin_7)

#define OLED_RST_Clr() GPIO_ResetBits(GPIOB, GPIO_Pin_0) // RES
#define OLED_RST_Set() GPIO_SetBits(GPIOB, GPIO_Pin_0)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOB, GPIO_Pin_1) // DC
#define OLED_DC_Set() GPIO_SetBits(GPIOB, GPIO_Pin_1)

#define OLED_BLK_Clr() GPIO_ResetBits(GPIOA, GPIO_Pin_4) // BLK
#define OLED_BLK_Set() GPIO_SetBits(GPIOA, GPIO_Pin_4)

#define OLED_CMD 0  // д����
#define OLED_DATA 1 // д����

extern u16 BACK_COLOR; // ����ɫ

void LCD_Writ_Bus(u8 dat);
void LCD_WR_DATA8(u8 dat);
void LCD_WR_DATA(u16 dat);
void LCD_WR_REG(u8 dat);
void LCD_Address_Set(u16 x1, u16 y1, u16 x2, u16 y2);
void Lcd_Init(void);
void LCD_Clear(u16 Color);
void LCD_ShowChinese(u16 x, u16 y, u8 index, u8 size, u16 color);
void LCD_DrawPoint(u16 x, u16 y, u16 color);
void LCD_DrawPoint_big(u16 x, u16 y, u16 colory);
void LCD_Fill(u16 xsta, u16 ysta, u16 xend, u16 yend, u16 color);
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);
void Draw_Circle(u16 x0, u16 y0, u8 r, u16 color);
void LCD_ShowChar(u16 x, u16 y, u8 num, u8 mode, u16 color);
void LCD_ShowString(u16 x, u16 y, const u8 *p, u16 color);
u32 mypow(u8 m, u8 n);
void LCD_ShowNum(u16 x, u16 y, u16 num, u8 len, u16 color);
void LCD_ShowNum1(u16 x, u16 y, float num, u8 len, u16 color);
void LCD_ShowPicture(u16 x, u16 y, u16 width, u16 height, const unsigned char *image);
void LCD_ShowChineses(u16 x, u16 y, u8 index, u16 size, u16 color);

// ������ɫ
#define WHITE 0xFFFF
#define BLACK 0x0000
#define BLUE 0x001F
#define BRED 0XF81F
#define GRED 0XFFE0
#define GBLUE 0X07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define GREEN 0x07E0
#define CYAN 0x7FFF
#define YELLOW 0xFFE0
#define BROWN 0XBC40 // ��ɫ
#define BRRED 0XFC07 // �غ�ɫ
#define GRAY 0X8430  // ��ɫ
// GUI��ɫ

#define DARKBLUE 0X01CF  // ����ɫ
#define LIGHTBLUE 0X7D7C // ǳ��ɫ
#define GRAYBLUE 0X5458  // ����ɫ
// ������ɫΪPANEL����ɫ

#define LIGHTGREEN 0X841F // ǳ��ɫ
#define LGRAY 0XC618      // ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE 0XA651 // ǳ����ɫ(�м����ɫ)
#define LBBLUE 0X2B12    // ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

#endif
