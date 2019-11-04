
char* temp[15]

char highest_total_rungetter(struct team teams[]){
    int i,j,max,k=0;
    for(i=0;i<sizeof(teams)/sizeof(teams[0]);i++){
        for(j=0;j<15;j++){
            if(teams[i].all_players[j].previous_total_score>max){
                max=teams[i].all_players[j].previous_total_score;

            }
        }

    }
    for(i=0;i<sizeof(teams)/sizeof(teams[0]);i++){
        for(j=0;j<15;j++){
            if(teams[i].all_players[j].previous_total_score==max){
                temp[k]=teams[i].all_players[j].player_id;
                k++;
            }
        }
    }
    return temp;

}

int partition_name(char* player[], int low, int high)
{
    char *pivot =player[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
      if(strcmp(player[j],pivot) < 0) //comparing the strings
      {
        i++;
        swap(&player[i], &player[j]);
      }
    }
    swap(&player[i + 1], &player[high]);

    return (i + 1);
}

void quickSort_name(char* player[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_pr(player, low, high);

        quickSort_pr(player, low, pi - 1);
        quickSort_pr(player, pi + 1, high);
    }
}
