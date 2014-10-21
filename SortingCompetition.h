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
    void quickSortOmp(char**, int);       //quick sort implementation
    int QsPartition(char**, int, int);
    void QsSequential(char**, int, int);
    void QuickSortOmpTask(char**, int, int, const int);
    vector<char*> prePrepare;           //vector that reads in file data
    ifstream fin;
    char** lenarray;                //array for length prefixed strings


    int getpstrlen(char*);          //gets length of length prefixed string
    int pstrcmp(char*, char*);      //compares two length prefixed strings

};

#endif // SORTINGCOMPETITION_H
