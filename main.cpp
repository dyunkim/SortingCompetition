#include <iostream>
#include <chrono>
#include <ctime>
#include "SortingCompetition.h"
#include <fstream>

using namespace std;

int main()
{
   SortingCompetition s("input.txt");
   s.readData();
   s.prepareData();
   chrono::time_point<chrono::system_clock> start, end;
   
   
   start = chrono::system_clock::now();
   s.sortData();
   end = chrono::system_clock::now();

   chrono::duration<double> elapsed_seconds = end - start;
   
   cout << "Elapsed time of function: " << elapsed_seconds.count() << endl;
}

