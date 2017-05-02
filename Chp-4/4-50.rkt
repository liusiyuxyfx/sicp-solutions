#lang planet neil/sicp
(define (ramb? exp) (tagged-list? exp 'ramb))
(define (ramb-choices exp) (cdr exp))
(define (analyze-ramb exp)
  (let ((cprocs (map (analyze (ramb-choices exp)))))
    (lambda (env suceed fail)
      (define (try-net choices)
        (cond ((null? choices) (fail))
              ((= 1 (random 2))
               ((car choices) env
                              succeed
                              (lambda ()
                                 (try-next (cdr chocies)))))
              (else ((cadr choices) env
                                    succeed
                                    (lambda ()
                                      (try-next (append
                                                 (car choices)
                                                 (cddr choices))))))))
      (try-next cprocs))))

                             