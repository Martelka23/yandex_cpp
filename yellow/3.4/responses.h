#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct BusesForStopResponse {
  // Наполните полями эту структуру
  bool exist = false;
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& bfs);

struct StopsForBusResponse {
  // Остановки для конкретного автобуса
  bool exist = false;
  string bus;
  vector<string> stops;
  map<string, vector<string>> stops_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& sfb);

struct AllBusesResponse {
  // Наполните полями эту структуру
  bool exist = false;
  map<string, vector<string>> bus_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& bfs);
