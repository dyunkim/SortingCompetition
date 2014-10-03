#include "SortingCompetition.h"
#include <iostream>

SortingCompetition::SortingCompetition(const string& inputFileName)
{
    fin.open(inputFileName);
}

void SortingCompetition::setfinName(const string& inputFileName) {
    fin.close();
    fin.open(inputFileName);
}

bool SortingCompetition::readData() {
    string word;
    if(!fin.is_open()) {
        cout << "Error reading File" << endl;
    }
    else {                               //read all words
        while(fin) {
            fin >> word;
            words.push_back(word);
        }
    }
}

bool SortingCompetition::prepareData() {
    
}

void SortingCompetition::sortData() {
    
}

void SortingCompetition::outputData(const string& outputfinName) {
    
}

SortingCompetition::~SortingCompetition() {
    
}

