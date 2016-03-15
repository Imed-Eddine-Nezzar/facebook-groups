#include <stdio.h>
int main(void) {
    char *jours[7] = {"Samedi" , "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi"};
    char *mois[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
    int j, m, a;
    // getting the year
    printf("entrer le nombre du année: "); scanf("%d", &a);
    // getting a valid month
    do {
        printf("entrer le nombre du mois: "); scanf("%d", &m);
    } while (m < 1 || m > 12);
    // calculating the end olf the month
    int end_of_month = 31;
    // month = 2
    if (m == 2) {
        if (a % 4 == 0) end_of_month = 29;
        else if (a % 100 == 0) end_of_month = 28;
        else if (a % 400 == 0) end_of_month = 29;
        else end_of_month = 28;
    }
    // month = 4, 6, 9, 11
    else {
        int i = 4;
        while (i <= 12) {
            if (m == i) end_of_month = 30;
            if (i == 6) i += 3;
            else i += 2;
        }
    }
    // getting the day
    do {
        printf("entrer le nombre du jour: "); scanf("%d", &j);
    } while (j < 1 || j > end_of_month);

    // printing the date
    printf("la date entree est: %s %d %s %d\n", jours[(j - 1) % 7], j, mois[m - 1], a);
}
