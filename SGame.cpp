#pragma once
#include "SGame.h"
//**********************************************************************


EDirection Direction;
//**********************************************************************
bool FSnakeGame::GetIfGameOver() { return bGameOver; }
int32 FSnakeGame::GetSpeed(){ return Speed; }

//**********************************************************************
void FSnakeGame::Draw() const
{

	system("cls"); //system("clear");
	for (int i = 0; i < Width + 2; i++)
		{
			std::cout << "#";
		}
	
	std::cout << std::endl;

	for (int i = 0; i < Height; i++)
	{
			for (int j = 0; j < Width; j++)
			{
				if (j == 0)
					std::cout << "#";

				if (i == Y && j == X)
					std::cout << "O";

				else if (i == FruitY && j == FruitX)
					std::cout << "F";

				else
					{
						bool Print = false;

						for (int k = 0; k < TailLength; k++)
						{
							if (aTailX[k] == j && aTailY[k] == i)
							{
								std::cout << "o";
								Print = true;
							}
						}

						if (!Print)
							std::cout << " "; // if no Tail element printed use white space
					}


				if (j == Width - 1)
					std::cout << "#";
			}

		std::cout << std::endl;
		
	}

	for (int i = 0; i < Width + 2; i++)
		{
			std::cout << "#";
		}
		
	std::cout << std::endl;
	std::cout << "\nUse WSAD to move SNAKE\n\n";
	std::cout << "\n      SCORE:" << Score << std::endl;

}

//************************************************************************************
void FSnakeGame::Logic()
{
	for (int32 i = TailLength; i > 0; i--) // loop is operating if TailLength incremented
		{
			aTailX[i] = aTailX[i - 1];
			aTailY[i] = aTailY[i - 1];
		}


	aTailX[0] = X;     //previous position of snake's HEAD will be postion for firs element of TAIL
	aTailY[0] = Y;



	switch (Direction)
		{

		case EDirection::LEFT:
			X--;              //left snake movement
			break;

		case EDirection::RIGHT:
			X++;
			break;

		case EDirection::UP:
			Y--;
			break;

		case EDirection::DOWN:
			Y++;
			break;


		default:
			break;
		}

	// touching border solutions
	if (X < 0)
		{
			X = (Width - 1); // if snake reaches left border I want new position to be on the other side of screen

		}

	if (X > (Width - 1)) // if snake reaches right border I want new position to be on the other side of screen

		{
			X = 0;
		}


	if (Y < 0)    //similar to RIGHT and LEFT
		{
			Y = (Height - 1);

		}

	if (Y > (Height - 1)) //similar to RIGHT and LEFT

		{
			Y = 0;
		}

	//collision when snak's HEAD and one element of TAIL have same position
	for (int j = 0; j < TailLength; j++)  
	{
		if ((Y == aTailY[j]) && (X == aTailX[j]))
		{
			bGameOver = true;
		}
	}


	// Scoring system 
	if ((X == FruitX) && (Y == FruitY)) 
	{
		Score += 1;

		FruitX = rand() % Width;
		FruitY = rand() % Height;

		TailLength++; //increment snake length (add element to tail)

		Speed -= 20;  //speed up after score (lower value speed up) by decrementation sleep time

		if (Speed <= 0)
		{
			Speed = 0; //prevents Speed to be less than  0, function sleep dosn't like it
		}
		
	}
	


}
//**********************************************************************
void FSnakeGame::Reset()
{
	
	int32 X = Width / 2;
	int32 Y = Height / 2;
	FruitX = rand() % Width;
	FruitY = rand() % Height;
	Score = 0;
	bGameOver = false;
	TailLength = 0;
	Speed = 150;

}
//************************************************************************
void FSnakeGame::Input()
{


	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			Direction = EDirection::LEFT;
			break;
		case 'd':
			Direction = EDirection::RIGHT;
			break;
		case 'w':
			Direction = EDirection::UP;
			break;
		case 's':
			Direction = EDirection::DOWN;
			break;
		case 'p':
			bGameOver = true;
			break;
		}
	}
}
