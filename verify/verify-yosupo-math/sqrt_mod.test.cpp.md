---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: math/mod_sqrt.hpp
  - icon: ':question:'
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
    \t\tmul=std::make_pair(f,s);\n\t}\n\treturn q.first;\n}\n#line 5 \"verify/verify-yosupo-math/sqrt_mod.test.cpp\"\
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
  timestamp: '2024-07-17 20:53:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/sqrt_mod.test.cpp
- /verify/verify/verify-yosupo-math/sqrt_mod.test.cpp.html
title: verify/verify-yosupo-math/sqrt_mod.test.cpp
---
