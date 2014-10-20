#ifndef SORTINGCOMPETITION_H
#define SORTINGCOMPETITION_H
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

class SortingCompetition
{
public:
    SortingCompetition(const string&);
    void setFileName(const string&);
    bool readData();
    bool prepareData();
    void sortData();
    void outputData(const string&);
    ~SortingCompetition();
    
private:
    void quickSort(char**, int, int);       //quick sort implementation
    void moveLargest(char**&, int);         //additional method for selection sort
    void selectionSort(char**&, int);       //selection sort implementation
    void bubbleSort(char**&, int);
    vector<char*> prePrepare;           //vector that reads in file data
    ifstream fin;
    char** lenarray;                //array for length prefixed strings
    char** array;               //array that has the prepared data
    int left;                   //bounds of array
    int right;

    int getpstrlen(char*);          //gets length of length prefixed string
    int pstrcmp(char*, char*);      //compares two length prefixed strings

};

#endif // SORTINGCOMPETITION_H
