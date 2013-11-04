(define (is-prime? n)
  (define (iter i)
	(if (> (* i i) n) #t
	  (if (= 0 (remainder n i)) #f (iter (+ i 1)))))
  (if (> n 1) (iter 2) #f))

(define (formula n a b)
  (+ (* n n) (* a n) b))

(define (seq-length a b)
  (define (iter i len)
	(if (is-prime? (formula i a b)) (iter (+ i 1) (+ len 1)) len))
  (iter 0 0))

(define (find bound)
  (define (iter a b aa bb len)
;	(display a)(display " ")(display b)(display "\n")
	(cond ((> b bound) (iter (+ a 1) 2 aa bb len))
		  ((> a bound) (list aa bb len (* aa bb)))
		  ((and (> (+ a b) 0) (even? (+ a b)) (is-prime? b))
		   (let ((l (seq-length a b)))
			 (if (> l len)
			   (iter a (+ b 1) a b l)
			   (iter a (+ b 1) aa bb len))))
		  (else (iter a (+ b 1) aa bb len))))
  (iter (- bound) 2 0 0 0))

(find 1000)
