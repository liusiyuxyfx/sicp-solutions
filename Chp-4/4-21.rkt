#lang planet neil/sicp
((lambda (n)
       ((lambda (fib)
          (fib fib 1 0 n))
        (lambda (fib pre nex cnt)
          (if (= cnt 0)
              nex
              (fib fib (+ pre nex) pre (- cnt 1 ))))))
 10)

(define (f x)
  ((lambda (even? odd?)
     (even? even? odd? x))
   (lambda (ev? od? n)
     (if (= n 0) true (od? ev? od? (- n 1))))
   (lambda (ev? od? n)
     (if (= n 0) false (ev? ev? od? (- n 1))))))