#include <stdio.h>

// �����ʾ�������ͱ������������Ϊ��Ԫ��USD��
typedef long long int Money;

// �ṹ���ʾ���������Ϣ
struct Pet {
    Money food;
    int is_healthy;
};

// �ṹ���ʾ���������Ϣ
struct Loan {
    double interest_rate;
    Money loan_amount;
    Money down_payment;
    Money monthly_payment;
};

// �ṹ���ʾ����Ĳ�������������
struct Person {
    Money salary;
    Money account;
    Money grocery;
    Money other_expenses;
    struct Loan loan;
    struct Pet pet;
};

// ȫ�ֱ�����������������Tom
struct Person tom;

// ����ÿ�µĴ�������
void tom_loan_payment() {
    tom.account -= tom.loan.monthly_payment;
}

// �����·ݴ���ʳƷ�ӻ�����
void tom_grocery(const int month) {
    if (month == 1) {
        tom.grocery *= 1.05;  // ÿ��1��ʳƷ�ӻ���������5%
    }
    tom.account -= tom.grocery;
}

// �����·ݴ�����������֧��
void tom_other_expenses(const int month) {
    if (month == 2) {
        tom.account -= 3000;  // 2���ж����һ����������֧��
    }
    tom.account -= tom.other_expenses;
}

// ��ʼ��Tom�ĸ�����������������
void tom_init() {
    tom.account = 800 * 1000;
    tom.salary = 180 * 1000;
    tom.grocery = 8 * 1000;
    tom.other_expenses = 60 * 1000;

    tom.loan.interest_rate = 0.15;
    tom.loan.loan_amount = 12000 * 1000;
    tom.loan.down_payment = 800 * 1000;
    tom.loan.monthly_payment = 90 * 1000;
    tom.account -= tom.loan.down_payment;

    tom.pet.food = 4000;
    tom.pet.is_healthy = 1;
}

// �����·ݺ���ݴ��������صĲ������
void tom_pet(const int month, const int year) {
    if ((month == 10) && (year == 2025)) {
        tom.account -= 25000;  // �����￴���ȴ��֧��
        tom.pet.is_healthy = 0;
    }
    if ((year == 2040) && (month == 6)) {
        tom.pet.is_healthy = 1;
        tom.account -= 2000;  // ���｡����ط���
    }
    if (month == 1) {
        tom.pet.food *= 1.08;  // 1�³���ʳƷ��������8%
    }
    if (tom.pet.is_healthy == 1) {
        tom.account -= tom.pet.food;
    }
}

// ��������ز���
void tom_salary(const int month, const int year) {
    if (month == 12) {
        tom.account += tom.salary;
    }
    if (month == 1) {
        tom.salary *= 1.05;  // 1�¹�������5%
    }
    tom.account += tom.salary;
}

// ģ�⺯����ģ��һ��ʱ�䷶Χ��Tom�Ĳ���״���仯
void simulation() {
    int month = 7;
    int year = 2024;

    while (!((month == 7) && (year == 2024 + 30))) {
        tom_salary(month, year);
        tom_loan_payment();
        tom_grocery(month);
        tom_other_expenses(month);
        tom_pet(month, year);

        month++;
        if (month == 13) {
            month = 1;
            year++;
        }
    }
}

// ���Tom���˻�������
void tom_print() {
    printf("Tom account = %lld \n", tom.account);
}

int main() {
    tom_init();
    simulation();
    tom_print();
    return 0;
}