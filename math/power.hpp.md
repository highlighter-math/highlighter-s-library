---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: math/mod_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-ntl/ntl_1_b.test.cpp
    title: verify/verify-aoj-ntl/ntl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/sqrt_mod.test.cpp
    title: verify/verify-yosupo-math/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/power.hpp\"\n#include<functional>\n\ntemplate<class\
    \ S>\nS power(S a,long long b,auto &op,auto &e){\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n    S mul=a;\n    S ans=e();\n\
    \    while(b){\n        if(b&1){\n        \tans=op(ans,mul);\n        }\n    \
    \    b>>=1;\n        mul=op(mul,mul);\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include<functional>\n\ntemplate<class S>\nS power(S a,long\
    \ long b,auto &op,auto &e){\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n    S mul=a;\n    S ans=e();\n\
    \    while(b){\n        if(b&1){\n        \tans=op(ans,mul);\n        }\n    \
    \    b>>=1;\n        mul=op(mul,mul);\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - math/mod_sqrt.hpp
  timestamp: '2024-06-18 23:43:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/sqrt_mod.test.cpp
  - verify/verify-aoj-ntl/ntl_1_b.test.cpp
documentation_of: math/power.hpp
layout: document
title: power
---

## 概要
