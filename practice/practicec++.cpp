#include <iostream>

using namespace std;

void RegularLoop();
void Break();
void Continue();

int main()
{
    RegularLoop();
    Break();
  return 0;

}

void RegularLoop()
{
    cout<<"----regular loop\n";
    for (int i=0; i<5; i++)
    {
        cout<<"i="<<i<<endl;
        //break or continue
        cout << "Do some more stuff with "<< i <<endl;
    }
    cout<<"\n\n";
}

void Break()
{
 cout<<"----break loop\n";
    for (int i=0; i<5; i++)
    {
        cout<<"i="<<i<<endl;
        if(i==2)
        {
            break;
        }
        cout << "Do some more stuff with "<< i <<endl;
    }
    cout<<"\n\n";
}
void Continue()
{
cout<<"----continue loop\n";
    for (int i=0; i<5; i++)
    {
        cout<<"i="<<i<<endl;
        if(i==2)
        {
            continue;
        }
        cout << "Do some more stuff with "<< i <<endl;
    }
    cout<<"\n\n";
}
