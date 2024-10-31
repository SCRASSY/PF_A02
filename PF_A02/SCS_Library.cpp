#include "SCS_Library.h"

vector<string> SCS::ReadFile(string Adventure)
{
	// Declares a string variable used for storing the text on each line of the chosen .txt file
	string LineReader;

	// Declares a collection of strings to hold the data of an adventure
	vector<string> L_FileData;

	// Creates a file stream object
	ifstream File;

	// Loops through the entire project folder on a surface level
	for (const auto& Entry : filesystem::directory_iterator("Adventures"))
	{
		// Checks if the current file in the adventures folder has the same name as the passed through adventure .txt file name
		if (Entry.path().filename() == Adventure)
		{
			// Opens the file and assignes it to the local file obj var
			File.open(Entry.path());
		}
	}

	// Checks if the file is open
	if (File.is_open())
	{
		// Iterates through each line in the .txt file and prints it out to the console
		while (getline(File, LineReader))
		{
			// Adds each line to the local file data
			L_FileData.push_back(LineReader);
		}

		// Finally returns the file string collection
		return L_FileData;
	}

	// Closes the file when finished to free up memory
	File.close();

	// Returns nothing when done
	return L_FileData;
}

void SCS::SearchProgramFile(vector<string>& FileCollection)
{
	// Loops through the entire project folder on a surface level
	for (const auto& Entry : filesystem::directory_iterator("Adventures"))
	{
		// Checks if the current file is a text file and that it is not the "ReadMe.txt" file
		if (Entry.path().extension() == ".txt" && Entry.path().filename() != "ReadMe.txt")
		{
			// Adds the name of the adventure file to the adventure engines file name collection
			FileCollection.push_back(Entry.path().filename().string());
		}
	}
}