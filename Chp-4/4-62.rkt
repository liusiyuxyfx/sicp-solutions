#lang planet neil/sicp
(rule (last-pair (?x ) (?x)))
(rule (last-pair (?v . ?z) (?x))
      (last-pair ?z (?x)))