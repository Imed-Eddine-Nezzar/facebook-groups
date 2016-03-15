/*
    Copyright © 2015 Imed Eddine Nezzar

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <string>
#include "dict.hpp"
using namespace std;


int main (void) {
    Dictionary dict;
    char choice;
    string stri, strii;
    while (true) {
        cout <<
            "Dictionary v 2.0\n"
            "==============\n\n"
            "1. Add a word.\n"
            "2. Delete a word.\n"
            "3. Translate a word.\n"
            "4. List all words.\n"
            "there are " << dict.getWordCount() << " words in dictionary.\n\n"
            "Enter your choice [q to quit]: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter word [French English]: ";
                cin >> stri >> strii;
                if (!dict.exist(stri) or !dict.exist(strii)) {
                    dict.addEntry(stri, strii);
                    cout << stri << " <=> " << strii << " added!\n" << endl;
                } else {
                    cout << "Word already in dictionary!\n" << endl;
                }
                break;

            case '2':
                cout << "Enter word: ";
                cin >> stri;
                if (dict.exist(stri)) dict.delEntry(stri);
                else cout << stri << " not found in dictionary!\n" << endl;
                break;

            case '3':
                cout << "Enter word: ";
                cin >> stri;
                cout << stri.append(PADDING - stri.length(), ' ')
                     << " => " << dict.translate(stri) + "\n" << endl;
                break;

            case '4':
                dict.listEntries();
                break;
            case 'q':
                return 0;
            default:
                cout << "Invalid input!\n\n" << endl;
        }
    }
    return -1;
}
