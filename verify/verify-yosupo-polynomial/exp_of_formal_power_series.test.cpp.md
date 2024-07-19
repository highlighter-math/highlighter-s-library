---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_sqrt.hpp
    title: mod sqrt
  - icon: ':question:'
    path: math/power.hpp
    title: power
  - icon: ':question:'
    path: polynomial/FormalPowerSeries.hpp
    title: polynomial/FormalPowerSeries.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
  bundledCode: "#line 1 \"verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n#line 2 \"polynomial/FormalPowerSeries.hpp\"\n#include<vector>\n#include<queue>\n\
    #include<atcoder/modint>\n#include<atcoder/convolution>\nusing namespace std;\n\
    using namespace atcoder;\nusing mint=modint998244353;\n\n#line 2 \"math/mod_sqrt.hpp\"\
    \n#include<stdio.h>\n#include<utility>\n#line 2 \"math/power.hpp\"\ntemplate<class\
    \ S>\nS power(S a,S b,S p=-1){\n\tS mul=a;\n\tS res=1;\n\tif(p==-1){\n\t\twhile(b){\n\
    \t\t\tif(b&1){\n\t\t\t\tres*=mul;\n\t\t\t}\n\t\t\tmul*=mul;\n\t\t\tb>>=1;\n\t\t\
    }\n\t\treturn res;\n\t}\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=mul;\n\t\t\tres%=p;\n\
    \t\t}\n\t\tmul*=mul;\n\t\tmul%=p;\n\t\tb>>=1;\n\t}\n\tif(res<0)res+=p;\n\treturn\
    \ res;\n}\n#line 5 \"math/mod_sqrt.hpp\"\n\nlong long mod_sqrt(long long Y,long\
    \ long p){\n\tif(p==2 || Y==0){\n\t\treturn Y;\n\t}\n\tif(power(Y,(p-1)/2LL,p)==p-1){\n\
    \t\treturn -1;\n\t}\n\tint Z=0;\n\twhile(true){\n\t\tlong long ZZ=Z*Z%p-Y%p;\n\
    \t\tZZ%=p;\n\t\tif(ZZ<0){\n\t\t\tZZ+=p;\n\t\t}\n\t\tif(power(ZZ,(p-1)/2,p)==p-1){\n\
    \t\t\tbreak;\n\t\t}\n\t\tZ++;\n\t}\n\tstd::pair<long long,long long> mul=std::make_pair(Z,1);\n\
    \tint t=(p+1)/2;\n\tstd::pair<long long,long long> q=std::make_pair(1,0);\n\t\
    while(t){\n\t\tif(t&1){\n\t\t\tint k=q.first*mul.first%p+(Z*Z-Y)%p*q.second%p*mul.second%p;\n\
    \t\t\tint l=q.second*mul.first%p+q.first*mul.second%p;\n\t\t\tl%=p;\n\t\t\tk%=p;\n\
    \t\t\tif(k<0){\n\t\t\t\tk+=p;\n\t\t\t}\n\t\t\tq=std::make_pair(k,l);\n\t\t}\n\t\
    \tt>>=1;\n\t\tint f=mul.first*mul.first%p+(Z*Z-Y)%p*mul.second%p*mul.second%p;\n\
    \t\tf%=p;\n\t\tif(f<0){\n\t\t\tf+=p;\n\t\t}\n\t\tint s=mul.second*mul.first%p*2%p;\n\
    \t\tmul=std::make_pair(f,s);\n\t}\n\treturn q.first;\n}\n#line 11 \"polynomial/FormalPowerSeries.hpp\"\
    \n\ntemplate<class T>\nclass FormalPowerSeries{\n\tprivate:\n\tvector<mint> fac;\n\
    \tvoid in_fac(int N=1000000){\n\t\tif((int)(fac.size())>=N){\n\t\t\treturn;\n\t\
    \t}\n\t\tif(N>1000000){\n\t\t\tN=1000000;\n\t\t}\n\t\tfac.resize(N);\n\t\tfac[0]=1;\n\
    \t\tfor(int i=1;i<N;i++){\n\t\t\tfac[i]=fac[i-1]*mint(i);\n\t\t}\n\t}\n\tpublic:\n\
    \tvector<T> vec;\n\tFormalPowerSeries():vec(0,0){}\n\tFormalPowerSeries(int siz)\
    \ : vec(siz){}\n\tFormalPowerSeries(vector<T> A){\n\t\tvec=A;\n\t}\n\tFormalPowerSeries\
    \ pre(int deg) const{\n\t\tif(deg==-1){\n\t\t\treturn *this;\n\t\t}\n\t\tFormalPowerSeries<T>\
    \ F(deg);\n\t\tfor(int i=0;i<deg;i++){\n\t\t\tif(i>=(int)((*this).vec.size())){\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t\tF.vec[i]=(*this).vec[i];\n\t\t}\n\t\treturn F;\n\
    \t}\n\tFormalPowerSeries inv(int deg=-1) const{\n\t\tif(deg==-1) deg=(*this).vec.size();\n\
    \t\tassert(vec[0]!=0 && deg>0);\n\t\tFormalPowerSeries<T> g({vec[0].inv()});\n\
    \t\twhile((int)(g.vec.size())<deg){\n\t\t\tint k=(int)(g.vec.size());\n\t\t\t\
    g=mint(2)*g-(*this).pre(2*k)*g*g;\n\t\t\tg=g.pre(2*k);\n\t\t}\n\t\treturn g.pre(deg);\n\
    \t}\n\tFormalPowerSeries diff(int deg=-1) const{\n\t\tif((int)((*this).vec.size())==0){\n\
    \t\t\treturn *this;\n\t\t}\n\t\tif(deg==-1){\n\t\t\tdeg=(int)((*this).vec.size());\n\
    \t\t}\n\t\tFormalPowerSeries<T> g(deg);\n\t\tfor(int i=0;i<deg;i++){\n\t\t\tif(i+1>=(int)((*this).vec.size())){\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t\tg.vec[i]=(*this).vec[i+1]*mint(i+1);\n\t\t}\n\t\
    \treturn g;\n\t}\n\tFormalPowerSeries integral(int deg=-1) const{\n\t\tif(deg==-1){\n\
    \t\t\tdeg=(int)((*this).vec.size());\n\t\t}\n\t\tFormalPowerSeries<T> g((int)((*this).vec.size())+1);\n\
    \t\tfor(int i=0;i<(int)((*this).vec.size());i++){\n\t\t\tif(i>=(int)((*this).vec.size())){\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t\tg.vec[i+1]=(*this).vec[i]/mint(i+1);\n\t\t}\n\t\
    \treturn g;\n\t}\n\tFormalPowerSeries log(int deg=-1) const{\n\t\tif(deg==-1){\n\
    \t\t\tdeg=(int)((*this).vec.size());\n\t\t}\n\t\tassert((*this).vec[0]==1 && deg>0);\n\
    \t\tFormalPowerSeries<T> g=(*this).diff().pre(deg)*(*this).inv(deg);\n\t\tg=g.pre(deg-1);\n\
    \t\treturn g.integral();\n\t}\n\tfriend FormalPowerSeries log(const FormalPowerSeries\
    \ &f){\n\t\treturn f.log();\n\t}\n\tFormalPowerSeries exp(int deg=-1) const{\n\
    \t\tif(deg==-1){\n\t\t\tdeg=(int)((*this).vec.size());\n\t\t}\n\t\tassert((*this).vec[0]==0\
    \ && deg>0);\n\t\tFormalPowerSeries<T> g({mint(1)});\n\t\twhile((int)(g.vec.size())<deg){\n\
    \t\t\tint k=(int)(g.vec.size());\n\t\t\tg*=mint(1)-g.log(2*k)+(*this).pre(2*k);\n\
    \t\t\tg=g.pre(2*k);\n\t\t}\n\t\tg=g.pre(deg);\n\t\treturn g;\n\t}\n\tFormalPowerSeries\
    \ pow(long long n,int deg=-1) const{\n\t\tif(deg==-1){\n\t\t\tdeg=(int)((*this).vec.size());\n\
    \t\t}\n\t\tFormalPowerSeries<T> g(deg);\n\t\tif(n==0){\n\t\t\tg.vec[0]=1;\n\t\t\
    \treturn g;\n\t\t}\n\t\tint l=-1;\n\t\tfor(int i=0;i<(int)((*this).vec.size());i++){\n\
    \t\t\tif((*this).vec[i]!=mint(0)){\n\t\t\t\tl=i;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\
    }\n\t\tif(l==-1){\n\t\t\treturn (*this).pre(deg);\n\t\t}\n\t\tif((deg-1)/n<(l)){\n\
    \t\t\treturn g;\n\t\t}\n\t\tFormalPowerSeries<T> f(deg-n*l);\n\t\tfor(int i=0;i<(int)(f.vec.size());i++){\n\
    \t\t\tif(i+l>=(int)((*this).vec.size())){\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tf.vec[i]=(*this).vec[i+l]/(*this).vec[l];\n\
    \t\t}\n\t\tf=(mint(n)*f.log()).exp();\n\t\tfor(int i=(int)((long long)l*n);i<deg;i++){\n\
    \t\t\tg.vec[i]=f.vec[i-n*l]*(*this).vec[l].pow(n);\n\t\t}\n\t\treturn g;\n\t}\n\
    \tFormalPowerSeries Taylor_shift(int a){\n\t\t//f(x+a)\u3092\u8A08\u7B97\n\t\t\
    if(fac[0]==0){\n\t\t\tin_fac();\n\t\t}\n\t\tFormalPowerSeries<T> g((int)((*this).vec.size()));\n\
    \t\tFormalPowerSeries<T> h((int)((*this).vec.size()));\n\t\tmint b=1;\n\t\tfor(int\
    \ i=0;i<(int)((*this).vec.size());i++){\n\t\t\tg.vec[i]=fac[(int)((*this).vec.size())-i-1]*(*this).vec[(int)((*this).vec.size())-i-1];\n\
    \t\t\th.vec[i]=b/fac[i];\n\t\t\tb*=a;\n\t\t}\n\t\tg*=h;\n\t\tg=g.pre((int)((*this).vec.size()));\n\
    \t\tfor(int i=0;i<(int)((*this).vec.size());i++){\n\t\t\tg.vec[i]/=fac[(int)((*this).vec.size())-i-1];\n\
    \t\t}\n\t\treverse(g.vec.begin(),g.vec.end());\n\t\treturn g;\n\t}\n\tFormalPowerSeries\
    \ sqrt(int deg=-1){\n\t\tif(deg==-1){\n\t\t\tdeg=(int)((*this).vec.size());\n\t\
    \t}\n\t\tint l=0;\n\t\tfor(int i=0;i<(int)((*this).vec.size());i++){\n\t\t\tif((*this).vec[i]!=0){\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t\tl++;\n\t\t}\n\t\tif(l==(int)((*this).vec.size())){\n\
    \t\t\treturn (*this).pre(deg);\n\t\t}\n\t\tassert(l%2==0);\n\t\tFormalPowerSeries<T>\
    \ f((int)((*this).vec.size())-l);\n\t\tfor(int i=0;i<(int)((*this).vec.size())-l;i++){\n\
    \t\t\tf.vec[i]=(*this).vec[i+l];\n\t\t}\n\t\tFormalPowerSeries<T> g({mod_sqrt((long\
    \ long)f.vec[0].val(),998244353)});\n\t\twhile((int)(g.vec.size())<deg-l/2){\n\
    \t\t\tint k=(int)(g.vec.size());\n\t\t\tg=(g+f.pre(2*k)*g.inv(2*k))/mint(2);\n\
    \t\t\tg=g.pre(2*k);\n\t\t}\n\t\tg=g.pre(deg-l/2);\n\t\tFormalPowerSeries<T> h(deg);\n\
    \t\tfor(int i=l/2;i<deg;i++){\n\t\t\th.vec[i]=g.vec[i-l/2];\n\t\t}\n\t\treturn\
    \ h;\n\t}\n\tfriend FormalPowerSeries product(vector<FormalPowerSeries<T>> &vec,int\
    \ deg=-1){\n\t\tint N=(int)(vec.size());\n\t\tif(N==0){\n\t\t\tFormalPowerSeries<T>\
    \ F(1);\n\t\t\tF.vec[0]=1;\n\t\t\treturn F;\n\t\t}\n\t\tqueue<FormalPowerSeries<T>>\
    \ que;\n\t\tfor(FormalPowerSeries<T> F : vec){\n\t\t\tque.push(F);\n\t\t}\n\t\t\
    while(que.size()>1){\n\t\t\tFormalPowerSeries<T> F=que.front();\n\t\t\tque.pop();\n\
    \t\t\tFormalPowerSeries<T> G=que.front();\n\t\t\tque.pop();\n\t\t\tque.push((F*G).pre(deg));\n\
    \t\t}\n\t\treturn que.front();\n\t}\n\t//\u3053\u3053\u304B\u3089\u306Foperator\n\
    \tFormalPowerSeries& operator+=(const FormalPowerSeries &other){\n\t\tint size=max((int)(vec.size()),(int)(other.vec.size()));\n\
    \t\tfor(int i=0;i<size;i++){\n\t\t\tif(i>=(int)(vec.size())){\n\t\t\t\tvec.emplace_back(other.vec[i]);\n\
    \t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif(i>=(int)(other.vec.size())){\n\t\t\t\tcontinue;\n\
    \t\t\t}\n\t\t\tvec[i]+=other.vec[i];\n\t\t}\n\t\treturn *this;\n\t}\n\tFormalPowerSeries&\
    \ operator+=(const T &other){\n\t\t(*this).vec[0]+=other;\n\t\treturn *this;\n\
    \t}\n\tFormalPowerSeries& operator-=(const FormalPowerSeries &other){\n\t\tint\
    \ size=max((int)(vec.size()),(int)(other.vec.size()));\n\t\tfor(int i=0;i<size;i++){\n\
    \t\t\tif(i>=(int)(vec.size())){\n\t\t\t\tvec.emplace_back(-other.vec[i]);\n\t\t\
    \t\tcontinue;\n\t\t\t}\n\t\t\tif(i>=(int)(other.vec.size())){\n\t\t\t\tcontinue;\n\
    \t\t\t}\n\t\t\tvec[i]-=other.vec[i];\n\t\t}\n\t\treturn *this;\n\t}\n\tFormalPowerSeries&\
    \ operator-=(const T &other){\n\t\t(*this).vec[0]-=other;\n\t\treturn *this;\n\
    \t}\n\tFormalPowerSeries& operator*=(const FormalPowerSeries &other){\n\t\tvec=convolution(vec,other.vec);\n\
    \t\treturn *this;\n\t}\n\tFormalPowerSeries& operator*=(const T &other){\n\t\t\
    for(int i=0;i<this->vec.size();i++){\n\t\t\t(*this).vec[i]*=other;\n\t\t}\n\t\t\
    return *this;\n\t}\n\tFormalPowerSeries& operator/=(const FormalPowerSeries &other){\n\
    \t\t(*this)*=other.inv();\n\t\treturn *this;\n\t}\n\tFormalPowerSeries& operator/=(const\
    \ T &other){\n\t\tfor(int i=0;i<(int)((*this).vec.size());i++){\n\t\t\t(*this).vec[i]/=other;\n\
    \t\t}\n\t\treturn *this;\n\t}\n\tFormalPowerSeries operator-() const{\n\t\treturn\
    \ FormalPowerSeries(0)-FormalPowerSeries(*this);\n\t}\n\tFormalPowerSeries operator+(const\
    \ FormalPowerSeries &g) const{\n\t\treturn FormalPowerSeries(*this)+=g;\n\t}\n\
    \tfriend FormalPowerSeries operator+(const FormalPowerSeries &f,const T &g){\n\
    \t\treturn FormalPowerSeries(f)+=g;\n\t}\n\tfriend FormalPowerSeries operator+(const\
    \ T &g,const FormalPowerSeries &f){\n\t\treturn FormalPowerSeries(f)+=g;\n\t}\n\
    \tfriend FormalPowerSeries operator-(const FormalPowerSeries &f,const T &g){\n\
    \t\treturn FormalPowerSeries(f)-=g;\n\t}\n\tfriend FormalPowerSeries operator-(const\
    \ T &g,const FormalPowerSeries &f){\n\t\treturn -FormalPowerSeries(f)+g;\n\t}\n\
    \tFormalPowerSeries operator-(const FormalPowerSeries &g) const{\n\t\treturn FormalPowerSeries(*this)-=g;\n\
    \t}\n\tFormalPowerSeries operator*(const FormalPowerSeries &g) const{\n\t\treturn\
    \ FormalPowerSeries(*this)*=g;\n\t}\n\tfriend FormalPowerSeries operator*(const\
    \ FormalPowerSeries &f, const T &g){\n\t\treturn FormalPowerSeries(f)*=g;\n\t\
    }\n\tfriend FormalPowerSeries operator*(const T &g, const FormalPowerSeries &f){\n\
    \t\treturn FormalPowerSeries(f)*=g;\n\t}\n\tFormalPowerSeries operator/(const\
    \ FormalPowerSeries &g) const{\n\t\treturn FormalPowerSeries(*this)/=g;\n\t}\n\
    \tfriend FormalPowerSeries operator/(const FormalPowerSeries &f,const T &g){\n\
    \t\treturn FormalPowerSeries(f)/=g;\n\t}\n\tfriend FormalPowerSeries operator/(const\
    \ T &g,const FormalPowerSeries &f){\n\t\treturn FormalPowerSeries(f).inv()*g;\n\
    \t}\n};\n#line 4 \"verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp\"\
    \n\nint main(){\n\tint N;\n\tscanf(\"%d\",&N);\n\tFormalPowerSeries<mint> F(N);\n\
    \tfor(int i=0;i<N;i++){\n\t\tint k;\n\t\tscanf(\"%d\",&k);\n\t\tF.vec[i]=k;\n\t\
    }\n\tF=F.exp();\n\tfor(mint i : F.vec){\n\t\tprintf(\"%d \",i.val());\n\t}\n\t\
    printf(\"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n#include \"../../polynomial/FormalPowerSeries.hpp\"\n#include<stdio.h>\n\nint\
    \ main(){\n\tint N;\n\tscanf(\"%d\",&N);\n\tFormalPowerSeries<mint> F(N);\n\t\
    for(int i=0;i<N;i++){\n\t\tint k;\n\t\tscanf(\"%d\",&k);\n\t\tF.vec[i]=k;\n\t\
    }\n\tF=F.exp();\n\tfor(mint i : F.vec){\n\t\tprintf(\"%d \",i.val());\n\t}\n\t\
    printf(\"\\n\");\n}\n"
  dependsOn:
  - polynomial/FormalPowerSeries.hpp
  - math/mod_sqrt.hpp
  - math/power.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2024-07-17 21:35:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp
- /verify/verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp.html
title: verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp
---
