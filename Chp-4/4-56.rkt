#lang planet neil/sicp
(and (supervisor ?x (Bitdiddle Ben))
     (address ?x ?where))

(and (salary (Bitdiddle Ben) ?amounta)
     (salary ?name ?amountb)
     (lisp-value > ?amounta ?amountb))

(and (job ?name-b (computer . ?y))
     (not (supervisor ?name-a ?name-b))
     (supervisor ?name-a ?name-c)
     (job ?name-c ?job-c))