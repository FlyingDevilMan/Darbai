#include <iostream>
#include <iomanip> // skirta nustatyti skaitiniu duomenu tiksluma

using namespace std;

// Valiutos kursai
double GBP_Total = 0.8593;
double GBP_Buy = 0.8450;
double GBP_Sell = 0.9060;
double USD_Total = 1.0713;
double USD_Buy = 1.0547;
double USD_Sell = 1.1309;
double INR_Total = 88.8260;
double INR_Buy = 85.2614;
double INR_Sell = 92.8334;
double EUR_Total = 1.0;  // EUR bazinis kursas yra 1

// Funkcija valiutos kursu palyginimui
void PalygintiKursus(const string& valiuta1, const string& valiuta2, double kursas1, double kursas2) {
    cout << fixed << setprecision(4); // nustatome keturių skaitmenų tikslumą
    cout << "1 " << valiuta1 << " = " << kursas1 << " " << valiuta2 << endl;
    cout << "1 " << valiuta2 << " = " << kursas2 << " " << valiuta1 << endl;
}

// Funkcija valiutai pirkti
double PirktiValiuta(double suma, double kursas) {
    return suma * kursas;
}

// Funkcija valiutai parduoti
double ParduotiValiuta(double suma, double kursas) {
    return suma / kursas;
}

int main() {
    string valiutos[] = {"EUR", "GBP", "USD", "INR"};

    int pasirinkimas;
    string nuoValiutos, ikiValiutos;
    double suma, rezultatas;

    // Ciklas, kuris leis programa kartoti tol, kol vartotojas nuspręs išeiti
    while (true) {
        cout << "Pasirinkite veiksma:" << endl;
        cout << "1. Palyginti valiutos kursus" << endl;
        cout << "2. Pirkti valiuta" << endl;
        cout << "3. Parduoti valiuta" << endl;
        cout << "4. Iseiti" << endl;
        cin >> pasirinkimas;

        // Jei pasirinkimas yra 4 - išeiti iš programos
        if (pasirinkimas == 4) {
            cout << "Programa baigia darba." << endl;
            break; // nutraukia while ciklą ir baigia programą
        }

        if (pasirinkimas == 1) {
            cout << "Iveskite pirmaja valiuta (EUR, USD, GBP, INR): ";
            cin >> nuoValiutos;
            cout << "Iveskite antraja valiuta (EUR, USD, GBP, INR): ";
            cin >> ikiValiutos;

            // Patikriname, ar įvestos valiutos skiriasi
            if (nuoValiutos != ikiValiutos) {
                if (nuoValiutos == "EUR") {
                    if (ikiValiutos == "GBP") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, EUR_Total / GBP_Total, GBP_Total / EUR_Total);
                    } else if (ikiValiutos == "USD") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, EUR_Total / USD_Total, USD_Total / EUR_Total);
                    } else if (ikiValiutos == "INR") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, EUR_Total / INR_Total, INR_Total / EUR_Total);
                    }
                } else if (nuoValiutos == "GBP") {
                    if (ikiValiutos == "USD") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, GBP_Total / USD_Total, USD_Total / GBP_Total);
                    } else if (ikiValiutos == "INR") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, GBP_Total / INR_Total, INR_Total / GBP_Total);
                    } else if (ikiValiutos == "EUR") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, GBP_Total / EUR_Total, EUR_Total / GBP_Total);
                    }
                } else if (nuoValiutos == "USD") {
                    if (ikiValiutos == "GBP") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, USD_Total / GBP_Total, GBP_Total / USD_Total);
                    } else if (ikiValiutos == "INR") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, USD_Total / INR_Total, INR_Total / USD_Total);
                    } else if (ikiValiutos == "EUR") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, USD_Total / EUR_Total, EUR_Total / USD_Total);
                    }
                } else if (nuoValiutos == "INR") {
                    if (ikiValiutos == "GBP") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, INR_Total / GBP_Total, GBP_Total / INR_Total);
                    } else if (ikiValiutos == "USD") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, INR_Total / USD_Total, USD_Total / INR_Total);
                    } else if (ikiValiutos == "EUR") {
                        PalygintiKursus(nuoValiutos, ikiValiutos, INR_Total / EUR_Total, EUR_Total / INR_Total);
                    }
                }
            } else {
                cout << "Sios dvi valiutos yra vienodos." << endl;
            }
        } else if (pasirinkimas == 2) {
            cout << "Iveskite valiuta, kuria norite pirkti (USD, GBP, INR): ";
            cin >> ikiValiutos;
            cout << "Iveskite suma EUR, kuria norite pirkti: ";
            cin >> suma;

            if (ikiValiutos == "GBP") {
                rezultatas = PirktiValiuta(suma, GBP_Buy);
            } else if (ikiValiutos == "USD") {
                rezultatas = PirktiValiuta(suma, USD_Buy);
            } else if (ikiValiutos == "INR") {
                rezultatas = PirktiValiuta(suma, INR_Buy);
            } else {
                cout << "Netinkama valiuta." << endl;
                continue; // grįžtame į pradžią, jeigu buvo klaida
            }

            cout << "Jus gausite " << fixed << setprecision(2) << rezultatas << " " << ikiValiutos << endl;
        } else if (pasirinkimas == 3) {
            cout << "Iveskite valiuta, kuria norite parduoti (USD, GBP, INR): ";
            cin >> nuoValiutos;
            cout << "Iveskite suma " << nuoValiutos << ", kuria norite parduoti: ";
            cin >> suma;

            if (nuoValiutos == "GBP") {
                rezultatas = ParduotiValiuta(suma, GBP_Sell);
            } else if (nuoValiutos == "USD") {
                rezultatas = ParduotiValiuta(suma, USD_Sell);
            } else if (nuoValiutos == "INR") {
                rezultatas = ParduotiValiuta(suma, INR_Sell);
            } else {
                cout << "Netinkama valiuta." << endl;
                continue; // grįžtame į pradžią, jeigu buvo klaida
            }

            cout << "Jus gausite " << fixed << setprecision(2) << rezultatas << " EUR" << endl;
        } else {
            cout << "Netinkamas pasirinkimas." << endl;
        }
    }

    return 0;
}
