#pragma once

namespace MusicDB
{
	// declaration of functions in MusicDB.cpp
	void loadTheMusicDatabaseFromFile();
	void saveTheMusicDatabaseToFile();
	int returnTheTotalNumberOfSongs();
	void printAllSongsInformations(int);
	void getTheSongInformationBySongNumber(int);
	void addANewSongToTheDatabase();
	bool isThereANewSong();

}