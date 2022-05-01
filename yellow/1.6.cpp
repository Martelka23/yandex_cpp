#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// Возведение вектора в квадрат
template <typename T>
vector<T> Sqr(vector<T> v);
// Возведение словаря в квадрат
template <typename key, typename value>
map<key, value> Sqr(map<key, value> d);
// Возведение пары в квадрат
template <typename first, typename second>
pair<first, second> Sqr(pair<first, second> p);

/*
Функция должна возвращать копию исходного контейнера, модифицировав его следующим образом:
для vector элементы нужно возвести в квадрат;
для map в квадрат нужно возвести только значения, но не ключи;
для pair в квадрат нужно возвести каждый элемент пары.
*/

// Возведение чисела в квадрат
template <typename T>
T Sqr(T a)
{
    return a * a;
}
// Возведение вектора в квадрат
template <typename T>
vector<T> Sqr(vector<T> v)
{
    for (auto& x : v)
        x = Sqr(x);
    return v;
}
// Возведение словаря в квадрат
template <typename key, typename value>
map<key, value> Sqr(map<key, value> d)
{
    for (auto& x : d)
        x.second = Sqr(x.second);
    return d;
}
// Возведение пары в квадрат
template <typename first, typename second>
pair<first, second> Sqr(pair<first, second> p)
{
    p.first = Sqr(p.first);
    p.second = Sqr(p.second);

    return p;
}