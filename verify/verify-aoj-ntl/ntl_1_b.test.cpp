#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"
#include<stdio.h>
#include "../../math/power.hpp"

long long p=1000000007LL;

long long op(long long a,long long b){
	return a%p*b%p;
}

long long e(){
	return 1LL;
}

int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",power<long long>(a,b,op,e));
}
