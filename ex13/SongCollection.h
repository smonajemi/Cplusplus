/*
NAME: SINA MONAJEMI
STUDENT# 021 - 3240124
EMAIL: SMONAJEMI@MYSENECA.CA
DIY - 7
*/
#include <string>
#include <vector>
#include <list> 

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

namespace sdds
{
	struct Song
	{
		std::string m_artist = "";
		std::string m_title = "";
		std::string m_album = "";
		double m_price = 0.0;
		int m_year = 0u;
		size_t m_length{};
	};		

	class SongCollection
	{
		std::vector<Song> m_songs;

	private:
		std::string& trim(std::string&);

	public:
		SongCollection(std::string);
		void display(std::ostream&) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;
	};

		std::ostream& operator<<(std::ostream&, const Song&);
}
#endif // !SDDS_SONGCOLLECTION_H
