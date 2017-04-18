#lang swindle

(define not-word '(not not))
(define verbs '(verb is eat eats kills beats kill beat))
(define nouns '(nounce smart pig wolf snake enemy animal lazy dumb))
(define judges '(judge good bad))
(define articles '(article a the an))

(define (require p)
  (if (not p) (amb)))

;sentence = first-phrase + verbs + second-phrase
;nouns-phrase = article + noun
;verb-phrase = verb + nouns-phrase
;judge-phrase = not-word + judges
;
;there are 4 options for a sentence:
;1.nouns-phrase + verbs + nouns-phrase
;2.nouns-phrase + verbs + judge-phrase
;3.nouns-phrase + verbs + nouns-phrase
;4.verb-phrase + verbs + judge-phrase


;;top-level
(define (parse-sentence)
  (list 'sentence
         (parse-first-phrase)
         (parse-verbs-phrase)
         (parse-second-phrase)))
;;second-level
(define (parse-second-phrase)
  (list 'second-phrase
        (parse-nouns-phrase)
        (parse-judge-phrase)))

(define (parse-first-phrase)
  (list 'first-phrase
        (parse-word verbs)
        (parse-nouns-phrase)))
;;third-level
(define (parse-nouns-phrase)
  (list 'nouns-phrase
        (parse-word articles)
        (parse-word nouns)))

(define (parse-verbs-phrase)
  (list 'verbs-phrase
        (parse-word verbs)
        (parse-word bes)))

(define (parse-judge-phrase)
  (list 'judge-phrase
        (parse-word not-word)
        (parse-word judges)))

(define (parse-word word-list)
  (require (not (null? *unparsed*)))
  (require (memq (car *unparsed*) (cdr word-list)))
  (let ((found-word (car *unparsed*)))
    (set! *unparsed* (cdr *unparsed*))
    (list (car word-list) found-word)))

(define *unparsed* '())

(define (parse input)
  (set! *unparsed* input)
  (let ((sent (parse-sentence)))
    (require (null? *unparsed*))
    sent))


