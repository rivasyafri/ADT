; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: ADT_PECAHAN.lsp
; Topik		: Program pengecek pecahan
; Tanggal	: Kamis, 5 September 2013
; Deskripsi	: Program yang memeriksa dan mengoperasi tipe pecahan

; DEFINISI DAN SPESIFIKASI TYPE
; type pecahan : < n : integer >= 0 , d : integer > 0 >
; < n : integer >= 0 , d : integer>0 > n adalah pembilang (numerator) 
; dan d adalah penyebut(denominator). Penyebut sebuah pecahan 
; tidak boleh nol.

; DEFINISI DAN SPESIFIKASI SELEKTOR DENGAN FUNGSI
; Pemb : pecahan -> integer >= 0
; Pemb(Pecahan) memberikan numerator pembilang n dari pecahan tsb

; Peny : pecahan -> integer > 0
; Peny(Pecahan) memberikan denominator penyebut d dari pecahan tsb

; DEFINISI DAN SPESIFIKASI KONSTRUKTOR
; MakeP : integer >= 0, integer > 0 -> pecahan
; MakeP (pembilang,penyebut) membentuk sebuah pecahan dari pembilang 
; dan penyebut yang integer positif

; DEFINISI DAN SPESIFIKASI OPERATOR TERHADAP PECAHAN
; AddP : 2 pecahan -> pecahan
; AddP(P1,P2) : Menambahkan dua buah pecahan P1 dan P2 :
; n1/d1 + n2/d2 = (n1*d2 + n2*d1)/d1*d2

; SubP : 2 pecahan -> pecahan
; SubP(P1,P2) : Mengurangkan dua buah pecahan P1 dan P2
; Mengurangkan dua pecahan : n1/d1 - n2/d2 = (n1*d2 - n2*d1)/d1*d2

; MulP : 2 pecahan -> pecahan
; MulP(P1,P2) : Mengalikan dua buah pecahan P1 dan P2
; Mengalikan dua pecahan : n1/d1 * n2/d2 = n1*n2/d1*d2

; DivP : 2 pecahan -> pecahan
; DivP(P1,P2) : Membagi dua buah pecahan P1 dan P2
; Membagi dua pecahan : (n1/d1)/(n2/d2) = n1*d2/d1*n2. }

; ReaP : pecahan -> real
;{ ReaP(Pecahan) menuliskan bilangan pecahan dalam notasi desimal

; DEFINISI DAN SPESIFIKASI PREDIKAT
; IsEqP?: 2 pecahan -> boolean
; IsEqP?(P1,P2) true jika P1 = P2
; Membandingkan apakah dua buah pecahan sama nilainya: 
; n1/d1 = n2/d2 jika dan hanya jika n1*d2=n2*d1

; IsLtP?: 2 pecahan -> boolean
; IsLtP?(P1,P2) true jika p1 < p2
; Membandingkan dua buah pecahan, apakah p1 lebih kecil nilainya 
; dari p2: n1/d1 < n2/d2 jika dan hanya jika n1d2 < n2d1 }

; IsGtP?: 2 pecahan -> boolean
; IsGtP?(P1,P2) true jika p1 > p2
; Membandingkan nilai dua buah pecahan,, apakah p1 lebih besar nilainya
; dari p2: n1/d1 > n2/d2 jika dan hanya jika n1d2 > n2d1 }

(defun Pemb (Pecahan)
	(car Pecahan)
)

(defun Peny (Pecahan)
	(car (cdr Pecahan))
)

(defun MakeP (pembilang penyebut)
	(cons pembilang (cons penyebut nil))
)

(defun IsEqP? (P1 P2)
	(and 
		(if (= (/ (Pemb P1) (Peny P1)) (/ (Pemb P2) (Peny P2))) T nil)
		(if T (= (* (Pemb P1) (Peny P2)) (* (Pemb P2) (Peny P1))) nil)
	)
)

(defun IsLtP? (P1 P2)
	(and 
		(if (< (/ (Pemb P1) (Peny P1)) (/ (Pemb P2) (Peny P2))) T nil)
		(if T (< (* (Pemb P1) (Peny P2)) (* (Pemb P2) (Peny P1))) nil)
	)
)

(defun IsGtP? (P1 P2)
	(and 
		(if (> (/ (Pemb P1) (Peny P1)) (/ (Pemb P2) (Peny P2))) T nil)
		(if T (> (* (Pemb P1) (Peny P2)) (* (Pemb P2) (Peny P1))))
	)
)

(defun AddP (P1 P2)
	(/ (+ (* (Pemb P1) (Peny P2)) (* (Pemb P2) (Peny P1))) (* (Peny P1) (Peny P2)))
)

(defun SubP (P1 P2)
	(/ (- (* (Pemb P1) (Peny P2)) (* (Pemb P2) (Peny P1))) (* (Peny P1) (Peny P2)))
)

(defun MulP (P1 P2)
	(/ (* (Pemb P1) (Pemb P2)) (* (Peny P1) (Peny P2)))
)

(defun DivP (P1 P2)
	(/ (* (Pemb P1) (Peny P2)) (* (Peny P1) (Pemb P2)))
)

(defun ReaP (Pecahan)
	(* (/ (Pemb Pecahan) (Peny Pecahan)) 1.0)
)

; APLIKASI

; 