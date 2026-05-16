#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

struct posizione{
    double coord_x;
    double coord_y;
};

posizione utente;

struct bici{
    int id;
    int autonomia;
    posizione pos;
    bool disponibile;
};

double distanza(bici bici_){
    return sqrt(pow(bici_.pos.coord_x-utente.coord_x,2)+pow(bici_.pos.coord_y-utente.coord_y,2));
}

bool confronta(bici bici1, bici bici2){
    return distanza(bici1)<distanza(bici2);
}
    
int main()
{
    srand(time(0));
    int n_bici=rand()%10+1;
    bici e_bike[n_bici];
    bici bici_noleggiata;
    int Pos_bici, km_da_fare;
    bool bici_prenotabile=false;
    int velocità_media=20, ritardo=0;
    float importo, tempo=0;
    do{
    cout<<"Inserisci coordinate posizione(X/Y)\n";
    cin>>utente.coord_x;
    cin>>utente.coord_y;
    }while(utente.coord_x<0 || utente.coord_x>=25 || utente.coord_y<0 || utente.coord_y>=25 );
    cout<<"La tua posizione\n X: "<<utente.coord_x<<" Y: "<<utente.coord_y<<endl;
    
    for(int i=0; i<n_bici; i++){
        e_bike[i].pos.coord_x=rand()%25;
        e_bike[i].pos.coord_y=rand()%25;
        e_bike[i].id=i;
        e_bike[i].autonomia=rand()%10+1;
        e_bike[i].disponibile=rand()%2;
    }
    
    sort(e_bike, e_bike+n_bici, confronta);
    
    for(int k=0;k<n_bici;k++){
        if(e_bike[k].disponibile==1){
        cout<<"Bici n: "<<k+1;
        cout<<" X: "<<e_bike[k].pos.coord_x;
        cout<<" Y: "<<e_bike[k].pos.coord_y;
        cout<<" ID: "<<e_bike[k].id;
        cout<<" Distanza: "<<distanza(e_bike[k]);
        cout<<" Autonomia: "<<e_bike[k].autonomia;
        cout<<" Disponibile(0-no/1-si): "<<e_bike[k].disponibile<<endl;
        }
    }
    
    while(bici_prenotabile==false){
    cout<<"Quale bici vuoi noleggiare?(Posizione): ";
    cin>>Pos_bici;
    bici_noleggiata=e_bike[Pos_bici-1];
    if(e_bike[Pos_bici-1].disponibile!=1){
        cout<<"Hai selezionato una bici non disponibile/non esistente\n";
        continue;
    }
    cout<<"Quanti km devi fare?: ";
    cin>>km_da_fare;
    while(km_da_fare<0){
        cout<<"Numero invalido, reinserisci\n";
        cin>>km_da_fare;
    }
    if(km_da_fare>bici_noleggiata.autonomia){
        cout<<"La bici non ha abbastanza autonomia\n";
    }else{
        cout<<"Bici noleggiata";
        bici_prenotabile=true;
        e_bike[Pos_bici-1].disponibile=0;
    }
    }
    ritardo=rand()%15+1;
    tempo=(((float)km_da_fare/velocità_media)*60)+ritardo;
    e_bike[Pos_bici-1].autonomia-=km_da_fare;
    importo=tempo*0.2;
    cout<<"\nKm percorsi: "<<km_da_fare;
    cout<<"\nTempo totale: "<<tempo;
    cout<<"\nL'importo è di "<<importo<<" euro";
    
}
