/*
    Algoritmo que realiza busca exaustiva num grafo, começando por um vértice inicial v e olhando
    para todos os vértices adjacentes a v até que todos os vértices tenham sido visitados
    
    Izabella Melo ~imcm
    imcm@cin.ufpe.br
*/
#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10

vector<int> adj[SizeNodes];
int visit[SizeNodes];

void bfs(int v){
	queue<int> fila;
	fila.push(v);

	// enquanto houverem nós para serem visitados
	while(!fila.empty()){
		int now = fila.front(); // primeiro elemento da fila
		fila.pop();

		visit[now] = 1; // marca

		// olha todos os nós adjacentes e coloca na fila os que ainda não foram visitados
		for(int i = 0; i < adj[now]; i++){
			int next = adj[now][i];

			if(visit[next] == 0)
				fila.push(next);
		}
	}
}

int main(){
	bfs(initialNode);
}
