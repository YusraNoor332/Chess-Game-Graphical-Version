// This file will contain the header files including class Definations;
#include<iostream>
#include<graphics.h>
#include<windows.h>
#include"mmsystem.h"
#include<cstring>
using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 640;  // 80 * 8 
const int BOX_SIZE = 80; // 80 * 80
string mode = "dark";


// Function Declarations;
void drawRoundedBox(int x, int y, int width, int height, int cornerRadius, int fillColor, int borderColor, int lineWidth);  //introFunc
void welcome();  //introFunc
void clearBackground(); //introFunc
string takeUser(char *str_for_input); //introFunc
string takeMode(); //introFunc
void setUpArena(); // introFunc
void stringToChar(char arr[],string s); //introFunc
string takeExit(); //introFunc
void setInstructionBox(char* i1=(char*)" ",char* i2=(char*)" ",char* i3=(char*)" ",char* i4=(char*)" ",char* i5=(char*)" ",char* i6=(char*)" ",char* i7=(char*)" ",char* i8=(char*)" ",char* i9=(char*)" ");



class Board;
class Box;
struct COORDS{
    int x,y;
};

class Piece{
    protected:
        string name;
        int x;
        int y;
        string color;
        string imageURL;
        COORDS movements[32];
        int totalMovements;
        Board* board;
    public:
    Piece():name("unknown"),x(-1),y(-1),color("White"),imageURL("nope"),totalMovements(0),board(nullptr){}
    Piece(string n):name(n),x(-1),y(-1),color("White"),imageURL("nope"),totalMovements(0),board(nullptr){}
    Piece(string n,int ax,int why,string clr,Board* b):name(n),x(ax),y(why),color(clr),imageURL("nope"),totalMovements(0),board(b){}
    virtual ~Piece(){}
    void setData(string n,int ax,int why,string clr,Board* b){name = n;x = ax;y = why;color = clr;board = b;}
    void setData(int ax,int why,string clr,Board* b){x = ax;y = why;color = clr;board = b;}
    virtual void setImage(string imgURL){
        imageURL = imgURL;
    }
    virtual void setImage(){
        string clr = (color== "White"?(mode=="dark"?"white":"light"):(mode=="dark"?"black":"brown"));
        if(name=="knight"){
            if(color=="White"){name = "lknight";}
            else{name = "rknight";}
        }
        imageURL = "img/pieces/" + clr + "-" + name + ".gif"; 
    }
    string getName(){return name;}
    string getImage(){return imageURL;}
    string getColor(){return color;}
    Board* getBoard(){return board;}
    int getTotalMoves(){return totalMovements;}
    COORDS* getMovement(int n){return &movements[n];}
    int getX(){return x;}
    int getY(){return y;}
    virtual void display(){
        readimagefile(imageURL.c_str(),y*BOX_SIZE,x*BOX_SIZE,y*BOX_SIZE + BOX_SIZE,x*BOX_SIZE+BOX_SIZE);
    }
    virtual void showMovements();
    virtual void muteMovements();
    virtual void updatePosition(int ax,int why){x = ax;y = why;};
    virtual void updateMovements();
};

// Inhereted Pieces;
class King:public Piece{
    public:
    King():Piece("king"){}
    King(int ax,int why,string clr,Board* b):Piece("king",ax,why,clr,b){}
    ~King(){}
    void updateMovements();
};
class Queen:public Piece{
    public:
    Queen():Piece("queen"){}
    Queen(int ax,int why,string clr,Board* b):Piece("queen",ax,why,clr,b){}
    ~Queen(){}
    void updateMovements();
};
class Bishop:public Piece{
    public:
    Bishop():Piece("bishop"){}
    Bishop(int ax,int why,string clr,Board* b):Piece("bishop",ax,why,clr,b){}
    ~Bishop(){}
    void updateMovements();
};
class Rook:public Piece{
    public:
    Rook():Piece("rook"){}
    Rook(int ax,int why,string clr,Board* b):Piece("rook",ax,why,clr,b){}
    ~Rook(){}
    void updateMovements();
};
class Knight:public Piece{
    public:
    Knight():Piece("knight"){}
    Knight(int ax,int why,string clr,Board* b):Piece("knight",ax,why,clr,b){}
    ~Knight(){}
    void updateMovements();
};
class Pawn:public Piece{
    public:
    Pawn():Piece("pawn"){}
    Pawn(int ax,int why,string clr,Board* b):Piece("pawn",ax,why,clr,b){}
    ~Pawn(){}
    void updateMovements();
};

class Player{
    enum{MAX=16};
    string name;
    string color;
    int totalPieces;
    Piece* pieces[MAX];
    public:
    Player():name("none"),color("White"),totalPieces(0){}
    Player(string n,string clr):name(n),color(clr),totalPieces(0){}
    ~Player(){
        for(int i=0;i<totalPieces;i++){
            delete pieces[i];
        }
    }
    void setData(string n,string clr){name=n;color=clr;}
    Piece* getPiece(int n){return pieces[n];}
    void setPiece(int n,Piece* p){
        pieces[n] = p;
    }
    string getColor(){return color;}
    string getName(){return name;}
    int getTotalpieces(){return totalPieces;}
    void setPieceImages();
    void addPiece(Piece& p);
    void removePiece(Piece& p);
    void pawnPromotion(int currentPiece);
};

class Box{
    int x;
    int y;
    COLORREF color;
    Piece* piece;
    bool set;
    public:
    Box():x(-1),y(-1),color(GREEN),piece(nullptr),set(false){}
    void setData(int ax,int why,Piece* p){x = ax;y = why;piece = p;set = true;setColor();}
    void setData(int ax,int why){x = ax;y = why;setColor();}
    void setColor(){
        if((x+y)%2==0){
            if(mode=="dark"){color = COLOR(255, 242, 216);}
            else{color = COLOR(255,255,255);}
        }else{
            if(mode=="dark"){color = COLOR(101, 69, 31);}
            else{color = COLOR(0,0,0);}
        }
    }
    void setPiece(Piece* p){piece = p;set=true;}
    Piece* getPiece(){return piece;}
    int getX(){return x;}
    int getY(){return y;}
    void setEmpty(){
        piece = nullptr;
        set = false;
    }
    bool checkSet(){return set;}
    void display();
    void display(COLORREF clr);
};

class Board{
    Box boxes[8][8];
    bool win,draw;
    public:
    Box* focus;
    Player* turn;
    Player p1,p2;
    Board(string s1,string s2):win(false),draw(false),p1(s1,"White"),p2(s2,"Black"){}
    bool getWin(){return win;}
    bool getDraw(){return draw;}
    void setBoard();
    void setArena();
    void gameLoop();
    Box* getBox(int x,int y){return &boxes[x][y];}
    void makeMove(int x1, int y1, int x2, int y2,int currentPiece);
    void setUpperBox(char* pn = (char*)"PLAYER NAME",char* clr=(char*)"PLAYER COLOR");
    void setPiecesBox(int white=16,int black=16);
    void checkStaleMate();
};










