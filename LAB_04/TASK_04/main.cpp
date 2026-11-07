#include<iostream>
#include<string>
#include"TextEditor.h"
using namespace std;
int main() {
    TextEditor editor;
    int choice;
    char ch; 
    do {
        cout << "------ TEXT EDITOR ------" << endl;
        cout << "1. Type a Character" << endl;
        cout << "2. Delete a Character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Display Text" << endl;
        cout << "0. Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter character: ";
            cin >> ch;
            editor.type(ch);
        } 
        else if (choice == 2) {
            editor.deleteChar();
        } 
        else if (choice == 3) {
            editor.undo();
        } 
        else if (choice == 4) {
            editor.redo();
        }
        else if (choice == 5) {
            editor.display();
        }
        else if (choice == 0) {
            cout << "Exiting Text Editor." << endl; 
        }  
    } while (choice != 0);

    return 0;
}