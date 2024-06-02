#include <iostream>
#include <tuple>
#include <Windows.h>

template<class T>
class table {
private:
    class table_two;
    int row, col;
    table_two* arr;

    class table_two {
    public:
        T* sarr;
        table_two() : sarr(nullptr) {}
        table_two(int size) {
            sarr = new T[size];
        }
       

        T& operator [] (int i) {
            return sarr[i];
        }

        const T& operator [] (int i) const {
            return sarr[i];
        }

    };

public:
    table(const int rows, const int cols) {
        row = (rows < 1) ? 1 : rows;
        col = (cols < 1) ? 1 : cols;
        arr = new table_two[row];
        for (int i = 0; i < row; ++i) {
            arr[i] = table_two(col);
        }
    }

    table(const table& copyFrom) {
        row = copyFrom.row;
        col = copyFrom.col;
        arr = new table_two[row];
        for (int i = 0; i < row; ++i) {
            arr[i] = table_two(col);
            for (int j = 0; j < col; ++j) {
                arr[i][j] = copyFrom.arr[i][j];
            }
        }
    }

    table& operator=(const table& copyFrom) {
        if (this != &copyFrom) {
            for (int i = 0; i < row; ++i) {
                delete[] arr[i].sarr;
            }
            delete[] arr;

            row = copyFrom.row;
            col = copyFrom.col;
            arr = new table_two[row];
            for (int i = 0; i < row; ++i) {
                arr[i] = table_two(col);
                for (int j = 0; j < col; ++j) {
                    arr[i][j] = copyFrom.arr[i][j];
                }
            }
        }
        return *this;
    }

    table_two& operator [] (int i) {
        return arr[i];
    }

    const table_two& operator [] (int i) const {
        return arr[i];
    }

    std::tuple<int, int> Size() const {
        return std::make_tuple(row, col);
    }

    ~table() {
        for (int i = 0; i < row; ++i) {
            delete[] arr[i].sarr;
        }
        delete[] arr;
    }

   
};

int main() {

    setlocale(LC_ALL, "RU");

    auto test = table<int>(2, 3);
    auto new_test = test;

    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    int rows, cols;
    std::tie(rows, cols) = test.Size();
    std::cout << "Строки: " << rows << ", Столбцы: " << cols << std::endl;

    return 0;
}
