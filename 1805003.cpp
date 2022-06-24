#include<bits/stdc++.h>
#include "1805003_SymbolInfo.h"
#include "1805003_ScopeTable.h"
# include "1805003_SymbolTable.h"


using namespace std;
ofstream file2("1805003_out.txt");

int main()
{

    // int bucketSize;


    // ifstream file("1805003_input.txt");



    // string command;




    // if(file.is_open())
    // {


    //     file>>bucketSize;

    //     SymbolTable table(bucketSize);


    //     while(file>>command)
    //     {


    //         cout<<command<<" ";

    //         file2<<command<<" ";

    //         if(command=="I")
    //         {




    //             string key,val;

    //             file>>key>>val;


    //             cout<<key<<" "<<val<<endl<<endl;
    //             file2<<key<<" "<<val<<endl<<endl;

    //             SymbolInfo *newSymbol=new SymbolInfo(key,val);

    //             if(table.insert(newSymbol))
    //             {
    //                 cout<<"Inserted in ScopeTable# "<<table.getCurrentScopeID()<<" at position "<<newSymbol->getBucket()<<","<<newSymbol->getBucketPosition()<<endl;
    //                 cout<<endl;
    //                 file2<<"Inserted in ScopeTable# "<<table.getCurrentScopeID()<<" at position "<<newSymbol->getBucket()<<","<<newSymbol->getBucketPosition()<<endl<<endl;

    //             }
    //             else
    //             {
    //                 cout<<"This word already exists"<<endl;
    //                 cout<<"<"<<key<<","<<val<<">"<<" already exists in current ScopeTable"<<endl;
    //                 cout<<endl;
    //                 file2<<"This word already exists"<<endl;
    //                 file2<<"<"<<key<<","<<val<<">"<<" already exists in current ScopeTable"<<endl<<endl;

    //                 delete newSymbol;
    //             }



    //         }

    //         else if(command=="L")
    //         {
    //             string name;
    //             file>>name;

    //             cout<<name<<endl<<endl;

    //             file2<<name<<endl<<endl;;
    //             SymbolInfo *found=table.lookUp(name);
    //             if(found==NULL)
    //             {
    //                 cout<<"Not found"<<endl<<endl<<endl;
    //                 file2<<"Not found"<<endl<<endl<<endl;
    //             }
    //             else
    //             {


    //                 cout<<"Found in ScopeTable# "<<table.getFoundScope()->getId()<<" at position "<<found->getBucket()<<","<<found->getBucketPosition()<<endl<<endl;
    //                 file2<<"Found in ScopeTable# "<<table.getFoundScope()->getId()<<" at position "<<found->getBucket()<<","<<found->getBucketPosition()<<endl<<endl;


    //             }

    //         }
    //         else if(command=="S")
    //         {


    //             cout<<endl<<endl;
    //             file2<<endl<<endl;

    //             table.enterScope();
    //             cout<<"New ScopeTable with id "<<table.getCurrentScopeID()<<" created"<<endl<<endl;
    //             file2<<"New ScopeTable with id "<<table.getCurrentScopeID()<<" created"<<endl<<endl;
    //         }
    //         else if(command=="E")
    //         {

    //             cout<<endl;
    //             cout<<endl;
    //             file2<<endl<<endl;


    //             table.exitScope();
    //         }
    //         else if(command=="D")
    //         {
    //             string name;
    //             file>>name;

    //             cout<<name<<endl;
    //             cout<<endl;
    //             file2<<name<<endl<<endl;
    //             int bucket=-1;
    //             int bucketPos=-1;
    //             SymbolInfo *s=table.getCurrentLookUpSymbol(name);

    //             if(s!=NULL)
    //             {
    //                 bucket=s->getBucket();
    //                 bucketPos=s->getBucketPosition();

    //             }




    //             if(table.remove(name))
    //             {
    //                 cout<<"Found in ScopeTable# "<<table.getCurrentScopeID()<<" at position "<<bucket<<","<<bucketPos<<endl<<endl;
    //                 cout<<"Deleted Entry "<<bucket<<","<<bucketPos<<" from current ScopeTable"<<endl;
    //                 cout<<endl;
    //                 file2<<"Found in ScopeTable# "<<table.getCurrentScopeID()<<" at position "<<bucket<<","<<bucketPos<<endl<<endl;
    //                 file2<<"Deleted Entry "<<bucket<<","<<bucketPos<<" from current ScopeTable"<<endl<<endl;


    //             }
    //             else
    //             {

    //                 cout<<"Not found"<<endl<<endl;
    //                 cout<<name<<" is not found"<<endl;
    //                 cout<<endl;
    //                 file2<<"Not found"<<endl<<endl;
    //                 file2<<name<<" is not found"<<endl<<endl;

    //             }

    //         }
    //         else if(command=="P")
    //         {

    //             string type;
    //             file>>type;
    //             cout<<type<<endl<<endl;
    //             file2<<type<<endl<<endl;

    //             table.printScope(type);



    //         }
    //         else
    //         {
    //             cout<<"Invalid command"<<endl;
    //             file2<<"Invalid command"<<endl;;
    //         }


    //     }
    // }
    // else
    // {
    //     cout<<"File is not open"<<endl;
    // }
    // file.close();
    // file2.close();
}
