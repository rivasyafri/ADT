; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: P01_13512036_13090304.lsp
; Topik		: Memeriksa kevalidan suatu jam masukan dan konversi jam
; Tanggal	: Selasa, 3 September 2013
; Deskripsi	: Program yang memeriksa apakah jam masukan valid
;			  yang lalu jika valid dikonversi ke detik dari 0:0:0
;			  pada hari itu dan jika tidak maka hasilnya nil

; APAKAH JAM VALID? dan KONVERSI JAM				KonversiJam (a,b,c)

; DEFINISI DAN SPESIFIKASI

; IsJamValid? : 3 integer -> boolean
; IsJamValid? (j,m,d) mengembalikan nilai true jika j, m, d menyusun
; jam yang valid. Definisi jam yang valid adalah jika elemen jam (j)
; bernilai antara 0 dan 23, elemen menit (m) bernilai antara 0 dan 59,
; dan elemen detik (d) bernilai antara 0 dan 59.

; JamToDetik : 3 integer -> integer
; JamToDetik (x,y,z) menerima masukan 3 buah integer yang sudah menyusun
; jam yang valid yang lalu menghitung jumlah detik dari jam itu 
; terhitung dari 0:0:0 pada tanggal tersebut

; KonversiJam : 3 integer -> integer
; KonversiJam (a,b,c) menerima masukan 3 buah integer yang lalu
; diperiksa susunan jam itu menggunakan fungsi IsJamValid? lalu 
; jika valid, jam itu akan dikonversi menjadi detik dengan fungsi
; JamToDetik

; REALISASI
(defun IsJamValid? (j m d)
	(and (>= j 0) (< j 24) (>= m 0) (< m 60) (>= d 0) (< d 60))
)

(defun JamToDetik (x y z)
	(+ (* x 3600) (* y 60) z)
)

(defun KonversiJam (a b c)
	(if (IsJamValid? a b c)
		(JamToDetik a b c)
		nil
	)
)

; CONTOH APLIKASI

; => (KonversiJam 0 0 0)
; => 0
; => (KonversiJam 0 -1 1)
; => NIL
; => (KonversiJam 3 3 3)
; => 10983
; => (IsJamValid? 0 -1 1)
; => T
; => (IsJamValid? 0 -1 1)
; => NIL
; => (JamToDetik 5 5 5)
; => 18305