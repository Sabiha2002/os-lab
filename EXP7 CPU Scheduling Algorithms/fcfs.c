#include <stdio.h>

struct PCB{
    int pid, arrival, burst, turnaround, waiting;
};

void pline(int x){
    for(int i = 0; i < x; i++){
        printf("-");
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct PCB p[n], temp;
    for(int i = 0; i < n; i++){
        printf("Enter Arrival time and Burst time for process %d: ", i+1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].pid = i+1;
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(p[j].arrival > p[j+1].arrival){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    int service = 0, total_waiting = 0, total_turnaround = 0;
    p[0].waiting = 0;
    for(int i = 1; i < n; i++){
        service += p[i-1].burst;
        p[i].waiting = service - p[i].arrival;
        if(p[i].waiting < 0){
            p[i].waiting = 0;
        }
        total_waiting += p[i].waiting;
    }
    for(int i = 0; i < n; i++){
        p[i].turnaround = p[i].waiting + p[i].burst;
        total_turnaround += p[i].turnaround;
    }

    float avg_waiting = total_waiting / (float)n;
    float avg_turnaround = total_turnaround / (float)n;

    pline(80);

    printf("pid\t\tarrival\t\tburst\t\twaiting\t\tturnaround\n");

    pline(80);

    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
    }
    
    pline(80);
    printf("\n");

    printf("Average waiting time: %.3f\n", avg_waiting);
    printf("Average turn around time: %.3f\n", avg_turnaround);
    return 0;

}