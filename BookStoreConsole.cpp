
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

class Book {
public:
    string bookName;
    int quant;
    bool chkInStock(string bookName, int quant) {
        cout << "Checking stock...\n";
        if (quant > 0) {
            cout << "The book " << bookName << " is in stock!\n";
            cout << quant << " books left\n" << endl;
            return true;
        }
        else {
            cout << "The book " << bookName << " is not available\n" << endl;
            return false;
        }
    }
    void buy() {
        quant--;
        cout << "Book purchased!\n" << endl;
    }
};


int main()
{
    bool stocked = true;
    bool avail;
    int choiceNum;
    int choice = 0;
    Book book1;
    Book book2;
    Book book3;
    book1.bookName = "Code 02 - how it all begun";
    book1.quant = 3;
    book2.bookName = "Death squad vs Weed squad";
    book2.quant = 5;
    book3.bookName = "The Book";
    book3.quant = 2;
    while (stocked) {
        int ovquant = book1.quant + book2.quant + book3.quant; //overall stock quantity
        if (ovquant <= 0) {
            stocked = false; //if out of stock, the loop stops
        }
        cout << "What do you wanna do?" << endl << "1 for buying, 2 for checking stock" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Pick a book: " << endl;
            cin >> choiceNum;
            switch (choiceNum) {
            case 1:
                avail = book1.chkInStock(book1.bookName, book1.quant); //checking if book is in stock
                if (avail) {
                    book1.buy();
                }
                break;
            case 2:
                avail = book2.chkInStock(book2.bookName, book2.quant);
                if (avail) {
                    book2.buy();
                }
                break;
            case 3:
                avail = book3.chkInStock(book3.bookName, book3.quant);
                if (avail) {
                    book3.buy();
                }
                break;
            }
        }
        else if (choice == 2) {
            cout << "Pick a book: " << endl;
            cin >> choiceNum;
            switch (choiceNum) {
            case 1:
                book1.chkInStock(book1.bookName, book1.quant);
                break;
            case 2:
                book2.chkInStock(book2.bookName, book2.quant);
                break;
            case 3:
                book3.chkInStock(book3.bookName, book3.quant);
                break;
            }
        }
    }
    cout << "Sorry, we ran out of books, closing now." << endl;
}

