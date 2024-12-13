#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main(){
    string name;
    int pop;

    string states[] = { "Meghalaya", "Bihar", "UttarPradesh","Maharashtra", "Gujarat", "Assam"};
    int pops[] = { 470, 2890, 800, 787, 2718, 944 };

    map<string, int> mapStates; //map
    map<string, int> :: iterator iter; //iterator

    for(int j=0; j<6; j++){
        mapStates[states[j]] = pops[j]; 
    }

    cout << "Enter state: ";cin >> name;
    pop = mapStates[name];
    cout << "Population: " << pop << ",000\n"<<endl;

    for(iter = mapStates.begin(); iter != mapStates.end(); iter++){
        cout << (*iter).first << " : " << (*iter).second <<",000\n";
    }

    return 0;
}