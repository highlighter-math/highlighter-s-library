#pragma once
#include<functional>

template<class S,auto op,auto e>
S power(S a,long long b){
	static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,"op must work as S(S, S)");
	static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,"e must work as S()");
    S mul=a;
    S ans=e();
    while(b){
        if(b&1){
        	ans=op(ans,mul);
        }
        b>>=1;
        mul=op(mul,mul);
    }
    return ans;
}
