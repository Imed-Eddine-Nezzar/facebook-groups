#include <stdio.h>
#define true 1
#define false 0
#define MAX_SIZE 5

void readArray(int tab[], int size) {
    int i;
    for (i = 0; i < size;i++)
        scanf("%d", &tab[i]);
}

//affichage:
void printArray(int tab[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int min(int tab[], int size) {
    // return the index of the smalist element.
    int min = 0,
        i;
    for (i = 1; i < size; i++)
        if (tab[i] < tab[min])
            min = i;
    return min;
}

int max(int tab[], int size) {
    // return the index of the largest element.
    int max = 0,
        i;
    for (i = 0; i< size; i++)
        if (tab[max] < tab[i])
            max = i;
    return max;
}

float average(int tab[], int size) {
    float sum = 0;
    int i;
    for (i = 0; i < size; i++)
        sum += tab[i];
    return (sum / size);
}

int aboveAverage(int tab[], int size){
    // return the number of elements above average.
    int counter = 0,
        i;
    int s = average(tab, size);
    for (i = 0; i < size; i++)
        if(tab[i] > s)
            counter += 1;
    return counter;
}

int find(int value, int tab[], int size){
    int i;
    for (i = 0; i < size; i++)
        if (tab[i] == value) 
            return true;
    return false;
}

int occurrences(int value, int tab[], int size){
    int counter = 0,
        i;
    for (i = 0; i < size; i++)
        if (tab[i] == value)
            ++counter;
    return counter;
}

int pairs(int tab[], int size) {
    int i, counter = 0;
    for (i = 0; i < size; ++i)
        if (tab[i] % 2 == 0)
            ++counter;
    return counter;
}

float unpairsAverage(int tab[], int size) {
    int i, counter = 0;
    float sum = 0;
    for (i = 0; i < size; ++i)
        if (tab[i] % 2 != 0) {
            sum += tab[i];
            ++counter;
        }
    return (sum / counter);
}

void reverse(int tab[], int size) {
    int i, j;
    int tmp;
    for (i = 0, j = size - 1; i < j; ++i, --j) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }
}

int removeFives(int tab[], int size) {
    // remove all mutiplicators of 5, return new size
    int j = 0,
        i = 0;
    for (i = 0, j = 0; j < size; ++j)
        if (tab[j] % 5 != 0) {
            tab[i] = tab[j];
            ++i;
        }
    return i;
}

// helper function
void sep() { printf("%s\n", "---------------------------------------"); }

int main() {
    int choice = 14, 
        size = MAX_SIZE,
        t[size];
    do{
        // main menu
        printf(
        "\n\nchoisir un operations avec sa numero\n"
        "=================================\n"
        "1  Lire le tableau\n"
        "2  Affichier le tableau\n"
        "3  Affiche Min\n"
        "4  Affiche Max\n"
        "5  Affichier le moyenne\n"
        "6  Determener si un valeur > moyenne\n"
        "7  Vérifier si un valeur exists dans le tableau\n"
        "8  Nombre apparition d'une valeur dans le tableau\n"
        "9  Valeur paires du tableau\n"
        "10 Moyenne des element impairs du tableaun\n"
        "11 Inverser les element de tableau\n"
        "12 Effacer tout les mul de 5 du tableu\n"
        "13 Quitter\n"
        );

        // getting choice
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        // processing choice
        switch (choice) {
            case 1:     // read array
                sep();
                printf("Enter array elments: ");
                readArray(t, size);
                sep();
                break;
            case 2:     // print array
                sep();
                printf("Array elements: ");
                printArray(t, size);
                sep();
                break;
            case 3: {   // print min
                int m = min(t, size);
                sep();
                printf("Min index: %d, Min value: %.d\n", m, t[m]);
                sep();
                break;
            }
            case 4:{    // print max
                int m = max(t, size);
                sep();
                printf("Max index: %d, Max value: %d\n", m, t[m]);
                sep();
                break;
            }
            case 5:     // print average
                sep();
                printf("Average: %.2f\n", average(t, size));
                sep();
                break;
            case 6:     // above average count
                sep();
                printf("Above average: %d\n", aboveAverage(t, size));
                sep();
                break;
            case 7: {  // find element
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                sep();
                printf("Value %d %s found!\n", value, (find(value, t, size) ? "\b":"not"));
                sep();
                break;
            }
            case 8: {   // number of occurrences
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                sep();
                printf("Value %d occurred %d time(s)!\n", value, occurrences(value, t, size));
                sep();
                break;
            }
            case 9:     // pair values
                sep();
                printf("Number of pair values is %d\n", pairs(t, size));
                sep();
                break;
            case 10:    // unpair average
                sep();
                printf("Average of unpair values: %.2f\n", unpairsAverage(t, size));
                sep();
                break;
            case 11:    // reverse elements
                reverse(t, size);
                sep();
                printArray(t, size);
                sep();
                break;
            case 12: {   // remove fives
                size = removeFives(t, size);
                sep();
                printArray(t, size);
                sep();
                break;
            }
            case 13:    // quit
                return 0;
            default:
                printf("Not a valid choice!\n");
        }
    } while (choice != 13);
    return -1;
}