---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: math/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: power
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"verify/verify-yosupo-math/sqrt_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include<stdio.h>\n#include<utility>\n\
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
    \        mul=std::make_pair(f,s);\n    }\n    return q.first;\n}\n#line 5 \"verify/verify-yosupo-math/sqrt_mod.test.cpp\"\
    \n\nsigned main(){\n    int t;\n    scanf(\"%d\",&t);\n    for(;t--;){\n\t   \
    \ long long a,p;\n\t    scanf(\"%lld%lld\",&a,&p);\n\t    printf(\"%lld\\n\",mod_sqrt(a,p));\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include<stdio.h>\n\
    #include<utility>\n#include \"../../math/mod_sqrt.hpp\"\n\nsigned main(){\n  \
    \  int t;\n    scanf(\"%d\",&t);\n    for(;t--;){\n\t    long long a,p;\n\t  \
    \  scanf(\"%lld%lld\",&a,&p);\n\t    printf(\"%lld\\n\",mod_sqrt(a,p));\n    }\n\
    }\n"
  dependsOn:
  - math/mod_sqrt.hpp
  - math/power.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-math/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2024-06-18 23:55:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/sqrt_mod.test.cpp
- /verify/verify/verify-yosupo-math/sqrt_mod.test.cpp.html
title: verify/verify-yosupo-math/sqrt_mod.test.cpp
---
