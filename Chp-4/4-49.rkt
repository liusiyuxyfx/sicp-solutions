#lang planet neil/sicp
(define (part exp)
  (require (not (null? exp)))
  (amb (car exp)
       (part (car exp))))
(define (parse-word word-list)
  (require (not (null? *unparsed*)))
  (require (memq (car *unparsed*)
                 (cdr word-list)))
  (let ((found-word (car *unparsed*)))
    (set! *unparsed* (cdr *unparsed*))
    (list (car word-list) (part (cdr (word-list))))))