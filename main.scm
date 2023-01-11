;;Checks the element passed is a BST
(define check-bst
    (lambda (bst)
        (if (and (list? bst) (or (null? bst) (and (equal? 3 (length bst)) (and (list? (car (cdr bst))) (list? (car (cdr (cdr bst))))))))
            #t
            #f)))

;; returning the root of bst
(define entry
  (lambda (bst)
    ;; checking if the root is a number and if the element passed is a bst
    (cond ((< (length bst) 3) #f)
          ((integer? (car bst)) (car bst))
          (else #f)
    )))
;; Returns the left subtree
(define left
  (lambda (bst)
    ;; checking if the root is a number and if the element passed is a bst
    (cond ((< (length bst) 3) #f)
          ((and (integer? (entry bst)) (list? (cdr bst))) (cdr bst))
          (else #f)
    )))

;; Returns the right subtree
(define right
  (lambda (bst)
    ;; checking if the root is a number and if the element passed is a bst
    (cond ((< (length bst) 3) #f)
          ((and (integer? (entry bst)) (list? (cdr (cdr bst)))) (cdr (cdr bst)))
          (else #f)
    )))

;;Creates a bst from the information provided
(define make-bst 
    (lambda (elt left-bst right-bst)
        (if (and (integer? elt) (and (check-bst left-bst) (check-bst right-bst)))
            (list elt left-bst right-bst)
            #f    
        )
    ))

(define preorder-helper
    (lambda (bst lst)
        (if (check-bst bst)
            (cons (entry bst) (append (preorder-helper (right bst) lst) (preorder-helper (left bst) lst)))
            '()
        )))

(define preorder
    (lambda (bst)
        (preorder-helper bst '())))







