;; Google Code Jam Round 1A Problem A
;; Elliott Slaughter
;; Common Lisp, run in SBCL

(defun digits (n r)
  (loop for c across (format nil (format nil "~~~ar" r) n)
     collect (- (char-code c) (char-code #\0))))

(defconstant +max-base+ 10)
(defconstant +max-num+ 1000000)

(defparameter *happy-memo* (make-array (list (1+ +max-base+) (1+ +max-num+))
                                       :initial-element 'unknown))

(defun happy (n r)
  (cond ((= n 1) t)
        ((and (<= n +max-num+) (eql (aref *happy-memo* r n) t)) t)
        ((and (<= n +max-num+) (eql (aref *happy-memo* r n) nil)) nil)
        (t
         (and (<= n +max-num+) (setf (aref *happy-memo* r n) nil))
         (when
             (happy (apply #'+ (mapcar #'(lambda (x) (* x x)) (digits n r))) r)
           (and (<= n +max-num+) (setf (aref *happy-memo* r n) t))
           t))))

(defun least-happy (rs)
  (loop for i = 2 then (1+ i)
     until (reduce #'(lambda (a b) (and a b))
                   (mapcar #'(lambda (r) (happy i r)) rs))
     finally (return i)))

(defun parse-numbers (line)
  (with-input-from-string (s line)
    (loop for n = (read s nil) then (read s nil) while n collect n)))

(defun main ()
  (loop for i from 1 to (read)
     do (format t "Case #~a: ~a~%"
                i (least-happy (parse-numbers (read-line))))))

(main)