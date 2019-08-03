#include <iostream>
#include <cstring>

using namespace std;

struct CPU{
  string process_no;
  int brust_time;
  int priority;
};

void  shortest_path(CPU element[],int n){
  int complete_time[100],waiting_time[100],i;
  complete_time[1]=element[1].brust_time;
  for(i=2;i<=n;i++){
    complete_time[i]=element[i].brust_time+complete_time[i-1];
  }

  for(i=1;i<=n;i++){
    waiting_time[i]=complete_time[i]-element[i].brust_time;
  }

  cout<<"process_no\tbrust_time\tpriority\tcomplete_time\twaiting_time"<<endl;
  for(i=1;i<=n;i++)
  {
    cout<<element[i].process_no<<"\t\t"<<element[i].brust_time<<"\t\t"<<element[i].priority<<"\t\t"<<complete_time[i]<<"\t\t"<<waiting_time[i]<<endl;
  }

}
int main()
{
    int n,i,j;
    cout<<"enter the number of activities:"<<endl;
    cin>>n;
    CPU element[100],temp;
    cout<<"enter the elements:"<<endl;
    for(i=1;i<=n;i++){
        cin>>element[i].process_no>>element[i].brust_time>>element[i].priority;
    }
     for(i=1;i<=n;i++){
		for(j=1;j<=n-1;j++){
			if(element[j].priority > element[j+1].priority){   //sorting technique
				temp = element[j];
				element[j] = element[j+1];
				element[j+1] = temp;
			}
		}
	}

    cout<<"elements are after rearrange according to the priority:"<<endl;
    cout<<"process_no\tbrust_time"<<endl;
	for(i=1;i<=n;i++)
    {
       cout<<element[i].process_no<<"\t\t"<< element[i].brust_time<<"\t\t"<<element[i].priority<<endl;
    }

   shortest_path(element,n);

    return 0;
}
