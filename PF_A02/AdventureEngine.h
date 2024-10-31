#pragma once
#include "SCS_Library.h"
#include "Adventure.h"

using namespace std;

class AdventureEngine
{
private:
	// Holds the string data for the current adventure
	vector<string> FileNameCollection;
	// Stores the .txt adventures found in the project folder
	vector<Adventure*> AdventureCollection;

public:
	// Creates a collection of adventures and adds them to the adventure collection
	void CreateAdventureCollection();

	// Checks that all data is valid and sets up the adventure game
	void SetupAdventureGame();

	// Checks if the player chose a valid adventure, if not then it will loop again and prompt the user to input a valid adventure
	bool InvalidAdventureInputChecker(int& UserInput);

	// Checks if the player chose a valid choice/scene, if not then it will loop again and prompt the user to input a valid choice/scene
	bool InvalidSceneInputChecker(int& UserInput, Scene* CurrentScene);

	// Runs the chosen adventure game
	void RunAdventureEngine(Scene* CurrentScene);

	// Creates a single adventure
	Adventure* CreateAdventure(string FileName);

	// Getters
	vector<Adventure*> GetAdventureCollection() { return AdventureCollection; }
};