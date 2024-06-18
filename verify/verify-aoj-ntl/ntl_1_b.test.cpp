#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"
#include<stdio.h>
#include "../../math/power.hpp"

long long p;
long long op(long long a,long long b){
	return a%p*b%p;
}

long long e(){
	return 1LL;
}

int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	p=1000000007LL;
	printf("%lld\n",power<long long,op,e>(a,b));
}
