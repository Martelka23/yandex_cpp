#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
public:
    // Пустой конструктор
    Matrix()
    {
        matrix.assign(0, vector<int>(0));
        rows = 0;
        columns = 0;
    }
    // Конструктор создания матрицы заданного размера
    Matrix(const int& m, const int& n)
    {
        Reset(m, n);
    }
    // Изменение размеров матрицы и очистка всех элементов
    void Reset(const int& m, const int& n)
    {
        if (m < 0 || n < 0)
            throw out_of_range("wrong range");
        if (m * n == 0)
        {
            rows = 0;
            columns = 0;
        } else
        {
            rows = m;
            columns = n;    
        }
        
        matrix.assign(rows, vector<int>(columns));
    }
    // Возвращение элемента матрицы
    int At(const int& m, const int& n) const
    {
        if (m < 0 || n < 0 || m >= GetNumRows() || n >= GetNumColumns())
            throw out_of_range("wrong range");
        return matrix[m][n];
    }
    int& At(const int& m, const int& n)
    {
        if (m < 0 || n < 0 || m >= GetNumRows() || n >= GetNumColumns())
            throw out_of_range("wrong range");
        return matrix[m][n];
    }
    // Возвращение количества строк
    int GetNumRows() const
    {
        return rows;
    }
    // Возвращение количества столбцов
    int GetNumColumns() const
    {
        return columns;
    }

private:
    vector<vector<int>> matrix;
    int rows, columns;
};

// Оператор проверки на равенство
bool operator==(const Matrix& a, const Matrix& b)
{
    if (!a.GetNumRows() && !b.GetNumRows())
        return true;
    if (a.GetNumRows() != b.GetNumRows() || a.GetNumColumns() != b.GetNumColumns())
        return false;
    for (int i = 0; i < a.GetNumRows(); i++)
        for (int j = 0; j < a.GetNumColumns(); j++)
            if (a.At(i, j) != b.At(i, j))
                return false;
    return true;
}
// Оператор сложения двух матриц
Matrix operator+(const Matrix& a, const Matrix& b)
{
    if (!a.GetNumRows() && !b.GetNumRows())
        return Matrix();
    if (a.GetNumRows() != b.GetNumRows() || a.GetNumColumns() != b.GetNumColumns())
        throw invalid_argument("error");
    Matrix c(a.GetNumRows(), a.GetNumColumns());
    for (int i = 0; i < a.GetNumRows(); i++)
        for (int j = 0; j < a.GetNumColumns(); j++)
            c.At(i, j) = a.At(i, j) + b.At(i, j);
    return c;
}
// Оператор ввода матрицы
istream& operator>>(istream& input, Matrix& a)
{
    int m, n;
    input >> m >> n;
    a.Reset(m, n);
    // if (!m && !n)
    //     return input;
    for (int i = 0; i < a.GetNumRows(); i++)
        for (int j = 0; j < a.GetNumColumns(); j++)
        {
            int tmp;
            input >> tmp;
            a.At(i, j) = tmp;
        }
    return input;
}
// Оператор вывода матрицы
ostream& operator<<(ostream& output, const Matrix& a)
{
    if (!a.GetNumRows())
    {
        output << 0 << " " << 0;
        return output;
    }
    output << a.GetNumRows() << " " << a.GetNumColumns() << endl;
    for (int i = 0; i < a.GetNumRows(); i++)
    {
        for (int j = 0; j < a.GetNumColumns(); j++)
        {
            output << a.At(i, j) << " ";
        }
        output << endl;
    }
    return output;
}

void test(){
  const string teststr{
    "1\n"
    
    "1 0\n"
    //"6 4 -1 9 8\n"
    //"12 1 2 9 -5\n"
    //"-4 0 12 8 6\n"
    "5 0\n"
    //"6 4 -1 9 8\n"
    //"12 1 2 9 -5\n"
    //"-4 0 12 8 6\n"
  };
  stringstream input(teststr);
  int t;
  input>>t;
  while(t--){
    Matrix one;
  Matrix two;

  input >> one >> two;
  cout << one + two << endl;
  one.Reset(1, 1);
  std::cout << boolalpha << (one == two) << '\n';
  }
}

int main() {
  test();
  return 0;
}