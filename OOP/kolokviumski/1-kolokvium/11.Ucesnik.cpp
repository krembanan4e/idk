/*
Да се дефинира класа Ucesnik за учесник во маратон за кој ќе се чуваат информации за:

име (динамички алоцирана низа од знаци)
пол (bool)
возраст (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)

Дополнително за оваа класа да се преоптоварат:

оператор за споредување > (споредува двајца учесници според возраста) (5 поени)
операторот за проследување на излезен тек << кој ќе ги печати името, полот (машки/женски) и возраста, секој во посебен ред. (5 поени)
Да се дефинира класа Maraton за кој се чуваат:

локација (низа од максимум 100 знаци)
низа од Ucesnik објекти (динмички алоцирана низа од објекти од класата Ucesnik)
број на учесници (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени) Исто така да се имплементираат следните методи:

оператор += за додавање нов Ucesnik на маратонот Maraton. (10 поени)
prosecnoVozrast() вреќа просечена возраст на учесниците на маратонот (5 поени)
pecatiPomladi(Ucesnik &u) ги печати сите учесници помлади од учесникот проследен како аргумент на методот. (5 поени)

For example:

Input	
5
Skopje
Elena 0 23
Mitko 1 41
Iskra 0 31
Jovan 1 28
Zoran 1 40

Output
Elena
zhenski
23
Iskra
zhenski
31
Jovan
mashki
28
32.6
*/

#include <iostream>
#include <cstring>

using namespace std;

// vashiot kod ovde

class Ucesnik{
private:
    char* ime;
    bool pol;
    int vozrast;
public:
    Ucesnik(){
        this->ime = new char[0];
        this->pol = false;
        this->vozrast = 0;
    }
    Ucesnik(char* ime, bool pol, int vozrast){ //parameters
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->pol = pol;
        this->vozrast = vozrast;
    }
    Ucesnik(const Ucesnik &u){ //cc
        this->ime = new char[strlen(u.ime)+1];
        strcpy(this->ime, u.ime);
        this->pol = u.pol;
        this->vozrast = u.vozrast;
    }
    Ucesnik &operator=(const Ucesnik &u){ //operator=
        if(this!=&u){
            delete []ime;
            this->ime = new char[strlen(u.ime)+1];
            strcpy(this->ime, u.ime);
            this->pol = u.pol;
            this->vozrast = u.vozrast;
        }
        return *this;
    }
    bool operator>(const Ucesnik &u){
        return (this->vozrast > u.vozrast);
    }
    friend ostream &operator<<(ostream &o, Ucesnik &u){
        o<<u.ime<<endl;
        if(u.pol){
            o<<"mashki"<<endl;
        }
        else{
            o<<"zhenski"<<endl;
        }
        o<<u.vozrast<<endl;
        return o;
    }
    int getVozrast(){
        return vozrast;
    }
    ~Ucesnik(){
        delete []ime;
    }
};

class Maraton{
private:
    char lokacija[100];
    Ucesnik *u;
    int n; //br ucesnici
public:
    Maraton(){
        strcpy(this->lokacija, "");
        this->n = 0;
        this->u = new Ucesnik[n];
    }
    Maraton(char* lokacija){
        strcpy(this->lokacija, lokacija);
        this->n = 0;
        this->u = new Ucesnik[n];
    }
    Maraton(const Maraton &m){
        strcpy(this->lokacija, m.lokacija);
        this->n = m.n;
        this->u = new Ucesnik[n];
        for (int i = 0; i < n; ++i) {
            this->u[i] = m.u[i];
        }
    }
    Maraton &operator=(const Maraton &m){
        if(this!=&m){
            delete []u;
            strcpy(this->lokacija, m.lokacija);
            this->n = m.n;
            this->u = new Ucesnik[n];
            for (int i = 0; i < n; ++i) {
                this->u[i] = m.u[i];
            }
        }
        return *this;
    }
    Maraton &operator+=(const Ucesnik &uu){
        Ucesnik *tmp = new Ucesnik[n+1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = u[i];
        }
        tmp[n] = uu;
        delete []u;
        u = tmp;
        n++;
        return *this;
    }
    float prosecnoVozrast(){
        float suma=0;
        for (int i = 0; i < n; ++i) {
            suma += u[i].getVozrast();
        }
        return suma/n;
    }
    void pecatiPomladi(const Ucesnik &uu){
        for (int i = 0; i < n-1; ++i) {
            if(!u[i].operator>(uu)){
                cout<<u[i];
            }
        }
    }
    ~Maraton(){
        delete []u;
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}
