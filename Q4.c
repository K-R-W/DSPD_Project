int Qtwo_Qthree(char *temp1[],m,char *temp2[],n){
  int ret=0,j;
  if (n==m){
  for(j=0; j<n&&ret==0;j++){
    if(strcmp(temp1[j], temp2[j]) != 0) //comparing the strings
    {
      ret=1;
      }
    else ret=0;
  }}
  else ret=1;
  return ret;
}
/*
if(ret=1)
{
printf("not same\n", );
}
else {
printf("same\n", );
} */
