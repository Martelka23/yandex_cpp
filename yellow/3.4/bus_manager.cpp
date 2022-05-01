#include "bus_manager.h"


void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Добавление автобуса и его остановок
    bus_stops[bus] = stops;

    for (const string& stop : stops)
        if (!count(begin(stop_buses[stop]), end(stop_buses[stop]), bus))
            stop_buses[stop].push_back(bus);
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
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

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse all_bus;
    if (bus_stops.size())
    {
        all_bus.bus_stops = bus_stops;
        all_bus.exist = true;
    }

    return all_bus;
}