---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/power.hpp
    title: power
  _extendedRequiredBy:
  - icon: ':question:'
    path: polynomial/FormalPowerSeries.hpp
    title: polynomial/FormalPowerSeries.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/sqrt_mod.test.cpp
    title: verify/verify-yosupo-math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp
    title: verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-polynomial/inv_of_formal_power_series.test.cpp
    title: verify/verify-yosupo-polynomial/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-polynomial/log_of_formal_power_series.test.cpp
    title: verify/verify-yosupo-polynomial/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-polynomial/pow_of_formal_power_series.test.cpp
    title: verify/verify-yosupo-polynomial/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-polynomial/sqrt_of_formal_power_series.test.cpp
    title: verify/verify-yosupo-polynomial/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_sqrt.hpp\"\n#include<stdio.h>\n#include<utility>\n\
    #line 2 \"math/power.hpp\"\ntemplate<class S>\nS power(S a,S b,S p=-1){\n\tS mul=a;\n\
    \tS res=1;\n\tif(p==-1){\n\t\twhile(b){\n\t\t\tif(b&1){\n\t\t\t\tres*=mul;\n\t\
    \t\t}\n\t\t\tmul*=mul;\n\t\t\tb>>=1;\n\t\t}\n\t\treturn res;\n\t}\n\twhile(b){\n\
    \t\tif(b&1){\n\t\t\tres*=mul;\n\t\t\tres%=p;\n\t\t}\n\t\tmul*=mul;\n\t\tmul%=p;\n\
    \t\tb>>=1;\n\t}\n\tif(res<0)res+=p;\n\treturn res;\n}\n#line 5 \"math/mod_sqrt.hpp\"\
    \n\nlong long mod_sqrt(long long Y,long long p){\n\tif(p==2 || Y==0){\n\t\treturn\
    \ Y;\n\t}\n\tif(power(Y,(p-1)/2LL,p)==p-1){\n\t\treturn -1;\n\t}\n\tint Z=0;\n\
    \twhile(true){\n\t\tlong long ZZ=Z*Z%p-Y%p;\n\t\tZZ%=p;\n\t\tif(ZZ<0){\n\t\t\t\
    ZZ+=p;\n\t\t}\n\t\tif(power(ZZ,(p-1)/2,p)==p-1){\n\t\t\tbreak;\n\t\t}\n\t\tZ++;\n\
    \t}\n\tstd::pair<long long,long long> mul=std::make_pair(Z,1);\n\tint t=(p+1)/2;\n\
    \tstd::pair<long long,long long> q=std::make_pair(1,0);\n\twhile(t){\n\t\tif(t&1){\n\
    \t\t\tint k=q.first*mul.first%p+(Z*Z-Y)%p*q.second%p*mul.second%p;\n\t\t\tint\
    \ l=q.second*mul.first%p+q.first*mul.second%p;\n\t\t\tl%=p;\n\t\t\tk%=p;\n\t\t\
    \tif(k<0){\n\t\t\t\tk+=p;\n\t\t\t}\n\t\t\tq=std::make_pair(k,l);\n\t\t}\n\t\t\
    t>>=1;\n\t\tint f=mul.first*mul.first%p+(Z*Z-Y)%p*mul.second%p*mul.second%p;\n\
    \t\tf%=p;\n\t\tif(f<0){\n\t\t\tf+=p;\n\t\t}\n\t\tint s=mul.second*mul.first%p*2%p;\n\
    \t\tmul=std::make_pair(f,s);\n\t}\n\treturn q.first;\n}\n"
  code: "#pragma once\n#include<stdio.h>\n#include<utility>\n#include \"power.hpp\"\
    \n\nlong long mod_sqrt(long long Y,long long p){\n\tif(p==2 || Y==0){\n\t\treturn\
    \ Y;\n\t}\n\tif(power(Y,(p-1)/2LL,p)==p-1){\n\t\treturn -1;\n\t}\n\tint Z=0;\n\
    \twhile(true){\n\t\tlong long ZZ=Z*Z%p-Y%p;\n\t\tZZ%=p;\n\t\tif(ZZ<0){\n\t\t\t\
    ZZ+=p;\n\t\t}\n\t\tif(power(ZZ,(p-1)/2,p)==p-1){\n\t\t\tbreak;\n\t\t}\n\t\tZ++;\n\
    \t}\n\tstd::pair<long long,long long> mul=std::make_pair(Z,1);\n\tint t=(p+1)/2;\n\
    \tstd::pair<long long,long long> q=std::make_pair(1,0);\n\twhile(t){\n\t\tif(t&1){\n\
    \t\t\tint k=q.first*mul.first%p+(Z*Z-Y)%p*q.second%p*mul.second%p;\n\t\t\tint\
    \ l=q.second*mul.first%p+q.first*mul.second%p;\n\t\t\tl%=p;\n\t\t\tk%=p;\n\t\t\
    \tif(k<0){\n\t\t\t\tk+=p;\n\t\t\t}\n\t\t\tq=std::make_pair(k,l);\n\t\t}\n\t\t\
    t>>=1;\n\t\tint f=mul.first*mul.first%p+(Z*Z-Y)%p*mul.second%p*mul.second%p;\n\
    \t\tf%=p;\n\t\tif(f<0){\n\t\t\tf+=p;\n\t\t}\n\t\tint s=mul.second*mul.first%p*2%p;\n\
    \t\tmul=std::make_pair(f,s);\n\t}\n\treturn q.first;\n}\n"
  dependsOn:
  - math/power.hpp
  isVerificationFile: false
  path: math/mod_sqrt.hpp
  requiredBy:
  - polynomial/FormalPowerSeries.hpp
  timestamp: '2024-07-17 20:53:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-yosupo-polynomial/pow_of_formal_power_series.test.cpp
  - verify/verify-yosupo-polynomial/inv_of_formal_power_series.test.cpp
  - verify/verify-yosupo-polynomial/log_of_formal_power_series.test.cpp
  - verify/verify-yosupo-polynomial/exp_of_formal_power_series.test.cpp
  - verify/verify-yosupo-polynomial/sqrt_of_formal_power_series.test.cpp
  - verify/verify-yosupo-math/sqrt_mod.test.cpp
documentation_of: math/mod_sqrt.hpp
layout: document
title: mod sqrt
---

## 使い方
- `long long mod_sqrt(long long Y,long long p)`

$\bmod p$ 上の $Y$ の平方根を返す．存在しない場合は `-1` を返す．

## 計算量
$O(\log p)$