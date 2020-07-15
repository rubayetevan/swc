//
//  main.c
//  SWC
//
//  Created by Md Rubayet Hassan on 27/5/20.
//  Copyright © 2020 Md Rubayet Hassan. All rights reserved.
//

// Program to calculate the sum of n numbers entered by the user

#include <stdio.h>
#include <stdlib.h>

#define SIZE_M 101
#define SIZE_SUM 50001

int totalValue,numberOfCoin,coin[SIZE_M],binary[SIZE_M],ans,dp[SIZE_M][SIZE_SUM];

void initDP(){
    for(int i=0;i<SIZE_M;i++)
        for(int j=0;j<SIZE_SUM;j++)
            dp[i][j]=-1;
}

void readCase(){
    scanf("%d",&numberOfCoin);
    for(int i=0;i<numberOfCoin;i++){
        scanf("%d",&coin[i]);
    }
}

void printCase(){
    printf("%d\n",ans);
}

int abs(int n){
    if(n<0)
        return -n;
    return n;
}

int solve(int i,int sum1){
    if(dp[i][sum1]>=0)
        return dp[i][sum1];
    
    if(i==numberOfCoin){
        int sum2 = totalValue -sum1;
        return dp[i][sum1]= abs(sum1-sum2);
    }
    
    binary[i]=0;
    int left =solve(i+1,sum1);
    binary[i]=1;
    int right= solve(i+1,sum1+coin[i]);
    
    if(left<right)
         return dp[i][sum1]=left;
    
    return dp[i][sum1]=right;
}

void solveCase(){
    for(int i=0;i<numberOfCoin;i++){
        totalValue += coin[i];
    }
    initDP();
    ans = solve(0,0);
}

int main(){
    int numberOfCase;
    scanf("%d",&numberOfCase);
    while(numberOfCase--){
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}

