#lang racket
(define (simple-flatten proc s)
  (simple-flatten (stream-map proc s)))
(define (simple-faltten stream)
  (stream-map (lambda (s) (stream-car s))
              (stream-filter (lambda (s)
                               (not (stream-null? s)))
                             stream)))
不会