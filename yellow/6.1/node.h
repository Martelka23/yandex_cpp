#pragma once

#include "date.h"

#include <memory>

using namespace std;

// Операции сравнения
enum class Comparison
{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

// Логические операции
enum class LogicalOperation
{
    Or,
    And
};

// Базовый класс
class Node
{
public:
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};

// Классы потомки

// Сравнение с пустотой
class EmptyNode : public Node
{
public:
    bool Evaluate(const Date& date, const string& event) override;
};

// Сравнение даты
class DateComparisonNode : public Node
{
public:
    DateComparisonNode(const Comparison& c, const Date& d) 
        : event_cmp(c), event_date(d) {}

    bool Evaluate(const Date& date, const string& event) override;

private:
    const Comparison event_cmp;
    const Date event_date;
};

// Сравнение события
class EventComparisonNode : public Node
{
public:
    EventComparisonNode(const Comparison& c, const string& s) 
        : event_cmp(c), event_info(s) {}

    bool Evaluate(const Date& date, const string& event) override;

private:
    const Comparison event_cmp;
    const string event_info;
};

// Логические операции
class LogicalOperationNode : public Node
{
public:
    LogicalOperationNode(const LogicalOperation& lgc, 
        const shared_ptr<Node> l, const shared_ptr<Node> r)
            : event_logical_operation(lgc), event_left(l), event_right(r) {}

    bool Evaluate(const Date& date, const string& event) override;

private:
    const LogicalOperation event_logical_operation;
    const shared_ptr<Node> event_left;
    const shared_ptr<Node> event_right;
};