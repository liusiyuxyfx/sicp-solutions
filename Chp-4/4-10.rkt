#lang planet neil/sicp
;ex:(set! i 1)=(i set! 1)
(define (assignment? exp)
  (eq? (cadr exp) 'set!))
(define (assignment-variable exp) (car exp))
(define (assignment-value exp) (caddr exp))
