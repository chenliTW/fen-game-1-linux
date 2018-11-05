#include<ncurses.h>

#include "fn.h"

int main(){
    reset();
    draw();
    food();
    int direction=1;
    while(1){
        frame();
        for(int time=0;time<10-(return_point()/5);++time){
            if (kbhit()){
                char ch = getchar();
                switch((int)ch){
                    case 100:
                        direction=1;
                        break;
                    case 115:
                        direction=2;
                        break;
                    case 97:
                        direction=3;
                        break;
                    case 119:
                        direction=4;
                        break;
                }
            }
            system("sleep 0.001");
        }
        nextmove(direction);
    }
    return 0;
}
