
/*
       _           _            _____        _        _                    
      | |         | |     /\   |  __ \      | |      | |                   
      | |_   _ ___| |_   /  \  | |  | | __ _| |_ __ _| |__   __ _ ___  ___ 
  _   | | | | / __| __| / /\ \ | |  | |/ _` | __/ _` | '_ \ / _` / __|/ _ \
 | |__| | |_| \__ | |_ / ____ \| |__| | (_| | || (_| | |_) | (_| \__ |  __/
  \____/ \__,_|___/\__/_/    \_|_____/ \__,_|\__\__,_|_.__/ \__,_|___/\___|

by 220041109_Kabir

supported functions:
- Update: updates any field of any entry; O(1)
- Query: fetches any field of any entry; O(1)
- AddRow: creates a new entry; O( # OF FIELDS )
- AddCol: creates a new field; O( # OF ROWS )
- DelRow: deletes an existing entry; O( # OF FIELDS )
- DelCol: deletes an existing field; O(1)
- Read: loads data from text file.
- Write: writes data to text file.

see end of code to observe test data.
*/


#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std;

using ll = long long;

ll ROW = 0;
ll COL = 0;
ll CID = 0;
map<string, ll> colmap;
set<ll> ids;
unordered_map<ll, unordered_map<ll, string>> database;

void read(string s){
  ifstream file(s);

  //read columns
  string fl; getline(file, fl);
  stringstream fss(fl); string cns;
  while(getline(fss, cns, ',')){
    colmap[cns]=CID++;
  }
  //-------------------------------
  
  //read data
  string line;
  ll row=0;
  while(getline(file, line)){
    stringstream ss(line);
    string item;
    
    ll col=0;
    ll curid=0;
    while(getline(ss, item, ',')){
      if(col==0){
        curid=stoi(item);
        ids.insert(curid);
      }
      else{
        database[col][curid]=item;
      }
      col++;
    }
    COL = col;
    row++;
  }
  ROW = row;
  //-------------------------------
  file.close();
}

void write(string s){
  ofstream file(s);
  vector<ll> cids;
  for(auto [colnm, colid]: colmap){
    file<<colnm;
    cids.push_back(colid);
    if(cids.size()!=colmap.size()) file<<",";
  }
  file<<"\n";
  for(ll id: ids){
    file<<id;
    for(int j=0; j<cids.size(); ++j){
      file<<database[cids[j]][id];
      if(j!=cids.size()-1) file<<",";
    }
    file<<"\n";
  }
  file.close();
}

void addRow(){
  cout<<"//// NEW ROW ////"<<endl;
  ll id=0;
  cout<<"ENTER ID ";
  cin>>id; ids.insert(id);

  for(auto [colm, coli]: colmap){
    if(colm != "ID"){
      cout<<"ENTER "<<colm<<" ";
      string newv; cin>>newv;
      database[coli][id]=newv;
    }
  }
  ROW++;
}
void delRow(){
  cout<<"//// DELETING ROW ////"<<endl;
  cout<<"Enter ID"<<endl;
  ll id; cin>>id;
  ids.erase(id);
  for(auto [ll, mp]: database){
    mp.erase(id);
  }
}

void query(){
  cout<<"//// QUERY ////"<<endl;
  cout<<"Enter ID"<<endl;
  ll id; cin>>id;
  cout<<"Enter Field to query: "<<endl;
  string s; cin>>s;
  cout<<"result: "<<database[colmap[s]][id]<<endl;
}
void update(){
  cout<<"//// UPDATE ////"<<endl;
  cout<<"Enter ID"<<endl;
  ll id; cin>>id;
  cout<<"Enter Field to update: "<<endl;
  string s; cin>>s;
  cout<<"Enter new value: "<<endl;
  string nv; cin>>nv;
  database[colmap[s]][id]=nv;
}

void addCol(){
  cout<<"//// NEW COL ////"<<endl;
  cout<<"Enter column name: "<<endl;
  string s; cin>>s; 
  colmap[s]=COL++;
  for(ll id: ids){
    cout<<"Enter value for ID "<<id<<endl;
    string val; cin>>val;
    database[colmap[s]][id]=val;
  }
}
void delCol(){
  cout<<"//// DELETING COL ////"<<endl;
  cout<<"Enter column"<<endl;
  string dc; cin>>dc;
  database.erase(colmap[dc]);
  colmap.erase(dc);
}


int main(){
  read("spells.txt");
  addRow(); //15, o, oscar
  addCol(); //sign, alpha, beta, gamma, omega
  delRow(); //2
  delCol(); //letter
  update(); //1, name, Alice
  query();  //15, sign -> omega
  write("newspells.txt");
}

/* 
    //// IO ////

spells.txt
------------------------------
ID,letter,name
1,a,alice
2,b,bob
3,c,charlie
------------------------------

newspells.txt
------------------------------
ID,name,sign
1,Alice,alpha
3,charlie,gamma
15,oscar,omega
------------------------------

*/
