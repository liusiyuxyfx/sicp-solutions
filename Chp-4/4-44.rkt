#lang swindle
(define (an-element-of items)
  (require (not (null? items)))
  (amb (car items) 
       (an-element-of (cdr items))))
       
(define (require p)
  (if (not p) (amb)))
(define (distinct? items)
  (cond ((null? items) true)
        ((null? (cdr items)) true)
        ((member (car items) (cdr items)) false)
(else (distinct? (cdr items)))))

(define row (list 1 2 3 4 5 6 7 8))
(define col (list 1 2 3 4 5 6 7 8))
(define (row-col row col)
  (define (loop row col)
  (let ((first-row (car row))
        (rest-row (cdr row))
        (first-col (car col))
        (rest-col (cdr row)))
    (cond ((null? row) '())
          ((null? col) (loop (rest-row) (rest-col)))
          (else (list (cons first-row first-col)
                      (loop row (rest-col)))))))
  (loop row col))
(define row-cols (amb (row-col row col)))
         
(define (eight-queens)
  (let ((q1 row-cols)
        (q2 row-cols)
        (q3 row-cols)
        (q4 row-cols)
        (q5 row-cols)
        (q6 row-cols)
        (q7 row-cols)
        (q8 row-cols))
    (require (distinct? (car q1) (car q2) (car q3) (car q4) (car q5) (car q6)
                        (car q7) (car q8)))
    (require (distinct? (cdr q1) (cdr q2) (cdr q3) (cdr q4) (cdr q5) (cdr q6)
                        (cdr q7) (cdr q8)))
    (list ('q1 q1)
          ('q2 q2)
          ('q3 q3)
          ('q4 q4)
          ('q5 q5)
          ('q6 q6)
          ('q7 q7)
          ('q8 q8))))