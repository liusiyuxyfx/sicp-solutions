#lang planet neil/sicp
;a
;若把过程放在定义之前，则由于cond的顺序执行，会先执行过程，则define会被
;判定为一个过程，而不会继续下去进行定义的判定
;b
(define (eval exp env)
        ((call? exp) (apply (eval (operator exp) env)
                            (list-of-values (operands exp) env)))))
(define (call? exp)
  (tagged-list? exp 'call))
(define (operator exp) (cadr exp))
(define (operands exp) (cddr exp))
;call? 可放在assignment之前