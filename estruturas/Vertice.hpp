#include <iostream>
using namespace std;

class Vertice{
private:
    int id;
    double lat;
    double longi;
    int demanda;
    int tempoInicioServicio;
    int horaDeFuncionamento;
    int duracaoDeCarregamento;
    int parDeColeta;
    int parDeEntrega;
public:
    Vertice(int id, double latitude,double longitude,int dem, int tempoI, int horaF, int durC,int parDeColeta, int parEntrega);
    int getId();
    int getColeta();
    int getEntrega();
    ~Vertice();
};



Vertice::Vertice(int id, double latitude,double longitude,int dem, int tempoI, int horaF, int durC,int parDeColeta, int parEntrega){
    this->id = id;
    this->lat = latitude;
    this->longi = longitude;
    this->demanda = dem;
    this->tempoInicioServicio = tempoI; 
    this->horaDeFuncionamento = horaF;
    this->duracaoDeCarregamento = durC;
    this->parDeColeta = parDeColeta;
    this->parDeEntrega = parEntrega;
}

int Vertice::getId(){
    return this->id;
}

int Vertice::getEntrega(){
    return this->parDeEntrega;
}

int Vertice::getColeta(){
    return this->parDeColeta;
}

Vertice::~Vertice(){
}

/*
O <p> e <d> são apenas para fins de integridade. Em todas as instâncias, para um
local de coleta <id> sua entrega é dada por (<id>+((SIZE-1)/2)). Para um local de
entrega <id>, sua coleta é dada por (<id>-((SIZE-1)/2)).
*/

int Vertice::getEntrega(){
    return this->parDeEntrega;
}

int Vertice::getColeta(){
    return this->parDeColeta;
}

Vertice::~Vertice(){
}

/*
O <p> e <d> são apenas para fins de integridade. Em todas as instâncias, para um
local de coleta <id> sua entrega é dada por (<id>+((SIZE-1)/2)). Para um local de
entrega <id>, sua coleta é dada por (<id>-((SIZE-1)/2)).
*/
