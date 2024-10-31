#pragma once
#include <iostream>
#include <vector>

// This class is using the Scene class, used for the Choice struct to prevent the Choice struct from being declared inside the Scene class
class Scene;

using namespace std;

// Choice data struct
struct Choice
{
	// Choice description
	string ChoiceDesc;
	// Name of the scene the choice leads to
	string ChoiceToPointTo;
	// The scene that the choice points to
	Scene* ChoiceScenePtr = nullptr;
};

class Scene
{
private:
	// Holds the ID of what scene this instance will be
	string SceneID;
	// Holds the description of the scene
	string SceneDescription;
	// Holds a description of a choice and where it should point to
	vector<Choice*> SceneChoices;

public:
	// Constructor
	Scene(string ID, string Desc);

	// Getters
	string GetSceneID() { return SceneID; }
	string GetDescription() { return SceneDescription; }
	vector<Choice*> GetChoiceCollection() { return SceneChoices; }

	// Setters
	void SetSceneID(string ID){ SceneID = ID; }
	void SetSceneDescription(string Desc){ SceneDescription = Desc; }

	// Adding data
	void AddToChoiceData(string ChoiceDesc, string SceneToPointTo);
};