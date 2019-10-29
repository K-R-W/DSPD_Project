#include<stdio.h>
#include<math.h>

void swap(int* a, int* b)
{
    int t = *a;
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
