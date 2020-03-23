#include <clocale>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void FillInc (int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=o+1;
}

void BSearch1(int X, int *A, int n,  int &C1) {
    int L = 0, R = n-1, m;
    C1=0;
    while (L <= R) {
        m = (L + R) / 2;
        C1++;
        if (A[m] == X)	{ return;}
        else {C1++;
            if (A[m]<X) L = m+1;
            else R=m-1;
        }
    }

}

void BSearch2(int X, int *A, int n, int &C2) {
    int L = 0, R = n-1, m;

    C2=0;
    while (L < R) {
        m = (L + R) / 2;
        C2++;
        if (A[m] < X)	L = m + 1;
        else R = m;
    }
    C2++;
    if (A[R] == X) {return;}
    else { return;}
}

void BSearchAll1(int X, int *A, int n, int &C1) {
    int L = 0, R = n-1, m, i;
    C1=0;
    while (L <= R) {
        m = (L + R) / 2;
        C1++;
        if (A[m] == X)	{
            i=m;
            while(A[m]==X) {m--; C1++;}
            while(A[i]==X) {i++; C1++;}
            return;}
        else {C1++;
            if (A[m]<X) L = m+1;
            else R=m-1;
        }
    }

}

void BSearchAll2(int X, int *A, int n, int &C2) {
    int L = 0, R = n-1, m, i;
    C2=0;
    while (L < R) {
        m = (L + R) / 2;
        C2++;
        if (A[m] < X)	L = m + 1;
        else R = m;
    }
    C2++;
    if (A[R] == X) {
        while(A[m]==X) {m++; C2++;}
        return;}
    else { return;}
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, mas[1000];
    int  x, C1, C2;
    srand(time(NULL));
    printf("+-----+------------+-------------+\n");
    printf("|  n  |Cf  Iversion|Cf  IIversion|\n");
    printf("+-----+------------+-------------+\n");
    FillInc(mas,1000);
    for(n=100;n<1001;n=n+100){
        x=rand()%n-1;
        x=mas[x];
        BSearch1(x, mas, n, C1);
        BSearch2(x, mas, n, C2);
        printf("|%5d|%12d|%13d|\n",n,C1,C2);
        printf("+-----+------------+-------------+\n");
    }
    printf("\n");
    printf("+-----+---------------+----------------+\n");
    printf("|  n  |Cf All Iversion|Cf All IIversion|\n");
    printf("+-----+---------------+----------------+\n");
    for(n=100;n<1001;n=n+100){
        x=rand()%n-1;
        x=mas[x];
        BSearchAll1(x, mas, n, C1);
        BSearchAll2(x, mas, n, C2);
        printf("|%5d|%15d|%16d|\n",n,C1,C2);
        printf("+-----+---------------+----------------+\n");
    }


}
