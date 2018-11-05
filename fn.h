#ifndef FN_H_INCLUDED
#define FN_H_INCLUDED

#include<string.h>
#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<queue>
#include<time.h>
#include<stdlib.h>

#include <termios.h>
#include <sys/ioctl.h>

#define SIZE 12

bool kbhit();
void reset();
void draw();
void frame();
void food();
void nextmove(int d);
bool die(int x,int y);
void lose();
int return_point();

#endif // FN_H_INCLUDED
