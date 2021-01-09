#include "gauss.h"
#include <stdlib.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int col = mat->c;
	int row = mat->r;
	for(int i = 0; i < row - 1; i++) {
		double maks = abs(mat->data[i][i]);
		int index = i;
		for(int j = i+1; j < row; j++) {
			if(abs(mat->data[j][i]) > maks) {
				maks = abs(mat->data[j][i]);
				index = j;
			}
		}
		if(maks > abs(mat->data[i][i])) {
			for(int j = 0; j < row; j++) {
				double temp = mat->data[i][j];
				mat->data[i][j] = mat->data[index][j];
				mat->data[index][j] = temp;
			}
			 
			double temp = b->data[i][0];
			b->data[i][0] = b->data[index][0];
			b->data[index][0] = temp;
		}


		for(int j = i+1; j < row; j++) {
			if(mat->data[i][i] == 0) return 1;
			double wsp = mat->data[j][i]/mat->data[i][i];
			for(int k = 0; k < col; k++)
				mat->data[j][k] -= mat->data[i][k]*wsp;
			b->data[j][0] -= b->data[i][0]*wsp;
		}
	}
	return 0;
}

