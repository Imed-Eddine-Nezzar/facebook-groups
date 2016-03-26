#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
#define MAX_SIZE 5

void readArray(double arr[], int size) {
    // fill array with values from the stdin
    int i;
    for (i = 0; i < size;i++)
        scanf("%lf", &arr[i]);
}

void printArray(double arr[], int size) {
    // print array elements to the stdout
    int i;
    for (i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int min(double arr[], int size) {
    // return the index of the smallest element.
    int min = 0,
        i;
    for (i = 1; i < size; i++)
        if (arr[i] < arr[min])
            min = i;
    return min;
}

int max(double arr[], int size) {
    // return the index of the largest element.
    int max = 0,
        i;
    for (i = 0; i< size; i++)
        if (arr[max] < arr[i])
            max = i;
    return max;
}

double average(double arr[], int size) {
    // return the average of all the elements.
    double sum = 0;
    int i;
    for (i = 0; i < size; i++)
        sum += arr[i];
    return (sum / size);
}

int aboveAverage(double arr[], int size){
    // return the number of elements above average.
    int counter = 0,
        i;
    double s = average(arr, size);
    for (i = 0; i < size; i++)
        if(arr[i] > s)
            counter += 1;
    return counter;
}

int find(double value, double arr[], int size){
    // return true (1) if value is found, false (0) otherways.
    int i;
    for (i = 0; i < size; i++)
        if (arr[i] == value) 
            return true;
    return false;
}

int occurrences(double value, double arr[], int size){
    // return the number of occurrences of value in arr[].
    int counter = 0,
        i;
    for (i = 0; i < size; i++)
        if (arr[i] == value)
            ++counter;
    return counter;
}

int pairs(double arr[], int size) {
    // return number of pairs in arr[].
    int i, counter = 0;
    for (i = 0; i < size; ++i)
        if (fmod(arr[i], 2) == 0)
            ++counter;
    return counter;
}

double unpairsAverage(double arr[], int size) {
    // return the average of all unpair elements.
    int i, counter = 0;
    float sum = 0;
    for (i = 0; i < size; ++i)
        if (fmod(arr[i], 2) != 0) {
            sum += arr[i];
            ++counter;
        }
    return (sum / counter);
}

void reverse(double arr[], int size) {
    // reverse arr[] inplace.
    int i, j;
    double tmp;
    for (i = 0, j = size - 1; i < j; ++i, --j) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int removeFives(double arr[], int size) {
    // remove all mutiplicators of 5, returns new size
    int j = 0,
        i = 0;
    for (i = 0, j = 0; j < size; ++j)
        if (fmod(arr[j], 5) != 0) {
            arr[i] = arr[j];
            ++i;
        }
    return i;
}

// helper function
void sep() { printf("%s\n", "---------------------------------------"); }

int main() {
    int choice = 14, 
        size = MAX_SIZE;
    double t[size];
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
        "10 Moyenne des element impairs du arrleaun\n"
        "11 Inverser les element de tableau\n"
        "12 Effacer tout les mul de 5 du tableau\n"
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
                printf("Min index: %d, Min value: %.2f\n", m, t[m]);
                sep();
                break;
            }
            case 4:{    // print max
                int m = max(t, size);
                sep();
                printf("Max index: %d, Max value: %.2f\n", m, t[m]);
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
                double value;
                printf("Enter value: ");
                scanf("%lf", &value);
                sep();
                printf("Value %.f occurred %d time(s)!\n", value, occurrences(value, t, size));
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
