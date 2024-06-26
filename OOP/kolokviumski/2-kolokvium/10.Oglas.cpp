/*
10.
За потребите на електронскиот огласник ФИНКИ-Огласи треба да се развие класа Oglas со информации за наслов (текстуална низа од максимум 50 знаци), 
категорија (текстуална низа од максимум 30 знаци), опис (текстуална низа од максимум 100 знаци) и цена изразена во евра (реален број). (5 поени)

За оваа класа да се обезбедат:

Оператор > за споредба на двa огласи според цената (5 поени)
Оператор << за печатење на податоците за огласот во форма: (5 поени)

[наслов]
[опис]
[цена] evra

Да се развие класа Oglasnik во која се чуваат податоци за име на огласникот (текстуална низа од максимум 20 знаци), 
низа од огласи (динамички резервирана низа од објекти од класата Oglas) и број на огласи во низата (цел број) (5 поени)

За оваа класа да се обезбедат:

Оператор += за додавање нов оглас во низата од огласи. (5 поени) 
Ако цената на огласот што се внесува е негативна, треба да се генерира исклучок NegativnaVrednost (објект од класата NegativnaVrednost што посебно треба да се дефинира). 
Во ваков случај се печати порака “Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!“ и не се додава во низата. (5 поени)
Оператор << за печатење на огласите во огласникот. (5 поени) Печатењето треба да биде во следниот формат:
[Име на огласникот]

[наслов1] [опис1] [цена1]
[наслов2] [опис2] [цена2]
...

Функција void oglasOdKategorija(const char *k) со која се печатат сите огласи од категоријата k што е проследена како влезен аргумент на методот. (5 поени)

Функција void najniskaCena() со која се печати огласот што има најниска цена. Ако има повеќе огласи со иста најниска цена, да се испечатат податоците за првиот од нив. (5 поени)

Сите променливи во класите се приватни.
Да се обезбедат сите потребни методи за правилно функционирање на програмата. (5 поени)

For example:

Input	
2
BMW 520 FULL OPREMA
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
13000
VW PASSAT 2.0 TDI 140 KS BLUEMOTION
Avtomobili
Godina: 2011 Kilometraza: 140 000 - 149 999
12000

Output
-----Test Oglas & operator > -----
Prviot oglas e poskap.
*/

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

//место за вашиот код

class NegativnaVrednost{
private:
    char* msg;
public:
    NegativnaVrednost(){
        this->msg=new char[0];
    }
    NegativnaVrednost(const char* msg){
        this->msg=new char[strlen(msg)+1];
        strcpy(this->msg,msg);
    }
    void message(){
        cout<<msg<<endl;
    }
    ~NegativnaVrednost(){
        delete []msg;
    }
};

class Oglas{
private:
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
public:
    Oglas(){}
    Oglas(char* naslov, char* kategorija, char* opis, float cena){
        strcpy(this->naslov, naslov);
        strcpy(this->kategorija, kategorija);
        strcpy(this->opis, opis);
        this->cena=cena;
    }
    bool operator>(Oglas &o){
        return this->cena > o.cena;
    }
    friend ostream &operator<<(ostream &out, Oglas &o){
        out<<o.naslov<<endl;
        out<<o.opis<<endl;
        out<<o.cena<<" evra"<<endl;
        return out;
    }
    float getCena(){
        return cena;
    }
    char* getKat(){
        return kategorija;
    }
    ~Oglas(){}
};

class Oglasnik{
private:
    char ime[20];
    Oglas *oglasi;
    int n; //broj na oglasi
public:
    Oglasnik(){
        this->n=0;
        this->oglasi=new Oglas[0];
    }
    Oglasnik(char* ime){
        this->n=0;
        this->oglasi=new Oglas[0];
        strcpy(this->ime, ime);
    }
    Oglasnik(const Oglasnik &o){
        this->n=o.n;
        this->oglasi=new Oglas[n];
        for (int i = 0; i < n; ++i) {
            this->oglasi[i]=o.oglasi[i];
        }
        strcpy(this->ime, o.ime);
    }
    Oglasnik &operator=(const Oglasnik &o){
        if(this!=&o) {
            delete []oglasi;
            this->n = o.n;
            this->oglasi = new Oglas[n];
            for (int i = 0; i < n; ++i) {
                this->oglasi[i] = o.oglasi[i];
            }
            strcpy(this->ime, o.ime);
        }
        return *this;
    }
    Oglasnik &operator+=(Oglas &o){
        for (int i = 0; i < n; ++i) {
            if (o.getCena() < 0){
                throw NegativnaVrednost("Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!");
            }
        }
        Oglas *tmp = new Oglas[n+1];
        for (int i = 0; i < n; ++i) {
            tmp[i]=oglasi[i];
        }
        tmp[n++]=o;
        delete []oglasi;
        oglasi=tmp;
        return *this;
    }
    friend ostream &operator<<(ostream &out, Oglasnik &o){
        out<<o.ime<<endl;
        for (int i = 0; i < o.n; ++i) {
            out<<o.oglasi[i]<<endl;
        }
        return out;
    }
    void oglasiOdKategorija(const char *k){
        for (int i = 0; i < n; ++i) {
            if (strcmp(oglasi[i].getKat(), k)==0){
                cout<<oglasi[i]<<endl;
            }
        }
    }
    void najniskaCena(){
        int id=0;
        for (int i = 1; i < n; ++i) {
            if (oglasi[i].getCena() < oglasi[id].getCena()){
                id=i;
            }
        }
        cout<<oglasi[id];
    }
    ~Oglasnik(){
        delete []oglasi;
    }
};


int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
        cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            try {
                Oglas o(naslov, kategorija, opis, cena);
                ogl += o;
            }
            catch (NegativnaVrednost &neg){
                neg.message();
            }
        }
        cout<<ogl;
    }
    else if (tip==4){
        cout<<"-----Test oglasOdKategorija -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            try {
                Oglas o(naslov, kategorija, opis, cena);
                ogl += o;
            }
            catch (NegativnaVrednost &neg){
                neg.message();
            }
        }
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
        cout<<"-----Test Exception -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            try {
                Oglas o(naslov, kategorija, opis, cena);
                ogl += o;
            }
            catch (NegativnaVrednost &neg){
                neg.message();
            }
        }
        cout<<ogl;

    }
    else if (tip==6){
        cout<<"-----Test najniskaCena -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            try {
                Oglas o(naslov, kategorija, opis, cena);
                ogl += o;
            }
            catch (NegativnaVrednost &neg){
                neg.message();
            }
        }
        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }
    else if (tip==7){
        cout<<"-----Test All -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            try {
                Oglas o(naslov, kategorija, opis, cena);
                ogl += o;
            }
            catch (NegativnaVrednost &neg){
                neg.message();
            }
        }
        cout<<ogl;

        cin.get();
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }

    return 0;
}
