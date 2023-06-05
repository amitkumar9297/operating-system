#include<iostream>
using namespace std;

class SJF
{
    private:
    int n=5;
    int *process=new int[n];
    int *burstTime=new int[n];
    int *completionTime=new int[n];
    int *waitingTime=new int[n];
    int *turnAroundTime=new int[n];
    float avgwt,avgtt;

    public:
    SJF()
    {
        cout<<"how many process enter";
        cin>>n;
    }
    void setData()
    {
        cout<<"enter the information \np b"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>process[i]>>burstTime[i];
        }
    }
    void sortTheProcess()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(burstTime[i]>burstTime[j])
                {
                    int temp;

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
        cout<<"your entered data \n     process \t burst time \tcompletion time\t   turnaround \t waiting time"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"\t"<<process[i]<<"\t\t"<<burstTime[i]<<"\t\t"<<completionTime[i]<<"\t\t"<<turnAroundTime[i]<<"\t\t"<<waitingTime[i]<<endl;
        }
        cout<<"avgwt->"<<avgwt/n<<endl<<"avgtt->"<<avgtt/n<<endl;
    }
};

int main()
{
    SJF sjf;
    sjf.setData();
    sjf.sortTheProcess();
    sjf.calculate();
    sjf.getData();
    return 0;
}