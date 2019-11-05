#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
#include "q5.h"
#include "q6.h"
#include "q7.h"






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
    int wicket_taken_by_pacer;
    char *match_result;
}



int main()
{
    struct player player1[15] = {{"jon","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"snow","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"tyrion","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"olenna","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"geoffrey","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"tywin","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"};
    , {"illiana","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"mance","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"george","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"night king","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"ollie","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}
    , {"samwell","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"drogon","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"mellisandre","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"agatha","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}};
    struct team teams[1][15] = {player1[0],player1[1],player1[2],player1[3],player1[4],player1[5],player1[6],player1[7],player1[8],player1[9],player1[10],player1[11],player1[12],player1[13],player1[14]};


    struct player player2[15] = {{"sumit","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"manohar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"pushkar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"sachin","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"makarand","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"};
    , {"kushal","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"sagar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bhau","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"ashok","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}
    , {"ganesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"nisarg","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"jayesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"mahesh","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}};
    struct team teams[2][15] = {player2[0],player2[1],player2[2],player2[3],player2[4],player2[5],player2[6],player2[7],player2[8],player2[9],player2[10],player2[11],player2[12],player2[13],player2[14]};


    struct player player3[15] = {{"sumit","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"manohar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"pushkar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"sachin","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"makarand","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"};
    , {"kushal","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"sagar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bhau","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"ashok","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}
    , {"ganesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"nisarg","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"jayesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"mahesh","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}};
    struct team teams[3][15] = {player3[0],player3[1],player3[2],player3[3],player3[4],player3[5],player3[6],player3[7],player3[8],player3[9],player3[10],player3[11],player3[12],player3[13],player3[14]};

    struct player player4[15] = {{"sumit","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"manohar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"pushkar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"sachin","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"makarand","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"};
    , {"kushal","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"sagar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bhau","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"ashok","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}
    , {"ganesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"nisarg","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"jayesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"mahesh","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}};
    struct team teams[4][15] = {player4[0],player4[1],player4[2],player4[3],player4[4],player4[5],player4[6],player4[7],player4[8],player4[9],player4[10],player4[11],player4[12],player4[13],player4[14]};

    struct player player5[15] = {{"sumit","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"manohar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"pushkar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"sachin","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"makarand","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"};
    , {"kushal","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"sagar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bhau","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"ashok","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}
    , {"ganesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"nisarg","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"jayesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"mahesh","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}};
    struct team teams[5][15] = {player5[0],player5[1],player5[2],player5[3],player5[4],player5[5],player5[6],player5[7],player5[8],player5[9],player5[10],player5[11],player5[12],player5[13],player5[14]};

    struct player player6[15] = {{"sumit","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"manohar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"pushkar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","out"}
    , {"sachin","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"makarand","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"};
    , {"kushal","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"sagar","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bhau","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"ashok","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"bharat","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}
    , {"ganesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"nisarg","M2019.1",56,30,2,1,310,4,1,45,1,"bowler","not out"}
    , {"jayesh","M2019.1",56,30,2,1,310,4,1,45,1,"batsman","not out"}
    , {"mahesh","M2019.1",56,30,2,1,310,4,1,45,1,"all-rounder","not out"}};
    struct team teams[6][15] = {player6[0],player6[1],player6[2],player6[3],player6[4],player6[5],player6[6],player6[7],player6[8],player6[9],player6[10],player6[11],player6[12],player6[13],player6[14]};

    //6 knockouts, 2 semifinals, 1 final
    struct match_played matches[9] = {{"M2019.1","1,2",102,"geoffrey",2,"1"},{"M2019.1","1,3",102,"geoffrey",2,"1"},{"M2019.1","2,3",102,"geoffrey",2,"3"},{"M2019.1","4,5",102,"geoffrey",2,"5"},{"M2019.1","4,6",102,"geoffrey",2,"4"},{"M2019.1","5,6",102,"geoffrey",2,"5"},{"M2019.1","1,5",102,"geoffrey",2,"1"},{"M2019.1","3,4",102,"geoffrey",2,"3"},{"M2019.1","1,3",102,"geoffrey",2,"3"}};
    

    run_q1(teams);//q1
    highest_total_rungetter(teams);//q2
    man_of_the_match_max(k,matches);//q3
    Qtwo_Qthree(char *temp1[],m,char *temp2[],n);//q4,citation needed
    highest_avg(teams);//q5
    wicket_difference(matches);//q6, extra attribute used but not declared
    //char temp7[]=
    man_of_the_match_finder(k,matches);
    men_of_match_sort(mamcen,matches,teams);//q7

    return 0;
}
