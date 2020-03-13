// TP1_saif.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Tableau {
    int s;
    long* numerateurs;
    long* denominateurs;
};

Tableau t;

Tableau remplirTableaux(int i) {

    int size = 0;
    std::cout << "Saisir combien de fractions vous voulez analyser: ";
    std::cin >> size;
    t.s = size;
    t.numerateurs = new long[size];
    t.denominateurs = new long[size];
    for (i = 0; i < size; i++) {
        std::cout << "Saisir le numerateur ";
        std::cin >> t.numerateurs[i];
        while (t.numerateurs[i] <= 0) {
            std::cout << "Saisir a nouveau ";
            std::cin >> t.numerateurs[i];
        }
        std::cout << "Saisir le denominateur ";
        std::cin >> t.denominateurs[i];
        while (t.denominateurs[i] <= 0) {
            std::cout << "Saisir a nouveau ";
            std::cin >> t.denominateurs[i];
        }
    }
    return t;

}

int calculerPGCD() {

    int i = 0;
    Tableau t = remplirTableaux(i);
    int diviseur, min;
    int pgcd = int(1);
    for (i = 0; i < t.s; i++) {
        if (t.numerateurs[i] <= t.denominateurs[i]) {
            min = t.numerateurs[i];
        }
        else if (t.denominateurs[i] <= t.numerateurs[i]) {
            min = t.denominateurs[i];
        }


        for (diviseur = 1; diviseur <= min; diviseur++) {


            if (t.numerateurs[i] % diviseur == 0 && t.denominateurs[i] % diviseur == 0) {
                pgcd = int(diviseur);
            }
        }

    }

    return pgcd;
}


struct Fraction {

    long* val1_simplifier;
    long* val2_simplifier;
    int diviseur;
    int pgcd;
};
Fraction f;
Fraction simplifierFractions() {

    f.pgcd = calculerPGCD();
    int i = 0;
    f.val1_simplifier = new long[t.s];
    f.val2_simplifier = new long[t.s];
    std::cout << "Saisir le diviseur: ";
    std::cin >> f.diviseur;
    while (f.diviseur == 0) {
        std::cout << "Saisir a nouveau ";
        std::cin >> f.diviseur;
    }

    for (i = 0; i < t.s; i++) {

        f.val1_simplifier[i] = t.numerateurs[i] / long(f.diviseur);
        f.val2_simplifier[i] = t.denominateurs[i] / long(f.diviseur);
    }



    return f;
}

void afficherFractions() {


    Fraction f = simplifierFractions();
    int i = 0;

    if (f.diviseur == f.pgcd) {
        for (i = 0; i < t.s; i++) {
            std::cout << "Simplification finale: " << t.numerateurs[i] << "/" << t.denominateurs[i] << ">>>" << f.val1_simplifier[i] << "/" << f.val2_simplifier[i] << std::endl;
        }
    }
    else {
        std::cout << "Le diviseur saisi n'est pas le plus grand commun diviseur de cette fraction";
    }


}

int main()
{
    afficherFractions();
    delete[] t.numerateurs;
    delete[] t.denominateurs;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
