#include "Queue.h"
#include <cstdlib>

/* 5 SEKAWAN */
Queue::Queue() {
	N = 0;
	HEAD = 0;
	TAIL = 0;
}

Queue::Queue(int MaxEl) {
	if (MaxEl>0) {
		Q = new infotype[MaxEl+1];
		N = MaxEl;
	} else {
		N = 0;
	}
	HEAD = 0;
	TAIL = 0;
}

Queue::Queue(const Queue& Q) {
	N = Q.N;
	this->Q = new infotype[N+1];
	HEAD = Q.HEAD;
	TAIL = Q.TAIL;
	int i = HEAD;
	while (i != TAIL) {
		this->Q[i] = Q.Q[i];
		i++;
		if (i == N+1) {
			i = 1;
		}
	}
}

Queue& Queue::operator=(const Queue& Q) {
	if (this->Q != NULL) {
		delete this->Q;
	}
	N = Q.N;
	this->Q = new infotype[N+1];
	HEAD = Q.HEAD;
	TAIL = Q.TAIL;
	int i = HEAD;
	while (i != TAIL) {
		this->Q[i] = Q.Q[i];
		i++;
		if (i == N+1) {
			i = 1;
		}
	}
	return *this;
}

Queue::~Queue() {
	delete Q;
}

/*	SELEKTOR */
address Queue::Head() {
	return HEAD;
}

address Queue::Tail() {
	return TAIL;
}

infotype Queue::InfoHead() {
	return Q[HEAD];
}

infotype Queue::InfoTail() {
	return Q[TAIL];
}

int Queue::MaxEl() {
	return N;
}

/*	PREDIKAT */
bool Queue::IsEmpty () {
	return (HEAD == 0 && TAIL == 0);
}

bool Queue::IsFull () {
	return Count() == N;
}

int Queue::Count () {
	/* Kamus */
	/* Algoritma */
	if (IsEmpty()) {
	 	return 0;
	} else if (TAIL > HEAD) {
		return TAIL - HEAD + 1;
	} else if (TAIL < HEAD) {
		return (N + TAIL) - HEAD + 1;
	} else {
		return 1;
	}
}

/*	OPERASI DASAR */
void Queue::Add (infotype X) {
	if (!IsFull()) {
		if (IsEmpty()) {
			HEAD = 1;
			TAIL = 1;
			Q[TAIL] = X;
		} else { 
			TAIL++;
			if (TAIL > N) {
				TAIL = 1;
				Q[TAIL] = X;
			} else {
				Q[TAIL] = X;
			}
		}	
	}
}

infotype Queue::Del () {
	if (!IsEmpty()) {
		int X = Q[HEAD];
		if (Count() == 1) {
			HEAD = 0;
			TAIL = 0;
		} else {
			HEAD++;
			if (HEAD > N) {
				HEAD = 1;
			}
		}
		return X;
	} else {
		return 0;
	}
}

infotype Queue::DelJockey() {
	if (!IsEmpty()) {
		int X = Q[TAIL];
		if (Count() == 1) {
			HEAD = 0;
			TAIL = 0;
		} else {
			TAIL--;
			if (TAIL == 0) {
				TAIL = N;
			}
		}
		return X;
	} else {
		return 0;
	}
}