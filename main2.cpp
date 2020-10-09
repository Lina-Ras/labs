//2 варыянт!!

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("some.txt");
    ofstream fout("result.txt");

    char str[300], str_with_number[300];

    if (fin.is_open()){
        fin.getline(str,300);
    }
    fin.close();

    cout<<str<<endl;

    int i=0;  //номер последнего введённого символа
    while (str[i]!='\000'){
        i++;
    }
    i--;

    int s=0; //подсчёт количетсва переставленных символов +1 (те s-1=кол-во переставленных символов)

    while ((i>=0)&&(i!=(s-2))){
        int j=0; //порядковый номер сивола в str_with_number (там хранится один элемент из всей строки str)
        bool f=true; // true - элемент является числом.
        while(str[i]!=' '){ //выделение одного элемента в str_with_number. Проверка: является ли элемент числом
            if ((str[i]<47) || (str[i]>58)){
                f=false;
            }
            str_with_number[j] = str[i];
            i--;
            j++; //после выхода из while - РАЗМЕР элемента в str_with_number
        }
        if(f) {
            for (int k = (i-1); k >=0; --k) { //сдвиг всех символов вправо на место "удаляемого" элемента
                str[k+j+1]=str[k];
            }
            str[j]=' ';
            for (int k = 0; k < j; k++) { //возвращение элемента из str_with_number в начало str
                str[k] = str_with_number[j-k-1];
            }

            i+=(j+1); //возвращение позиции i для проверки следующего за "удаленным" элемента
            s+=(j+1);
        }
        i--; //пропуск пробела
    }

    cout<<"RESULT: "<<str<<endl;

    if (fout.is_open()){
        fout<<str;
    }
    fout.close();

    return 0;
}
