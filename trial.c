//
//  asssign.c
//  Learn
//
//  Created by Prathit Aswar on 29/10/19.
//  Copyright © 2019 Prathit Aswar. All rights reserved.
//

#include "assign.h"
#include<stdio.h>
#include<math.h>



struct player
{
    char *player_id;
    /*here, player_id will be a string, but has not been assigned a size. this shall be done using %ms instead of %s during scanf


    #include <stdio.h>
        int main(){
        char *player_id;
        printf("enter name");
        scanf("%ms",&player_id);
        printf("name is %s",player_id);
        return 0;
        }
    */
    char *match_id;
    int previous_total_score;
    float previous_avg;
    int previous_total_wickets;
    float previous_wicket_avg;
    int total_runs_in_last_five_matches;
    int total_wickets_in_last_five_matches;
    int century;
    int present_match_score;
    int present_match_wicket;
    //player role to be bowler=-1 all rounder=0 batsman=1
    int player_role;
    char *out_status;
};

struct team
{
    struct player all_players[15];
};

struct match_played
{
    char *match_id;
    char *teams_played;
    int highest_run;
    char *man_of_the_match;
    char *wicket_taken_by_pacer;
    char *match_result;
};




void swap(struct player* a, struct player* b)
{
    struct player t = *a;
    *a = *b;
    *b = t;
}
int partition_pr (struct player player[], int low, int high)
{
    int pivot =player[high].player_role;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (player[j].player_role < pivot)
        {
            i++;
            swap(&player[i], &player[j]);
        }
    }
    swap(&player[i + 1], &player[high]);

    return (i + 1);
}

void quickSort_pr(struct player player[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_pr(player, low, high);

        quickSort_pr(player, low, pi - 1);
        quickSort_pr(player, pi + 1, high);
    }
}

int partition_pts(struct player player[], int low, int high)
{
    int pivot = player[high].previous_total_score;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (player[j].previous_total_score < pivot)
        {
            i++;
            swap(&player[i], &player[j]);
        }
    }
    swap(&player[i + 1], &player[high]);

    return (i + 1);
}

void quickSort_pts(struct player player[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_pts(player, low, high);

        quickSort_pts(player, low, pi - 1);
        quickSort_pts(player, pi + 1, high);
    }
}

int main()
{
    struct player player1[15] = {{"jon","M2019.1",56,30,2,1,310,4,1,45,1,-1,"out"}
    , {"snow","M2019.1",57,30,2,1,310,4,1,45,1,-1,"out"}
    , {"tyrion","M2019.1",58,30,2,1,310,4,1,45,1,-1,"out"}
    , {"olenna","M2019.1",59,30,2,1,310,4,1,45,1,1,"not out"}
    , {"geoffrey","M2019.1",60,30,2,1,310,4,1,45,1,1,"not out"}
    , {"tywin","M2019.1",61,30,2,1,310,4,1,45,1,0,"not out"}
    , {"illiana","M2019.1",62,30,2,1,310,4,1,45,1,1,"not out"}
    , {"mance","M2019.1",63,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"george","M2019.1",64,30,2,1,310,4,1,45,1,1,"not out"}
    , {"night king","M2019.1",65,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"ollie","M2019.1",66,30,2,1,310,4,1,45,1,0,"not out"}
    , {"samwell","M2019.1",67,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"drogon","M2019.1",68,30,2,1,310,4,1,45,1,1,"not out"}
    , {"mellisandre","M2019.1",69,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"agatha","M2019.1",70,30,2,1,310,4,1,45,1,0,"not out"}};
    struct team teams1 = {player1[0],player1[1],player1[2],player1[3],player1[4],player1[5],player1[6],player1[7],player1[8],player1[9],player1[10],player1[11],player1[12],player1[13],player1[14]};


    struct player player2[15] = {{"sumit","M2019.1",56,30,2,1,310,4,1,45,1,-1,"out"}
    , {"manohar","M2019.1",56,30,2,1,310,4,1,45,1,-1,"out"}
    , {"pushkar","M2019.1",56,30,2,1,310,4,1,45,1,-1,"out"}
    , {"sachin","M2019.1",56,30,2,1,310,4,1,45,1,1,"not out"}
    , {"makarand","M2019.1",56,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,0,"not out"}
    , {"kushal","M2019.1",56,30,2,1,310,4,1,45,1,1,"not out"}
    , {"sagar","M2019.1",56,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"bhau","M2019.1",56,30,2,1,310,4,1,45,1,1,"not out"}
    , {"ashok","M2019.1",56,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,0,"not out"}
    , {"ganesh","M2019.1",56,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"nisarg","M2019.1",56,30,2,1,310,4,1,45,1,1,"not out"}
    , {"jayesh","M2019.1",56,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"mahesh","M2019.1",56,30,2,1,310,4,1,45,1,0,"not out"}};
    struct team teams2 = {player2[0],player2[1],player2[2],player2[3],player2[4],player2[5],player2[6],player2[7],player2[8],player2[9],player2[10],player2[11],player2[12],player2[13],player2[14]};



    quickSort_pr(teams1.all_players,0,14);
    int p=0,flag=0;
    while(p<15 && flag==0){
        if(teams1.all_players[p].player_role==0)
        {
            flag=1;
        }
        p++;
    }
    quickSort_pts(teams1.all_players,0,p-1);
    int q=0;
    flag=0;
    while(q<15 && flag==0){
        if(teams1.all_players[q].player_role==1)
        {
            flag=1;
        }
        q++;
    }
    quickSort_pts(teams1.all_players,p,q-1);
    quickSort_pts(teams1.all_players,q,14);
    int k;
    for(k=0;k<15;k++){
        printf("%s\n",teams1.all_players[k].player_id);
    }

    return 0;
}
