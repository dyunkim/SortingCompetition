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
    void quickSort(char**, int, int);
    vector<char*> prePrepare;
    ifstream fin;
    void resize(char**&, int&);
    char** lenarray;
    char** array;
    int left;
    int right;

    int getpstrlen(char*);
    int pstrcmp(char*, char*);
};

#endif // SORTINGCOMPETITION_H
