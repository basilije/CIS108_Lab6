#include <iostream>
#include <string>
#include "conio.h"
#include "MusicDB.h"

using namespace std;
string command_entered;

// A help function that prints the possible commands
void printHelp()
{
	cout << endl << "add  : Add a new song to the database" << endl;
	cout << "list : List the songs in the database " << endl;
	cout << "save : Save the songs to the database" << endl;
	cout << "help : Display a menu explaining the commands to the users " << endl;
	cout << "exit : Exit the program " << endl << endl;
}



int main()
{
	
	MusicDB::loadTheMusicDatabaseFromFile();  // try to load music database from the file
	int number_of_songs_in_db = MusicDB::returnTheTotalNumberOfSongs();  // get a total number of songs
	printHelp();  // print the help

	do  // help until command 'exit' is entered
	{
		cout << "> ";  // print the defualt terminal string
		cin >> command_entered;  // get the command

		if (command_entered == "add")  // if the command is to add the song
			MusicDB::addANewSongToTheDatabase();  // use the function to add a new song to the database

		if (command_entered == "list")  // if the commands is to list the database
		{
			cout << "There are " << number_of_songs_in_db << " songs in the database." << endl;   // print the number of the songs in the database
			MusicDB::printAllSongsInformations(number_of_songs_in_db);  // use the function to print all songs in the database
		}

		if (command_entered == "save")  // if the command is to save the database
		{
			if (MusicDB::isThereANewSong())  // only if there is a new song entered
			{
				MusicDB::saveTheMusicDatabaseToFile();  // append that song to the current database
				MusicDB::loadTheMusicDatabaseFromFile();  // reload the database
				number_of_songs_in_db = MusicDB::returnTheTotalNumberOfSongs();  // get the number of total songs
			}
			else
				cout << "There is no new song to save." << endl;  // if there isn't a new songs, just warn the user about that
		}

		if (command_entered == "help")  // if the command is to print available commands
			printHelp();  // print the available commands

	} while (command_entered != "exit");  // if the command is to exit, exit the loop

	return 0;
}
