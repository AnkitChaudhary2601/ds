#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Graph {
	vector<vector<int> > G;	
	
	Graph(){}

	Graph(int n){
		G.resize(n+1);
	}

	void add(int u, int v){
		if(G.size() < u || G.size() < v)
			G.resize(max(u,v)+1);
		G[u].push_back(v);
	}

	bool isPathExists(int source, int destination){
		if(source == destination) return true;
		vector<bool> visited(G.size(), false);
		queue<int> q;
		q.push(source);
		while(!q.empty()){
			int u = q.front();
			q.pop();

			for(int i=0;i<G[u].size();i++){
				int v = G[u][i];
				if(!visited[v]){
					if(v ==  destination){
						return true;
					}
					q.push(v);
					visited[v] = true;
				}
			}
		}
		return false;
	}
};

int main(){
	// int n;
	// printf("Enter number of nodes in graph : ");
	// scanf("%d", &n);
	Graph g ;
	int u,v;
	while(true){
		scanf("%d %d", &u, &v);
		if(u==0 || v==0) break;
		g.add(u, v);
	}
	while(true){
		printf("Enter source and destination : ");
		scanf("%d %d", &u, &v);
		if(u==0 || v==0) break;
		printf("%s\n", g.isPathExists(u,v) ? "Yes" : "No");
	}
}



