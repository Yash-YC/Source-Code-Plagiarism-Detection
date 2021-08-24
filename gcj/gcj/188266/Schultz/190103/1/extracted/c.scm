#lang r6rs

(import (rnrs))

(define MMAX 40)

(define comb
  (let ((C (make-vector (+ MMAX 1))))
    (let loop ((n 0))
      (when (<= n MMAX)
        (let ((X (make-vector (+ n 1))))
          (vector-set! X 0 1)
          (let loop ((k 0))
            (when (< k n)
              (vector-set! X (+ k 1)
                           (/ (* (- n k) (vector-ref X k)) (+ k 1)))
              (loop (+ k 1))))
          (vector-set! C n X))
        (loop (+ n 1))))
    (lambda (n k)
      (vector-ref (vector-ref C n) k))))

(define (answer m n)
  (let ((comb-m-n (comb m n))
        (A (make-vector (+ m 1))))
    (vector-set! A m 0)
    (let loop ((a (- m 1)))
      (when (>= a 0)
        (let ((coef (if (>= a n)
                        (- 1 (/ (comb a n) comb-m-n))
                        1))
              (low (max 1 (- n a)))
              (upper (min (- m a) n)))
          (vector-set! A a (let loop ((x low)
                                      (s 0))
                             (if (> x upper)
                                 (/ (+ 1 (/ s comb-m-n)) coef)
                                 (loop (+ x 1)
                                       (+ s (* (comb a (- n x)) 
					       (comb (- m a) x) 
					       (vector-ref A (+ a x))))))))
          (loop (- a 1)))))
    (vector-ref A 0)))

(define tc (read))

(let loop ((cs 1))
  (when (<= cs tc)
    (let ((m (read))
          (n (read)))
      (map display (list
                    "Case #" cs ": " (real->flonum (answer m n)) #\newline))
      (loop (+ cs 1)))))

(exit)

