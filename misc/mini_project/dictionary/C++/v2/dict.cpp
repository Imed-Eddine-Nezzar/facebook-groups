#ifndef DICT_CPP
#define DICT_CPP
#include "dict.hpp"
using namespace std;
using namespace Dictionary;

Entry *Dictionary::add_word(
        const string &en,
        const string &fr,
        Entry *dict) {
    Entry *t = new Entry;
    t->en = en ; t->fr = fr;
    t->next = dict;
    dict = t;
    return dict;
}

Entry *Dictionary::remove_word(string w, Entry *dict) {
    Entry *cur = dict,
          *pre = dict;
    while(cur) {
        if (cur->fr == w or cur->en == w) {
            pre->next = cur->next;
            delete cur;
        }
        pre = cur;
        cur = cur->next;
    }
    return dict;
}

string Dictionary::translate(
        const string &w,
        int l,
        Entry *dict) {
    Entry *t = dict;
    while (t) {
        if (l == 2  and t->fr == w)
            return t->en;
        if (l == 1 and t->en == w)
            return t->fr;
        t = t->next;
    }
    return w;
}

// Entry Dictionary::init_dict() { }

#endif
