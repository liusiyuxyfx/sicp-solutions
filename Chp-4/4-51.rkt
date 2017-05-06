#lang planet neil/sicp
(define (permanent-set!? exp)
  (tagged-list? exp 'permanent-set!))
(define (analyze-permanent exp)
  (let ((var (assignment-variable exp))
        (vproc (analyze (assignment-value exp))))
    (lambda (env succeed fail)
      (vproc env
             (lambda (val fail2)
               (let ((old-value (lookup-variable-value var env)))
                 (set-variable-value! var val env)
                 (succeed 'ok fail2)))
             fail))))
                 