#pragma once
#include "Scene.h"
#include "SCS_Library.h"

using namespace std;

class Adventure
{
private:
	// Holds the name of the adventure
	string AdventureID;
	// Holds all the scenes attached to the adventure
	vector<Scene*> SceneCollection;

public:
	// Constructor
	Adventure(string ID) { AdventureID = ID; }

	// Getters
	string GetAdventureID() { return AdventureID; }
	vector<Scene*> GetSceneCollection() { return SceneCollection; }

	// Setters
	void SetAdventureID(string ID) { AdventureID = ID; }

	// Add scenes
	void AddToSceneCollection(Scene* SceneToAdd);

	// Sets the scenes choice ptrs to a valid scene
	void SetSceneChoicePtrs();

	// Creates a collection of scenes
	void CreateSceneCollection();
};