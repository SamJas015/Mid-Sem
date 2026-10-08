#include <iostream>
using namespace std;

class Book
{
    string title;
    string author;

public:

    Book(string t, string a)
    {
        title = t;
        author = a;
    }


    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main()
{

    Book book1("Harry Potter", "J.K. Rowling");
    Book book2("The Alchemist", "Paulo Coelho");

    cout << "Book 1:" << endl;
    book1.display();

    cout << endl;

    cout << "Book 2:" << endl;
    book2.display();

    return 0;
}
