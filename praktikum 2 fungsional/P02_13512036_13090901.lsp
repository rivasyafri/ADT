; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: P02_13512036_13090901.lsp
; Topik		: Program pengecek point
; Tanggal	: Senin, 9 September 2013
; Deskripsi	: Program yang memeriksa dan mengoperasi tipe point

; DEFINISI TYPE
; type point : <x: real , y: real >
; <x,y> adalah sebuah point, dengan x adalah absis, y adalah ordinat

; DEFINISI DAN SPESIFIKASI SELEKTOR
; Absis : point -> real
; Absis(Point) memberikan absis Point P

; Ordinat : point -> real
; Ordinat(Point) memberikan ordinat Point P

; DEFINISI DAN SPESIFIKASI KONSTRUKTOR
; MakePoint : 2 real -> point
; MakePoint(x,y) membentuk sebuah Point dari a dan b dengan a sebagai
; absis dan b sebagai ordinat

; DEFINISI DAN SPESIFIKASI PREDIKAT
; IsOrigin? : point -> boolean
; IsOrigin?(Point) benar jika P adalah titik origin yaitu titik <0,0>

; IsMirrorOnPoint : 3 point -> boolean
; IsMirrorOnPoint (P1,P2,Pm) menghasilkan true jika P1 dan P2 merupakan
; mirror satu sama lain terhadap Pm

; DEFINISI OPERATOR/FUNGSI LAIN TERHADAP POINT
; Jarak : 2 point -> real
; Jarak(a,b) : menghitung jarak antara 2 point P1 dan P2

; Jarak0 : point -> integer
; Jarak0(Point) menghitung jarak titik P terhadap titik pusat koordinat (0,0)

; Kuadran : point -> integer [1..4]
; Kuadran(Point) menghitung di mana kuadran di mana titik tersebut terletak.
; Syarat: Point bukan titik origin dan bukan terletak pada Sumbu X dan 
; bukan terletak pada sumbu Y. }

; MirrorPoint : 2 point -> point
; MirrorPoint (P,Pm) menghasilkan sebuah Point yang merupakan hasil
; pencerminan P terhadap Pm

; MirrorPointKuadran : 2 point -> 3 integer
; MirrorPointKuadran (P1,P2) menghasilkan sebuah tuple <K1,K2,K3> dengan
; K1 adalah kuadran dari P1, K2 adalah kuadran dari P2, dan K3 adalah
; kuadran dari P1 dicerminkan terhadap P2

; REALISASI SELEKTOR
(defun Absis (Point)
	(car Point)
)

(defun Ordinat (Point)
	(car (cdr Point))
)

; REALISASI KONSTRUKTOR
(defun MakePoint (x y)
	(cons x (cons y nil))
)

; REALISASI PREDIKAT
(defun IsOrigin? (Point)
	(and (= (Absis Point) 0) (= (Ordinat Point) 0))
)

(defun IsMirrorOnPoint (P1 P2 Pm)
	(equal (MirrorPoint P1 Pm) P2)
)

; DEFINISI OPERATOR/FUNGSI LAIN TERHADAP POINT
(defun Jarak (a b)
	(sqrt (+ (expt (- (Absis a) (Absis b)) 2) (expt (- (Ordinat a) (Ordinat b)) 2)))
)

(defun Jarak0 (Point)
	(sqrt (+ (expt (Absis Point) 2) (expt (Ordinat Point) 2)))
)

(defun Kuadran (Point)
	(cond
		((and (> (Absis Point) 0) (> (Ordinat Point) 0)) 1)
		((and (< (Absis Point) 0) (> (Ordinat Point) 0)) 2)
		((and (< (Absis Point) 0) (< (Ordinat Point) 0)) 3)
		((and (> (Absis Point) 0) (< (Ordinat Point) 0)) 4)
		nil
	)
)

(defun MirrorPoint (P Pm)
	(MakePoint (- (Absis Pm) (- (Absis P) (Absis Pm))) (- (Ordinat Pm) (- (Ordinat P) (Ordinat Pm))))
)

(defun MirrorPointKuadran (P1 P2)
	(list (Kuadran P1) (Kuadran P2) (Kuadran (MirrorPoint P1 P2)))
)

; APLIKASI

; => (setq a (MakePoint 1 0))
; <1,0>
; => (setq b (MakePoint 0 0))
; <0,0>
; => (setq c (MakePoint 9 2))
; <9,2>
; => (setq d (MakePoint -1 -1))
; <-1,-1>
; => (setq P (MakePoint 5 5))
; <5,5>
; => (setq Pm (MakePoint 1,1))
; <1,1>
; => (absis a)
; 1
; => (absis c)
; 9
; => (ordinat c)
; 2
; => (IsOrigin? b)
; T
; => (IsOrigin? c)
; NIL
; => (Jarak a c)
; 8.246211
; => (Jarak0 c)
; 9.219544
; => (Kuadran c)
; 1
; => (Kuadran d)
; 3
; => => MirrorPoint(P,Pm)
; <-3,-3>
; => MirrorPoint(Pm,P)
; <9,9>