##Scheme Interpreter
这是一个简单的scheme解释器，用c语言完成，程序入口在main.c。
---
它实现了以下功能：

* (print a) 
* (max)
* (min) 
* (and,or,not)
* (abs) 
* (+, -, *, /)
* (>, <)大于，小于
* (if)
* (let)
* (set)
* (while)
* (clock)

___

本项目编译配置为`gcc -O2 -std=gnu99`

在windows上，我用Jetbrains Clion完成了程序的编写，推荐使用clion进行编译，其支持CMake，这使得其在linux上可直接用cmake进行编译,并且项目中准备了CMakelist。

我最初在linux上完成了本项目，但是由于后来加入了一系列不同类型的指针以及调用关系，导致其在linux上编译出来后无法正确执行，而只能在windows上执行，目前我正在尽快寻找方法解决这一问题。
