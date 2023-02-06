/*Observações 
- Esse arquivo tem como objetivo funções de leitura de dados de um arquivo genérico,
estamos usando o "bar-n100-1.txt" pra testes.
- A manipulação de dados ocorre na classe: "Dadosbase.hpp"
- O encapsulamento foi deixado de lado durante a primeira entrega
*/

#include <iostream>
#include <bits/stdc++.h>
#include "Dadosbase.hpp"
#include "DijkstraOficial.hpp"
using namespace std;


typedef list<pair<int, int> > LA;


void clearVetor(double vetor[], int tam){
	for(int i=0; i<tam; i++){
		vetor[i]=0.0;
	}
}

Dadosbase lerDadosBase(){
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
		int pesos;
		while(!arquivo.eof()){//enquanto o arquivo não chegar ao fim
			switch (mestreMandou){
				case 0:
					getline(arquivo,palavra);
					if(palavra != "NODES"){
						var[i] = palavra;
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
							nodes[i] = pegaDados;
							i++;
						}
						Vertice ver(nodes[0],nodes[1],nodes[2],nodes[3],nodes[4],nodes[5],nodes[6],nodes[7],nodes[8]);
						base->adicionarNode(ver);
						clearVetor(nodes, 9);
					}
					mestreMandou++;
					break;
				case 2:
					getline(arquivo,palavra);
					getline(arquivo,palavra);
					LA * adj = new LA[base->getSize()];

					for(int j=0; j<base->getSize(); j++){
						for(int k=0; k<base->getSize(); k++){
							arquivo >> pesos;
							adj[j].push_back(make_pair(k, pesos));
						}
					}
						
					base->setLAA(adj);
					mestreMandou++;
					getline(arquivo,palavra);
					getline(arquivo,palavra);
					break;
			}
		}
		printf("%s \n","Insira inicio de veiculos M(X1*): ");
		int pontoI, capacidadeI;
		cin>>pontoI;
		printf("%s \n","Insira fim C(X1*): ");
		cin>>capacidadeI;

		cout<<dijkstra(pontoI,capacidadeI,base->getSize(),base->getLA());
		arquivo.close();
		return *base;
	}
}

