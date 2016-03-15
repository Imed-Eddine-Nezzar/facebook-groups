#define SWITCH_LIST_VECTOR 0 // to compile with list set this to '1', vector '0'
#include <iostream>

#if SWITCH_LIST_VECTOR
	#include "game_list.hpp"
#else
	#include "game_vector.hpp"
#endif

using namespace std;

// helper function
void sep() { string s(40, '-'); cout << s << endl; }

int main (void) {
	Game circle; // creating a game object
	ifstream f("names.txt");
	circle.get_names_from_file(f);
	sep();
	cout << "## There are " << circle.get_child_count() << " child in the circle." <<  endl;
	sep();
	cout << "Starting the Game!";
#if SWITCH_LIST_VECTOR
	cout << "~~Chained list mode~~" << endl;
#else
	cout << "~~Vector mode~~" << endl;
#endif
	sep();
	string name;
	int pos;

	while(circle.get_child_count() > 0) {
		pos = circle.rand_child(circle.get_child_count());
		name = circle.remove_child(pos);
		if (circle.get_child_count() == 0) {
			sep();
			cout << "The winner is: " << name << endl;
			sep();
		} else {
			cout << "\nremoving child at position: " << pos << endl;
			cout << name << " is out of the circle, children left: " << circle.get_child_count() << endl;
			cin.get();
		}
	}
	return 0;
}
