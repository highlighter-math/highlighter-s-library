---
title: Fenwick Tree
documentation_of: ../../data-structure/Fenwick_Tree.hpp
---

[アーベル群](https://ja.wikipedia.org/wiki/%E3%82%A2%E3%83%BC%E3%83%99%E3%83%AB%E7%BE%A4) $(S, \cdot ~ \colon S \times S \to S,e \in S)$ ，つまり

- 結合律: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a,b,c \in S$
- 単位元の存在: $a \cdot e = e \cdot a = a$ for all $a \in S$
- 逆元の存在: $a \cdot a^{-1} = a^{-1} \cdot a = e$ for all $a \in S$
- 交換律: $a \cdot b = b \cdot a$ for all $a, b \in S$

を満たす代数構造に対し使用できるデータ構造です．

長さ $N$ の $S$ の配列に対し，

- 要素の $1$ 点変更
- 区間の要素の総積の取得

を $O(\log N)$ で行うことが出来ます．

また，このライブラリはオラクルとして<code>op</code
