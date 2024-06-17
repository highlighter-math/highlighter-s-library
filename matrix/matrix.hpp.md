---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-matrix/matrix_product.test.cpp
    title: verify/verify-yosupo-matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-matrix/pow_of_matrix.test.cpp
    title: verify/verify-yosupo-matrix/pow_of_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matrix/matrix.hpp\"\n#include<vector>\n#include<cassert>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct matrix{\n\tint H,W;\n\tvector<vector<T>>\
    \ table;\n\tmatrix(int h,int w) : H(h),W(w){\n\t\ttable.resize(h,vector<T>(w));\n\
    \t}\n\tint size(){\n\t\treturn H;\n\t}\n\tmatrix pow(long long N){\n\t\tassert(H==W);\n\
    \t\tassert(0<=N);\n\t\tmatrix x=*this;\n\t\tmatrix r(H,H);\n\t\tfor(int i=0;i<H;i++){\n\
    \t\t\tr[i][i]=1;\n\t\t}\n\t\twhile(N){\n\t\t\tif(N&1)r*=x;\n\t\t\tx*=x;\n\t\t\t\
    N>>=1;\n\t\t}\n\t\treturn r;\n\t}\n\tvector<T>& operator[](int index){\n\t\tassert(index<H);\n\
    \t\treturn table[index];\n\t}\n\tmatrix& operator+=(const matrix &other){\n\t\t\
    for(int i=0;i<H;i++){\n\t\t\tfor(int j=0;j<W;j++){\n\t\t\t\tif((int)(other.table.size())<=i){\n\
    \t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tif((int)(other.table[i].size())<=j){\n\
    \t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\t(*this)[i][j]+=other.table[i][j];\n\t\t\
    \t}\n\t\t}\n\t\treturn *this;\n\t}\n\tmatrix operator*=(const matrix &other){\n\
    \t\tint h=other.H;\n\t\tint w=other.W;\n\t\tassert(h==W);\n\t\t//\u7D50\u679C\u306F\
    H*w\u884C\u5217\u306B\u306A\u308B\n\t\tmatrix result(H,w);\n\t\tfor(int i=0;i<H;i++){\n\
    \t\t\tfor(int k=0;k<W;k++){\n\t\t\t\tfor(int j=0;j<w;j++){\n\t\t\t\t\tresult.table[i][j]+=table[i][k]*other.table[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t*this=result;\n\t\treturn *this;\n\t}\n};\n"
  code: "#include<vector>\n#include<cassert>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct matrix{\n\tint H,W;\n\tvector<vector<T>> table;\n\tmatrix(int h,int\
    \ w) : H(h),W(w){\n\t\ttable.resize(h,vector<T>(w));\n\t}\n\tint size(){\n\t\t\
    return H;\n\t}\n\tmatrix pow(long long N){\n\t\tassert(H==W);\n\t\tassert(0<=N);\n\
    \t\tmatrix x=*this;\n\t\tmatrix r(H,H);\n\t\tfor(int i=0;i<H;i++){\n\t\t\tr[i][i]=1;\n\
    \t\t}\n\t\twhile(N){\n\t\t\tif(N&1)r*=x;\n\t\t\tx*=x;\n\t\t\tN>>=1;\n\t\t}\n\t\
    \treturn r;\n\t}\n\tvector<T>& operator[](int index){\n\t\tassert(index<H);\n\t\
    \treturn table[index];\n\t}\n\tmatrix& operator+=(const matrix &other){\n\t\t\
    for(int i=0;i<H;i++){\n\t\t\tfor(int j=0;j<W;j++){\n\t\t\t\tif((int)(other.table.size())<=i){\n\
    \t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tif((int)(other.table[i].size())<=j){\n\
    \t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\t(*this)[i][j]+=other.table[i][j];\n\t\t\
    \t}\n\t\t}\n\t\treturn *this;\n\t}\n\tmatrix operator*=(const matrix &other){\n\
    \t\tint h=other.H;\n\t\tint w=other.W;\n\t\tassert(h==W);\n\t\t//\u7D50\u679C\u306F\
    H*w\u884C\u5217\u306B\u306A\u308B\n\t\tmatrix result(H,w);\n\t\tfor(int i=0;i<H;i++){\n\
    \t\t\tfor(int k=0;k<W;k++){\n\t\t\t\tfor(int j=0;j<w;j++){\n\t\t\t\t\tresult.table[i][j]+=table[i][k]*other.table[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t*this=result;\n\t\treturn *this;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy: []
  timestamp: '2024-06-17 08:20:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-matrix/matrix_product.test.cpp
  - verify/verify-yosupo-matrix/pow_of_matrix.test.cpp
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: matrix/matrix.hpp
---
