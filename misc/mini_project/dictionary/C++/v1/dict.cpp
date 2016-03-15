#ifndef DICT_CPP
#define DICT_CPP
#include "dict.hpp"

Dictionary::Dictionary() {
   head = nullptr;
   word_count = 0;
}

Dictionary::~Dictionary() {
    Entry *t = head;
    while (t) {
        head = head->next;
        delete t;
        t = head;
    }
    word_count = 0;
}


bool Dictionary::isEmpty() { return head == nullptr; }

int Dictionary::getWordCount() {
    return word_count;
}

bool Dictionary::exist(const std::string &s) {
    Entry *t = head;
    while (t) {
        if (t->fr == s or t->en == s) return true;
        t = t->next;
    }
    return false;
}

void Dictionary::addEntry(const std::string &fr, const std::string &en) {
    Entry *t = new Entry;
    t->fr = fr;
    t->en = en;
    t->next = head;
    head = t;
    word_count++;
}

void Dictionary::delEntry(const std::string &s) {
    if (isEmpty()) return;
    Entry *cur = head,
          *pre = head;
    while (cur) {
        if (cur->fr == s or cur->en == s) {
            if (cur == head) head = head->next;
            pre = cur->next;
            delete cur;
            word_count--;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}

void Dictionary::listEntries() {
    Entry *t = head;
    std::cout <<
        "Listing Entries:\n"
        "=================\n" << std::endl;
    while (t) {
        std::cout << t->fr.append(PADDING - t->fr.length(), ' ')
             << " <=> " << t->en << std::endl;
        t = t->next;
    }
    std::cout << std::endl;
}

const std::string Dictionary::translate(const std::string &s) {
    Entry *t = head;
    while (t) {
        if (t->fr == s) return t->en;
        if (t->en == s) return t->fr;
        t = t->next;
    }
    return s;
}
#endif
