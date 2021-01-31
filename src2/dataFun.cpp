#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <chrono>
#include <list>
#include "shows.cpp"

using namespace std;
int count_common_elements(set<int> s1, set<int> s2)
    {
            int c = 0;
            for (int x : s1)
            {
                for (int y : s2)
                {
                    if (x == y)
                    {
                        c++;
                        break;
                    }
                }
            }
        return c;
    };
int* readData(string filename,int exams)
{
    vector<double>stoixeiaArxeiou(20);
    vector<set<int>>foititesAnaMathimaExetasis(exams+1);
    set<int>mathimata;
    ifstream file(filename);
    if(!file.is_open())
    {
        cout<<"Problhma me to arxeio"<<endl;
        exit(-1);
    }
    int id_Foititi=0;
    int PlithosEggrafon=0;
    string line;
    while(getline(file,line))
    {
        if(line.empty())continue;
        id_Foititi++;
        int mathima = 0;
        istringstream issa(line);
        while(issa>>mathima)
            {
            mathima-1;
            foititesAnaMathimaExetasis[mathima].insert(id_Foititi);
            PlithosEggrafon++;
            mathimata.insert(mathima);
            }
    }
    // // // δημιουργία πίνακα γειτνίασης
    int plithos = 0;
    int *adj_matrix = new int[exams * exams];
    for (int i = 0; i <  exams; i++)
    {
        for (int j = 0; j <  exams; j++)
        {
            if (i == j)
                {
                    adj_matrix[i * exams + j] = 0; // adj_matrix[i][j]
                    continue;
                }
            int c = count_common_elements(foititesAnaMathimaExetasis[i+1], foititesAnaMathimaExetasis[j+1]);
            adj_matrix[i * exams + j] = c;
            if(c>0)plithos++;
        }
    }
    //Πυκνότητα πίνακα.
    double piknotita = (double)plithos/(double)(exams*exams);
    stoixeiaArxeiou[0]=exams;
    stoixeiaArxeiou[1]=id_Foititi;
    stoixeiaArxeiou[2]=PlithosEggrafon;
    stoixeiaArxeiou[3]=piknotita;
    showMostImportartCharacteristis(stoixeiaArxeiou);
    return adj_matrix;
}

