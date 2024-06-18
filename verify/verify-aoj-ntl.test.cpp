#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"
#include<functional>
#include<stdio.h>

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
