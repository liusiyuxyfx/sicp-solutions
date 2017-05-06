#lang planet neil/sicp
(rule (replace ?person1 ?person2)
      (and (not (same ?person1 ?person2))
           (job ?person1 ?person1-job)
           (job ?person2 ?person2-job)
           (or (same ?person1-job ?person2-job)
               (can ?person-1 ?person2-job))))


(replace ?x (D.Fect Cy))

(and (replace ?x ?y)
     (salary ?x ?xs)
     (salary ?y ?ys)
     (lisp-value < ?xs ?ys))