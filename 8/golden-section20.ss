#lang racket
;golden-section20
(define a 3)(define b 4);3.47372
(define (fun x) 
  (set! x (+ x (- (* 13(/ 14)))))

  (+ x ( + (- (*(* 2(sin x))(cos x)))  (- (* 1(/ 2)))))
  )

(define (golden-section-search a b)
 (let(
      (xmin (cond( (< a b)(golden-start a b))(#t (golden-start b a ))))
     )
     (newline)
     xmin
 )
)



(define (golden-start a b)
 (let(
      (xa (+ a (* mphi(+ b (- a)))))
      (xb (+ b (-(* mphi(+ b (- a))))))
     )
     (try a b xa (fun xa) xb (fun xb))
 )
)



(define mphi (* (* 1(/ 2))(+ 3(-(sqrt 5)))))

(define (try a b xa ya xb yb)
  (cond((close-enough? a b)
        (* (+ a b)(/ 2)))
       (#t (let() (display "+")
             (cond((< ya yb)(let() (set! b xb)
                               (set! xb xa)
                               (set! yb ya)
                               (set! xa (+ a (* mphi(+ b (- a)))))
                               (try a b xa (fun xa) xb yb))
                             )
                  (#t (let() (set! a xa)
                        (set! xa xb)
                        (set! ya yb)
                        (set! xb (+ b (-(* mphi(+ b (- a))))))
                        (try a b xa ya xb (fun xb)))
                      )
                  );cond...
             );let...
           )
       );if...
)
 


(define tolerance (* 1 (/ 10000)))
(define (close-enough? x y)
  (<(abs (+ x (- y)))tolerance))




(define xmin 0)
(set! xmin(golden-section-search a b))
  (display"interval=\t[")
  (display a)
  (display" , ")
  (display b)
  (display"]\n")
  (display"xmin=\t\t")
xmin
  (display"f(xmin)=\t")
(fun xmin)
