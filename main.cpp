#include <iostream>
using namespace std;


    int A[100][100];
    int M, N;


    void function(int r, int c) {


        if (r < 0 || r >= M || c < 0 || c >= N || A[r][c] == 0) { 

            
            return;       // проверяет, не выходит ли оно за пределы матрицы, если 0, то прекращает работу
        }


        A[r][c] = 0;   // посетили клетку


        function(r + 1, c); // вниз
        function(r - 1, c); // верх
        function(r, c+1); // вправо
        function(r, c-1); // влево


    }



    int main() {
        setlocale(LC_ALL, "Russian");
        cout << "Сколько столбцов(M) и строк (N) в вашем листе?";
        cin >> M >> N;        // заполняю матрицу данными 

        for (int i = 0; i < M; i++) {

            for (int j = 0; j < N; j++) {

                cin >> A[i][j];
            }


        }


        int count = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {

                if (A[i][j] == 1) {
                    count++;        // если нашли 1, то увеличиваем счетчик (новый кусок)
                    function(i, j);
                }
            }
        }

        cout << "Количество кусков " << count << endl;
        return 0;
    }


    


