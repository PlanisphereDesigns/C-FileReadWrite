// citiesapp.cpp : Read in a file; sort contents; output a new reformatted .txt file.
//

#include <iostream>
#include <string>
#include<vector>
#include<cmath>
#include<fstream>
#include <set>
#include<algorithm>
using namespace std;

int main()
{
    string textline;
    /*store the pairs in a vector*/
    vector<string> gotLine;
    vector<string> city;
    vector<string> state;
    int splitCharIndex;
    string currLine;
    string cityString;
    string stateString;
    cout << "This program will get text from one file, reformat and process it, and write it into a new text file." << endl;
    cout << endl;

    ifstream readingCitiesFileStream("cities.txt");
    /*Error catching: check if the file is open or not.*/
    if (readingCitiesFileStream.is_open()) {
        while (!readingCitiesFileStream.fail()) {
            /*This getline break up the city and its state abbreviation so they can be stored in pairs.*/
            getline(readingCitiesFileStream, textline);
            cout << "Got: " << textline << " as raw text from the original file." << endl;
           
            gotLine.push_back(textline);
        }
    }
    else {
        cout << "Sorry, the file could not be opened.  Please try again when you have the correct file saved in the correct folder." << endl;
    }
    //end; close the file
    readingCitiesFileStream.close();

    /*Now that the file has been read, process its contents.*/

   
    for (int i = 0; i < int(gotLine.size() -1); i++) {
        /*split the string at the seperator*/
        currLine = gotLine.at(i);
        splitCharIndex = currLine.find('%');
        /*Get the split index*/
        cityString = currLine.substr(0, currLine.find("%"));
        stateString = currLine.substr(currLine.find("%") + 1);
  
        city.push_back(cityString);
        state.push_back(stateString);
       
    }

    //sort vector

    vector<string> cityStatePairs;
    string conglomerate;
    /*Fixed duplicate city bug*/
    for (int d = 0; d < int(city.size()); d++) {
        /*concatenate the two vectors*/
        conglomerate = state.at(d) + " has the city of " + city.at(d) + "!";
    
    
        cityStatePairs.push_back(conglomerate);
        conglomerate = "";

    }
    sort(cityStatePairs.begin(), cityStatePairs.end());//Sort this

    for (int l = 0; l < int(cityStatePairs.size()); l++) {
        cout << "The sorted and reformatted contents to be written into the file are: " << cityStatePairs.at(l)  << endl;
    }
    
    /*Write to a new file.*/
    ofstream writeNewCityStateFile("sortedCities.txt");
    for (int fileIterator = 0; fileIterator < int(cityStatePairs.size()); fileIterator++) {
        writeNewCityStateFile<< cityStatePairs.at(fileIterator);
        writeNewCityStateFile << "\n";
    }
    cout << "File successfully written." << endl;
    /*close the stream*/
    writeNewCityStateFile.close();
    cout << "File stream successfully closed.  Look for the text file." << endl;
    return 0;
}