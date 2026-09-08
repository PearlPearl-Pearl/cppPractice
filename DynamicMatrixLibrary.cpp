#include <iostream>

struct Matrix{
    int rows;
    int cols;
    double* data;
};

Matrix create_matrix(int rows, int cols);
void set(Matrix& A, int row, int col, double value);
double get(const Matrix& A, int row, int col);
void print(const Matrix& A);
Matrix add(const Matrix& A, const Matrix& B);
void scale(Matrix& A, double c);
Matrix matvec(const Matrix& A, const Matrix& x);

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

void print(const Matrix& A){
    int total_cols = A.cols;
    int total_rows = A.rows;

    for (int i = 0; i < total_rows; i++){
        for (int j = 0; j < total_cols; j++){
            std::cout << A.data[total_cols*(i)+(j)] << ' ';
        }
        std::cout << '\n';
    }
}

Matrix add(const Matrix& A, const Matrix& B){
    int A_cols = A.cols;
    int A_rows = A.rows;
    int B_cols = B.cols;
    int B_rows = B.rows;
    Matrix result;

    if (A_cols == B_cols && A_rows == B_rows){
        result.cols = A_cols;
        result.rows = A_rows;
        result.data = new double[A_cols*A_rows];
        for (int i = 0; i < A_rows; i++){
            for (int j = 0; j < A_cols; j++){
                result.data[A_cols*(i)+(j)] = A.data[A_cols*(i)+(j)] + B.data[B_cols*(i)+(j)];
            }
        }
        return result;
    }
    else{
        result.cols = 0;
        result.rows = 0;
        return result;
    }
}

void scale(Matrix& A, double c){
    int A_rows = A.rows;
    int A_cols = A.cols;

    for (int i = 0; i < A_rows*A_cols; i++){
        A.data[i] *= c;
    }
}

Matrix matvec(const Matrix& A, const Matrix& x){
    int A_rows = A.rows;
    int A_cols = A.cols;
    int x_rows = x.rows;
    int x_cols = x.cols;
    Matrix result;

    if (A_cols == x_rows){
        result.cols = 1;
        result.rows = A_rows;
        result.data = new double[A_rows];

        for (int i = 0; i < A_rows; i++){
            double row_data = 0;
            for (int j = 0; j < A_cols; j++){
                row_data += A.data[A_cols*(i)+j]*x.data[j];
            }
            result.data[i] = row_data;
        }
        return result;
    }
    else if (A_rows == x_cols){
        result.rows = 1;
        result.cols = A_cols;
        result.data = new double[A_cols];

        for (int i = 0; i < A_cols; i++){
            double col_data = 0;
            for (int j = 0; j < A_rows; j++){
                col_data += x.data[j]*A.data[(A_cols*j)+i];
            }
            result.data[i] = col_data;
        }
        return result;
    }
}