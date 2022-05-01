#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
  string type;
  is >> type;
  if (type == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count;
    is >> stop_count;
    q.stops.clear();
    for (int i = 0; i < stop_count; i++)
    {
      string stop;
      is >> stop;
      q.stops.push_back(stop);
    }
  } else if (type == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (type == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (type == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
  bool exist = false;
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& bfs) {
  // Реализуйте эту функцию
  if (bfs.exist)
  {
    bool first = true;
    for (const string& bus : bfs.buses)
    {
      if (!first)
        os << " " << bus;
      else
      {
        os << bus;
        first = false;
      }
    }
  } else
  {
    os << "No stop";
  }
  
  return os;
}

struct StopsForBusResponse {
  // Остановки для конкретного автобуса
  bool exist = false;
  string bus;
  vector<string> stops;
  map<string, vector<string>> stops_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& sfb) {
  // Остановки для конкретного автобуса
  if (sfb.exist)
  {
    bool first = true;
    for (const auto& stop : sfb.stops)
    {
      if (!first)
        os << endl;
      else
        first = false;
      // vector<string> buses = GetBusesForStop(stop).buses;
      // buses.erase(remove(buses.begin(), buses.end(), sfb.bus), buses.end());
      if (sfb.stops_buses.at(stop).size())
      {
        os << "Stop " << stop << ":";
        for (const string bus : sfb.stops_buses.at(stop))
          os << " " << bus;
      } else
      {
        os << "Stop " << stop << ": no interchange";
      }
    }
  } else
  {
    os << "No bus";
  }
  
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
  bool exist = false;
  map<string, vector<string>> bus_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& bfs) {
  // Реализуйте эту функцию
  if (bfs.exist)
  {
    bool first = true;
    for (const auto& [bus, stops] : bfs.bus_stops)
    {
      if (!first)
        os << endl;
      else
        first = false;
      os << "Bus " << bus << ":";
      for (const string& stop : stops)
        os << " " << stop;
    }
  } else
  {
    os << "No buses";
  }
  
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Добавление автобуса и его остановок
    bus_stops[bus] = stops;

    for (const string& stop : stops)
      if (!count(begin(stop_buses[stop]), end(stop_buses[stop]), bus))
        stop_buses[stop].push_back(bus);
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    BusesForStopResponse bfs;

    if (stop_buses.count(stop))
    {
      bfs.exist = true;
      for (const string& bus : stop_buses.at(stop))
        bfs.buses.push_back(bus);
    }

    return bfs;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Остановки для конкретного автобуса
    StopsForBusResponse sfb;
    sfb.bus = bus;
    if (bus_stops.count(bus))
    {
      sfb.exist = true;
      for (const string& stop : bus_stops.at(bus))
      {
        sfb.stops_buses[stop] = GetBusesForStop(stop).buses;
        sfb.stops_buses[stop].erase(remove(sfb.stops_buses[stop].begin(), 
          sfb.stops_buses[stop].end(), bus), sfb.stops_buses[stop].end());
      }
      sfb.stops = bus_stops.at(bus);
    }

    return sfb;
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse all_bus;
    if (bus_stops.size())
    {
      all_bus.bus_stops = bus_stops;
      all_bus.exist = true;
    }
    
    return all_bus;
  }
private:
  map<string, vector<string>> bus_stops;
  map<string, vector<string>> stop_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
