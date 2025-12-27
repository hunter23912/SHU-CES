#include "Net.h"

int main()
{
    //              0    1    2    3    4    5    6    7
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int n = sizeof(vexs) / sizeof(vexs[0]);
    int w[8][8] = {
        //     A  B  C  D  E  F  G
        /*A*/ {0, 1, 0, 1, 1, 1, 0},
        /*B*/ {0, 0, 0, 0, 0, 0, 0},
        /*C*/ {0, 0, 0, 0, 0, 0, 0},
        /*D*/ {0, 0, 0, 0, 0, 0, 0},
        /*E*/ {0, 0, 0, 1, 0, 0, 0},
        /*F*/ {0, 0, 0, 0, 1, 0, 1},
        /*G*/ {1, 0, 0, 0, 0, 0, 0},
    };
    Net<char, int> net(vexs, n);

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (w[r][c] != 0)
                net.Insertarc(r, c, w[r][c]);
        }
    }
    net.show();
    cout << endl;
    if (net.search_path('b', 'F', 'C') == 1)
        cout << "YES, WAY FOUND!" << endl;
    else
        cout << "NO, WAY NOT FOUND!" << endl;
    cout << endl;
    cout << "the degree of the graph is " << net.max_degree() << endl;
    return 0;
}