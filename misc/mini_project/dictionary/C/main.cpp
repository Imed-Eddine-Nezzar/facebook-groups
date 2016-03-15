#include <iostream>
#include "init_db.h"

// declaring external trackers
extern entry *head, *tail;

// external functions declarations
bool isEmpty (entry *head);
void cls(void);
void insertFirst (std::string w_fr, std::string w_en, entry *&head, entry *&tail);
void push (std::string w_fr, std::string w_en, entry *&head);
void append (std::string w_fr, std::string w_en, entry *&tail);
std::string search (std::string w, std::string w_lang, entry *head);
bool remove (std::string w, entry *head);
void listEntries (entry *head);
void init();

int main (void) {
    init();
    while (true) {
        // declaring variables
        std::string stri, strii;
        char choice;
        std::cout << std::endl;
        std::cout << "Dictionary v 1.0" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << "1. Add a new word to the dictionary." << std::endl;
        std::cout << "2. Delete a word from the dictionary." << std::endl;
        std::cout << "3. Translate word." << std::endl;
        std::cout << "4. List all word in dictionary." << std::endl;
        std::cout << "[1,2,3,4][q to quit][c to clear the screan]: ";
        std::cin >> choice;

        // processing input
        switch (choice) {
            case '1': // adding a new word
                std::cout << std::endl << "Enter the word in French: ";
                std::cin >> stri;
                std::cout << "Enter the word in English: ";
                std::cin >> strii;
                if (isEmpty(head)) insertFirst(stri, strii, head, tail);
                else push(stri, strii, head);
                std::cout << std::endl << "Word add!" << std::endl;
                break;

            case '2': // deleting a word
                std::cout << std::endl << "Enter the word to delete: ";
                std::cin >> stri;
                if (rm(stri, head)) {
                    rm(stri, head);
                    std::cout << std::endl << "Word deleted!" << std::endl;
                }
                else std::cout << "Word not found in dictionary!" << std::endl;
                break;

            case '3': // translating stri
                // TODO: implement translation
                std::cout << std::endl << "Enter the word and its language [word lang]: ";
                std::cin >> stri >> strii;
                std::cout << std::endl << stri << " = " << search(stri, strii, head) << std::endl;
                break;

            case '4': // listing entries
                if (isEmpty(head)) std::cout << std::endl << "There are no words in the dictionary!" << std::endl;
                else listEntries(head);
                break;
            case 'c':
                cls();
                break;

            case 'q': // quiting the program
                return 0;

            default: // help message
                std::cout << "Enter a valid choice [1,2,3,4][q to quit]" << std::endl;
        }
    }
}
