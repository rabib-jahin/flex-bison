

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "1805003_ScopeTable.h"

#include<bits/stdc++.h>

using namespace std;

extern ofstream file2;





class SymbolTable
{
    ScopeTable* current;
    int bucketSize;
    ScopeTable *found;


public:


    SymbolTable(int bucket_size)
    {
        this->bucketSize = bucket_size;


        current = new ScopeTable(bucket_size);
        found=NULL;
    }

    ~SymbolTable();



    void enterScope();
    void exitScope();
    bool insert(SymbolInfo s);
    bool remove(string key);
    SymbolInfo* lookUp(string key);
    int hash(string key);
    void printScope(string type,ofstream&);
    void printCurrentScope(ofstream&);
    void printAllScope(ofstream&);
    string getCurrentScopeID();
    ScopeTable* getFoundScope();
   SymbolInfo* getCurrentLookUpSymbol(string key);

};



void SymbolTable::enterScope()
{


    ScopeTable *s = new ScopeTable(bucketSize);

    s->setParentScope(current);

    current=s;

    if(s->getParentScope()!=NULL)
    {
        string id=s->getParentScope()->getId()+"."+to_string(s->getParentScope()->getCounter());
        s->setId(id);
    }




}


void SymbolTable::exitScope()
{



    if(current!=NULL)
    {

       // cout<<"ScopeTable with id "<<current->getId()<<" removed"<<endl<<endl;

     //   file2<<"ScopeTable with id "<<current->getId()<<" removed"<<endl<<endl;

        ScopeTable * st=current;

        current=current->getParentScope();

        if(current!=NULL)
            current->increaseCounter();

        delete st;





    }
    else
    {
    
       // file2<<"No current scope"<<endl;
    }

}

bool SymbolTable::insert(SymbolInfo s)
{



    SymbolInfo * temp=NULL;
    SymbolInfo *p=&s;

    if(current !=NULL)
    {
        temp= current->lookUp(s.getKey());
    }
    else
    {
        current=new ScopeTable(bucketSize);
    }
    if(temp != NULL)
    {
         
        return false;
    }
    else
    {


        return current->insert(p);

    }
}
ScopeTable* SymbolTable::getFoundScope()
{

    return found;
}
string SymbolTable::getCurrentScopeID()
{

    return current->getId();

}
bool SymbolTable::remove(string key)
{



    if(current==NULL)
    {

        return false;
    }
    else
    {
        SymbolInfo* temp = current->lookUp(key);
        if(temp != NULL)
        {

            return  current->erase(key);


        }
        else
        {

            return false;

        }
    }
}

SymbolInfo* SymbolTable::getCurrentLookUpSymbol(string key)
{

    if(current!=NULL)
        return current->lookUp(key);
    return NULL;

}

SymbolInfo* SymbolTable::lookUp(string key)
{



    ScopeTable *temp=current;

    while(temp!=NULL)
    {


        SymbolInfo* foundSymbol = temp->lookUp(key);

        if(foundSymbol!=NULL)
        {



            this->found=temp;


            return foundSymbol ;

        }

        temp=temp->getParentScope();

    }


    return NULL;
}
void SymbolTable::printScope(string type,ofstream &file)
{



    if(type=="C")
    {
        printCurrentScope(file);
    }
    else if(type=="A")
    {
        printAllScope(file);
    }
    else
    {
       
       file<<"Invalid command"<<endl;
    }

}

void SymbolTable::printCurrentScope(ofstream &file)
{
    if(current==NULL)
    {
     
       file<<"No scope found"<<endl;
    }
    else
        current->print(file);
}

void SymbolTable::printAllScope(ofstream &file)
{
    ScopeTable* temp = current;
    if(current==NULL)
    {
        
        file<<"No scope found"<<endl;
    }

    while(temp != NULL)
    {
        temp->print(file);
        temp = temp->getParentScope();
    }


    file<<endl;
}




SymbolTable::~SymbolTable()
{


    while(current != NULL)
    {
        ScopeTable* tmp = current->getParentScope();
        delete current;
        current = tmp;
    }
    found=NULL;
    current=NULL;
}


#endif
