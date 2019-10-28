#include<stdio.h>
#include<math.h>

int partition_pts(int team.player[], int low, int high)
{
    int pivot = team.all_players[high].previous_total_score;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (team.all_players[j].previous_total_score < pivot)
        {
            i++;
            swap(&team.all_players[i], &team.all_players[j]);
        }
    }
    swap(&team.all_players[i + 1], &team.all_players[high]);

    return (i + 1);
}

void quickSort_pts(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_pts(team.all_players, low, high);

        quickSort(team.all_players, low, pi - 1);
        quickSort(team.all_players, pi + 1, high);
    }
}

int partition_pts (int team.player[], int low, int high)
{
    int pivot = team.all_players[high].previous_total_score;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (team.all_players[j].previous_total_score < pivot)
        {
            i++;
            swap(&team.all_players[i], &team.all_players[j]);
        }
    }
    swap(&team.all_players[i + 1], &team.all_players[high]);

    return (i + 1);
}

void quickSort_pts(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition_pts(team.all_players, low, high);

        quickSort(team.all_players, low, pi - 1);
        quickSort(team.all_players, pi + 1, high);
    }
}
