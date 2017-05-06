#lang planet neil/sicp
(define (if-fail? exp) (tagged-list? exp 'if-fail))
(define (analyze-if-fail exp)
  (let ((pproc (analyze (if-predciate exp)))
        (vproc (analyze (if-consequent exp))))
    (lambda (env succed fail)
      (pproc env
             succeed
             (lambda () (cproc env succeed fail))))))