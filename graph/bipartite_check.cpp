#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10

vector<int> graph[SizeNodes];
int color[SizeNodes];

bool check(int v, int c){
	if(color[v] == -1){ // uncolored node
		color[v] = c; 
  
    		// coloring all neighbors nodes
		for(int i = 0; i < graph[v].size(); i++){
			if(!check(graph[v][i], 1 - c)) return false;	
		}
	}

	else if(color[v] != c)
		return false;

	return true;
}

int main(){
  for(int i = 0; i < SizeNodes; i++)
  	color[i] = -1;

  graph[0].push_back(1);
  graph[1].push_back(0);
  graph[1].push_back(2);
  graph[2].push_back(1);
  graph[1].push_back(3);
  graph[3].push_back(1);
  
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
