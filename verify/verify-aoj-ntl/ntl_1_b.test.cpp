#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"
#include<stdio.h>
#include "../../math/power.hpp"

long long p=1000000007LL;

int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",power(a,b,p));
}
