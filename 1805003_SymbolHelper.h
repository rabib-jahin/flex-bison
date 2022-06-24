#ifndef SYMBOLHELPER_H
#define SYMBOHELPER_H

#include<bits/stdc++.h>
#include "1805003_SymbolInfo.h"
using namespace std;


class SymbolHelper{

public:
string  text;
string htype;
vector<SymbolInfo *> vec;
vector<string> parameters;


SymbolHelper();
SymbolHelper(string text,vector<SymbolInfo*> v);

  void setText(string text);
  void setHType(string HType);
  void setVector(vector<SymbolInfo*>v);
  void print();


};

SymbolHelper::SymbolHelper(){


}
SymbolHelper::SymbolHelper(string text,vector<SymbolInfo*>v){
    this->text=text;
    this->vec=v;


}
void SymbolHelper::setText(string text){
this->text=text;
}
void SymbolHelper::setHType(string HType){

this->htype=HType;

}
void SymbolHelper::setVector(vector<SymbolInfo*>v){

    this->vec=v;
}

void SymbolHelper::print()
{
    cout<<"Text : "<<text<<endl;

    cout<<"Vector Size : "<<vec.size()<<endl;
    cout<<"Vector  : "<<endl;
    for(auto s:vec)
    {
        cout<<s->getKey()<<" , "<<s->getVal()<<endl;
    }
}
#endif