#lang sicp
(rule (append-to-form () ?x ?x)
(rule (append-to-form (?u . ?v) ?x (?u . ?z))
      (append-to-form ?v ?x ?z))

(rule (last-pair (?x) (?x)))
(rule (last-pair (?u . ?v) (?x))
      (last-pair ?v (?x)))
