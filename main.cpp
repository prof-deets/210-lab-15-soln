//COMSC-210 
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int SIZE = 4;

class Movie {
   private:
      string screenWriter;
      int yearReleased;
      string title;
   public:
      string getScreenWriter()       { return screenWriter; };
      int getYearReleased()           { return yearReleased; };
      string getTitle()               { return title; };
      void setScreenWriter(string a)  { screenWriter = a; };
      void setYearReleased(int y)     { yearReleased = y; };
      void setTitle(string t)         { title = t; };

      // other methods
      void print() {
          cout << "Movie: " << title << endl;
          cout << "\tYear released: " << yearReleased << endl;
          cout << "\tScreenwriter: " << screenWriter << "\n\n";
      }
};

int main() {
    // declarations
    vector<Movie>    myFavMovies;
    string           writer, movieName;
    int              year;
    ifstream         fin("input.txt");

    // banner  
    cout << "This program will create several objects depicting movies.\n";
    cout << "Reading input file...\n";

    // read input file and store data into Class member variables
    while (getline(fin, writer)) {
        Movie tmp;
        fin >> year;
        fin.ignore();
        getline(fin, movieName);
        tmp.setScreenWriter(writer);
        tmp.setYearReleased(year);
        tmp.setTitle(movieName);
        myFavMovies.push_back(tmp);
    }
    cout << "...done.\n";

    //output contents of vector of Movies
    for (int i = 0; i < SIZE; i++)
        myFavMovies[i].print();

    fin.close();
    return 0;
}
