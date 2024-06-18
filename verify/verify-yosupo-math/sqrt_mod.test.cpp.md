---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../math/power.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include<stdio.h>\n\
    #include<utility>\n#include \"../../math/mod_sqrt.hpp\"\n\nsigned main(){\n  \
    \  int t;\n    scanf(\"%d\",&t);\n    for(;t--;){\n\t    long long a,p;\n\t  \
    \  scanf(\"%lld%lld\",&a,&p);\n\t    printf(\"%lld\\n\",mod_sqrt(a,p));\n    }\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/verify-yosupo-math/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-math/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-math/sqrt_mod.test.cpp
- /verify/verify/verify-yosupo-math/sqrt_mod.test.cpp.html
title: verify/verify-yosupo-math/sqrt_mod.test.cpp
---
