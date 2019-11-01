#include <stdlib.h>
int wicket_difference(struct match_played matches[]){
    int i,max=0;
    for(i=0;i<4;i++){//no. of matches
        printf("the difference in wickets for match %d is: ",i,abs(matches[i].total_wickets_taken-matches[i].wickets_taken_by_pacer));                  
        }
    }
}