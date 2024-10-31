#include "Scene.h"

Scene::Scene(string ID, string Desc)
{
	// Modifies scene data on construct
	SceneID = ID;
	SceneDescription = Desc;
}

void Scene::AddToChoiceData(string ChoiceDesc, string SceneToPointTo)
{
	// Declares and defines a choice struct
	Choice* L_Choice = new Choice();
	L_Choice->ChoiceDesc = ChoiceDesc;
	L_Choice->ChoiceToPointTo = SceneToPointTo;

	// Adds the choice obj to the collection of scene choices
	SceneChoices.push_back(L_Choice);
}