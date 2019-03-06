#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


namespace MusicDB
{

	const int MAX_SONG_RECORDS = 8;  // define a max number of song records in database
	string binary_database_file_name = "MyFavoriteSongs.db";  // define the database file name
	int total_number_of_songs;  // integer to keep total number of songs in any time
	Song all_songs [MAX_SONG_RECORDS];  // make an empty array for storing all songs
	Song song_to_add;  // make a one-element structure for adding a new song
	bool there_is_a_new_song;  // define the bool that will know if there is a new song entered

	// a function for loading the song database into the array and counting a number of songs
	void loadTheMusicDatabaseFromFile()
	{
		Song song;  // make a one-element structure for reading song-by-song from a database
		ifstream file;  // construct a ifstream object
		total_number_of_songs = 0;  // set number of songs to 0

		try
		{
			file.open(binary_database_file_name, ios::in | ios::binary);  // open the file for reading
			file.exceptions(ifstream::eofbit | ifstream::failbit);  // set the possible exceptions when opening the file

			while (file.is_open() && !file.eof())  // repeat if file exists and it is not a end of file
			{
				file.exceptions(ifstream::badbit | ifstream::eofbit);  // set the possible exceptions when reading the file
				try
				{
					file.read((char*)& song, sizeof(song));  // read the one song from the file
					if (total_number_of_songs <= MAX_SONG_RECORDS - 1)  // if there is a space in an array
						all_songs[total_number_of_songs] = song;  // add that song to the array
					total_number_of_songs++;  // increase the number of total songs
				}
				catch (const exception & exc)
				{
					(void)exc;  // silent catch
				}
			}
			file.close();  // close the file
		}

		catch (const exception &exc)
		{
			cout << "Failed to load the music database: Failed to open file '" << binary_database_file_name << "'" << endl;  // if there is exception print the sentence defined in assginment
			(void)exc;  // silent catch
		}

	}

	// a function for returning number of songs that is in variable 'total_number_of_songs'
	int returnTheTotalNumberOfSongs()
	{
		return total_number_of_songs;  // return a number of songs
	}

	// a function that print info of one song by order number in array
	void getTheSongInformationBySongNumber(int song_number)
	{
		string genre_string;  // define the string for genre output
		cout << "Song #" << song_number + 1 << ":" << endl;  // print a song order number (+1 cause the array index starts from 0)
		cout << "  Title:   " << all_songs[song_number].song_title << endl; // print a song title from an array
		cout << "  Artist:  " << all_songs[song_number].artist_name << endl; // print a artist name from an array
		cout << "  Album:   " << all_songs[song_number].album_name << endl; // print a album name from an array
		cout << "  Track #: " << all_songs[song_number].track_number << endl; // print a track number from an array
		cout << "  Year:    " << all_songs[song_number].year_released << endl; // print a year released from an array

		switch (all_songs[song_number].song_genre)  // decide which string to print as genre based on genre recorded in an array
		{
		case Blues:						 // cases are obvious
			genre_string = "Blues";
			break;
		case Country:                   
			genre_string = "Country";
			break;
		case Electronic:
			genre_string = "Electronic";
			break;
		case Folk:
			genre_string = "Folk";
			break;
		case HipHop:
			genre_string = "HipHop";
			break;
		case Jazz:
			genre_string = "Jazz";
			break;
		case Latin:
			genre_string = "Latin";
			break;
		case Pop:
			genre_string = "Pop";
			break;
		case Rock:
			genre_string = "Rock";
			break;
		default: // to avoid an error, Unknown (0) is default
			genre_string = "Unknown";
			break;
		}                               // end of switch

		cout << "  Genre:   " << genre_string << endl;  // print the genre selected
	}

	// function that prints info of all songs in the database until the defined numer
	void printAllSongsInformations(int song_number)
	{
		for (int song_number_counter = 0; song_number_counter < song_number; song_number_counter++)  // through the loop
			getTheSongInformationBySongNumber(song_number_counter);  // print the song information
	}

	// function that add a new song to the database
	void addANewSongToTheDatabase()
	{
		string input_str;  // define the strign for taking the input
		there_is_a_new_song = false;  // set that there is currently not a new song

		if (total_number_of_songs < MAX_SONG_RECORDS - 1)  // just if there is a space in the array (number of songs is lower than max - 1)
		{ 
			try
			{
				cout << "Enter song title: ";  // print to the user what type of data to enter
				getline(cin >> ws, input_str);  // get the input string (with spaces if needed)

				if (input_str.length() > sizeof(song_to_add.song_title))  // if string is bigger than a predicted space
					throw exception("Song title is to large! ");  // throw an exception
				else  // in other case
					strcpy_s(song_to_add.song_title, input_str.c_str());  // copy a string to the song_tgitle char array structure

				cout << "Enter artist: ";  // print to the user what type of data to enter
				getline(cin >> ws, input_str);  // get the input string (with spaces if needed)

				if (input_str.length() > sizeof(song_to_add.artist_name))  // if string is bigger than a predicted space
					throw exception("Artist name is to large! ");  // throw an exception
				else  // in other case
					strcpy_s(song_to_add.artist_name, input_str.c_str());  // copy a string to the artist_name char array structure

				cout << "Enter album name: ";  // print to the user what type of data to enter
				getline(cin >> ws, input_str);  // get the input string (with spaces if needed)

				if (input_str.length() > sizeof(song_to_add.album_name))  // if string is bigger than a predicted space
					throw exception("Album name is to large! ");  // throw an exception
				else  // in other case
					strcpy_s(song_to_add.album_name, input_str.c_str());  // copy a string to the album_name char array structure
				
				cout << "Enter track #: ";  // print to the user to enter the song's track number
				getline(cin >> ws, input_str);  // get the input string 
				try
				{
					song_to_add.track_number = stoi(input_str);  // try to convert entered string to integer and put it to the structure
				}
				catch (const exception &exc)  // if something went wrong
				{
					throw exception("Wrong track number format! ");  // throw the exeption
					(void)exc;  // silent catch
				}

				cout << "Enter year: ";  // print to the user to enter the song's year
				getline(cin >> ws, input_str);  // get the input string 
				try
				{
					song_to_add.year_released = stoi(input_str);  // try to convert entered string to integer and put it to the structure
				}
				catch (const exception &exc)  // if something went wrong
				{
					throw exception("Wrong year format! ");  // throw the exeption
					(void)exc;  // silent catch
				}

				cout << "Enter genre: ";  // print to the user to enter the song's genre
				getline(cin >> ws, input_str); // get the input string 

				song_to_add.song_genre = Unknown; // set genre to default value (Unknown=0) to avoid an error
				if (input_str == "Blues")                    // other cases are obvious
					song_to_add.song_genre = Blues;
				else if (input_str == "Country")
					song_to_add.song_genre = Country;
				else if (input_str == "Electronic")
					song_to_add.song_genre = Electronic;
				else if (input_str == "Folk")
					song_to_add.song_genre = Folk;
				else if (input_str == "HipHop")
					song_to_add.song_genre = HipHop;
				else if (input_str == "Jazz")
					song_to_add.song_genre = Jazz;
				else if (input_str == "Latin")
					song_to_add.song_genre = Latin;
				else if (input_str == "Pop")
					song_to_add.song_genre = Pop;
				else if (input_str == "Rock")
					song_to_add.song_genre = Rock;
                                                             // end of if

				there_is_a_new_song = true;  // set to there is a new song entered
			}
			catch (const exception &exc)  // if there is an exception
			{
				cout << exc.what() << endl << " Adding a new song is automatically canceled!" << endl;  // print type of exception and the information that adding is canceled
			}
		}
		else  // if there is no space in the array
			cout << "Could not add a new song, there are too many songs in the database." << endl;  // print that info to the user
	}

	// a function that append a new song to the database file
	void saveTheMusicDatabaseToFile()
	{
		ofstream output_file; // construct a ofstream object
		output_file.open(binary_database_file_name, ios::out | ios::app | ios::binary);  // open a file for binary appending
		output_file.write((char*)&song_to_add, sizeof(song_to_add));  // append a new song
		output_file.close(); // close the file
		there_is_a_new_song = false; // set to there is currently not a new song
	}

	// a function that return is there a valid new song entered
	bool isThereANewSong()
	{
		return there_is_a_new_song;  // return the value of the boolean variable
	}

}
