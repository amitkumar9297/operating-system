// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // class process
// // // {
// // //     public:
// // //     int pid;
// // //     int bt;
// // //     int art;
// // // };

// // // void totalTimeInterval(process proc[],int n,int wt[],int tat[])
// // // {
// // //     for(int i=0;i<n;i++)
// // //     tat[i]=wt[i]+proc[i].bt;
// // // }

// // // void WaitingTime(process proc[],int n,int wt[])
// // // {
// // //     int rt[n];
// // //     for(int i=0;i<n;i++)
// // //     rt[i]=proc[i].bt;
// // //     int complete=0,t=0, minm = INT_MAX;
// // //     int shortest=0,finish_time;
// // //     bool check=false;
// // //     while(complete != n)
// // //     {
// // //         for(int j=0;j<n;j++)
// // //         {
// // //             if((proc[j].art<=t) && (rt[j]<minm) && rt[j]>0 )
// // //             {
// // //                 minm=rt[j];
// // //                 shortest=j;
// // //                 check=true;
// // //             }
// // //         }
// // //         if(check==false)
// // //         {
// // //             t++;
// // //             continue;
// // //         }

// // //         rt[shortest]--;
// // //         minm=rt[shortest];
// // //         if(minm==0)
// // //         {
// // //             minm=INT_MAX;

// // //         }
// // //         if(rt[shortest]==0)
// // //         {
// // //             complete++;
// // //             check=false;
// // //             finish_time=t+1;
// // //             wt[shortest]=finish_time-proc[shortest].art-proc[shortest].bt;
// // //             // if(wt[shortest]<0)
// // //             // {
// // //             //     wt[shortest]=0;
// // //             // }
// // //         }

// // //         t++;
// // //     }
// // // }

// // // void calculation(process proc[],int n)
// // // {
// // //     int wt[n],tat[n],total_wt=0,total_tat=0;

// // //     WaitingTime(proc,n,wt);
// // //     totalTimeInterval(proc,n,wt,tat);

// // //     for(int i=0;i<n;i++)
// // //     {
// // //         cout<<wt[i]<<"'"<<tat[i]<<endl;
// // //     }
// // // }

// // // int main()
// // // {

// // //     process proc[]={{1,5,1},{2,3,1},{3,6,2},{4,5,3}};
// // //     int n=sizeof(proc)/sizeof(proc[0]);
// // //     calculation(proc,n);

// // //     return 0;
// // // }

// // #include<bits/stdc++.h>
// // using namespace std;

// // void turnaroundtime(int bursttime[],int tat[],int n,int wt[])
// // {
// //     for(int i=0;i<n;i++)
// //     {
// //         tat[i]=wt[i]+bursttime[i];
// //     }
// // }

// // void waitingtime(int process[],int bursttime[],int n,int wt[],int quantum)
// // {
// //     int t=0;
// //     int rem_bt[n];
// //     for(int i=0;i<n;i++)
// //     rem_bt[i]=bursttime[i];
// //     while(1)
// //     {
// //         bool done=true;
// //         for(int i=0;i<n;i++)
// //         {
// //             if(rem_bt[i]>0)
// //             {
// //                 done=false;
// //                 if(rem_bt[i]>quantum)
// //                 {
// //                     rem_bt[i]-=quantum;
// //                     t+=quantum;
// //                 }

// //                 else{
// //                     t=t+rem_bt[i];
// //                     wt[i]=t-bursttime[i];
// //                     rem_bt[i]=0;
// //                 }

// //             }
// //         }
// //         if(done==true)
// //         break;
// //     }
// // }

// // void calculation(int process[],int n,int bursttime[],int quantum)
// // {
// //     int wt[n],tat[n];
// //     waitingtime(process,bursttime,n,wt,quantum);
// //     turnaroundtime(bursttime,tat,n,wt);

// //     for(int i=0;i<n;i++)
// //     {
// //         cout<<wt[i]<<","<<tat[i]<<endl;
// //     }

// // }
// // int32_t main()
// // {
// //     int process[]={1,2,3};
// //     int n=sizeof(process)/sizeof(process[0]);
// //     int bursttime[]={8,6,12};
// //     int quantum=2;

// //     calculation(process,n,bursttime,quantum);
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// int mutex = 1, full = 0, empty = 5, x = 0;

// int wait(int n)
// {
//     return (--n);
// }
// int signal(int n)
// {
//     return (++n);
// }

// void producer()
// {
//     mutex = wait(mutex);
//     full = signal(full);
//     empty = wait(empty);
//     x++;
//     cout << "produce=" << x << endl;
//     mutex = signal(mutex);
// }

// void consumer()
// {
//     mutex = wait(mutex);
//     empty = signal(empty);
//     full = wait(full);
//     cout << "consume=" << x << endl;
//     x--;
//     mutex = signal(mutex);
// }

// int32_t main()
// {
//     cout << "1. press for consumer \n2. press for producer\n3. press for exit" << endl;
//     int n;
//     while (1)
//     {
//         cin >> n;
//         switch (n)
//         {
//         case 1:
//         {
//             if (mutex == 1 && full != 0)
//             {
//                 consumer();
//             }
//             else{
//                 cout<<"buffer is empty";
//             }
//             break;
//         }

//         case 2:
//         {
//             if (mutex == 1 && empty != 0)
//             {
//                 producer();
//             }
//             else{
//                 cout<<"buffer is full";
//             }
//             break;
//         }

//         case 3:
//         {
//             exit(0);
//         }

//         default:
//         {
//             cout << "please enter a valid key";
//         }
//         }
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

class FCFS
{
    public:
    int pid;
    int bt;
    int art;
};

void sort_wrt_art(FCFS fcfs[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(fcfs[j].art>fcfs[j+1].art)
            {
                FCFS temp = fcfs[j];
                fcfs[j]=fcfs[j+1];
                fcfs[j+1]=temp;
            }
        }
    }

}

void waiting_time(FCFS fcfs[],int n, int wt[],int tat[])
{
    int sum=0;
    int complete[n]={0};
    for(int i=0;i<n;i++)
    {
        sum=sum+fcfs[i].bt;
        complete[i]=complete[i]+sum-fcfs[i].art+fcfs[0].art;

        wt[i]=complete[i]-fcfs[i].bt;
        tat[i] = complete[i]-fcfs[i].art;

    }
}

int32_t main()
{
    FCFS fcfs[5];
    int wt[5];
    int tat[5];
    cout<<"enter here";
    for(int i=0;i<5;i++)
    {
        cin>>fcfs[i].pid>>fcfs[i].bt>>fcfs[i].art;
    }
    sort_wrt_art(fcfs,5);
    waiting_time(fcfs,5,wt,tat);
    for(int i=0;i<5;i++)
    {
        cout<<fcfs[i].pid<<fcfs[i].bt<<fcfs[i].art<<" "<<wt[i]<<" "<<tat[i]<<endl;
    }


    
    return 0;
}
