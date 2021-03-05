/*
NAME: SINA MONAJEMI
STUDENT# 021-3240124
EMAIL: SMONAJEMI@MYSENECA.CA
DIY-7
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm> 
#include <numeric>
#include "SongCollection.h"
using namespace std;
namespace sdds
{

	string& SongCollection::trim(string& str)
	{
		while (str.begin(), str[0] == ' ')
			str.erase(0, 1);
		while (str.length() > 0 && str[str.length() - 1] == ' ')
			str.erase(str.length() - 1, 1);

		return str;
	}

	SongCollection::SongCollection(string filename)
	{
		ifstream in;
		in.open(filename);
		try
		{
			if (!in)
				throw "INVALID FILENAME!";
			else if (!in.is_open())
				throw "FILE IS NOT OPEN!";

			while (in)
			{
				Song temp;
				string line;
				size_t pos = 0;
				size_t poe = 25;
				getline(in, line);
				if (in)
				{
					trim(temp.m_title = line.substr(pos, poe));
					pos = pos + poe;
					trim(temp.m_artist = line.substr(pos, poe));
					pos = pos + poe;
					trim(temp.m_album = line.substr(pos, poe));
					try	{temp.m_year = stoi(line.substr(75, 5));}
					catch (...){temp.m_year = 0;}
					temp.m_length = stoi(line.substr(80, 5));
					temp.m_price = stod(line.substr(85));
					m_songs.push_back(temp);
				}
			}
		}
		catch(const char* error)
		{
			cout << error << endl;
		}
		in.close();
	}
	void SongCollection::display(ostream& os) const
	{
		for_each(m_songs.begin(), m_songs.end(), [&os](const Song& line)
			{
				os << line << endl;
			});

		auto total = accumulate(m_songs.begin(), m_songs.end(), 0u, [](const size_t& size, const Song& song)
			{
				return size + song.m_length;
			});
		
		os << setw(89) << setfill('-') << '\n' << setfill(' ');
		string str = "Total Listening Time: ";
		str += to_string(total / 3600); str += ":";
		str += to_string((total %= 3600) / 60); str += ":";
		str += to_string(total % 60); 
		os << "| " << setw(84) << str << " |" << endl;;

	}
	void SongCollection::sort(string src)
	{
		try
		{
			vector<string>array = { "title","album","length"};
			auto& first = array[0];
			auto& second = array[1];
			auto& third = array[2];			
			for (vector<string>::iterator i = array.begin(); i < array.end(); i++) {
				//advance(i, 0);
				if (/*first*/*i++ == src) {
					std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b)
						{
							return a.m_title < b.m_title; // reverse order
						});
					break;
				}	
				
				else if (/*second*/*i++ == src) {
					std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b)
						{
							return a.m_album < b.m_album;
						});
					break;
				}
				else if (/*third*/*i == src) {
					std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b)
						{
							return a.m_length < b.m_length;
						});
					break;
				}
				else
					throw "\nNOT VALID!\n";
			}
		}
		catch (const char* error)
		{
			cout << error << endl;
		}
		catch (const int error)
		{
			cout << error << endl;
		}
	}
	void SongCollection::cleanAlbum()
	{
		for_each(m_songs.begin(), m_songs.end(), [](Song& a)
			{
				if (a.m_album == "[None]")
					a.m_album = ' ';				
			});
	};
	bool SongCollection::inCollection(string src) const
	{
		auto x = find_if(m_songs.begin(), m_songs.end(), [&src](const Song& a)
			{
				return a.m_artist == src;
			});
		return x != m_songs.end(); 
	}
	list<Song> SongCollection::getSongsForArtist(string src) const
	{
		auto x = count_if(m_songs.begin(), m_songs.end(), [&src](const Song& a)
			{
				return a.m_artist == src;
			});
			
		list<Song> songs(x);
		copy_if(m_songs.begin(), m_songs.end(), songs.begin(),[&src](const Song& a)
			{
				return a.m_artist == src;
			});		
		return songs;		
	}
	ostream& operator<<(ostream& os, const Song& theSong)
	{		
		string bar = " | ";
		string empty = " ";
		string year = theSong.m_year > 0 ? to_string(theSong.m_year) : empty;
		os << "| " << left << setw(20) << theSong.m_title << bar << left << setw(15) << theSong.m_artist << bar << left << setw(20) << theSong.m_album
			<< bar << right << setw(6) << year
			<< bar << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60 << setfill(' ')
			<< bar << fixed << setprecision(2) << theSong.m_price << " |";
		return os;
	}
}