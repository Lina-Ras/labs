#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int mod(int a){
    if (a>=0)
        return a;
    else
        return -a;
}

int main() {
    const int cn=200;
    int a[cn];
    srand( time(NULL) );

    int n;
    cout << "Enter n: " << endl;
    cin>>n;
    if (n>cn){
        cout << "n is incorrect. Try again";
        return 0;
    }

    cout << "Chose a way to build a massive: 1 - by hands, 2 - make it random " << endl;
    int ch;
    cin >> ch;
    switch (ch){

        case 1:{
            cout << "Enter a[i]:" << endl;
            for (int i=0; i<n; ++i)
                cin>>a[i];
            break;
        }

        case 2:{
            int b,v;
            cout << "Enter b:";
            cin >> b;
            cout << "Enter v: ";
            cin >> v;
            for (int i=0; i<n; ++i) {
                a[i]=rand()%v+b;
                cout << a[i] << " ";
            }
            break;
        }

        default:{
            cout << "That is incorrect.";
            return 0;
        }
    }


    cout << endl;

    //-	минимальный по модулю элемент массива;
    int m;
    m=0;
    for (int i = 1; i < n; ++i){
        if(mod(a[m])>mod (a[i])){
            m=i;
        }
    }
    cout << "min: " << endl;
    for (int i = 0; i < n; ++i){
        if( mod(a[i]) == mod(a[m]) ){
            cout << a[i] << ", i=" << i <<endl;
        }
    }

    //-	сумму элементов массива, расположенных после последнего нулевого элемента.

    int l=-1, summ=0;
    for (int i = 0; i < n; ++i){
        if(a[i]==0){
            l=i;
        }
    }
    for (int i=l; i < n; ++i){
        summ+=a[i];
    }

    //вывод суммы и "ошибок"
    if (l==(n-1)){
        cout << "No digits after 0" << endl;
    }
    else{
        if(l==-1){
            cout << "There is no 0." << endl;
        }
        else{
            cout << "summ - "<< summ << endl;
        }
    }


    //-Преобразовать массив таким образом, чтобы в первой его половине располагались все  элементы с четными номерами ,
    // а во второй половине — с нечетными. Порядок следования элементов не изменять.

    cout << "example: ";
    for (int i = 0; i < n; ++i){
        if(i%2==0){
            cout << a[i] << "  ";
        }
    }
    for (int i = 0; i < n; ++i){
        if(i%2==1){
            cout << a[i] << "  ";
        }
    }

    cout<<endl;

    l=0;
    int p=n, s;
    if(n%2==0) {
        p = n - 1;
    }
    while (l<p) {
        for (int i = (l + 1); i < (p - 1); i += 2) {
            s = a[i];
            a[i] = a[i + 1];
            a[i + 1] = s;
        }
        l++;
        p--;
    }

    cout << "final:   ";
    for (int i=0; i<n; i++){
        cout<<a[i]<<"  ";
    }
    return 0;
}
