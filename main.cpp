// Mobin Panahandeh
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <windows.h>  

using namespace std;

long long int codemelli;
int clockintotal, clockouttotal;
int undertime = 0, overtime = 0;
int clockinh, clockinmin;
int clockouth, clockoutmin;
int overtimeh = 0, overtimemin = 0;
int undertimeh = 0, undertimemin = 0;

void printl()
{
    cout << "---------------------------------------------------------\n";
}

void askTime()
{

    cout << "Please enter your clock-in hour.\n";
    cin >> clockinh;
    printl();
    while (clockinh > 14 | clockinh < 6)
    {
        cout << "Invalid clock-in hour.\nPlease try again.\n";
        cin >> clockinh;
        printl();
    }

    cout <<"Please enter your clock-in minute.\n";
    cin >> clockinmin ;
    printl();
    while (clockinmin > 59 | clockinmin < 0)
    {
        cout << "Invalid clock-in minute.\nPlease try again.\n";
        cin >> clockinmin;
        printl();
    }
    while (clockinh == 14 && clockinmin >= 30)
    {
        cout << "Invalid clock-in minute.\n Please try again.\n";
        cin >> clockinmin;
        printl();
    }
    
    
    cout << "Please enter your clock-out hour.\n";
    cin >> clockouth;
    printl();
    while (clockouth > 23 | clockouth < clockinh | clockouth < 0)
    {
        cout << "Invalid clock-out hour.\nPlease try again.\n";
        cin >> clockouth;
        printl();
    }

    cout << "Please enter your clock-out minute.\n";
    cin >> clockoutmin;
    printl();
    while (clockoutmin > 59)
    {
        cout << "Invalid clock-out minute.\nPlease try again.\n";
        cin >> clockoutmin;
        printl();
    }
    while (clockinh == clockouth && clockoutmin <= clockinmin)
    {
    cout << "your clock-in time and clock-out time can not be the same.\n"
         << "Please enter another clock-out minute.\n";
    cin >> clockoutmin;
    printl();
    }
}

int hourMinToTotal(int h, int min)
{
    int total;
    total = (h*60+min);

    return total;
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
    string name;
    fstream file;
    file.open("File.txt", ios::app);
    if (file.is_open())
    {
        undertime = 0;
        overtime = 0;
        cout << "Please enter your id code.\n";
        cin >> codemelli;
        printl();
        while ( 9999999999 < codemelli | codemelli < 1000000000)
        {
            cout << "invalid ID.\nPlease try again.\n";
            cin >> codemelli;
            printl();
        }

        cout << "Please enter your full name.\n";
        cin.ignore();
        getline(cin, name);
        printl();
       
        askTime();
        
        clockintotal = hourMinToTotal(clockinh, clockinmin);
        clockouttotal = hourMinToTotal(clockouth, clockoutmin);

        
        if (clockintotal > 420)
        {
            undertime += clockintotal - 420;
        }
        else
        {
            overtime += 420 - clockintotal ;
        }

        if (clockouttotal > 870)
        {
            overtime += clockouttotal - 870;
        }
        else
        {
            undertime += 870 - clockouttotal;
        }
        
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

        clockintotal = 0, clockouttotal = 0;
        overtimeh = 0, overtimemin = 0;
        overtime = 0, undertime = 0;
        undertimeh = 0, undertimemin = 0;
        clockinh = 0, clockinmin = 0;
        clockouth = 0, clockoutmin = 0;

    }
    else
    {
        cerr << "There is a problem with your file.\n";
        printl();
    }
    file.close();
    system("cls");

}

void editEntry()
{   
    string fileline ;
    string userinput ;
    fstream old("File.txt", ios::in);
    fstream neew("File1.txt", ios::out);
    cout << "please enter the id\n";
    cin >> userinput;
    printl();
    if (neew.is_open())
    {
        while (!old.eof())
        {
            undertime = 0;
            overtime = 0;

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
                int b;
                for ( int i =12 ; i <= myWord.size()+1; i++)
                {
                    if (myArray[i] == '#')
                    {
                         b = i+1;
                         break;
                    }
                    
                }
               
                askTime();

                clockintotal = hourMinToTotal(clockinh, clockinmin);
                clockouttotal = hourMinToTotal(clockouth, clockoutmin);
                
                if (clockintotal > 420)
                {
                    undertime += clockintotal - 420;
                }
                else
                {
                    overtime += 420 - clockintotal ;
                }

                if (clockouttotal > 870)
                {
                    overtime += clockouttotal - 870;
                }
                else
                {
                    undertime += 870 - clockouttotal;
                }

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
                neew << setfill('0') << setw(2) << overtimemin << endl;       
                
                clockintotal = 0, clockouttotal = 0;
                overtime = 0, undertime = 0;
                overtimeh = 0, overtimemin = 0;
                undertimeh = 0, undertimemin = 0;
                clockinh = 0, clockinmin = 0;
                clockouth = 0, clockoutmin = 0;
            }
        }
        
    }
    else
    { cerr << "Ther is a problem with your file.\n";
        printl();
    }
    old.close();
    neew.close();
    remove("File.txt");
    rename("File1.txt", "File.txt");
    system("cls");
}

int main()
{   
    system("color 1");
    system("cls");
    printl();
    int option;
    cout << "Welcome\n";
    do
    {
        printl();
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
            system("color 7");
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