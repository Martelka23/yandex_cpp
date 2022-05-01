// класс Database, который представляет собой базу данных, — 
// вы должны сами создать его публичный интерфейс, основываясь на том, 
// как он используется в функции main;

#include "database.h"

// Добавление события в БД
void Database::Add(const Date& date, const string& event) {
    if (dataset.count(date) == 0) {
        database[date].push_back(event);
        dataset[date].insert(event);
    }
    else if (dataset[date].count(event) == 0) {
        database[date].push_back(event);
        dataset[date].insert(event);
    }
}

// Вывод всех событий на экран
void Database::Print(ostream& os) const {
    for (const pair<Date, vector<string>>& info : database)
        for (const string& event : info.second)
            os << info.first << " " << event << endl;
}

// Вывод последнего события в поток
string Database::Last(const Date& date) const
{
    ostringstream os;
    auto it = database.upper_bound(date);
    if (it == begin(database))
        os << "No entries";
    else {
        --it;
        os << it->first << " " << *(end(it->second) - 1);
    }

    return os.str();
}