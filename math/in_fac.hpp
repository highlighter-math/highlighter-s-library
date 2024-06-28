#pragma once
#include<vector>

void in_fac(auto *factorial){
	factorial[0]=1;
	for(int i=1;i<10;i++){
		factorial[i]=factorial[i-1]*i;
	}
}

template<class S>
void in_fac(std::vector<S> &factorial){
	factorial[0]=1;
	for(int i=1;i<10;i++){
		factorial[i]=factorial[i-1]*i;
	}
}
