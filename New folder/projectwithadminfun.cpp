#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

/*
1. menu
2. user registration (sign up)
3. user login (sign in)
4. Exit
5. input validation
*/

string user_name[100] = {"hello", "hanzala", "ABDULLAH AMEEN", "abdullah jamsahid", "Abdul Hadi"};
string passwords[100] = {"123", "1234", "1232", "12323", "21412"};

// Parallel initialization of book data
int Id[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
string Name[100] = {"Peer-e-Kamil", "Mushaf", "Jannat Kay Pattay", "Zaviya", "Udaas Naslain", "Raja Gidh", "Shahab Nama", "Dastak Naa Do", "Mirza Ghalib", "Aangan", "How to train your dragon", "ABD"};
string Author[100] = {"Umera Ahmed", "Nimra Ahmed", "Nimra Ahmed", "Ashfaq Ahmed", "Abdullah Hussain", "Bano Qudsia", "Qudrat Ullah Shahab", "Mustansar Hussain Tarar", "Mirza Asadullah Khan Ghalib", "Khadija Mastoor", "Abdullah", "ABD"};
int Quantity[100] = {5, 7, 10, 6, 5, 8, 6, 9, 7, 4, 3, 1};

int totalUsers = 5;
int totalnumberofbooks = 12; // Initialize to 11, as books are hardcoded initiallint
int iddbookofborrow=0;
string nameofbook;


void Menu();
void signUp(string user, string password);
bool signIn(string user, string password);
bool isUserPresent(string user);
void isuseradmin();
void total_names_of_user();
void del_user();
void Booksmanagement();
void NumberofBooks();
void additionofBook();
void delofbooks();
void borrowbookslist();
void usersfunction();
void serchthebook();
void serching();
void borrowthebookbyuser();

int main()
{
    cout << "Welcome to the Sign In/Sign Up page!" << endl;

    int choice;

    do
    {
        Menu();
        cin >> choice;

        string user, password;
        switch (choice)
        {
        case 1:
            // Sign Up
            cout << "Sign Up" << endl;
            cout << "Enter your user: ";
            cin >> user;
            cout << "Enter your password: ";
            cin >> password;
            if (isUserPresent(user))
            {
                cout << "User already exists" << endl;
                break;
            }
            else
            {
                signUp(user, password);
            }
            break;
        case 2:
            // Sign In
            cout << "Sign In" << endl;
            cout << "Enter your User Name : ";
            cin >> user;
            cout << "Enter your password: ";
            cin >> password;

            if (signIn(user, password))
            {
                choice = 3; // Exit after sign in
            }
            break;
        case 3:
            cout << "Exiting..." << endl;
            return 0;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 3);

    // getch();
    system("cls");

    return 0;
}

void signUp(string user, string password)
{
    user_name[totalUsers] = user;
    passwords[totalUsers] = password;
    totalUsers++;
}

bool signIn(string user, string password)
{
    if (user == "admin" && password == "123")
    {
        system("cls");
        isuseradmin();
        return true;
    }

    for (int i = 0; i < totalUsers; i++)
    {
        if (user_name[i] == user)
        {
            if (passwords[i] == password)
            {

                usersfunction();
                return true;
            }
        }
    }
    cout << "Invalid user or password" << endl;
    getch();
    system("cls");
    return false;
}

bool isUserPresent(string user)
{
    for (int i = 0; i < totalUsers; i++)
    {
        if (user_name[i] == user)
        {
            return true;
        }
    }
    return false;
}

void Menu()
{
    cout << "\n===================================================\n";
    cout << "\n            LIBRARY - USER SYSTEM         \n";
    cout << "\n===================================================\n";
    cout << "  1. Sign Up                       \n";
    cout << "  2. Sign In                       \n";
    cout << "  3. Exit                          \n";
    cout << "\n===================================================\n";
    cout << " Enter your choice: ";
}

void isuseradmin()
{
    int choice;
agaimadmin:
    cout << "\n===================================================\n";
    cout << "             WELCOME DEAR ADMIN \n";
    cout << "\n===================================================\n";
    cout << "\n1.Checking number of users.\n";
    cout << "2.Deleting the user\n";
    cout << "3.Book Management System \n";
    cout << "4.Name of People borrowed the books. \n";
    cout << "5.Exit \n";
    cout << "\nEnter the choice: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        total_names_of_user();
        break;
    case 2:
        del_user();
        break;
    case 3:
        Booksmanagement();
        break;
    case 4:
        borrowbookslist();
    default:
        Menu();
    }
    getch();
    system("cls");
    goto agaimadmin;
}

void total_names_of_user()
{
    cout << "TOTAL USERS ARE: " << totalUsers << "\n";
    for (int i = 0; i < totalUsers; i++)
    {
        cout << "\n"
             << i << " User Name is || " << user_name[i] << " and The Password is || " << passwords[i];
    }
    cout << "\n=======================================================\n";
}

void del_user()
{
    int indexnumber;
    for (int i = 0; i < totalUsers; i++)
    {
        cout << "\n"
             << i << " User Name is || " << user_name[i] << " and The Password is || " << passwords[i];
    }

    do
    {
        cout << "\nEnter the index number: ";
        cin >> indexnumber;
        if (indexnumber < 0 || indexnumber >= totalUsers)
        {
            printf("Please enter a correct index number.\n");
        }
    } while (indexnumber < 0 || indexnumber >= totalUsers);

    for (int i = indexnumber; i < totalUsers - 1; i++)
    {
        user_name[i] = user_name[i + 1];
        passwords[i] = passwords[i + 1];
    }
    cout << "\n===================================================\n";
    cout << "             AFTER DELETING THE USER: ";
    cout << "\n===================================================\n";

    for (int i = 0; i < totalUsers - 1; i++)
    {
        cout << "\n"
             << i << " User Name is || " << user_name[i] << " and The Password is || " << passwords[i];
    }
    totalUsers--;
    cout << "\n UPDATED NUMBER OF USERS: " << totalUsers;
    cout << "\n===================================================\n";
}

void Booksmanagement()
{
    int choice;
    cout << "\n===================================================\n";
    cout << "               ADMIN MENU           \n";
    cout << "\n===================================================\n";
    cout << "1. View All Books\n";
    cout << "2. Add Books\n";
    cout << "3. Delete Books\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        NumberofBooks();
        break;
    case 2:
        additionofBook();
        break;
    case 3:
        delofbooks();
        break;
    case 4:
        isuseradmin();
        break;
    default:
        cout << "Invalid choice" << endl;
        Booksmanagement();
        break;
    }
}

void NumberofBooks()
{
    cout << "\n===================================================\n";
    cout << "               LIBRARY BOOKS LIST                  ";
    cout << "\n===================================================\n";
    for (int i = 0; i < totalnumberofbooks; i++)
    {
        cout << "ID: " << Id[i] << ", Name: " << Name[i] << ", Author: " << Author[i] << ", Quantity: " << Quantity[i] << endl;
    }
    cout << "\n===================================================\n";
    getch();
    Booksmanagement();
}

void additionofBook()
{
    cout << "\nEnter Book Name: ";
    cin >> Name[totalnumberofbooks];

    cout << "Enter Author Name: ";
    cin >> Author[totalnumberofbooks];

    cout << "Enter Quantity: ";
    cin >> Quantity[totalnumberofbooks];

    Id[totalnumberofbooks] = totalnumberofbooks + 1;

    cout << "\nBook added successfully with ID: " << Id[totalnumberofbooks] << endl;

    totalnumberofbooks++;
    getch();
    system("cls");
    Booksmanagement();
}

void delofbooks()
{
    int indexnumber;

    for (int i = 0; i < totalnumberofbooks; i++)
    {
        cout << "\n"
             << "Book ID: " << i + 1 << ", Name: " << Name[i] << ", Author: " << Author[i] << ", Quantity: " << Quantity[i];
    }

    do
    {
        cout << "\nEnter ID number (1 to " << totalnumberofbooks << "): ";
        cin >> indexnumber;
        if (indexnumber < 1 || indexnumber > totalnumberofbooks)
        {
            cout << "Please enter a valid ID number between 1 and " << totalnumberofbooks << ".\n";
        }
    } while (indexnumber < 1 || indexnumber > totalnumberofbooks);

    indexnumber--;

    for (int i = indexnumber; i < totalnumberofbooks - 1; i++)
    {
        Id[i] = Id[i + 1];
        Name[i] = Name[i + 1];
        Author[i] = Author[i + 1];
        Quantity[i] = Quantity[i + 1];
    }

    cout << "\n===================================================\n";
    cout << "             AFTER DELETING THE BOOK: ";
    cout << "\n===================================================\n";

    for (int i = 0; i < totalnumberofbooks - 1; i++)
    {
        cout << "\n"
             << "Book ID: " << i + 1 << ", Name: " << Name[i] << ", Author: " << Author[i] << ", Quantity: " << Quantity[i];
    }

    totalnumberofbooks--;
    cout << "\n UPDATED NUMBER OF BOOKS: " << totalnumberofbooks;
    cout << "\n===================================================\n";
    getch();
    Booksmanagement();
}
/////exist keri jao to kuch or he kr raha hai usay bh esahe kerna han yaad sa
void borrowbookslist()
{
    cout << "\n===================================================\n";

    printf("                     WORKing....");
    cout << "\n===================================================\n";

    Booksmanagement();
}

void usersfunction()
{

    int choice;
agaimadmin:
    cout << "\n===================================================\n";
    cout << "             WELCOME DEAR " << user_name << " \n";
    cout << "\n===================================================\n";
    cout << "\n1.Book Serching.\n";
    cout << "2.Borrowing the Books\n";
    cout << "3. \n";
    cout << "4.\n";
    cout << "5.Exit \n";
    cout << "\nEnter the choice: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        serchthebook();
        break;
    case 2:
        borrowthebookbyuser();
        break;
    case 3:

        break;
    case 4:

    default:
        Menu();
    }
    getch();
    system("cls");
    goto agaimadmin;
}

void serchthebook()
{

    cout << "\n===================================================\n";
    cout << "               LIBRARY BOOKS LIST                  ";
    cout << "\n===================================================\n";
    for (int i = 0; i < totalnumberofbooks; i++)
    {
        cout << "ID: " << Id[i] << ", Name: " << Name[i] << ", Author: " << Author[i] << ", Quantity: " << Quantity[i] << endl;
    }
    cout << "\n===================================================\n";
    // getch();
    serching();
}
void serching()
{

    
    cout << "\n===================================================\n";
    cout << "Enter the book name: ";
    cin >> nameofbook;

    for (int i = 0; i < totalnumberofbooks; i++)
    {
        if (Name[i] == nameofbook)
        {
            cout << "ID: " << Id[i] << ", Name: " << Name[i] << ", Author: " << Author[i] << ", Quantity: " << Quantity[i] << endl;
   
    // iddbookofborrow=Quantity[i]-1;
    // Quantity[i]=iddbookofborrow;
        }
    }
    cout << "\n===================================================\n";
}
void borrowthebookbyuser()
{
    char yesorno;
     cout << "\n===================================================\n";
    cout << "               LIBRARY BOOKS LIST                  ";
    cout << "\n===================================================\n";
    for (int i = 0; i < totalnumberofbooks; i++)
    {
        cout << "ID: " << Id[i] << ", Name: " << Name[i] << ", Author: " << Author[i] << ", Quantity: " << Quantity[i] << endl;
    }
    cout << "\n===================================================\n";
    serching(); // Find the book

    if (iddbookofborrow == -1)
    {
        cout << "Book not found. Please try again." << endl;
        getch();
        return;
    }

    cout << "\n===================================================\n";
    cout << "Are you sure you want to borrow this Book (y/n): ";
    cin >> yesorno;

    if (yesorno == 'y' || yesorno == 'Y')
    {
        if (Quantity[iddbookofborrow] > 0)
        {
            Quantity[iddbookofborrow]--; // Decrease the quantity
            cout << "Book borrowed successfully!\n";
            cout << "Remaining Quantity: " << Quantity[iddbookofborrow] << endl;
        }
        else
        {
            cout << "Sorry, this book is out of stock." << endl;
        }
    }
    else
    {
        cout << "Borrowing canceled." << endl;
    }

    cout << "\n===================================================\n";
    getch();
}