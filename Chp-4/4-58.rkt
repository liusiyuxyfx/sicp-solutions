#lang planet neil/sicp
(rule (big-boss ?x)
    (and (job ?x (?parment1 . ?y1))
         (or (not (supervisor ?person1 ?person2))
             (and (supervisor ?person1 ?person2)
                  (job ?person2 (?perment2 . ?y2))
                  (not (same ?parment1 ?perment2))))))