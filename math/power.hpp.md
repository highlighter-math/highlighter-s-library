---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: math/mod_sqrt.hpp
  - icon: ':warning:'
    path: polynomial/FormalPowerSeries.hpp
    title: polynomial/FormalPowerSeries.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-aoj-ntl/ntl_1_b.test.cpp
    title: verify/verify-aoj-ntl/ntl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/sqrt_mod.test.cpp
    title: verify/verify-yosupo-math/sqrt_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/power.hpp\"\ntemplate<class S>\nS power(S a,S b,S p=-1){\n\
    \tS mul=a;\n\tS res=1;\n\tif(p==-1){\n\t\twhile(b){\n\t\t\tif(b&1){\n\t\t\t\t\
    res*=mul;\n\t\t\t}\n\t\t\tmul*=mul;\n\t\t\tb>>=1;\n\t\t}\n\t\treturn res;\n\t\
    }\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=mul;\n\t\t\tres%=p;\n\t\t}\n\t\tmul*=mul;\n\
    \t\tmul%=p;\n\t\tb>>=1;\n\t}\n\tif(res<0)res+=p;\n\treturn res;\n}\n"
  code: "#pragma once\ntemplate<class S>\nS power(S a,S b,S p=-1){\n\tS mul=a;\n\t\
    S res=1;\n\tif(p==-1){\n\t\twhile(b){\n\t\t\tif(b&1){\n\t\t\t\tres*=mul;\n\t\t\
    \t}\n\t\t\tmul*=mul;\n\t\t\tb>>=1;\n\t\t}\n\t\treturn res;\n\t}\n\twhile(b){\n\
    \t\tif(b&1){\n\t\t\tres*=mul;\n\t\t\tres%=p;\n\t\t}\n\t\tmul*=mul;\n\t\tmul%=p;\n\
    \t\tb>>=1;\n\t}\n\tif(res<0)res+=p;\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - polynomial/FormalPowerSeries.hpp
  - math/mod_sqrt.hpp
  timestamp: '2024-07-17 20:49:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-yosupo-math/sqrt_mod.test.cpp
  - verify/verify-aoj-ntl/ntl_1_b.test.cpp
documentation_of: math/power.hpp
layout: document
title: power
---

## 概要
モノイドを入れて使用する．
$a$ に $op$ を $b$ 回作用させたときの結果を $O(\log b)$ で返す．
オラクルとして `op,e` の $2$ 種類を使用するが，これらが定数時間で動くものと仮定したときの計算量を記述する．オラクル内部の計算量が $O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる．

## 使い方
- `power<S>(S a,long long b,auto op,auto e)`
