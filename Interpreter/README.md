<h1>Scheme Interpreter<h1>  

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
**使用方法**  
解释器采用repl方式，当用户输入(quit)时，程序停止
___
****编译****
* windows下
  windows下可使用Jetbrain Clion进行编译  
* linux和mac下
  项目中配置了makefile，所以可以直接在项目根目录下执行命令`make`即可。