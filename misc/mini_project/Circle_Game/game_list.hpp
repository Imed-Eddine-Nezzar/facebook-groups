#ifndef GAME_LIST_HPP // include guard
#define GAME_LIST_HPP
#include <iostream>
#include <fstream> // for reading files

using namespace std;

// Child declaration
class Child {
    public:
        Child(); // constructor
        Child(const string &, Child *); // destructor
        inline string get_name() { return name; }; // return the name of the child
    private:
        string name; // name of the child
        Child *next; // pointer to the next child object
        friend class Game; // grant access to the Game class
};

// Game declaration
class Game {
    public:
        Game(); // constructor
        ~Game(); // destructor
        bool is_empty(); // check if the circle is empty
        void add_child(const string &); // add child to the circle
        string remove_child(int); // remove child from the circle and return his name
        inline int get_child_count() { return child_count; } // return the children count
        inline int rand_child(int, int); // generate a random number between start and end
        void get_names_from_file(ifstream &); // read children names from a file
        void list_all_children(); // print all the names of the children
    private:
        Child *head; // first child in the circle
        Child *tail; // last child in the circle
        int child_count; // number of children in the circle
};
#include "game_list.cpp"
#endif
