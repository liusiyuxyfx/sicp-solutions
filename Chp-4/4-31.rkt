#lang planet neil/sicp

(define (apply procedure arguments env)
  (cond ((primitive-procedure? procedure)
         (apply-primitive-procedure
          procedure
          (list-of-arg-values arguments env))) ; changed
        ((compound-procedure? procedure)
         (eval-extra procedure arguments env))
        (else
         (error
          "Unknown procedure type -- APPLY" procedure))))
(define (eval-sequence exps env)
  (cond ((last-exp? exps) (eval (first-exp exps) env))
        (else (actual-value (first-exp exps) env)
              (eval-sequence (rest-exps exps) env))))
(define (delay? arg) (and (pair? arg) (or (eq? (cadr arg) 'lazy?)
                                          (eq? (cadr arg) 'lazy-memo?))))
(define (get-delay-parameters proc)
  (map (lambda (x) (if (delay? x) (car x) x)) parameters))

(define (eval-extra procedure arguments env)
  (define (list-of-delayed-args paraments args)
    (if (null? formal-args)
        '()
        (cons (if (delay? (car paraments))
                  (delay-it (car args) env)
                  (actual-value (car args) env)))))
  (eval-sequence
   (procedure-body procedure)
   (extend-environment
    (get-delay-parameters (procedure-parameters procedure))
    (list-of-delayed-args (procedure-parameters procedure)
          arguments)
    (procedure-environmet procedure))))