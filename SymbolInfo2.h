#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<bits/stdc++.h>
using namespace std;

class SymbolInfo
{
    int bucket;
    int bucketPosition;

    string key;
    string val;
    string type;
    vector<string> parameters;
    int isDeclaredFunction();
    int isFunction();




    SymbolInfo* next;


public:

    SymbolInfo();

    SymbolInfo(string key,string val);

  SymbolInfo(string key,string val,string type,vector<string> parameters,int isDeclaredFunction,int isFunction ,SymbolInfo *next);
   
    void setType(string type);
   
    void setBucketPosition(int pos);

    void setBucket(int p);
    string getKey();

    string getVal();

    void setNext(SymbolInfo* s);

    SymbolInfo* getNext();

    int getBucket();

    int getBucketPosition();
    ~SymbolInfo();




};
#endif