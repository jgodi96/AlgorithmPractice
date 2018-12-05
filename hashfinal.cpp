#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;
class hashy
{
    public:
        hashy();
        int Hash(int);
        void AddItem(string, double, string,int);
        void Search(int);
        int compared(int);
        void Delete(int);
    private:
        static const int tableSize=1000;
        
        struct item
        {
            string name;
            double GPA;
            string AcademicLevel;
            int keys;
            item* next;
        };

        item* HashTable[tableSize];
       

};

hashy::hashy()
{
    for(int i=0; i<tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i] ->name ="empty";
        HashTable[i] ->GPA=0;
        HashTable[i] ->AcademicLevel ="empty";
        HashTable[i] ->keys=-11;
        HashTable[i] ->next = NULL;

    }
}

int hashy::compared(int x)
{   int index=x%tableSize;
    int again=x;
    item* ptr=HashTable[index];
    while(ptr!=NULL)
    {
    
        if(ptr->keys==x)
        {
            do 
            {
                cout<<"Key already entered. Try again "<<endl;
                cin>>x

            }

            
        }
        ptr=ptr->next;
    }
   return again;


}

void hashy::Delete(int x)
{
    int index=x%tableSize;
    item* dptr;
    item* ptrone;
    item* ptrtwo;
    if(HashTable[index]->name=="empty")//no info
    {   cout<<endl;
        cout<<"Empty! Nothing to Delete!"<<endl;
        cout<<endl;
        
    }
    else if(HashTable[index]->keys==x && HashTable[index]->next==NULL)//only 1 ifo in index

   {
    cout<<endl;
    cout<< "---------------------\n";
    cout<<"Deleted "<<HashTable[x]->name<<"'s"<<" information."<<endl;
    cout<< "---------------------\n";
    cout<<endl;

            HashTable[index] ->name ="empty";
            HashTable[index] ->GPA=0;
            HashTable[index] ->AcademicLevel ="empty";
            HashTable[index] ->keys=-11;
     


    }
    else if(HashTable[index]->keys==x) //more linked list
    {    cout<<endl;
         cout<< "---------------------\n";
         cout<<"Deleted "<<HashTable[index]->name<<"'s"<<" information."<<endl;
         cout<< "---------------------\n";
         cout<<endl;
         dptr=HashTable[index];
         HashTable[index]=HashTable[index]->next;
         delete dptr;
   

    }
    else
    {
        ptrone=HashTable[index]->next;
        ptrtwo=HashTable[index];

        while(ptrone!=NULL && ptrone->keys!=x)
        {
            ptrtwo=ptrone;
            ptrone=ptrone->next;
        }
        if(ptrone==NULL)
        {
        cout<<endl;
        cout<<"Empty! Nothing to Delete!"<<endl;
        cout<<endl;
          
        }
        else
        {
            dptr=ptrone;
            ptrone=ptrone->next;
            ptrtwo->next=ptrone;
            delete dptr;
        cout<<endl;
         cout<< "---------------------\n";
         cout<<"Deleted "<<HashTable[index]->name<<"'s"<<" information."<<endl;
         cout<< "---------------------\n";
         cout<<endl;
           
        }
    }
}
void hashy::Search(int x)
{   int index=x%tableSize;
    item* ptr=HashTable[index];
    while(ptr!=NULL)
    {
        if(ptr->keys==-11)
        {
        cout<<endl;
        cout<<"Empty! No Information!"<<endl;
        cout<<endl;
        

        }
        else if(ptr->keys==x)
        {
        cout<<endl;
        cout<< "---------------------\n";
        cout<<"Name: "<<ptr->name<<endl;
        cout<<"Gpa: "<<ptr->GPA<<endl;
        cout<<"Academic Level: "<<ptr->AcademicLevel<<endl;
        cout<< "---------------------\n";
        cout<<endl;
    

        }
        ptr=ptr->next;
    }
}

void hashy::AddItem(string name, double GPA, string AcademicLevel,int key)
{   int index=key%tableSize;
    Hash(index); //index location

    if(HashTable[index]->name=="empty")
    {
        HashTable[index]->name=name;
        HashTable[index]->GPA=GPA;
        HashTable[index]->AcademicLevel=AcademicLevel;
        HashTable[index]->keys=key;
        cout<<endl;
        cout<<name<<" added to index " << index<<endl;
        cout<<endl;
    }
    else
    {

        item* Ptr=HashTable[index]; //look at index
        item* n =new item;
        n->name=name;
        n->GPA=GPA;
        n->AcademicLevel=AcademicLevel;
        n->keys=key;
        n->next=NULL;
        while(Ptr->next != NULL)
        {
            Ptr=Ptr->next; //pointing to last item when exiting the while loop
        }
        Ptr->next=n;
        cout<<endl;
        cout<<name<<" added to index " << index<<endl;
        cout<<endl;
    }

}

int hashy::Hash(int key)
{   int index;
    index=key%tableSize;
    return index;
}

int main()
{
    hashy Hashy;
    int choice,key,ckey;
    double gpa;
    string name, academiclevel;
    for(int i=0;i<=10000;) //max students entered
    {
            cout<<"Hash Table Implementation"<<endl;
            cout<<"========================="<<endl;
            cout<<"1. Insert a Record (user enters the name, GPA, Academic level, Key (Key should be between 0-65536))"<<endl;
            cout<<"2. Search the table (user enters a key for search) Key should be between 0-65536"<<endl;
            cout<<"3. Delete a record (user enter a key of the record to be deleted)"<<endl;
            cout<<"4.Quit"<<endl;
            cout<<"Enter your choice: ";
            cin>> choice;
            cout<<endl;
            cin.ignore();

            switch(choice)
            {
                case 1: cout<<"Enter name: ";
                        getline(cin,name);
                        cout<<"Enter GPA: ";
                        cin>>gpa;
                        cout<<"Enter Academic level: ";
                        cin>>academiclevel;
                        cout<<"Enter key to store data in (0-65536): ";
                        cin>>key;
                         if (key>=0 && key<=65536)
                        {
                           ckey=Hashy.compared(key);


                        }
                        else
                        {
                            while (key<=0 || key>=65536)
                            {
                                cout<<"ERROR:Enter a value from 0 to 65536"<<endl;
                                cin>>key;
                            }

                        }

                Hashy.AddItem(name,gpa,academiclevel,ckey);
                i++;

                break;
                case 2: cout<<"Enter Key to search (0-65536): "; //no data entered in this key statement
                        cin>>key;
                        Hashy.Search(key);
                        break;

                case 3: cout<<"Enter Key to delete (0-65536): ";
                        cin>>key;
                        Hashy.Delete(key);
                        break;
                case 4:
                    return 0;
                    break;
                default:
                    cout<<"Invalid choice"<<endl;
                    cout<<endl;


            };
    }


}

