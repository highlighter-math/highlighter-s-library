#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "Fenwick_Tree.hpp"
using namespace std;

long long op(long long a,long long b){
	return a+b;
}

long long op_inv(long long a,long long b){
	return a-b;
}

long long e(){
	return 0LL;
}

bool comp(long long a,long long b){
	return a<b;
}

int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	Fenwick_Tree<long long,op,op_inv,e> fw(A);
	for(;Q--;){
		int c;
		scanf("%d",&c);
		if(c==0){
			int p;
			long long x;
			scanf("%d%lld",&p,&x);
			fw.add(p,x);
			continue;
		}
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",fw.prod(l,r));
	}
}
