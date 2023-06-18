#include <iostream>
#include <string>
using namespace std;


int main()
{   
    int option;
    cout << "Welcome\n";
    do
    {
        cout << "1. New entry\n2. Edit past entry\n0. Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "New entry\n";
            break;
        case 2:
            cout << "Edit entry\n";
            break;
        case 0:
            cout << "Goodbye\n";
            exit;
        default:
            cout << "Option not valid\nPlease try again\n";
            break;
        }
    } while (option != 0);
    
    
}