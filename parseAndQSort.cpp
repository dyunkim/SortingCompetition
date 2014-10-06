#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

void quickSort(char** arr, int left, int right)
{
    int i=left, j=right;
    char* pivot = arr[(left+right)/2];
    char* temp;
    while (i<=j)
    {
       while(strlen(arr[i]) > strlen(pivot)) //if greater or lessthan
       {
           i++;
       }
       if (strlen(arr[i])==strlen(pivot))
       {
           while(strcmp(arr[i], pivot) > 0) //if greater or lessthan
           {
               i++;
           }
       }
       while(strlen(arr[j]) < strlen(pivot)) //if greater or lessthan
       {
           j--;
       }
       if (strlen(arr[j])==strlen(pivot))
       {
           while(strcmp(arr[j], pivot) > 0) //if greater or lessthan
           {
               j--;
           }
       }
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
void parse(ifstream& fin, vector<char*>& prePrepare, char**& array)
{

    for (int i=0; i<20; i++)
    {
        array[i]=new char[50];
    }

    while(!fin.eof()) {
        char* word = new char[50];
        fin >> word;
        prePrepare.push_back(word);
    }
    for(int i = 0; i < prePrepare.size(); i++) {
        array[i] = new char[50];
        array[i] = prePrepare.at(i);
    }
}

/*int main()
{
    ifstream fin("data.txt");
    char** array=new char*[40];
    vector<char*> prePrepare;
    parse(fin, prePrepare, array);
    cout <<"here is the sorted array: " << endl;
    quickSort(array, 0, 19);
    for(int i=0; i<20; i++)
        cout << array[i] << endl;
    delete[] array;
    return 0;
}*/

