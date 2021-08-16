#include "Game.h"

#include <iostream>


/*
*	In Rendering -> fetch collisionBox shape from Collider??? if need to draw
* 
* 
*	Rename components: Collidable, Renderable, Moveable`??
*	
*	All components contains an entityid?? used to fetch components?? - or maybe a pointer to parent (Entity/Game_object)
*	
*	SceneNodes?? - collision is child of player?? 
* 
* 
*	TODO:
* 
*	- Collision (pushing objects??)	
*	- Camera following player?
*	- game objects gets spawned or tile map??
* 
* 
*	Communication between components:
*		
*		- use friend functios and/or friend functions instead of aggregation (pointers and reference to other classes)
* 
* 
*	Render Object:
*	
*		Instead of having multiple tree objects -> have one tree object but store multiple position it gets rendered at???
* 
*	Entity Management:
* 
*		1) Implement ESC (Entity component system)
* 
*		2) Component_esc Pattern	
*			Entity contains a map of Components (or, maybe worse, it contains struct that contains pointers to all the differetn components, 
*			like a context class - if a Entity doesn't need specific component it is nullptr)
*	
*		3) worst; inheritance way
* 
* 
*	Animations
*		in movement => use/set states like idle_down, walking_left instead?? and then in animation => fetch state and dispaly animation.
*		maybe use struct to pass possible states to movement??
* 
*	Consider:
*		Implementing a Scene Graph (objects belogns to their parents)
* 
*	Changes:
*		Rather than having RenderWindow in State; pass it in all the way?? - maybe bad idea!?
* 
*	TODO:
*		- make windwo and mouse classes
* 
*		- Player is not a class; instead there exist an input component that responds to key commands??
* 
*		- try to automate pointer/reference assignment in components (if not found -> try to fetch from entity??)
* 
*		- Some classe; like window, should accept a string and then read all the data from a file!
* 
*		- Fix so you can change keys and it will still work...
* 
*		- Can close the game
* 
*		(Manual z-ordering??)
*		- FIx so when character runs infront of objects, character renders infront, and when running behind, character renders behind the object
*			check if bottom of player sprite is larger than bottom of object sprite, if it's the render player infront			
* 
* 
*		- can resume after pause, 
* 
*		- FIx; entity update key bindings...
* 
*		- set mouse to hand when hovering over button (sf::Cursour cursor, ...)
*	
*		- Window class?!
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
* 
* 
*		Components
* 
*			AI
*			Physics
*			Animation
*			Graphics
* 
* 
*	Creatuer -> Hero & Monster 
* 
*	Alternative
*	
*	Mosnter has a Breed (Dragon, Orc, etc...)
*	
* 
*	Game Implementations
* 
*		Make tree leefs wiggle
* 
* 
*	Late Game implementations
*		- building/crafting
*		- chop down trees/palm trees for wood 
*		- punching/stricking trees or barrels make them shake
*		- speech bubbles when people are talking
*/

#include "playground/collision/Collision_playground.h"

int main()
{

	//collision_playground::run();

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