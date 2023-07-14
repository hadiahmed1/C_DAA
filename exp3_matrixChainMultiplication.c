#include <stdio.h>
#include <limits.h>
#define INFY 999999999
long int m[20][20];
int s[20][20];
int p[20];

void print_optimal(int i,int j){
    if(i==j)
        printf("A%d ",i);
    else{
        printf("(");
        print_optimal(i,s[i][j]);
        print_optimal(s[i][j]+1,j);
        printf(")");
    }
}
void matrixChainMultiplication(int n){
    long int q;
    int i,j,k;
    for(i=n;i>0;i--){
        for(j=i;j<=n;j++){
            if(i==j)
                m[i][j]=0;
            else{
                for(k=i;k<j;k++){
                    q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(q<m[i][j]){
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
    }
}

int matrixChainOrder(int p[],int i,int j){
    if(i==j)
        return 0;
    int k;
    int min=INT_MAX;
    int count;
    for(k=i;k<j;k++){
        count=matrixChainOrder(p,i,k)+matrixChainOrder(p,k+1,j)+p[i-1]*p[k]*p[j];
        if(count<min)
            min=count;
    }
    return min;
}

int main(){
    int i,j,k,n;
    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            m[i][i]=0;
            m[i][j]=INFY;
            s[i][j]=0;
        }
    }
    printf("\nEnter the Dimensions: \n");
    for(k=0;k<=n;k++){
        printf("P%d: ",k);
        scanf("%d",&p[k]);
    }

    matrixChainMultiplication(n);

    printf("\n***COST MATRIX*** \n");
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            printf("m[%d][%d]: %ld\n",i,j,m[i][j]);
        }
    }
    printf("\n***************\n");
    i=1;j=n;
    printf("\n***multiplication seqence***\n");
    print_optimal(i,j);
    printf("\n****************\n");
    printf("\n minimmum numbr of multiplication is :%d",matrixChainOrder(p,1,n));
    
    return 0;
}