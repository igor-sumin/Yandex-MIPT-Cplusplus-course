#include "responses.h"

std::ostream& operator<<(std::ostream& os, const BusesForStopResponse& r) {
	// Реализуйте эту функцию
	if(r.buses.empty()) {
		os << "No stop";
	} else {
		for(const std::string& bus : r.buses) {
			os << bus << " ";
		}	
	}

	return os;
}

std::ostream& operator<<(std::ostream& os, const StopsForBusResponse& r) {
	// Реализуйте эту функцию
	if(r.stops_for_buses.empty()) {
		os << "No bus";
	} else {
		bool first = true;
		for(const auto& st : r.stops_for_buses) {
			if(!first) {
				os << std::endl;
			} first = false;
			
			os << "Stop " << st.first << ": ";
			if(st.second.size() == 1) {
				os << "no interchange";
			} else {
				for(const auto& bus : st.second) {
					if (bus != r.bus) {
			        	os << bus << " ";
			        }
				}
			}
		}
	}

	return os;
}

std::ostream& operator<<(std::ostream& os, const AllBusesResponse& r) {
	// Реализуйте эту функцию
	if (r.buses_to_stops.empty()) {
		os << "No buses";
	} else {
		bool first = true;
		for (const auto& bus_item : r.buses_to_stops) {
			if(!first) {
				os << std::endl;
			} first = false;

			os << "Bus " << bus_item.first << ": ";
			for (const std::string& stop : bus_item.second) {
				os << stop << " ";
			} 
		}
	}

	return os;
}