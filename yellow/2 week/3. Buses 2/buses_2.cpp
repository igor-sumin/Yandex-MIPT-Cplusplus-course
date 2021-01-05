#include <string>
#include <iostream>
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

// QueryType MoveType(QueryType qt) { 
// 	return static_cast<QueryType>(static_cast<int>(qt) + 1);
// }

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator>>(istream& is, Query& q) {
	// Реализуйте эту функцию
	string data;
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
		string unk = "unknown command: " + data;
		throw runtime_error(unk);
	}

	return is;
}

struct BusesForStopResponse {
	// Наполните полями эту структуру
	vector<string> buses;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r) {
	// Реализуйте эту функцию
	if(r.buses.empty()) {
		os << "No stop";
	} else {
		for(const string& bus : r.buses) {
			os << bus << " ";
		}	
	}

	return os;
}

struct StopsForBusResponse {
	// Наполните полями эту структуру
	string bus;
	vector<pair<string, vector<string>>> stops_for_buses;
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r) {
	// Реализуйте эту функцию
	if(r.stops_for_buses.empty()) {
		os << "No bus";
	} else {
		for(const auto& st : r.stops_for_buses) {
			os << "Stop " << st.first << ": ";
			if(st.second.size() == 1) {
				os << "no interchange";
			} else {
				for(const auto& bus : st.second) {
					if (bus != r.bus) {
			        	os << bus << " ";
			        }
				}
			} os << endl;
		}
	}

	return os;
}

struct AllBusesResponse {
	// Наполните полями эту структуру
	map<string, vector<string>> buses_to_stops;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r) {
	// Реализуйте эту функцию
	if (r.buses_to_stops.empty()) {
		os << "No buses";
	} else {
		for (const auto& bus_item : r.buses_to_stops) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			} os << endl;
		}
	}

	return os;
}

class BusManager {
private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
public:
	// BusManager() {}

	void AddBus(const string& bus, const vector<string>& stops) {
		// Реализуйте этот метод
		buses_to_stops.insert(make_pair(bus, stops));
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		// Реализуйте этот метод
		if (stops_to_buses.count(stop) == 0) {
			return BusesForStopResponse{vector<string>()};
		}

		return BusesForStopResponse{stops_to_buses.at(stop)};
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		// Реализуйте этот метод
		vector<pair<string, vector<string>>> result;

		if (buses_to_stops.count(bus) > 0) {
			for (const auto& stop : buses_to_stops.at(bus)) {
		    	result.push_back(make_pair(stop, stops_to_buses.at(stop)));
		    }
		}

		return StopsForBusResponse{bus, result};
	}

	AllBusesResponse GetAllBuses() const {
		// Реализуйте этот метод
		return AllBusesResponse{buses_to_stops};
	}
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

// 10
// ALL_BUSES
// BUSES_FOR_STOP Marushkino
// STOPS_FOR_BUS 32K
// NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
// NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
// BUSES_FOR_STOP Vnukovo
// NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
// NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
// STOPS_FOR_BUS 272
// ALL_BUSES