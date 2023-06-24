// Mobin Panahandeh
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>

using namespace std;

const int stdworkmin = 420;
int undertime = 0;
int overtime = 0;

void printl()
{
    cout << "---------------------------------------------------------\n";
}

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
    if (file.is_open())
    {
        
        cout << "Please enter your id code.\n";
        cin >> codemelli;
        while ( 9999999999 < codemelli)
        {
            cout << "invalid ID.\nPlease try again.\n";
            cin >> codemelli;
        }
        while (codemelli < 1000000000 )
        {
            cout << "invalid ID.\nPlease try again.\n";
            cin >> codemelli;
        }
        
        
        cout << "Please enter your full name.\n";
        cin.ignore();
        getline(cin, name);

        cout << "Please enter your clock-in hour.\n";
        cin >> clockinh; 
        while (clockinh>14)
        {
            cout << "Invalid clock-in hour.\nPlease try again.\n";
            cin >> clockinh;
        }
        while (clockinh > 23)
        {
            cout << "Invalid clock-in hour.\nPlease try again.\n";
            cin >> clockinh;
        }

        cout <<"Please enter your clock-in minute.\n";
        cin >> clockinmin ;
        while (clockinmin > 59)
        {
            cout << "Invalid clock-in minute.\nPlease try again.\n";
            cin >> clockinmin;
        }
        
        cout << "Please enter your clock-out hour.\n";
        cin >> clockouth;
        while (clockouth > 23)
        {
            cout << "Invalid clock-out hour.\nPlease try again.\n";
            cin >> clockouth;
        }
        while (clockouth < clockinh)
        {
            cout << "Invalid clock-out hour.\nPlease try again.\n";
            cin >> clockouth;
        }

        cout << "Please enter your clock-out minute.\n";
        cin >> clockoutmin;
        while (clockoutmin > 59)
        {
            cout << "Invalid clock-out minute.\nPlease try again.\n";
            cin >> clockoutmin;
        }
        
        
        
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
    {
        cerr << "There is a problem with your file.\n";
    }
    file.close();
    system("cls");

}

void editEntry()
{   
    int clockintotal, clockouttotal;
    int clockinh, clockinmin;
    int clockouth, clockoutmin;
    int overtimeh = 0, overtimemin = 0;
    int undertimeh = 0, undertimemin = 0;
    int diffcalreturn;
    string fileline ;
    string userinput ;
    fstream old("File.txt", ios::in);
    fstream neew("File1.txt", ios::out);
    cout << "please enter the id\n";
    cin >> userinput;
    if (neew.is_open())
    {
        while (!old.eof())
        {

            char check[100];
            getline(old, fileline);
            
            for (int i = 0; i < 10; i++)
            {
                check [i] = fileline [i];
            }
            check[10] = '\0';
            int res = userinput.compare(check);
            if (res!=0)
                neew << fileline << endl;
            else
            {   

                string myWord = fileline;
                char myArray[myWord.size()+1];
                strcpy(myArray, myWord.c_str()); 
                int j = 0 ;
                int b;
                for ( int i =12 ; i <= myWord.size()+1; i++)
                {
                    if (myArray[i] == '#')
                    {
                         b = i+1;
                         j++;
                         break;
                    }
                    
                }
               
                cout << "Please enter your clock-in hour.\n";
                cin >> clockinh; 
                while (clockinh>14)
                {
                    cout << "Invalid clock-in hour.\nPlease try again.\n";
                    cin >> clockinh;
                }
                while (clockinh > 23)
                {
                    cout << "Invalid clock-in hour.\nPlease try again.\n";
                    cin >> clockinh;
                }

                cout <<"Please enter your clock-in minute.\n";
                cin >> clockinmin ;
                while (clockinmin > 59)
                {
                    cout << "Invalid clock-in minute.\nPlease try again.\n";
                    cin >> clockinmin;
                }
                
                cout << "Please enter your clock-out hour.\n";
                cin >> clockouth;
                while (clockouth > 23)
                {
                    cout << "Invalid clock-out hour.\nPlease try again.\n";
                    cin >> clockouth;
                }
                while (clockouth < clockinh)
                {
                    cout << "Invalid clock-out hour.\nPlease try again.\n";
                    cin >> clockouth;
                }

                cout << "Please enter your clock-out minute.\n";
                cin >> clockoutmin;
                while (clockoutmin > 59)
                {
                    cout << "Invalid clock-out minute.\nPlease try again.\n";
                    cin >> clockoutmin;
                }
                clockintotal = hourMinToTotal(clockinh, clockinmin);
                clockouttotal = hourMinToTotal(clockouth, clockoutmin);
                diffcalc(clockouttotal - clockintotal);
                overtimeh = totalToHour(overtime);
                overtimemin = totalToMin(overtime);
                undertimeh = totalToHour(undertime);
                undertimemin = totalToMin(undertime);                

                neew << userinput << '#';
                for (int i = 11; i < b-1 ; i++)
                {
                    neew << myArray[i];
                }
                neew << "#";
                neew << setfill('0') << setw(2) << clockinh << ":" ;
                neew << setfill('0') << setw(2) << clockinmin << "#";
                neew << setfill('0') << setw(2) << clockouth << ":" ;
                neew << setfill('0') << setw(2) << clockoutmin << "#";
                neew << setfill('0') << setw(2) << undertimeh << ":" ;
                neew << setfill('0') << setw(2) << undertimemin << "#" ;
                neew << setfill('0') << setw(2) << overtimeh << ":" ;
                neew << setfill('0') << setw(2) << overtimemin << endl ;       
                
            }
        }
        
    }
    else
        cerr << "Ther is a problem with your file.\n";
    old.close();
    neew.close();
    remove("File.txt");
    rename("File1.txt", "File.txt");
    system("cls");
    // system("pause");
}

int main()
{   
    system("cls");
    printl();
    int option;
    cout << "Welcome\n";
    do
    {
        cout << "1. New entry\n2. Edit past entry\n0. Exit\n";
        printl();
        cin >> option;
        switch (option)
        {
        case 1:
            newEntry();
            break;
        case 2:
            editEntry();
            break;
        case 0:
            break;
        default:
            printl();
            cout << "Option not valid\nPlease try again\n";
            printl();
            break;
        }
    } while (option != 0);
    system("cls");
    cout << "Goodbye";
}