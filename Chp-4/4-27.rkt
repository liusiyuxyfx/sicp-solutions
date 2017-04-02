#lang planet neil/sicp
因为w是个符合过程，所以由惰性求值原则，这里并不对（id （id 10））进行运算，
所以第一个输出值是0，而当调用w时，输出10，此时count为2