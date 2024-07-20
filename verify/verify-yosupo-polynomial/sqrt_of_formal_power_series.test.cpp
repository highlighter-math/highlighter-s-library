#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"
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
	int count=0;
	for(int i=0;i<N;i++){
		if(F.vec[i]!=0){
			if(mod_sqrt((long long)F.vec[i].val(),998244353)==-1){
				printf("-1\n");
				return 0;
			}
			break;
		}
		count++;
	}
	if(count%2==1 && count!=N){
		printf("-1\n");
		return 0;
	}
	F=F.sqrt();
	for(int i=0;i<N;i++){
		printf("%d ",F.vec[i].val());
	}
	printf("\n");
}
