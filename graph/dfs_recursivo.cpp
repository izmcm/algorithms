/*
    Algoritmo que realiza busca exaustiva num grafo, começando por um vértice inicial v e visitando
    o máximo possivel seu ramo até retroceder para visitar outro ramo até que todos os vértices tenham
    sido visitados
    
    Izabella Melo ~imcm
    imcm@cin.ufpe.br
*/
#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10

vector<int> adj[SizeNodes];
int visit[SizeNodes];

void DFS(int v){
  visit[v] = 1;
  
  for(int i = 0; i < adj[v].size(); i++)[
    int next = adj[v][i];
    
    if(visit[next] == 0) dfs(next);
  }
}

int main(){
  dfs(initialNode);
}
