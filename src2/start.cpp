// #include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include "graph.cpp"
#include "menuFun.cpp"
#include <chrono>

using namespace std;

void menu()
{
        int choice = 0;
        vector<string>namesOfFiles(26);
        char b;
        system("cls");
        int menuChoice=0;
        vector<double>stoixeiaMath(10);
        int * adj_matrix;
        string nFile;
        int V; 
        do{
                namesOfFiles=getNames("filesName.txt");
                cout<<":Chose a number problem:";
                menuChoice = GetInput(0,12);
                cout<<endl<<"Your choice is :"<<namesOfFiles[menuChoice*2]<<endl;
                nFile = "../datasets/"+namesOfFiles[menuChoice*2];
                std::istringstream (namesOfFiles[(menuChoice*2)+1]) >> V;
                adj_matrix = readData(nFile, V);
                cout<<endl<<"To SELECT another problem  press 1 :";
                cout<<endl<<"To CREATE a solusion       press 2 :";
                cout<<endl<<"To LEAVE                   press 3 :";
                cout<<endl<<endl<<"SELECT : ";
                int x =GetInput(1,3);
                if(x==1)
                        {
                        continue;
                        }
                else if(x==2)
                        {
                        Graph g(V);
                        loadProblem(g, adj_matrix,V);
                        delete[] adj_matrix;
                        int *sol;
                        auto start = std::chrono::high_resolution_clock::now();
                        sol = g.greedyColoring();
                        auto finish = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<float> duration = finish - start;
                        std::cout << "Time passed: " << duration.count() << " seconds" << std::endl;
                        g.writeSolToFile(sol,namesOfFiles[menuChoice*2]);
                        bool proper_coloring = check_coloring(g, sol);
                        delete []sol;
                        if (proper_coloring)
                                {
                                        cout << "This is a proper coloring" << endl;
                                }
                                else   
                                {
                                        cout << "This is not a proper coloring" << endl;
                                }
                                cout<<endl;
                                system("PAUSE");
                        }
                        
                else break;
        }
        while(true);
}     
int main()
{
    menu();
    return 0;
}
