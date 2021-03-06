unsigned char colors[64][3] = {
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0x2A},   /* palette 0x00 - 0x0F    */
    {0x00, 0x2A, 0x00}, {0x00, 0x2A, 0x2A},   /* basic VGA colors       */
    {0x2A, 0x00, 0x00}, {0x2A, 0x00, 0x2A},
    {0x2A, 0x15, 0x00}, {0x2A, 0x2A, 0x2A},
    {0x15, 0x15, 0x15}, {0x15, 0x15, 0x3F},
    {0x15, 0x3F, 0x15}, {0x15, 0x3F, 0x3F},
    {0x3F, 0x15, 0x15}, {0x3F, 0x15, 0x3F},
    {0x3F, 0x3F, 0x15}, {0x3F, 0x3F, 0x3F},
    {0x00, 0x00, 0x00}, {0x05, 0x05, 0x05},   /* palette 0x10 - 0x1F    */
    {0x08, 0x08, 0x08}, {0x0B, 0x0B, 0x0B},   /* VGA grey scale         */
    {0x0E, 0x0E, 0x0E}, {0x11, 0x11, 0x11},
    {0x14, 0x14, 0x14}, {0x18, 0x18, 0x18},
    {0x1C, 0x1C, 0x1C}, {0x20, 0x20, 0x20},
    {0x24, 0x24, 0x24}, {0x28, 0x28, 0x28},
    {0x2D, 0x2D, 0x2D}, {0x32, 0x32, 0x32},
    {0x38, 0x38, 0x38}, {0x3F, 0x3F, 0x3F},
    {0x3F, 0x3F, 0x3F}, {0x3F, 0x3F, 0x3F},   /* palette 0x20 - 0x2F    */
    {0x00, 0x00, 0x3F}, {0x00, 0x00, 0x00},   /* wa ll and player colors */
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00},
    {0x10, 0x08, 0x00}, {0x18, 0x0C, 0x00},   /* palette 0x30 - 0x3F    */
    {0x20, 0x10, 0x00}, {0x28, 0x14, 0x00},   /* browns for maze floor  */
    {0x30, 0x18, 0x00}, {0x38, 0x1C, 0x00},
    {0x3F, 0x20, 0x00}, {0x3F, 0x20, 0x10},
    {0x20, 0x18, 0x10}, {0x28, 0x1C, 0x10},
    {0x3F, 0x20, 0x10}, {0x38, 0x24, 0x10},
    {0x3F, 0x28, 0x10}, {0x3F, 0x2C, 0x10},
    {0x3F, 0x30, 0x10}, {0x3F, 0x20, 0x10}
};

#include "text.h"
#include "png.h"
int main(){
PNG g(300, sizeof(colors)/3*20);
char s[50];
int s_idx,x,y; char c;
for (int i=0; i < sizeof(colors)/3; i++){
    RGBAPixel p(4*colors[i][0],4*colors[i][1],4*colors[i][2]);
    RGBAPixel b(0,0,0);
    for (x=150; x < 300; x++){
        for (y=20*i; y<20*(i+1); ++y){
        *g(x,y) = p;
    }}
    
    sprintf(s,"DEC: %02d, HEX: 0x%02X", i, i);
    for (s_idx = 0; s_idx < strlen(s); ++s_idx){ //for each char in string
        c = s[s_idx];
        for (y=0; y<FONT_HEIGHT; ++y)
            for (x=0; x < FONT_WIDTH; ++x)
                if (font_data[(int)c][y] & (1 << (FONT_WIDTH-1-x))){ //if the pixel is filled
                    *g(x+s_idx*FONT_WIDTH,20*i+y) = b; //draw the pixsel with FG_COLOR
                }
    }

}

g.writeToFile("colors.png");
}
