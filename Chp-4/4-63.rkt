#lang planet neil/sicp
(rule (grandson ?persong ?persons)
      (and (son ?personf ?persons)
           (son ?persong ?personf)))
(rule (son ?personm ?persons)
      (and (wife ?personm ?personw)
           (son ?personw ?persons)))