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

const int STREAM_IGNORE_CHARS = 100;
const pair<int, int> FRIENDSHIP_RANGE = {1, 10};

void OutputVillager(const pair<string, tuple<int,string,string>> villager);
void OutputMenu();
void IncreaseFriendship(map<string, tuple<int, string, string>>& villagers);
void DecreaseFriendship(map<string, tuple<int, string, string>>& villagers);
void SearchVillager(const map<string, tuple<int, string, string>>& villagers);

int main() {
    // declarations
    //{Name, (friendshipLevel, species, catchphrase)}
    map<string, tuple<int, string, string>> villagerData;
    enum MENU_OPTION {INCREASE_FRIENDSHIP = 1, DECREASE_FRIENDSHIP = 2, SEARCH = 3, EXIT = 4};
    const pair<int, int> MENU_RANGE = {1, 4};
    int option;


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

    do {
        cout << endl;
        OutputMenu();
        //Validate input
        do {
            cout << " > ";
            cin >> option;

            if (cin.fail()) {
                cout << "Menu option must be an integer" << endl;
                option = -1;
            } else if (option < MENU_RANGE.first || option > MENU_RANGE.second) {
                cout << "Menu option is a number between " << MENU_RANGE.first << " and " << MENU_RANGE.second << endl;
            }
            cin.clear();
            cin.ignore(STREAM_IGNORE_CHARS, '\n');
            
        } while (option < MENU_RANGE.first || option > MENU_RANGE.second);

        switch(option) {
            case INCREASE_FRIENDSHIP:
                IncreaseFriendship(villagerData);
                break;
            case DECREASE_FRIENDSHIP:
                DecreaseFriendship(villagerData);
                break;
            case SEARCH:
                SearchVillager(villagerData);
                break;
        }

        cout << "Villager details: " << endl;
        for (auto villager : villagerData) OutputVillager(villager);
        cout << endl;

    } while (option != EXIT);



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
void OutputVillager(const pair<string, tuple<int,string,string>> villager) {
    cout << villager.first << ": "
             << "[" 
             << get<0>(villager.second) << ", "
             << get<1>(villager.second) << ", "
             << get<2>(villager.second)
             << "]" << endl;
}

/**
 * Outputs menu
 */
void OutputMenu() {
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit"                << endl;
}

/**
 * Increases friendship level of all villagers by 1
 * @param villagers Villager data stored as a map formatted {string name, tuple(int friendship, string species, string catchphrase)}
 */
void IncreaseFriendship(map<string, tuple<int, string, string>>& villagers) {
    cout << "Increased friendship of all villagers" << endl;
    //iterate through pairs and increment friendship
    for (auto& pair : villagers) {
        if (get<0>(pair.second) < FRIENDSHIP_RANGE.second) get<0>(pair.second)++;
    }
}

/**
 * Decreases friendship level of all villagers by 1
 * @param villagers Villager data stored as a map formatted {string name, tuple(int friendship, string species, string catchphrase)}
 */
void DecreaseFriendship(map<string, tuple<int, string, string>>& villagers) {
    cout << "Decreased friendship of all villagers" << endl;
    //iterate through pairs and decrement friendship
    for (auto& pair : villagers) {
        if (get<0>(pair.second) > FRIENDSHIP_RANGE.first) get<0>(pair.second)--;
    }
}

/**
 * Search for a villager name (from input) and output their info
 * @param villagers Villager data stored as a map formatted {string name, tuple(int friendship, string species, string catchphrase)}
 */
void SearchVillager(const map<string, tuple<int, string, string>>& villagers) {
    //Retrieve villager name from input
    string searchKey;
    cout << "Enter the name of the villager to search for: ";
    getline(cin, searchKey);

    // search for an element using .find() to avoid errors
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s information: ";
        OutputVillager(*it);
    } else
        cout << searchKey << " was not found." << endl;
}