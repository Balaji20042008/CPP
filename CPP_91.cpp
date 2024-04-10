#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main() {

    map <char,int> map_01;

    pair<char,int> pair_01 = make_pair('a', 1);
    map_01.insert(pair_01);

    pair<char,int> pair_02('b', 2);
    map_01.insert(pair_02);

    map_01['c'] = 3;

    cout << "Key: 'a', Value: " << map_01['a'] << endl;
    cout << "Key: 'a', Value: " << map_01.at('a') << endl;

    cout << "Key: 'd', Value: " << map_01['d'] << endl;
    cout << "Key: 'd', Value: " << map_01.at('d') << endl;

    map_01['d'] = 4;

    cout << "Key: 'd', Value: " << map_01['d'] << endl;

    cout << "The size of the unordered map is: " << map_01.size() << endl;

    cout << "The element 'b' is present in the map. - " << bool(map_01.count('b')) << endl;
    cout << "The element 'z' is present in the map. - " << bool(map_01.count('z')) << endl;

    // for (auto i:map) {

    //     cout << "Key: " << i.first << ", Value: " << i.second << endl;
    // }

    map <char,int> :: iterator i = map_01.begin();

    while (i != map_01.end()) {

        cout << "Key: " << i->first << ", Value: " << i->second << endl;
        i++;
    }

    return 0;
}