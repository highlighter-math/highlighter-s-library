#pragma once
template<class S>
S power(S a,S b,S p=-1){
	S mul=a;
	S res=1;
	if(p==-1){
		while(b){
			if(b&1){
				res*=mul;
			}
			mul*=mul;
			b>>=1;
		}
		return res;
	}
	while(b){
		if(b&1){
			res*=mul;
			res%=p;
		}
		mul*=mul;
		mul%=p;
		b>>=1;
	}
	if(res<0)res+=p;
	return res;
}
