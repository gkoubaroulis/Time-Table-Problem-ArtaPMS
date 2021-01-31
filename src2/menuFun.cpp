#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <cstdlib>

#include "dataFun.cpp"
using namespace std;

int GetInput(int min,int max)
{
    int choice;
    do
    {   
        cin>>choice;
        if(choice>max || choice<min) cout<<endl<<"Try Again :";
    }while(choice>max || choice<min);
    return choice;
}

vector<string> getNames(string fileToOpen){
    vector<string> namesOfFile(52);
    ifstream file(fileToOpen);
    if (!file.is_open())
    {
        cout << "Could not open file " << fileToOpen <<std::endl;
        exit(-1);
    }
    string str;
    int i=0; 
    while (getline(file, str))
        {
            stringstream s(str);
            s>>namesOfFile[i];
            s>>namesOfFile[i+1];
            i=i+2;
        }
        file.close();
    cout<<endl<<":--------Problem's File-------------:";
    int j=0;
    for(int i = 0; i<26;i=i+2){
        cout <<endl<<" "<<namesOfFile[i]<<"\t"<<namesOfFile[i+1]<<"\t -->  "<<j;
        j++;
    }
    cout<<endl;
    cout<<endl<<"To stop press Ctrl+C";
    cout<<endl;
    MyPrintLin();
    return namesOfFile;
}

void DisplayNamesOfProblems(vector<string> VectorfilesName)
{
    for (size_t n=0;n<VectorfilesName.size();n++)
    {
            cout<<VectorfilesName[n]<<" = "<<n<<endl;
    }
}
void emfaniseStoixeia(vector<int> stoixeia){
    cout<<endl;
    MyPrintLin();
    cout<<"Exams  \t"<<"Studens\t"<<"Eggrafes\t"<<endl;
    cout<<stoixeia[0]<<"\t"<<stoixeia[1]<<"\t"<<stoixeia[2]<<"\t"<<endl;

}
