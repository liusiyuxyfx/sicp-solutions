#lang planet neil/sicp 
(define (subsets s)
  (if (null? s)
      (list nil)
      (let ((rest (subsets (cdr s))))
        (append rest (map (lambda (subtree)
                           (cons (car s)
                                 subtree))
                          rest)))))
(define tree1 (list 1 2 3))
(display (subsets tree1))