#include"main.h"

class Card{
    int x;
    int y;
    int width;
    int height;
    int radius;
    COLORREF color;
    COLORREF borderColor;
    int borderWidth;
    char name[20];
    string imageName;
    public:
    Card(){}
    Card(int x,int y,int w,int h,int rad,COLORREF clr,COLORREF bclr,int bw,char* n,string img):x(x),y(y),width(w),height(h),radius(rad),color(clr),borderColor(bclr),borderWidth(bw),imageName(img){strcpy(name,n);}
    void setData(int ax,int why,int w,int h,int rad,COLORREF clr,COLORREF bclr,int bw,char* n,string img){x=ax;y=why;width=w;height=h;radius=rad;color=clr;borderColor=bclr;borderWidth=bw;strcpy(name,n);imageName=img;}
    void display(){
        drawRoundedBox(x,y,width,height+40,radius,color,borderColor,borderWidth);
        settextstyle(BOLD_FONT,HORIZ_DIR,3);
        setbkcolor(color);
        setcolor(WHITE);
        outtextxy(x + width/2 - textwidth(name)/2,y - textheight(name)/2 + 30,name);
        readimagefile(imageName.c_str(),x,y+30,x+width,y+width+40);
    }
    void display(COLORREF clr,COLORREF txtclr){
        drawRoundedBox(x,y,width,height+40,radius,clr,borderColor,borderWidth);
        settextstyle(BOLD_FONT,HORIZ_DIR,3);
        setcolor(txtclr);
        setbkcolor(clr);
        outtextxy(x + width/2 - textwidth(name)/2,y - textheight(name)/2 + 30,name);
        readimagefile(imageName.c_str(),x,y+30,x+width,y+width+40);
    }
};

void Player::pawnPromotion(int currentPiece){
    char* text = (char*)"Select the piece of promotion:";
    setbkcolor(COLOR(240, 219, 81));
    cleardevice();
    drawRoundedBox(getmaxx() / 2 - 300, getmaxy() / 2 - 200, 600, 400, 12, COLOR(109, 29, 222), BLACK, 3);
    setbkcolor(COLOR(109, 29, 222));
    setcolor(WHITE);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(getmaxx() / 2 - textwidth(text) / 2, getmaxy() / 2 - textheight(text) / 2 - 150, text);
    Card arr[4];
    arr[0].setData(300,320,100,110,12,RED,WHITE,2,(char*)"Queen","img/pieces/black-queen.gif");
    arr[1].setData(405,320,100,110,12,RED,WHITE,2,(char*)"Rook","img/pieces/black-rook.gif");
    arr[2].setData(510,320,100,110,12,RED,WHITE,2,(char*)"Bishop","img/pieces/black-bishop.gif");
    arr[3].setData(615,320,100,110,12,RED,WHITE,2,(char*)"Knight","img/pieces/black-rknight.gif");
    for(int i=0;i<4;i++){
        arr[i].display();
    }
    arr[0].display(YELLOW,BLACK);
    int currentCard = 0;
    while(true){
        if(kbhit()){
            char ch=getch();
            if(ch == 13){
                Piece* todelete = getPiece(currentPiece);
                Board* brd = todelete->getBoard();
                string clr = todelete->getColor();
                int x = todelete->getX();
                int y = todelete->getY();
                Piece* newPiece;
                switch (currentCard)
                {
                case 0:newPiece = new Queen(x,y,clr,brd);break;
                case 1:newPiece = new Rook(x,y,clr,brd);break;
                case 2:newPiece = new Bishop(x,y,clr,brd);break;
                case 3:newPiece = new Knight(x,y,clr,brd);break;
                default:
                    break;
                }
                newPiece->setImage();
                brd->getBox(x,y)->setPiece(newPiece);
                setPiece(currentPiece,newPiece);
                delete todelete;
                break;
            }
            if(ch=='w'|| ch=='W' || ch=='a' || ch=='A' || ch == 72 || ch == 75){
                if(currentCard == 0){
                    currentCard = 3;
                }else{
                    currentCard--;
                }
            }
            if(ch=='s'|| ch=='S' || ch=='d' || ch=='D' || ch == 77 || ch == 80){
                if(currentCard==3){
                    currentCard=0;
                }else{
                    currentCard++;
                }
            }
            for(int i=0;i<4;i++){
                if(i==currentCard)
                    arr[i].display(YELLOW,BLACK);
                else
                    arr[i].display();
            }
        }
    }
}
