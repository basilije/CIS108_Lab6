#pragma once

namespace MusicDB
{
	// declaration of functions in MusicDB.cpp
	void loadTheMusicDatabaseFromFile();
	void saveTheMusicDatabaseToFile();
	int returnTheTotalNumberOfSongs();
	void printAllSongsInformations();
	void addANewSongToTheDatabase();
	bool isThereANewSong();

}