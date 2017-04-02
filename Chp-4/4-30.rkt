a:
因为display是基本过程，对于任何基本过程，都将调用actual-value，而begin对
每个表达式都进行eval调用，所以可以
b:
origin version:
(p1 1)：　(1 , 2)
(p2 1):   1

Cy version:
(p1 1): (1, 2)
(p2 1): (1, 2)
c:
因为force-it对不是槽的obj会直接返回，所以当直接force一个数时，会直接返回，没有影响
D:
cy的
 