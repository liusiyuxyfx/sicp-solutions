#lang planet neil/sicp
(define (cond? exp) (tagged-list? exp 'cond))
(define (cond-clauses exp) (cdr exp))
(define (cond-else-clauses? clause)
  (eq? (cond-predicate clause) 'else))
(deifne (cond-predicate clause) (car clause))
(define (cond-actions clause) (cdr clause))
(define (cond->if exp)
  (expand-clauses (cond-clause exp)))
;;;;;;;;;;ans;;;;;;;;;;;;;;;;;;;;;;
(define (another-cond? clause) (eq? (cadr clause) '=>))
(define (another-cond-test clause) (car clause))
(define (another-cond-recipient clause) (caddr clause)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (expand-clauses clauses)
  (if (null? clauses)
      'false
      (let ((first (car clauses))
            (rest (cdr clauses)))
        (if (cond-else-clause? first)
            (if (null? rest)
                (sequence->exp (cond-actions first))
                (erro "ELSE clause isn't last -- COND->IF"
                      clauses))
            (if (another-cond? clause)
                (make-if another-cond-test
                         (list another-cond-recipient another-cond-test)
                         (expand-clauses rest))
                (make-if (cond-predicate first)
                     (sequence->exp (cond-actions first))
                     (expand-clauses rest)))))))