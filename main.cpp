//В задании память для исходной матрицы выделяется динамически в объеме, минимально необходимом для хранения данных, размерности массивов не превосходят 10.
//Необходимо:

//-	построчно вывести на консоль введенную матрицу;
//-	расчеты выполнять так, будто матрица хранится целиком. Для обращения к элементам написать соответствующие функции;
//-	вывести результаты расчетов.

//3.В целочисленной квадратной матрице a[i, j] = 0 для элементов, лежащих выше побочной диагонали. Требуется определить:
//– сумму элементов в тех строках, которые не содержат отрицательных элементов;
//– минимум среди элементов диагоналей, параллельных главной диагонали матрицы, не включая диагональ.

#include <iostream>
#include <iomanip>

using namespace std;


int obr (int **a, int n, int i, int j){
    if ((j + i) > (n - 2)) {
        return a[i][j];
    }
    else {
        return 0;
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;
    if((n>10)||(n<1)){
        cout << "error";
        return 0;
    }

    int **a =new int*[n];
    for(int i=0; i<n; ++i){
        a[i]= new int[n];
    }

    cout << "Enter " << double(1+n)/2*n <<" elements: " << endl;
    for (int i=0; i<n; ++i){
        for (int j=n-1; (j+i)>(n-2); --j){
            cin >> a[i][j];
        }
    }

    cout << "Massiv: " << endl;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if((j+i)>(n-2)){
                cout << setw(6) << obr(a,n,i,j);
            }
            else{
                cout << setw(6)<< 0;
            }
        }
        cout << endl;
    }

    for (int i=0; i<n; ++i){
        int summ=0;
        for (int j=n-1; (j+i)>(n-2); --j){
            if(obr(a,n, i,j)<0){
                summ =-1;
                j=-10;
            }
            else{
                summ+=obr(a,n,i,j);
            }
        }
        if (summ!=-1){
        cout << "Summ of elements in "<< i << " line is " << summ << endl;
        }
    }

    int mini=0;
    int minj=0;
    for (int i=0; i<n; ++i){
        for (int j=n-1; (j+i)>(n-2); --j){
            if(i!=j){
                if(obr(a, n,mini, minj)>obr(a,n,i,j)){
                    mini = i;
                    minj =j;
                }
            }
        }
    }

    cout << "Minimum: " << obr (a, n,mini,minj) << endl;
    cout << obr(a,n, 0, 1);


    for(int i=0; i<n; ++i){
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
