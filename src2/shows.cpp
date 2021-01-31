#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void MyPrintLin()
{
        int len=35;
        cout<<":-";
        for(int i=0;i<len;i++)cout<<"-";
        cout<<":"<<endl;
}
void showMostImportartCharacteristis(vector<double>pinSt)
{
    cout<<endl;
    MyPrintLin();
    cout<<"Exams\t"<<"Studens\t"<<"Enroll\t"<<"Density\t"<<endl;
    cout<<(int)pinSt[0]<<"\t"<<(int)pinSt[1]<<"\t"<<(int)pinSt[2]<<"\t"<<setprecision (2) <<pinSt[3]<<"\t"<<endl;
    MyPrintLin();
}
