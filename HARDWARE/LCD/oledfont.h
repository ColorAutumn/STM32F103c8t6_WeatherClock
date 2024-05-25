#ifndef __OLEDFONT_H
#define __OLEDFONT_H
//常用ASCII表
//偏移量32
//ASCII字符集
//偏移量32
//大小:12*6
#define	u8 unsigned char
#define	u16 unsigned int
#define	u32 unsigned long
/************************************6*8的点阵************************************/


/****************************************32*32的点阵************************************/
 u8 Hzk32[] =
{
    
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0xFF,0x0F,0x30,0x00,0x00,0x0C,
0xB0,0xF0,0xC0,0x0C,0x30,0x31,0x63,0x0C,0x30,0x1E,0x34,0x0C,0x30,0x0C,0x18,0x0C,
0x30,0x36,0x68,0x0C,0x30,0x62,0xC4,0x0C,0xB0,0x21,0xC3,0x0D,0x70,0x80,0x00,0x0C,
0x30,0x00,0x00,0x0C,0x30,0x00,0x80,0x0C,0x30,0x00,0x00,0x07,0x00,0x00,0x00,0x00,/*"网",0*/
0x00,0x00,0x00,0x00,0x80,0x01,0x06,0x00,0xC0,0x00,0x03,0x00,0x60,0x80,0xFF,0x07,
0x10,0x8C,0x02,0x03,0xC8,0x66,0x84,0x01,0x38,0x11,0x78,0x00,0xC0,0x00,0x78,0x00,
0x20,0x00,0x87,0x03,0xFC,0xE7,0x00,0x3E,0x00,0x9C,0xFF,0x03,0x00,0x80,0x01,0x02,
0xE0,0x87,0x01,0x02,0x1C,0x80,0xFF,0x03,0x00,0x80,0x01,0x02,0x00,0x00,0x00,0x00,/*"络",1*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE0,0xFF,0xFF,0x07,0x00,0xC0,0x00,0x00,
0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x0C,0xF8,0xFF,0xFF,0x13,
0x00,0x60,0x02,0x00,0x00,0x60,0x04,0x00,0x00,0x30,0x08,0x00,0x00,0x18,0x30,0x00,
0x00,0x06,0xE0,0x00,0x80,0x01,0x80,0x07,0x70,0x00,0x00,0x3E,0x0C,0x00,0x00,0x00,/*"天",2*/
0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x03,0x00,0x00,0x80,0xFF,0xFF,0x0F,
0xC0,0x00,0x00,0x00,0x20,0xFF,0xFF,0x01,0x18,0x00,0x00,0x00,0xE4,0xFF,0xFF,0x00,
0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0xC0,0x00,
0x00,0x00,0xC0,0x10,0x00,0x00,0x80,0x11,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,/*"气",3*/
0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0xC0,0x00,0xF8,0x0F,0xC0,0x00,
0x18,0x0C,0xC0,0x18,0x18,0xFC,0xFF,0x07,0x18,0x0C,0xC0,0x00,0xF8,0x8F,0xC0,0x00,
0x18,0x0C,0xC3,0x00,0x18,0x0C,0xC6,0x00,0x18,0x0C,0xC0,0x00,0xF8,0x0F,0xC0,0x00,
0x18,0x0C,0xC0,0x00,0x08,0x00,0xC0,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,/*"时",4*/
0x00,0x00,0x00,0x00,0xC0,0x00,0x60,0x00,0xC0,0x00,0x60,0x00,0xE0,0x1F,0x60,0x00,
0x20,0x00,0x60,0x08,0x10,0x80,0xFF,0x0F,0xF8,0x9F,0x61,0x08,0xC4,0x80,0x61,0x08,
0xC0,0x90,0x61,0x08,0xFC,0x8F,0xFF,0x0F,0xC0,0x00,0x60,0x00,0xC0,0x30,0x60,0x00,
0xC0,0x0C,0x60,0x00,0xC0,0x03,0x60,0x00,0x80,0x00,0x60,0x00,0x00,0x00,0x00,0x00,/*"钟",5*/
0x00,0x00,0x00,0x00,0x10,0x00,0x38,0x00,0x60,0x00,0x18,0x08,0xC0,0xF0,0xFF,0x17,
0x00,0xC0,0xFF,0x07,0x00,0x00,0x18,0x00,0xFE,0xF9,0xFF,0x3F,0xC0,0x00,0x00,0x00,
0xC0,0xC0,0xFF,0x07,0xC0,0x40,0x00,0x06,0xC0,0xC8,0xFF,0x07,0xC0,0xC4,0xFF,0x07,
0xC0,0x43,0x00,0x06,0xE0,0x40,0x00,0x06,0x00,0x40,0xE0,0x03,0x00,0x00,0x00,0x00,/*"请",6*/
0x00,0x00,0x00,0x00,0xC0,0x00,0x38,0x00,0x40,0x00,0x2C,0x00,0xE8,0x1F,0xC6,0x00,
0x34,0x80,0x01,0x03,0x90,0x61,0xFF,0x7D,0x98,0x19,0x00,0x00,0xFE,0xEF,0x5F,0x18,
0x80,0x71,0x8C,0x08,0x80,0xE1,0x8F,0x08,0x80,0x7F,0x8C,0x08,0xFE,0xE1,0x8F,0x08,
0x80,0x61,0x8C,0x08,0x80,0x61,0x0C,0x08,0x80,0x61,0x8F,0x0F,0x80,0x00,0x04,0x00,/*"输",7*/
0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0xC0,0x00,0x00,
0x00,0x80,0x01,0x00,0x00,0xC0,0x03,0x00,0x00,0xC0,0x02,0x00,0x00,0x60,0x06,0x00,
0x00,0x30,0x0C,0x00,0x00,0x18,0x18,0x00,0x00,0x04,0x70,0x00,0x00,0x03,0xC0,0x00,
0xC0,0x00,0x80,0x07,0x30,0x00,0x00,0x7E,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"入",8*/
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0xF8,0x1F,0x03,0x04,0x18,0x18,0x03,0x03,
0x98,0x1B,0xC3,0x00,0x98,0x19,0x33,0x00,0x98,0x19,0x0F,0x00,0x98,0x39,0x03,0x1C,
0x98,0xD9,0xFF,0x03,0x98,0x19,0x13,0x00,0x98,0x08,0x63,0x00,0xC0,0x06,0xC3,0x00,
0x40,0x38,0xA3,0x03,0x30,0x30,0x1F,0x0E,0x08,0x00,0x07,0x18,0x04,0x00,0x00,0x00,/*"账",9*/
0x00,0x00,0x00,0x00,0x00,0xFD,0xBF,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,
0x00,0x03,0xC0,0x00,0x00,0xFF,0xFF,0x00,0x00,0x01,0x00,0x00,0xFC,0xFF,0xFF,0x3F,
0x00,0x18,0x00,0x00,0x00,0x0C,0x80,0x01,0x00,0xF4,0xFF,0x01,0x00,0x00,0xC0,0x00,
0x00,0x00,0xC0,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,/*"号",10*/
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x80,0x01,0x00,0xF0,0x7F,0xFE,0x3F,
0x18,0xC0,0x60,0x04,0x00,0xDC,0x38,0x00,0x40,0x0C,0x06,0x02,0x60,0xCC,0x21,0x0C,
0x00,0x3E,0x60,0x08,0xFC,0xF9,0x3F,0x00,0x00,0x80,0x01,0x00,0xC0,0x81,0x01,0x03,
0xC0,0x80,0x01,0x01,0xC0,0x80,0x01,0x01,0xC0,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,/*"密",11*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0x07,0xC0,0x00,0x02,0x06,
0x60,0x00,0x03,0x02,0x20,0x00,0x03,0x03,0xF0,0x0F,0x03,0x03,0x38,0x04,0x01,0x03,
0x3C,0x84,0xFF,0x3F,0x32,0x04,0x00,0x10,0x30,0x04,0x80,0x19,0x30,0xE4,0x7F,0x18,
0xF0,0x07,0x00,0x18,0x30,0x00,0x60,0x0C,0x00,0x00,0x80,0x07,0x00,0x00,0x00,0x00,/*"码",12*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0xF0,0x07,0x00,
0x00,0xF0,0x0F,0x00,0x00,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"·",13*/
0x00,0x00,0x00,0x00,0x00,0x07,0x02,0x00,0x00,0x03,0x0C,0x00,0x80,0x01,0x0C,0x00,
0xC0,0xF8,0xFF,0x1F,0xE0,0x00,0x00,0x00,0xE0,0x20,0x80,0x07,0xD8,0x40,0x80,0x01,
0xC4,0xC0,0x80,0x00,0xC2,0x80,0xC1,0x00,0xC0,0x80,0x41,0x00,0xC0,0x80,0x61,0x00,
0xC0,0x00,0x20,0x00,0xC0,0x00,0x10,0x10,0xC0,0xFC,0xEF,0x2F,0x00,0x00,0x00,0x00,/*"位",14*/
0x00,0x00,0x00,0x00,0xA0,0xCF,0xF3,0x07,0x60,0x30,0x0C,0x06,0x60,0x30,0x0C,0x06,
0xE0,0xFF,0xFF,0x07,0x00,0x80,0x01,0x06,0xF0,0xFF,0xFE,0x01,0x00,0xFD,0xFF,0x01,
0x00,0x03,0xC0,0x00,0x00,0xFF,0xFF,0x00,0x00,0x03,0xC0,0x00,0x00,0xFF,0xFF,0x00,
0x00,0xFF,0xFF,0x00,0x00,0x03,0xC0,0x00,0xFE,0xFF,0xFF,0x3F,0x00,0x00,0x00,0x00,/*"置",15*/
0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0xC0,0x00,0xF8,0x0F,0xC0,0x00,
0x18,0x0C,0xC0,0x18,0x18,0xFC,0xFF,0x07,0x18,0x0C,0xC0,0x00,0xF8,0x8F,0xC0,0x00,
0x18,0x0C,0xC3,0x00,0x18,0x0C,0xC6,0x00,0x18,0x0C,0xC0,0x00,0xF8,0x0F,0xC0,0x00,
0x18,0x0C,0xC0,0x00,0x08,0x00,0xC0,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,/*"时",16*/
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0xF3,0xFF,0x0F,0x30,0x03,0x00,0x0C,
0x30,0x00,0x00,0x0C,0x30,0xF8,0x3F,0x0C,0x30,0x18,0x18,0x0C,0x30,0x18,0x18,0x0C,
0x30,0xF8,0x1F,0x0C,0x30,0x18,0x18,0x0C,0x30,0x18,0x18,0x0C,0x30,0xF8,0x1F,0x0C,
0x30,0x08,0x00,0x0C,0x30,0x00,0x00,0x0C,0x30,0x00,0xC0,0x07,0x00,0x00,0x00,0x00,/*"间",17*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE0,0xFF,0xFF,0x07,0x00,0xC0,0x00,0x00,
0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x0C,0xF8,0xFF,0xFF,0x13,
0x00,0x60,0x02,0x00,0x00,0x60,0x04,0x00,0x00,0x30,0x08,0x00,0x00,0x18,0x30,0x00,
0x00,0x06,0xE0,0x00,0x80,0x01,0x80,0x07,0x70,0x00,0x00,0x3E,0x0C,0x00,0x00,0x00,/*"天",18*/
0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x03,0x00,0x00,0x80,0xFF,0xFF,0x0F,
0xC0,0x00,0x00,0x00,0x20,0xFF,0xFF,0x01,0x18,0x00,0x00,0x00,0xE4,0xFF,0xFF,0x00,
0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0xC0,0x00,
0x00,0x00,0xC0,0x10,0x00,0x00,0x80,0x11,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,/*"气",19*/
0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0xE0,0xF0,0xFF,0x03,0x80,0x30,0x00,0x01,
0x00,0xF2,0xFF,0x01,0x0C,0x32,0x00,0x01,0x38,0x31,0x00,0x01,0x00,0xF1,0xFF,0x01,
0x80,0x00,0x00,0x00,0xC0,0xFC,0xFF,0x0F,0x60,0x8C,0x31,0x06,0x7C,0x8C,0x31,0x06,
0x30,0x8C,0x31,0x06,0x30,0x8C,0x31,0x06,0xB0,0xFF,0xFF,0x3F,0x00,0x00,0x00,0x00,/*"温",20*/
0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x02,0x08,0xE0,0xFF,0xFD,0x17,
0x60,0x60,0xE0,0x00,0xE0,0xFF,0xFF,0x1F,0x60,0x60,0x60,0x00,0x60,0x60,0x60,0x00,
0x60,0xE0,0x7F,0x00,0x20,0xDC,0xBF,0x01,0x30,0x60,0xC0,0x00,0x30,0x80,0x30,0x00,
0x10,0x00,0x0F,0x00,0x08,0x80,0x3B,0x00,0x04,0x7E,0xC0,0x3F,0xE2,0x01,0x00,0x00,/*"度",21*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x3E,0x00,0x10,0xE1,0xC1,0x05,
0xF0,0x31,0x00,0x06,0x00,0x18,0x00,0x04,0x00,0x0C,0x00,0x04,0x00,0x0C,0x00,0x00,
0x00,0x0C,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x18,0x00,0x04,
0x00,0x70,0x80,0x03,0x00,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"℃",22*/


0x08,0x08,0x89,0xEA,0x18,0x88,0x00,0x04,0x04,0xFC,0x04,0x04,0x04,0xFC,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x01,0x00,0xFF,0x01,0x86,0x40,0x20,0x18,0x07,0x40,0x80,0x40,0x3F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"chu",23*/


0x10,0x10,0xF0,0x1F,0x10,0xF0,0x00,0x40,0xE0,0x58,0x47,0x40,0x50,0x60,0xC0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x40,0x22,0x15,0x08,0x16,0x21,0x00,0x00,0xFE,0x42,0x42,0x42,0x42,0xFE,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"shi",24*/


0x00,0x80,0x60,0xF8,0x07,0x00,0x00,0x00,0xFF,0x40,0x20,0x10,0x08,0x04,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x00,0x00,0xFF,0x00,0x04,0x02,0x01,0x3F,0x40,0x40,0x40,0x40,0x40,0x78,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"hua",25*/


0x00,0x00,0xF0,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0xF0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"zhong",26*/
/* (32 X 16 , ?? )*/

0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0x08,0x08,0xFF,0x08,0x09,0x0A,0xC8,0x08,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x60,0x1F,0x00,0x10,0x20,0x1F,0x80,0x40,0x21,0x16,0x18,0x26,0x41,0xF8,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"cheng",27*/
/* (32 X 16 , ?? )*/

0x08,0x08,0x08,0xF8,0x08,0x08,0x08,0x10,0x10,0xFF,0x10,0x10,0x10,0xF0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x10,0x30,0x10,0x1F,0x08,0x88,0x48,0x30,0x0E,0x01,0x40,0x80,0x40,0x3F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"gong",28*/
/* (32 X 16 , ?? )*/



0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0xC0,0xF3,0xE8,0x0B,0x60,0x0C,0x18,0x0C,
0x10,0x0C,0x18,0x0C,0xFC,0xFF,0x1B,0x0C,0x00,0x1E,0x18,0x0C,0x00,0xE3,0xF8,0x0F,
0xC0,0x80,0x09,0x00,0x38,0xFE,0xFF,0x03,0x00,0x06,0x80,0x01,0x00,0xFE,0xFF,0x01,
0x00,0x06,0x80,0x01,0x00,0x06,0x80,0x01,0x00,0xFE,0xFF,0x01,0x00,0x00,0x00,0x00,/*"智",23*/
0x00,0x00,0x00,0x00,0x00,0x03,0x0C,0x00,0x80,0x01,0x0C,0x00,0x60,0x20,0x8C,0x07,
0x98,0xFF,0x7C,0x00,0x78,0x80,0x0C,0x10,0xD0,0x3F,0x08,0x18,0x30,0x20,0xF0,0x07,
0xF0,0x3F,0x04,0x00,0x30,0x20,0x0C,0x0E,0x30,0x20,0xCC,0x01,0xF0,0x3F,0x3C,0x00,
0x30,0x20,0x0C,0x10,0x30,0x20,0x0C,0x10,0x30,0x3E,0xFC,0x3F,0x00,0x00,0x00,0x00,/*"能",24*/
0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0xF8,0x0F,0x30,0x00,0x18,0xE6,0xFF,0x1F,
0x18,0x23,0x00,0x04,0x18,0x01,0x00,0x01,0x98,0x80,0xFF,0x00,0x18,0x03,0x00,0x00,
0x18,0xF4,0xFF,0x0F,0x18,0x0C,0x62,0x00,0x98,0x0C,0x62,0x00,0x18,0x03,0x63,0x10,
0x18,0x80,0x61,0x10,0x18,0xE0,0x60,0x10,0x18,0x1C,0xC0,0x1F,0x08,0x02,0x00,0x00,/*"院",25*/
0x00,0x00,0x00,0x00,0x00,0x03,0x18,0x00,0x80,0x01,0x18,0x00,0x80,0x61,0x0C,0x00,
0xF8,0x1E,0xFC,0x1B,0x40,0x06,0x02,0x0C,0x60,0x06,0x71,0x02,0x30,0xC6,0x30,0x00,
0xF0,0x3F,0x70,0x00,0x00,0x06,0x58,0x00,0x00,0x7E,0xD8,0x00,0xF8,0x07,0x8C,0x00,
0x08,0x06,0x06,0x03,0x00,0x06,0x03,0x06,0x00,0xE6,0x00,0x7C,0x00,0x10,0x00,0x00,/*"软",26*/
0x00,0x00,0x00,0x00,0x00,0x06,0x30,0x00,0x00,0x43,0x30,0x00,0x80,0xC1,0x30,0x00,
0xC0,0x60,0x30,0x00,0xC0,0xE1,0xFF,0x1F,0xA0,0x30,0x30,0x00,0x98,0x08,0x30,0x00,
0x84,0x08,0x30,0x10,0x80,0xF8,0xFF,0x7F,0x80,0x00,0x30,0x00,0x80,0x00,0x30,0x00,
0x80,0x00,0x30,0x00,0x80,0x00,0x30,0x00,0x80,0x00,0x30,0x00,0x40,0x00,0x00,0x00,/*"件",27*/
0x00,0x00,0x00,0x00,0xC0,0x00,0x06,0x00,0xC0,0x00,0x06,0x00,0xC0,0x00,0x06,0x00,
0xC0,0xF0,0xFF,0x03,0xFC,0x0F,0x06,0x01,0xC0,0x00,0x06,0x01,0xC0,0x10,0x06,0x05,
0xC0,0x10,0x02,0x19,0xC0,0x18,0x03,0x31,0xC0,0x0E,0x03,0x31,0xC0,0x80,0x81,0x01,
0xC0,0xC0,0x80,0x01,0xC0,0x30,0xCC,0x00,0xC0,0x0C,0xF0,0x00,0x00,0x02,0x00,0x00,/*"协",28*/
0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0xE0,0x01,0x00,0x00,0x30,0x02,0x00,
0x00,0x18,0x1C,0x00,0x00,0x06,0x60,0x00,0x80,0x01,0xB0,0x3F,0x70,0xFE,0x4F,0x0C,
0x0C,0x00,0x00,0x00,0xF0,0x1F,0xFF,0x0F,0x00,0xE0,0x00,0x00,0x00,0x38,0x04,0x00,
0x00,0x0C,0x38,0x00,0x00,0x03,0xC0,0x01,0xC0,0xFF,0xBF,0x03,0x00,0x00,0x00,0x00,/*"会",29*/



0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0xFF,0x03,0x80,0x01,0x80,0x01,
0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0xFF,0xFF,0x01,
0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,
0x80,0x01,0x80,0x01,0x80,0xFF,0xFF,0x01,0x80,0x01,0x80,0x01,0x00,0x00,0x00,0x00,/*"日",30*/
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xFE,0xFF,0x01,0x00,0x06,0x80,0x00,
0x00,0x06,0x80,0x00,0x00,0xFE,0xFF,0x00,0x00,0x02,0x80,0x00,0x00,0x02,0x80,0x00,
0x00,0x02,0x80,0x00,0x00,0xFF,0xFF,0x00,0x00,0x03,0x80,0x00,0x00,0x03,0x80,0x00,
0x80,0x01,0x80,0x00,0x40,0x00,0x80,0x00,0x30,0x00,0xFC,0x00,0x0C,0x00,0x00,0x00,/*"月",31*/


};

const u8 asc2_1608[1520] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00,
    0x00, 0x48, 0x6C, 0x24, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x24, 0x24, 0x24, 0x7F, 0x12, 0x12, 0x12, 0x7F, 0x12, 0x12, 0x12, 0x00, 0x00,
    0x00, 0x00, 0x08, 0x1C, 0x2A, 0x2A, 0x0A, 0x0C, 0x18, 0x28, 0x28, 0x2A, 0x2A, 0x1C, 0x08, 0x08,
    0x00, 0x00, 0x00, 0x22, 0x25, 0x15, 0x15, 0x15, 0x2A, 0x58, 0x54, 0x54, 0x54, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0C, 0x12, 0x12, 0x12, 0x0A, 0x76, 0x25, 0x29, 0x11, 0x91, 0x6E, 0x00, 0x00,
    0x00, 0x06, 0x06, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x20, 0x40, 0x00,
    0x00, 0x02, 0x04, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x04, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x6B, 0x1C, 0x1C, 0x6B, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x7F, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x04, 0x03,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x24, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3C, 0x42, 0x42, 0x42, 0x20, 0x20, 0x10, 0x08, 0x04, 0x42, 0x7E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3C, 0x42, 0x42, 0x20, 0x18, 0x20, 0x40, 0x40, 0x42, 0x22, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x30, 0x28, 0x24, 0x24, 0x22, 0x22, 0x7E, 0x20, 0x20, 0x78, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7E, 0x02, 0x02, 0x02, 0x1A, 0x26, 0x40, 0x40, 0x42, 0x22, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x38, 0x24, 0x02, 0x02, 0x1A, 0x26, 0x42, 0x42, 0x42, 0x24, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7E, 0x22, 0x22, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3C, 0x42, 0x42, 0x42, 0x24, 0x18, 0x24, 0x42, 0x42, 0x42, 0x3C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x18, 0x24, 0x42, 0x42, 0x42, 0x64, 0x58, 0x40, 0x40, 0x24, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x04,
    0x00, 0x00, 0x00, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3C, 0x42, 0x42, 0x46, 0x40, 0x20, 0x10, 0x10, 0x00, 0x18, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1C, 0x22, 0x5A, 0x55, 0x55, 0x55, 0x55, 0x2D, 0x42, 0x22, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08, 0x08, 0x18, 0x14, 0x14, 0x24, 0x3C, 0x22, 0x42, 0x42, 0xE7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0x22, 0x22, 0x22, 0x1E, 0x22, 0x42, 0x42, 0x42, 0x22, 0x1F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7C, 0x42, 0x42, 0x01, 0x01, 0x01, 0x01, 0x01, 0x42, 0x22, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0x22, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x22, 0x1F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3F, 0x42, 0x12, 0x12, 0x1E, 0x12, 0x12, 0x02, 0x42, 0x42, 0x3F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3F, 0x42, 0x12, 0x12, 0x1E, 0x12, 0x12, 0x02, 0x02, 0x02, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3C, 0x22, 0x22, 0x01, 0x01, 0x01, 0x71, 0x21, 0x22, 0x22, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE7, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0xE7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x11, 0x0F,
    0x00, 0x00, 0x00, 0x77, 0x22, 0x12, 0x0A, 0x0E, 0x0A, 0x12, 0x12, 0x22, 0x22, 0x77, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x42, 0x7F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x77, 0x36, 0x36, 0x36, 0x36, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x6B, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE3, 0x46, 0x46, 0x4A, 0x4A, 0x52, 0x52, 0x52, 0x62, 0x62, 0x47, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1C, 0x22, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x22, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3F, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x02, 0x02, 0x02, 0x02, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1C, 0x22, 0x41, 0x41, 0x41, 0x41, 0x41, 0x4D, 0x53, 0x32, 0x1C, 0x60, 0x00,
    0x00, 0x00, 0x00, 0x3F, 0x42, 0x42, 0x42, 0x3E, 0x12, 0x12, 0x22, 0x22, 0x42, 0xC7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7C, 0x42, 0x42, 0x02, 0x04, 0x18, 0x20, 0x40, 0x42, 0x42, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7F, 0x49, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE7, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE7, 0x42, 0x42, 0x22, 0x24, 0x24, 0x14, 0x14, 0x18, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x6B, 0x49, 0x49, 0x49, 0x49, 0x55, 0x55, 0x36, 0x22, 0x22, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE7, 0x42, 0x24, 0x24, 0x18, 0x18, 0x18, 0x24, 0x24, 0x42, 0xE7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x77, 0x22, 0x22, 0x14, 0x14, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7E, 0x21, 0x20, 0x10, 0x10, 0x08, 0x04, 0x04, 0x42, 0x42, 0x3F, 0x00, 0x00,
    0x00, 0x78, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x78, 0x00,
    0x00, 0x00, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x20, 0x40, 0x40,
    0x00, 0x1E, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1E, 0x00,
    0x00, 0x38, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0x00, 0x06, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x42, 0x78, 0x44, 0x42, 0x42, 0xFC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x1A, 0x26, 0x42, 0x42, 0x42, 0x26, 0x1A, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x02, 0x02, 0x02, 0x44, 0x38, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x60, 0x40, 0x40, 0x40, 0x78, 0x44, 0x42, 0x42, 0x42, 0x64, 0xD8, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x42, 0x7E, 0x02, 0x02, 0x42, 0x3C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF0, 0x88, 0x08, 0x08, 0x7E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x22, 0x22, 0x1C, 0x02, 0x3C, 0x42, 0x42, 0x3C,
    0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x3A, 0x46, 0x42, 0x42, 0x42, 0x42, 0xE7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x22, 0x1E,
    0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x72, 0x12, 0x0A, 0x16, 0x12, 0x22, 0x77, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x92, 0x92, 0x92, 0x92, 0x92, 0xB7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3B, 0x46, 0x42, 0x42, 0x42, 0x42, 0xE7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x26, 0x42, 0x42, 0x42, 0x22, 0x1E, 0x02, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x44, 0x42, 0x42, 0x42, 0x44, 0x78, 0x40, 0xE0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x4C, 0x04, 0x04, 0x04, 0x04, 0x1F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x42, 0x02, 0x3C, 0x40, 0x42, 0x3E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x42, 0x42, 0x42, 0x42, 0x62, 0xDC, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE7, 0x42, 0x24, 0x24, 0x14, 0x08, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x49, 0x49, 0x55, 0x55, 0x22, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x24, 0x18, 0x18, 0x18, 0x24, 0x6E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE7, 0x42, 0x24, 0x24, 0x14, 0x18, 0x08, 0x08, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x22, 0x10, 0x08, 0x08, 0x44, 0x7E, 0x00, 0x00,
    0x00, 0xC0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xC0, 0x00,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x00, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x06, 0x00,
    0x0C, 0x32, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};




 u8 Hzk16[] =
{

    0x00, 0x00, 0xFE, 0x3F, 0x02, 0x20, 0x02, 0x20, 0x42, 0x28, 0x4A, 0x29, 0x52, 0x2A, 0x22, 0x24,
    0x22, 0x24, 0x52, 0x2A, 0x52, 0x2A, 0x4A, 0x29, 0x86, 0x20, 0x02, 0x20, 0x02, 0x28, 0x02, 0x10, /*"网",0*/

    0x08, 0x01, 0x08, 0x01, 0x04, 0x1F, 0x84, 0x10, 0xD2, 0x08, 0x3F, 0x05, 0x08, 0x02, 0x04, 0x05,
    0x82, 0x18, 0x5F, 0x60, 0xA2, 0x1F, 0x80, 0x10, 0x98, 0x10, 0x87, 0x10, 0x82, 0x1F, 0x80, 0x10, /*"络",1*/

    0x00, 0x00, 0xFC, 0x1F, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xFF, 0x7F, 0x80, 0x00,
    0x40, 0x01, 0x40, 0x01, 0x20, 0x02, 0x20, 0x02, 0x10, 0x04, 0x08, 0x08, 0x04, 0x10, 0x03, 0x60, /*"天",2*/

    0x08, 0x00, 0x08, 0x00, 0xFC, 0x3F, 0x04, 0x00, 0xF2, 0x0F, 0x01, 0x00, 0xFC, 0x0F, 0x00, 0x08,
    0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x50, 0x00, 0x50, 0x00, 0x60, 0x00, 0x40, /*"气",3*/

    0x00, 0x10, 0x00, 0x10, 0x3E, 0x10, 0x22, 0x10, 0xA2, 0x7F, 0x22, 0x10, 0x22, 0x10, 0x3E, 0x10,
    0x22, 0x11, 0x22, 0x12, 0x22, 0x12, 0x22, 0x10, 0x3E, 0x10, 0x22, 0x10, 0x00, 0x14, 0x00, 0x08, /*"时",4*/

    0x08, 0x04, 0x08, 0x04, 0x3C, 0x04, 0x04, 0x04, 0x82, 0x3F, 0xBD, 0x24, 0x88, 0x24, 0x88, 0x24,
    0xBF, 0x24, 0x88, 0x3F, 0x88, 0x24, 0x08, 0x04, 0x28, 0x04, 0x18, 0x04, 0x08, 0x04, 0x00, 0x04, /*"钟",5*/

    0x00, 0x04, 0x00, 0x04, 0xDE, 0x7F, 0x12, 0x04, 0x92, 0x3F, 0x12, 0x04, 0xD2, 0x7F, 0x1E, 0x00,
    0x92, 0x3F, 0x92, 0x20, 0x92, 0x3F, 0x92, 0x20, 0x9E, 0x3F, 0x92, 0x20, 0x80, 0x28, 0x80, 0x10, /*"晴",6*/

    0x00, 0x00, 0xF8, 0x1F, 0x08, 0x10, 0x08, 0x10, 0x08, 0x10, 0xF8, 0x1F, 0x08, 0x10, 0x08, 0x10,
    0x08, 0x10, 0xF8, 0x1F, 0x08, 0x10, 0x08, 0x10, 0x04, 0x10, 0x04, 0x10, 0x02, 0x14, 0x01, 0x08, /*"月",7*/

    0x00, 0x00, 0xF8, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xF8, 0x0F,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xF8, 0x0F, 0x08, 0x08, /*"日",8*/

    0x00, 0x00, 0xC4, 0x1F, 0x48, 0x10, 0x48, 0x10, 0xC1, 0x1F, 0x42, 0x10, 0x42, 0x10, 0xC8, 0x1F,
    0x08, 0x00, 0xE4, 0x3F, 0x27, 0x25, 0x24, 0x25, 0x24, 0x25, 0x24, 0x25, 0xF4, 0x7F, 0x00, 0x00, /*"温",9*/

    0x80, 0x00, 0x00, 0x01, 0xFC, 0x7F, 0x44, 0x04, 0x44, 0x04, 0xFC, 0x3F, 0x44, 0x04, 0x44, 0x04,
    0xC4, 0x07, 0x04, 0x00, 0xF4, 0x0F, 0x24, 0x08, 0x42, 0x04, 0x82, 0x03, 0x61, 0x0C, 0x1C, 0x70, /*"度",10*/

    0x06, 0x00, 0x89, 0x2F, 0x69, 0x30, 0x36, 0x20, 0x10, 0x20, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00,
    0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x10, 0x00, 0x30, 0x20, 0x60, 0x10, 0x80, 0x0F, 0x00, 0x00, /*"℃",11*/

		
    0x10,0x01,0x10,0x02,0x10,0x02,0x08,0x00,0xE8,0x3F,0x0C,0x00,0x0C,0x10,0x4A,0x10,
    0x49,0x10,0x88,0x08,0x88,0x08,0x88,0x08,0x88,0x04,0x08,0x04,0xF8,0x7F,0x08,0x00,/*"位",12*/
    
		0xFE,0x3F,0x22,0x22,0xFE,0x3F,0x80,0x00,0xFE,0x3F,0x80,0x00,0xF8,0x0F,0x08,0x08,
    0xF8,0x0F,0x08,0x08,0xF8,0x0F,0x08,0x08,0xF8,0x0F,0x08,0x08,0xFF,0x7F,0x00,0x00,/*"置",13*/

		0x00,0x10,0x00,0x10,0x3E,0x10,0x22,0x10,0xA2,0x7F,0x22,0x10,0x22,0x10,0x3E,0x10,
    0x22,0x11,0x22,0x12,0x22,0x12,0x22,0x10,0x3E,0x10,0x22,0x10,0x00,0x14,0x00,0x08,/*"时",14*/

    0x04,0x00,0xC8,0x3F,0x08,0x20,0x02,0x20,0xE2,0x23,0x22,0x22,0x22,0x22,0x22,0x22,
    0xE2,0x23,0x22,0x22,0x22,0x22,0x22,0x22,0xE2,0x23,0x02,0x20,0x02,0x28,0x02,0x10,/*"间",15*/

		0x04,0x00,0x7C,0x3E,0x12,0x22,0x10,0x22,0xFF,0x22,0x28,0x22,0x44,0x3E,0x02,0x00,
		0xF8,0x0F,0x08,0x08,0x08,0x08,0xF8,0x0F,0x08,0x08,0x08,0x08,0xF8,0x0F,0x08,0x08,/*"智",16*/


0x08,0x02,0x24,0x22,0x42,0x12,0xFF,0x0E,0x80,0x02,0x00,0x42,0x7E,0x42,0x42,0x7C,
0x42,0x00,0x7E,0x22,0x42,0x12,0x42,0x0E,0x7E,0x02,0x42,0x42,0x52,0x42,0x22,0x7C,/*"能",17*/


0x00,0x02,0x1E,0x04,0xD2,0x7F,0x4A,0x40,0x2A,0x20,0x86,0x1F,0x0A,0x00,0x12,0x00,
0xD2,0x7F,0x12,0x09,0x16,0x09,0x0A,0x09,0x82,0x48,0x82,0x48,0x42,0x70,0x22,0x00,/*"院",18*/


0x08,0x02,0x08,0x02,0x08,0x02,0x7F,0x3E,0x04,0x21,0x14,0x11,0x92,0x04,0x7E,0x04,
0x10,0x04,0x10,0x0A,0x70,0x0A,0x1F,0x0A,0x12,0x11,0x10,0x11,0x90,0x20,0x50,0x40,/*"软",19*/


0x10,0x04,0x10,0x04,0x90,0x04,0x88,0x04,0x88,0x3F,0x4C,0x04,0x4C,0x04,0x2A,0x04,
0x09,0x04,0xE8,0x7F,0x08,0x04,0x08,0x04,0x08,0x04,0x08,0x04,0x08,0x04,0x08,0x04,/*"件",20*/


0x04,0x01,0x04,0x01,0x04,0x01,0x04,0x01,0xDF,0x0F,0x04,0x09,0x04,0x09,0x44,0x19,
0x44,0x29,0x24,0x49,0x14,0x49,0x04,0x09,0x84,0x08,0x84,0x08,0x44,0x0A,0x24,0x04,/*"协",21*/

0x80,0x00,0x80,0x00,0x40,0x01,0x20,0x02,0x10,0x04,0x0C,0x18,0xF3,0x67,0x00,0x00,
0x00,0x00,0xFE,0x3F,0x40,0x00,0x20,0x00,0x10,0x04,0x08,0x08,0xFC,0x1F,0x08,0x10,/*"会",22*/




};
#endif

