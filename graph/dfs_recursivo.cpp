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
