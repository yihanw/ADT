#lang racket

;; A Priority Queue ADT in Racket

(provide create-priorityq priorityq-add priorityq-remove 
         priorityq-top priorityq-empty?)

;; (create-priorityq) creates a new priority queue
;; create-priorityq: Void -> PriorityQ

;; (priorityq-add i pri pq) add item i with priority pri to pq
;; priorityq-add: Any Int PriorityQ -> PriorityQ

;; (priorityq-remove pq) removes the item with the largest priority in pq
;; requires: pq is non-empty
;; priorityq-remove: PriorityQ -> PriorityQ

;; (priorityq-top pq) returns the item with the largest priority in pq 
;;   if multiple items have the same largest priority, any can be returned
;; requires: pq is non-empty
;; priorityq-top: PriorityQ -> Any

;; (priorityq-empty? pq) determines if pq is empty
;; priorityq-empty?: PriorityQ -> Bool

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; do not modify the file above this line

;; INTEGRITY STATEMENT (modify if neccessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name
;; Name: Yihan Wang
;; login ID: y2349wan

;; IMPLEMENTATION BELOW

;; see interface above
(struct queue (lst))

;; see interface above
(define (create-priorityq)
  (queue empty))

;; see interface above
(define (priorityq-add i pri pq)
  (define lst (queue-lst pq))
  ;; (sort-lst i pri lst) produces a sorted lst with descending priority order from i pri and lst
  ;; sort-lst: Any Int (listof (list Any Int)) -> (list of (list Any Int))
  (define (sort-lst i pri lst)
    (cond [(empty? lst) (list (list i pri))]
      [(< pri (second (first lst)))
       (cons (first lst) (sort-lst i pri (rest lst)))]
      [else (cons (list i pri) lst)]))
  (queue (sort-lst i pri lst)))

;; see interface above
(define (priorityq-remove pq)
  (queue (rest (queue-lst pq))))
     
;; see interface above
(define (priorityq-top pq)
  (first (first (queue-lst pq))))

;; see interface above
(define (priorityq-empty? pq)
  (empty? (queue-lst pq)))



