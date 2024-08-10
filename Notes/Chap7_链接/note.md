# 7.1 编译器驱动程序
过程
使用 `-save-temps` 选项
1. `cpp main.c /tmp/main.i` 预处理器 cpp 输出 .i 文件
2. `ccl /tmp/main.i -o /tmp/main.x`   编译器 ccl 编译为汇编文件
3. `as -o /tmp/main.o /tmp/main.s`  汇编器 as 翻译为 __可重定位目标文件__ main.o
4. `ld -o prog /tmp/main.o /tmp/sum.o`  链接器 ld 创建可执行文件 prog
5. `./prog` shell 调用操作系统加载器 `loader` 函数，将 prog 的代码和数据复制到内存，PC 跳转至 prog 开头

# 7.3 目标文件
三种形式：
1. __可重定位目标文件__
2. __可执行目标文件__
3. __共享目标文件__
x86-64 Linux Unix 使用可执行可链接格式 __ELF (Executable & Linable Format)__
```
> ELF 头
  > .text       已编译程序机器码
  > .rodata     只读数据 eg. const char[]
  > .data       已初始化全局&静态 C 变量（包括在外部定义的全局变量）
  > .bss        未初始化 or 初始化为 0 全局&静态变量
  > .symtab     符号表
    > 模块 m 定义并被其他模块引用的全局符号——非静态的（C函数 & 全局变量）
    > 其他模块定义并被 m 引用的全局符号——其他模块的非静态（C函数 & 全局变量） extern?
    > 只被 m 定义与引用的局部符号——static （C函数 & 全局变量）
  > .rel.text
  > .rel.data
  > .debug
  > .line
  > .strtab
```
C 中 static 作用 -> file1.c file2.c，既用来保证数据持久性（多次访问某函数，不会重新初始化），又用来保证数据的当前文件独有性

**编译器两大任务**
* 符号解析
* 重定位

### 7.6 符号解析
**强弱符号规则**
1. 不允许强符号同名
2. 一个强符号与多个弱符号同名，选择强符号
3. 多个弱符号同名，从中随机挑选一个
### 7.7 重定位