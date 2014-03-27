; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: P01_13512036_13090305.lsp
; Topik		: Memeriksa kevalidan suatu tanggal masukan
; Tanggal	: Selasa, 3 September 2013
; Deskripsi	: Program yang memeriksa apakah tanggal masukan valid

; APAKAH TANGGAL VALID?							IsDateValid? (d,m,y)

; DEFINISI DAN SPESIFIKASI

; IsDateValid? : 3 integer -> boolean
; IsDateValid? (d,m,y) mengembalikan nilai true jika d, m, y membentuk
; date yang valid. Definisi date yang valid adalah jika elemen hari (d)
; bernilai antara 1 dan 31, tergantung pada bulan dan apakah tahun 
; kabisat atau bukan, elemen bulan (m) bernilai antara 1 dan 12,
; dan elemen tahun (y) bernilai lebih dari 0.

; REALISASI
(defun IsDateValid? (d m y)
	(cond
		((and (= (mod y 4) 0) (> y 0)) (cond 
											((= m 2) (and (>= d 1) (<= d 29)))
											 ; untuk bulan februari di tahun kabisat
											((or (= m 1) (= m 3) (= m 5) (= m 7) (= m 8) (= m 10) (= m 12))
											 (and (>= d 1) (<= d 31))
											 ; untuk bulan yang jumlah harinya 31
											)
											((or (= m 2) (= m 4) (= m 6) (= m 9) (= m 11))
											 (and (>= d 1) (<= d 30))
											 ; untuk bulan yang jumlah harinya 30
											)
											(nil)
										)
		)
		((and (/= (mod y 4) 0) (> y 0)) (cond 
											((= m 2) (and (>= d 1) (<= d 28)))
											 ; untuk bulan februari di bukan tahun kabisat
											((or (= m 1) (= m 3) (= m 5) (= m 7) (= m 8) (= m 10) (= m 12))
											 (and (>= d 1) (<= d 31))
											 ; untuk bulan yang jumlah harinya 31
											)
											((or (= m 4) (= m 6) (= m 9) (= m 11))
											 (and (>= d 1) (<= d 30))
											 ; untuk bulan yang jumlah harinya 30
											)
											(nil)
										)
		)
	)
)

; CONTOH APLIKASI

; => (IsDateValid? 29 2 4)
; => T
; => (IsDateValid? 29 2 5)
; => NIL
; => (IsDateValid? 31 3 5)
; => T
; => (IsDateValid? 32 3 5)
; => NIL
; => (IsDateValid? 30 3 5)
; => T
; => (IsDateValid? 29 2 2000)
; => T
; => (IsDateValid? 0 2 4)
; => NIL