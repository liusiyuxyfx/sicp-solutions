#lang planet neil/sicp
#lang planet neil/sicp
(define (name-let? exp) (and (let? exp) (symbol? (cadr exp))))
(define (name-let-proc exp) (cadr exp))
(define (name-let-vars exp) (map car (caddr exp)))
(define (name-let-exps exp) (map cadr (caddr exp)))
(define (name-let-body exp) (cadddr expr))


(define (name-let->proc exp)
  (let ((proc (name-let-proc exp))
        (vars (name-let-vars exp))
        (exps (name-let-exps exp))
        (body (name-let-body body)))
    (list 'define
          (cons proc vars)
          body)))

(define (let->combination exp)
  (if (nam-let? exp)
      (sequence->exp
         (let ((proc (name-let-proc exp))
               (vars (name-let-vars exp))
               (exps (name-let-exps exp))
               (body (name-let-body body)))
           (list (name-let-proc exp)
                 (cons proc exps))))))