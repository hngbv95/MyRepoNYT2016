#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

void writeFile(string fileName)
{
    string RealNumber;
    int quantityOfRealNumber = 10;
    int RealNumber_No = 1;
    ofstream myfile (fileName.c_str());
    if (myfile.is_open())
    {
        while (RealNumber_No <= quantityOfRealNumber )
        {
            cout<<"real number no."<<RealNumber_No<<" : ";
            cin >> RealNumber;
            myfile << RealNumber<<endl;
            RealNumber_No++;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
}

void readFile(string fileName)
{
    string line;
    ifstream myfile (fileName.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << "  ";
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

double square(double realNumber)
{
    return realNumber*realNumber;
}

double CalculateSumOfSquareOfEachNumber(string fileName)
{
    string line;
    double sum = 0.0f;
    ifstream myfile (fileName.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            sum = sum + square(atof(line.c_str()));
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return sum;
}

int main()
{
    cout<<"Start Input : "<<endl;
    writeFile("input.txt");
    readFile("input.txt");
    cout<<endl<<"Sum of square of each number : "<<CalculateSumOfSquareOfEachNumber("input.txt");
    return 0;
}
