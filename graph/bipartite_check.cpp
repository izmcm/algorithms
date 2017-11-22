/*
	Algoritmo para checar se um grafo é bipartido
	
	Izabella Melo ~imcm
	imcm@cin.ufpe.br
*/

#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10

vector<int> graph[SizeNodes];
int color[SizeNodes];

// cores: 0 e 1
bool check(int v, int c){
	if(color[v] == -1){ 
		color[v] = c; // caso um nó V não possua nenhuma cor, coloca-se uma cor em V
  
    		// e a cor contrária em todos os nós adjacentes, se for possivel
		for(int i = 0; i < graph[v].size(); i++){
			if(!check(graph[v][i], 1 - c)) return false; 
		}
	}
	
	// caso o nó V já tenha sido colorido, mas a sua cor é diferente da cor atual
	else if(color[v] != c)
		return false;
	
	return true;
}

int main(){
  for(int i = 0; i < SizeNodes; i++)
  	color[i] = -1; // todos os nós serão descoloridos
	
  // bipartite
  graph[0].push_back(1);
  graph[1].push_back(0);
  graph[1].push_back(2);
  graph[2].push_back(1);
  graph[1].push_back(3);
  graph[3].push_back(1);
  
  // not bipartite
  //graph[2].push_back(3);
  //graph[3].push_back(2);
  //graph[2].push_back(0);
  //graph[0].push_back(2);

  if(check(0, 0))
  	cout << "bipartite" << endl;
  else
    cout << "not bipartite" << endl;
    
return 0;
}
