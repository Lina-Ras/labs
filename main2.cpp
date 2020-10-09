//варыянт 2!!

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream fin("some.txt");
    ofstream fout("result.txt");

    int n=1;
    while(!fin.eof()){

        for (int l = 0; l < n; l++) {

            char str[300];
            char str_with_number[300];

            fin.getline(str, 300, '\n');

            cout << str << endl;

            int i = 0;  //номер последнего введённого символа
            while (str[i] != '\000') {
                i++;
            }
            i--;

            int s = 0; //подсчёт количетсва переставленных символов +1 (те s-1=кол-во переставленных символов)

            while ((i >= 0) && (i != (s - 2))) {
                int j = 0; //порядковый номер сивола в str_with_number (там хранится один элемент из всей строки str)
                bool f = true; // true - элемент является числом.
                while (str[i] !=
                       ' ') { //выделение одного элемента в str_with_number. Проверка: является ли элемент числом
                    if ((str[i] < 47) || (str[i] > 58)) {
                        f = false;
                    }
                    str_with_number[j] = str[i];
                    i--;
                    j++; //после выхода из while - РАЗМЕР элемента в str_with_number
                }
                if (f) {
                    for (
                            int k = (i - 1);
                            k >= 0; --k) { //сдвиг всех символов вправо на место "удаляемого" элемента
                        str[k + j + 1] = str[k];
                    }
                    str[j] = ' ';
                    for (
                            int k = 0;
                            k < j;
                            k++) { //возвращение элемента из str_with_number в начало str
                        str[k] = str_with_number[j - k - 1];
                    }

                    i += (j + 1); //возвращение позиции i для проверки следующего за "удаленным" элемента
                    s += (j + 1);
                }
                i--; //пропуск пробела
            }
            cout << "RESULT: " << str << endl;
            cout<<endl;
            if(fout){
                fout<<str<<'\n';
            }
        }
        n++;
    }
    fout.close();
    fin.close();



    return 0;
}

