---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../math/power.hpp:\
    \ line -1: no such header\n"
  code: "#include<stdio.h>\n#include<utility>\n#include \"../../math/power.hpp\"\n\
    \nlong long mod_sqrt(long long &Y,long long &p){\n    if(p==2 || Y==0){\n    \
    \    return Y;\n    }\n    auto op=[&](long long a,long long b){\n    \treturn\
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
  dependsOn: []
  isVerificationFile: false
  path: math/mod_sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/math/mod_sqrt.hpp
- /library/math/mod_sqrt.hpp.html
title: math/mod_sqrt.hpp
---
