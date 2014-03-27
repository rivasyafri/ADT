; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: P01_13512036_13090301.lsp
; Topik		: Contoh Program Kecil dalam Bahasa LISP
; Tanggal	: Selasa, 3 September 2013
; Deskripsi	: Program kecil ini digunakan untuk mengubah bilangan
;			  negatif menjadi positif (absolut), mencari min dan max
;			  dari suatu sampel data berjumlah 2 atau 4, dan mencari
;			  nilai yang berdasarkan perhitungan Mean-Olympique dari
;			  suatu sampel data.


; MEAN-OLYMPIQUE						MO (u,v,w,x)

; DEFINISI DAN SPESIFIKASI

; MO : 4 integer > 0 -> real
; MO (u,v,w,x): menghitung rata-rata dari dua buah bilangan integer,
; yang bukan maksimum dan bukan minimum dari 4 buah integer:
; (u+v+w+x-min4 (u,v,w,x) - max4 (u,v,w,x))/2

; max4 : 4 integer > 0 -> integer
; max4 (i,j,k,l) menentukan maksimum dari 4 buah bilangan integer

; min4 : 4 integer > 0 -> integer
; min4 (i,j,k,l) menentukan minimum dari 4 buah bilangan integer

; max2 : 2 integer > 0 -> integer
; max2 (a,b) menentukan maksimum dari 2 bilangan integer, hanya dengan
; ekspresi matematika: jumlah dari kedua bilangan ditambah dengan
; selisih kedua bilangan, hasilnya dibagi 2

; min2 : 2 integer > 0 -> integer
; min2 (a,b) menentukan minimum dari 2 bilangan integer, hanya dengan
; ekspresi aritmatika :jumlah dari kedua bilangan - selisih
; kedua bilangan , hasilnya dibagi 2

; absolut: integer -> integer
; absolut(a) mengembalikan nilai absolut a

; REALISASI
(defun absolut (a)
	(cond	((> a 0) a)
			((< a 0) (* -1 a))
			(t 0)
	)
)

(defun max2 (a b)
	(/ (+ a b (absolut (- a b))) 2)
)

(defun min2 (a b)
	(/ (- (+ a b) (absolut (- a b))) 2)
)

(defun max4 (i j k l)
	(max2 (max2 i j) (max2 k l))
)

(defun min4 (i j k l)
	(min2 (min2 i j) (min2 k l))
)

(defun MO (u v w x)
	(/ (- (+ u v w x)
		  (min4 u v w x)
		  (max4 u v w x))
		2
	)
)

; CONTOH APLIKASI

; => (absolut -8)
; 8
; => (max2 8 10)
; 10
; => (min2 8 10)
; 8
; => (max4 8 10 12 20)
; 20
; => (min4 8 10 12 20)
; 8
; => (MO 8 10 12 20)
; 11
