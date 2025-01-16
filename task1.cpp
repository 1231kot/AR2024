#include <stdio.h>

typedef long long int Money;

// è�Ľṹ��
struct Cat {
    Money catfood;
    int life_cat;
};

// ��Ѻ����ṹ��
struct Mortgage {
    Money mortgage;
    Money month_mortgage;
};

// ��Ա�ṹ��
struct Person {
    Money salary;
    Money expenses;
    Money flat;
    Money rent_flat;
    Money account;
    struct Cat person_cat;
    struct Mortgage person_mortgage;
};

struct Person Bob;
struct Person Alice;

// ��ʼ�� Bob ����Ϣ
void Bob_init()
{
    // ��ʼ�� Bob ���˻������ʡ��ճ��������ⷿ����
    Bob.account = 1200000;
    Bob.salary = 300000;
    Bob.expenses = 40000;
    Bob.rent_flat = 35000;
    // Ϊ�˱���δ������Ϊ����δʹ�õĳ�Ա��ʼ��Ϊ 0
    Bob.flat = 0;
    Bob.person_cat.catfood = 0;
    Bob.person_cat.life_cat = 0;
    Bob.person_mortgage.mortgage = 0;
    Bob.person_mortgage.month_mortgage = 0;
}


// ��ʼ�� Alice ����Ϣ
void Alice_init()
{
    // ��ʼ�� Alice ���˻������ʡ��ճ�������������ֵ��
    Alice.account = 1200000;
    Alice.salary = 300000;
    Alice.expenses = 40000;
    Alice.flat = 13000000;
    Alice.person_cat.catfood = 7000;
    Alice.person_cat.life_cat = 15;

    // �����Ѻ�������ÿ�»����
    Alice.person_mortgage.mortgage = Alice.flat;
    Alice.person_mortgage.mortgage -= Alice.account;
    Alice.person_mortgage.mortgage *= 1.2;
    Alice.account = 0;
    Alice.person_mortgage.month_mortgage = Alice.person_mortgage.mortgage / (30 * 12);
}


// ������Ա�Ĺ���
void update_salary(struct Person* person, const int month, const int year)
{
    person->account += person->salary;
    if (month == 1) {
        person->salary *= 1.06;
    }
}


// ������Ա���ճ�����
void update_expenses(struct Person* person, const int month, const int year)
{
    person->account -= person->expenses;
    if (month == 1) {
        person->expenses *= 1.06;
    }
}


// ������Ա���ⷿ����
void update_rent_flat(struct Person* person, const int month, const int year)
{
    if (person->rent_flat != 0) {
        person->account -= person->rent_flat;
        if (month == 1) {
            person->rent_flat *= 1.06;
        }
    }
}


// ������Ա�Ĵ��
void update_deposit(struct Person* person, const int month, const int year)
{
    person->account *= 1 + (0.2 / 12);
}


// ���� Alice �ķ�����ֵ
void update_flat(struct Person* person, const int month, const int year)
{
    if (month == 1) {
        person->flat *= 1.06;
    }
}


// ���� Alice �ĵ�Ѻ�����
void update_mortgage(struct Person* person)
{
    person->account -= person->person_mortgage.month_mortgage;
}


// ���� Alice ����è����
void update_cat(struct Person* person, const int month, const int year)
{
    if (month == 1) {
        person->person_cat.catfood *= 1.06;
    }
    if ((year >= 2027) && (year <= (2027 + person->person_cat.life_cat))) {
        person->account -= person->person_cat.catfood;
    }
}


// ģ�����״��
void simulation()
{
    int month = 1;
    int year = 2024;
    // �� 2024 �� 1 �¿�ʼģ�⣬ֱ�� 2054 �� 1 ��
    while (!(month == 1 && year == 2054)) {
        update_salary(&Bob, month, year);
        update_expenses(&Bob, month, year);
        update_rent_flat(&Bob, month, year);
        update_deposit(&Bob, month, year);

        update_salary(&Alice, month, year);
        update_expenses(&Alice, month, year);
        update_flat(&Alice, month, year);
        update_mortgage(&Alice);
        update_deposit(&Alice, month, year);
        update_cat(&Alice, month, year);

        month++;
        if (month == 13) {
            month = 1;
            year++;
        }
    }
}


// ��ӡ�ȽϽ��
void print()
{
    if (Alice.account + Alice.flat < Bob.account) {
        printf("Bob will save up for a flat faster");
    }
    else {
        printf("Alice will pay off the mortgage faster");
    }
}


int main()
{
    Alice_init();
    Bob_init();

    simulation();

    print();
    return 0;
}