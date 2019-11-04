int man_of_the_match_max(int k,struct match_played matches[]){
    int length=sizeof(matches)/sizeof(matches[0]),i,j,maxm,flag=0;



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
    j=0;
    maxm=largest(times , sizeof(times)/sizeof(times[0]));
    for(i=0;i<length;i++){
        if(times[i]==maxm){
            temp[j]=names[i];
        }
    }
    sort(temp,sizeof(temp)/sizeof(temp[0]));
    return temp;
}
static int myCompare(const void* a, const void* b) 
{ 
  
   
    return strcmp(*(const char**)a, *(const char**)b); 
} 
   
void sort(const char* arr[], int n) 
{ 
    
    qsort(arr, n, sizeof(const char*), myCompare); 
} 
int largest(int arr[], int n) 
{ 
    int i; 
    int max = arr[0]; 
    for (i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
  
    return max; 
} 