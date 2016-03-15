#ifndef GAME_VECTOR_CPP
#define GAME_VECTOR_CPP
#include "game_vector.hpp"
#include <cstdlib> // to get access the rand() and srand() functions
#include <ctime> // to get access to the time() function and time_t type
#include <vector>
using namespace std;

Child::Child() {  }
Child::Child( const string &name ) : name(name) { }
string Child::getName() { return name; }

Game::Game() {  }
Game::~Game() {  }

void Game::add_child (const string &name) {
    circle.push_back(new Child(name));
}

string Game::remove_child(int position) {
    if (circle.empty()) {
        return "";
    } else {
        position %= circle.size();
        string name = circle.at(position)->getName();
        circle.erase(circle.begin() + position);
        return name;
    }
}

void Game::get_names_from_file(ifstream &f) {
	string s; s.clear();
	while (f >> s) {
		circle.push_back(new Child(s));
	}
}

int Game::get_child_count() { return circle.size(); }

int Game::rand_child(int end, int start = 0) {
    /*
     *  return a random integer between "start" and "end"
     */
    time_t s;
    srand(unsigned(time(&s)));
    return rand() % (end - start) + start;
}
#endif
