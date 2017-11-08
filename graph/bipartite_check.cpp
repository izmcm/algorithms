#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10

vector<int> graph[SizeNodes];
int color[SizeNodes];

bool check(int v, int c){
	if(color[v] == -1){ // if v is a node without color
		color[v] = c; // put a color in v
  
    		// put another color in all neighbors nodes
		for(int i = 0; i < graph[v].size(); i++){
			if(!check(graph[v][i], 1 - c)) return false; // if it's impossible
		}
	}

	else if(color[v] != c) // if v is colored with another color
		return false;
	
	// else
	return true;
}

int main(){
  for(int i = 0; i < SizeNodes; i++)
  	color[i] = -1;
	
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
