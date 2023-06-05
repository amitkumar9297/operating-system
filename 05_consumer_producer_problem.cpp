#include<iostream>
using namespace std;


int mutex=1,full=0,empty=3,x=0;
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    cout<<"\nproducer produces the value:  "<<x;
    mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    cout<<"\nconsumer consumes item:  "<<x;
    x--;
    mutex=signal(mutex);
}

int32_t main()
{
    int n;
    cout<<"\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n";
    while(1){
        cout<<endl<<"Enter your choice here"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
            {
                if(mutex==1 && empty!=0)
                producer();
                else
                cout<<"BUFFER is Full";

            }
            break;
            case 2:
            {
                if(mutex==1 && full!=0)
                consumer();
                else
                cout<<"BUFFER is empty";
            }
            break;
            case 3:
            {
                exit(0);
            }
            break;
            default:
            {
                cout<<"please enter a valid option ";
            }
        }
    }

    return 0;
}