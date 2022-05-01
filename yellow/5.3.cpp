#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

// Базовый класс
class Figure
{
public:
    Figure(const string& n, const double& p, const double& g = 0, const double& t = 0)
        : name(n), a(p), b(g), c(t) {}
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;

    const string name;
    const double a;
    const double b;
    const double c;
};

// Классы потомки
class Triangle : public Figure
{
public:
    Triangle(const string& n, const double& p, const double& a, const double& t) : Figure(n, p, a, t) {}
    string Name() const override { return name; }
    double Perimeter() const override { return a + b + c; }
    double Area() const override 
    {
        double p = Perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Rect : public Figure
{
public:
    Rect(const string& n, const double& p, const double& a) : Figure(n, p, a) {}
    string Name() const override { return name; }
    double Perimeter() const override { return 2 * (a + b); }
    double Area() const override { return a * b; }
};

class Circle : public Figure
{
public:
    Circle(const string& n, const double& p) : Figure(n, p) {}
    string Name() const override { return name; }
    double Perimeter() const override { return 2 * 3.14 * a; }
    double Area() const override { return 3.14 * a * a; }
};


shared_ptr<Figure> CreateFigure(istringstream& is)
{
    string type;
    is >> type;
    if (type == "TRIANGLE")
    {
        double a, b, c;
        is >> a >> b >> c;
        
        return make_shared<Triangle>(type, a, b, c);
    } else if (type == "RECT")
    {
        double a, b;
        is >> a >> b;
        return make_shared<Rect>(type, a, b);
    } else if (type == "CIRCLE")
    {
        double a;
        is >> a;
        return make_shared<Circle>(type, a);
    }
}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}