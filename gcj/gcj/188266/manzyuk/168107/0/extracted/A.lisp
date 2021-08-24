(defun sum-of-sqs-of-digits (n base)
  (loop for q = n then (floor q base)
        for r = (mod q base)
        sum (* r r)
        until (= q 0)))

(memoize 'sum-of-sqs-of-digits :key #'identity :test #'equal)

(defun perfect-p (n base)
  (do ((k n (sum-of-sqs-of-digits k base))
       (l nil (cons k l)))
      ((member k l) (= k 1))))

(memoize 'perfect-p :key #'identity :test #'equal)

(defun perfect-wrt-bases-p (n bases)
  (every #'(lambda (base)
             (perfect-p n base))
         bases))

(defun min-perfect-wrt-bases (bases)
  (loop for n from 2
        if (perfect-wrt-bases-p n bases)
        do (return n)))

(defun solve (file1 file2)
  (with-interaction (in file1) (out file2)
    (let ((cases (parse-integer (read-line in))))
      (loop for case from 1 to cases do
            (format out "~&Case #~d: ~d"
                    case
                    (min-perfect-wrt-bases (read-as-list (read-line in))))))))