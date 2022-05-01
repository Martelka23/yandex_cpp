#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "responses.h"


using namespace std;

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const;

  StopsForBusResponse GetStopsForBus(const string& bus) const;

  AllBusesResponse GetAllBuses() const;

private:
  map<string, vector<string>> bus_stops;
  map<string, vector<string>> stop_buses;
};

// Compile error: 
// b"/tmp/submission1j_qsh4n/main.cpp:1:9: warning: #pragma once in main file [-Wpragma-once-outside-header]\n#pragma once\n 
//        ^\nIn file included from /tmp/submission1j_qsh4n/main.cpp:3:
//        \n/tmp/submission1j_qsh4n/bus_manager.h:13:3: fatal error: unknown type name 'BusesForStopResponse'\n 
//         BusesForStopResponse GetBusesForStop(const string& stop) const;\n  ^\n1 warning and 1 error generated.
//         \nIn file included from /tmp/submission1j_qsh4n/full.cpp:1:\n/tmp/submission1j_qsh4n/bus_manager.h:13:3: 
//         fatal error: unknown type name 'BusesForStopResponse'\n  BusesForStopResponse GetBusesForStop(const string& stop) 
//         const;\n  ^\n1 error generated.\n"