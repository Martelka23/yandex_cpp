#include <iostream>
using namespace std;



class Tester
{
public:
    // Запускатор тестов
    template <typename F>
    void RunTest(F func, const string& test_name)
    {
        try
        {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch(const exception& e)
        {
            ++fail_count;
            cerr << e.what() << endl;
        }
    }
    // Деструктор
    ~Tester()
    {
        if (fail_count)
        {
            cerr << fail_count << " unit tests failed. Terminate program." << endl;
            exit(1);
        }
    }
private:
    int fail_count = 0; // Подсчет ошибок

    // Сравнение результатов
    template <typename T, typename U>
    void AssertEqual(const T& t, const U& u)
    {
        if (t != u)
        {
            ostringstream os;
            os << "Assertion failed: " << t << "!=" << u << " Hint: " << hint;
            throw runtime_error(os.str());
        }
    }
};