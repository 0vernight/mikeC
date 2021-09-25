//#pragma once
#ifndef _SNACKE_H_
#define _SNACKE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>		//¹â±ê
#include <Windows.h>


#define WIDE 60
#define HIGH 25

struct Body
{
	int x;
	int y;
};
struct SNACKE
{
	int size;
	struct Body body[10];
}snacke;
struct FOOD
{
	int x;
	int y;
}food;


void initSnacke(void);
void initUI(void);
void initFood(void);
void startGame(void);
void initWall(void);
#endif // !_SNACKE_H_

