#include <bits/stdc++.h>
using namespace std;

#define SizeNodes 10
#define INF 1e8

typedef pair<int, int> ii;

vector<ii> graph[SizeNodes];
int D[SizeNodes], visit[SizeNodes];

priority_queue<ii, vector<ii>, greater<ii> > min_heap;

void dijkstra(int v){
	D[v] = 0;
	min_heap.push(ii(0, v)); // put initial node in min heap

	while(!min_heap.empty()){
		ii now = min_heap.top();
		min_heap.pop();

		visit[now.second] = 1;
		
		// see all neighbors nodes
		for(int i = 0; i < graph[now.second].size(); i++){
			ii next = graph[now.second][i];

			if(visit[next.second] == 0){ // unvisited node
				if(D[next.second] > D[now.second] + next.first){ // if new distance is smaller than old
					D[next.second] = D[now.second] + next.first;
				
					min_heap.push(ii(D[next.second], next.second)); // put new node in min heap
				}
			}
		}
	}
}


int main(){
  for(int i = 0; i < SizeNodes; i++) // init distance
  	D[i] = INF;

  //dijkstra(initialNode);
  //cout << D[arrivalNode] << endl;

return 0;
}
