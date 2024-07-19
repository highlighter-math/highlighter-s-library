#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "../../polynomial/FormalPowerSeries.hpp"
#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	FormalPowerSeries<mint> F(N);
	for(int i=0;i<N;i++){
		int k;
		scanf("%d",&k);
		F.vec[i]=k;
	}
	F=F.log();
	for(mint i : F.vec){
		printf("%d ",i.val());
	}
	printf("\n");
}
