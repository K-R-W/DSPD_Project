#include <stdio.h>
#include <string.h>




}
int man_of_the_match_finder(int k,struct match_played matches[]){
    int length=sizeof(matches)/sizeof(matches[0]),i,j,flag=0;



    char times[length],temp[length];
    char* names[length];
    for(i=0;i<length;i++){
        for(j=0;j<length;j++){
            if(strcmp(matches[i].man_of_the_match,names[j])==0){
                times[j]+=1;
                flag=1;
            }
        }
        if(flag==0){
            names[i]=matches[i].man_of_the_match;
            times[i]+=1;


        }
    }
    j=0
    for(i=0;i<length;i++){
        if(times[i]>k){
            temp[j]=names[i];
            j++
        }
    }
    return temp;
}

int men_of_match_sort(char temp[], struct match_played matches[], struct team teams){
    int i,j,k,t=0,length=sizeof(temp)/sizeof(temp[0]),century[length];
    for(i=0;i<2;i++){
        for(j=0;j<15;j++){
            for(k=0;k<length;k++){
                if(strcmp(temp[k],teams[i].all_players[j].player_id)==0){
                    century[t]=teams[i].all_players[j].century;
                    t++;
                }
            }
        }
    }
    mergeSort_2key(century, 0, length, temp);
    //condition for same centuries, then sort by name to be added


}
void merge_2key(int arr[], int l, int m, int r, char original[])
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2], L1[n1], L2[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
        L1[i]= original[l+i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
        R1[i]= original[m+1+j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            original[k] = L1[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            original[k] = R1[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        original[k] = L1[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        original[k] = R1[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort_2key(int arr[], int l, int r, char original[])
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort_2key(arr, l, m, original);
        mergeSort_2key(arr, m+1, r,original);

        merge_2key(arr, l, m, r,original);
    }
}
