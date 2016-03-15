#ifndef DICT_HPP
#define DICT_HPP

#define PADDING 10
// defining entry
class Entry {
    private:
        std::string fr, // French
               en; // English
        Entry *next; // pointer to the next Entry
    friend class Dictionary; // granting access to Dictionary class
};

// defining Dictionary
class Dictionary {
    private:
        int word_count;
        Entry *head;
    public:
        // prototypes
        Dictionary(); // constructor
        ~Dictionary(); // destructor
        bool isEmpty(); // checks if the dictionary if empty
        int getWordCount(); // return number of entries
        bool exist(const std::string &); // check if the entry exists
        void addEntry(const std::string &, const std::string &); // add entry to the dictionary
        void delEntry(const std::string &); // delete entry from the dictionary
        void listEntries(); // print all entries to the screen
        const std::string translate(const std::string &); // return word translation
};

#include "dict.cpp"
#endif
