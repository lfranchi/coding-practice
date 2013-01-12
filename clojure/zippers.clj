(ns lzippers)

;; list zipper
(defn lzipper
  []
  [() ()])

(defn list-insert-at-cursor
  [lzipper newchar]
  [(cons newchar (first lzipper)) (second lzipper)])

(defn list-get-at-cursor
  [lzipper]
  (ffirst lzipper))

(defn list-move-left
  [lzipper]
  [(rest (first lzipper)) (cons (ffirst lzipper) (second lzipper))])

(defn list-move-right
  [lzipper]
  (if (seq (second lzipper))
    [(cons (first (second lzipper)) (first lzipper)) (rest (second lzipper))]
    lzipper))

(defn list-delete-at-cursor
  [lzipper]
  [(rest (first lzipper)) (second lzipper)])

;; tree zipper

(defn tzipper
  []
  ())

(defrecord tree [val left right])

(defn tree-insert
  [tree val]
  (cons (->tree val (first tree) nil) tree))

(defn tree-get
  [tree]
  (:val (first tree)))

;; tests

(def z (lzipper))
(def z (list-insert-at-cursor z "a"))
(def z (list-insert-at-cursor z "b"))
(def z (list-insert-at-cursor z "c"))
(def z (list-insert-at-cursor z "d"))

(list-get-at-cursor z)

(def z (list-move-left z))
(list-get-at-cursor z)

(def z (list-delete-at-cursor z))
(list-get-at-cursor z)

(def z (list-insert-at-cursor z "q"))
(list-get-at-cursor z)

(def z (list-move-right z))
(list-get-at-cursor z)

(def z (list-move-right z))
(list-get-at-cursor z)