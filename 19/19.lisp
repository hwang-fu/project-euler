; sbcl --script 19.lisp
(defun is-leap-year (year)
  (if (= (mod year 100) 0)
    (= (mod year 400) 0)
    (= (mod year 4) 0)))

(defun month-days (month)
  (cond
    ((= month 1) 31)
    ((= month 2) 28); +1 in leap year
    ((= month 3) 31)
    ((= month 4) 30)
    ((= month 5) 31)
    ((= month 6) 30)
    ((= month 7) 31)
    ((= month 8) 31)
    ((= month 9) 30)
    ((= month 10) 31)
    ((= month 11) 30)
    ((= month 12) 31)))

(defvar *count* 0)
(defvar *start-day-of-the-month* 0); 0 - Sun, 1 - Mon, ..., 6 - Sat

(defun Counting-Sundays ()
  (do ((year 1900 (+ year 1)))
      ((= year 2001))
    (do ((month 1 (+ month 1)))
        ((= month 13))
      (let ((days (month-days month)))
        (when (= month 2) (incf days 1))
        (when (and (> year 1900) (= *start-day-of-the-month* 0)) (incf *count* 1))
        (setf *start-day-of-the-month* (mod (+ *start-day-of-the-month* (mod days 7)) 7)))))
  (format t "~A~%" *count*))

(Counting-Sundays)
