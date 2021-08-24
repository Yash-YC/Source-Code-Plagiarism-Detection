(in-package :utils)

;;;; Queues

;;; A queue is a (last . contents) pair

(proclaim '(inline queue-contents make-queue enqueue dequeue
                   front empty-queue-p queue-nconc))

(defun make-queue ()
  "Build a new queue, with no elements."
  (let ((q (cons nil nil)))
    (setf (car q) q)))

(defun queue-contents (q) (cdr q))

(defun empty-queue-p (q) (null (queue-contents q)))

(defun enqueue (item q)
  "Insert item at the rear of the queue."
  (setf (car q)
        (setf (rest (car q))
              (cons item nil)))
  q)

(defun dequeue (q)
  "Remove an item from the front of the queue."
  (assert (not (empty-queue-p q))
          ()
          "Cannot dequeue from the empty queue.")
  (pop (cdr q))
  (if (null (cdr q)) (setf (car q) q))
  q)

(defun front (q)
  "Return the front element of the queue."
  (assert (not (empty-queue-p q))
          ()
          "The queue is empty.")
  (cadr q))

(defun rear (q)
  "Return the rear element of the queue."
  (assert (not (empty-queue-p q))
          ()
          "The queue is empty.")
  (caar q))

(defun clear-queue (q)
  "Remove all items from the queue."
  (setf (cdr q) nil
        (car q) q))

(defun queue-nconc (q list)
  "Add the elements of LIST to the end of the queue."
  (setf (car q)
        (last (setf (rest (car q)) list))))

;;;; Memoization

(defun memo (fn name key test)
  "Return a memo-function of fn."
  (let ((table (make-hash-table :test test)))
    (setf (get name 'memo) table)
    #'(lambda (&rest args)
        (let ((k (funcall key args)))
          (multiple-value-bind (val found-p) (gethash k table)
            (if found-p val
                (setf (gethash k table) (apply fn args))))))))

(defun memoize (fn-name &key (key #'first) (test #'eql))
  "Replace FN-NAME's global definition with a memoized version."
  (setf (symbol-function fn-name)
        (memo (symbol-function fn-name) fn-name key test)))

(defun clear-memoize (fn-name)
  "Clear the hash table from a memo function."
  (let ((table (get fn-name 'memo)))
    (when table (clrhash table))))

;;;; Operations on sequences

(proclaim '(inline last1 single append1 conc1))

(defun last1 (list)
  "Return the last element (not cons cell) of LIST."
  (first (last list)))

(defun single (x)
  "Is X a list of one element?"
  (and (consp x) (null (rest x))))

(defun append1 (list item)
  "Append ITEM to the end of LIST."
  (append list (list item)))

(defun nconc1 (list item)
  "Destructively append ITEM to the end of LIST."
  (nconc list (list item)))

(defun group-if (test list &key (key #'identity))
  "Split list into a LIST of lists of adjacent elements satisfying TEST.
  Example: (group-if #'eql '(a a a b b c)) => ((a a a) (b b) (c))
           (group-if #'< '(1 2 3 2 1 4 5) => ((1 2 3) (2) (1 4 5))."
  (if (null list)
      nil
      (let ((so-far (list (first list)))
            (result nil))
        (dolist (item (rest list))
          (cond ((funcall test (funcall key (first so-far))
                               (funcall key item))
                 (push item so-far))
                (t (push (nreverse so-far) result)
                   (setf so-far (list item)))))
        (nreverse (cons (nreverse so-far) result)))))

(defun group-by (n list)
  "Group the elements of list into sublists of length N, 
  putting the remainder in the final sublist. Returns a list."
  (assert (plusp n) (n)
          "The first argument to GROUP-BY must be a positive integer.")
  (labels ((rec (src acc)
             (let ((rest (nthcdr n src)))
               (if (consp rest)
                   (rec rest (cons (subseq src 0 n) acc))
                   (nreverse (cons src acc))))))
    (if list (rec list nil) nil)))

(defun split-if (predicate sequence &key (key #'identity))
  "Split SEQUENCE at elements satisying PREDICATE. 
  Returns a list of subsequences."
  (labels ((vector-split-if (predicate vector key)
             (let ((p1 (position-if-not predicate vector :key key)))
               (if p1
                   (let ((p2 (position-if predicate vector
                                          :start p1 :key key)))
                     (cons (subseq vector p1 p2)
                           (if p2
                               (split-if predicate (subseq vector p2)
                                         :key key)
                               nil)))
                   nil)))
           (list-split-if (predicate list key)
             (let ((result nil)
                   (so-far nil))
               (dolist (item list)
                 (cond ((funcall predicate (funcall key item))
                        (when so-far
                          (push (nreverse so-far) result))
                        (setf so-far nil))
                       (t (push item so-far))))
               (when so-far
                 (push (nreverse so-far) result))
               (nreverse result))))
    (etypecase sequence
      (vector (vector-split-if predicate sequence key))
      (list   (list-split-if   predicate sequence key)))))

(defun split-at (delimiter sequence &key (key #'identity) (test #'eql))
  "Split SEQUENCE at DELIMITER. Returns a list of subsequences."
  (split-if #'(lambda (item)
                (funcall test item delimiter))
            sequence :key key))

;;; The functions `sum' and `product' allow for the same keyword
;;; arguments as `reduce'.

(defun sum (sequence &rest args)
  "Return the sum of the elements of SEQUENCE."
  (apply #'reduce #'+ sequence args))

(defun product (sequence &rest args)
  "Return the product of the elements ot SEQUENCE."
  (apply #'reduce #'* sequence args))

;;;; Search

(defun best (test sequence &key (key #'identity) (start 0) end)
  "Return the element of SEQUENCE that beats all the others according
  to TEST, where Y is better than X if (FUNCALL TEST X Y) is non-nil.
  You can specify a subrange of the sequence."
  (reduce #'(lambda (prev curr)
              (if (funcall test (funcall key prev) (funcall key curr))
                  curr
                  prev))
          sequence :start start :end end))

(defun maximum (sequence &key (key #'identity) (start 0) end)
  "Return an element of SEQUENCE that maximizes the value of KEY.
  In case of ties, the first element is returned.
  You can specify a subrange of the sequence."
  (best #'< sequence :key key :start start :end end))

(defun minimum (sequence &key (key #'identity) (start 0) end)
  "Return an element of SEQUENCE that maximizes the value of KEY.
  In case of ties, the first element is returned.
  You can specify a subrange of the sequence."
  (best #'> sequence :key key :start start :end end))

(setf (symbol-function 'filter) #'remove-if-not)

;;;; Mapping

(defun map2 (fn list)
  "Map FN over successive pairs of LIST."
  (mapcar fn list (rest list)))

(defun mapx (fn &rest lists)
  "Map FN over the cross product of LISTS."
  (if lists
      (mapcan #'(lambda (x)
                  (apply #'mapx
                         #'(lambda (&rest args)
                             (apply fn x args))
                         (rest lists)))
              (first lists))
      (list (funcall fn))))

(defun maprange (fn lower upper)
  "Map FN over the integers from LOWER to UPPER."
  (do ((i upper (1- i))
       (vals nil))
      ((< i lower) vals)
    (push (funcall fn i) vals)))

(defun range (lower upper)
  "Return the list of integers from LOWER to UPPER."
  (do ((i upper (1- i))
       (vals nil))
      ((< i lower) vals)
    (push i vals)))

(defun mappend (fn &rest lists)
  "Map FN over LISTS and non-destructively append the results."
  (apply #'append (apply #'mapcar fn lists)))

(defun string-concat (&rest strings)
  "Return the concatenation of STRINGS."
  (apply #'concatenate 'string strings))

;;;; I/O

(defun read-as-list (string)
  "Wrap STRING in parenthesis and read in as a list."
  (values (read-from-string (string-concat "(" string ")"))))

(defun read-to-eof (stream)
  "Read charecters from STREAM until EOF and return the string read."
  (with-output-to-string (s)
    (loop for char = (read-char stream nil nil)
          while char do (write-char char s))))

;;;; Symbols

(defun symb (&rest names)
  "Concatenate symbols or strings to form an interned symbol."
  (intern (format nil "~{~A~}" names)))

(defun explode (string)
  "Return a list of symbols made from the characters of STRING."
  (map 'list #'(lambda (c)
                 (intern (make-string 1 :initial-element c)))
             string))

;;;; Function builders

(defun compose (&rest fns)
  "Return the composite of a list of functions."
  (if fns
      #'(lambda (&rest args)
          (reduce #'funcall
                  (butlast fns)
                  :from-end t
                  :initial-value (apply (last1 fns) args)))
      #'identity))

;;;; Macros

(defmacro with-interaction ((in from) (out to) &body body)
  `(with-open-file (,in ,from :direction :input)
     (with-open-file (,out ,to :direction :output
                               :if-exists :supersede)
       ,@body)))

(defmacro with-gensyms (syms &body body)
  `(let ,(mapcar #'(lambda (s)
                     `(,s (gensym)))
                 syms)
     ,@body))

(defmacro dolist* (spec &body body)
  "(DOLIST* (VAR1 LIST1 VAR2 LIST2 ...) ...) is equivalent to
  a chain of nested dolist loops (DOLIST (VARI LISTI) ...)."
  (if (evenp (length spec))
      (dolist-gen (group-by 2 spec) body)
      (error "Odd number of arguments.")))

(defun dolist-gen (pairs body)
  (let ((gensyms (loop repeat (length pairs) collect (gensym))))
    `(let ,(loop for g in gensyms
                 for (var list) in pairs
                 collect `(,g ,list))
       ,(reduce #'(lambda (parms expr)
                    `(dolist ,parms ,expr))
                (loop for g in gensyms
                      for (var list) in pairs
                      collect `(,var ,g))
                :from-end t :initial-value `(progn ,@body)))))

(defmacro dotimes* (spec &body body)
  "(DOTIMES* (VAR1 COUNT1 VAR2 COUNT2 ...) ...) is equivalent to
  a chain of nested dotimes loops (DOTIMES (VARI COUNTI) ...)."
  (if (evenp (length spec))
      (dotimes-gen (group-by 2 spec) body)
      (error "Odd number of arguments.")))

(defun dotimes-gen (pairs body)
  (let ((gensyms (loop repeat (length pairs) collect (gensym))))
    `(let ,(loop for g in gensyms
                 for (var count) in pairs
                 collect `(,g ,count))
       ,(reduce #'(lambda (parms expr)
                    `(dotimes ,parms ,expr))
                (loop for g in gensyms
                      for (var count) in pairs
                      collect `(,var ,g))
                :from-end t :initial-value `(progn ,@body)))))

(defmacro dotuples ((parms list) &body body)
  "Iterate over the successive tuples of LIST."
  (if parms
      (with-gensyms (glist)
        `(prog ((,glist ,list))
            (mapc #'(lambda ,parms ,@body)
                  ,@(loop for n from 0 below (length parms)
                          collect `(nthcdr ,n ,glist)))))))

(defmacro dolines ((lines stream) &body body)
  (with-gensyms (gstream)
    `(let ((,gstream ,stream))
       ,(if (listp lines)
            `(loop ,@(mappend #'(lambda (line)
                                  `(for ,line = (read-line ,gstream nil nil)))
                              lines)
               while (and ,@lines) do
               ,@body)
            `(loop for ,lines = (read-line ,gstream nil nil)
                   while ,lines do
                   ,@body)))))

(defmacro dohash (((key val) hash) &body body)
  `(block nil
     (maphash #'(lambda (,key ,val) ,@body) ,hash)))

(defmacro dovector ((var vector &key key (start 0) end from-end)
                    &body body)
  `(block nil
     (mapvector #'(lambda (,var) ,@body)
                ,vector
                :key ,key :start ,start :end ,end :from-end ,from-end)))

(defun mapvector (fn vector &key key (start 0) end from-end)
  "Call FN on each element of vector within a range."
  (if from-end
      (loop for index from (or end (length vector)) downto start
            do (funcall fn
                        (funcall (or key #'identity)
                                 (aref vector index))))
      (loop for index from start to (or end (length vector))
            do (funcall fn
                        (funcall (or key #'identity)
                                 (aref vector index))))))

(defmacro in (obj &rest choices)
  "Is OBJ eql to one of CHOICES?"
  (with-gensyms (gin)
    `(let ((,gin ,obj))
       (or ,@(mapcar #'(lambda (c) `(eql ,gin ,c))
                     choices)))))

(defmacro inq (obj &rest args)
  "A quoting variant of IN."
  `(in ,obj ,@(mapcar #'(lambda (a)
                          `',a)
                      args)))

(defmacro n-values (n form)
  (let ((values (loop repeat n collect (gensym "VALUE"))))
    `(multiple-value-bind ,values ,form
       (values ,@values))))

(defmacro bind (bindings &body body)
  (let* ((pats (mapcan #'(lambda (binding)
                           (cond ((atom binding) (list binding))
                                 ((single binding) (list (first binding)))
                                 (t (butlast binding))))
                       bindings))
         (vals (mapcar #'(lambda (binding)
                           (if (or (atom binding) (single binding))
                               nil
                               `(n-values ,(1- (length binding))
                                          ,(last1 binding))))
                       bindings))
         (args (gensym "ARGS")))
    `(multiple-value-call #'(lambda (&rest ,args)
                              (destructuring-bind ,pats ,args
                                ,@body))
       ,@vals)))

(defmacro bind* (bindings &body body)
  (if (null bindings)
      `(progn ,@body)
      (let ((binding (first bindings)))
        (cond ((or (atom binding)                     ;var
                   (single binding)                   ;(var)
                   (and (= (length binding) 2)        ;(var val)
                        (atom (first binding))))
               `(let (,binding)
                  (bind* ,(rest bindings) ,@body)))
              ((= (length binding) 2)                 ;(lambda-list val)
               `(destructuring-bind ,@binding
                  (bind* ,(rest bindings) ,@body)))
              (t                                      ;(lambda-list-1
               (let* ((pats (butlast binding))        ; lambda-list-2
                      (vals (last1 binding))          ; ...
                      (temp nil))                     ; lambda-list-n vals)
                 `(multiple-value-bind
                        ,(mapcar #'(lambda (pat)
                                     (if (atom pat)
                                         pat
                                         (let ((gen (gensym "VALUE")))
                                           (push `(,pat ,gen) temp)
                                           gen)))
                                 pats)
                      ,vals
                    (bind* ,(revappend temp (rest bindings))
                      ,@body))))))))

