#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
//zmiana1testNiko
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	int col=mat->c;
	int row=mat->r;
	if(row!=col) return 2;
	if(x->r!=row) return 2;
	if(b->r!=row) return 2;
	for(int i=r-1;i>=0;i--)
	{
		double s=0;
		for(int j=i+1;j<col;j++)
			s += mat->data[i][j] * x->data[i][0];
		if(mat->data[i][i]==0) return 1;
		x->data[i][0]= ( (b->data[i][0]-s) / mat->data[i][i] );
	}
	

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

				//Petla niepotrzebna
	return 0;
}


