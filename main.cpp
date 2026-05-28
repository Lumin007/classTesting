#include <fstream>
#include <string>
#include <chrono>
#include <iostream>
#include <exception>

using namespace std;

class Konto {
private:
    string name;
    string nr;
    double betrag;

public:

    Konto(string name, string nr) {
        this->name = name;
        this->nr = nr;
        betrag = 0;
    }

    void einzahlen(double money) {
        betrag = betrag + money;
    }

    void auszahlen(double money) {
        if (money > betrag) {
            throw runtime_error("Fehler: Nicht genug Geld auf dem Konto!");
        }
        betrag = betrag - money;
    }

    void ueberweisen(Konto& zielkonto, double money) {
        if (money > betrag) {
            throw runtime_error("Fehler: Nicht genug Geld auf dem Konto!");
        }
        this->auszahlen(money);
        zielkonto.einzahlen(money);
    }

    void kontostand_anzeigen() {
        cout << name << " (" << nr << "): " << betrag << " Euro" << endl;
    }
};

int main() {
    Konto k1("BOB", "1");
    Konto k2("ALICE", "2");

    try {
        k1.einzahlen(200);
        k2.einzahlen(200);
        k1.auszahlen(50);
        k1.ueberweisen(k2, 100);
        k1.kontostand_anzeigen();
        k2.kontostand_anzeigen();
        k1.ueberweisen(k2, 250);
        k2.auszahlen(500);

    } catch (const exception& e) {

        cerr << "\nError: " << e.what() << endl;
    }

    return 0;
}