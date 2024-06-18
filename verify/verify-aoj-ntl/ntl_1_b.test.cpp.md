---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
  bundledCode: "#line 1 \"verify/verify-aoj-ntl/ntl_1_b.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\n#include<stdio.h>\n#line\
    \ 2 \"math/power.hpp\"\n#include<functional>\n\ntemplate<class S>\nS power(S a,long\
    \ long b,auto op,auto e){\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n    S mul=a;\n    S ans=e();\n\
    \    while(b){\n        if(b&1){\n        \tans=op(ans,mul);\n        }\n    \
    \    b>>=1;\n        mul=op(mul,mul);\n    }\n    return ans;\n}\n#line 4 \"verify/verify-aoj-ntl/ntl_1_b.test.cpp\"\
    \n\nlong long p=1000000007LL;\n\nlong long op(long long a,long long b){\n\treturn\
    \ a%p*b%p;\n}\n\nlong long e(){\n\treturn 1LL;\n}\n\nint main(){\n\tlong long\
    \ a,b;\n\tscanf(\"%lld%lld\",&a,&b);\n\tprintf(\"%lld\\n\",power<long long>(a,b,op,e));\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\n#include<stdio.h>\n\
    #include \"../../math/power.hpp\"\n\nlong long p=1000000007LL;\n\nlong long op(long\
    \ long a,long long b){\n\treturn a%p*b%p;\n}\n\nlong long e(){\n\treturn 1LL;\n\
    }\n\nint main(){\n\tlong long a,b;\n\tscanf(\"%lld%lld\",&a,&b);\n\tprintf(\"\
    %lld\\n\",power<long long>(a,b,op,e));\n}\n"
  dependsOn:
  - math/power.hpp
  isVerificationFile: true
  path: verify/verify-aoj-ntl/ntl_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-06-18 23:40:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-ntl/ntl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-ntl/ntl_1_b.test.cpp
- /verify/verify/verify-aoj-ntl/ntl_1_b.test.cpp.html
title: verify/verify-aoj-ntl/ntl_1_b.test.cpp
---
