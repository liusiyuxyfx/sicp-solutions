#lang planet neil/sicp
;a
(define (unless->if exp)
  (let ((condition (cadr exp))
        (usual-value (caddr exp))
        (exceptional-value (cadddr exp)))
    (make-if condition  exceptional-value usual-value)))
;b
filter这一过滤过程中即可使用unless这一过程