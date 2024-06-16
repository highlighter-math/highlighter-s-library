---
title: Fenwick Tree
documentation_of: ../../data-structure/Fenwick_Tree.hpp
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
(1) Fenwick_Tree<S, op, op_inv, e> fw(int n)
(2) Fenwick_Tree<S, op, op_inv, e> fw(vector<S> v)
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

int op_inv(int a, int b) {
 return a-b;
}

int e() {
  return 0;
}

Fenwick_Tree<int, op, op_inv, e> fw(10);
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
