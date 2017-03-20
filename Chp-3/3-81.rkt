;#lang planet neil/sicp
(define rand-init 100)
(define (rand-update x) (+ x 2))
(define (rand-stream input-stream)
  (define (dispatch s x)
    (let ((me (stream-car s)))
      (cond ((eq? me 'generate)
             (cons-stream x (dispatch (stream-cdr s)
                                      (rand-update x))))
            ((and (pair? me)
                  (eq? (car me) 'reset)
                  (number? (cdr me)))
             (cons-stream (cdr me) (dispatch (stream-cdr s)
                                             (rand-update (cdr me))))))))
  (dispatch rand-init commands))
                  