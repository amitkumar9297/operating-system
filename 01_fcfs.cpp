#include<iostream>
using namespace std;

class fcfs{
    private:
    int n;
    int *process=new int[n];
    int *burstTime=new int[n];
    int *arivalTime=new int[n];
    int *completionTime=new int[n];
    int *turnAoundTime=new int[n];
    int *waitingTime=new int[n];
    float avgwt,avgtt,avgbt;
    public:
    fcfs(int n)
    {
        this->n=n;
    }
    void setData()
    {
        cout<<"enter the information \np b a"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>process[i]>>burstTime[i]>>arivalTime[i];
        }
    }
    void sortTheProcess()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arivalTime[j]>arivalTime[j+1])
                {
                    // cout<<arivalTime[i]<<" "<<arivalTime[j]<<endl;
                    int temp=arivalTime[j];
                    arivalTime[j]=arivalTime[j+1];
                    arivalTime[j+1]=temp;

                    temp=burstTime[j];
                    burstTime[j]=burstTime[j+1];
                    burstTime[j+1]=temp;

                    temp=process[j];
                    process[j]=process[j+1];
                    process[j+1]=temp;
                }
                
            }
        }
    }
    void calculate()
    {        
        int sum=0;
        avgbt=0;
        avgtt=0;
        avgwt=0;
        for(int i=0;i<n;i++)
        {
            sum+=burstTime[i];
            completionTime[i]=sum-arivalTime[i]+arivalTime[0];
            turnAoundTime[i]=completionTime[i]-arivalTime[i];
            waitingTime[i]=completionTime[i]-burstTime[i];

            cout<<waitingTime[i];
            avgwt+=waitingTime[i];
            avgtt+=turnAoundTime[i];
            avgbt+=burstTime[i];
        }
        //cout<<"waiting time"<<avgwt;
    }
    void getData()
    {
        cout<<"your entered data \n     process \t burst time \t arival time\tcompletion time\t   turnaround \t waiting time"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"\t"<<process[i]<<"\t\t"<<burstTime[i]<<"\t\t"<<arivalTime[i]<<"\t\t"<<completionTime[i]<<"\t\t"<<turnAoundTime[i]<<"\t\t"<<waitingTime[i]<<endl;
        }
        cout<<"avgwt->"<<avgwt/n<<endl<<"avgbt->"<<avgbt/n<<endl<<"avgtt->"<<avgtt/n<<endl;
    }
};
int main()
{
    int n;
    cout<<"how many process are you enter :";
    cin>>n;
    fcfs FCFS(n);
    FCFS.setData();
    FCFS.sortTheProcess();
    FCFS.calculate();
    FCFS.getData();

    return 0;
}