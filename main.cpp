#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int stdworkmin = 420;
int undertime = 0;
int overtime = 0;

int hourMinToTotal(int h, int min)
{
    int total;
    total = (h*60+min);

    return total;
}

void diffcalc(int x)
{
    if(x >= 450)
    {
        overtime = x-450;
        undertime = 0;
    }
    else
    {
        undertime = 450-x;
        overtime = 0;
    }
}


int totalToHour(int a)
{
    int hour;
    hour = a/60;
    
    return hour;
}


int totalToMin(int a)
{
    int min;
    min = a % 60;

    return min;
}

void newEntry()
{
    int clockintotal, clockouttotal;
    long long int codemelli;
    string name;
    int clockinh, clockinmin;
    int clockouth, clockoutmin;
    int overtimeh = 0, overtimemin = 0;
    int undertimeh = 0, undertimemin = 0;
    int diffcalreturn;
    fstream file;
    file.open("File.txt", ios::app);
    if (file)
    {
        
        cout << "Please enter your id code.\n";
        cin >> codemelli; 
        cout << "Please enter your full name.\n";
        cin.ignore();
        getline(cin, name);
        cout << "Please enter your clock-in hour and miunte accordingly.\n";
        cin >> clockinh >> clockinmin ;
        cout << "Please enter your clock-out hour and miunte accordingly.\n";
        cin >> clockouth >> clockoutmin;

        clockintotal = hourMinToTotal(clockinh, clockinmin);
        clockouttotal = hourMinToTotal(clockouth, clockoutmin);
        diffcalc(clockouttotal - clockintotal);
        overtimeh = totalToHour(overtime);
        overtimemin = totalToMin(overtime);
        undertimeh = totalToHour(undertime);
        undertimemin = totalToMin(undertime);

        file << codemelli << "#" << name << "#";
        file << setfill('0') << setw(2) << clockinh << ":" ;
        file << setfill('0') << setw(2) << clockinmin << "#";
        file << setfill('0') << setw(2) << clockouth << ":" ;
        file << setfill('0') << setw(2) << clockoutmin << "#";
        file << setfill('0') << setw(2) << undertimeh << ":" ;
        file << setfill('0') << setw(2) << undertimemin << "#" ;
        file << setfill('0') << setw(2) << overtimeh << ":" ;
        file << setfill('0') << setw(2) << overtimemin << endl ;        
    }
    else
        cerr << "There is a problem with your file.\n";
    system("cls");

}

int main()
{   
    system("cls");
    int option;
    cout << "Welcome\n";
    do
    {
        cout << "1. New entry\n2. Edit past entry\n0. Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            newEntry();
            break;
        case 2:
            cout << "Edit entry\n";
            break;
        case 0:
            break;
        default:
            cout << "Option not valid\nPlease try again\n";
            break;
        }
    } while (option != 0);
    system("cls");
    cout << "Goodbye";
}