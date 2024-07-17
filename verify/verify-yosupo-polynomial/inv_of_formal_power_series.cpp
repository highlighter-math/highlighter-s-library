#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "../../polynomial/FormalPowerSeries.hpp"
#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	FormalPowerSeries F(N);
	for(int i=0;i<N;i++){
		int k;
		scanf("%d",&k);
		F.vec[i]=k;
	}
	F=F.inv();
	for(int i=0;i<N;i++){
		printf("%d ",F.vec[i].val());
	}
	printf("\n");
}
