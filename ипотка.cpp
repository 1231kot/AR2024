#include<iostream>//����� �� 300000/���https://calcus.ru/kalkulyator-ipoteki?input=eyJjdXJyZW5jeSI6IlJVQiIsInR5cGUiOiIxIiwiY29zdCI6IjE0MDAwMDAwIiwic3RhcnRfc3VtIjoiMTAwMDAwMCIsInN0YXJ0X3N1bV90eXBlIjoiMSIsInBlcmlvZCI6IjMwIiwicGVyaW9kX3R5cGUiOiJZIiwicGVyY2VudCI6IjE3IiwicGF5bWVudF90eXBlIjoiMSJ9
using namespace std;// ��� 25/��� ����������15/��� ������25/���  ������25/���
 int main(){ //�������� 14���
    setlocale(LC_ALL, "Russian");
    long long Bob, Alice,mes,rashA,rashB,zp,pl,infl,dep,nadbv,stavka,mlnA,tysA,mlnB,tysB,A,B,C,D;
    Bob = 0;
    Alice = 0;
    pl = 185337;//������ �� ������� 185 337
    zp = 300000;
    mes=0; //https://calcus.ru/kalkulyator-ipoteki?input=eyJjdXJyZW5jeSI6IlJVQiIsInR5cGUiOiIxIiwiY29zdCI6IjE0MDAwMDAwIiwic3RhcnRfc3VtIjoiMTAwMDAwMCIsInN0YXJ0X3N1bV90eXBlIjoiMSIsInBlcmlvZCI6IjMwIiwicGVyaW9kX3R5cGUiOiJZIiwicGVyY2VudCI6IjE3IiwicGF5bWVudF90eXBlIjoiMSJ9
    infl = 9;
    rashA=65000;//�����65/��� ��� ��
    rashB=90000;//�����90/��� ��� ��
    dep=1000000;
    nadbv=9;
    stavka=20;
    cout<<"Alice:                Bob:"<<endl;
    for(mes=1;mes<=360;mes++){
      Alice=Alice+zp-rashA-pl;
      Bob=Bob+zp-rashB;
      B=Bob;
      A=Alice;
      while (B/1000>1){
        mlnB=B/1000000;
        B=B%1000000;
        tysB=B/1000;
        B=B%1000;
        }
        while (A/1000>1){
        mlnA=A/1000000;
        A=A%1000000;
        tysA=A/1000;
        A=A%1000;
    }
    if(mes%12==0){cout<<mlnA<<"��� "<<tysA<<"��� "<<A<<"���    "<<mlnB<<"��� "<<tysB<<"��� "<<B<<"���    "<<mes/12<<"-� ���"<<endl;
    zp=zp+(zp/100)*nadbv;
    rashA=rashA+((rashA/100)*infl);
    rashB=rashB+((rashB/100)*infl);
    dep=dep+((dep/100)*(stavka-infl));
    }
    }
    Alice=Alice+13000000;
    Bob=Bob+dep;
    C=Bob-Alice;
    D=Alice-Bob;
      while (C/1000>1){
        mlnB=C/1000000;
        C=C%1000000;
        tysB=C/1000;
        C=C%1000;
        }
        while (D/1000>1){
        mlnA=D/1000000;
        D=D%1000000;
        tysA=D/1000;
        D=D%1000;
    }
    cout<<dep<<endl;//����� ���� ������
if(D>C){cout<<"Alice,� �������� =  "<<mlnA<<"��� "<<tysA<<"��� "<<D<<"��� "<<endl;}
    else{cout<<"Bob,� �������� = "<<mlnB<<"��� "<<tysB<<"��� "<<C<<"��� ";}

    return 0;
}
