(defvar *four-million* 4000000)

(defun sum-even-fibonacci-numbers (upper-bound-inclusive)
  (loop for a = 1 then b
        for b = 2 then (+ a b)
        while (<= a upper-bound-inclusive)
        when (evenp a) sum a))
