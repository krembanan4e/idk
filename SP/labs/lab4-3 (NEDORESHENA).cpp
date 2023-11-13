//Од тастатура се читаат 2 цели броеви а и б. Да се испечатат сите парни броеви коишто
//се деливи со 7 и сите непарни броеви кои што не се деливи со 3 во опсегот (a,b].
//Ако вакви броеви не постојат да се испечати 0, а во спротивно да се испечати колкав процент од броевите ги исполнуваат условите (односно ќе бидат испечатени)

//input          output
//1 7            5   7   33.3333%

#include <iostream>
using namespace std;
int main(){
    int a, b, br = 0, vkupno = 0;
    float procent;
    cin >> a >> b;
    for ( int i = a+1; i <= b; i++){
        if ( i % 2 == 0 && i % 7 == 0 ){
            cout << i << endl;
            br++;
        }
        else if ( i % 2 != 0 && i % 3 != 0 ){
            cout << i << endl;
            br++;
        }

        vkupno++;
    }
    procent = (100.0 / vkupno) * br;
    cout << procent;

    return 0;
}
