
#include <fstream>
#include <string>
#include <chrono>
#include <iostream>

using namespace std;

class Konto {
    private:
    string name;
    string nr;
    double betrag = 0;

    public:
    void konto(string name, string nr) {
        this->name = name;
        this->nr = nr;
    }
    void einzahlen(double money) {
        betrag = betrag + money;
    }
    void auszahlen(double money) {
        betrag = betrag - money;
    }
    void ueberweisen(Konto& zielkonto, double money) {
        this->auszahlen(money);
        zielkonto.einzahlen(money);
    }


    void kontostand_anzeigen() {
        cout << name << " (" << nr << "): " << betrag << " Euro" << endl;
    }
};

int main() {
    Konto *k1 = new Konto;
    Konto *k2 = new Konto;
    k1->einzahlen(200);
    k2->einzahlen(200);
    k1->auszahlen(50);
    k1->ueberweisen(*k2, 100);
    k1->ueberweisen(*k2, 250);
    k2->auszahlen(500);
}