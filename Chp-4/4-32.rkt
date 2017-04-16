#lang planet neil/sicp
多出来的惰性在于序对的car 也被delay
只有cdr被delay时可以构造出流，那么当car和cdr都被delay时，即可构造出一棵惰性的树
(define (tree)
  (define tree-leaves (cons tree tree))
  (cons tree-leaves tree-leavs))

