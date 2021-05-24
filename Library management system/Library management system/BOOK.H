#ifndef BOOK_H
#define BOOK_H
#pragma  warning (disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
#include "Linked_list.h"
#include <queue>
using namespace std;
class Book
{
    struct copy
    {
        string copyDate;
        bool status;
        string borrower;
        string borrowDate;
        int copyID;
        int daysLeft;
    };

    string bookName;
    int bookISBN;
    int copiesNO;
    queue <copy> bookCopies;
    Linked_list <copy> borrowedBook;
public:
    string getName()
    {
        return this->bookName;
    }
    int getISBN()
    {
        return this->bookISBN;
    }
    int getCopies()
    {
        return this->copiesNO;
    }
    void addCopy()
    {
        copy newCopy;
        cout << "Enter the date of the copy : ";
        cin >> newCopy.copyDate;

        cout << "Enter the ID of copy : ";
        cin >> newCopy.copyID;
        newCopy.status = 0;
        newCopy.borrower = "NULL";
        newCopy.daysLeft = 0;
        newCopy.borrowDate = "NULL";
        bookCopies.push(newCopy);
        copiesNO++;
    }
    void registerBook()
    {
        cout << "Enter the book name : ";
        cin >> bookName;
        cout << "Enter the book ISBN : ";
        cin >> bookISBN;
    }
    void borrow()
    {
        if (bookCopies.size() == 0)
        {
            cout << "There is no copies for this book\n";
        }
        else
        {
            copy newBorrowed;
            string borrower;
            cout << "Enter the borrower name : ";
            cin >> borrower;
            time_t date = time(0);
            char* stringDate = ctime(&date);
            bookCopies.front().borrowDate = stringDate;
            bookCopies.front().borrower = borrower;
            bookCopies.front().daysLeft = 15;
            bookCopies.front().status = 1;
            newBorrowed = bookCopies.front();
            bookCopies.pop();
            borrowedBook.push_back(newBorrowed);
            cout << "The book name is " << this->bookName << endl;
            cout << "The book ISBN is : " << this->bookISBN << endl;
            cout << "The book copy date is : " << newBorrowed.copyDate << endl;
            cout << "The book is borrowed by : " << newBorrowed.borrower << endl;
            cout << "The book borrow date is : " << newBorrowed.borrowDate << endl;
            cout << "You have " << newBorrowed.daysLeft << " days left to return the book" << endl;
        }
    }
    int copiesSize()
    {
        return bookCopies.size();
    }
    void displayCopies()
    {
        if (bookCopies.size() == 0)
        {
            cout << "There is no copies for this book\n";
        }
        else
        {
            //displayCopies(this->bookCopies);
        }
    }
    void displayBorrowed()
    {
        if (borrowedBook.listSize() != 0)
        {
            for (Linked_list<copy>::listIterator it = borrowedBook.begin(); it != borrowedBook.End(); it++)
            {
                cout << "===============================\n";
                cout << "Copy ID : " << it.getCurrent().data.copyID << endl;
                cout << "Copy Date : " << it.getCurrent().data.copyDate << endl;
                cout << "Copy Date : " << "Borrowed" << endl;
                cout << "Copy Borrower : " << it.getCurrent().data.borrower << endl;
                cout << "Borrow Date : " << it.getCurrent().data.borrowDate << endl;
                cout << "Days left to return the copy : " << it.getCurrent().data.daysLeft << endl;
                cout << "===============================\n";
            }
        }
        else
        {
            cout << "There is no borrowed copies\n";
        }
    }
    int borrowedSize()
    {
        return this->borrowedBook.listSize();
    }
    void returnBorrowed()
    {
        bool founded;
        int counter = 1;
        copy returnedCopy;
        int ID;
        cout << "Please enter copy-ID : ";
        cin >> ID;
        for (Linked_list<copy>::listIterator it = borrowedBook.begin(); it != borrowedBook.End(); it++)
        {
            if (it.getCurrent().data.copyID == ID)
            {
                returnedCopy = it.getCurrent().data;
                bookCopies.push(returnedCopy);
                borrowedBook.erase(counter);
                founded = 1;
                break;
            }
            else
            {
                founded = 0;
                counter++;
            }
        }
        if (founded == 0)
        {
            cout << "Please return a right copy-ID\n";
        }
        else
        {
            cout << "The returned operation has been done\n";
        }

    }
    friend void printqueue(queue <copy> copyQueue)
    {
        while (!copyQueue.empty())
        {
            cout << "===============================\n";
            cout << "Copy ID : " << copyQueue.front().copyID;
            cout << "Copy date : " << copyQueue.front().copyDate << endl;
            cout << "Copy status : Not borrowed " << endl;
            cout << "===============================\n";
            copyQueue.pop();
        }
    }
    Book()
    {}
    ~Book()
    {}
};
#endif // BOOK_H

