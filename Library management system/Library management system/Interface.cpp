#include <iostream>
#include "Linked_list.h"
#include "Book.h"
using namespace std;
Linked_list <Book> libraryBooks;
// Function which help user to regiser a new book in the library
void registerBook(Linked_list <Book>& bookList)
{
    Book newBook;
    newBook.registerBook();
    bookList.push_back(newBook);
    cout << "\nThe book registerd successfully\n";
}
// Function which make user add new copy for certain book
void addNewCopy(Linked_list <Book>& bookList)
{
    int ISBNtemp;
    bool founded;
    cout << "Please enter the book ISBN : ";
    cin >> ISBNtemp;
    for (Linked_list<Book>::listIterator it = bookList.begin(); it != bookList.End(); it++)
    {
        if (it.getCurrent().data.getISBN() == ISBNtemp)
        {
            it.getCurrent().data.addCopy();
            founded = 1;
            break;
        }
        else
        {
            founded = 0;
        }
    }
    if (!founded)
    {
        cout << "Please try to enter right ISBN \n";
    }
    else
    {
        cout << "The copy has been rigestered successfully\n";
    }
}
// Function which allow the user to borrow a book
void borrowBook(Linked_list <Book>& bookList)
{
    int ISBNtemp;
    bool founded;
    cout << "Please enter the book ISBN : ";
    cin >> ISBNtemp;
    for (Linked_list<Book>::listIterator it = bookList.begin(); it != bookList.End(); it++)
    {
        if (it.getCurrent().data.getISBN() == ISBNtemp)
        {
            it.getCurrent().data.borrow();
            founded = 1;
            break;
        }
    }
    if (!founded)
    {
        cout << "Please try to enter right ISBN \n";
    }
    else
    {
        cout << "The copy has been borrowed successfully\n";
    }
}
// Function which allow the user to return borrowed book
void returnBorrowed(Linked_list <Book>& bookList)
{
    int ISBNtemp;
    bool founded;

    cout << "Please enter the book ISBN : ";
    cin >> ISBNtemp;
    for (Linked_list<Book>::listIterator it = bookList.begin(); it != bookList.End(); it++)
    {
        if (it.getCurrent().data.getISBN() == ISBNtemp)
        {
            it.getCurrent().data.returnBorrowed();
            founded = 1;
            break;
        }
        else
        {
            founded = 0;
        }
    }
    if (!founded)
    {
        cout << "Please try to enter correct ISBN\n";
    }
}
// Function to display all borrowed books
void displayBorrowed(Linked_list <Book>& bookList)
{
    bool founded = 0;

    for (Linked_list<Book>::listIterator it = bookList.begin(); it != bookList.End(); it++)
    {
        if (it.getCurrent().data.borrowedSize() != 0)
        {
            cout << "Book name : " << it.getCurrent().data.getName() << endl;
            cout << "Book ISBN : " << it.getCurrent().data.getISBN() << endl;
            cout << "============ Borrowed Copies of the book ============\n\n";
            it.getCurrent().data.displayBorrowed();
            founded = 1;
        }
    }
    if (!founded)
    {
        cout << "There is no borrowed book\n";
    }
}
// Function to display library statistics
void libraryStat(Linked_list <Book>& bookList)
{
    if (libraryBooks.listSize() == 0)
    {
        cout << "There is no books in the shelve\n";
    }
    else
    {
        for (Linked_list<Book>::listIterator it = bookList.begin(); it != bookList.End(); it++)
        {
            cout << "============== Book info ============== \n\n";
            cout << "Book name : " << it.getCurrent().data.getName() << endl;
            cout << "Book ISBN : " << it.getCurrent().data.getISBN() << endl;
            cout << "============== Book statistics ============== \n\n";
            cout << "Book copies in the library : " << it.getCurrent().data.getCopies() << endl;
            cout << "Book borrowed copies : " << it.getCurrent().data.borrowedSize() << endl;
        }
    }
}
int main()
{
    while (true)
    {
        string operation;
        cout << "1- Register new book\n";
        cout << "2- Add new copy\n";
        cout << "3- Borrow a book\n";
        cout << "4- Return a borrowed book\n";
        cout << "5- Diplay all borrowed books\n";
        cout << "6- Display library statistics\n";
        cout << "7-Exit\n";
        cin >> operation;
        if (operation == "1")
        {
            registerBook(libraryBooks);
        }
        else if (operation == "2")
        {
            addNewCopy(libraryBooks);
        }
        else if (operation == "3")
        {
            borrowBook(libraryBooks);
        }
        else if (operation == "4")
        {
            returnBorrowed(libraryBooks);

        }
        else if (operation == "5")
        {
            displayBorrowed(libraryBooks);
        }
        else if (operation == "6")
        {
            libraryStat(libraryBooks);
        }
        else if (operation == "7")
        {
            return 0;
        }
        else
        {
            system("cls");
        }
    }
}
