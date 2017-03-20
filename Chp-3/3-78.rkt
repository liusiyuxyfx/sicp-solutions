#lang planet neil/sicp
(define (solve-2nd a b dt y y0 dy0)
  (define y (integral (delay dy) y0 dt))
  (define dy (integral (delay ddy) dyo dt))
  (define ddy (add-streams (scale-stream dy a) (scale-stream y b)))
  y)
