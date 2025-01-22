// This file will contain the major fuction definations  (Game Loop Related);
#include"movements.h"

void Board::setUpperBox(char* pn,char* clr){
    drawRoundedBox(640 + 20 + 6,0+20 +6 ,320 -12,180 -12,12,COLOR(130, 209, 152),COLOR(74, 5, 35),3);
    // Setting up text for turn with name and color;
    setbkcolor(COLOR(130, 209, 152));
    settextstyle(SIMPLEX_FONT,HORIZ_DIR,5);
    setcolor(COLOR(107, 30, 74));
    outtextxy(660 + 30,50,(char*)"TURN : ");
    setcolor(COLOR(3, 71, 66));
    settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
    char *txt = pn;
    outtextxy(820 - textwidth(txt)/2,100,txt);
    txt = clr;
    if(turn == &p2){setcolor(BLACK);}
    else{setcolor(WHITE);}
    outtextxy(820 - textwidth(txt)/2,130,txt);
}

void Board::setPiecesBox(int white,int black){
    drawRoundedBox(660, 210, 320, 140, 12, COLOR(130, 209, 152), COLOR(53, 8, 94), 4);
    drawRoundedBox(666, 215, 150, 128, 12, WHITE, WHITE, 1);
    drawRoundedBox(823, 215, 150, 128, 12, WHITE, WHITE, 1);
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    setbkcolor(WHITE);
    setcolor(BLUE);
    char * txt = (char*)"WHITE";
    outtextxy(741-textwidth(txt)/2,220,txt);
    txt = (char*)"BLACK";
    outtextxy(898-textwidth(txt)/2,220,txt);
    char num[3];
    if(white>9){
        num[0] = '1';
        num[1] = to_string(white)[1];num[2]='\0';
    }else{
        num[0]=to_string(white)[0];num[1]='\0';
    }
    settextstyle(GOTHIC_FONT,HORIZ_DIR,8);
    setcolor(RED);
    outtextxy(741-textwidth(num)/2 ,258,num);
    if(black>9){
        num[0] = '1';
        num[1] = to_string(black)[1];num[2]='\0';
    }else{
        num[0]=to_string(black)[0];num[1]='\0';
    }
    num[1] = to_string(black)[1];num[2]='\0';
    outtextxy(898-textwidth(num)/2 ,258,num);
}

void Player::addPiece(Piece& p){
    pieces[totalPieces++] = &p;
}

void Board::setBoard(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            boxes[i][j].setData(i,j);
        }
    }
    // Giving Pieces to player1 (White) and also placing them on the board boxes;
    Rook* rook = new Rook(0,0,"White",this);
    // rook->setImage("img/pieces/white-rook.gif");
    p1.addPiece(*rook);
    boxes[0][0].setPiece(rook);
    Knight* knight = new Knight(1,0,"White",this);
    // knight->setImage("img/pieces/white-lknight.gif");
    p1.addPiece(*knight);
    boxes[1][0].setPiece(knight);
    Bishop* bishop = new Bishop(2,0,"White",this);
    // bishop->setImage("img/pieces/white-bishop.gif");
    p1.addPiece(*bishop);
    boxes[2][0].setPiece(bishop);
    King* king=new King(3,0,"White",this);
    p1.addPiece(*king);
    boxes[3][0].setPiece(king);
    Queen* queen = new Queen(4,0,"White",this);
    p1.addPiece(*queen);
    boxes[4][0].setPiece(queen);
    bishop = new Bishop(5,0,"White",this);
    p1.addPiece(*bishop);
    boxes[5][0].setPiece(bishop);
    knight = new Knight(6,0,"White",this);
    p1.addPiece(*knight);
    boxes[6][0].setPiece(knight);
    rook = new Rook(7,0,"White",this);
    p1.addPiece(*rook);
    boxes[7][0].setPiece(rook);
    Pawn* pawn;
    for(int i=0;i<8;i++){
        pawn = new Pawn(i,1,"White",this);
        p1.addPiece(*pawn);
        boxes[i][1].setPiece(pawn);
    }

    // Now Giving Pieces to player2 (Black) and also placing them on the board boxes;
    rook = new Rook(0,7,"Black",this);
    p2.addPiece(*rook);
    boxes[0][7].setPiece(rook);
    knight = new Knight(1,7,"Black",this);
    p2.addPiece(*knight);
    boxes[1][7].setPiece(knight);
    bishop = new Bishop(2,7,"Black",this);
    p2.addPiece(*bishop);
    boxes[2][7].setPiece(bishop);
    king=new King(3,7,"Black",this);
    p2.addPiece(*king);
    boxes[3][7].setPiece(king);
    queen = new Queen(4,7,"Black",this);
    p2.addPiece(*queen);
    boxes[4][7].setPiece(queen);
    bishop = new Bishop(5,7,"Black",this);
    p2.addPiece(*bishop);
    boxes[5][7].setPiece(bishop);
    knight = new Knight(6,7,"Black",this);
    p2.addPiece(*knight);
    boxes[6][7].setPiece(knight);
    rook = new Rook(7,7,"Black",this);
    p2.addPiece(*rook);
    boxes[7][7].setPiece(rook);
    for(int i=0;i<8;i++){
        pawn = new Pawn(i,6,"Black",this);
        p2.addPiece(*pawn);
        boxes[i][6].setPiece(pawn);
    }
    // Setting up Images for Both Players;
    p1.setPieceImages();
    p2.setPieceImages();
}


void Player::setPieceImages(){
    for(int i=0;i<totalPieces;i++){
        pieces[i]->setImage();
    }
}

void Box::display(){
    setfillstyle(SOLID_FILL,color);
    bar(y*BOX_SIZE,x*BOX_SIZE,y*BOX_SIZE+BOX_SIZE,x*BOX_SIZE+BOX_SIZE);
    if(checkSet()){
        piece->display();
    }
}


void Box::display(COLORREF clr){
    setfillstyle(SOLID_FILL,clr);
    bar(y*BOX_SIZE,x*BOX_SIZE,y*BOX_SIZE+BOX_SIZE,x*BOX_SIZE+BOX_SIZE);
    if(checkSet()){
        piece->display();
    }
}


void Board::setArena(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            boxes[i][j].display();
        }
    }
    setfillstyle(SOLID_FILL,COLOR(0, 0, 0));
    bar(640,0,1000,640);
    setfillstyle(SOLID_FILL,COLOR(250,250,250));
    bar(640 + 5,0 + 5,1000 - 5,640 - 5);
    setfillstyle(SOLID_FILL,COLOR(45,45,45));
    bar(640 + 7,0 + 7,1000 - 7,640 - 7);
    // Setting up upper box;
    drawRoundedBox(660,20,320,180,12,COLOR(130, 209, 152),COLOR(53, 8, 94),4);
    drawRoundedBox(663,23,314,174,12,COLOR(130, 209, 152),COLOR(6, 77, 13),4);
    drawRoundedBox(666,26,308,168,12,COLOR(130, 209, 152),COLOR(74, 5, 35),3);
    // Setting up pieces box;
    drawRoundedBox(660,210,320,140,12,COLOR(130, 209, 152),COLOR(53, 8, 94),4);
    // Setting up Instruction box;
    drawRoundedBox(660,360,320,260,12,COLOR(250, 247, 227),COLOR(53, 8, 94),3);

    // Proper setting boxes;
    // char name[80];strcpy(name,p1.getName().c_str());
    // char clr[80];strcpy(clr,p1.getColor().c_str()); 
    setUpperBox();
    setPiecesBox();
    setInstructionBox((char*)"Press Enter to",(char*)"Start Game!");
}

void Piece::showMovements(){
    string other;
    if(board->turn == &board->p1){
        other = "Black";
    }else{
        other = "White";
    }
    for(int i=0;i<totalMovements;i++){
        if(board->getBox(movements[i].x,movements[i].y)->checkSet()){
            if(board->getBox(movements[i].x,movements[i].y)->getPiece()->color == other){
                board->getBox(movements[i].x,movements[i].y)->display(COLOR(240,155,98));
                continue;
            }
        }
        board->getBox(movements[i].x,movements[i].y)->display(COLOR(155, 240, 98));
    }
}

void Piece::muteMovements(){
    for(int i=0;i<totalMovements;i++){
        board->getBox(movements[i].x,movements[i].y)->display();
    }
}

void Board::makeMove(int x1,int y1,int x2,int y2,int currentPiece){
    if(!getBox(x2,y2)->checkSet()){
        getBox(x2,y2)->setPiece(getBox(x1,y1)->getPiece());
        getBox(x1,y1)->getPiece()->updatePosition(x2,y2);
        getBox(x1,y1)->setEmpty();
    }
    else if(getBox(x1,y1)->getPiece()->getColor()!=getBox(x2,y2)->getPiece()->getColor()){
        if(getBox(x2,y2)->getPiece()->getName()=="king"){
            win = true;
        }
        if(turn==&p1){
            p2.removePiece(*getBox(x2,y2)->getPiece());
        }else{
            p1.removePiece(*getBox(x2,y2)->getPiece());
        }
        getBox(x2,y2)->setPiece(getBox(x1,y1)->getPiece());
        getBox(x1,y1)->getPiece()->updatePosition(x2,y2);
        getBox(x1,y1)->setEmpty();
    }else{
        cout<<"Error::In Make Move Function";exit(0);
    }
    if(turn==&p1 && getBox(x2,y2)->getPiece()->getName()=="pawn" && y2 == 7){
        p1.pawnPromotion(currentPiece);
        setUpArena();
        setArena();
    }
    else if(turn==&p2 && getBox(x2,y2)->getPiece()->getName()=="pawn" && y2 == 0){
        p2.pawnPromotion(currentPiece);
        setUpArena();
        setArena();
    }
}

void Player::removePiece(Piece& p){
    int idx = -1;
    for(int i=0;i<totalPieces;i++){
        if(pieces[i]->getX()== p.getX() && pieces[i]->getY() == p.getY()){
            idx = i;break;
        }
        if(i == totalPieces -1){
            cout<<"Error:: Piece was not Found in removePiece!";exit(-1);
        }
    }
    Piece* todelete = pieces[idx];
    for(int i=idx;i<totalPieces-1;i++){
        pieces[i] = pieces [i+1];
    }
    totalPieces--;
    delete todelete;
}


