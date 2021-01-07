#pragma once

#include <map>
#include <string>
#include <vector>
#include <ostream>

struct BusesForStopResponse {
	// Наполните полями эту структуру
	std::vector<std::string> buses;
};
std::ostream& operator<<(std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	std::string bus;
	std::vector<std::pair<std::string, std::vector<std::string>>> stops_for_buses;
};
std::ostream& operator<<(std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	// Наполните полями эту структуру
	std::map<std::string, std::vector<std::string>> buses_to_stops;
};
std::ostream& operator<<(std::ostream& os, const AllBusesResponse& r);