## C++ Template Features

1. 基础模板 (Templates)

| 英文名称	| 中文名称 | RV支持 | 说明 |
|---|---|---|---|
| Function Templates          | 函数模板	     | | 通用函数定义，可接受多种类型参数 |
| Variable Templates (C++14)  |	变量模板 (C++14) | | 可参数化的常量或变量 |

 
2. 模板参数 (Template Parameters)

| 英文名称	| 中文名称 | RV支持 | 说明 |
|---|---|---|---|
| Type Parameters               | 类型参数	    |   | **template<typename T>** 或 **template<class T>** |
| Non-type Parameters           | 非类型参数	|   | 接受值参数（如整型、指针等）： **template<int N>** |
| Template Template Parameters  | 模板模板参数	|   | 参数本身是模板： **template<template<typename> class Container>** |
| Default Template Arguments    | 默认模板参数	|   | 为模板参数指定默认值： **template<typename T = int>** |


- Class Templates (类模板)
  - 类模板特化
  - 嵌套参数化
  - 成员方法参数化

- 编译期分支 (if constexpr)


