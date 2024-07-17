#pragma once
#include<vector>
#include<queue>
#include<atcoder/modint>
#include<atcoder/convolution>
using namespace std;
using namespace atcoder;
using mint=modint998244353;

#include "../math/mod_sqrt.hpp"

template<class T>
class FormalPowerSeries{
	private:
	vector<mint> fac;
	void in_fac(int N=1000000){
		if((int)(fac.size())>=N){
			return;
		}
		if(N>1000000){
			N=1000000;
		}
		fac.resize(N);
		fac[0]=1;
		for(int i=1;i<N;i++){
			fac[i]=fac[i-1]*mint(i);
		}
	}
	public:
	vector<T> vec;
	FormalPowerSeries():vec(0,0){}
	FormalPowerSeries(int siz) : vec(siz){}
	FormalPowerSeries(vector<T> A){
		vec=A;
	}
	FormalPowerSeries pre(int deg) const{
		if(deg==-1){
			return *this;
		}
		FormalPowerSeries<T> F(deg);
		for(int i=0;i<deg;i++){
			if(i>=(int)((*this).vec.size())){
				break;
			}
			F.vec[i]=(*this).vec[i];
		}
		return F;
	}
	FormalPowerSeries inv(int deg=-1) const{
		if(deg==-1) deg=(*this).vec.size();
		assert(vec[0]!=0 && deg>0);
		FormalPowerSeries<T> g({vec[0].inv()});
		while((int)(g.vec.size())<deg){
			int k=(int)(g.vec.size());
			g=mint(2)*g-(*this).pre(2*k)*g*g;
			g=g.pre(2*k);
		}
		return g.pre(deg);
	}
	FormalPowerSeries diff(int deg=-1) const{
		if((int)((*this).vec.size())==0){
			return *this;
		}
		if(deg==-1){
			deg=(int)((*this).vec.size());
		}
		FormalPowerSeries<T> g(deg);
		for(int i=0;i<deg;i++){
			if(i+1>=(int)((*this).vec.size())){
				break;
			}
			g.vec[i]=(*this).vec[i+1]*mint(i+1);
		}
		return g;
	}
	FormalPowerSeries integral(int deg=-1) const{
		if(deg==-1){
			deg=(int)((*this).vec.size());
		}
		FormalPowerSeries<T> g((int)((*this).vec.size())+1);
		for(int i=0;i<(int)((*this).vec.size());i++){
			if(i>=(int)((*this).vec.size())){
				break;
			}
			g.vec[i+1]=(*this).vec[i]/mint(i+1);
		}
		return g;
	}
	FormalPowerSeries log(int deg=-1) const{
		if(deg==-1){
			deg=(int)((*this).vec.size());
		}
		assert((*this).vec[0]==1 && deg>0);
		FormalPowerSeries<T> g=(*this).diff().pre(deg)*(*this).inv(deg);
		g=g.pre(deg-1);
		return g.integral();
	}
	friend FormalPowerSeries log(const FormalPowerSeries &f){
		return f.log();
	}
	FormalPowerSeries exp(int deg=-1) const{
		if(deg==-1){
			deg=(int)((*this).vec.size());
		}
		assert((*this).vec[0]==0 && deg>0);
		FormalPowerSeries<T> g({mint(1)});
		while((int)(g.vec.size())<deg){
			int k=(int)(g.vec.size());
			g*=mint(1)-g.log(2*k)+(*this).pre(2*k);
			g=g.pre(2*k);
		}
		g=g.pre(deg);
		return g;
	}
	FormalPowerSeries pow(long long n,int deg=-1) const{
		if(deg==-1){
			deg=(int)((*this).vec.size());
		}
		FormalPowerSeries<T> g(deg);
		if(n==0){
			g.vec[0]=1;
			return g;
		}
		int l=-1;
		for(int i=0;i<(int)((*this).vec.size());i++){
			if((*this).vec[i]!=mint(0)){
				l=i;
				break;
			}
		}
		if(l==-1){
			return (*this).pre(deg);
		}
		if((deg-1)/n<(l)){
			return g;
		}
		FormalPowerSeries<T> f(deg-n*l);
		for(int i=0;i<(int)(f.vec.size());i++){
			if(i+l>=(int)((*this).vec.size())){
				break;
			}
			f.vec[i]=(*this).vec[i+l]/(*this).vec[l];
		}
		f=(mint(n)*f.log()).exp();
		for(int i=(int)((long long)l*n);i<deg;i++){
			g.vec[i]=f.vec[i-n*l]*(*this).vec[l].pow(n);
		}
		return g;
	}
	FormalPowerSeries Taylor_shift(int a){
		//f(x+a)を計算
		if(fac[0]==0){
			in_fac();
		}
		FormalPowerSeries<T> g((int)((*this).vec.size()));
		FormalPowerSeries<T> h((int)((*this).vec.size()));
		mint b=1;
		for(int i=0;i<(int)((*this).vec.size());i++){
			g.vec[i]=fac[(int)((*this).vec.size())-i-1]*(*this).vec[(int)((*this).vec.size())-i-1];
			h.vec[i]=b/fac[i];
			b*=a;
		}
		g*=h;
		g=g.pre((int)((*this).vec.size()));
		for(int i=0;i<(int)((*this).vec.size());i++){
			g.vec[i]/=fac[(int)((*this).vec.size())-i-1];
		}
		reverse(g.vec.begin(),g.vec.end());
		return g;
	}
	FormalPowerSeries sqrt(int deg=-1){
		if(deg==-1){
			deg=(int)((*this).vec.size());
		}
		int l=0;
		for(int i=0;i<(int)((*this).vec.size());i++){
			if((*this).vec[i]!=0){
				break;
			}
			l++;
		}
		if(l==(int)((*this).vec.size())){
			return (*this).pre(deg);
		}
		assert(l%2==0);
		FormalPowerSeries<T> f((int)((*this).vec.size())-l);
		for(int i=0;i<(int)((*this).vec.size())-l;i++){
			f.vec[i]=(*this).vec[i+l];
		}
		FormalPowerSeries<T> g({mod_sqrt((long long)f.vec[0].val(),998244353)});
		while((int)(g.vec.size())<deg-l/2){
			int k=(int)(g.vec.size());
			g=(g+f.pre(2*k)*g.inv(2*k))/mint(2);
			g=g.pre(2*k);
		}
		g=g.pre(deg-l/2);
		FormalPowerSeries<T> h(deg);
		for(int i=l/2;i<deg;i++){
			h.vec[i]=g.vec[i-l/2];
		}
		return h;
	}
	friend FormalPowerSeries product(vector<FormalPowerSeries<T>> &vec,int deg=-1){
		int N=(int)(vec.size());
		if(N==0){
			FormalPowerSeries<T> F(1);
			F.vec[0]=1;
			return F;
		}
		queue<FormalPowerSeries<T>> que;
		for(FormalPowerSeries<T> F : vec){
			que.push(F);
		}
		while(que.size()>1){
			FormalPowerSeries<T> F=que.front();
			que.pop();
			FormalPowerSeries<T> G=que.front();
			que.pop();
			que.push((F*G).pre(deg));
		}
		return que.front();
	}
	//ここからはoperator
	FormalPowerSeries& operator+=(const FormalPowerSeries &other){
		int size=max((int)(vec.size()),(int)(other.vec.size()));
		for(int i=0;i<size;i++){
			if(i>=(int)(vec.size())){
				vec.emplace_back(other.vec[i]);
				continue;
			}
			if(i>=(int)(other.vec.size())){
				continue;
			}
			vec[i]+=other.vec[i];
		}
		return *this;
	}
	FormalPowerSeries& operator+=(const T &other){
		(*this).vec[0]+=other;
		return *this;
	}
	FormalPowerSeries& operator-=(const FormalPowerSeries &other){
		int size=max((int)(vec.size()),(int)(other.vec.size()));
		for(int i=0;i<size;i++){
			if(i>=(int)(vec.size())){
				vec.emplace_back(-other.vec[i]);
				continue;
			}
			if(i>=(int)(other.vec.size())){
				continue;
			}
			vec[i]-=other.vec[i];
		}
		return *this;
	}
	FormalPowerSeries& operator-=(const T &other){
		(*this).vec[0]-=other;
		return *this;
	}
	FormalPowerSeries& operator*=(const FormalPowerSeries &other){
		vec=convolution(vec,other.vec);
		return *this;
	}
	FormalPowerSeries& operator*=(const T &other){
		for(int i=0;i<this->vec.size();i++){
			(*this).vec[i]*=other;
		}
		return *this;
	}
	FormalPowerSeries& operator/=(const FormalPowerSeries &other){
		(*this)*=other.inv();
		return *this;
	}
	FormalPowerSeries& operator/=(const T &other){
		for(int i=0;i<(int)((*this).vec.size());i++){
			(*this).vec[i]/=other;
		}
		return *this;
	}
	FormalPowerSeries operator-() const{
		return FormalPowerSeries(0)-FormalPowerSeries(*this);
	}
	FormalPowerSeries operator+(const FormalPowerSeries &g) const{
		return FormalPowerSeries(*this)+=g;
	}
	friend FormalPowerSeries operator+(const FormalPowerSeries &f,const T &g){
		return FormalPowerSeries(f)+=g;
	}
	friend FormalPowerSeries operator+(const T &g,const FormalPowerSeries &f){
		return FormalPowerSeries(f)+=g;
	}
	friend FormalPowerSeries operator-(const FormalPowerSeries &f,const T &g){
		return FormalPowerSeries(f)-=g;
	}
	friend FormalPowerSeries operator-(const T &g,const FormalPowerSeries &f){
		return -FormalPowerSeries(f)+g;
	}
	FormalPowerSeries operator-(const FormalPowerSeries &g) const{
		return FormalPowerSeries(*this)-=g;
	}
	FormalPowerSeries operator*(const FormalPowerSeries &g) const{
		return FormalPowerSeries(*this)*=g;
	}
    friend FormalPowerSeries operator*(const FormalPowerSeries &f, const T &g){
        return FormalPowerSeries(f)*=g;
    }
    friend FormalPowerSeries operator*(const T &g, const FormalPowerSeries &f){
    	return FormalPowerSeries(f)*=g;
    }
	FormalPowerSeries operator/(const FormalPowerSeries &g) const{
		return FormalPowerSeries(*this)/=g;
	}
	friend FormalPowerSeries operator/(const FormalPowerSeries &f,const T &g){
		return FormalPowerSeries(f)/=g;
	}
	friend FormalPowerSeries operator/(const T &g,const FormalPowerSeries &f){
		return FormalPowerSeries(f).inv()*g;
	}
};

int main(){
	int N;
	scanf("%d",&N);
	vector<FormalPowerSeries<mint>> vec(N);
	for(int i=0;i<N;i++){
		int d;
		scanf("%d",&d);
		FormalPowerSeries<mint> F(d+1);
		for(int j=0;j<=d;j++){
			int a;
			scanf("%d",&a);
			F.vec[j]=mint(a);
		}
		vec[i]=F;
	}
	FormalPowerSeries<mint> F=product(vec);
	for(mint i : F.vec){
		printf("%d ",i.val());
	}
	printf("\n");
}
