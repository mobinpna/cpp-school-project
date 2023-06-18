#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// int diffCalculator(int a, int b)
// {

//     if (b-a >= 7)
//     {
//         /* code */
//     }
    

// }

void newEntry()
{
       
    long long int codemelli;
    string name;
    int clockinhour, clockinmin;
    int clockouthour, clockoutmin;
    int overtimehour, overtimemin;
    int undertimehour, undertimemin;
    
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
        cin >> clockinhour >> clockinmin ;
        cout << "Please enter your clock-out hour and miunte accordingly.\n";
        cin >> clockouthour >> clockoutmin;
        // diffCalculator(clockinhour, clockouthour);
        file << codemelli << "#" << name << "#" 
        << clockinhour << ":" << clockinmin << "#"
        <<clockouthour << ":" << clockoutmin << "#" << endl;

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