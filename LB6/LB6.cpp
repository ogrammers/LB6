// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

int example1() {
    setlocale(LC_ALL, "Ru");
    int matrix[3][4] = {
        {1, 5, 6, 4},
        {2, 9, 8, 7},
        {3, 12, 11, 10}
    };

    int K;
    cout << "Введите K: ";
    cin >> K;

    int targetrow = -1;

    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == K) {
            targetrow = i;
            break;
        }
    }

    if (targetrow == -1) {
        cout << "Строка с таким номером не найдена\n";
        return 0;
    }

    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 4 - i; j++) {
            if (matrix[targetrow][j] > matrix[targetrow][j + 1]) {
                for (int r = 0; r < 3; r++) {
                    int temp = matrix[r][j];
                    matrix[r][j] = matrix[r][j + 1];
                    matrix[r][j + 1] = temp;
                }
            }
        }
    }

    cout << "\nРезультат:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
};

void example2() {
    setlocale(LC_ALL, "Ru");

    string s;
    int N;

    if (cin.peek() == '\n') {
        cin.ignore();
    }

    do {
        cout << "Введите строку (не пустую): ";
        getline(cin, s);
    } while (s.empty());

    cout << "Введите длину N: ";
    cin >> N;

    int count = 0;
    int pos = 0;

    while (pos < s.length()) {

        while (pos < s.length() && s[pos] == ' ') {
            pos++;
        }
        if (pos >= s.length()) break;

        int endPos = s.find(" ", pos);

        if (endPos == string::npos) {
            endPos = s.length();
        }

        int wordLength = endPos - pos;

        if (wordLength != N) {
            count++;
        }

        pos = endPos + 1;
    }

    cout << "Количество слов с длиной, не равной " << N << ": " << count << "\n";
}


int main()
{
    example1();
    example2();
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
