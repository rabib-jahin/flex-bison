#ifndef SYMBOLHELPER_H
#define SYMBOHELPER_H

#include<bits/stdc++.h>
#include "SymbolInfo2.h"
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
#endif