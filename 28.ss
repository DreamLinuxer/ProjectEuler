(define (corner n)
  (if (= n 0) 1
      (let ((m (+ 1 (* 2 n))))
	(- (* 4 m m) (* 12 n)))))

(define (sum n)
  (if (= n 0) (corner n)
      (+ (corner n) (sum (- n 1)))))

(sum 500)
