#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���������ṹ��
struct Vector {
    size_t size;
    double* data;
};
typedef struct Vector Vector;

// �����쳣����ö������
enum VectorExceptionLevel { ERROR, WARNING, INFO, DEBUG };

// �����쳣������
void vector_exception(const enum VectorExceptionLevel level, const char* msg)
{
    if (level == ERROR) {
        printf("ERROR: %s", msg);
    }
    if (level == WARNING) {
        printf("WARNING: %s", msg);
    }
}

// ����ָ����С�������ڴ�ռ�
Vector vector_allocate(const size_t size)
{
    Vector v = { 0, NULL };
    if (size == 0) {
        return v;
    }
    v.data = (double*)malloc(size * sizeof(double));
    if (v.data == NULL) {
        vector_exception(ERROR, "Memory allocation failed for vector.");
        return v;
    }
    v.size = size;
    return v;
}

// �ͷ������ڴ�ռ�
void vector_free(Vector* v)
{
    free(v->data);
    v->size = 0;
    v->data = NULL;
}

// ��������Ԫ��ֵ����ӺϷ��Լ��
void vector_set(Vector v, const double* values)
{
    if (v.size > 0 && values != NULL) {
        memcpy(v.data, values, v.size * sizeof(double));
    }
}

// ��ӡ����Ԫ��
void vector_print(const Vector v)
{
    for (size_t i = 0; i < v.size; ++i) {
        printf("%2.3f ", v.data[i]);
    }
    printf("\n");
}

// ������ӣ�v1 += v2
int vector_add(Vector v1, Vector v2)
{
    if (v1.size != v2.size) {
        vector_exception(ERROR, "vector_add: Incompatible sizes.");
        return 0;
    }
    for (size_t i = 0; i < v1.size; ++i) {
        v1.data[i] += v2.data[i];
    }
    return 1;
}

int main()
{
    Vector v1, v2;
    double arr1[] = { 1., 2., 3., 4. };
    double arr2[] = { 5., 6., 7., 8. };
    v1 = vector_allocate(4);
    v2 = vector_allocate(4);
    vector_set(v1, arr1);
    vector_set(v2, arr2);
    vector_print(v1);
    vector_print(v2);

    vector_add(v1, v2);
    vector_print(v1);

    vector_free(&v1);
    return 1;
}