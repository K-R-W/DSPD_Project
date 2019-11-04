//
//  asssign.c
//  Learn
//
//  Created by Prathit Aswar on 29/10/19.
//  Copyright © 2019 Prathit Aswar. All rights reserved.
//

//#include "asssign.h"
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

int partition_preav(struct player player[], int low, int high)
{
    int pivot = player[high].previous_avg;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (player[j].previous_total_score == pivot && player[j].previous_avg < pivot)
        {
            i++;
            swap(&player[i], &player[j]);
        }
    }
    swap(&player[i + 1], &player[high]);

    return (i + 1);
}

void quickSort_preav(struct player player[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_pts(player, low, high);

        quickSort_preav(player, low, pi - 1);
        quickSort_preav(player, pi + 1, high);
    }
}
//
//

//
//
int partition_maxw(struct player player[], int low, int high)
{
    int pivot = player[high].previous_total_wickets;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (player[j].previous_total_wickets < pivot)
        {
            i++;
            swap(&player[i], &player[j]);
        }
    }
    swap(&player[i + 1], &player[high]);

    return (i + 1);
}

void quickSort_maxw(struct player player[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_maxw(player, low, high);

        quickSort_maxw(player, low, pi - 1);
        quickSort_maxw(player, pi + 1, high);
    }
}

int partition_wavg(struct player player[], int low, int high)
{
    int pivot = player[high].previous_wicket_avg;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (player[j].previous_total_wickets == pivot && player[j].previous_wicket_avg < pivot)
        {
            i++;
            swap(&player[i], &player[j]);
        }
    }
    swap(&player[i + 1], &player[high]);

    return (i + 1);
}

void quickSort_wavg(struct player player[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_wavg(player, low, high);

        quickSort_wavg(player, low, pi - 1);
        quickSort_wavg(player, pi + 1, high);
    }
}

//
//

//
//
int gu=1;
void combinationUtil(struct team team , int n, int r, int index, struct player data[], int i, int bat, int bow, int allround)
{
    if (index == r)
    {
        for (int ge=0; ge< 14 ; ge++){
            if (data[ge].player_role == -1) {bow++;
            //printf("  b%d  ",team.all_players[i].player_role);

            }
            else if (data[ge].player_role == 1) {bat++;
            //printf("  a%d  ",team.all_players[i].player_role);

            }
            else if (data[ge].player_role == 0){
                allround++;
            }
        }
        if (bat >=5  && bow >=4 && (bat+bow+allround==11)){
        printf("%d %d %d %d %s  ",bow, bat,allround,gu++,team.all_players[0].player_id);
        printf("%s  ",team.all_players[1].player_id);
        printf("%s  ",team.all_players[14].player_id);
        printf("%s  ",team.all_players[13].player_id);
        for (int j=0; j<r; j++)
            printf("%s   ",data[j].player_id);
        printf("\n");

        }
        return;
    }

    if (i >= n+2)
        return;

    data[index] = team.all_players[i];

    combinationUtil(team, n, r, index+1, data, i+1,bat,bow,allround);
    combinationUtil(team, n, r, index, data, i+1,bat,bow,allround);
}

void printCombination(struct team team, int n, int r)
{
    // A temporary array to store all combination one by one
    struct player data[r];

    // Print all combination using temprary array 'data[]'
    combinationUtil(team, n, r, 0, data, 2 ,2,2,0);
}

void build_team(struct team team)
{
    //int arr[] = {1, 2, 3, 4, 5};
    int r = 7;
    int n = 11;
    printCombination(team, n, r);
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */

//
//

int main()
{
    struct player player1[15] = {{"jon","M2019.1",56,30,2,1,310,4,1,45,1,1,"out"}
    , {"snow","M2019.1",57,30,2,1,310,4,1,45,1,1,"out"}
    , {"tyrion","M2019.1",58,30,2,1,310,4,1,45,1,1,"out"}
    , {"olenna","M2019.1",59,30,2,1,310,4,1,45,1,1,"not out"}
    , {"geoffrey","M2019.1",60,30,2,1,310,4,1,45,1,1,"not out"}
    , {"tywin","M2019.1",61,30,2,1,310,4,1,45,1,0,"not out"}
    , {"illiana","M2019.1",62,30,2,1,310,4,1,45,1,0,"not out"}
    , {"mance","M2019.1",63,30,2,1,310,4,1,45,1,0,"not out"}
    , {"george","M2019.1",64,30,2,1,310,4,1,45,1,0,"not out"}
    , {"night king","M2019.1",65,30,2,1,310,4,1,45,1,0,"not out"}
    , {"ollie","M2019.1",66,30,2,1,310,4,1,45,1,0,"not out"}
    , {"samwell","M2019.1",67,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"drogon","M2019.1",68,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"mellisandre","M2019.1",69,30,2,1,310,4,1,45,1,-1,"not out"}
    , {"agatha","M2019.1",70,30,2,1,310,4,1,45,1,-1,"not out"}};

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


    struct team teams[2] ={ {player1[0],player1[1],player1[2],player1[3],player1[4],player1[5],player1[6],player1[7],player1[8],player1[9],player1[10],player1[11],player1[12],player1[13],player1[14]},{player2[0],player2[1],player2[2],player2[3],player2[4],player2[5],player2[6],player2[7],player2[8],player2[9],player2[10],player2[11],player2[12],player2[13],player2[14]}};



    //struct team teams2 = {player2[0],player2[1],player2[2],player2[3],player2[4],player2[5],player2[6],player2[7],player2[8],player2[9],player2[10],player2[11],player2[12],player2[13],player2[14]};



    quickSort_pr(teams[0].all_players,0,14);
    int p=0,flag=0;
    while(p<15 && flag==0){
        p++;
        if(teams[0].all_players[p].player_role==0)
        {
            flag=1;
        }
    }
    int k;
    for(k=0;k<15;k++){
        printf("%s\t",teams[0].all_players[k].player_id);
    }
    printf("\n");

    quickSort_maxw(teams[0].all_players,0,p-1);
    quickSort_wavg(teams[0].all_players,0,p-1);

    int q=0;
    flag=0;
    while(q<15 && flag==0){
        q++;
        if(teams[0].all_players[q].player_role==1)
        {
            flag=1;
        }

    }
    //quickSort_pts(teams[0].all_players,p,q-1);
    quickSort_pts(teams[0].all_players,q,14);
    quickSort_preav(teams[0].all_players,q,14);
    //int k;
    for(k=0;k<15;k++){
        printf("%s\t",teams[0].all_players[k].player_id);
    }
    printf("\n");
    build_team(teams[0]);

    return 0;
}
