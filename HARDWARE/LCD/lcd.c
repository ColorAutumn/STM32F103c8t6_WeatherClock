#include "lcd.h"
#include "oledfont.h"
#include "delay.h"

u16 BACK_COLOR; // ����ɫ

/******************************************************************************
      ����˵����LCD��������д�뺯��
      ������ݣ�dat  Ҫд��Ĵ�������
      ����ֵ��  ��
******************************************************************************/
void LCD_Writ_Bus(u8 dat)
{
    u8 i;
    for (i = 0; i < 8; i++)
    {
        OLED_SCLK_Clr();
        if (dat & 0x80)
            OLED_SDIN_Set();
        else
            OLED_SDIN_Clr();
        OLED_SCLK_Set();
        dat <<= 1;
    }
}

/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_DATA8(u8 dat)
{
    OLED_DC_Set(); // д����
    LCD_Writ_Bus(dat);
}

/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_DATA(u16 dat)
{
    OLED_DC_Set(); // д����
    LCD_Writ_Bus(dat >> 8);
    LCD_Writ_Bus(dat);
}

/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_REG(u8 dat)
{
    OLED_DC_Clr(); // д����
    LCD_Writ_Bus(dat);
}

/******************************************************************************
      ����˵����������ʼ�ͽ�����ַ
      ������ݣ�x1,x2 �����е���ʼ�ͽ�����ַ
                y1,y2 �����е���ʼ�ͽ�����ַ
      ����ֵ��  ��
******************************************************************************/
void LCD_Address_Set(u16 x1, u16 y1, u16 x2, u16 y2)
{
    if (USE_HORIZONTAL == 0)
    {
        LCD_WR_REG(0x2a); // �е�ַ����
        LCD_WR_DATA(x1);
        LCD_WR_DATA(x2);
        LCD_WR_REG(0x2b); // �е�ַ����
        LCD_WR_DATA(y1);
        LCD_WR_DATA(y2);
        LCD_WR_REG(0x2c); // ������д
    }
    else if (USE_HORIZONTAL == 1)
    {
        LCD_WR_REG(0x2a); // �е�ַ����
        LCD_WR_DATA(x1);
        LCD_WR_DATA(x2);
        LCD_WR_REG(0x2b); // �е�ַ����
        LCD_WR_DATA(y1 + 80);
        LCD_WR_DATA(y2 + 80);
        LCD_WR_REG(0x2c); // ������д
    }
    else if (USE_HORIZONTAL == 2)
    {
        LCD_WR_REG(0x2a); // �е�ַ����
        LCD_WR_DATA(x1);
        LCD_WR_DATA(x2);
        LCD_WR_REG(0x2b); // �е�ַ����
        LCD_WR_DATA(y1);
        LCD_WR_DATA(y2);
        LCD_WR_REG(0x2c); // ������д
    }
    else
    {
        LCD_WR_REG(0x2a); // �е�ַ����
        LCD_WR_DATA(x1 + 80);
        LCD_WR_DATA(x2 + 80);
        LCD_WR_REG(0x2b); // �е�ַ����
        LCD_WR_DATA(y1);
        LCD_WR_DATA(y2);
        LCD_WR_REG(0x2c); // ������д
    }
}

/******************************************************************************
      ����˵����LCD��ʼ������
      ������ݣ���
      ����ֵ��  ��
******************************************************************************/
void Lcd_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // ʹ��A�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // �������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // �ٶ�50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);            // ��ʼ��GPIOD3,6
    GPIO_SetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_7 | GPIO_Pin_4);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // ʹ��B�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // �������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // �ٶ�50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);            // ��ʼ��GPIOB0,1
    GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);

    OLED_RST_Clr();
    delay_ms(20);
    OLED_RST_Set();
    delay_ms(20);
    OLED_BLK_Set();

    //************* Start Initial Sequence **********//
    LCD_WR_REG(0x36);
    if (USE_HORIZONTAL == 0)
        LCD_WR_DATA8(0x00);
    else if (USE_HORIZONTAL == 1)
        LCD_WR_DATA8(0xC0);
    else if (USE_HORIZONTAL == 2)
        LCD_WR_DATA8(0x70);
    else
        LCD_WR_DATA8(0xA0);

    LCD_WR_REG(0x3A);
    LCD_WR_DATA8(0x05);

    LCD_WR_REG(0xB2);
    LCD_WR_DATA8(0x0C);
    LCD_WR_DATA8(0x0C);
    LCD_WR_REG(0x36);
    // LCD_WR_DATA8(0x40);//������ʾ
    LCD_WR_DATA8(0x00); // ������ʾ
    LCD_WR_DATA8(0x33);
    LCD_WR_DATA8(0x33);

    LCD_WR_REG(0xB7);
    LCD_WR_DATA8(0x35);

    LCD_WR_REG(0xBB);
    LCD_WR_DATA8(0x19);

    LCD_WR_REG(0xC0);
    LCD_WR_DATA8(0x2C);

    LCD_WR_REG(0xC2);
    LCD_WR_DATA8(0x01);

    LCD_WR_REG(0xC3);
    LCD_WR_DATA8(0x12);

    LCD_WR_REG(0xC4);
    LCD_WR_DATA8(0x20);

    LCD_WR_REG(0xC6);
    LCD_WR_DATA8(0x0F);

    LCD_WR_REG(0xD0);
    LCD_WR_DATA8(0xA4);
    LCD_WR_DATA8(0xA1);

    LCD_WR_REG(0xE0);
    LCD_WR_DATA8(0xD0);
    LCD_WR_DATA8(0x04);
    LCD_WR_DATA8(0x0D);
    LCD_WR_DATA8(0x11);
    LCD_WR_DATA8(0x13);
    LCD_WR_DATA8(0x2B);
    LCD_WR_DATA8(0x3F);
    LCD_WR_DATA8(0x54);
    LCD_WR_DATA8(0x4C);
    LCD_WR_DATA8(0x18);
    LCD_WR_DATA8(0x0D);
    LCD_WR_DATA8(0x0B);
    LCD_WR_DATA8(0x1F);
    LCD_WR_DATA8(0x23);

    LCD_WR_REG(0xE1);
    LCD_WR_DATA8(0xD0);
    LCD_WR_DATA8(0x04);
    LCD_WR_DATA8(0x0C);
    LCD_WR_DATA8(0x11);
    LCD_WR_DATA8(0x13);
    LCD_WR_DATA8(0x2C);
    LCD_WR_DATA8(0x3F);
    LCD_WR_DATA8(0x44);
    LCD_WR_DATA8(0x51);
    LCD_WR_DATA8(0x2F);
    LCD_WR_DATA8(0x1F);
    LCD_WR_DATA8(0x1F);
    LCD_WR_DATA8(0x20);
    LCD_WR_DATA8(0x23);

    LCD_WR_REG(0x21);

    LCD_WR_REG(0x11);
    // Delay (120);

    LCD_WR_REG(0x29);
}

/******************************************************************************
      ����˵����LCD��������
      ������ݣ���
      ����ֵ��  ��
******************************************************************************/
void LCD_Clear(u16 Color)
{
    u16 i, j;
    LCD_Address_Set(0, 0, LCD_W - 1, LCD_H - 1);
    for (i = 0; i < LCD_W; i++)
    {
        for (j = 0; j < LCD_H; j++)
        {
            LCD_WR_DATA(Color);
        }
    }
}

/******************************************************************************
      ����˵����LCD��ʾ����
      ������ݣ�x,y   ��ʼ����
                index ���ֵ����
                size  �ֺ�
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowChinese(u16 x, u16 y, u8 index, u8 size, u16 color)
{
    u8 i, j;
    u8 *temp, size1;
    if (size == 16)
    {
        temp = Hzk16; // ѡ���ֺ�
    }
    if (size == 32)
    {
        temp = Hzk32;
    }
    LCD_Address_Set(x, y, x + size - 1, y + size - 1); // ����һ�����ֵ�����
    size1 = size * size / 8;                           // һ��������ռ���ֽ�
    temp += index * size1;                             // д�����ʼλ��
    for (j = 0; j < size1; j++)
    {
        for (i = 0; i < 8; i++)
        {
            if ((*temp & (1 << i)) != 0) // �����ݵĵ�λ��ʼ��
            {
                LCD_WR_DATA(color); // ����
            }
            else
            {
                LCD_WR_DATA(BACK_COLOR); // ������
            }
        }
        temp++;
    }
}

/******************************************************************************
      ����˵����LCD��ʾ����
      ������ݣ�x,y   ��ʼ����
      ����ֵ��  ��
******************************************************************************/
void LCD_DrawPoint(u16 x, u16 y, u16 color)
{
    LCD_Address_Set(x, y, x, y); // ���ù��λ��
    LCD_WR_DATA(color);
}

/******************************************************************************
      ����˵����LCD��һ����ĵ�
      ������ݣ�x,y   ��ʼ����
      ����ֵ��  ��
******************************************************************************/
void LCD_DrawPoint_big(u16 x, u16 y, u16 color)
{
    LCD_Fill(x - 1, y - 1, x + 1, y + 1, color);
}

/******************************************************************************
      ����˵������ָ�����������ɫ
      ������ݣ�xsta,ysta   ��ʼ����
                xend,yend   ��ֹ����
      ����ֵ��  ��
******************************************************************************/
void LCD_Fill(u16 xsta, u16 ysta, u16 xend, u16 yend, u16 color)
{
    u16 i, j;
    LCD_Address_Set(xsta, ysta, xend, yend); // ���ù��λ��
    for (i = ysta; i <= yend; i++)
    {
        for (j = xsta; j <= xend; j++)
            LCD_WR_DATA(color); // ���ù��λ��
    }
}

/******************************************************************************
      ����˵��������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
      ����ֵ��  ��
******************************************************************************/
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
    u16 t;
    int xerr = 0, yerr = 0, delta_x, delta_y, distance;
    int incx, incy, uRow, uCol;
    delta_x = x2 - x1; // ������������
    delta_y = y2 - y1;
    uRow = x1; // �����������
    uCol = y1;
    if (delta_x > 0)
        incx = 1; // ���õ�������
    else if (delta_x == 0)
        incx = 0; // ��ֱ��
    else
    {
        incx = -1;
        delta_x = -delta_x;
    }
    if (delta_y > 0)
        incy = 1;
    else if (delta_y == 0)
        incy = 0; // ˮƽ��
    else
    {
        incy = -1;
        delta_y = -delta_x;
    }
    if (delta_x > delta_y)
        distance = delta_x; // ѡȡ��������������
    else
        distance = delta_y;
    for (t = 0; t < distance + 1; t++)
    {
        LCD_DrawPoint(uRow, uCol, color); // ����
        xerr += delta_x;
        yerr += delta_y;
        if (xerr > distance)
        {
            xerr -= distance;
            uRow += incx;
        }
        if (yerr > distance)
        {
            yerr -= distance;
            uCol += incy;
        }
    }
}

/******************************************************************************
      ����˵����������
      ������ݣ�x1,y1   ��ʼ����
                x2,y2   ��ֹ����
      ����ֵ��  ��
******************************************************************************/
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)
{
    LCD_DrawLine(x1, y1, x2, y1, color);
    LCD_DrawLine(x1, y1, x1, y2, color);
    LCD_DrawLine(x1, y2, x2, y2, color);
    LCD_DrawLine(x2, y1, x2, y2, color);
}

/******************************************************************************
      ����˵������Բ
      ������ݣ�x0,y0   Բ������
                r       �뾶
      ����ֵ��  ��
******************************************************************************/
void Draw_Circle(u16 x0, u16 y0, u8 r, u16 color)
{
    int a, b;
    a = 0;
    b = r;
    while (a <= b)
    {
        LCD_DrawPoint(x0 - b, y0 - a, color); // 3
        LCD_DrawPoint(x0 + b, y0 - a, color); // 0
        LCD_DrawPoint(x0 - a, y0 + b, color); // 1
        LCD_DrawPoint(x0 - a, y0 - b, color); // 2
        LCD_DrawPoint(x0 + b, y0 + a, color); // 4
        LCD_DrawPoint(x0 + a, y0 - b, color); // 5
        LCD_DrawPoint(x0 + a, y0 + b, color); // 6
        LCD_DrawPoint(x0 - b, y0 + a, color); // 7
        a++;
        if ((a * a + b * b) > (r * r)) // �ж�Ҫ���ĵ��Ƿ��Զ
        {
            b--;
        }
    }
}

/******************************************************************************
      ����˵������ʾ�ַ�
      ������ݣ�x,y    �������
                num    Ҫ��ʾ���ַ�
                mode   1���ӷ�ʽ  0�ǵ��ӷ�ʽ
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowChar(u16 x, u16 y, u8 num, u8 mode, u16 color)
{
    u8 temp;
    u8 pos, t;
    u16 x0 = x;
    if (x > LCD_W - 16 || y > LCD_H - 16)
        return;                                   // ���ô���
    num = num - ' ';                              // �õ�ƫ�ƺ��ֵ
    LCD_Address_Set(x, y, x + 8 - 1, y + 16 - 1); // ���ù��λ��
    if (!mode)                                    // �ǵ��ӷ�ʽ
    {
        for (pos = 0; pos < 16; pos++)
        {
            temp = asc2_1608[(u16)num * 16 + pos]; // ����1608����
            for (t = 0; t < 8; t++)
            {
                if (temp & 0x01)
                    LCD_WR_DATA(color);
                else
                    LCD_WR_DATA(BACK_COLOR);
                temp >>= 1;
                x++;
            }
            x = x0;
            y++;
        }
    }
    else // ���ӷ�ʽ
    {
        for (pos = 0; pos < 16; pos++)
        {
            temp = asc2_1608[(u16)num * 16 + pos]; // ����1608����
            for (t = 0; t < 8; t++)
            {
                if (temp & 0x01)
                    LCD_DrawPoint(x + t, y + pos, color); // ��һ����
                temp >>= 1;
            }
        }
    }
}

/******************************************************************************
      ����˵������ʾ�ַ���
      ������ݣ�x,y    �������
                *p     �ַ�����ʼ��ַ
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowString(u16 x, u16 y, const unsigned char *p, u16 color)
{
    while (*p != '\0')
    {
        if (x > LCD_W - 16)
        {
            x = 0;
            y += 16;
        }
        if (y > LCD_H - 16)
        {
            y = x = 0;
            LCD_Clear(RED);
        }
        LCD_ShowChar(x, y, *p, 0, color);
        x += 8;
        p++;
    }
}

/******************************************************************************
      ����˵������ʾ����
      ������ݣ�m������nָ��
      ����ֵ��  ��
******************************************************************************/
u32 mypow(u8 m, u8 n)
{
    u32 result = 1;
    while (n--)
        result *= m;
    return result;
}

/******************************************************************************
      ����˵������ʾ����
      ������ݣ�x,y    �������
                num    Ҫ��ʾ������
                len    Ҫ��ʾ�����ָ���
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowNum(u16 x, u16 y, u16 num, u8 len, u16 color)
{
    u8 t, temp;
    u8 enshow = 0;
    for (t = 0; t < len; t++)
    {
        temp = (num / mypow(10, len - t - 1)) % 10;
        if (enshow == 0 && t < (len - 1))
        {
            if (temp == 0)
            {
                LCD_ShowChar(x + 8 * t, y, ' ', 0, color);
                continue;
            }
            else
                enshow = 1;
        }
        LCD_ShowChar(x + 8 * t, y, temp + 48, 0, color);
    }
}

/******************************************************************************
      ����˵������ʾС��
      ������ݣ�x,y    �������
                num    Ҫ��ʾ��С��
                len    Ҫ��ʾ�����ָ���
      ����ֵ��  ��
******************************************************************************/
void LCD_ShowNum1(u16 x, u16 y, float num, u8 len, u16 color)
{
    u8 t, temp;
    u16 num1;
    num1 = num * 100;
    for (t = 0; t < len; t++)
    {
        temp = (num1 / mypow(10, len - t - 1)) % 10;
        if (t == (len - 2))
        {
            LCD_ShowChar(x + 8 * (len - 2), y, '.', 0, color);
            t++;
            len += 1;
        }
        LCD_ShowChar(x + 8 * t, y, temp + 48, 0, color);
    }
}

/******************************************************************************
      ����˵������ʾ40x40ͼƬ
      ������ݣ�x,y    �������
      ����ֵ��  ��
******************************************************************************/
// void LCD_ShowPicture(u16 x1,u16 y1,u16 x2,u16 y2)
//{
//     int i;
//     LCD_Address_Set(x1,y1,x2,y2);
//     for(i=0; i<57600; i++)
//     {
//         LCD_WR_DATA8(image[i*2+1]);
//         LCD_WR_DATA8(image[i*2]);
//     }
// }
void LCD_ShowPicture(u16 x1, u16 y1, u16 x2, u16 y2, const unsigned char *image) {
    int width = x2 - x1 + 1;
    int height = y2 - y1 + 1;
    int rowBytes = width * 2;  // 2 bytes per pixel for 16-bit color

    // Make sure rowBytes is a multiple of 4
    int padding = (4 - (rowBytes % 4)) % 4;
    int newRowBytes = rowBytes + padding;

    LCD_Address_Set(x1, y1, x2, y2);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int idx = (j * width + i) * 2;
            LCD_WR_DATA8(image[idx + 1]);  // high byte
            LCD_WR_DATA8(image[idx]);      // low byte
        }
        // Write padding bytes to align the row
        for (int p = 0; p < padding; p++) {
            LCD_WR_DATA8(0);  // Pad with zeroes
        }
    }
}
// void LCD_ShowPicture(u16 x, u16 y, u16 x2, u16 y2, const unsigned char *image)
// {
//     // 计算整幅图片的数据长度
//     u32 totalBytes = y2 * y2 * 3;

//     for (u16 i = 0; i < y2; i++)
//     {
//         for (u16 j = 0; j < y2; j++)
//         {
//             // 计算每个像素的起始字节位置
//             u32 pixelIndex = (i * y2 + j) * 3;

//             // 读取RGB值
//             u8 red = image[pixelIndex];
//             u8 green = image[pixelIndex + 1];
//             u8 blue = image[pixelIndex + 2];

//             // 将RGB值组合成一个16位的颜色值（取决于LCD的色深）
//             // 假设LCD支持18位或16位色深，其中5位用于红色，6位用于绿色，5位用于蓝色
//             u16 color = ((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3);

//             // 显示像素
//             LCD_DrawPoint(x + j, y + i, color);
//         }
//     }
// }

void LCD_ShowChineses(u16 x, u16 y, u8 index, u16 size, u16 color)
{
    u8 j, k;
    u8 *temp;
    u16 size1;

    temp = Hzk32;

    LCD_Address_Set(x, y, x + 32 - 1, y + 16 - 1); // ???16????
    size1 = 32 * 16 / 8;                           // ???32�16?????
    temp += index * size1;                         // ???32�16?????

    for (j = 0; j < size1; j++)
    {

        for (k = 0; k < 8; k++)
        {
            if ((*temp & (1 << k)) != 0)
            {
                LCD_WR_DATA(color);
            }
            else
            {
                LCD_WR_DATA(BACK_COLOR);
            }
        }
        temp++;
    }
}
