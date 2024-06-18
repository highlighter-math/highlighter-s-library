#pragma once
#include<vector>
#include<cassert>
using namespace std;

template<typename T>
struct matrix{
	int H,W;
	vector<vector<T>> table;
	matrix(int h,int w) : H(h),W(w){
		table.resize(h,vector<T>(w));
	}
	int size(){
		return H;
	}
	matrix pow(long long N){
		assert(H==W);
		assert(0<=N);
		matrix x=*this;
		matrix r(H,H);
		for(int i=0;i<H;i++){
			r[i][i]=1;
		}
		while(N){
			if(N&1)r*=x;
			x*=x;
			N>>=1;
		}
		return r;
	}
	vector<T>& operator[](int index){
		assert(index<H);
		return table[index];
	}
	matrix& operator+=(const matrix &other){
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if((int)(other.table.size())<=i){
					continue;
				}
				if((int)(other.table[i].size())<=j){
					continue;
				}
				(*this)[i][j]+=other.table[i][j];
			}
		}
		return *this;
	}
	matrix operator*=(const matrix &other){
		int h=other.H;
		int w=other.W;
		assert(h==W);
		//結果はH*w行列になる
		matrix result(H,w);
		for(int i=0;i<H;i++){
			for(int k=0;k<W;k++){
				for(int j=0;j<w;j++){
					result.table[i][j]+=table[i][k]*other.table[k][j];
				}
			}
		}
		*this=result;
		return *this;
	}
};
