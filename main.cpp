/*
COMSC-210 | Lab 27 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

void OutputVillager(pair<string, tuple<int,string,string>> villager);

int main() {
    // declarations
    //{Name, (friendshipLevel, species, catchphrase)}
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerData["Audie"] = {4, "Beagle", "Woof"};
    villagerData["Raymond"] = {7, "Siamese Cat", "Meowzers"};
    villagerData.insert({"Marshal", {10, "Bee", "Ya like jazz?"}});

    // access the map using a range-based for loop
    cout << "Villagers and their information:" << endl;
    for (auto pair : villagerData) {
        OutputVillager(pair);
    }

    // access the map using iterators
    cout << "\nVillagers and their information (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
                                               it != villagerData.end(); ++it) {
        OutputVillager(*it);
    }

    // delete an element
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s information: ";
        OutputVillager(*it);
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}

/**
 * Outputs a villager's information.
 * @param villager Villager information, formatted as a pair containing the villager's name, and a typle containing friendship level, species, and catchphrase 
 * 
 */
void OutputVillager(pair<string, tuple<int,string,string>> villager) {
    cout << villager.first << ": "
             << "[" 
             << get<0>(villager.second) << ", "
             << get<1>(villager.second) << ", "
             << get<2>(villager.second)
             << "]" << endl;
}