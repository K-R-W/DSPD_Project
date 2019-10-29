


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
}
