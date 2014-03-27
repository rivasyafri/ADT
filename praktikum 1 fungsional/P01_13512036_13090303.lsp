; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: P01_13512036_13090303.lsp
; Topik		: Penghitung Luas Bidang Geometri
; Tanggal	: Selasa, 3 September 2013
; Deskripsi	: Program yang menghitung luas dari suatu bidang berdasarkan
;			  kode dan parameter masukan yang diasumsikan selaras.

; PENGHITUNG LUAS BIDANG GEOMETRI
; LuasBidang (k,x,y(opsional),z(opsional))

; DEFINISI DAN SPESIFIKASI

; LuasBidang : 1 hingga 3 real > 0, 1 character ['S','P','B','T','L'] -> real
; LuasBidang (k,x,y,z) menerima kode bidang geometri yang lalu diteruskan
; ke rumus matematika masing-masing bidang geometri.
; rumus Segitiga : (x*y)/2 dengan x = alas dan y = tinggi
; rumus Persegi Panjang : x*y dengan x = sisi panjang dan y = sisi lebar
; rumus Bujur Sangkar : x*x dengan x = panjang sisi
; rumus Trapesium : ((x+y)*z)/2 dengan x = sisi panjang, y = sisi pendek
; 					, dan z = tinggi trapesium
; rumus LIngkaran : 3.14*x*x dengan x = panjang jari-jari lingkaran.

; REALISASI
(defun LuasBidang (k x &optional y z)
	(cond
		((equal k 'P) (* x y))
		((equal k 'S) (* (/ 1 2) x y))
		((equal k 'B) (* x x))
		((equal k 'T) (/ (* (+ x y) z) 2))
		((equal k 'L) (* 3.14 x x))
	)
)

; CONTOH APLIKASI

; => (LuasBidang 'B 2)
; => 4
; => (LuasBidang 'L 3)
; => 28.26
; => (LuasBidang 'S 3 4)
; => 6
; => (LuasBidang 'P 3 4)
; => 12
; => (LuasBidang 'T 3 4 5)
; => 35/2
