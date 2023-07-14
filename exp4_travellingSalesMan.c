#include <stdio.h>
#include <limits.h>
int c_matrix[25][25],v_cities[20],no_city,cost=0;
void display_cost(){
    printf("\nMinimum cost=%d",cost);
}
int least_tsp(int c){
    int i,nearest_city =INT_MAX;
    int minimum=INT_MAX,temp;   
    
    for(i=0;i<no_city;i++){
        if((!v_cities[i])&& (c_matrix[c][i]!=0) && (c_matrix[c][i]<minimum)){
            minimum=c_matrix[i][0]+c_matrix[c][i];
            temp=c_matrix[c][i];
            nearest_city=i;
        }
    }
    if(minimum!=INT_MAX)
        cost=cost+temp;
    return nearest_city;
}
void tsp_minCost(int city){
    int nearest_city;
    v_cities[city]=1;
    printf("%d--->",city+1);
    nearest_city=least_tsp(city);
    if(nearest_city==INT_MAX){
        nearest_city=0;
        printf("%d", nearest_city+1);
        cost=cost+c_matrix[city][nearest_city];
        return;
    }
    tsp_minCost(nearest_city);
}

int main(){
    int i,j;
    printf("\nEnter total number of cities:");
    scanf("%d",&no_city);
    printf("\nEnter cost matrix\n");
    for(i=0;i<no_city;i++){
        printf("\nEnter %d elements in row[%d]\n",no_city,i+1);
        for(j=0;j<no_city;j++){
            scanf("%d",&c_matrix[i][j]);
        }
    }
    for(i=0;i<no_city;i++){
        v_cities[i]=0;
    }
    printf("\nTSP Path::");
    tsp_minCost(0);
    display_cost();
    return 0;
}