#include "Adventure.h"

void Adventure::AddToSceneCollection(Scene* SceneToAdd)
{
	SceneCollection.push_back(SceneToAdd);
}

void Adventure::SetSceneChoicePtrs()
{
	// Loops through each scene in the current adventure
	for (Scene* Scn : GetSceneCollection())
	{
		// Loops through each choice in the current scene
		for (Choice* Chc : Scn->GetChoiceCollection())
		{
			for (Scene* ScnToCheck : GetSceneCollection())
			{
				// Checks if the current choice scene to point to string var is equal to the current scene ID
				if (Chc->ChoiceToPointTo == ScnToCheck->GetSceneID())
				{
					// Sets the choice scene ptr to the scene that it's meant to point to
					Chc->ChoiceScenePtr = ScnToCheck;
				}
			}
		}
	}
}

void Adventure::CreateSceneCollection()
{
	// Holds the string data for the selected .txt files line
	vector<string> FileData = SCS::ReadFile(GetAdventureID() + ".txt");

	// Declared to hold local values to create a scene
	string L_SceneID;
	string L_SceneDesc;
	Scene* NewScene = nullptr;

	// Loops through each line of the chosen .txt file (converted to a vector<string> first)
	for (int i = 0; i < FileData.size(); i++)
	{
		// Checks if the current line is [Scene] which indicates that a scene component is now being read
		if (FileData[i] == "[Scene]")
		{
			// Moves the index by 1 and checks if the current line doesn't = end_scene; which indicates that a scene has been 100% processed
			for (int j = ++i; FileData[j] != "end_scene;"; j++)
			{
				// Declares a variable and sets it to the size of the current line - 1 as the size() function returns the size of the string which starts from 1 not 0
				int SizeOfCurrentLine = FileData[j].size() - 1;

				// Checks if the current line is the scene ID
				if (FileData[j].substr(0, 3) == "ID=")
				{
					// Sets the local scene ID to the rest of the current line (Scene Name)
					L_SceneID = FileData[j].substr(3);
				}
				// Checks if the current line is the description for the scene
				else if (FileData[j].substr(0, 12) == "Description=")
				{
					// Sets the local scene description to the rest of the current line (Scene Description)
					L_SceneDesc = FileData[j].substr(12);

					// Declares a local new scene variable and inputs the scene name and scene description
					NewScene = new Scene(L_SceneID, L_SceneDesc);
				}
				// Checks if the current line has the correct syntax in order to create the scene (e.g. [1. Inspect the comms array]->[CommsRoom])
				else if (FileData[j].substr(0, 1) == "[" && FileData[j].substr(FileData[j].find_first_of("->") - 1, 1) == "]")
				{
					// Checks if there is a "->" after the choice desc, checks if there is a "[" after the "->" and if there is a "]" at the end of the current line
					if (FileData[j].find_first_of("->") != string::npos && FileData[j].substr(FileData[j].find_first_of("->") + 2, 1) == "[" && FileData[j].substr(SizeOfCurrentLine) == "]")
					{
						// Finds the first "]" in the current line
						int LastIndex = FileData[j].find_first_of("]");

						// Declares a local string variable which is set to the text inside the first "[]"
						string L_ChoiceDescToAdd = FileData[j].substr(1, --LastIndex);

						// Gets the first index of the name which the choice is pointing towards
						int FirstIndex = (FileData[j].find_first_of("->") + 3);

						// Declares a local var to hold the name of the scene the choice will point to
						string L_SceneToPointTo = FileData[j].substr(FirstIndex);
						// Removes the last element of the scene to point to string which is "]"
						L_SceneToPointTo.pop_back();

						// Adds the choice name and the scene name to point to
						NewScene->AddToChoiceData(L_ChoiceDescToAdd, L_SceneToPointTo);
					}
				}
			}
		}
		// If the current line does equal end_scene; then the scene is finished and the new scene variable will be added to the adventures scene collection
		else if (FileData[i] == "end_scene;")
		{
			// Passes through the new scene ptr to be officially stored in the adventure choice list
			AddToSceneCollection(NewScene);
		}
		// Checks if the current line doesn't = end_adventure; which indicates that the adventure has been 100% read through
		else if (FileData[i] == "end_adventure;")
		{
			// If the current line in the .txt file is end_adventure; than all scenes have been added and the adventure is processed
			break;
		}
	}
}