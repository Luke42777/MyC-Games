#pragma once
#include <iostream>
#include <string>
#include <conio.h> // to get output from player (function _kbhit and _getchar)


using int32 = int;
using Fstring = std::string;

enum class EDirection { STOP, RIGHT, LEFT, UP, DOWN };

class FSnakeGame
{

public:

	FSnakeGame() //constructor inside Reset function called
	{
		Reset();

	}
	//******************member functions
	void Reset();
	
	void Draw() const;
	void Input();
	void Logic();
	

	bool bAskToPlayAgain;
	bool GetIfGameOver();
	int32 GetSpeed();

	
	
private:
	const int Width = 20;
	const int Height = 20;
	

	int32 X,Y;
	int32 FruitX, FruitY;
	
	int32 Score;
	int32 aTailX[100], aTailY[100]; 
	int32 TailLength;

	bool bGameOver;
	int  Speed;


};