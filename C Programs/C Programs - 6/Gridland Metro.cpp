#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

struct post
{
    int column_no, type;
};

int compare(const post &A, const post &B)
{
    if(A.column_no < B.column_no)
        return true;
    else if(A.column_no == B.column_no)
        return (A.type < B.type);

    return false;
}

map <int, int> assigned;
int smallest_free_number = 0;

int get_index(int n)
{
    if(assigned.count(n) == 0)
    {
        assigned[n] = smallest_free_number++;
    }

    return assigned[n];
}

int main()
{
    int no_of_rows, no_of_columns, no_of_tracks;
    scanf("%d %d %d", &no_of_rows, &no_of_columns, &no_of_tracks);

    vector <post> tracks[1001];

    const int START = 1, END = 2;

    while(no_of_tracks--)
    {
        int row, column_1, column_2;
        scanf("%d %d %d", &row, &column_1, &column_2);

        post start, ending;
        start.column_no = column_1, start.type = START;
        ending.column_no = column_2, ending.type = END;

        row = get_index(row);
        tracks[row].push_back(start);
        tracks[row].push_back(ending);
    }

    long long covered_blocks = 0;

    for(int row = 0; row < smallest_free_number; row++)
    {
            sort(all(tracks[row]), compare);

            long long current_track_start = 0;
            int no_of_starts = 0;

            for(int pillar = 0; pillar < tracks[row].size(); pillar++)
            {
                if(tracks[row][pillar].type == START)
                {
                    no_of_starts++;

                    if(current_track_start == 0)
                        current_track_start = tracks[row][pillar].column_no;
                }
                else if(tracks[row][pillar].type == END)
                {
                    no_of_starts--;

                    if(no_of_starts == 0)
                    {
                        int current_track_end = tracks[row][pillar].column_no;

                        covered_blocks += (current_track_end - current_track_start + 1);

                        current_track_start = 0;
                    }
                }
            }
    }

    long long no_of_blocks = no_of_rows*1LL*no_of_columns;
    long long uncovered_blocks = no_of_blocks - covered_blocks;

    printf("%lld\n", uncovered_blocks);
    return 0;
}

