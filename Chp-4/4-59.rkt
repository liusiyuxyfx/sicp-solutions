#lang planet neil/sicp
(meeting ?x (Friday ?y))


(rule (meeting-time ?person ?day-and-time)
      (and (job ?person (?parm1 . ?x))
           (or (meeting whole-company ?day-and-time)
               (meeting ?parm1 ?day-and-time))))


(meeting-timme (Hacker Alyssa P) (Wednesday ?pm))