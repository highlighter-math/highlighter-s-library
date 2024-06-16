---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/Fenwick_Tree.hpp\"\n#include<bit>\n#include<functional>\n\
    #include<stdio.h>\n#include<vector>\nusing namespace std;\n\ntemplate<class S,auto\
    \ op,auto op_inv,auto e>\nstruct Fenwick_Tree{\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(op_inv),\
    \ std::function<S(S, S)>>,\"op_inv must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n\tint siz=1;\n\tvector<S> dat;\n\
    \tFenwick_Tree(int N) : dat(N,e()){\n\t\tsiz=N;\n\t}\n\tFenwick_Tree(vector<S>\
    \ A) : dat(A.size(),e()){\n\t\tsiz=(int)(A.size());\n\t\tvector<S> sum(siz+1,e());\n\
    \t\tfor(int i=1;i<=siz;i++){\n\t\t\tsum[i]=op(sum[i-1],A[i-1]);\n\t\t}\n\t\tfor(int\
    \ i=0;i<siz;i++){\n\t\t\tint len=(i+1)&(-i-1);\n\t\t\tdat[i]=op_inv(sum[i+1],sum[i+1-len]);\n\
    \t\t}\n\t}\n\tvoid add(int k,S x){\n\t\tfor(int i=k;i<siz;i+=((i+1)&(-i-1))){\n\
    \t\t\tdat[i]=op(dat[i],x);\n\t\t}\n\t}\n\tS prod(int k){\n\t\t//op(A[0],A[1],...,A[k-1])\n\
    \t\tif(k<=0){\n\t\t\treturn e();\n\t\t}\n\t\tif(k>siz){\n\t\t\treturn prod(siz);\n\
    \t\t}\n\t\tS ans=e();\n\t\tfor(int i=k-1;i>=0;i-=((i+1)&(-i-1))){\n\t\t\tans=op(ans,dat[i]);\n\
    \t\t}\n\t\treturn ans;\n\t}\n\tS prod(int l,int r){\n\t\treturn op_inv(prod(r),prod(l));\n\
    \t}\n\tvoid update(int k,S x){\n\t\tS y=prod(k,k+1);\n\t\tadd(k,op_sub(x,y));\n\
    \t}\n\tint lower_bound(S x,bool (*comp)(S,S)){\n\t\t//comp(op(A[0],A[1],...,A[k-1]),x)\u304C\
    true\u306B\u306A\u308B\u6700\u5927\u306Ek\n\t\t//true,true,true,...,true,false,false,...false\u3067\
    \u306A\u3044\u3068\u3044\u3051\u306A\u3044\n\t\tint k=(int)(bit_floor((unsigned\
    \ int)(siz)));\n\t\tint ans=0;\n\t\tfor(;k>0;k/=2){\n\t\t\tif(ans+k<=siz && comp(dat[ans+k-1],x)){\n\
    \t\t\t\tx=op_inv(x,dat[ans+k-1]);\n\t\t\t\tans+=k;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ ans;\n\t}\n};\n"
  code: "#pragma once\n#include<bit>\n#include<functional>\n#include<stdio.h>\n#include<vector>\n\
    using namespace std;\n\ntemplate<class S,auto op,auto op_inv,auto e>\nstruct Fenwick_Tree{\n\
    \tstatic_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,\"\
    op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(op_inv),\
    \ std::function<S(S, S)>>,\"op_inv must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n\tint siz=1;\n\tvector<S> dat;\n\
    \tFenwick_Tree(int N) : dat(N,e()){\n\t\tsiz=N;\n\t}\n\tFenwick_Tree(vector<S>\
    \ A) : dat(A.size(),e()){\n\t\tsiz=(int)(A.size());\n\t\tvector<S> sum(siz+1,e());\n\
    \t\tfor(int i=1;i<=siz;i++){\n\t\t\tsum[i]=op(sum[i-1],A[i-1]);\n\t\t}\n\t\tfor(int\
    \ i=0;i<siz;i++){\n\t\t\tint len=(i+1)&(-i-1);\n\t\t\tdat[i]=op_inv(sum[i+1],sum[i+1-len]);\n\
    \t\t}\n\t}\n\tvoid add(int k,S x){\n\t\tfor(int i=k;i<siz;i+=((i+1)&(-i-1))){\n\
    \t\t\tdat[i]=op(dat[i],x);\n\t\t}\n\t}\n\tS prod(int k){\n\t\t//op(A[0],A[1],...,A[k-1])\n\
    \t\tif(k<=0){\n\t\t\treturn e();\n\t\t}\n\t\tif(k>siz){\n\t\t\treturn prod(siz);\n\
    \t\t}\n\t\tS ans=e();\n\t\tfor(int i=k-1;i>=0;i-=((i+1)&(-i-1))){\n\t\t\tans=op(ans,dat[i]);\n\
    \t\t}\n\t\treturn ans;\n\t}\n\tS prod(int l,int r){\n\t\treturn op_inv(prod(r),prod(l));\n\
    \t}\n\tvoid update(int k,S x){\n\t\tS y=prod(k,k+1);\n\t\tadd(k,op_sub(x,y));\n\
    \t}\n\tint lower_bound(S x,bool (*comp)(S,S)){\n\t\t//comp(op(A[0],A[1],...,A[k-1]),x)\u304C\
    true\u306B\u306A\u308B\u6700\u5927\u306Ek\n\t\t//true,true,true,...,true,false,false,...false\u3067\
    \u306A\u3044\u3068\u3044\u3051\u306A\u3044\n\t\tint k=(int)(bit_floor((unsigned\
    \ int)(siz)));\n\t\tint ans=0;\n\t\tfor(;k>0;k/=2){\n\t\t\tif(ans+k<=siz && comp(dat[ans+k-1],x)){\n\
    \t\t\t\tx=op_inv(x,dat[ans+k-1]);\n\t\t\t\tans+=k;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ ans;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/Fenwick_Tree.hpp
  requiredBy: []
  timestamp: '2024-06-16 21:49:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/Fenwick_Tree.hpp
layout: document
title: Fenwick Tree
---

# 概要
[アーベル群](https://ja.wikipedia.org/wiki/%E3%82%A2%E3%83%BC%E3%83%99%E3%83%AB%E7%BE%A4) $(S, \cdot ~ \colon S \times S \to S,e \in S)$ ，つまり

- 結合律: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a,b,c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$
- 逆元の存在: $a \cdot a^{-1} = a^{-1} \cdot a = e$ for all $a \in S$
- 交換律: $a \cdot b = b \cdot a$ for all $a, b \in S$

を満たす代数構造に対し使用できるデータ構造．

長さ $N$ の $S$ の配列に対し，

- 要素の $1$ 点変更
- 区間の要素の総積の取得

を $O(\log N)$ で行うことが出来る．

また，このライブラリはオラクルとして `op,op_inv,e` の $3$ 種類を使用するが，これらが定数時間で動くものと仮定したときの計算量を記述する．オラクル内部の計算量が $O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる．

# コンストラクタ
```cpp
(1) Fenwick_Tree<S, op, e> fw(int n)
(2) Fenwick_Tree<S, op, e> fw(vector<S> v)
```
 - 型 `S`
 - 二項演算 `S op(S a, S b)`
 - 逆演算 `S op_inv(S a, S b)`
 - 単位元 `S e()`

を定義する必要がある．例として，Range Sum Queryならば

```cpp
int op(int a, int b) {
  return a+b;
}

int e() {
  return 0;
}

Fenwick_Tree<int, op, e> fw(10);
```

のようになる．

- (1): 長さ `n` で初期値がすべて `e()` であるような数列 `a` を作る．
- (2): 長さ `n=v.size()` の数列 `a` を作る．`v` の内容が初期値となる．

## 計算量
- $O(n)$

# update

```cpp
void fw.update(int p, S x)
```

`a[p]` に `x` を代入する．

## 計算量
- $O(\log n)$

# add

```cpp
void fw.add(int p,S x)
```

`a[p]` に `op(a[p],x)` を代入する．

## 計算量
- $O(\log n)$

# get

```cpp
S fw.get(int p)
```

`a[p]` を返す．

## 計算量
- $O(\log n)$

# prod

```cpp
(1) S fw.prod(int r)
(2) S fw.prod(int l, int r)
```

- (1): `op(a[0],a[1], ... , a[r-1])` を計算する．
- (2): `op(a[l],a[l+1], ... , a[r-1])` を計算する．

## 計算量
- $O(log n)$

# lower_bound

```cpp
int fw.lower_bound(S x, bool comp)
```

`a<b` のときに `true` ，そうでないときに `false` を返すような関数 `bool comp(S a, S b)` を定義する必要がある．

`comp(x,op(a[0],a[1], ..., a[r-1]))=true` となる最小の `r` を返す．

## 計算量
- $O(log n)$
