#include "AdventureEngine.h"

void AdventureEngine::CreateAdventureCollection()
{
	// Searches through the project files for all .txt files and adds there names to the file name collection vector
	SCS::SearchProgramFile(FileNameCollection);

	// Loops through each file name in the file name collection
	for (string s : FileNameCollection)
	{
		// Adds a new adventure each loop
		AdventureCollection.push_back(CreateAdventure(s));
	}
}

Adventure* AdventureEngine::CreateAdventure(string FileName)
{
	// Declares a local adventure id and removes the .txt at the end
	string L_AdventureID = FileName.erase(FileName.length() - 4);

	// Creates a new adventure ptr
	Adventure* NewAdventure = new Adventure(L_AdventureID);

	// Creates a collection of scenes for each adventure
	NewAdventure->CreateSceneCollection();

	// Returns an adventure obj
	return NewAdventure;
}

void AdventureEngine::SetupAdventureGame()
{
	// Declared local pointer variables
	Adventure* CurrentAdventure = nullptr;
	Scene* CurrentScene = nullptr;

	// Holds the users number input for decisions
	int UserInput = 0;

	// Greets the user in the console
	cout << "Welcome to SCRASSY's text adventure engine!\n\n";
	cout << "Here are 2 text adventure games that come pre-installed with the engine\n";

	// Loops through every available adventure in the adventure collection
	for (int i = 0; i < AdventureCollection.size(); i++)
	{
		// Numbers each adventure starting from 1
		cout << (i + 1) << ". " << AdventureCollection[i]->GetAdventureID() << endl;
	}

	// Informs the player that they can add more text adventure games to the text adventure game engine
	cout << "\nIf you would like more games to play you can simply copy one of the adventure games .txt\n";
	cout << "file and change the name of the file itself and replace the data inside the .txt file.\n\n";

	// This function is called to check if the player inputs a valid adventure
	while (!InvalidAdventureInputChecker(UserInput))
	{
		// Game is paused
		// Do nothing until the user inputs a valid number/adventure
	}

	// Clears the console
	SCS::ClearConsole();

	// Sets the current adventure to the players entered number - 1 to revert back to indexing starting from 0 instead of 1
	CurrentAdventure = AdventureCollection[UserInput - 1];

	// Loops through each scene in the selected adventure game
	for (Scene* Scn : CurrentAdventure->GetSceneCollection())
	{
		// Checks if the current scene has an ID called "StartRoom"
		if (Scn->GetSceneID() == "StartRoom")
		{
			// Sets the current scene var to the start room scene in the adventure
			CurrentScene = Scn;
		}
	}

	// Checks if the current scene var has been assigned a "StartRoom" scene
	// If it has not then the game will stop and will not continue the rest of the adventure
	if (CurrentScene != nullptr)
	{
		// Once game setup is complete the game will begin to run
		RunAdventureEngine(CurrentScene);
	}
}

bool AdventureEngine::InvalidAdventureInputChecker(int& UserInput)
{
	// Declares a local bool var which determines if the player has input valid or invalid information
	bool IsUserInputValid = false;

	// Prompts the user to input a valid adventure by entering a number corresponding to the adventure number displayed earlier
	cout << "Please enter the number of the adventure you would like to play: ";
	cin >> UserInput;
	cout << endl;

	// Checks if the entered number is outside the adventure collection range
	if (UserInput < 0 || UserInput > AdventureCollection.size())
	{
		// Informs the user they input an invalid number/adventure
		cout << "Invalid number\n";

		// The function will then call itself again, this will be done continuesly until the player inputs a valid number/adventure
		// Eventually the player will input a valid number and will pass through the bool return value through the stacks back to the while loop
		IsUserInputValid = InvalidAdventureInputChecker(UserInput);
	}
	else
	{
		// Sets the user input valid to true if the user input a valid number/adventure
		IsUserInputValid = true;
	}

	return IsUserInputValid;
}

bool AdventureEngine::InvalidSceneInputChecker(int& UserInput, Scene* CurrentScene)
{
	// Declares a local bool var which determines if the player has input valid or invalid information
	bool IsUserInputValid = false;

	cout << "Where do you want to go?\nChoice:";
	cin >> UserInput;

	if (UserInput < 0 || UserInput > CurrentScene->GetChoiceCollection().size())
	{
		// Informs the user they input an invalid number/choice
		cout << "Invalid number\n";

		// The function will then call itself again, this will be done continuesly until the player inputs a valid number/choice
		// Eventually the player will input a valid number and will pass through the bool return value through the stacks back to the while loop
		IsUserInputValid = InvalidSceneInputChecker(UserInput, CurrentScene);
	}
	else
	{
		// Sets the user input valid to true if the user input a valid number/choice
		IsUserInputValid = true;
	}

	return IsUserInputValid;
}

void AdventureEngine::RunAdventureEngine(Scene* CurrentScene)
{
	// Declares a local user input var which holds the data for the users input
	int UserInput = 0;

	// Displays the current scenes information
	cout << "Current Room: " << CurrentScene->GetSceneID() << endl;
	cout << CurrentScene->GetDescription() << endl;
	
	// Checks if the current scene ID is not the end scene
	// If it is the end scene then the scene name and description will only be displayed since there are no choices at the end of the adventure
	if (CurrentScene->GetSceneID() != "EndScene")
	{
		// Loops through each choice of the current scene
		for (Choice* Chc : CurrentScene->GetChoiceCollection())
		{
			// Displays the description of the current iterated choice
			cout << Chc->ChoiceDesc << endl;
		}

		while (!InvalidSceneInputChecker(UserInput, CurrentScene))
		{
			// Game is paused
			// Do nothing until the user inputs a valid number/choice
		}

		// Loops through each choice in the current scenes choice collection
		for (int i = 0; i < CurrentScene->GetChoiceCollection().size(); i++)
		{
			// Checks if the users input is the same to the currently iterated element
			if ((UserInput - 1) == i)
			{
				// Sets the current scene to be the scene the selected choice points to
				CurrentScene = CurrentScene->GetChoiceCollection()[i]->ChoiceScenePtr;

				// Clears the console
				SCS::ClearConsole();

				// Runs the next scene the choice points to
				RunAdventureEngine(CurrentScene);
			}
		}
	}
}