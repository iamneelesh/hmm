#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30); //10
                     //20
                     //100
                     //40
                     //50
                     //0   this is v[3]garbage value
                     //0
  v[2]=100;
  v[3]=90;
    v.push_back(40);
   v.push_back(50);
   v.pop_back();
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<endl;
    }

  
  cout<< "size:"<<v.size()<<endl;
  cout<<"cap:"<<v.capacity()<<endl; //tells how much more can the vector arr accomodate

  cout<< v.at(2)<<endl;  // at gives the value stored at that particular loc 
  cout<< v.at(6)<<endl; // print ni hga garbage value  what():  vector::_M_range_check: __n (which is 6) >= this->size() (which is 5)

}