#pragma once
#include<stdio.h>
#include<utility>
#include "power.hpp"

long long mod_sqrt(long long Y,long long p){
	if(p==2 || Y==0){
		return Y;
	}
	if(power(Y,(p-1)/2LL,p)==p-1){
		return -1;
	}
	int Z=0;
	while(true){
		long long ZZ=Z*Z%p-Y%p;
		ZZ%=p;
		if(ZZ<0){
			ZZ+=p;
		}
		if(power(ZZ,(p-1)/2,p)==p-1){
			break;
		}
		Z++;
	}
	std::pair<long long,long long> mul=std::make_pair(Z,1);
	int t=(p+1)/2;
	std::pair<long long,long long> q=std::make_pair(1,0);
	while(t){
		if(t&1){
			int k=q.first*mul.first%p+(Z*Z-Y)%p*q.second%p*mul.second%p;
			int l=q.second*mul.first%p+q.first*mul.second%p;
			l%=p;
			k%=p;
			if(k<0){
				k+=p;
			}
			q=std::make_pair(k,l);
		}
		t>>=1;
		int f=mul.first*mul.first%p+(Z*Z-Y)%p*mul.second%p*mul.second%p;
		f%=p;
		if(f<0){
			f+=p;
		}
		int s=mul.second*mul.first%p*2%p;
		mul=std::make_pair(f,s);
	}
	return q.first;
}
