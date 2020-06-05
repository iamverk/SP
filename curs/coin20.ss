#lang racket
;bit-count
(define variant 13)
(define last-digit-of-group-number 6)
(define kinds-of-coins 6)
(define(NOT? x?)(= 0(cond (x? 1) (#t 0))))
          

(define (implication? x? y?)
  (or (NOT? x?) y?)
  )



  

(define (cc amount kinds-of-coins)
(cond
((= amount 0) 1)
(#t (cond ((implication? (< 0 amount) (= kinds-of-coins 0)) 0)
(#t (+ (cc amount (+ kinds-of-coins -1))
(cc (+ amount (- (first-denomination kinds-of-coins))) kinds-of-coins)))
)
)
)
) 

 



(define (count-change amount kinds-of-coins)
   (display "count-change for ")
   (display amount)
   (display " ")
   (display kinds-of-coins)
   (display " \t= ")
  (cond ((< 0 amount) (cond ((< 0 kinds-of-coins)
                            (cond((< 0 (first-denomination kinds-of-coins)) (cc amount kinds-of-coins))
                            (#t (let() (display "(improper parameter value) ") 0)))
                            )
                            (#t (let() (display "(improper parameter value) ") 0))))
                            (#t (let() (display "(improper parameter value) ") 0))
                            )
       
)


          
  
  

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        (#t (cond((= kinds-of-coins 2) 2)
        (#t (cond((= kinds-of-coins 3) 3)
        (#t (cond((= kinds-of-coins 4) 5)
        (#t (cond((= kinds-of-coins 5) 10)
        (#t (cond((= kinds-of-coins 6)20)
        (#t 0)
        )
  )))))))))))



(define (gr-amount)
  (remainder (+ (* 100 last-digit-of-group-number) variant) 137)
  )
  

(display "MVM variant ")
variant
(newline)
(display "1-2-3-5-10-20")
(newline)
(count-change 100 kinds-of-coins)
(newline)
(count-change (gr-amount) kinds-of-coins)
(newline)
(count-change 100 100)
(newline)