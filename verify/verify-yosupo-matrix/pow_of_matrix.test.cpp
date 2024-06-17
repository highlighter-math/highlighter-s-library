#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include "../../matrix/matrix.hpp"
#include<iostream>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;

int main(){
	int N;
	long long K;
	scanf("%d%lld",&N,&K);
	matrix<mint> A(N,N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int a;
			scanf("%d",&a);
			A[i][j]=a;
		}
	}
	A=A.pow(K);
	for(int i=0;i<A.H;i++){
		for(int j=0;j<A.W;j++){
			printf("%d ",A[i][j].val());
		}
		printf("\n");
	}
}
