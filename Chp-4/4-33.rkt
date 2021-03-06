#lang planet neil/sicp
(define (quoted? exp) (tagged-list? exp 'quote))
(define (text-of-quotation exp env)
  (define (make-list text)
    (if (null? text)
        '()
        (list 'cons (list 'quote (car text))
                    (make-list (cdr text)))))
  (let ((result (cadr exp)))
    (if (pair? result)
        (eval-lazy (make-list result) env)
        result)))
