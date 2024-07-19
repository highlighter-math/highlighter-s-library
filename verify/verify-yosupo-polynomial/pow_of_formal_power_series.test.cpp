#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "../../polynomial/FormalPowerSeries.hpp"
#include<stdio.h>

int main(){
	int N;
  long long M;
	scanf("%d%lld",&N,&M);
	FormalPowerSeries<mint> F(N);
	for(int i=0;i<N;i++){
		int k;
		scanf("%d",&k);
		F.vec[i]=k;
	}
	F=F.pow(M);
	for(mint i : F.vec){
		printf("%d ",i.val());
	}
	printf("\n");
}
