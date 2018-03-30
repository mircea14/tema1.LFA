#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

struct tranzitie
{
    int x;
    int y;
    char s[10];
}tranzitii[100];


int verificare( char *cuvant, int poz_cur, int n) // tranzitie tranzitii[100],
{
    cout<<endl<<"afisez din subprogram:"<<endl;
    cout<<"cuvant: "<<cuvant<<endl;
    cout<<"poz_cur: "<<poz_cur<<" a[1].x: "<<tranzitii[1].x<<endl;
    cout<<"a[0].s"<<tranzitii[0].s<<endl;
    cout<<"n= "<<n<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<i<<endl;
        //strcpy(tranzitii[i].s,tranzitii[i].s+1);
        //memcpy(tranzitii[i].s,tranzitii[i].s+1,sizeof(char)*strlen(tranzitii[i].s+1));

        cout<<"verif strcmp: "<<strcmp(cuvant,tranzitii[i].s+1)<<" "<<tranzitii[i].s<<" "<<cuvant<<endl;
        cout<<poz_cur<<" "<<tranzitii[i].x<<endl;
        if(strcmp(cuvant,tranzitii[i].s+1) == 0 && poz_cur == tranzitii[i].x )
           {
               cout<<"a[i].y"<<tranzitii[i].y<<endl;
               return tranzitii[i].y;
           }
    }
    return -1;
}
int main()
{
    int numar_stari,numar_tranzitii=0,stare_initiala;
    char stari[20],alfabet[20],stari_finale[20];
    ifstream f;
    f.open("automat.in");
    f.get(stari,256);
    cout<<stari<<endl;
    numar_stari=strlen(stari)/2+1;
    f.get();
    f.get(alfabet,256);
    cout<<alfabet<<endl;
    f.get();
    f>>stare_initiala;
    f.get();
    cout<<"stare initiala: "<<stare_initiala<<endl;
    f.get(stari_finale,256);
    cout<<stari_finale<<endl;
    f.get();
    //tranzitie tranzitii[40];
    char tranzitie_move[20];
    int i=0;
    char test[32];
    while(!f.eof())
    {
        f>>tranzitii[i].x>>tranzitii[i].y;
        f.get(tranzitii[i].s,20);
        f.get();
        cout<<tranzitii[i].x<<" "<<tranzitii[i].y<<" "<<tranzitii[i].s<<endl;
        i++;

    }
    numar_tranzitii=i-1;
    cout<<endl<<"i= "<<i;cout<<endl<<"numar tranzitii= "<<numar_tranzitii;
    cout<<endl<<"verificare stocare automat:"<<endl;
    for(int i=0;i<numar_tranzitii;i++)
        cout<<tranzitii[i].x<<" "<<tranzitii[i].y<<" "<<tranzitii[i].s<<endl;
    // INTERFATA+METODA PENTRU VERIFICARE CUVANT LIMBAJ

    char cuvant[100];
    char *token;
    int poz_cur=stare_initiala;
    cout<<"scrieti un cuvant: ";
    cin.get(cuvant,100);
    cout<<endl<<strlen(cuvant);
    cout<<endl<<cuvant;
    token=strtok(cuvant," ");
    cout<<endl<<"pozitia curenta inainte de for: "<<poz_cur<<endl;
    cout<<endl<<endl<<"verif tranzitii"<<endl;
    for(int i=0;i<numar_tranzitii;i++)
        cout<<tranzitii[i].x<<" "<<tranzitii[i].y<<" "<<tranzitii[i].s<<endl;
    while(token != NULL)
    {
        cout<<endl<<"test token:"<<token;
        if(verificare(token,poz_cur,numar_tranzitii) == -1) //tranzitii,
        {
            cout<<endl<<"EROARE !";
            cout<<"datele introduse sunt gresite. automatul nu ajunge intr-o stare finala";
            return 0;
        }

        poz_cur=verificare(token,poz_cur,numar_tranzitii); // tranzitii,
        cout<<"asta returneaza subprogramul: "<<verificare(token,poz_cur,numar_tranzitii)<<endl; // tranzitii,

        token=strtok(NULL, " ");

    }
    //for(int j=0;j<strlen(stari_finale);j++)
            cout<<endl<<"AUTOMAT CORECT !";




    f.close();
    return 0;
}
