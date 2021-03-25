#include "Argumenty.h"
#include "SekwencjaAlgorytmow.h"
#include "Algs.h"


struct Printer{
    Printer(const char* prefix) : m_prefix{prefix} {}
    Argumenty operator()(const Argumenty& arg) const {
        std::cout << m_prefix << arg << std::endl;
        return arg;
    }
    const char* m_prefix;
};

int main() {
    SekwencjaAlgorytmow kwadratNajmniejszej;
    kwadratNajmniejszej.add( Printer("Wejscie ") );
    kwadratNajmniejszej.add(minimum);
    kwadratNajmniejszej.add([](const Argumenty& a){ std::cout << "1 " << a << std::endl; return a;});
    kwadratNajmniejszej.add([](const Argumenty& a){ return Argumenty::pojedynczy(a[0]*a[0]); });

    Argumenty a(3);
    a(0, 4)(1, -2)(2, 6);
    const Argumenty a2(a); 

    auto wynik = kwadratNajmniejszej.procesuj(a2);
    std::cout <<  "Result " << wynik << std::endl;

    const Argumenty a3(a2);
    SekwencjaAlgorytmow kwadratSumy;
    kwadratSumy.add(sum);
    kwadratSumy.add(sq);

    wynik = kwadratSumy.procesuj(a3);
    std::cout << "Result " << wynik << std::endl;

}
/* wynik
Wejscie 4 -2 6
1 -2
Wynik 4
Wynik 2.82843
*/
