#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#ifndef Dadosbase_HPP
#define Dadosbase_HPP

class Dadosbase{
    private:
        char name[50];
        char location[50];
        char comment[50];
        char type[50];
        char size[50];
        char distribution[50];
        char depot[50];
        char routime[50];
        char timeWindow[50];
        char capacity[50];
    public:
        Dadosbase(string name, string location, string coment, string type, string size,
                  string distribu, string depot, string routime, string time, string capacity);
        int getSize();
        int getRoutime();
        int getCapacity();
        int getTimeWindow();
        string getDistribution();
};

   Dadosbase::Dadosbase(string name, string location, string coment, string type, string size,
            string distribu, string depot, string routime, string time, string capacity){
                    strcpy(this->name, name.c_str());
                    strcpy(this->location, location.c_str());
                    strcpy(this->comment, coment.c_str());
                    strcpy(this->type, type.c_str());
                    strcpy(this->size, size.c_str());
                    strcpy(this->distribution, distribu.c_str());
                    strcpy(this->depot, depot.c_str());
                    strcpy(this->routime, routime.c_str());
                    strcpy(this->timeWindow, time.c_str());
                    strcpy(this->capacity, capacity.c_str());
            };
            
    int Dadosbase::getSize(){
        string tamanho = "";
        for(unsigned int i=0; i<(int)strlen(size); i++){
            if(i>6){
                tamanho += size[i];
            }
        }
        return atoi(tamanho.c_str());
    }

    int Dadosbase::getRoutime(){
        string rout = "";
        for(unsigned int i=0; i<(int)strlen(size); i++){
            if(i>12){
                rout += size[i];
            }
        }
        return atoi(rout.c_str());
    }

    int Dadosbase::getCapacity(){
        string cap = "";
        for(unsigned int i=0; i<(int)strlen(capacity); i++){
            if(i>10){
                cap += capacity[i];
            }
        }
        return atoi(cap.c_str());
    }

    int Dadosbase::getTimeWindow(){
        string windows = "";
        for(unsigned int i=0; i<(int)strlen(timeWindow); i++){
            if(i>13){
                windows += timeWindow[i];
            }
        }
        return atoi(windows.c_str());
    }

    string Dadosbase::getDistribution(){
        string word;
        bool verdade = false;
        for(unsigned int i=0; i<(int)strlen(distribution); i++){
            if(" "){
                verdade=true;
            }if(verdade){
                word += distribution[i];
            }
        }
        return word;
    }

#endif