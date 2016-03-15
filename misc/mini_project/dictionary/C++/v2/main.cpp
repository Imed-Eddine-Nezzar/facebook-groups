#include <iostream>
#include "dict.hpp"
#include "util.hpp"
#include "init_dict.cpp"
using namespace std;
using namespace Dictionary;
using namespace Util;

/* tests
 * =====
 * [X] init_dict()
 * [X] add_word()
 * [X] remove_word()
 * [X] translate()
 * [X] parser()
 * [ ] translator
 * [X] construct_string()
 */


int main (void) {
    // initializing the dictionary
    Entry *dict = NULL;
    dict = init_dict(dict);

    // displaying the menu
    cout <<
        "\n-- Dictionnaire Français / Anglais ------\n"
        << endl;

    // setting the language
    int lang;
    do {
        cout <<
            "1. Français => Anglais\n"
            "2. Anglais => Français\n"
            "Choisez la langue: ";
        cin >> lang;
    } while (lang != 1 && lang != 2);

    // displaying choices
    char choice;
    while (true) {
        cout <<
            "\n-- Dictionnaire Français / Anglais ------\n"
            "1. Ajouter un mot.\n"
            "2. Supprimer un mot.\n"
            "3. Traduire un mot.\n"
            "4. Traduire un block text.\n"
            "5. Afficher les mot dans le dictionnaire.\n\n"
            "Votre choix [q pout quiter]: ";
        cin >> choice;

        switch (choice) {
            case '1': { // add a word
                string str_1, str_2;
                cout << sep << endl;
                cout << "Le mot en Français: ";
                cin >> str_1;
                cout << "Le mot en Anglais: ";
                cin >> str_2;
                dict = add_word(str_2, str_1, dict);
                cout << sep << endl;
                cout << "**** le mot a été ajouté ****" << endl;
                cout << sep << endl;
                break;
            }
            case '2': { // remove a word
                string str;
                cout << sep << endl;
                cout << "Entrez le mot: ";
                cout << sep << endl;
                cin >> str;
                dict = remove_word(str, dict);
                break;
            }
            case '3': { // translate a word
                string word, translation;
                cout << sep << endl;
                cout << "Entrez le mot: ";
                cin >> word;
                cout << sep << endl;
                translation = translate(word, lang, dict);
                cout << word << " => " << translation << endl;
                cout << sep << endl;
                break;
            }

            case '4': { // translate text
                string text;
                cout << "------- Entrez votre text: ---------" << endl;
                cin.ignore();
                getline(cin, text);

                Text *words = NULL;
                words = parser(text);

                words = translator(words, lang, dict);
                text = construct_string(words);
                cout << "------- Translation ----------------\n"
                    << text << endl;
                cout << sep << endl;
                break;
            }

            case '5': { // list all words
                cout << "------- Les mots -------------------\n";
                Entry *t = dict;
                while(t) {
                    cout << t->fr << " <=> " << t->en << endl;
                    t = t->next;
                }
                cout << sep << endl;
                break;
            }
            case 'q': return 0; // quit

            default: 
                cout << sep << endl;
                cout << "Choix inconnue!" << endl;
                cout << sep << endl;
        }
    }
    return 1;
}
