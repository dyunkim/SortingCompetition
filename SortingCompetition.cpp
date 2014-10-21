#include "SortingCompetition.h"
#include <iostream>
#include <iomanip>
#include <omp.h>

SortingCompetition::SortingCompetition(const string& inputFileName)
{
    fin.open(inputFileName);
    omp_set_num_threads(4);


}

void SortingCompetition::setFileName(const string& inputFileName) {
    fin.close();
    fin.open(inputFileName);
}

bool SortingCompetition::readData() {
    while(!fin.eof()) {
        char* word = new char[50];
        fin >> word;
        prePrepare.push_back(word);
    }
    return true;
}

bool SortingCompetition::prepareData() {

    //length prefixed char* implementation
    lenarray = new char*[prePrepare.size()];
    for(int i = 0; i < prePrepare.size(); i++) {
        lenarray[i] = new char[50];
        for(int j = 0; j < 50; j++) {
            lenarray[i][j] = 0;
        }
        lenarray[i][0] = strlen(prePrepare.at(i));      //set first char to length of string
        for(int j = 0; j < strlen(prePrepare.at(i)) + 1; j++) {
            lenarray[i][j + 1] = prePrepare.at(i)[j];       //copy rest of the data
        }
    }
    return true;
}

void SortingCompetition::sortData() {

    quickSortOmp(lenarray, prePrepare.size());


}

void SortingCompetition::outputData(const string& outputfinName) {
    ofstream fout(outputfinName);
    if(!fout.is_open()) {
        cout << "ERROR OPENING OUTPUT FILE" << endl;
    }

    else {
        for(int i = 0; i < prePrepare.size(); i++) {        //special file out for length prefixed
            for(int j = 1; j < lenarray[i][0] + 1; j++) {
                fout << lenarray[i][j];
            }
            fout << endl;
        }
    }

}


/** Swap to value */
template <class NumType>
inline void Swap(NumType& value, NumType& other)
{
    NumType temp = value;
    value = other;
    other = temp;
}


int SortingCompetition::QsPartition(char** arr, int l, int h)
{
    char* x = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element

    for (int j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (getpstrlen(arr[j]) <= getpstrlen(x))
        {
            if (getpstrlen(arr[j]) == getpstrlen(x) && pstrcmp(arr[j],x)<0)
            {
                    i++;    // increment index of smaller element
                    Swap(arr[i], arr[j]);  // Swap current element with index
                }
                if (getpstrlen(arr[j]) < getpstrlen(x))
                {
                    i++;    // increment index of smaller element
                    Swap(arr[i], arr[j]);  // Swap current element with index
                }
            }
        }
        Swap(arr[i + 1], arr[h]);
        return (i + 1);
    }

    /* a sequential qs */

    void SortingCompetition::QsSequential(char** array, int left, int right){
        if(left < right){
            int part = QsPartition(array, left, right);
            QsSequential(array,left,part - 1);
            QsSequential(array,part + 1,right);
        }
    }

    /** A task dispatcher */
    void SortingCompetition::QuickSortOmpTask(char** array, int left, int right, const int deep){
        if(left < right){
            int part = QsPartition(array, left, right);
            if( deep ){
                #pragma omp task
                QuickSortOmpTask(array,part + 1,right, deep - 1);
                #pragma omp task
                QuickSortOmpTask(array,left,part - 1, deep - 1);
            }
            else {
                QsSequential(array,part + 1,right);
                QsSequential(array,left,part - 1);
            }
        }
    }

    /** The openmp quick sort */
    void SortingCompetition::quickSortOmp(char** array, int size){
        const int nbTasksRequired = (omp_get_max_threads() * 5);
        int deep = 0;
        while( (1 << deep) < nbTasksRequired ) deep += 1;

        #pragma omp parallel
        {
            #pragma omp single nowait
            {
                QuickSortOmpTask(array, 0, size - 1 , deep);
            }
        }
    }


int SortingCompetition::getpstrlen(char * word) {
    return word[0];                 //return length of string
}

int SortingCompetition::pstrcmp(char * first, char * second) {

    int length = 0;
    if (first[0] > second[0]) {     //find which one has a longer length and use that
        length = first[0];
    }
    else {
        length = second[0];
    }
    for(int i = 1; i < length + 1; i++) {
        if(first[i] < second[i]) {      //compare char by char
            return -1;                  //first argument has lower value
        }
        else if(second[i] < first[i]) {
            return 1;                   //second argument has higher value
        }
    }
    return 0;                   //equal strings
}




SortingCompetition::~SortingCompetition() {
    for(int i = 0; i < prePrepare.size(); i++) {
        delete [] prePrepare.at(i);
        delete [] lenarray[i];
    }
    delete lenarray;
}
