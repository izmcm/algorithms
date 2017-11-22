/*
	Estrutura de dados para manipulação de conjuntos disjuntos
	
	 Izabella Melo ~imcm
	 imcm@cin.ufpe.br
*/
#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10
#define INF 1e8

vector<int> adj[SizeNodes];
int id[SizeNodes], size[SizeNodes];

// inicializa todos os nós
void init(int i){
	id[i] = i; // id (pai) de i como sendo ele mesmo
	size[i] = 1; // tamanho de i como sendo 1
}

// encontra o id (pai) do nó i
int find(int i){
	if(id[i] == i) return i;
	return id[i] = find(id[i]); // path compression
}

// une os nós a e b no mesmo conjunto
void unionSet(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return; // verifica se já fazem parte do mesmo conjunto

	// sempre conecta o menor conjunto na raiz do maior
	if(size[a] > size[b]) swap(a, b);
	
	id[a] = b;
	size[b] += size[a]; // atualiza o tamanho
}

int main(){
	for(int i = 0; i < SizeNodes; i++) // inicialização
		init(i);

	unionSet(1, 3);
	unionSet(3, 7);

	unionSet(0, 5);

	cout << find(7) << " " << find(0) << endl;
  
return 0;
}
