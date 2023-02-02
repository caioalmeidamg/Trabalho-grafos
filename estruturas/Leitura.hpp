#include <iostream>
#include <bits/stdc++.h>
#include "Dadosbase.hpp"
using namespace std;

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
		string palavra = "";
		string palavraVariante = "";
		int i=0;
		while(!arquivo.eof()){//enquanto o arquivo não chegar ao fim
			switch (mestreMandou){
				case 0:
					getline(arquivo,palavra);
					if(palavra != "NODES"){
						var[i] = palavra;
						// cout<<i<<endl;
					}else{
						mestreMandou++;
						base = new Dadosbase(var[0],var[1],var[2],var[3],var[4],var[5],var[6],var[7],var[8],var[9]);
					}
					i++;
					palavra.clear(); //funfando
					break;
				case 1:
					for(unsigned int j=0; j<base->getSize(); j++){
						getline(arquivo,palavra);
						i=0;
						int k = 0;
						while(i<sizeof(palavra)){
							if(' ' == palavra[i] || '\n' == palavra[i]){
								 var[k] = palavraVariante;
							}else{
								palavraVariante += palavra[i];
							}
							i++;
							palavra.clear();
						}
					//  registra onde vc quiser
						clearVetor(var);
					}
					mestreMandou++;
					break;
				case 2:
					mestreMandou++;
				default:
					break;
			}
		}
	}
}

void clearVetor(string vetor[]){
	for(int i=0; i<sizeof(vetor); i++){
		vetor[i]="";
	}
}