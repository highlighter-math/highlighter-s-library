---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/power.hpp
    title: power
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
  bundledCode: "#line 1 \"verify/verify-aoj-ntl/ntl_1_b.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\n#include<stdio.h>\n#line\
    \ 2 \"math/power.hpp\"\ntemplate<class S>\nS power(S a,S b,S p=-1){\n\tS mul=a;\n\
    \tS res=1;\n\tif(p==-1){\n\t\twhile(b){\n\t\t\tif(b&1){\n\t\t\t\tres*=mul;\n\t\
    \t\t}\n\t\t\tmul*=mul;\n\t\t\tb>>=1;\n\t\t}\n\t\treturn res;\n\t}\n\twhile(b){\n\
    \t\tif(b&1){\n\t\t\tres*=mul;\n\t\t\tres%=p;\n\t\t}\n\t\tmul*=mul;\n\t\tmul%=p;\n\
    \t\tb>>=1;\n\t}\n\tif(res<0)res+=p;\n\treturn res;\n}\n#line 4 \"verify/verify-aoj-ntl/ntl_1_b.test.cpp\"\
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
  timestamp: '2024-07-17 20:49:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-aoj-ntl/ntl_1_b.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-ntl/ntl_1_b.test.cpp
- /verify/verify/verify-aoj-ntl/ntl_1_b.test.cpp.html
title: verify/verify-aoj-ntl/ntl_1_b.test.cpp
---
