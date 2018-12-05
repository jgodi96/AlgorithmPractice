#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
class hashy
{
    public:
        hashy();
        int Hash(int);
        void AddItem(string, int, string,int);
        void Search(int);
        int compare(int keyarr[],int );
        void Delete(int);

    private:
        static const int tableSize=1000;
        struct item
        {
            string name;
            int GPA;
            string AcademicLevel;
            int keys;
            item* next;
        };

        item* HashTable[tableSize];

};

#endif // HASH_H
