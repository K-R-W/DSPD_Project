char highest_total_rungetter(struct team teams[]){
    int i,j,max,k=0;
    char temp[15]
    for(i=0;i<sizeof(teams)/sizeof(teams[0]);i++){
        for(j=0;j<15;j++){
            if(teams[i].all_players[j].previous_total_score>max){
                max=teams[i].all_players[j].previous_total_score;

            }
        }

    }
    for(i=0;i<sizeof(teams)/sizeof(teams[0];i++){
        for(j=0;j<15;j++){
            if(teams[i].all_players[j].previous_total_score==max){
                temp[k]=teams[i].all_players[j].player_id;
                k++;
            }
        }
    }
    return temp;

}