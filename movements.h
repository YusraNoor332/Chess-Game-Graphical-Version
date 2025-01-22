// This file will contain the movement definations taken from class Objects;
#include"staleMate.h"

void Piece::updateMovements(){}
void King::updateMovements(){
    totalMovements=0;
    string clr = board->turn->getColor();
    int x = board->focus->getX();
    int y = board->focus->getY();
    if((x+1>=0 && x+1<8) && (y>=0 && y<8)){
        if(!board->getBox(x+1,y)->checkSet()){
            movements[totalMovements].x =x+1;
            movements[totalMovements++].y =y;
        }
        else if(board->getBox(x+1,y)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x+1;
            movements[totalMovements++].y =y;
        }
    }
    if((x+1>=0 && x+1<8) && (y+1>=0 && y+1<8)){
        if(!board->getBox(x+1,y+1)->checkSet()){
            movements[totalMovements].x =x+1;
            movements[totalMovements++].y =y+1;
        }
        else if(board->getBox(x+1,y+1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x+1;
            movements[totalMovements++].y =y+1;
        }
    }
    if((x>=0 && x<8) && (y+1>=0 && y+1<8)){
        if(!board->getBox(x,y+1)->checkSet()){
            movements[totalMovements].x =x;
            movements[totalMovements++].y =y+1;
        }
        else if(board->getBox(x,y+1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x;
            movements[totalMovements++].y =y+1;
        }
    }
    if((x>=0 && x<8) && (y-1>=0 && y-1<8)){
        if(!board->getBox(x,y-1)->checkSet()){
            movements[totalMovements].x =x;
            movements[totalMovements++].y =y-1;
        }
        else if(board->getBox(x,y-1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x;
            movements[totalMovements++].y =y-1;
        }
    }
    if((x-1>=0 && x-1<8) && (y-1>=0 && y-1<8)){
        if(!board->getBox(x-1,y-1)->checkSet()){
            movements[totalMovements].x =x-1;
            movements[totalMovements++].y =y-1;
        }
        else if(board->getBox(x-1,y-1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x-1;
            movements[totalMovements++].y =y-1;
        }
    }
    if((x-1>=0 && x-1<8) && (y>=0 && y<8)){
        if(!board->getBox(x-1,y)->checkSet()){
            movements[totalMovements].x =x-1;
            movements[totalMovements++].y =y;
        }
        else if(board->getBox(x-1,y)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x-1;
            movements[totalMovements++].y =y;
        }
    }
    if((x+1>=0 && x+1<8) && (y-1>=0 && y-1<8)){
        if(!board->getBox(x+1,y-1)->checkSet()){
            movements[totalMovements].x =x+1;
            movements[totalMovements++].y =y-1;
        }
        else if(board->getBox(x+1,y-1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x+1;
            movements[totalMovements++].y =y-1;
        }
    }
    if((x-1>=0 && x-1<8) && (y+1>=0 && y+1<8)){
        if(!board->getBox(x-1,y+1)->checkSet()){
            movements[totalMovements].x =x-1;
            movements[totalMovements++].y =y+1;
        }
        else if(board->getBox(x-1,y+1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x =x-1;
            movements[totalMovements++].y =y+1;
        }
    }
}
void Queen::updateMovements(){
    totalMovements=0;
    int x = board->focus->getX();
    int y = board->focus->getY();
    string clr = board->turn->getColor();
    // For right side;
    for(int i=y+1;i<8;i++){
        if(!board->getBox(x,i)->checkSet()){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
        }
        else if(board->getBox(x,i)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
            if(board->getBox(x,i)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For left side;
    for(int i=y-1;i>=0;i--){
        if(!board->getBox(x,i)->checkSet()){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
        }
        else if(board->getBox(x,i)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
            if(board->getBox(x,i)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For up side;
    for(int i=x-1;i>=0;i--){
        if(!board->getBox(i,y)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
        }
        else if(board->getBox(i,y)->getPiece()->getColor()!= clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
            if(board->getBox(i,y)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For down side;
    for(int i=x+1;i<8;i++){
        if(!board->getBox(i,y)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
        }
        else if(board->getBox(i,y)->getPiece()->getColor()!= clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
            if(board->getBox(i,y)->checkSet()){
                break;
            }
        }
        else{
            break;
        }
    }
    // For left-top diagonal;
    int i=x,j=y;
    while(i>0&&j>0){
        i--;j--;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For right-top diagonal;
    i=x,j=y;
    while(i>0&&j<7){
        i--;j++;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For right-bottom diagonal;
    i=x,j=y;
    while(i<7&&j<7){
        i++;j++;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For left-bottom diagonal;
    i=x,j=y;
    while(i<7&&j>0){
        i++;j--;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
}
void Bishop::updateMovements(){
    totalMovements=0;
    int x = board->focus->getX();
    int y = board->focus->getY();
    string clr = board->turn->getColor();
    // For left-top diagonal;
    int i=x,j=y;
    while(i>0&&j>0){
        i--;j--;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For right-top diagonal;
    i=x,j=y;
    while(i>0&&j<7){
        i--;j++;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For right-bottom diagonal;
    i=x,j=y;
    while(i<7&&j<7){
        i++;j++;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For left-bottom diagonal;
    i=x,j=y;
    while(i<7&&j>0){
        i++;j--;
        if(!board->getBox(i,j)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
        }
        else if(board->getBox(i,j)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = j;
            if(board->getBox(i,j)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
}
void Rook::updateMovements(){
    totalMovements=0;
    int x = board->focus->getX();
    int y = board->focus->getY();
    string clr = board->turn->getColor();
    // For right side;
    for(int i=y+1;i<8;i++){
        if(!board->getBox(x,i)->checkSet()){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
        }
        else if(board->getBox(x,i)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
            if(board->getBox(x,i)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For left side;
    for(int i=y-1;i>=0;i--){
        if(!board->getBox(x,i)->checkSet()){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
        }
        else if(board->getBox(x,i)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x;
            movements[totalMovements++].y = i;
            if(board->getBox(x,i)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For up side;
    for(int i=x-1;i>=0;i--){
        if(!board->getBox(i,y)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
        }
        else if(board->getBox(i,y)->getPiece()->getColor()!= clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
            if(board->getBox(i,y)->checkSet()){
                break;
            }
        }else{
            break;
        }
    }
    // For down side;
    for(int i=x+1;i<8;i++){
        if(!board->getBox(i,y)->checkSet()){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
        }
        else if(board->getBox(i,y)->getPiece()->getColor()!= clr){
            movements[totalMovements].x = i;
            movements[totalMovements++].y = y;
            if(board->getBox(i,y)->checkSet()){
                break;
            }
        }
        else{
            break;
        }
    }
}
void Knight::updateMovements(){
    totalMovements=0;
    int x = board->focus->getX();
    int y = board->focus->getY();
    string clr = board->turn->getColor();
    if((x+1>=0 && x+1<8) && (y+2>=0&&y+2<8)){
        if(!board->getBox(x+1,y+2)->checkSet()){
            movements[totalMovements].x = x+1;
            movements[totalMovements++].y = y+2;
        }
        else if(board->getBox(x+1,y+2)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x+1;
            movements[totalMovements++].y = y+2;
        }
    }
    if((x+1>=0 && x+1<8) && (y-2>=0&&y-2<8)){
        if(!board->getBox(x+1,y-2)->checkSet()){
            movements[totalMovements].x = x+1;
            movements[totalMovements++].y = y-2;
        }
        else if(board->getBox(x+1,y-2)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x+1;
            movements[totalMovements++].y = y-2;
        }
    }
    if((x-1>=0 && x-1<8) && (y+2>=0&&y+2<8)){
        if(!board->getBox(x-1,y+2)->checkSet()){
            movements[totalMovements].x = x-1;
            movements[totalMovements++].y = y+2;
        }
        else if(board->getBox(x-1,y+2)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x-1;
            movements[totalMovements++].y = y+2;
        }
    }
    if((x-1>=0 && x-1<8) && (y-2>=0&&y-2<8)){
        if(!board->getBox(x-1,y-2)->checkSet()){
            movements[totalMovements].x = x-1;
            movements[totalMovements++].y = y-2;
        }
        else if(board->getBox(x-1,y-2)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x-1;
            movements[totalMovements++].y = y-2;
        }
    }
    if((x+2>=0 && x+2<8) && (y+1>=0&&y+1<8)){
        if(!board->getBox(x+2,y+1)->checkSet()){
            movements[totalMovements].x = x+2;
            movements[totalMovements++].y = y+1;
        }
        else if(board->getBox(x+2,y+1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x+2;
            movements[totalMovements++].y = y+1;
        }
    }
    if((x+2>=0 && x+2<8) && (y-1>=0&&y-1<8)){
        if(!board->getBox(x+2,y-1)->checkSet()){
            movements[totalMovements].x = x+2;
            movements[totalMovements++].y = y-1;
        }
        else if(board->getBox(x+2,y-1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x+2;
            movements[totalMovements++].y = y-1;
        }
    }
    if((x-2>=0 && x-2<8) && (y+1>=0&&y+1<8)){
        if(!board->getBox(x-2,y+1)->checkSet()){
            movements[totalMovements].x = x-2;
            movements[totalMovements++].y = y+1;
        }
        else if(board->getBox(x-2,y+1)->getPiece()->getColor() !=clr && (x-2>=0 && x-2<8) && (y+1>=0&&y+1<8)){
            movements[totalMovements].x = x-2;
            movements[totalMovements++].y = y+1;
        }
    }
    if((x-2>=0 && x-2<8) && (y-1>=0&&y-1<8)){
        if(!board->getBox(x-2,y-1)->checkSet()){
            movements[totalMovements].x = x-2;
            movements[totalMovements++].y = y-1;
        }
        else if(board->getBox(x-2,y-1)->getPiece()->getColor() !=clr){
            movements[totalMovements].x = x-2;
            movements[totalMovements++].y = y-1;
        }
    }
}
void Pawn::updateMovements(){
    totalMovements=0;
    int x = board->focus->getX();
    int y = board->focus->getY();
    string clr = board->turn->getColor();
    string otherPlayer = (clr=="White")?"Black":"White";
    if(clr == "White"){
    // White pawns can only move from left to right;
        // There are only two movements available for pawn i.e. one or two steps;
        for(int i=1;i<=2;i++){
            if(!board->getBox(x,y+1)->checkSet()){
                if(board->getBox(x,y+i)->checkSet()){
                    break;
                }
                movements[totalMovements].x = x;
                movements[totalMovements++].y = y+i;
            }else{
                break;
            }
        }
        // If there is an enemy ahead on right and left;
        if(board->getBox(x-1,y+1)->checkSet() && (x-1>=0 && x-1<8) && (y+1>=0&&y+1<8)){
            if(board->getBox(x-1,y+1)->getPiece()->getColor()==otherPlayer && (x-1>=0 && x-1<8) && (y+1>=0&&y+1<8)){
                movements[totalMovements].x = x-1;
                movements[totalMovements++].y = y+1;
            }
        }
        if(board->getBox(x+1,y+1)->checkSet() && (x+1>=0 && x+1<8) && (y+1>=0&&y+1<8)){
            if(board->getBox(x+1,y+1)->getPiece()->getColor()==otherPlayer && (x+1>=0 && x+1<8) && (y+1>=0&&y+1<8)){
                movements[totalMovements].x = x+1;
                movements[totalMovements++].y = y+1;
            }
        }
    } 
    else{
    // Black pawns can move from right to left;
        // There are only two movements available for pawn i.e. one or two steps;
        for(int i=1;i<=2;i++){
            if(!board->getBox(x,y-i)->checkSet()){
                if(board->getBox(x,y-i)->checkSet()){
                    break;
                }
                movements[totalMovements].x = x;
                movements[totalMovements++].y = y-i;
            }else{
                break;
            }
        }
        // If there is an enemy ahead on right and left;
        if(board->getBox(x-1,y-1)->checkSet() && (x-1>=0 && x-1<8) && (y-1>=0&&y-1<8)){
            if(board->getBox(x-1,y-1)->getPiece()->getColor()==otherPlayer && (x-1>=0 && x-1<8) && (y-1>=0&&y-1<8)){
                movements[totalMovements].x = x-1;
                movements[totalMovements++].y = y-1;
            }
        }
        if(board->getBox(x+1,y-1)->checkSet() && (x+1>=0 && x+1<8) && (y-1>=0&&y-1<8)){
            if(board->getBox(x+1,y-1)->getPiece()->getColor()==otherPlayer && (x+1>=0 && x+1<8) && (y-1>=0&&y-1<8)){
                movements[totalMovements].x = x+1;
                movements[totalMovements++].y = y-1;
            }
        }
    }
}