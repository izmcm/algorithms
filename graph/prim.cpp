/*
	Algoritmo para criação de uma MST (Árvore Geradora de Custo Mínimo), ou seja,
	garante a conexão de todos os nós do grafo com o menor custo de arestas
	* implementação quase igual a dijkstra
*/
#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10
#define INF 1e8

typedef pair<int, int> ii;

// pair<distância, vértice>
vector<ii> graph[SizeNodes];
int D[SizeNodes], visit[SizeNodes];

priority_queue<ii, vector<ii>, greater<ii> > min_heap;

void prim(int v){
	D[v] = 0;
	min_heap.push(ii(0, v));

	while(!min_heap.empty()){
		ii now = min_heap.top();
		min_heap.pop();

		visit[now.second] = 1;

		for(int i = 0; i < graph[now.second].size(); i++){
			ii next = graph[now.second][i];

			if(visit[next.second] == 0){
				// verifica se a aresta [now.second-next.second] possui peso menor que a anteriormente armazenada
				if(D[next.second] > next.first){
					D[next.second] = next.first;
				
					min_heap.push(ii(D[next.second], next.second));
				}
			}
		}
	}
}


int main(){
  for(int i = 0; i < SizeNodes; i++) // atribui infinito para todos os nós
  	D[i] = INF;
	
  // chama a função a partir do que será a raiz da árvore
  // prim(root);

return 0;
}
