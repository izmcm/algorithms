/*
	Algoritmo para criação de uma MST (Árvore Geradora de Custo Mínimo), ou seja,
	garante a conexão de todos os nós do grafo com o menor custo de arestas
	* implementação a partir de union find (conjuntos disjuntos)
	
	Izabella Melo ~imcm
	imcm@cin.ufpe.br
*/

#include <bits/stdc++.h>
using namespace std;

#define NODES 10

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> edges;
vector<iii> MST;

int id[NODES], size[NODES];

void init(){
	for(int i = 0; i < NODES; i++){
		id[i] = i;
		size[i] = 1;
	}
}

int find(int a){
	if(id[a] == a) return a;
	return id[a] = find(id[a]);
}

void unionSet(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(size[a] > size[b]) swap(a, b);
	id[a] = b;
	size[b] += size[a];
}

void kruskal(){
	init();

	sort(edges.begin(), edges.end()); // ordena arestas pelo menor custo

	// a ordenação garante que sempre serão adicionadas as arestas de menor custo à MST
	for(int i = 0; i < edges.size(); i++){
		iii next = edges[i]; // pega arestas de acordo com a ordenação do sort

		// se os vértices possuirem id's diferentes, quer dizer que ainda não foram adicionadas à MST
		if(find(next.second.first) != find(next.second.second)){
			MST.push_back(iii(next.first, ii(next.second.first, next.second.second))); // adiciona-se tal aresta à MST
			unionSet(next.second.first, next.second.second); // estabelece que tal caminho já está garantido com o menor custo
		}
	}
}

int main(){
	int a, b, cost;
	for(int i = 0; i < NODES; i++){
		cin >> a >> b >> cost; // pega arestas e custos

		edges.push_back(iii(cost, ii(a, b))); // insere informações no vector de arestas
	}

	kruskal();

	int ans = 0;

	// para obter o menor custo total, soma-se todas as arestas da MST
	for(int i = 0; i < MST.size(); i++)
		ans += MST[i].first;

	cout << ans << endl;	
}
