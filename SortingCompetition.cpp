#include "SortingCompetition.h"
#include <iostream>
#include <iomanip>

SortingCompetition::SortingCompetition(const string& inputFileName)
{
    fin.open(inputFileName);


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
//    array = new char*[prePrepare.size()];
//    for(int i = 0; i < prePrepare.size(); i++) {
//        array[i] = new char[50];
//        array[i] = prePrepare.at(i);
//    }

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

    left = 0;                   //define bounds
    right = prePrepare.size() - 1;
    return true;
}

void SortingCompetition::sortData() {

   //quickSort(lenarray, left, right);
    selectionSort(lenarray, right + 1);


}

void SortingCompetition::outputData(const string& outputfinName) {
    ofstream fout(outputfinName);
    if(!fout.is_open()) {
        cout << "ERROR OPENING OUTPUT FILE" << endl;
    }
//    else{
//        for(int i = 0; i < prePrepare.size(); i++) {
//            fout << array[i] << endl;
//        }
//    }
    else {
        for(int i = 0; i < prePrepare.size(); i++) {        //special file out for length prefixed
            for(int j = 1; j < lenarray[i][0] + 1; j++) {
                fout << lenarray[i][j];
            }
            fout << endl;
        }
    }

}


void SortingCompetition::quickSort(char ** arr, int left, int right) {
    int i=left;
    int j=right;
    char* pivot = arr[(left+right)/2];
    char* temp;

    while (i<=j)
    {
       while(getpstrlen(arr[i]) > getpstrlen(pivot)) //if greater or lessthan
       {
           i++;
       }
//       if (pstrlen(arr[i])==pstrlen(pivot))
//       {
//           if(strcmp(arr[i], pivot) > 0) //if greater or lessthan
//           {
//               i++;
//           }
//       }

       while(getpstrlen(arr[j]) < getpstrlen(pivot)) //if greater or lessthan
       {
           j--;
       }
//       if (pstrlen(arr[j])==pstrlen(pivot))
//       {
//           if(strcmp(arr[j], pivot) > 0) //if greater or lessthan
//           {
//               j--;
//           }
//       }

       if (i <= j)
       {
           temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
           i++;
           j--;
       }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
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

void SortingCompetition::moveLargest(char **& arr, int size) {
    int index = size - 1;
    char* temp = new char[50];
    for(int i = index - 1; i >=0; i--) {
        if(getpstrlen(arr[index]) > getpstrlen(arr[i])) {       //order by length
            index = i;
        }
        else if(getpstrlen(arr[index]) == getpstrlen(arr[i])) { //if same length, order by alphabet
            if(pstrcmp(arr[index], arr[i]) < 0) {
                index = i;
            }
        }
    }
    temp = arr[index];          //swap
    arr[index] = arr[size - 1];
    arr[size - 1] = temp;
}

void SortingCompetition::selectionSort(char **& arr, int size) {       //implementation for selection Sorting
    if (size == 1) return;      //base case
    else {
        moveLargest(arr, size);
        selectionSort(arr, size - 1);
    }
}

SortingCompetition::~SortingCompetition() {
    for(int i = 0; i < prePrepare.size(); i++) {
        delete [] prePrepare.at(i);
        delete [] lenarray[i];
    }
    delete lenarray;
}
