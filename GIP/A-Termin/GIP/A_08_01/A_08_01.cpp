#include <iostream>
#include <cstring>
using namespace std;

struct id3v1tag {
	char Kennung[3];
	char Trackname[30];
	char Interpretename[30];
	char Albumname[30];
	char Jahr[4];
	char Kommentar[30];
	unsigned int Genre;
};

char genres[][23] = { {"Blues"}, {"Classic Rock"}, {"Country"}, {"Dance"}, {"Disco"}, {"Funk"}, {"Grunge"}, {"Hip-Hop"}, {"Jazz"}, {"Metal"}, {"New Age"}, {"Oldies"}, {"Other"}, {"Pop"}, {"R&B"}, {"Rap"}, {"Reggae"}, {"Rock"}, {"Techno"}, {"Industrial"}, {"Alternative"}, {"Ska"}, {"Death Metal"}, {"Pranks"}, {"Soundtrack"}, {"Euro-Techno"}, {"Ambient"}, {"Trip-Hop"}, {"Vocal"}, {"Jazz+Funk"}, {"Fusion"}, {"Trance"}, {"Classical"}, {"Instrumental"}, {"Acid"}, {"House"}, {"Game"}, {"Sound Clip"}, {"Gospel"}, {"Noise"}, {"Alternative Rock"}, {"Bass"}, {"Soul"}, {"Punk"}, {"Space"}, {"Meditative"}, {"Instrumental Pop"}, {"Instrumental Rock"}, {"Ethnic"}, {"Gothic"}, {"Darkwave"}, {"Techno-Industrial"}, {"Electronic"}, {"Pop-Folk"}, {"Eurodance"}, {"Dream"}, {"Southern Rock"}, {"Comedy"}, {"Cult"}, {"Gangsta"}, {"Top 40"}, {"Christian Rap"}, {"Pop/Funk"}, {"Jungle"}, {"Native US"}, {"Cabaret"}, {"New Wave"}, {"Psychadelic"}, {"Rave"}, {"Showtunes"}, {"Trailer"}, {"Lo-Fi"}, {"Tribal"}, {"Acid Punk"}, {"Acid Jazz"}, {"Polka"}, {"Retro"}, {"Musical"}, {"Rock & Roll"}, {"Hard Rock"}, {"Folk"}, {"Folk-Rock"}, {"National Folk"}, {"Swing"}, {"Fast Fusion"}, {"Bebob"}, {"Latin"}, {"Revival"}, {"Celtic"}, {"Bluegrass"}, {"Avantgarde"}, {"Gothic Rock"}, {"Progressive Rock"}, {"Psychedelic Rock"}, {"Symphonic Rock"}, {"Slow Rock"}, {"Big Band"}, {"Chorus"}, {"Easy Listening"}, {"Acoustic"}, {"Humour"}, {"Speech"}, {"Chanson"}, {"Opera"}, {"Chamber Music"}, {"Sonata"}, {"Symphony"}, {"Booty Bass"}, {"Primus"}, {"Porn Groove"}, {"Satire"}, {"Slow Jam"}, {"Club"}, {"Tango"}, {"Samba"}, {"Folklore"}, {"Ballad"}, {"Power Ballad"}, {"Rhythmic Soul"}, {"Freestyle"}, {"Duet"}, {"Punk Rock"}, {"Drum Solo"}, {"A Cappella"}, {"Euro-House"}, {"Dance Hall"}, {"Goa"}, {"Drum & Bass"}, {"Club-House"}, {"Hardcore"}, {"Terror"}, {"Indie"}, {"BritPop"}, {"Negerpunk"}, {"Polsk Punk"}, {"Beat"}, {"Christian Gangsta Rap"}, {"Heavy Metal"}, {"Black Metal"}, {"Crossover"}, {"Contemporary Christian"}, {"Christian Rock"}, {"Merengue"}, {"Salsa"}, {"Thrash Metal"}, {"Anime"}, {"JPop"}, {"Synthpop"}, {""}};

struct id3v1tag eingabe_id3v1tag(){
	// Auf dem heap erstellt:
	//id3v1tag *new_tag = new id3v1tag;
	// Auf dem stack erstellen:
	id3v1tag new_tag;
	new_tag.Kennung[0] = 'T';
	new_tag.Kennung[1] = 'A';
	new_tag.Kennung[2] = 'G';
	
	cout << "Track? \t =? ";

	cin >> new_tag.Trackname;
	new_tag.Trackname[29] = '\0';

	cout << "Interpret=? ";

	cin >> new_tag.Interpretename;
	new_tag.Interpretename[29] = '\0';

	cout << "Album \t =? ";

	cin >> new_tag.Albumname;
	new_tag.Albumname[29] = '\0';

	cout << "Jahr \t =? ";

	cin >> new_tag.Jahr;

	cout << "Kommentar=? ";

	cin >> new_tag.Kommentar;
	new_tag.Kommentar[29] = '\0';

	cout << "Genre \t =? ";
	cin >> new_tag.Genre;

	return new_tag;
}

void suche_interpret(struct id3v1tag titel[250], char interpret[30], int n){
	for (int i = 0; i < n; i++){
		if (strcmp(titel[i].Interpretename, interpret) == 0){
			cout << endl;
			cout << "Titel Nummer: " << i+1 << endl;
			cout << titel[i].Trackname << endl;
			cout << titel[i].Interpretename << endl;
			cout << titel[i].Albumname << endl;
			for (unsigned int j = 0; j<4;j++){
				cout << titel[i].Jahr[j];
			}
			cout << endl;
			cout << titel[i].Kommentar << endl;
			cout << genres[titel[i].Genre] << endl;
			cout << endl;
		}
	}
}

int main() {
	unsigned int current_pos = 0;
	char selector = 'n';
	// Auf dem Heap:
	id3v1tag *titel = new id3v1tag[250];

	//Menu
	for(;;) {
		cout << "t - Titel eingeben" << endl;
		cout << "i - Interprete suchen" << endl;
		cout << "e - Programm beenden" << endl;

		cin >> selector;
		if (selector == 'e'){
			break;
		} else {

			// Titel eingeben
			if (selector == 't'){
				titel[current_pos] = eingabe_id3v1tag();
				current_pos++;
			}

			// Interpret suchen
			if (selector == 'i'){
				if (current_pos == 0)
					cout << "Es sind noch keine Titel gespeichert." << endl;
				else{
					char gesucht[30];
					cout << "Gesuchter Interpret? ";
					cin >> gesucht;
					gesucht[29] = '\0';
					suche_interpret(titel,gesucht, current_pos);
				}
			}
		}
	}

	system("PAUSE");
	return 0;
}
