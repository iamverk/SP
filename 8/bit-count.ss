#lang racket
;(define(even-bits n)
;  (cond((= n 0)1)
;       ((=(remainder n 2)0)
;          (even-bits (quotient n 2)))
;       (#t(odd-bits(quotient n 2)))
;  )
;  )


(define (even-bits n)
  (cond ( (= n 0) 1)
    (#t (cond
      ((=(remainder n 2) 0) (even-bits (quotient n 2)))
      ( #t (odd-bits(quotient n 2)))
 )
 )
 )
)
 ;(cond(x? 1 2)(y? 3 4)(else 5 6)) ~ 
    ; (cond(x?(let()1 2)) (#t(cond(y?(let()3 4)) (#t(let()5 6))))



(define (odd-bits n)
  (cond ( (= n 0) 0)
    (#t (cond
      ((=(remainder n 2) 0) (odd-bits (quotient n 2)))
      ( #t (even-bits(quotient n 2)))
 )
 )
 )
)



(define(bit-count n)
  (cond ((= n 0) 0)
        (#t (+ (remainder n 2)(bit-count (quotient n 2))))
    )
)



(define(report-results n)
  (display "Happy birthday to you!\n\t")
  (display n)(newline)
  (display "\teven?\t")(display (if(=(even-bits n)1) "yes" "no"))
  (newline)
  (display "\todd?\t")(display (if(=(odd-bits n)1) "yes" "no"))
  (newline)
  (display "bit-count = ")
  (bit-count n)
) 
;***** Date of YOUR birthday *******
(define dd 30)
(define mm 09)
(define yyyy 2020)
;***********************************
(report-results (+ (* dd 1000000)
                   (* mm 10000)
                   yyyy))
