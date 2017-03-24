#lang planet neil/sicp
;for (i = 1; i < n; ++i) {
;body};
; ||
;\||/
; \/
;(for (i 1 (< i n) (+ i 1)) body)
;    ||       |       |
;   \||/      |       |
;    \/      end?     update
(define (end? proc i n)
  (if (proc i n) false
      true))
(define (update proc i k)
  (set! i (proc i k)))
(define (for var init end update body)
  (define (iter cur last)
    (if (not end?
(define (for? exp) (tagged-list? exp 'for))
(define (for-var) (car (cadr exp)))
(define (for-init) (cadr (cadr exp)))
(define (for-end) (caddr (cadr exp)))
(define (for-update) (cadddr (cadr exp)))
(define (for-body) (caddr exp))
(define (for->combination exp)
  (