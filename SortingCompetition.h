#ifndef SORTINGCOMPETITION_H
#define SORTINGCOMPETITION_H
#include <string>
#include <vector>

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
    vector<string> words;
    istream fin;
};

#endif // SORTINGCOMPETITION_H
