#include <iostream>
#include <vector>
#include "reconstruct_itinerary.cpp"

using namespace std;

int main() {
    ReconstructItinerary s;

    //vector<vector<string>> in = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    //vector<vector<string>> in = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    //vector<vector<string>> in = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<vector<string>> in = {{"ADL","ANU"},{"ADL","AXA"},{"ADL","CNS"},{"ADL","JFK"},{"ADL","TIA"},{"ANU","ADL"},{"ANU","AUA"},{"ANU","BNE"},{"ANU","BNE"},{"AUA","ADL"},{"AUA","ADL"},{"AUA","EZE"},{"AUA","TIA"},{"AUA","TIA"},{"AXA","ANU"},{"AXA","AUA"},{"AXA","EZE"},{"BNE","ANU"},{"BNE","AXA"},{"BNE","CBR"},{"BNE","EZE"},{"BNE","EZE"},{"CBR","AUA"},{"CBR","JFK"},{"CNS","JFK"},{"EZE","ADL"},{"EZE","ANU"},{"EZE","AUA"},{"EZE","AXA"},{"EZE","HBA"},{"EZE","OOL"},{"EZE","TIA"},{"JFK","AUA"},{"JFK","BNE"},{"JFK","CBR"},{"JFK","EZE"},{"JFK","OOL"},{"OOL","EZE"},{"OOL","JFK"},{"TIA","ADL"},{"TIA","BNE"},{"TIA","BNE"},{"TIA","EZE"},};
    for(auto b : s.findItinerary(in)) {
        cout << b << " ";
    }

    return 0;
}