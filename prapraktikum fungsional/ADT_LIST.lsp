; NIM / Nama	: 13512036 / Riva Syafri Rachmatullah
; Nama file 	: P03_13512036_13101401.lsp
; Topik     	: ADT LIST fungsional
; Tanggal		: 13 Oktober 2013
; Deskripsi		: ADT List fungsional 

; DEFINISI DAN SPESIFIKASI TYPE
; Konstruktor menambahkan elemen di awal, notasi prefix
; type List of integer : [ ], atau [e o List]
; Konstruktor menambahkan elemen di akhir, notasi postfix
; type List of integer : [ ] atau [List • e]
; Definisi List : sesuai dengan definisi rekursif

; SELEKTOR

; FirstElmt: List of integer tidak kosong -> integer
; FirstElmt(L) menghasilkan elemen pertama List L 
(defun FirstElmt (L)
	(car L)
)

; LastElmt : List of integer tidak kosong -> integer
; LastElmt(L) menghasilkan elemen terakhir List L
(defun LastElmt (L)
	(car (reverse L))
)

; Tail : List of integer tidak kosong -> List of integer
; Tail(L) menghasilkan List L tanpa elemen pertama
(defun Tail (L)
	(cdr L)
)
; Head : List of integer tidak kosong -> List of integer
; Head(L) menghasilkan List L tanpa elemen terakhir
(defun Head (L)
	(cdr (reverse L))
)

; KONSTRUKTOR

; Konso : integer, List of integer tidak kosong -> List of integer
; Konso(x,L) menghasilkan sebuah List dari e dan L dengan e sebagai 
; elemen pertama L : x o L -> L'
(defun Konso (x L)
	(cons x L)
)

; Kons• : List of integer tidak kosong, integer -> List of integer
; Kons(L,x) menghasilkan sebuah List dari L dan e, dengan e sebagai 
; elemen terakhir L : L • x -> L'
(defun Konsd (L x)
	(reverse (cons x (reverse L)))
)

; PREDIKAT UNTUK BASIS ANALSASI REKURENS

; IsEmpty : List of integer -> boolean
; IsEmpty(L) benar jika List L kosong
(defun IsEmpty (L)
	(equal L '())
)

; IsOneElmt: List of integer -> boolean
; IsOneElmt(L) adalah benar jika L hanya mempunyai satu elemen
(defun IsOneElmt (L)
	(and (not (equal (car L) '())) (equal (cdr L) '()))
)

; PREDIKAT KEABSAHAN

; IsListInt: List -> boolean
; IsListInt(L) menghasilkan true jika L adalah List dengan elemen 
; integer
(defun IsListInt (L)
	(if (IsEmpty L) ; basis
		nil
		(if (integerp (FirstElmt L)) ;rekurens
			(IsListInt (Tail L))
			nil
		)
	)
)

; PREDIKAT RELASIONAL

; IsEqual : 2 List of integer -> boolean
; IsEqual(L1,L2) benar jika semua elemen List L1 sama dengan L2:
; sama urutan dan sama nilainya
(defun IsEqual (L1 L2)
	(cond
		((and (IsEmpty L1) (IsEmpty L2)) T)
		((and (IsEmpty L1) (not (IsEmpty L2))) nil)
		((and (not (IsEmpty L1)) (IsEmpty L2)) nil)
		((and (not (IsEmpty L1)) (not (IsEmpty L2)))
			(if (= (FirstElmt L1) (FirstElmt L2))
				(IsEqual (Tail L1) (Tail L2))
				nil
			)
		)
	)
)

; FUNGSI LAIN

; NbElmt : List of integer -> integer
; NbElmt(L) menghasilkan banyaknya elemen List L, nol jika kosong
(defun NbElmt (L)
	(if (IsEmpty L) 
		0 
		(+ 1 (NbElmt (Tail L)))
	)
)

; ElmtkeN : integer > 0 , List -> integer
; ElmtkeN(N, L) mengirimkan elemen List L yang ke N, N £ NbELmt(L) 
; dan N>=0
(defun ElmtkeN (n L)
	(if (= n 1) ;basis
		(FirstElmt L)
		(ElmtkeN (- n 1) (Tail L)) ;rekurens
	)
)

; Copy : List of integer -> List of integer
; Copy(L) menghasilkan List yang identik dengan List asal L
(defun Copy (L)
	(if (IsEmpty L) ;basis
		nil
		(Konso (FirstElmt L) (Copy(Tail L)))
	)
)

; Inverse : List of integer -> List of integer
; Inverse(L) menghasilkan List L yang dibaLk, yaitu yang urutan 
; elemennya adalah kebaLkan dari List asal L
(defun Inverse (L)
	(if (IsEmpty L) ;basis
		nil
		(Konsd (Inverse (Tail L)) (FirstElmt L))
	)
)

; Konkat : 2 List of integer -> List of integer
; Konkat(L1,L2) menghasilkan konkatenasi 2 buah List, dengan List L2 
; "sesudah" List L1
(defun Konkat (L1 L2)
	(if (IsEmpty L1)
		L2
		(Konso (FirstElmt L1) (Konkat (Tail L1) L2))
	)
)

; PREDIKAT

; IsMember: integer, List of integer -> boolean
; IsMember(x,L) adalah benar jika x adalah elemen List L
(defun IsMember (n L)
	(if (IsEmpty L) ; basis
		nil
		(if (equal n (FirstElmt L)) ;rekurens
			T
			(IsMember n (Tail L))
		)
	)
)

; IsFirst: integer, List of integer tidak kosong -> boolean
; IsFirst(x,L) adalah benar jika x adalah elemen pertama List L
(defun IsFirst (n L)
	(equal (FirstElmt L) n)
)

; IsLast : integer, List of integer tidak kosong -> boolean
; IsLast (x,L) adalah benar jika x adalah elemen terakhir List L
(defun IsLast (n L)
	(equal (LastElmt L) n)
)

; IsNbElmtN : integer > 0, List of integer -> boolean
; IsNbElmtN(n, L) true jika banyaknya elemen List L sama dengan n
(defun IsNbElmtN (n L)
	(equal (NbElmt L) n)
)

; IsInverse : List of integer, List of integer -> boolean
; IsInverse(L1,L2) true jika L2 adalah List dengan urutan elemen 
; terbaLk dibandingkan L1
(defun IsInverse (L1 L2)
	(equal (Inverse L2) L1)
)

; IsXElmtkeN : integer, integer > 0, List of integer -> boolean
; IsXElmtkeN(x,n,L) adalah benar jika x adalah elemen List L yang ke-n,
;  0 < n £ NbElmt(L).
(defun IsXElmtkeN (x n L)
	(equal (ElmtkeN n L) x)
)

; OPERASI LAIN TERKAIT INTEGER

; MaxList : List of integer tidak kosong -> integer
; MaxList(L) menghasilkan elemen L yang bernilai maksimum
(defun MaxList (L)
	(if (IsOneElmt (Tail L)) ;basis
		(if (>= (FirstElmt L) (FirstElmt(Tail L)))
			(FirstElmt L)
			(FirstElmt (Tail L))
		)
		(if (>= (FirstElmt L) (MaxList (Tail L))) ; rekurens
			(FirstElmt L)
			(MaxList (Tail L))
		)
	)
)

; MinList : List of integer tidak kosong -> integer
; MinList(L) menghasilkan elemen L yang bernilai minimum
(defun MinList (L)
	(if (IsOneElmt (Tail L)) ;basis
		(if (<= (FirstElmt L) (FirstElmt(Tail L)))
			(FirstElmt L)
			(FirstElmt (Tail L))
		)
		(if (<= (FirstElmt L) (MinList (Tail L))) ; rekurens
			(FirstElmt L)
			(MinList (Tail L))
		)
	)
)

; Dimensi : List of integer -> integer > 0
; Dimensi(L) menghasilkan banyaknya elemen List integer
(defun Dimensi (L)
	(if (IsOneElmt L) ; basis
		(if (integerp (FirstElmt L))
			1
			0
		)
		(if (integerp (FirstElmt L)) ;rekurens
			(+ (IsListInt (Tail L)) 1)
			(IsListInt (Tail L))
		)
	)
)

; ListPlus : 2 List of integer 0 -> List of integer 0
; ListPlus(L1,L2) menjumlahkan setiap elemen List integer L1 dan L2 
; yang berdimensi sama, hasilnya berupa List integer berdimensi tsb.
(defun ListPlus (L1 L2)
	(if (and (IsOneElmt L1)(IsOneElmt L2)) ; basis
		(Konso (+ (FirstElmt L1) (FirstElmt L2)) nil)
		(Konso (+ (FirstElmt L1) (FirstElmt L2)) (ListPlus (Tail L1) (Tail L2)))
	)
)

; ElmtPlus : List of integer -> integer
; ElmtPlus(L) menjumlahkan setiap elemen List integer L
(defun ElmtPlus (L)
	(if (IsEmpty L) ; basis
		0
		(+ (FirstElmt L) (ElmtPlus (Tail L)))	
	)
)

; Insort : List of integer -> List of integer
; Insort(L) menghasilkan List integer yang terurut dengan metode 
; insertion sort
(defun Insort (L)
	(if (IsEmpty L)
		'()
		(Insert (FirstElmt L) (Insort (Tail L)))
	)
)

; Insert : integer, List of integer -> List of integer
; Insert(L) menghasilkan List integer yang terurut dengan metode 
; insertion sort yang memasukkan x di tempat yang sesuai
(defun Insert (x L)
	(if (IsEmpty L) 
		(Konso x L) 
		(if (<= x (FirstElmt L))
			(Konso x L)
			(Konso (FirstElmt L) (Insert x (Tail L)))
		)
	)
)
; MaxNb : List of integer -> <integer, integer>
; MaxNb(L) menghasilkan <nilai maksimum, kemunculan nilai maksimum> dari
; suatu List integer
; L: <m,n> = m adalah elemen L yang bernilai maksimum, dan n adalah 
; jumlah occurence m dalam List L.
(defun MaxNb (L)
	(Konso (MaxList L) (list (NbKemunculan L (MaxList L))))
)

; NbKemunculan : List of integer, integer → integer
; NbKemunculan (L,x) menghitung jumlah kemunculan X di L
(defun NbKemunculan (L x)
	(if (IsOneElmt L)
		(if (= x (FirstElmt L)) 
			1
			0
		)
		(if (= x (FirstElmt L))
			(+ 1 (NbKemunculan (Tail L) x))
			(NbKemunculan (Tail L) x)
		)
	)
)

; NbFaktor : integer > 0, List of integer →  integer 
; NbFaktor(Li,N) menghasilkan banyaknya kemunculan bilangan yang merupakan
; faktor dari N dalam list Li. Jika Li kosong, maka nilai yang dihasilkan 
; adalah 0. dalam LISP fungsi mod adalah rem
(defun NbFaktor (Li N)
	(if (IsEmpty Li) ; kasus khusus untuk list kosong
		0
		(if (IsOneElmt Li) ; basis
			(if (= 0 (rem N (FirstElmt Li)))
				1
				0
			)
			(if (= 0 (rem N (FirstElmt Li))) ; rekurens
				(+ 1 (NbFaktor (Tail Li) N))
				(NbFaktor (Tail Li) N)
			)
		)
	)
)

; FilterFaktor : List of integer, integer → List of integer
; FilterFaktor (L,X) menghasilkan List of integer tanpa elemen- elemen 
; yang merupakan faktor dari X. List kosong menghasilkan list kosong.
(defun FilterFaktor (L X)
	(if (IsEmpty L) ; kasus khusus untuk list kosong
		nil
		(if (IsOneElmt L) ; basis
			(if (= 0 (rem X (FirstElmt L)))
				'()
				(Konso (FirstElmt L) nil)
			)
			(if (= 0 (rem X (FirstElmt L))) ; rekurens
				(FilterFaktor (Tail L) X)
				(Konso (FirstElmt L) (FilterFaktor (Tail L) X))
			)
		)
	)
)

; IsAllElmtExist : 2 List of integer → boolean
; IsAllElmtExist (L1,L2) memeriksa apakah semua elemen dalam L1 terdapat 
; dalam L2 (tanpa memperhatikan urutan ataupun banyaknya elemen). 
; Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false.
(defun IsAllElmtExist (L1 L2)
	(if (IsEmpty L1) ; kasus khusus
		nil
		(if (IsOneElmt L1) ; basis 1
		 	(IsMember (FirstElmt L1) L2)
		 	(if (IsMember (FirstElmt L1) L2)
		 		(IsAllElmtExist (Tail L1) L2)
		 		nil
		 	)
		)
	)
)

; MOExtended : List of integer dengan minimum 3 elemen → real
; MOExtended (L) menghasilkan nilai rata-rata semua elemen list of integer
; (dengan banyaknya elemen minimum adalah 3) setelah dikurangi salah satu
; nilai maksimum dan salah satu nilai minimum dari nilai-nilai integer 
; dalam list tersebut.
(defun MOExtended (L)
	(* (/ (- (ElmtPlus L) (MaxList L) (MinList L)) (- (NbElmt L) 2)) 1.0)
)