// It will contain the game Loop functions;
#include "majorFunctions.h"

void Board::gameLoop(){

    bool Exit = false, Enter = true, SelectPiece = true, SelectMovement = false;

    turn = &p1;

    COORDS prevPosition;

    int currentPiece = 0, currentMovement = 0, oldPiece = 0, oldMovement = 0;

    focus = getBox(turn->getPiece(currentPiece)->getX(),turn->getPiece(currentPiece)->getY());

    turn->getPiece(currentPiece)->updateMovements();

    turn->getPiece(currentPiece)->showMovements();

    if(turn->getPiece(currentPiece)->getTotalMoves()>0){
        focus->display(COLOR(245, 221, 115));
        Enter = true;
    }else{
        focus->display(COLOR(90, 90, 90));
        Enter = false;
    }

    char displayName[20], displayColor[20];

    stringToChar(displayName,turn->getName());
    stringToChar(displayColor,turn->getColor());

    setUpperBox(displayName,displayColor);

    if(Enter){
        setInstructionBox((char*)"Press Enter to", (char*)"select current Piece!");
    }else{
        setInstructionBox((char*)"You can not select", (char*)"current Piece!", (char*)"because it does not", (char*)"movements available!");
    }

    while(!getWin() && !getDraw()){

        if(kbhit()){

            char ch = getch();

            focus->display();

            if(ch == 27){

                setInstructionBox((char*)"Do you really",(char*)"want to EXIT this",(char*)"game?",(char*)"Press P to Exit.",(char*)"To Abort press C.");
                Exit=true;

            }

            if(( ch == 'p' || ch == 'P' ) && Exit){

                break; //  Pathway to Exit!

            }

            if(( ch == 'c' || ch == 'C') && Exit){

                Exit = false; //  User Changed his mind;

            }

            if(ch == 72  ||  ch == 75 || ch == 'w' || ch == 'a' || ch == 'W' || ch == 'A'){

                if(SelectMovement){

                    oldMovement = currentMovement;
                    if(currentMovement>0){
                        currentMovement--;
                    }else if(currentMovement == 0){
                        currentMovement = turn->getPiece(currentPiece)->getTotalMoves() - 1;
                    }

                }else if(SelectPiece){

                    oldPiece = currentPiece;
                    if(currentPiece > 0){
                        currentPiece--;
                    }else if(currentPiece == 0){
                        currentPiece = turn->getTotalpieces() - 1;
                    }

                }
                PlaySound(TEXT("sounds/movement.wav"),NULL,SND_SYNC);

            }

            if(ch == 77 || ch == 80 || ch == 's' || ch == 'S' || ch == 'd' || ch == 'D'){

                if(SelectMovement){

                    oldMovement = currentMovement;
                    if(currentMovement < turn->getPiece(currentPiece)->getTotalMoves() - 1){
                        currentMovement++;
                    }else if(currentMovement == turn->getPiece(currentPiece)->getTotalMoves() - 1){
                        currentMovement = 0;
                    }

                }else if(SelectPiece){

                    oldPiece = currentPiece;
                    if(currentPiece < turn->getTotalpieces()-1){
                        currentPiece++;
                    }else if(currentPiece == turn->getTotalpieces()-1){
                        currentPiece = 0;
                    }

                }
                PlaySound(TEXT("sounds/movement.wav"),NULL,SND_SYNC);

            }

            if(ch == 13){

                if(!Enter){
                    // Making Him Clear that He can not Select this particular item.
                    setInstructionBox((char*)"I am really Sorry",(char*)"You can not Select",(char*)"it beacuse somehow it",(char*)"is not supposed to",(char*)"be Valid.");
                    focus->display(COLOR(90, 90, 90));

                }

                if(Enter){

                    if(SelectPiece){

                        prevPosition.x = focus->getX();
                        prevPosition.y = focus->getY();

                        SelectPiece = false;
                        SelectMovement = true;

                        currentMovement = 0;

                        COORDS* m = turn->getPiece(currentPiece)->getMovement(currentMovement);
                        focus = getBox(m->x,m->y);

                        focus->display(COLOR(245, 221, 115));

                        setInstructionBox((char*)"Press ENTER to",(char*)"select a Movement!",(char*)"And make an",(char*)"Excelent Move.");

                    }else if(SelectMovement){

                        SelectMovement = false;
                        SelectPiece = true;

                        makeMove(prevPosition.x,prevPosition.y,focus->getX(),focus->getY(),currentPiece);

                        getBox(prevPosition.x,prevPosition.y)->display();

                        if(getWin()|| getDraw()){
                            goto END_OF_GAME;
                        }

                        Piece* oldPiece = turn->getPiece(currentPiece);

                        currentPiece = 0;
                        currentMovement = 0;
                        COORDS m ;
                        if(turn == &p1){
                            turn = &p2;
                            m.x = p2.getPiece(currentPiece)->getX();
                            m.y = p2.getPiece(currentPiece)->getY();
                        }else{
                            turn = &p1;
                            m.x = p1.getPiece(currentPiece)->getX();
                            m.y = p1.getPiece(currentPiece)->getY();
                        }

                        oldPiece->muteMovements();

                        focus = getBox(m.x,m.y);

                        turn->getPiece(currentPiece)->updateMovements();

                        turn->getPiece(currentPiece)->showMovements();

                        if(turn->getPiece(currentPiece)->getTotalMoves()>0){
                            focus->display(COLOR(245, 221, 115));
                            Enter = true;
                        }else{
                            focus->display(COLOR(90, 90, 90));
                            Enter = false;
                        }

                        stringToChar(displayName,turn->getName());
                        stringToChar(displayColor,turn->getColor());

                        setUpperBox(displayName,displayColor);

                        setPiecesBox(p1.getTotalpieces(),p2.getTotalpieces());

                        setInstructionBox((char*)"Press ENTER to",(char*)"select a Piece!");

                    }

                    continue;

                }

            }

            if((ch == 72  ||  ch == 75 || ch == 'w' || ch == 'a' || ch == 'W' || ch == 'A'|| ch == 77 || ch == 80 || ch == 's' || ch == 'S' || ch == 'd' || ch == 'D')&& (!Exit)){

                if(SelectPiece){

                    turn->getPiece(oldPiece)->muteMovements();

                    focus = getBox(turn->getPiece(currentPiece)->getX(),turn->getPiece(currentPiece)->getY());

                    // turn->getPiece(currentPiece)->updateMovements();
                    focus->getPiece()->updateMovements();

                    // turn->getPiece(currentPiece)->showMovements();
                    focus->getPiece()->showMovements();

                    if(turn->getPiece(currentPiece)->getTotalMoves()>0){
                        focus->display(COLOR(245, 221, 115));
                        Enter = true;
                    }else{
                        focus->display(COLOR(90, 90, 90));
                        Enter = false;
                    }

                }else if(SelectMovement){

                    COORDS* m = turn->getPiece(currentPiece)->getMovement(oldMovement);
                    getBox(m->x,m->y)->display();

                    turn->getPiece(currentPiece)->showMovements();

                    m = turn->getPiece(currentPiece)->getMovement(currentMovement);
                    focus = getBox(m->x,m->y);

                    focus->display(COLOR(245, 221, 115));

                }

            }

        }else{
            Sleep(100);
        }

    }

    END_OF_GAME:

    if(getWin()){
        stringToChar(displayName,turn->getName());
        setInstructionBox((char*)"CONGRATS !",displayName,(char*)"is the Winner",(char*)"of this game.");
    }
    // If it was a draw;
    if(getDraw()){
        setInstructionBox((char*)"GREAT GAME BOYS !",(char*)"Both of you",(char*)"tried well",(char*)"But it is a",(char*)"DRAW !");
    }

}
