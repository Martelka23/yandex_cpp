#pragma once

#include "date.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Database
{
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& os) const;
    // template <typename P> int RemoveIf(P predicate);
    // template <typename P> vector<string> FindIf(P predicate) const;

    // Удаление событий удовлетворяющих условию
    template <typename P> int RemoveIf(P predicate)
    {
        int count = 0;
        // Удаление и подсчёт удалённых событий
        for (auto& info : database) {
            auto it = end(info.second);
            it = stable_partition(begin(info.second), end(info.second), 
                [predicate, info](const string& s) { return !predicate(info.first, s); });
            count += end(info.second) - it;
            while (it < end(info.second)) {
                dataset[info.first].erase(*it);
                info.second.erase(it);
            }
        }
        vector <Date> for_del;
        // Удаление пустых дат
        for (auto& info : database)
            if (info.second.empty())
                for_del.push_back(info.first);
        for (auto& date : for_del) {
            database.erase(date);
            dataset.erase(date);
        }

        return count;
    }

    // Поиск событий удовлетворяющих условию
    template <typename P> vector<string> FindIf(P predicate) const
    {
        vector<string> answer;
        for (const pair<Date, vector<string>>& info : database)
            for (const string& event : info.second)
                if (predicate(info.first, event)) {
                    stringstream os;
                    os << info.first << " " << event;
                    answer.push_back(os.str());
                }
        
        return answer;
    }


    string Last(const Date& date) const;

private:
    map<Date, set<string>> dataset;
    map<Date, vector<string>> database;
};