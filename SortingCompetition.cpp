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
    array = new char*[20000000];
    for(int i = 0; i < prePrepare.size(); i++) {
        array[i] = new char[50];
        array[i] = prePrepare.at(i);
    }


    left = 0;
    right = prePrepare.size() - 1;
    return true;
}

void SortingCompetition::sortData() {

    quickSort(array, left, right);

    for(int i = 0; i < prePrepare.size(); i++) {
        cout << array[i] << endl;
    }
}

void SortingCompetition::outputData(const string& outputfinName) {
    ofstream fout(outputfinName);
    if(!fout.is_open()) {
        cout << "ERROR" << endl;
    }
    else {
        for(int i = 0; i < prePrepare.size(); i++) {
            fout << array[i] << endl;
        }
    }
}

SortingCompetition::~SortingCompetition() {
    
}

void SortingCompetition::quickSort(char ** arr, int left, int right) {
    int i=left;
    int j=right;
    char* pivot = arr[(left+right)/2];
    char* temp;

    while (i<=j)
    {
       while(strlen(arr[i]) > strlen(pivot)) //if greater or lessthan
       {
           i++;
       }
//       if (strlen(arr[i])==strlen(pivot))
//       {
//           if(strcmp(arr[i], pivot) > 0) //if greater or lessthan
//           {
//               i++;
//           }
//       }

       while(strlen(arr[j]) < strlen(pivot)) //if greater or lessthan
       {
           j--;
       }
//       if (strlen(arr[j])==strlen(pivot))
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
