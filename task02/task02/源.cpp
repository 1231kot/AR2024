#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// �������ṹ��
struct Matrix {
    size_t rows;
    size_t cols;
    double* data;
};
typedef struct Matrix Matrix;


// �����쳣����ö������
enum MatrixExceptionLevel { ERROR, WARNING, INFO, DEBUG };


// �쳣������
void matrix_exception(const enum MatrixExceptionLevel level, char* msg)
{
    if (level == ERROR) {
        printf("ERROR: %s\n", msg);
    }
    else if (level == WARNING) {
        printf("WARNING: %s\n", msg);
    }
}


// �����ڴ���亯��
Matrix matrix_allocate(const size_t rows, const size_t cols)
{
    Matrix A = { 0, 0, NULL };

    if (rows == 0 || cols == 0) {
        return (Matrix) { rows, cols, NULL };
    }

    // ����ڴ�����Ƿ�����
    size_t num_elements = rows * cols;
    if (num_elements > SIZE_MAX / sizeof(double)) {
        matrix_exception(ERROR, "Memory allocation overflow.");
        return A;
    }

    A.data = (double*)malloc(rows * cols * sizeof(double));
    if (A.data == NULL) {
        matrix_exception(ERROR, "Memory allocation failed.");
        return A;
    }

    A.rows = rows;
    A.cols = cols;
    return A;
}


// �����ڴ��ͷź���
void matrix_free(Matrix* A)
{
    free(A->data);
    *A = (Matrix){ 0, 0, NULL };
}


// ����Ԫ�����ú���
void matrix_set(const Matrix A, const double* values)
{
    if (A.data == NULL) {
        matrix_exception(ERROR, "Matrix data is NULL, cannot set elements.");
        return;
    }
    memcpy(A.data, values, A.rows * A.cols * sizeof(double));
}


// �����ӡ����
void matrix_print(const Matrix A)
{
    for (size_t row = 0; row < A.rows; ++row) {
        for (size_t col = 0; col < A.cols; ++col) {
            printf("%2.3f ", A.data[row * A.cols + col]);
        }
        printf("\n");
    }
    printf("\n");
}


// �����������
Matrix matrix_subtract(const Matrix A, const Matrix B)
{
    if (!(A.cols == B.cols && A.rows == B.rows)) {
        matrix_exception(ERROR, "matrix_subtract: Incompatible matrix sizes.");
        return (Matrix) { 0, 0, NULL };
    }

    Matrix C = matrix_allocate(A.rows, A.cols);
    if (C.data == NULL) {
        matrix_exception(ERROR, "matrix_subtract: Memory allocation for result failed.");
        return C;
    }

    for (size_t idx = 0; idx < A.rows * A.cols; ++idx) {
        C.data[idx] = A.data[idx] - B.data[idx];
    }
    return C;
}


int main()
{
    Matrix A, B, C;

    // ��������ڴ�
    A = matrix_allocate(3, 3);
    if (A.data == NULL) {
        matrix_exception(ERROR, "main: Matrix A allocation failed.");
        return 1;
    }
    B = matrix_allocate(3, 3);
    if (B.data == NULL) {
        matrix_exception(ERROR, "main: Matrix B allocation failed.");
        matrix_free(&A);
        return 1;
    }

    // ���þ���Ԫ��
    matrix_set(A, (double[]) {
        5.0, 4.0, 3.0,
            2.0, 1.0, 0.0,
            9.0, 8.0, 7.0
    });
    matrix_set(B, (double[]) {
        1.0, 1.0, 1.0,
            2.0, 2.0, 2.0,
            3.0, 3.0, 3.0
    });

    // ��ӡ����
    matrix_print(A);
    matrix_print(B);

    // �����������
    C = matrix_subtract(A, B);
    if (C.data != NULL) {
        matrix_print(C);
        matrix_free(&C);
    }

    // �ͷž����ڴ�
    matrix_free(&A);
    matrix_free(&B);

    return 0;
}