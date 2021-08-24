#! /usr/bin/gosh

(use srfi-13)

(define (num-to-list n base)
  (let ((q (quotient n base))
	(r (remainder n base)))
    (if (= 0 q)
	(list r)
	(cons r (num-to-list q base)))))

(define (step n base)
  (apply + (map (lambda (x) (* x x)) (num-to-list n base))))

(define (is-happy-inner n base original pol)
  (or (= n 1)
      (let ((next (step n base)))
	(and (not (= next original))
	     (is-happy-inner next base 
			     (if (> pol 0) (step original base) original)
			     (* -1 pol))))))

(define (is-happy n base)
  (is-happy-inner n base n -1))

(define (is-happy-for-all n bases)
  (if (null? bases) #t
      (let ((hd (car bases))
	    (tl (cdr bases))
	    )
	(and (is-happy n hd)
	     (is-happy-for-all n tl)))))

(define (solve-line)
  (let* ((str (read-line))
	 (problem (read-from-string (string-concatenate (list "(" str ")"))))
	)
    (search-happy 2 problem)))

(define (search-happy n bases)
  (if (is-happy-for-all n bases)
      n
      (search-happy (+ n 1) bases)))
    

(define T (read))
(read-line)
(define t 1)

(define (go)
  (if (< T t) ()
      (begin
	(print (format "Case #~d: ~d" t (solve-line)))
	(set! t (+ t 1))
	(go))))

(go)