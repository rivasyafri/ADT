; NIM / Nama	: 13512036 / Riva Syafri Rachmatullah
; Nama file 	: P03_13512036_13101802.lsp
; Topik     	: ADT POHON BINER
; Tanggal		: 13 Oktober 2013
; Deskripsi		: ADT pohon biner fungsional 

; DEFINISI DAN SPESIFIKASI TYPE
; type elemen : integer
; type PohonBiner : < A : elemen, L : PohonBiner, R : PohonBiner >
; PohonBiner terdiri dari Akar yang berupa elemen, L dan R adalah 
; PohonBiner yang merupakan subpohon kiri dan subpohon kanan

; DEFINISI DAN SPESIFIKASI KONSTRUKTOR
; Perhatikanlah bahwa konstruktor pohon biner dengan basis pohon 
; kosong dituliskan sebagai
; Prefix : //A L R\\

; SELEKTOR

; Akar : PohonBiner tidak kosong -> elemen
; Akar(P) adalah Akar dari P. Jika P adalah //L A R\\ = Akar(P) adalah A
(defun Akar (P)
	(car P)
)

; Left : PohonBiner tidak kosong -> PohonBiner
; Left(P) adalah sub pohon kiri dari P. Jika P adalah //L A R\ \, Left (P) adalah L
(defun Left (P)
	(car (cdr P))
)

; Right : PohonBiner tidak kosong -> PohonBiner
; Right(P) adalah sub pohon kanan dari P. Jika P adalah //L A R\\, Right (P) adalah R
(defun Right (P)
	(car (cdr (cdr P)))
)

; PREDIKAT

; IsTreeEmpty : PohonBiner -> boolean
; IsTreeEmpty(P) true jika P kosong : (// \\)
(defun IsTreeEmpty (P)
	(null P)
)

; IsOneElmt : PohonBiner -> boolean
; IsOneElmt(P) true jika P hanya mempunyai satu elemen, yaitu akar (// A \\)
(defun IsOneElmt (P)
	(and (not (equal (Akar P) '())) (equal (Left P) '()) (equal (Right P) '()))
)

; IsUnerLeft : PohonBiner -> boolean
; IsUnerLeft(P) true jika P hanya mengandung sub pohon kiri tidak kosong: (//L A\\)
(defun IsUnerLeft (P)
	(and (not (equal (Akar P) '())) (not (equal (Left P) '())) (equal (Right P) '()))
)

; IsUnerRight : PohonBiner -> boolean
; IsUnerRight (P) true jika P hanya mengandung sub pohon kanan tidak kosong: (//A R\\)
(defun IsUnerRight (P)
	(and (not (equal (Akar P) '())) (equal (Left P) '()) (not (equal (Right P) '())))
)

; IsBiner : PohonBiner tidak kosong -> boolean
; IsBiner(P) true jika P mengandung sub pohon kiri dan sub pohon kanan : (//L A R\\)
(defun IsBiner (P)
	(and (not (equal (Akar P) '())) (not (equal (Left P) '())) (not (equal (Right P) '())))
)

; IsExistLeft : PohonBiner tidak kosong -> boolean
; IsExistLeft (P) true jika P mengandung sub pohon kiri
(defun IsExistLeft (P)
	(and (not (equal (Akar P) '())) (not (equal (Left P) '())))
)

; IsExistRight : PohonBiner tidak kosong -> boolean
; IsExistRight(P) true jika P mengandung sub pohon kanan
(defun IsExistRight (P)
	(and (not (equal (Akar P) '())) (not (equal (Right P) '())))
)

; OPERASI LAIN

; NbElmt : PohonBiner -> integer > 0
; NbElmt(P) memberikan banyaknya elemen dari pohon P. P boleh kosong.
(defun NbElmt (P)
	(if (IsTreeEmpty P)
		0
		(if (IsOneElmt P)
			1
			(+ 1 (NbElmt (Left P)) (NbElmt (Right P)))
		)
	)
)

; NbDaun : PohonBiner -> integer > 0
; NbDaun (P) memberikan banyaknya daun dari pohon P. P boleh kosong.
(defun NbDaun (P)
	(if (IsTreeEmpty P)
		0
		(NbDaun1 P)
	)
)

; NbDaun1 : PohonBiner -> integer > 1
; Prekondisi : PohonBiner P tidak kosong
; NbDaun1 (P) memberikan banyaknya daun dari pohon P
(defun NbDaun1 (P)
	(if (IsOneElmt P)
		1
		(cond 
			((IsBiner P) (+ (NbDaun1 (Left P)) (NbDaun1 (Right P))))
			((IsUnerLeft P) (NbDaun1 (Left P)))
			((IsUnerRight P) (NbDaun1 (Right P)))
		)
	)
)

; RepPrefix: PohonBiner -> List of elemen
; RepPrefix (P) memberikan representasi linier (dalam bentuk list), dengan urutan elemen list
; sesuai dengan urutan penulisan pohon secara prefix. P boleh kosong.
(defun RepPrefix (P)
	(if (IsOneElmt P)
		(cons (Akar P) nil)
		(cons (Akar P) (append (RepPrefix (Left P)) (RepPrefix (Right P))))
	)
)

; IsMember : PohonBiner, elemen -> boolean
; IsMember(P,X) mengirimkan true jika ada node dari P yang bernilai X
(defun IsMember (P x)
	(if (IsOneElmt P)
		(equal (Akar P) x)
		(or (equal (Akar P) x) (IsMember (Left P) x) (IsMember (Right P) x))
	)
)

; IsSkewLeft: PohonBiner -> boolean
; IsSkewLeft(P) mengirimkan true jika P adalah pohon condong kiri
(defun IsSkewLeft (P)
	(if (IsTreeEmpty P)
		nil
		(if (IsOneElmt P)
			T
			(if (IsExistRight P)
				nil
				(IsSkewLeft (Left P))
			)
		)
	)
)

; IsSkewRight : PohonBiner -> boolean
; IsSkewRight(P) mengirimkan true jika P adalah pohon condong kiri
(defun IsSkewRight (P)
	(if (IsTreeEmpty P)
		nil
		(if (IsOneElmt P)
			T
			(if (IsExistLeft P)
				nil
				(IsSkewLeft (Right P))
			)
		)
	)
)

; LevelOfX: PohonBiner, elemen -> integer
; LevelOfX(P,X) Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon
; biner P
(defun LevelOfX (P x)
	(if (IsMember P x)
		(if (IsOneElmt P)
			(if (equal (Akar P) x) 1 0)
			(if (equal (Akar P) x)
				1
				(if (IsMember (Left P) x)
					(+ 1 (LevelOfX (Left P) x))
					(+ 1 (LevelOfX (Right P) x))
				)
			)
		)
		0
	)
)

; AddDaunTerkiri : PohonBiner, elemen -> PohonBiner
; AddDaunTerkiri(P,X): mengirimkan pohon biner P yang telah bertambah simpulnya, dengan X
; sebagai simpul daun terkiri
(defun AddDaunTerkiri (P x)
	(if (IsTreeEmpty P)
		(list x)
		(list (Akar P) (AddDaunTerkiri (Left P) x) (Right P))
	)
)

; AddDaun : PohonBiner tidak kosong, elemen, elemen, boolean -> PohonBiner
; AddDaun (P,X,Y,Kiri) : P bertambah simpulnya, dengan Y sebagai anak 
; kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri)
; Prekondisi : X adalah salah satu daun Pohon Biner P
(defun AddDaun (P x y Kiri)
	(if Kiri
		(if (equal (Akar P) x) ; basis
			(list (Akar P) (list y) nil)
			(if (IsMember (Left P) x) ; check & rekurens
				(list (Akar P) (AddDaun (Left P) x y Kiri) (Right P))
				(list (Akar P) (Left P) (AddDaun (Right P) x y Kiri))
			)
		)
		(if (equal (Akar P) x) ; basis
			(list (Akar P) nil (list y))
			(if (IsMember (Left P) x) ; check & rekurens
				(list (Akar P) (AddDaun (Left P) x y Kiri) (Right P))
				(list (Akar P) (Left P) (AddDaun (Right P) x y Kiri))
			)
		)
	)
)

; DeleteDaunTerkiri: PohonBiner tidak kosong -> PohonBiner
; DeleteDaunTerkiri(P) menghasilkan P’ dengan P’ adalah pohon biner P yang telah
; dihapus daun terkirinya
(defun DeleteDaunTerkiri (P)
	(if (IsOneElmt P)
		nil
		(if (IsExistLeft P) 
			(list (Akar P) (DeleteDaunTerkiri (Left P)) (Right P)) 
			(list (Akar P) (Left P) (DeleteDaunTerkiri (Right P)))
		)
	)
)

; UnitDeleteDaunTerkiri: PohonBiner tidak kosong -> integer
; UnitDeleteDaunTerkiri(P) menghasilkan suatu integer yang merupakan daun terkiri dari
; pohon P
(defun UnitDeleteDaunTerkiri (P)
	(if (IsOneElmt P)
		(Akar P)
		(if (IsExistLeft P) 
			(UnitDeleteDaunTerkiri (Left P)) 
			(UnitDeleteDaunTerkiri (Right P))
		)
	)
)

; DelDaunTerkiri: PohonBiner tidak kosong -> <PohonBiner, elemen>
; DelDaunTerkiri(P) menghasilkan pasangan <P’,X> dengan P’ adalah pohon biner P yang telah
; dihapus daun terkirinya dan X adalah nilai yang semula disimpan pada daun terkiri P yang
; dihapus
(defun DelDaunTerkiri (P)
	(list (DeleteDaunTerkiri P) (UnitDeleteDaunTerkiri P))
)

; DelDaun : PohonBiner tidak kosong, elemen -> PohonBiner
; DelDaun(P,X) dengan X adalah salah satu daun P, menghasilkan sebuah pohon tanpa X
(defun DelDaun (P x)
	(if (IsOneElmt P)
		nil
		(if (IsMember (Left P) x)
			(list (Akar P) (DelDaun (Left P) x) (Right P))
			(list (Akar P) (Left P) (DelDaun (Right P) x))
		)
	)
)

; NbOcc : PohonBiner, elemen → elemen
; NbOcc (P,X) menghasilkan banyaknya kemunculan X di pohon biner P
(defun NbOcc (P X)
	(if (or (IsTreeEmpty P) (not (IsMember P X))) ; kasus khusus
		0
		(if (IsOneElmt P)
			(if (equal (Akar P) X)
				1
				0
			)
			(if (equal (Akar P) X)
				(+ 1 (NbOcc (Left P) X) (NbOcc (Right P) X))
				(+ (NbOcc (Left P) X) (NbOcc (Right P) X))
			)
		)
	)
)

; MaxElmt : PohonBiner tidak kosong → elemen
; MaxElmt(P) menghasilkan nilai maksimum dari elemen-elemen pohon biner P
; yang tidak kosong
(defun MaxElmt (P)
	(if (IsOneElmt P) ;basis
		(Akar P)
		(if (IsBiner P) ; rekurens
			(if (and (< (Akar P) (MaxElmt (Left P))) (< (MaxElmt (Right P)) (MaxElmt (Left P))))
				(MaxElmt (Left P))
				(if (and (> (Akar P) (MaxElmt (Left P))) (> (Akar P) (MaxElmt (Right P))))
					(Akar P)
					(MaxElmt (Right P))
				)
			)
			(if (IsUnerLeft P)
				(if (< (Akar P) (MaxElmt (Left P)))
					(MaxElmt (Left P))
					(Akar P)
				)
				(if (< (Akar P) (MaxElmt (Right P)))
					(MaxElmt (Right P))
					(Akar P)
				)
			)
		)
	)
)

; NbMax : PohonBiner tidak kosong → < elemen, integer > 0 >
; NbMax(P) menghasilkan pasangan nilai <max, nb> dengan max adalah nilai maksimum dari 
; elemen-elemen pohon biner P yang tidak kosong dan nb adalah banyaknya kemunculan max 
; di pohon biner P
(defun NbMax (P)
	(list (MaxElmt P) (NbOcc P (MaxElmt P)))
)