#lang planet neil/sicp
(define (let*? exp) (tagged-list? exp 'let*))
(define (let*-body exp) (caddr exp))
(define (let*-vars exp) (map car (cadr exp)))
(define (let*-exps exp) (map cadr (cadr exp)))
(define (make-lets vars exps body)
  (if (null? exps)
      body
      (list 'let
            (list (car vars) (car exps))
            (make-lets (cdr vars) (cdr exps)))))
(define (let*->nested-lets exp)
  (make-lets (let*-vars exp) (let*-exps exp) (let*-body exp)))