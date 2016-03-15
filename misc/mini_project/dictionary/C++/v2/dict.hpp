#ifndef DICT_HPP
#define DICT_HPP
using namespace std;

namespace Dictionary {
    // defining a word entry
    typedef struct node {
        string en;
        string fr;
        struct node *next;
    } Entry;

    // defining a text input
    typedef struct input {
        string word;
        struct input *next;
    } Text;

    // initializing the dictionry
    Entry *init_dict(Entry *dict);

    // adding a word to the dictionary
    Entry *add_word(const string &, const string &, Entry *);

    // removing a word from the dictionary
    Entry *remove_word(string w, Entry *dict);

    // return the translation of the word if found
    string translate (const string &, int l, Entry *);

    string sep(40, '-');
}

#include "dict.cpp"
#endif
