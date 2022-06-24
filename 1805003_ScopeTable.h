
#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include<bits/stdc++.h>
#include "1805003_SymbolInfo.h"

using namespace std;



static uint32_t sdbm(string key)
{
    const char * str = key.c_str();
    uint32_t hash1 = 0;
    int c;

    while (c = *str++)
        hash1 = c + (hash1 << 6) + (hash1 << 16) - hash1;

    return hash1;

}

class ScopeTable
{
    string id;
    int counter;


    ScopeTable* parentScope;



    SymbolInfo** hash_table;

     int n;

public:



    ScopeTable(int table_size)
    {
        id = "1";
        counter = 1;
        parentScope = NULL;

        n = table_size;

        hash_table = new SymbolInfo*[n];
        for(int i=0; i<n; i++)
        {
            hash_table[i]=NULL;
        }


    }

    ~ScopeTable();


    string getId();
    void setId(string id);

    void setParentScope( ScopeTable* p);

    ScopeTable* getParentScope();


    int getCounter();
    void setCounter(int counter);
    void increaseCounter();


    int hash(string key);


    SymbolInfo* lookUp(string key);
    bool insert(SymbolInfo *s);
    bool erase(string key);

    void print(ofstream&);


};





string ScopeTable::getId()
{
    return id;
}
void ScopeTable::setId(string id)
{
    this->id = id;
}

void ScopeTable::setParentScope( ScopeTable* p)
{

    this->parentScope=p;

}

ScopeTable* ScopeTable::getParentScope()
{

    return this->parentScope;

}
void ScopeTable::setCounter(int counter)
{

    this->counter=counter;

}

void ScopeTable::increaseCounter()
{


    this->counter++;

}

int ScopeTable::getCounter()
{

    return counter;
}
int ScopeTable::hash(string key)
{




    return sdbm(key)%(this->n);

}
SymbolInfo* ScopeTable::lookUp(string key)
{


    int idx = hash(key);

    int bucketPosition=0;
    SymbolInfo * temp=hash_table[idx];

    while(temp!=NULL)
    {
        if(temp->getKey()==key)
        {

            temp->setBucketPosition(bucketPosition);
            return temp;
        }
        bucketPosition++;
        temp=temp->getNext();
    }
    return NULL;
}
bool ScopeTable::insert(SymbolInfo *newSymbol)
{


    if(this->lookUp(newSymbol->getKey())==NULL)
    {


        int idx=hash(newSymbol->getKey());




        newSymbol->setBucket(idx);
        if(hash_table[idx]==NULL)
        {
            hash_table[idx]=newSymbol;
            newSymbol->setBucketPosition(0);
        }
        else
        {

            SymbolInfo *temp=hash_table[idx];



            int position=1;
            while(temp->getNext()!=NULL)
            {



                temp=temp->getNext();
                position++;


            }

            newSymbol ->setBucketPosition(position);
            temp->setNext(newSymbol);
        }
        return true;
    }
    else
        return false;
}
bool ScopeTable::erase(string key)
{



    SymbolInfo* prev = NULL;

    int index=hash(key);

    if(this->lookUp(key)==NULL)
    {

        return false;

    }


    SymbolInfo* temp = hash_table[index];
    prev =temp;
    int flag=0;

    while(temp->getKey()!=key)
    {
        prev=temp;
        temp=temp->getNext();
    }
    if(prev==temp)
    {
        hash_table[index]=temp->getNext();
    }
    else
        prev->setNext(temp->getNext());



    delete temp;
    return true;

}



void ScopeTable::print(ofstream &file)
{


  //  cout<<"ScopeTable # "<<this->getId()<<endl;
    file<<endl; 
   file<<"ScopeTable # "<<this->getId()<<endl;
  int flag=0;
    for(int i=0; i<n; i++)
    {



        SymbolInfo* temp = hash_table[i];
       // cout<<i<<"-->";
       if(temp!=NULL){
        file<<i<<"-->";
       }

        while(temp != NULL)
        {

          //  cout<<"< "<<temp->getKey() <<" : "<<temp->getVal()<<" > ";
           file<<"< "<<temp->getKey() <<" : "<<temp->getVal()<<" > ";
            temp = temp->getNext();
            flag=1;

        }
        if(flag==1){
                 file<<endl;
                 flag=0;
        }
       // cout<<endl;
      
  

    }
 
    file<<endl;
}
ScopeTable::~ScopeTable()
{


    for(int i=0; i<n; i++)
    {
        SymbolInfo* now = hash_table[i];

        while(now != NULL)
        {
            SymbolInfo* tmp = now->getNext();
            delete now;
            now = tmp;
        }
    }
    if(this->getId()=="1")
    {

       
  //      file2<<"Destroying the First Scope"<<endl;
    }
   
//    file2<<"Destroying the ScopeTable"<<endl;
    delete[] hash_table;
    parentScope=NULL;
}



#endif
