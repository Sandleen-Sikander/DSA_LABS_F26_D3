#pragma once
#include<iostream>
#include"string"
using namespace std;
class TextEditor {
private:
    string text;
    string undoStack[100];
    string redoStack[100];
    int undoSize;
    int redoSize;
public:
    //CONSTRUCTOR
    TextEditor() {
        text = "";
        undoSize = 0;
        redoSize = 0;
    } 
    void type(char ch) {
        if (undoSize < 100) {
            undoStack[undoSize] = text;
            undoSize++;
            text = text + ch;
            redoSize = 0;
            cout << "Text Added Sucessfully." << endl;
        }
    } 
    void deleteChar() {
        if (text.length() > 0 && undoSize < 100) {
            undoStack[undoSize] = text;
            undoSize++;
            text = text.substr(0, text.length() - 1);
            redoSize = 0;
            cout << "Text Deleted Sucessfully." << endl;
        }
    } 
    void undo() {
        if (undoSize > 0 && redoSize < 100) {
            redoStack[redoSize] = text;
            redoSize++; 
            undoSize--;
            text = undoStack[undoSize];
            cout << "Undo Sucessfully." << endl;
        }
        else {
            cout << "NOTHING TO UNDO!" << endl;
        }
    } 
    void redo() {
        if (redoSize > 0 && undoSize < 100) {
            undoStack[undoSize] = text;
            undoSize++;

            redoSize--;
            text = redoStack[redoSize];
            cout << "Redo Sucessfully." << endl;
        }
        else {
            cout << "NOTHING TO REDO!" << endl;
        }
    } 
    void display() {
        cout << "Current Text: " << text << endl;
    }

};

