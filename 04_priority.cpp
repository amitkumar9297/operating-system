#include<iostream>
using namespace std;

class PRIORITY
{
    private:
    int n;
    int *process=new int[n];
    int *burstTime=new int[n];
    int *completionTime=new int[n];
    int *waitingTime=new int[n];
    int *turnAroundTime=new int[n];
    int *priority=new int[n];
    float avgwt,avgtt;

    public:
    PRIORITY()
    {
        cout<<"how many process enter";
        cin>>n;
    }
    void setData()
    {
        cout<<"enter the information \np b p"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>process[i]>>burstTime[i]>>priority[i];
        }
    }
    void sortTheProcess()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(priority[i]>priority[j])
                {
                    int temp;

                    temp=priority[i];
                    priority[i]=priority[j];
                    priority[j]=temp;

                    temp=burstTime[i];
                    burstTime[i]=burstTime[j];
                    burstTime[j]=temp;

                    temp=process[i];
                    process[i]=process[j];
                    process[j]=temp;
                }
                
            }
        }
    }
    void calculate()
    {
        int sum=0;
        avgtt=0;
        avgwt=0;

        for(int i=0;i<n;i++)
        {
            sum+=burstTime[i];
            completionTime[i]=sum;
            waitingTime[i]=completionTime[i]-completionTime[0];
            turnAroundTime[i]=waitingTime[i]+burstTime[i];
            avgwt+=waitingTime[i];
            avgtt+=turnAroundTime[i];
        }
    }
    void getData()
    {
        cout<<"your entered data \n     process \t burst time \tcompletion time\t   turnaround \t waiting time \t priority"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"\t"<<process[i]<<"\t\t"<<burstTime[i]<<"\t\t"<<completionTime[i]<<"\t\t"<<turnAroundTime[i]<<"\t\t"<<waitingTime[i]<<"\t"<<priority[i]<<endl;
        }
        cout<<"avgwt->"<<avgwt/n<<endl<<"avgtt->"<<avgtt/n<<endl;
    }
};

int main()
{
    PRIORITY priority;
    priority.setData();
    priority.sortTheProcess();
    priority.calculate();
    priority.getData();
    return 0;
}