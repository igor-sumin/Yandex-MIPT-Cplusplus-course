#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

#include "query.h"
#include "bus_manager.h"

int main() {
    int query_count;
    Query q;

    std::cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        std::cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                std::cout << bm.GetBusesForStop(q.stop) << std::endl;
                break;
            case QueryType::StopsForBus:
                std::cout << bm.GetStopsForBus(q.bus) << std::endl;
                break;
            case QueryType::AllBuses:
                std::cout << bm.GetAllBuses() << std::endl;
                break;
        }
    }

    return 0;
}

// Compile error: b"In file included from /tmp/submissiony61g0avz/query.cpp:1:\n/tmp/submissiony61g0avz/query.h:3:17: warning: 
// using directive refers to implicitly-defined namespace 'std'\nusing namespace std;\n                ^\n/tmp/submissiony61g0avz/query.h:14:2: 
// fatal error: unknown type name 'string'\n        string bus;\n        ^\n1 warning and 1 error generated.\n
// In file included from /tmp/submissiony61g0avz/responses.cpp:1:\n/tmp/submissiony61g0avz/responses.h:5:2: fatal error: no template named 'vector'\n        
// vector<string> buses;\n        ^\n1 error generated.\nIn file included from /tmp/submissiony61g0avz/full.cpp:1:\n
// /tmp/submissiony61g0avz/bus_manager.h:5:5: fatal error: no template named 'map'\n    map<string, vector<string>> buses_to_stops;\n    ^
// \n1 error generated.\nIn file included from /tmp/submissiony61g0avz/bus_manager.cpp:1:\n/tmp/submissiony61g0avz/bus_manager.h:5:5: fatal error: no template named 'map'\n
// map<string, vector<string>> buses_to_stops;\n    ^\n1 error generated.\n
