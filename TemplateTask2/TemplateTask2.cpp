#include <iostream>
#include <tuple> 
#include <Windows.h>

template<class T>
class table
{
private:
    class table_two;
    int row, col;
    table_two* arrint;
    class table_two
    {
    public:
        int* sarrint;
        table_two() {}
        table_two(int size)
        {
            sarrint = new int[size];
        }
        int& operator [] (int i)
        {
            return sarrint[i];
        }
    };

public:
    table(const int rows, const int cols)
    {
        rows < 1 ? row = 1 : row = rows;
        cols < 1 ? col = 1 : col = cols;
        arrint = new table_two[row];
        for (int i = 0; i < row; i++)
        {
            arrint[i] = table_two(col);
        }
    }

    table& operator=(const table& copyFrom) {
        if (this != &copyFrom) {
            for (int i = 0; i < row; i++)
            {
                if (arrint[i].sarrint != nullptr)
                    delete[](arrint[i].sarrint);
            }
            if (arrint != nullptr)
                delete[] arrint;
            this->row = copyFrom.row;
            this->col = copyFrom.col;
            this->arrint = new table_two[row];
            for (int i = 0; i < row; i++)
            {
                this->arrint[i] = table_two(col);
            }
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    this->arrint[i][j] = copyFrom.arrint[i][j];
                }
            }
            return *this;
        }
        else {
            return *this;
        }
    }

    table(const table& copyFrom) {
        this->row = copyFrom.row;
        this->col = copyFrom.col;
        this->arrint = new table_two[row];
        for (int i = 0; i < row; i++)
        {
            this->arrint[i] = table_two(col);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                this->arrint[i][j] = copyFrom.arrint[i][j];
            }
        }
    }

    table_two& operator [] (int i)
    {
        return arrint[i];
    }

    std::tuple<int, int> Size() const 
    {
        return std::make_tuple(row, col);
    }

    ~table()
    {
        for (int i = 0; i < row; i++)
        {
            if (arrint[i].sarrint != nullptr)
                delete[](arrint[i].sarrint);
        }
        if (arrint != nullptr)
            delete[] arrint;
    }
};

int main()
{
    setlocale(LC_ALL, "RU");

    auto test = table<int>(2, 3);
    auto new_test = test;

    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; 

    int rows, cols;
    std::tie(rows, cols) = test.Size(); 
    std::cout << "Строки: " << rows << ", Столбцы: " << cols << std::endl; // выводит размеры таблицы

    return 0;
}
