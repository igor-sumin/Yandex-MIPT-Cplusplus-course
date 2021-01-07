#include "query.h"

std::istream& operator>>(std::istream& is, Query& q) {
	// Реализуйте эту функцию
	std::string data;
	is >> data;

	if(data == "NEW_BUS") {
		q.type = QueryType::NewBus;

		is >> q.bus;
		int count = 0;
		is >> count;

		// Задаем размер вектору
		q.stops.resize(count);
		for(auto& s : q.stops) {
			is >> s;
		}
	}
	else if(data == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if(data == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if(data == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	} 
	else {
		std::string unk = "unknown command: " + data;
		throw std::runtime_error(unk);
	}

	return is;
}