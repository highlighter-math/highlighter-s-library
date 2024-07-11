#pragma once
#include<queue>
#include<utility>
#include<vector>
using namespace std;

template<typename T>
vector<T> dijkstra(vector<vector<pair<int,T>>> G,int v){
	vector<bool> kakutei((int)(G.size()),false);
	vector<T> cur((int)(G.size()),2000000000000LL);
	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;
	cur[v]=0;
	que.push(make_pair(cur[v],v));
	while(!que.empty()){
		int pos=que.top().second;
		que.pop();
		if(kakutei[pos]==true){
			continue;
		}
		kakutei[pos]=true;
		for(pair<int,T> i : G[pos]){
			int nex=i.first;
			T cost=i.second;
			if(cur[nex]>cur[pos]+cost){
				cur[nex]=cur[pos]+cost;
				que.push(make_pair(cur[nex],nex));
			}
		}
	}
	for(int i=0;i<(int)(cur.size());i++){
		if(cur[i]==2000000000000LL){
			cur[i]=-1;
		}
	}
	return cur;
}
