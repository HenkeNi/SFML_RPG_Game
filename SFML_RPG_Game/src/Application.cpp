#include "Game.h"

#include <iostream>


/*
*	Consider:
*		Implementing a Scene Graph (objects belogns to their parents)
* 
*	Changes:
*		Rather than having RenderWindow in State; pass it in all the way?? - maybe bad idea!?
* 
*	TODO:
*		Fix so you can change keys and it will still work...
* 
*		Splash State... in update (After x seconds => go to MainMenuState)
*		ResourceManager....
* 
*		
*		Have GameState bottom, then push and pop the menustate over it??
* 
* 
*		
*		If you are at PauseStaet and chose Main Menu, (push it on top?), menu should update with continue (chech how many states in
*		stack? or check if any game saved?)
* 
*/

int main()
{
	try
	{
		Game game;
		game.run();	
	}
	catch (...)
	{
		std::cerr << "Unexpected error. Program terminating\n";
	}

	return 0;
}