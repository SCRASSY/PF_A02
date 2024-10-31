#include "AdventureEngine.h"

int main()
{
	AdventureEngine* AdventureEngineObj = new AdventureEngine();

	// Creates the adventure collection
	AdventureEngineObj->CreateAdventureCollection();

	// Sets all ptrs for the choices of every scene in this adventure
	// Loops through every adventure in the adventure engines adventure collection
	for (Adventure* Adv : AdventureEngineObj->GetAdventureCollection())
	{
		// Sets up the choice ptrs for each scene in the current adventure
		Adv->SetSceneChoicePtrs();
	}

	// Calls the main game function
	AdventureEngineObj->SetupAdventureGame();
}