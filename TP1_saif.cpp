// TP1_saif.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Tableau {
    int s;
    long* numerateurs;
    long* denominateurs;
};

Tableau t;

Tableau tableaux(int i) {

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

int main()
{
    std::cout << "Hello World!\n";
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
