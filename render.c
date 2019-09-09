#include "config.h"
#include "set_address.h"
#include "lcdWrite.h"
#include <stdio.h>

void render(struct posnData s, bool erase)      //render receives the entire struct containing page, date, col and offset
{
                 //[row][col]
     if(erase == 1)
     {
        // gameplay_area[s.pageHigh][s.col] = gameplay_area[s.pageHigh][s.col]|0x00;      // clear the ball data from gameplay_area[][]]
          set_address( s.col, s.pageHigh);  
         lcdWrite(0x00|gameplay_area[s.pageHigh][s.col], HIGH);
         if(s.pageHigh != 5)
         {
         set_address( s.col, s.pageLow);  
         lcdWrite(0x00|gameplay_area[s.pageLow][s.col], HIGH);
         }
     }
     else if (erase == 0)
     {
         set_address( s.col, s.pageHigh);  
       // gameplay_area[s.pageHigh][s.col] = gameplay_area[s.pageHigh][s.col]|(s.dataHigh);       // write the ball data to gameplay_area[][]]
        lcdWrite(gameplay_area[s.pageHigh][s.col]|s.dataHigh, HIGH);       // refresh the LCD with the latest version of gameplay_area[][] 
       /*  if(s.row%8 == 0)                           //if row is 8, 16, 24, 32 or 40
            {
                set_address(s.col, s.pageHigh-1);   // go back a page
                lcdWrite(0x00, HIGH);               // erase unwanted data on LCD
            }*/
         if(s.pageHigh != 5)
         {
        set_address( s.col, s.pageLow); 
       // gameplay_area[s.pageLow][s.col] = gameplay_area[s.pageLow][s.col]|(s.dataLow); 
        lcdWrite(gameplay_area[s.pageLow][s.col]|s.dataLow, HIGH);       // refresh the LCD with the latest version of gameplay_area[][] 
         }
      /*  if(s.col == 1)
        {
        collision[s.pageHigh][s.col] = s.dataHigh;  // ball position at column 1
        collision[s.pageLow][s.col] = s.dataLow;    // test is made to see if the ball and paddle are going to collide
        printf("collisionHigh[%d][%d] = %x\n",  collision[s.pageHigh][s.col], s.dataHigh);
        printf("collisionLow[%d][%d] = %x\n",  collision[s.pageLow][s.col],  s.dataLow);
        }*/
     }
     
    // lcdWrite(gameplay_area[s.page][s.col], HIGH);       // refresh the LCD with the latest version of gameplay_area[][] 
     //lcdWrite(gameplay_area[s.page][s.x]&s.data, HIGH);
    // printf("data = %d, erase = %d\n", s.data, erase);
}
