#ifndef UTIL_CPP
#define UTIL_CPP
#include <string>
#include <vector>
#include "dict.hpp"
#include "util.hpp"

using namespace std;

Text *Util::parser (const string &s) {
    int i = 0,
        j = s.find(' ');
    Text *head = NULL;
    if (j < 0) {
        Text *u = new Text;
        u->word = s.substr(i, s.length());
        u->next = head;
        head = u;
    }
    while (j >= 0) {
        Text *u = new Text;
        u->word = s.substr(i, j - i);
        u->next = head;
        head = u;
        i = ++j;
        j = s.find(' ', j);
        if (j < 0) {
            Text *u = new Text;
            u->word = s.substr(i, s.length());
            u->next = head;
            head = u;
        }
    }
    return head;
}

Text *Util::translator(Text *text, int l,Entry *dict) {
    Text *t = text;
    while (t) {
        t->word = translate(t->word, l, dict);
        t = t->next;
    }
    return text;
}

string Util::construct_string (Text *str) {
    string s = "",
           word;
    Text *t = str;
    while (t) {
        word = t->word + " ";
        s.insert(0, word);
        t = t->next;
    }
    return s;
}
#endif
