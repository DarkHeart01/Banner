#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Personal {
    string name;
    string dob; 
    string telephone;
public: 
    Personal() {
        name = dob = telephone = "";
    }

    Personal(string name) {
        this->name = name;
    }

    void input() {
        cout << "Enter name: ";cin>>name;
        cout << "Enter DOB (YYYY-MM-DD): ";cin>>dob;
        cout << "Enter Telephone number: ";cin>>telephone;
        cout<<endl;
        
    }
   
    void display() {
        cout << "Name: " << name << ", DOB: " << dob << ", Telephone: " << telephone << endl;
    }

    friend bool comparename(Personal& , Personal&);
    friend bool operator == (const Personal& ,const Personal&);
};

bool comparename (Personal& p1, Personal&p2){
    return p1.name < p2.name; // Sort by name
}

bool operator == (const Personal& p1, const Personal& p2){
    return (p1.name == p2.name);
}


int main() {
    vector<Personal> records;
    Personal p1;
    int n;

    cout << "Enter the number of records you want to input: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        p1.input();
        records.push_back(p1);
    }

    // Sorting
    sort(records.begin(), records.end(), comparename);
    cout << "\nSorted Records:"<<endl;
    for (auto ele : records) {
        ele.display();
    }

    string nm;
    cout<<"What name to search for: ";cin>>nm;

    Personal target(nm);

    vector<Personal> :: iterator it;
    it = find(records.begin(), records.end(), target);

    if(it != records.end()){
        cout<<"Record Found"<<endl;
        it->display();
    }else{
        cout<<"NOT FOUND"<<endl;
    }
    

    return 0;
}