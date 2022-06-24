#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include<bits/stdc++.h>
using namespace std;

class SymbolInfo
{

    public:
    int bucket;
    int bucketPosition;

    string key;
    string val;
    string type;
    vector<string> parameters;
    int isDeclaredFunction;
    int isFunction;




    SymbolInfo* next;


public:

    SymbolInfo();

    SymbolInfo(string key,string val);

  SymbolInfo(string key,string val,string type,vector<string> parameters,int isDeclaredFunction,int isFunction ,SymbolInfo *next);
   
    void setType(string type);
   
    void setBucketPosition(int pos);
    string getType(){
        return type;
    }
    void setBucket(int p);
    string getKey();

    string getVal();

    void setNext(SymbolInfo* s);

    SymbolInfo* getNext();

    int getBucket();

    int getBucketPosition();
    ~SymbolInfo();




};



SymbolInfo::SymbolInfo()
{
    this->key = "0";
    this->val = "0";
    this->next = NULL;

    bucket = -1;
    bucketPosition = 0;
}


SymbolInfo::SymbolInfo(string key,string val)
{
    this->key = key;
    this->val = val;
    this->next = NULL;

    bucket = -1;
    bucketPosition = 0;
}

SymbolInfo::SymbolInfo(string key,string val,string type,vector<string> parameters,int isDeclaredFunction,int isFunction,SymbolInfo *next ){


    this->key = key;
    this->val = val;
    this->type =type;
    this->parameters = parameters;
    this-> isDeclaredFunction =  isDeclaredFunction;
    this->isFunction = isFunction;
    this->next = next;
    bucket = -1;
    bucketPosition = 0;

}
  void SymbolInfo::setType(string type){
this->type=type;

  } 
void SymbolInfo::setBucketPosition(int pos)
{


    this->bucketPosition=pos;

}
void SymbolInfo::setBucket(int p)
{
    bucket=p;
}
int SymbolInfo::getBucketPosition()
{

    return this->bucketPosition;
}

string SymbolInfo::getKey()
{

    return key;

}
string SymbolInfo::getVal()
{
    return val;
}
void SymbolInfo::setNext(SymbolInfo* s)
{
    next=s;
}
SymbolInfo* SymbolInfo::getNext()
{
    return next;
}
int SymbolInfo::getBucket()
{
    return bucket;
}
SymbolInfo:: ~SymbolInfo()
{

    next=NULL;
}






#endif

