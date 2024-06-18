#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include<stdio.h>
#include<utility>
#include "../../math/mod_sqrt.hpp"

signed main(){
    int t;
    scanf("%d",&t);
    for(;t--;){
	    long long a,p;
	    scanf("%lld%lld",&a,&p);
	    printf("%lld\n",mod_sqrt(a,p));
    }
}
