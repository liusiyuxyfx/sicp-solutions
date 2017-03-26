#lang planet neil/sicp
(define (make-unbound! var env)
  (define (scan frame)
    (cond ((null? frame) (error "No such var"))
          ((eq? var (car (car frame)))
           (set! frame (cdr frame)))
          (else (scan cdr frame))))
  (scan (first-frame env)))
;没有必要删除外围环境的约束