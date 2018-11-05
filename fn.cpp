#include "fn.h"

using namespace std;
int point=0;
char world[SIZE][SIZE];
queue<int> snake[2];

bool kbhit(){
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

void reset(){
    point=0;
    while(snake[0].size()>0){
        snake[0].pop();
    }
    while(snake[1].size()>0){
        snake[1].pop();
    }
    snake[0].push(SIZE/2);
    snake[1].push(SIZE/2);
}

void draw(){//畫牆
    for(int y=0;y<SIZE;++y){
        world[y][0]='|';
        world[y][SIZE-1]='|';
    }
    for(int x=0;x<SIZE;++x){
        world[0][x]='-';
        world[SIZE-1][x]='-';
    }
    world[0][0]='*';
    world[SIZE-1][0]='*';
    world[0][SIZE-1]='*';
    world[SIZE-1][SIZE-1]='*';
    world[snake[1].back()][snake[0].back()]='@';
    food();
}

void nextmove(int d){//下個動作
    switch(d){
        case 1:
            snake[0].push(snake[0].back()+1);
            snake[1].push(snake[1].back());
            if(die(snake[0].back(),snake[1].back())){
                lose();
            }else if(world[snake[1].back()][snake[0].back()]=='.'){
                point++;
                food();
            }else{
                world[snake[1].front()][snake[0].front()]=' ';
                snake[0].pop();
                snake[1].pop();
            }
            break;
        case 2:
            snake[0].push(snake[0].back());
            snake[1].push(snake[1].back()+1);
            if(die(snake[0].back(),snake[1].back())){
                lose();
            }else if(world[snake[1].back()][snake[0].back()]=='.'){
                point++;
                food();
            }else{
                world[snake[1].front()][snake[0].front()]=' ';
                snake[0].pop();
                snake[1].pop();
            }
            break;
        case 3:
            snake[0].push(snake[0].back()-1);
            snake[1].push(snake[1].back());
            if(die(snake[0].back(),snake[1].back())){
                lose();
            }else if(world[snake[1].back()][snake[0].back()]=='.'){
                point++;
                food();
            }else{
                world[snake[1].front()][snake[0].front()]=' ';
                snake[0].pop();
                snake[1].pop();
            }
            break;
        case 4:
            snake[0].push(snake[0].back());
            snake[1].push(snake[1].back()-1);
            if(die(snake[0].back(),snake[1].back())){
                lose();
            }else if(world[snake[1].back()][snake[0].back()]=='.'){
                point++;
                food();
            }else{
                world[snake[1].front()][snake[0].front()]=' ';
                snake[0].pop();
                snake[1].pop();
            }
            break;
    }
    world[snake[1].back()][snake[0].back()]='@';
}

void food(){
    while(1){
        srand(time(NULL));
        int x=(rand()%(SIZE-2))+1,y=(rand()%(SIZE-2))+1;
        if(world[y][x]!='@'){
            world[y][x]='.';
            break;
        }
    }
}

void frame(){
    system("clear");
    string output;
    output.clear();
    for(int y=0;y<SIZE;++y){
        output+=(string(world[y],16)+"\n");
    }
    cout<<output;
    cout<<"point:"<<point<<"point(s)"<<endl;
    cout<<"level:"<<(point/5)+1<<endl;
}

bool die(int x,int y){
    if(x<=0||y<=0||x>=SIZE-1||y>=SIZE-1){
        return 1;
    }else if(!(x==snake[0].front()&&y==snake[1].front())){
        if(world[y][x]=='@'){
            return 1;
        }
    }
    return 0;
}

void lose(){
    memset(world,0,sizeof(world));
    system("clear");
    cout<<"-----you lose-----"<<endl;
    reset();
    draw();
    system("sleep 1000000");
}

int return_point(){
    return point;
}
