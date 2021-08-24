(define seen (make-table init: #f))

(define (seen? n base)
  (table-ref seen (cons n base)))

(define (seen! n base)
  (table-set! seen (cons n base) #t))

(define (memoize f)
  (let ((t (make-table init: #f)))
    (lambda args
      (if (table-ref t args)
	  (car (table-ref t args))
	  (let ((result (apply f args)))
	    (table-set! t args (cons result #t))
	    result)))))

(define (happy? n base)
  (set! seen (make-table init: #f))
  (happy-in n base))

(define happy-in (memoize 
		  (lambda (n base)
		    (or (= 1 n)
			(if (seen? n base)
			    #f
			    (begin (seen! n base)
				   (happy-in (sum-sq n base) base)))))))

(define (square n)
  (* n n))

(define (sum-sq n base)
  (if (zero? n)
      0
      (+ (square (modulo n base))
	 (sum-sq (floor (/ n base)) base))))

(define (every f l)
  (or (null? l)
      (and (f (car l))
	   (every f (cdr l)))))

(define (happy-in-all bases)
  (let loop ((n 2))
					;    (display (list n "\n"))
    (if (every (lambda (base)
		 (happy? n base))
	       bases)
	n
	(loop (+ n 1)))))

(define (code-jam cases input process output)
  (do ((i 1 (+ i 1)))
      ((> i cases))
    (display-each (list "Case #" i ": " (output (process (input))) "\n"))))

(define (display-each l)
  (if (not (null? l))
      (begin (display (car l))
             (display-each (cdr l)))))

(with-output-to-file "~/A-small-attempt2.out"
  (lambda ()
    (with-input-from-file "~/A-small-attempt2.in"
      (lambda ()  
	(code-jam (let ((res (read))) (read-line) res)
		  (lambda ()
		    (with-input-from-string (read-line)
		      (lambda ()
		      (read-all))))
		  happy-in-all
		  values)))))
