#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"
#include "../../graph/dijkstra.hpp"
#include<stdio.h>

int main(){
	int N,M,r;
	scanf("%d%d%d",&N,&M,&r);
	vector<vector<pair<int,long long>>> G(N);
	for(int i=0;i<M;i++){
		int s,t;
		long long d;
		scanf("%d%d%lld",&s,&t,&d);
		G[s].push_back(make_pair(t,d));
	}
	vector<long long> dist=dijkstra(G,r);
	for(int i=0;i<N;i++){
		if(dist[i]==-1){
			printf("INF\n");
		}
		else{
			printf("%lld\n",dist[i]);
		}
	}
}
