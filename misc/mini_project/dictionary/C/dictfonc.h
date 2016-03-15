#include <iostream>

// entry definition
// ================
struct entry {
    std::string w_fr, w_en;
    entry *next_entry;
};

// creating global trackers
// =================
entry *head = new entry,
    *tail = new entry;

// functions definitions
// =====================

bool isEmpty (entry *head) {
    return (head == NULL);
}

// clear the screen 
void cls(void) {
    std::cout << "\033[2J\033[1;1H";
}

// insert the first entry
void insertFirst (std::string w_fr, std::string w_en, entry *&head, entry *&tail) {
    entry *t = new entry;
    t->w_fr = w_fr;
    t->w_en = w_en;
    t->next_entry = NULL;
    head = t;
    tail = t;
}

// push an entry on top of the dictionary
void push (std::string w_fr, std::string w_en, entry *&head) {
    entry *t = new entry;
    t->w_fr = w_fr;
    t->w_en = w_en;
    t->next_entry = head;
    head = t;
}

// append an entry on the end of the dictionary
void append (std::string w_fr, std::string w_en, entry *&tail) {
    entry *t = new entry;
    t->w_fr = w_fr;
    t->w_en = w_en;
    t->next_entry = NULL;
    tail->next_entry = t;
    tail = t;
}

// remove entry from a dictionary
bool rm (std::string w, entry *&head) {
    if (isEmpty(head)) return false;
    else {
        entry *cur = head,
              *pre = cur;
        while (cur != NULL) {
            if (cur->w_fr == w or cur->w_en == w) {
                if (cur == head) {
                    head = head->next_entry;
                    delete cur;
                    return true;
                } else {
                    pre->next_entry = cur->next_entry;
                    delete cur;
                    return true;
                }
            }
            pre = cur;
            cur = cur->next_entry;
        }
    }
    return false;
}

// search for an entry in the dictionary
std::string search (std::string w, std::string w_lang, entry *head) {
    if (isEmpty(head)) return w;
    else {
        for (entry *dict_w = head; dict_w != NULL; dict_w = dict_w->next_entry) {
            if (w_lang == "fr") {
                if (dict_w->w_fr == w) return dict_w->w_en;
            } else {
                if (dict_w->w_en == w) return dict_w->w_fr;
            }
        }
    }
    return w;
}

// list dictionary entries
void listEntries (entry *head) {
    std::cout << std::endl << "Listing Dictionary:" << std::endl;
    std::cout << "===================" << std::endl;
    for (entry *t = head; t != NULL; t = t->next_entry){
        std::cout << t->w_fr << " : " << t->w_en << std::endl;
    }
}
