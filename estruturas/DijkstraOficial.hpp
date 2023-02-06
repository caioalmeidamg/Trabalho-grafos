
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;
typedef list<pair<int, int>> vii;


int dijkstra(int origem, int destino, int nVertices,  vii * adj){
		
		int dist[nVertices];
		int visitados[nVertices];

		
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < nVertices; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		dist[origem] = 0;
		pq.push(make_pair(dist[origem], origem));

		while(!pq.empty()){
			
			pair<int, int> p = pq.top(); 
			int u = p.second; 
			pq.pop(); 

			
			if(visitados[u] == false){
				
				visitados[u] = true;
				list<pair<int, int> >::iterator it;
				
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					
					int v = it->first;
					int custo_aresta = it->second;

					
					if(dist[v] > (dist[u] + custo_aresta))
					{
						
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}
		
		return dist[destino];

}


/*
int main(){
int vertices, arestas;
cin>> vertices >> arestas;

vii * LA = new vii[vertices];

	for(int i=0; i<arestas; i++){
		int vertice1, vertice2, valor;

		cin>> vertice1 >> vertice2 >> valor;
		LA[vertice1].push_back(make_pair(vertice2, valor));
		
	}

cout<< dijkstra(0,3,vertices,LA);
delete [] LA;


return 0; 
}


5 10
0 1 10
0 2 5
1 1 2
2 1 3
2 3 9
1 3 1
3 4 4
4 3 6
4 0 7
2 4 2

 * 
 */