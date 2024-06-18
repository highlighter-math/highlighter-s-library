---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/sqrt_mod.test.cpp
    title: verify/verify-yosupo-math/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/mod_sqrt.hpp\"\n#include<stdio.h>\n#include<utility>\n\
    #line 2 \"math/power.hpp\"\n#include<functional>\n\ntemplate<class S>\nS power(S\
    \ a,long long b,auto &op,auto &e){\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n    S mul=a;\n    S ans=e();\n\
    \    while(b){\n        if(b&1){\n        \tans=op(ans,mul);\n        }\n    \
    \    b>>=1;\n        mul=op(mul,mul);\n    }\n    return ans;\n}\n#line 4 \"math/mod_sqrt.hpp\"\
    \n\nlong long mod_sqrt(long long &Y,long long &p){\n    if(p==2 || Y==0){\n  \
    \      return Y;\n    }\n    auto op=[&](long long a,long long b){\n    \treturn\
    \ a%p*b%p;\n    };\n    auto e=[](){\n    \treturn 1LL;\n    };\n    if(power<long\
    \ long>(Y,(p-1)/2LL,op,e)==p-1){\n        return -1;\n    }\n    int Z=0;\n  \
    \  while(true){\n        long long ZZ=Z*Z%p-Y%p;\n        ZZ%=p;\n        if(ZZ<0){\n\
    \            ZZ+=p;\n        }\n        if(power<long long>(ZZ,(p-1)/2,op,e)==p-1){\n\
    \            break;\n        }\n        Z++;\n    }\n    std::pair<long long,long\
    \ long> mul=std::make_pair(Z,1);\n    int t=(p+1)/2;\n    std::pair<long long,long\
    \ long> q=std::make_pair(1,0);\n    while(t){\n        if(t&1){\n            int\
    \ k=q.first*mul.first%p+(Z*Z-Y)%p*q.second%p*mul.second%p;\n            int l=q.second*mul.first%p+q.first*mul.second%p;\n\
    \            l%=p;\n            k%=p;\n            if(k<0){\n                k+=p;\n\
    \            }\n            q=std::make_pair(k,l);\n        }\n        t>>=1;\n\
    \        int f=mul.first*mul.first%p+(Z*Z-Y)%p*mul.second%p*mul.second%p;\n  \
    \      f%=p;\n        if(f<0){\n            f+=p;\n        }\n        int s=mul.second*mul.first%p*2%p;\n\
    \        mul=std::make_pair(f,s);\n    }\n    return q.first;\n}\n"
  code: "#include<stdio.h>\n#include<utility>\n#include \"power.hpp\"\n\nlong long\
    \ mod_sqrt(long long &Y,long long &p){\n    if(p==2 || Y==0){\n        return\
    \ Y;\n    }\n    auto op=[&](long long a,long long b){\n    \treturn a%p*b%p;\n\
    \    };\n    auto e=[](){\n    \treturn 1LL;\n    };\n    if(power<long long>(Y,(p-1)/2LL,op,e)==p-1){\n\
    \        return -1;\n    }\n    int Z=0;\n    while(true){\n        long long\
    \ ZZ=Z*Z%p-Y%p;\n        ZZ%=p;\n        if(ZZ<0){\n            ZZ+=p;\n     \
    \   }\n        if(power<long long>(ZZ,(p-1)/2,op,e)==p-1){\n            break;\n\
    \        }\n        Z++;\n    }\n    std::pair<long long,long long> mul=std::make_pair(Z,1);\n\
    \    int t=(p+1)/2;\n    std::pair<long long,long long> q=std::make_pair(1,0);\n\
    \    while(t){\n        if(t&1){\n            int k=q.first*mul.first%p+(Z*Z-Y)%p*q.second%p*mul.second%p;\n\
    \            int l=q.second*mul.first%p+q.first*mul.second%p;\n            l%=p;\n\
    \            k%=p;\n            if(k<0){\n                k+=p;\n            }\n\
    \            q=std::make_pair(k,l);\n        }\n        t>>=1;\n        int f=mul.first*mul.first%p+(Z*Z-Y)%p*mul.second%p*mul.second%p;\n\
    \        f%=p;\n        if(f<0){\n            f+=p;\n        }\n        int s=mul.second*mul.first%p*2%p;\n\
    \        mul=std::make_pair(f,s);\n    }\n    return q.first;\n}\n"
  dependsOn:
  - math/power.hpp
  isVerificationFile: false
  path: math/mod_sqrt.hpp
  requiredBy: []
  timestamp: '2024-06-18 23:55:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/sqrt_mod.test.cpp
documentation_of: math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/math/mod_sqrt.hpp
- /library/math/mod_sqrt.hpp.html
title: math/mod_sqrt.hpp
---
