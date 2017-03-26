#lang planet neil/sicp
;因为在前面的实现里，将let先转化为lambda在进行解释，而lambda会多出一个框架
;因为多出的框架约束于let中的上一层环境，而并不是比其高或者平级，则根据前面查询
;var的流程，没有影响
