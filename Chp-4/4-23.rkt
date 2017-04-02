#lang planet neil/sicp
一个表达式
 origin:
lambda (env) (proc1);
alyssa:
begin (proc1 env);

两个表达式：
origin:
lambda (env) (proc1 proc2);
alyssa:
begin (proc1 env) (proc2 env);
