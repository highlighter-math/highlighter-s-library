---
title: power
documentation_of: ../../math/power.hpp
---

## 概要
モノイドを入れて使用する．
$a$ に $op$ を $b$ 回作用させたときの結果を $O(\log b)$ で返す．
オラクルとして `op,e` の $2$ 種類を使用するが，これらが定数時間で動くものと仮定したときの計算量を記述する．オラクル内部の計算量が $O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる．

## 使い方
- `power<S>(S a,long long b,auto op,auto e)`
