//Од стандарден влез се читаат два телефонски броја и времетраење на разговорот во минути.
//Да се пресмета цената на повикот доколку знаеме дека првите 30 минути чинат 3 ден/мин, а после тие 30 мин цената на една минута е 2 ден.
//Дополнително доколку двата телефонски броја се на ист оператор да се пресмета 30% попуст.
//оператор 1 ги користи (071, 072, 073) оператор 2 ги користи (074, 075, 076)

//input              output             2.input               output
//071234567          88.2                 073444909           190
//072987654                               075787989
//48                                      80

#include <iostream>
using namespace std;
int main() {
    int br1, br2, minuti, a, b;
    float cena = 0, popust;
    cin >> br1 >> br2 >> minuti;
    a = br1 / 1000000 % 10;
    b = br2 / 1000000 % 10;

    if ( minuti <= 30 ){
        for ( int i = 1; i <= minuti ; i++ ){
            cena += 3;
        }
    }
    if ( minuti > 30 ){
        minuti = minuti - 30;
        for ( int i = 1; i <= 30 ; i++ ){
            cena += 3;
        }
        for ( int i = 1; i <= minuti ; i++ ){
            cena += 2;
        }
    }
    if ( ( a == 1 || a == 2 || a == 3) && ( b == 1 || b == 2 || b == 3 ) ){
        popust = cena * 0.3;
        cena -= popust;
    }
    else if  ( ( a == 4 || a == 5 || a == 6 ) &&  ( b == 4 || b == 5 || b == 6 ) ){
        popust = cena * 0.3;
        cena -= popust;
    }
    cout << cena;
    return 0;
}
