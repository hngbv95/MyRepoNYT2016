#include <iostream>
#include <fstream>

using namespace std;

void Input(int* &InputArrayNumber, int &ArrayNumberLength)
{
    cout<<"Input quantity of numbers : ";
    cin>>ArrayNumberLength;

    InputArrayNumber = new int[ArrayNumberLength];

    for(int countNumber = 0; countNumber<ArrayNumberLength;countNumber++)
    {
        cout<<"Input ("<<countNumber+1<<") : ";
        cin>>InputArrayNumber[countNumber];
    }
}

int findMin(int* InputArrayNumber, int ArrayNumberLength)
{
    int Min = InputArrayNumber[0];
    for(int countNumber = 1; countNumber<ArrayNumberLength;countNumber++)
    {
        if(InputArrayNumber[countNumber] < Min)
        {
            Min = InputArrayNumber[countNumber];
        }
    }
    return Min;
}

int findMax(int* InputArrayNumber, int ArrayNumberLength)
{
    int Max = InputArrayNumber[0];
    for(int countNumber = 1; countNumber<ArrayNumberLength; countNumber++)
    {
        if(InputArrayNumber[countNumber] > Max)
        {
            Max = InputArrayNumber[countNumber];
        }
    }
    return Max;
}

int findMostFreq(int* InputArrayNumber, int ArrayNumberLength)
{
    int countFreq = 1;
    int mostFreq = InputArrayNumber[0];
    int temp = 0;
    int tempCountFreq;

    for(int CountToTheSecondLast = 0; CountToTheSecondLast < ArrayNumberLength - 1; CountToTheSecondLast++)
    {
        temp = InputArrayNumber[CountToTheSecondLast];
        tempCountFreq = 0;

        for(int CountFromNextNumberToTheLast = 1; CountFromNextNumberToTheLast < ArrayNumberLength; CountFromNextNumberToTheLast++)
        {
            if(temp == InputArrayNumber[CountFromNextNumberToTheLast])
                tempCountFreq++;
        }
        if(tempCountFreq > countFreq)
        {
            mostFreq = temp;
            countFreq = tempCountFreq;
        }
    }
    return mostFreq;
}

void SortAsc(int* &InputArrayNumber, int ArrayNumberLength)
{
    int temp;
    for(int CountToTheSecondLast = 0; CountToTheSecondLast < ArrayNumberLength - 1; CountToTheSecondLast++)
        for(int CountFromNextNumberToTheLast = CountToTheSecondLast+1; CountFromNextNumberToTheLast < ArrayNumberLength; CountFromNextNumberToTheLast++)
        {
            if(InputArrayNumber[CountFromNextNumberToTheLast] < InputArrayNumber[CountToTheSecondLast])
            {
                temp = InputArrayNumber[CountToTheSecondLast];
                InputArrayNumber[CountToTheSecondLast] = InputArrayNumber[CountFromNextNumberToTheLast];
                InputArrayNumber[CountFromNextNumberToTheLast] = temp;
            }
        }
}

void SortDesc(int* &InputArrayNumber, int ArrayNumberLength)
{
    int temp;
    for(int CountToTheSecondLast = 0; CountToTheSecondLast < ArrayNumberLength - 1; CountToTheSecondLast++)
        for(int CountFromNextNumberToTheLast = CountToTheSecondLast+1; CountFromNextNumberToTheLast < ArrayNumberLength; CountFromNextNumberToTheLast++)
        {
            if(InputArrayNumber[CountFromNextNumberToTheLast] > InputArrayNumber[CountToTheSecondLast])
            {
                temp = InputArrayNumber[CountToTheSecondLast];
                InputArrayNumber[CountToTheSecondLast] = InputArrayNumber[CountFromNextNumberToTheLast];
                InputArrayNumber[CountFromNextNumberToTheLast] = temp;
            }
        }
}

void showArray(int* InputArrayNumber, int ArrayNumberLength)
{
    cout<<" Your Numbers : "<<endl;
    for(int NumberCount=0;NumberCount<ArrayNumberLength;NumberCount++)
    {
        cout<< InputArrayNumber[NumberCount] << " " ;
    }
    cout<<endl;
}


int main()
{
    int NumberQuantity;
    int* ArrayNumber;

    bool IsProgramRunning = true;
    int WidthBorderMenus = 70;
    int choice;
    bool IsInput = false;
    int InputChoice = 1;
    int Exit = 8;

    while(IsProgramRunning != false)
    {
        cout<<endl<<endl<<endl;
        for(int countBorder = 1; countBorder < WidthBorderMenus; countBorder++)
            cout<<"-";
            cout<<endl;
        cout<<" MENU BAR "<<endl;
        for(int countBorder = 1; countBorder < WidthBorderMenus; countBorder++)
            cout<<"-";
        cout<<endl;
        cout<<"1. Input number."<<endl;
        cout<<"2. Find the Minimum Number."<<endl;
        cout<<"3. Find the Maximum Number."<<endl;
        cout<<"4. Find the number has largest frequent existence."<<endl;
        cout<<"5. Sort ascending"<<endl;
        cout<<"6. Sort descending"<<endl;
        cout<<"7. Show your input Numbers."<<endl;
        cout<<"8. Exit !"<<endl;
        for(int countBorder = 1; countBorder < WidthBorderMenus; countBorder++)
            cout<<"-";
        cout<<endl;
        cout<<"Let me know your choice !"<<endl;
        YourChoice : cout<<"My choice is : ";
        cin >> choice;
        cout<<endl;

        if(IsInput != true)
        {
            if (choice != InputChoice && choice != Exit)
            {
                cout<<"Input numbers are empty ! Please make your choice again !"<<endl;
                goto YourChoice;
            }
        }

        switch(choice)
        {
            case 1: delete[] ArrayNumber;
                    Input(ArrayNumber,NumberQuantity);
                    IsInput = true;
                    break;
            case 2: cout<<"The Minimum Number is : " << findMin(ArrayNumber,NumberQuantity)<<endl;
                    break;
            case 3: cout<<"The Maximum Number is : "<<findMax(ArrayNumber,NumberQuantity)<<endl;
                    break;
            case 4: cout<<"The number has largest frequent existence : "<< findMostFreq(ArrayNumber,NumberQuantity)<<endl;
                    break;
            case 5: SortAsc(ArrayNumber,NumberQuantity);
                    cout<<"Sort Completed ! Now show your array !"<<endl;
                    break;
            case 6: SortDesc(ArrayNumber,NumberQuantity);
                    cout<<"Sort Completed ! Now show your array !"<<endl;
                    break;
            case 7: showArray(ArrayNumber,NumberQuantity);
                    break;
            case 8: cout<<"Exit program !"<<endl;
                    IsProgramRunning = false;
                    delete[] ArrayNumber;
                    break;
            default: cout<<"Invalid Choice! Please choose again : ";
                     cin>>choice;
                     cout<<endl;
                     break;
        }
    }
    return 0;
}
