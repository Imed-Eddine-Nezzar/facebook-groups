#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*************************************************
 * Child definition
 ************************************************/
class Child {
    public:
        Child();
        Child(const string &);
        ~Child();
        string getName(); // return the child's name
    private:
        string name; // child name
        friend class Game; // grant access to the Game class
};

/*************************************************
 * Game definition
 ************************************************/
class Game {
    public:
        Game(); // constructor
        ~Game(); // destroctur
        void add_child(const string &); // add child to the game
        string remove_child(int); // remove child from the game
        int get_child_count();
        int rand_child(int, int);
        void get_names_from_file(ifstream &);

    private:
        vector<Child*> circle; // a vector to contain the circle
};
#include "game_vector.cpp"
#endif
