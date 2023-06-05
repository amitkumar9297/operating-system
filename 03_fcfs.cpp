#include<iostream>
using namespace std;

class fcfs{
    private:
    int n;
    int *bursttime=new int[n];
    int *waitingtime=new int[n];
    int *turnaroundtime=new int[n];
    int *process=new int[n];
    float avgwt,avgtt;
    public:
    fcfs()
    {
        cout<<"how many process enter";
        cin>>n;
    }
    void setdata()
    {
        cout<<"enter data\np b w"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>process[i]>>bursttime[i]>>waitingtime[i];
        }
    }
    void calculate()
    {
        avgtt=0;
        avgwt=0;
        float totalwt,totaltt;
        totalwt=0;
        totaltt=0;
        for(int i=0;i<n;i++)
        {
            totalwt+=waitingtime[i];
            turnaroundtime[i]=waitingtime[i]+bursttime[i];
            totaltt+=turnaroundtime[i];
        }
        // cout<<totaltt<<" "<<totalwt<<" "<<n;
        avgwt=totalwt/n;
        avgtt=totaltt/n;
        // cout<<avgwt<<avgtt;
    }
    void showdata()
    {
        cout<<"your entered data \n     process \t burst time \t   turnaround \t waiting time"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"\t"<<process[i]<<"\t\t"<<bursttime[i]<<"\t\t"<<turnaroundtime[i]<<"\t\t"<<waitingtime[i]<<endl;
        }
        cout<<"avgwt->"<<avgwt<<endl<<"avgtt->"<<avgtt<<endl;
    }
};
int main()
{
    // int n;
    // cout<<"how many process enter";
    // cin>>n;
    fcfs FCFS;
    FCFS.setdata();
    FCFS.calculate();
    FCFS.showdata();

    return 0;
}