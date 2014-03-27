; NIM/Nama	: Riva Syafri Rachmatullah
; Nama File	: P02_13512036_13090903.lsp
; Topik		: Program pengecek tanggal
; Tanggal	: Senin, 9 September 2013
; Deskripsi	: Program yang memeriksa dan mengoperasi tipe date

; type Hr : integer [1...31]
; Definisi ini hanyalah untuk “menamakan” type integer dengan nilai 
; tertentu supaya mewakili hari, sehingga jika dipunyai suatu nilai
; integer, kita dapat memeriksa apakah nilai integer tersebut mewakili
; Hari yang absah

; type Bln : integer [1...12]
; Definisi ini hanyalah untuk “menamakan” type integer dengan daerah 
; nilai tertentu supaya mewakili bulan

; type Thn : integer > 0
; Definisi ini hanyalah untuk “menamakan“ type integer dengan daerah 
; nilai tertentu supaya mewakili tahun

; type date <d : Hr, m : Bln, y : Thn>
; <d,m,y> adalah tanggal d bulan m tahun y

; DEFINISI DAN SPESIFIKASI SELEKTOR
; Day : date -> Hr
; Day (date) memberikan hari d dari D yang terdiri dari <d,m,y>

; Month : date -> Bln
; Month (date) memberikan bulan m dari D yang terdiri dari <d,m,y>

; Year : date -> Thn
; Year (date) memberikan tahun y dari D yang terdiri dari <d,m,y>

;DEFINISI DAN SPESIFIKASI KONSTRUKTOR
; MakeDate : Hr, Bln, Thn -> date
; MakeDate (d,m,y) membentuk date dari tanggal d, bulan m, dan tahun y

;DEFINISI DAN SPESIFIKASI OPERATOR/FUNGSI LAIN TERHADAP DATE
; NextDay : date -> date
; NextDay(date): menghitung date yang merupakan keesokan hari dari date D 
; yang diberikan

; Yesterday : date -> date
; Yesterday(date): Menghitung date yang merupakan 1 hari sebelum date D
; yang diberikan

; NextNDay : date, integer -> date
; NextNDay(date,N) : Menghitung date yang merupakan N hari sesudah dari 
; date D yang diberikan

; HariKe: date -> integer [1..365]
; HariKe (date) : Menghitung jumlah hari terhadap 1 Januari pada tahun D.y, dengan
; memperhitungkan apakah D.y adalah tahun kabisat

; MaxDay: date -> integer
; MaxDay (date) : Menentukan jumlah hari maksimum yang ada pada suatu
; bulan yang ditentukan.

; NumOfDays : 2 date -> integer
; NumOfDays (D1,D2) menghasilkan sebuah integer yang merupakan selisih 
; hari antara D1 dan D2 dengan Prekondisi D1 selalu sebelum atau sama
; dengan D2

;DEFINISI DAN SPESIFIKASI PREDIKAT
; IsEqD?: 2 date -> boolean
; IsEqD?(D1,D2) benar jika d1=d2, mengirimkan true jika D1.d=D2.d dan 
; D1.m=D2.m dan D1.y=D2.y.

; IsBefore? : 2 date -> boolean
; IsBefore?(D1,D2) benar jika D1 adalah “sebelum” D2

; IsAfter? : 2 date -> boolean
; IsAfter?(D1,D2) benar jika D1 adalah “sesudah” D2

; IsKabisat? : integer > 0 -> boolean
; IsKabisat?(a) true jika tahun a lebih besar 0 dan tahun kabisat: 
; habis dibagi 4 tetapi tidak habis dibagi 100, atau habis dibagi 400

; IsDateValid? : 3 integer -> boolean
; IsDateValid? (d,m,y) mengembalikan nilai true jika d, m, y membentuk
; date yang valid. Definisi date yang valid adalah jika elemen hari (d)
; bernilai antara 1 dan 31, tergantung pada bulan dan apakah tahun 
; kabisat atau bukan, elemen bulan (m) bernilai antara 1 dan 12,
; dan elemen tahun (y) bernilai lebih dari 0.

(defun Day (date)
	(car date)
)

(defun Month (date)
	(car (cdr date))
)

(defun Year (date)
	(car (cdr (cdr date)))
)

(defun MakeDate (d m y)
	(if (IsDateValid? d m y)
		(cons d (cons m (cons y nil)))
		nil
	)
)

(defun IsEqD? (D1 D2)
	(and (= (Day D1) (Day D2)) (= (Month D1) (Month D2)) (= (Year D1) (Year D2)))
)

(defun IsBefore? (D1 D2)
	(cond
		((= (Year D1) (Year D2)) (cond
									((= (Month D1) (Month D2)) (cond
																	((< (Day D1) (Day D2)) T)
																	((>= (Day D1) (Day D2)) nil)
																)
									)
									((< (Month D1) (Month D2)) T)
									((> (Month D1) (Month D2)) nil)
								)
		)
		((<(Year D1)(Year D2)) T)
		((>(Year D1)(Year D2)) nil)
	)
)

(defun IsAfter? (D1 D2)
	(cond
		((= (Year D1) (Year D2)) (cond
									((= (Month D1) (Month D2)) (cond
																	((<= (Day D1) (Day D2)) nil)
																	((> (Day D1) (Day D2)) T)
																)
									)
									((< (Month D1) (Month D2)) nil)
									((> (Month D1) (Month D2)) T)
								)
		)
		((< (Year D1) (Year D2))nil)
		((> (Year D1) (Year D2)) T)
	)
)


(defun IsKabisat? (Thn)
	(if (> Thn 0)
		(or (and (= (mod Thn 4) 0) (/= (mod Thn 100) 0)) (= (mod Thn 400) 0))
		nil
	)
)

(defun IsDateValid? (d m y)
	(cond
		((and (IsKabisat? y) (> y 0)) 
			(cond 
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
				(t nil)
			)
		)
		((and (not (IsKabisat? y)) (> y 0))
			(cond 
				((= m 2) (and (>= d 1) (<= d 28)))
				; untuk bulan februari di bukan tahun kabisat
				((or (= m 1) (= m 3) (= m 5) (= m 7) (= m 8) (= m 10) (= m 12))
					(and (>= d 1) (<= d 31))
					; untuk bulan yang jumlah harinya 31
				)
				((or (= m 2) (= m 4) (= m 6) (= m 9) (= m 11))
					(and (>= d 1) (<= d 30))
					; untuk bulan yang jumlah harinya 30
				)
				(t nil)
			)
		)
		(t nil)
	)
)

(defun MaxDay (date)
	(if (IsKabisat? (Year date)) 
		(cond
			((= (Month date) 2) 29)
			((or (= (Month date) 1) (= (Month date) 3) (= (Month date) 5) (= (Month date) 7) (= (Month date) 8) (= (Month date) 10) (= (Month date) 12)) 31)
			((or (= (Month date) 2) (= (Month date) 4) (= (Month date) 6) (= (Month date) 9) (= (Month date) 11)) 30)
		)
		(cond
			((= (Month date) 2) 28)
			((or (= (Month date) 1) (= (Month date) 3) (= (Month date) 5) (= (Month date) 7) (= (Month date) 8) (= (Month date) 10) (= (Month date) 12)) 31)
			((or (= (Month date) 2) (= (Month date) 4) (= (Month date) 6) (= (Month date) 9) (= (Month date) 11)) 30)
		)
	)
)

(defun NextDay (date)
	(if (= (Day date) (MaxDay date)) 
		(cond 
			((= (Month date) 12) 
				(MakeDate 1 1 (+ (Year date) 1))
			)
			((/= (Month date) 12)
				(MakeDate 1 (+ (Month date) 1) (Year date))
			)
		)			
		(MakeDate (+ (Day date) 1) (Month date) (Year date))
	) 
)

(defun Yesterday (date)
	(if (= (Day date) 1) 
		(cond 
			((= (Month date) 1) 
				(MakeDate 31 12 (- (Year date) 1))
			)
			((/= (Month date) 1)
				(MakeDate (MaxDay (list 1 (- (Month date) 1) (Year date))) (- (Month date) 1) (Year date))
			)
		)			
		(MakeDate (- (Day date) 1) (Month date) (Year date))
	)
)

(defun NextNDay (date N)
	(cond 
		((> N 1) (NextNDay (NextDay date) (- N 1)))
		((= N 1)(NextDay date))
		((= N 0) date)
		((< N 0) nil)
	)
)

(defun HariKe (date)
	(cond 
		((= (Month date) 1) (Day date))
		((/= (Month date) 1) (HariKe (list (+ (Day date) (MaxDay (list 1 (- (Month date) 1) (Year date)))) (- (Month date) 1) (Year date))))
	)
)

(defun NumOfDays (D1 D2)
	(if (equal D1 D2)
		0
		(+ (NumOfDays D1 (Yesterday D2)) 1)
	)
)

; APLIKASI

; => (setq a (makedate 1 2 3))
; <1,2,3>
; => (HariKe a)
; => 32