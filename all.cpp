#include <iostream>
#include <string>
#include <random>

using namespace std;

void Sailor_quantity(const int sailor_quantity, const int sailor_steps, long int & average_sailor_final, long int & average_sailor_final_squered);
int Sailor_final_place(const int sailor_steps);

int main()
{
    const int sailor_quantity = 10000;
    int sailor_steps = 100;
    int max_steps = 1000000
        for (sailor_steps; sailor_steps <= max_steps; sailor_steps=sailor_steps*10) {
        // Zmienne do przechowywania i zliczania wartości średnich potrzebnych do obliczenia odchylenia standardowego.
        long int average_sailor_final = 0;
        long int average_sailor_final_squered = 0;

        Sailor_quantity(sailor_quantity, sailor_steps, average_sailor_final, average_sailor_final_squered);

        // Dzielenie int/int tak by wynik był double.
        double average1 = average_sailor_final;
        double average2 = average_sailor_final_squered;
        double sailor_quantity_double = sailor_quantity;
        double average_sailor_final_double = average1 / sailor_quantity_double;
        double average_sailor_final_squered_double = average2 / sailor_quantity_double;

        double varianty = average_sailor_final_squered_double - (average_sailor_final_double * average_sailor_final_double);
        double standard_deviation = sqrt(varianty);

        // Wypisanie obliczonych wartości
        cout << "Sailor steps: " << sailor_steps << endl;
        cout << "Number of sailors: " << sailor_quantity << endl;
        cout << "Average sailor finals place:" << average_sailor_final_double << endl;
        cout << "Average sailor finals place squered: " << average_sailor_final_squered_double << endl;
        cout << "Wariancja: " << varianty << endl;
        cout << "Odchylenie standardowe: " << standard_deviation << endl;
        cout << endl;
    }
    return 0;
}

// Funkcja odpowiedzialna za obliczenie miejsca do którego dojdzie "sailor_quantity" ilości marynarzy którzy wykonują "sailor_steps" kroków.
void Sailor_quantity(const int sailor_quantity, const int sailor_steps, long int & average_sailor_final, long int & average_sailor_final_squered) {
    int sailor_final = 0;
    for (int j = 0; j < sailor_quantity; j++) {
        sailor_final = Sailor_final_place(sailor_steps);
       // cout << sailor_final << endl;
    }
    average_sailor_final = average_sailor_final + sailor_final;
    average_sailor_final_squered = average_sailor_final_squered + (sailor_final * sailor_final);
}

// Funkcja odpowiedzialna za wyznaczenie miejsca do którego dojdzie marynarz po "sailor_steps" krokach.
int Sailor_final_place(const int sailor_steps) {
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_real_distribution<> dis(0.0, 1.0);  // Losowanie liczby z zakresu (0,1) rozkład jednostajny.
    int sailor_final = 0;
    double sailor_decision;
    for (int k = 0; k < sailor_steps; k++) {
        if (sailor_decision = dis(gen) > 0.5) {
            sailor_final++;
        }
        else
            sailor_final--;
    }
    return sailor_final;
}
