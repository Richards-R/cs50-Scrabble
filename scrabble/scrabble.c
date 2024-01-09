// Score two players' inputs according to Scrabble points scoring system

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_score(string player_input_str);

int main(void)
{

    string player_one_input = get_string("Player 1: ");
    int p1_score = check_score(player_one_input);

    string player_two_input = get_string("Player 2: ");
    int p2_score = check_score(player_two_input);

    if (p1_score > p2_score)
    {
        printf("Player 1 Wins!\n");
    }
    else if (p2_score > p1_score)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int check_score(string player_input_str)
{

    // 1 point  = {a, e, i, l, n, o, r, s, t, u}
    // 2 points = {d, g}
    // 3 points = {b, c, m, p};
    // 4 points = {f, h, v, w, y};
    // 5 points = {k};
    // 8 points = {j, x};
    // 10 points = {q, z};

    int points_accum = 0;

    for (int i = 0, n = strlen(player_input_str); i < n; i++)
    {

        char player_input_test_letter = tolower(player_input_str[i]);

        string letters = "aeilnorstudgbcmpfhvwykjxqz";

        for (int j = 0, m = strlen(letters); j < m; j++)
        {
            if (player_input_test_letter == letters[j])
            {
                if (j < 10)
                {
                    points_accum = points_accum + 1;
                }
                else if (j < 12)
                {
                    points_accum = points_accum + 2;
                }
                else if (j < 16)
                {
                    points_accum = points_accum + 3;
                }
                else if (j < 21)
                {
                    points_accum = points_accum + 4;
                }
                else if (j < 22)
                {
                    points_accum = points_accum + 5;
                }
                else if (j < 24)
                {
                    points_accum = points_accum + 8;
                }
                else
                {
                    points_accum = points_accum + 10;
                }
            }
        }
    }
    return points_accum;
}
