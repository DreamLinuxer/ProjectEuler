(define (pow x y)
  (define (iter x y result)
    (cond ((= y 0) result)
	  ((even? y) (iter (* x x) (/ y 2) result))
	  (else (iter x (- y 1) (* x result)))))
  (iter x y 1))

(define bound
  ((lambda (x y)
     (define (iter sum prod)
       (if (< sum prod)
	   sum
	   (iter (+ sum x) (* prod y))))
     (iter x y))
   (pow 9 5) 10))

(define (sum-fifth-power n)
  (if (> n 0) (+ (pow (remainder n 10) 5) (sum-fifth-power (quotient n 10))) 0))

(define (sum-all up)
  (define (iter n acc)
    (if (< n up) 
	(if (= n (sum-fifth-power n))
	    (iter (+ n 1) (+ n acc))
	    (iter (+ n 1) acc))
	acc))
  (iter 2 0))

(sum-all bound)
