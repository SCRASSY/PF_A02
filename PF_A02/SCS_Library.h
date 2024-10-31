#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

class SCS
{
public:
	// Reads each file in the file collection and creates a vector of strings (converts .txt file to vector<string> allowing for easy access to each line)
	static vector<string> ReadFile(string Adventure);

	// Searches through the projects folder for any adventure.txt files which are then added to a string file collection that holds the names of every .txt file (surface level)
	static void SearchProgramFile(vector<string>& FileCollection);

	// Clears the console
	static void ClearConsole() { system("cls"); }
};