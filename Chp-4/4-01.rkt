;#lang sicp
;left->right
(define (list-of-value1 exps env)
  (let ((left (eval (first-operand exps) env)))
    (if (no-operands? exps)
        '()
        (cons left
              (list-of-value1 (rest-operands exps) env)))))
;right->left
(define (list-of-value2 exps env)
  (let ((right (list-of-value2 (rest-operands exps) env)))
    (if (no-operands? exps)
        '()
        (cons (eval (first-operand epxs) env)
              right))))