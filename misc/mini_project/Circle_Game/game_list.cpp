#ifndef GAME_LIST_CPP
#define GAME_LIST_CPP
#include <iostream>
#include <fstream>
#include <cstdlib> // to get access the rand() and srand() functions
#include <ctime> // to get access to the time() function and time_t type
#include "game_list.hpp" // header file with all the definitions

using namespace std;

// constructor
Child::Child(const string &name, Child *next = NULL) : name(name), next(next) {};

Game::Game() {
    /*
     *  initialize the game
     */
    head = NULL;
    child_count = 0;
}

Game::~Game() {
    // TODO: implement this
}

bool Game::is_empty() { return head == NULL; }

void Game::add_child(const string &name) {
    /*
     *  add a child with the given to the circle
     *  
     *  complexity: O(1)
     */
    Child *t = new Child(name);
    if (is_empty()) {
        head = t;
        tail = t;
    } else {
        tail->next = t;
        tail = t;
    }
    ++child_count; // update the children count
}

string Game::remove_child(int pos) {
    /* 
     *  remove and return the child object at the given
     *  position "pos"
     * 
     *  complexity: O(n)
     */
    pos %= child_count; // remove full circles
    Child *cur = head,
          *pre = head;
    if (pos == 0) head = head->next; // first child
    else {
        while(pos--) {
            pre = cur;
            cur = cur->next;
        }
    }
    pre->next = cur->next; // unlinking the child from the circle
    string name = cur->name; // get the name of the child
    delete cur; // destroy the child object
    --child_count; // update children counter
    return name; // return the name of the child
}

int Game::rand_child(int end, int start = 0) {
    /*
     *  return a random integer between "start" and "end"
     */
    time_t s;
    srand(unsigned(time(&s)));
    return rand() % (end - start) + start;
}

void Game::get_names_from_file(ifstream &f) {
    /*
     *  parse the given file and populate the children circle
     *  
     *  complexity: O(n)
     */
    string s; s.clear();
    while(f >> s) {
        add_child(s);
    }
}

void Game::list_all_children() {
    Child *iter = head;
    while(iter) {
        cout << iter->name << endl;
        iter = iter->next;
    }
}
#endif
