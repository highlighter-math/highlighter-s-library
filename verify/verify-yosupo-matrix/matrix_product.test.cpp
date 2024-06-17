#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../matrix/matrix.hpp"
#include<iostream>
#include "atcoder/modint"
using namespace atcoder;
using mint=modint998244353;

int main(){
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	matrix<mint> A(N,M);
	matrix<mint> B(M,K);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int a;
			scanf("%d",&a);
			A[i][j]=a;
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<K;j++){
			int b;
			scanf("%d",&b);
			B[i][j]=b;
		}
	}
	A*=B;
	for(int i=0;i<A.H;i++){
		for(int j=0;j<A.W;j++){
			printf("%d ",A[i][j].val());
		}
		printf("\n");
	}
}
