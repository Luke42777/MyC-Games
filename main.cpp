/*that is simple console snake game showing screen game in loops, player will be asked to change postion of snake to reach fruit, 
when fruit reached- tail length is increased,there is no win the game option, player needs to reach maximum score before gameover
gameover happens when head touches one of tail element
*/




#include <iostream>
#include <string>
#include <conio.h> // to get output from player
#include <windows.h>
#include "SGame.h"


using int32 = int;
using Ftext = std::string;


void PlayGame();
bool AskToPlayAgain();


FSnakeGame SGame; //instance of the game


//*************************************************************************************************
int main()
{
	do
	{
		SGame.Reset();
		PlayGame();
		SGame.bAskToPlayAgain = AskToPlayAgain();
	}
	while (SGame.bAskToPlayAgain);
	return 0;
}
//*************************************************************************************************

void PlayGame()
	{
		while (!SGame.GetIfGameOver())
		{

			SGame.Draw();
			SGame.Input(); 
			SGame.Logic();

			Sleep(SGame.GetSpeed());
		}
		return;
	}



//**************************************************************************************************
bool  AskToPlayAgain()
	{

		std::cout << "\nDo you wanna play again (y/n)? ";
		Ftext Response;
		std::cin >> Response;

		return ((Response[0] == 'Y') || (Response[0] == 'y'));


	}
//****************************************************************************************************


