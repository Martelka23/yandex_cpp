#include "responses.h"



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



ostream& operator << (ostream& os, const AllBusesResponse& bfs) {
  // Реализуйте эту функцию
  if (bfs.exist)
  {
    bool first = true;
    for (const auto elem : bfs.bus_stops)
    {
      if (!first)
        os << endl;
      else
        first = false;
      os << "Bus " << elem.first << ":";
      for (const string& stop : elem.second)
        os << " " << stop;
    }
  } else
  {
    os << "No buses";
  }
  
  return os;
}

