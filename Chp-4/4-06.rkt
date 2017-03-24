#lang planet neil/sicp
(define (let? exp) (tagged-list? exp 'let))
(define (let-vars exp) (map car (cadr exp)))
(define (let-exps exp) (map cadr (cadr exp)))
(define (let*-body exp) (caddr exp))
(define (let->combination exp)
  (list (make-lambda (let-vars exp) (let-bodt exp) (let-exps exp))))


;;;;;;;;;;;;;;;eval子句
(define (eval exp env)
  ((let? exp) (eval (let->combination exp) env)))