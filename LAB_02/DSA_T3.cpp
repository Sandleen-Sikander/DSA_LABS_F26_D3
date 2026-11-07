#include <iostream>
#include <string>
using namespace std;

// Linear Search Template
template <typename T>
int linearSearch(T arr[], T value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Binary Search Template
template <typename T>
int binarySearch(T arr[], T value, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Abstract Class
class LibraryItem
{
public:
    virtual void display() const = 0;
    virtual ~LibraryItem() {}
};

// Book Class
class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() const {
        return title;
    }

    int getPages() const {
        return pages;
    }

    void display() const override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

// Newspaper Class
class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() const {
        return name;
    }

    string getEdition() const {
        return edition;
    }

    void display() const override {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

// Library Class
class Library
{
private:
    Book* books[100];
    Newspaper* newspapers[100];

    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book book) {
        books[bookCount] = new Book(book);
        bookCount++;
    }

    void addNewspaper(Newspaper newspaper) {
        newspapers[newspaperCount] = new Newspaper(newspaper);
        newspaperCount++;
    }

    void displayCollection() {
        cout << "\nBooks:\n";

        for (int i = 0; i < bookCount; i++) {
            books[i]->display();
            cout << endl;
        }

        cout << "Newspapers:\n";

        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i]->display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j]->getPages() > books[j + 1]->getPages()) {
                    Book* temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - i - 1; j++) {
                if (newspapers[j]->getEdition() >
                    newspapers[j + 1]->getEdition()) {
                    Newspaper* temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title)
    {
        string titles[100];

        for (int i = 0; i < bookCount; i++)
        {
            titles[i] = books[i]->getTitle();
        }

        int index = linearSearch(titles, title, bookCount);

        if (index != -1)
            return books[index];

        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name) {
        string names[100];

        for (int i = 0; i < newspaperCount; i++)
        {
            names[i] = newspapers[i]->getName();
        }

        int index = linearSearch(names, name, newspaperCount);

        if (index != -1)
            return newspapers[index];

        return nullptr;
    }

    ~Library() {
        for (int i = 0; i < bookCount; i++)
            delete books[i];

        for (int i = 0; i < newspaperCount; i++)
            delete newspapers[i];
    }
};

int main()
{
    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    // Create newspaper objects
    Newspaper newspaper1(
        "Washington Post",
        "2024-10-13",
        "Morning Edition"
    );

    Newspaper newspaper2(
        "The Times",
        "2024-10-12",
        "Weekend Edition"
    );

    // Create library object
    Library library;

    // Add books and newspapers
    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    // Display collection
    cout << "Before Sorting:\n";
    library.displayCollection();

    // Sort
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    // Search for a book
    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else  {
        cout << "\nBook not found.\n";
    }

    // Search for a newspaper
    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else  {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}