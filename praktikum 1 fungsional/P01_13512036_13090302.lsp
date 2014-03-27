; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: P01_13512036_13090302.lsp
; Topik		: Penghitung Tahanan
; Tanggal	: Selasa, 3 September 2013
; Deskripsi	: Program yang menghitung tahanan total berdasarkan seri 
;			  atau paralel yang ditentukan oleh ekspresi kondisional.

; PENGHITUNG TAHANAN						Tahanan (j,r1,r2,r3)

; DEFINISI DAN SPESIFIKASI

; Tahanan : 3 real > 0, 1 character ['S','P'] -> real
; Tahanan (j,r1,r2,r3) menghitung tahanan total sesuai dengan
; kode penanda jenis rangkaian yang digunakan : menggunakan ekspresi 
; kondisional untuk menentukan jenis rangkaian yang selanjutnya 
; dimasukkan ke rumus paralel :(r1*r2*r3)/(r1*r2+r2*r3+r3*r1)
; atau ke rumus seri : (r1+r2+r3)

; REALISASI
(defun Tahanan (j r1 r2 r3)
	(if (equal j 'P)
	; Asumsikan karakter yang dimasukkan selalu benar
		(/ (* r1 r2 r3) (+ (* r1 r2) (* r2 r3) (* r3 r1)))
		(+ r1 r2 r3)
	)
)

; CONTOH APLIKASI
; => (Tahanan 'P 2 3 5)
; => 30/31
; => (Tahanan 'P 1 3 5)
; => 15/23
; => (Tahanan 'S 1 3 5)
; => 9
; => (Tahanan 'S 2 3 5)
; => 10
