#include <iostream>
#include <bits/stdc++.h>
#include "Dadosbase.hpp"
using namespace std;

void clearVetor(double Vetor[], int tam);

void lerDadosBase(){
	string name = "";
	printf("%s \n","Insira o nome do arquivo: ");
	cin>>name;
	ifstream arquivo(name);
	Dadosbase* base;
	//loopaDanado
	if(!arquivo){ //se o arquivo não foi corretamente aberto
		cerr << "Não foi possivél abrir o arquivo" << endl;
		exit(EXIT_FAILURE);
	}else{
		int mestreMandou = 0;
		string var[10]; // base da tabela
		double nodes[9]; //nodes
		string palavra = "";
		string palavraVariante = "";
		int i=0;
		while(!arquivo.eof()){//enquanto o arquivo não chegar ao fim
			switch (mestreMandou){
				case 0:
					getline(arquivo,palavra);
					if(palavra != "NODES"){
						var[i] = palavra;
						 cout<<var[i]<<endl;
					}else{
						mestreMandou++;
						base = new Dadosbase(var[0],var[1],var[2],var[3],var[4],var[5],var[6],var[7],var[8],var[9]);
					}
					i++;
					palavra.clear(); //funfando
					break;
				case 1:
					double pegaDados;
					for(int j=0; j<base->getSize(); j++){
						i=0;
						while(i<9){
							arquivo >> pegaDados;
							nodes[i]= pegaDados;
							i++;
						}
						palavra.clear();
						clearVetor(nodes, i);
					}
					//No = new Nodes(nodes[0],nodes[1],nodes[2],nodes[3],nodes[4],nodes[5],nodes[6],nodes[7],nodes[8])
					mestreMandou++;
					break;
					
				case 2:
					mestreMandou++;
					break;
			}
		}
	}
}

void clearVetor(double vetor[], int tam){
	for(int i=0; i<tam; i++){
		vetor[i]=0.0;
	}
}
