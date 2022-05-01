// классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и
//  LogicalOperationNode — сформировать их иерархию и публичный интерфейс 
//  вам поможет анализ функций main и ParseCondition;

#include "node.h"

// Сравнение с пустотой
bool EmptyNode::Evaluate(const Date& date, const string& event) {
    return true;
}

// Сравнение даты
bool DateComparisonNode::Evaluate(const Date& date, const string& event) {
    vector<int> date_v = { date.GetYear(), date.GetMonth(), date.GetDay() };
    vector<int> event_date_v = { event_date.GetYear(), event_date.GetMonth(), event_date.GetDay() };
    if (event_cmp == Comparison::Less)
        return date_v < event_date_v;
    else if (event_cmp == Comparison::LessOrEqual)
        return date_v <= event_date_v;
    else if (event_cmp == Comparison::Greater)
        return date_v > event_date_v;
    else if (event_cmp == Comparison::GreaterOrEqual)
        return date_v >= event_date_v;
    else if (event_cmp == Comparison::Equal)
        return date_v == event_date_v;
    else if (event_cmp == Comparison::NotEqual)
        return date_v != event_date_v;

    return false;
}

// Сравнение события
bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
    if (event_cmp == Comparison::Less)
        return event < event_info;
    else if (event_cmp == Comparison::LessOrEqual)
        return event <= event_info;
    else if (event_cmp == Comparison::Greater)
        return event > event_info;
    else if (event_cmp == Comparison::GreaterOrEqual)
        return event >= event_info;
    else if (event_cmp == Comparison::Equal)
        return event == event_info;
    else if (event_cmp == Comparison::NotEqual)
        return event != event_info;

    return false;
}

// Сравнение даты
bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {
    if (event_logical_operation == LogicalOperation::And)
        return event_left->Evaluate(date, event) && event_right->Evaluate(date, event);
    else if (event_logical_operation == LogicalOperation::Or)
        return event_left->Evaluate(date, event) || event_right->Evaluate(date, event);

    return false;
}