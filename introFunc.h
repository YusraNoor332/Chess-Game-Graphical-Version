#include"gameLoop.h"


// Function to draw round box;
void drawRoundedBox(int x, int y, int width, int height, int cornerRadius, int fillColor, int borderColor, int lineWidth)
{
    // Set fill style and color
    setfillstyle(SOLID_FILL, fillColor);
    setcolor(borderColor);
    setlinestyle(SOLID_LINE, 0, lineWidth);

    // Draw rounded corners
    arc(x + cornerRadius, y + cornerRadius, 90, 180, cornerRadius);
    arc(x + width - cornerRadius, y + cornerRadius, 0, 90, cornerRadius);
    arc(x + cornerRadius, y + height - cornerRadius, 180, 270, cornerRadius);
    arc(x + width - cornerRadius, y + height - cornerRadius, 270, 0, cornerRadius);

    // Draw the straight lines to connect the arcs
    line(x + cornerRadius, y, x + width - cornerRadius, y);
    line(x, y + cornerRadius, x, y + height - cornerRadius);
    line(x + width, y + cornerRadius, x + width, y + height - cornerRadius);
    line(x + cornerRadius, y + height, x + width - cornerRadius, y + height);

    floodfill(x + (width / 2), y + (height / 2), borderColor);
}


// Welcome Fuction;
void welcome()
{
    readimagefile("img/background/bg-img.jpg", -100, 0, getmaxx() + 100, getmaxy());
    Sleep(1200);
    char *text = (char *)"CHESS";
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 54);
    setcolor(YELLOW);
    setbkcolor(COLOR(6, 12, 59));
    outtextxy(getmaxx() / 2 - textwidth(text) / 2, getmaxy() / 2 - textheight(text) / 2 - 100, text);
    Sleep(1000);
    text = (char *)"Powered By : graphics.h";
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 14);
    setcolor(COLOR(163, 163, 163));
    outtextxy(getmaxx() / 2 - textwidth(text) / 2, getmaxy() / 2 - textheight(text) / 2 + 130, text);
    Sleep(1000);
    text = (char *)"Developed By : Faraz Ahmad";
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 48);
    setcolor(COLOR(213, 213, 213));
    outtextxy(getmaxx() / 2 - textwidth(text) / 2, getmaxy() / 2 - textheight(text) / 2 + 170, text);
    Sleep(2000);
}


void clearBackground()
{
    setbkcolor(COLOR(30, 30, 30));
    cleardevice();
}

string takeUser(char *str_for_input)
{
    char *text1 = str_for_input;
    setbkcolor(COLOR(16, 12, 59));
    cleardevice();
    drawRoundedBox(getmaxx() / 2 - 300, getmaxy() / 2 - 200, 600, 400, 12, COLOR(46, 32, 89), BLUE, 3);
    setbkcolor(COLOR(46, 32, 89));
    setcolor(WHITE);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(getmaxx() / 2 - textwidth(text1) / 2, getmaxy() / 2 - textheight(text1) / 2 - 80, text1);
    char p1[80];
    int i = 0;
    while (1)
    {
        char ch = getch();
        if (ch == 13)
        {
            break;
        }
        if (ch == 8 && i >= 0)
        {
            p1[--i] = '\0';
            goto Print_REST_OF_TEXT;
        }
        p1[i++] = ch;
        p1[i] = '\0';
    Print_REST_OF_TEXT:
        drawRoundedBox(getmaxx() / 2 - 300, getmaxy() / 2 - 200, 600, 400, 12, COLOR(46, 32, 89), BLUE, 3);
        setbkcolor(COLOR(46, 32, 89));
        setcolor(WHITE);
        settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
        outtextxy(getmaxx() / 2 - textwidth(text1) / 2, getmaxy() / 2 - textheight(text1) / 2 - 80, text1);
        settextstyle(BOLD_FONT, HORIZ_DIR, 4);
        setcolor(COLOR(146, 222, 40));
        outtextxy(getmaxx() / 2 - textwidth(p1) / 2, getmaxy() / 2 - textheight(p1) / 2 + 20, p1);
        Sleep(200);
    }
    string name;
    for (int j = 0; j < i; j++)
        name.push_back(p1[j]);
    return name;
}

string takeMode(){
    char *text1 = (char*)"Select Mode OF Game : ";
    bool option1 = true;
    setbkcolor(COLOR(16, 12, 59));
    cleardevice();
    drawRoundedBox(getmaxx() / 2 - 300, getmaxy() / 2 - 200, 600, 400, 12, COLOR(46, 32, 89), BLUE, 3);
    setbkcolor(COLOR(46, 32, 89));
    setcolor(WHITE);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(getmaxx() / 2 - textwidth(text1) / 2, getmaxy() / 2 - textheight(text1) / 2 - 120, text1);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    text1 = (char*)"(Press W for upper and S for lower)";
    outtextxy(getmaxx() / 2 - textwidth(text1) / 2, getmaxy() / 2 - textheight(text1) / 2 - 100, text1);
    drawRoundedBox(350,270,300,50,13,YELLOW,BLACK,3);
    text1 = (char*)"Dark";
    setbkcolor(YELLOW);
    setcolor(GREEN);
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(500 - textwidth(text1)/2,295-textheight(text1)/2,text1);
    text1 = (char*)"Light";
    drawRoundedBox(350,350,300,50,13,COLOR(78, 32, 89),BLUE,3);
    setbkcolor(COLOR(78, 32, 89));
    setcolor(WHITE);
    outtextxy(500 - textwidth(text1)/2,375-textheight(text1)/2,text1);
    while(true){
        if(kbhit()){
            char ch = getch();
            if(ch == 13){
                if(option1){
                    return "dark";
                }else{
                    return "light";
                }
                // break;
            }else{
                if(option1){
                    option1=false;
                }else{
                    option1=true;
                }
            }
            if(ch == 'w'|| ch == 'W'|| ch == 'a' || ch == 'A'|| ch=='s'||ch=='S'||ch=='d'||ch=='D'||ch==72||ch==75||ch==77||ch==80){
                if(option1){
                    drawRoundedBox(350,270,300,50,13,YELLOW,BLACK,3);
                    text1 = (char*)"Dark";
                    setbkcolor(YELLOW);
                    setcolor(GREEN);
                    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
                    outtextxy(500 - textwidth(text1)/2,295-textheight(text1)/2,text1);
                    text1 = (char*)"Light";
                    drawRoundedBox(350,350,300,50,13,COLOR(78, 32, 89),BLUE,3);
                    setbkcolor(COLOR(78, 32, 89));
                    setcolor(WHITE);
                    outtextxy(500 - textwidth(text1)/2,375-textheight(text1)/2,text1);
                }else{
                    drawRoundedBox(350,270,300,50,13,COLOR(78, 32, 89),BLUE,3);
                    text1 = (char*)"Dark";
                    setbkcolor(COLOR(78, 32, 89));
                    setcolor(WHITE);
                    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
                    outtextxy(500 - textwidth(text1)/2,295-textheight(text1)/2,text1);
                    text1 = (char*)"Light";
                    drawRoundedBox(350,350,300,50,13,YELLOW,BLACK,3);
                    setbkcolor(YELLOW);
                    setcolor(GREEN);
                    outtextxy(500 - textwidth(text1)/2,375-textheight(text1)/2,text1);
                }
            }
        }
    }
}


string takeExit(){
    char *text1 = (char*)"Do you really want an exit? : ";
    bool option1 = true;
    setbkcolor(COLOR(16, 12, 59));
    cleardevice();
    drawRoundedBox(getmaxx() / 2 - 300, getmaxy() / 2 - 200, 600, 400, 12, COLOR(46, 32, 89), BLUE, 3);
    setbkcolor(COLOR(46, 32, 89));
    setcolor(WHITE);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(getmaxx() / 2 - textwidth(text1) / 2, getmaxy() / 2 - textheight(text1) / 2 - 120, text1);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    text1 = (char*)"(Press W for upper and S for lower)";
    outtextxy(getmaxx() / 2 - textwidth(text1) / 2, getmaxy() / 2 - textheight(text1) / 2 - 100, text1);
    drawRoundedBox(350,270,300,50,13,YELLOW,BLACK,3);
    text1 = (char*)"YES";
    setbkcolor(YELLOW);
    setcolor(GREEN);
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(500 - textwidth(text1)/2,295-textheight(text1)/2,text1);
    text1 = (char*)"NO";
    drawRoundedBox(350,350,300,50,13,COLOR(78, 32, 89),BLUE,3);
    setbkcolor(COLOR(78, 32, 89));
    setcolor(WHITE);
    outtextxy(500 - textwidth(text1)/2,375-textheight(text1)/2,text1);
    while(true){
        if(kbhit()){
            char ch = getch();
            if(ch == 13){
                if(option1){
                    return "yes";
                }else{
                    return "no";
                }
            }else{
                if(option1){
                    option1=false;
                }else{
                    option1=true;
                }
            }
            if(option1){
                drawRoundedBox(350,270,300,50,13,YELLOW,BLACK,3);
                text1 = (char*)"YES";
                setbkcolor(YELLOW);
                setcolor(GREEN);
                settextstyle(BOLD_FONT, HORIZ_DIR, 4);
                outtextxy(500 - textwidth(text1)/2,295-textheight(text1)/2,text1);
                text1 = (char*)"NO";
                drawRoundedBox(350,350,300,50,13,COLOR(78, 32, 89),BLUE,3);
                setbkcolor(COLOR(78, 32, 89));
                setcolor(WHITE);
                outtextxy(500 - textwidth(text1)/2,375-textheight(text1)/2,text1);
            }else{
                drawRoundedBox(350,270,300,50,13,COLOR(78, 32, 89),BLUE,3);
                text1 = (char*)"YES";
                setbkcolor(COLOR(78, 32, 89));
                setcolor(WHITE);
                settextstyle(BOLD_FONT, HORIZ_DIR, 4);
                outtextxy(500 - textwidth(text1)/2,295-textheight(text1)/2,text1);
                text1 = (char*)"NO";
                drawRoundedBox(350,350,300,50,13,YELLOW,BLACK,3);
                setbkcolor(YELLOW);
                setcolor(GREEN);
                outtextxy(500 - textwidth(text1)/2,375-textheight(text1)/2,text1);
            }
        }
    }
}
void displayImage(int x,int y,const char * str){
    readimagefile(str,y*BOX_SIZE,x*BOX_SIZE,y*BOX_SIZE + BOX_SIZE,x*BOX_SIZE+BOX_SIZE);
}

void setUpArena(){
    for (int row = 0; row < 8; row++){
        for (int col = 0; col < 8; col++){
            int x = col * BOX_SIZE;
            int y = row * BOX_SIZE;
            if ((row + col) % 2 == 0){
                if(mode=="dark"){setfillstyle(SOLID_FILL, COLOR(255, 242, 216));}
                else{setfillstyle(SOLID_FILL,WHITE);}
                // setfillstyle(SOLID_FILL, COLOR(255, 242, 216));
            }else{
                if(mode=="dark"){setfillstyle(SOLID_FILL, COLOR(101, 69, 31));}
                else{setfillstyle(SOLID_FILL,BLACK);}
                // setfillstyle(SOLID_FILL, COLOR(101, 69, 31));
            }
            bar(x, y, x + BOX_SIZE, y + BOX_SIZE);
        }
    }
    setfillstyle(SOLID_FILL,COLOR(0, 0, 0));
    bar(640,0,1000,640);
    setfillstyle(SOLID_FILL,COLOR(45,45,45));
    bar(640 + 5,0 + 5,1000 - 5,640 - 5);

    // Error Testing;
    char txt[80] ;
    stringToChar(txt,mode);
    setbkcolor(COLOR(45,45,45));
    setcolor(WHITE);
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
    outtextxy(820 - textwidth(txt)/2,140-textwidth(txt)/2,txt);
}

void stringToChar(char arr[],string s){
    for(unsigned int i =0;i<s.length();i++){
        arr[i]=s[i];
        arr[i+1] = '\0';
    }
}

void setInstructionBox(char* i1,char* i2,char* i3,char* i4,char* i5,char* i6,char* i7,char* i8,char* i9){
    drawRoundedBox(660,360,320,260,12,COLOR(250, 247, 227),COLOR(53, 8, 94),3);
    setbkcolor(COLOR(250, 247, 227));
    setcolor(COLOR(121, 10, 247));
    settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
    char * txt = (char*)"INSTRUCTIONS:";
    outtextxy(820 - textwidth(txt)/2,370,txt);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    setcolor(BLACK);
    txt = i1;
    outtextxy(820 - textwidth(i1)/2,410,i1);
    txt = i2;
    outtextxy(820 - textwidth(i2)/2,430,i2);
    txt = i3;
    outtextxy(820 - textwidth(i3)/2,450,i3);
    txt = i4;
    outtextxy(820 - textwidth(i4)/2,470,i4);
    txt = i5;
    outtextxy(820 - textwidth(i5)/2,490,i5);
    txt = i6;
    outtextxy(820 - textwidth(i6)/2,510,i6);
    txt = i7;
    outtextxy(820 - textwidth(i7)/2,530,i7);
    txt = i8;
    outtextxy(820 - textwidth(i8)/2,550,i8);
    txt = i9;
    outtextxy(820 - textwidth(i9)/2,570,i9);
}




