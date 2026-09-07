#include <iostream>

struct Matrix{
    int rows;
    int cols;
    double* data;
};

Matrix create_matrix(int rows, int cols);
void set(Matrix& A, int row, int col, double value);
double get(const Matrix& A, int row, int col);

int main(){

    Matrix A = create_matrix(3, 2);
    set(A, 3,1, 2);


    return 0;
}

Matrix create_matrix(int rows, int cols){
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = new double[rows*cols];

    return matrix;
}

void set(Matrix& A, int row, int col, double value){
    A.data[A.cols*(row-1)+(col-1)] = value;
}

double get(const Matrix& A, int row, int col){
    return A.data[A.cols*(row-1)+(col-1)];
}
