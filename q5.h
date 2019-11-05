int highest_avg(struct team teams[][]){
    int i,j,max=0;
    char *maxname;
    for(i=0;i<2;i++){
        for(j=0;j<15;j++){
            if(teams[i].all_players[j].previous_avg>max){
                max=teams[i].all_players[j].previous_avg;
                strcpy(maxname,teams[i].all_players[j].player_id);            
            }    
        }
    }
    printf("player with highest avg is %s with avg %d",maxname, max);


}