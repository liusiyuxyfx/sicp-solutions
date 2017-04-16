#lang planet neil/sicp
;因为对于一个没有上届的try，只会不断的更新最内层的k，而外层的i和j并不会变换

(define (a-pythagorean-triple-starting-from low)
  (let ((k (an-integer-starting-from low)))
    (let ((i (an-integer-between 1 k)))
      (let ((j (an-integer-between i k)))
        (require (= (+ (* i i) (* j j) (* k k))))
        (list i j k)))))

