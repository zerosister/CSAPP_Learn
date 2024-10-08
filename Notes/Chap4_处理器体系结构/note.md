# 4.3 Y86-64 顺序实现
书中使用微指令寄存器或中间值
```
> ALU
  > 输入
    > 输入A valA  // 同时也为寄存器输出 a/b
    > 输入B valB
  > 输出 valE
> 指令内存
  > icode:ifun 第一个字节,表明类型与功能
  > rA:rB      需要访问的寄存器
  > valC       call,jxx 等指令的 Dest
  > valP       PC 自增后值，如 rrmovq 指令为 PC + 2       
> valM 数据内存输出
```
# 4.4 流水线通用原理
## 4.4.1 ~ 4.4.2
概念 & 计算：
> 吞吐量：单位时间内执行指令总数

p283

> 延迟：从头到尾执行一条指令 *组合逻辑延迟 + 寄存器延迟（全部加一块）*

p285 直到时钟上升沿到来，才会改变寄存器的输出（时钟上升沿触发）

## 4.4.3 流水线局限性
当组合逻辑的延迟不同时（如：取值和 ALU 时延不同），流水线周期选择 __最慢者__。

## 4.4.4 带反馈流水线系统
why 反馈路径？
1. 数据相关
2. 控制相关
实现：检查指令要访问的寄存器
# Y86-64 流水线实现
### 暂停避免数据冒险
> __bubble__ 暂停为将取指，译码阶段停滞住，即下一个周期其寄存器的值不变。
  区别 nop，nop 为指令正常流动

必须要使用 `bubble` 的情况：__Load/Use__
```s
# load use 冒险实例
mrmovq 0(%rdx),%rax
bubble              # 解决方案为此处插一个 bubble
addq %ebx,%eax 
```
### 避免控制冒险
1. __ret__
由于 `ret` 需要对于内存进行访问，需要等到写回阶段后（指令执行完毕）再进行译码阶段，故插入 3 个 bubble 在 `ret` 指令后

参见 p305