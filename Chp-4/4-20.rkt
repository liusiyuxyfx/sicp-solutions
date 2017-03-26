#lang planet neil/sicp
(define (letrec-vars exp) (cadr exp))
(define (letrec-body exp) (cddr exp))
(define (letrec-init exp)
  (map (lambda (x) (list (car x) '*unassigned*)) (letrec-vars exp)))
(define (letrec->let exp)
  (list 'let
        (letrec-init exp)
        (make-begin (append (map (lambda (x) (list 'set! (car x) (cadr x))) (letrec-vars exp))
                            (letrec-bodt exp)))))