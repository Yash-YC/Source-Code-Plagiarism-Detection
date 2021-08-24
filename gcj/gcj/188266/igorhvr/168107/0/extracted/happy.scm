;;; Igor Hjelmstrom Vinhas Ribeiro <igorhvr@iasylum.net>
;; Run command below to execute (fix the directory to where this file is):
;(load "/home/igorhvr/idm/gcj/2009/round1a/happy/happy.scm")

;; To use this you need the sisc 1.16.6 from http://sisc-scheme.org/ and the Bedlam library
;; at http://github.com/igorhvr/bedlam/tree/master (version v00000003)

;; IMPORTANT - you need to make iasylum-bedlam-location below point to the place where you put the bedlam library. Example:
(begin (define iasylum-bedlam-location "/home/igorhvr/idm/bedlam/") (load (string-append iasylum-bedlam-location "iasylum/init.scm")))

(define (^2 n) (expt n 2))

(define (get-digits number base)
  (let* ((max-potency (inexact->exact (ceiling (/ (log number) (log base))))))
    (let loop ((c max-potency) (remaining number))
       (let ((pot (expt base c)))
         (let ((numeric-digit (inexact->exact (floor (/ remaining pot)))))
           (if (> c 0)
               (let ((remaining-result (loop (- c 1) (modulo remaining pot))))
                 (if (or (< c max-potency) (not (= numeric-digit  0)))
                       (cons numeric-digit remaining-result)
                       remaining-result))
               (list numeric-digit)))))))

(define (is-happy number base)
  (let ((already-taken (make-hashtable)))
    (let loop ((n number))
      (cond ((= n 1) #t)
            ((hashtable/get already-taken n) #f)
            (else
             (hashtable/put! already-taken n #t)
             (loop (fold + 0 (map ^2 (get-digits n base)))))))))

(define (smallest-happy base-list)
  (call/cc
   (lambda (k)
     (let loop ((n 2))
       (if (every (cute is-happy n <>) base-list)
           (k n)
           (loop (+ n 1)))))))

(define (read-line . port)
  (let* ((char (apply read-char port)))
    (if (eof-object? char)
        char
        (do ((char char (apply read-char port))
             (clist '() (cons char clist)))
            ((or (eof-object? char) (char=? #\newline char))
             (list->string (reverse clist)))))))

(define (parse-pattern s)
  (define process
    (lambda  (from-index tmatch seed)
      (let ((abase (irregex-match-substring tmatch 'abase)))
        (cons (string->number abase) seed))))
  (let ((exp '(: (* whitespace) (=> abase (+ digit) ) (* whitespace))))
    (reverse (irregex-fold exp  process '()  s))))

(dp n 1)
(define next-number
  (lambda ()
    (let ((return-value (n)))
        (n (+ (n) 1))
        return-value)))


(define (pfile fn)
  (let* ((src (open-input-file fn))
         (test-cases (read src)))
    (read-line src) ;empty line
    
    (for-each
     (lambda (ignored)
       (let* ((test-case-string (read-line src))
              (base-list (parse-pattern test-case-string)))
         (let ((result (smallest-happy base-list)))
           (d "\nCase #" (next-number) ": " result)
           )))
     (iota test-cases))))
           
(pfile "A-small-attempt0.in")
