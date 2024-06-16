#pragma once
#include<bit>
#include<functional>
#include<stdio.h>
#include<vector>

using namespace std;

template<class S,auto op,auto op_inv,auto e>
struct Fenwick_Tree{
	static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,"op must work as S(S, S)");
	static_assert(std::is_convertible_v<decltype(op_inv), std::function<S(S, S)>>,"op_inv must work as S(S, S)");
	static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,"e must work as S()");
	int siz=1;
	vector<S> dat;
	Fenwick_Tree(int N) : dat(N,e()){
		siz=N;
	}
	Fenwick_Tree(vector<S> A) : dat(A.size(),e()){
		siz=(int)(A.size());
		vector<S> sum(siz+1,e());
		for(int i=1;i<=siz;i++){
			sum[i]=op(sum[i-1],A[i-1]);
		}
		for(int i=0;i<siz;i++){
			int len=(i+1)&(-i-1);
			dat[i]=op_inv(sum[i+1],sum[i+1-len]);
		}
	}
	void add(int k,S x){
		for(int i=k;i<siz;i+=((i+1)&(-i-1))){
			dat[i]=op(dat[i],x);
		}
	}
	S prod(int k){
		if(k<=0){
			return e();
		}
		if(k>siz){
			return prod(siz);
		}
		S ans=e();
		for(int i=k-1;i>=0;i-=((i+1)&(-i-1))){
			ans=op(ans,dat[i]);
		}
		return ans;
	}
	S prod(int l,int r){
		return op_inv(prod(r),prod(l));
	}
	S get(int p){
		return prod(p,p+1);
	}
	void update(int k,S x){
		S y=prod(k,k+1);
		add(k,op_sub(x,y));
	}
	int lower_bound(S x,bool (*comp)(S,S)){
		int k=31-__builtin_clz(siz);
		k=1<<k;
		int ans=0;
		for(;k>0;k/=2){
			if(ans+k<=siz && comp(dat[ans+k-1],x)){
				x=op_inv(x,dat[ans+k-1]);
				ans+=k;
			}
		}
		return ans;
	}
};
