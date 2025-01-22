// This file will contain the main function of the game;
#include"introFunc.h"

int main(){
    initwindow(WIDTH,HEIGHT,(char*)"CHESS : Game Of Mind");
    string exitStatus = "no";
    welcome();
START_OF_GAME:
    string whiteName,blackName;
    clearBackground();
    Sleep(100);
    whiteName = takeUser((char*)"Enter name for white:");
    blackName = takeUser((char*)"Enter name for black:");
    mode = takeMode();
    setUpArena();
    Board board(whiteName,blackName);
    board.setBoard();
    board.setArena();
    board.gameLoop();



    Sleep(5000);
    exitStatus = takeExit();
    if(exitStatus=="no"){
        goto START_OF_GAME;
    }
    getch();
    closegraph();
    return 0;
}
