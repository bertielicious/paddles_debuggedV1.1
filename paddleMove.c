#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
#include <stdio.h>
void paddleMove(void)
{    
    //static uchar page = 3;
    uchar up[9] = {0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff};
    uchar down[9] = {0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01,0x00};
    
    if(PADDLEUP == LOW && PADDLEDWN == HIGH)       // paddleUp button pressed
    {
        set_address(0, page-1);   // x = 0, y = 3
        lcdWrite(up[buttonPress], HIGH);    // write up[0 to 7]
        set_address(1, page-1);   // x = 0, y = 3
        lcdWrite(up[buttonPress], HIGH);    // write up[0 to 7]
        set_address(0, page);   // x = 0, y = 2
        lcdWrite(down[buttonPress], HIGH);    // write up[0 to 7]
        set_address(1, page);   // x = 0, y = 3
        lcdWrite(down[buttonPress], HIGH);    // write up[0 to 7]
       // printf("buttonPress %d, page %d, up[%d],%x, down[%d], %x\n", buttonPress, page, buttonPress, up[buttonPress], buttonPress, down[buttonPress] );
        buttonPress++;
        if(buttonPress == 9 && page != 1)
        {
            buttonPress = 1;
            page = page - 1;        // becase we are moving up
        }
        if(page == 1 && buttonPress >8)
        {
            page = 1;
            buttonPress = 8;
        }  
    }
    
     if(PADDLEUP == HIGH && PADDLEDWN == LOW)       // paddleDown button pressed
     {
        set_address(0, page-1);   // x = 0, y = 3
        lcdWrite(up[buttonPress], HIGH);    // write up[0 to 7]
        set_address(1, page-1);   // x = 0, y = 3
        lcdWrite(up[buttonPress], HIGH);    // write up[0 to 7]
        set_address(0, page);   // x = 0, y = 2
        lcdWrite(down[buttonPress], HIGH);    // write up[0 to 7]
        set_address(1, page);   // x = 0, y = 3
        lcdWrite(down[buttonPress], HIGH);    // write up[0 to 7]
       // printf("DWNbuttonPress %d, page %d, up[%d],%x, down[%d], %x\n", buttonPress, page, buttonPress, up[buttonPress], buttonPress, down[buttonPress] );
        
        if(buttonPress > 0)
        {
            buttonPress--;
        }
        else
        {
            if(page < 5)
            {
                page = page + 1;
                buttonPress = 7;
            }   
        } 
     }
    
    position[page - 1][0] = up[buttonPress];   // copy current position of paddle into collision [row][0]]
    position[page][0] = down[buttonPress];
    //printf("collision[%d][0] = %x\t     collision[%d][0] = %x\n", page-1, collision[page - 1][0], page, collision[page][0]);
   
}