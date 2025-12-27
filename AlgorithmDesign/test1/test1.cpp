#include<iostream>
#include<fstream>
// 棋盘覆盖
// 棋盘覆盖问题要求用下图所示的4种不同形状的L型骨牌覆盖给定棋盘上除特殊方格以外的所有方格，且任何2个L型骨牌不得重叠覆盖。
using namespace std;

const int N = 2048;
int board[N][N];

int flag = 1;//L型骨牌编号
int num;//累计测试次数
int k,x,y;//输入数据

//算法策略--分治法
void cover(int x,int y,int p,int q,int size)
{
    if(size == 1)
        return;
    int t = flag++;
    int s = size / 2;
    // 特殊棋子是否在左上角
    if(p < x + s && q < y + s)
        cover(x,y,p,q,s);
    else
    {
        board[x+s-1][y+s-1] = t;
        cover(x,y,x+s-1,y+s-1,s);
    }

    //特殊棋子是否在右上角
    if(p < x + s && q >= y + s)
        cover(x,y+s,p,q,s);
    else
    {
        board[x+s-1][y+s] = t;
        cover(x,y+s,x+s-1,y+s,s);
    }

    // 特殊棋子是否在左下角
    if(p >= x + s && q < y + s)
        cover(x+s,y,p,q,s);
    else
    {
        board[x+s][y+s-1] = t;
        cover(x+s,y,x+s,y+s-1,s);
    }

    // 特殊棋子是否在右下角
    if(p >= x + s && q >= y + s)
        cover(x+s,y+s,p,q,s);
    else
    {
        board[x+s][y+s] = t;
        cover(x+s,y+s,x+s,y+s,s);
    }
}

void print_save(int size)
{
    ofstream outfile("Matrix.txt");
    for(int i = 1;i <= size;i++)
    {
        for(int j = 1;j <= size;j++)
        {
            if(i == x && j == y)
            {
                cout << "  # ";
                outfile << "# ";
            }
            else
            {
                printf("%3d ",board[i][j]);
                outfile << board[i][j] << " ";
            }
        }
        cout << endl;
        outfile << endl;
    }
    outfile.close();
}

int main()
{
    while(cin >> k >> x >> y)//循环处理多组数据
    {
        int size = 1 << k;// 棋盘大小为2^k
        printf("Case %d: n=%d\n",++num,size);
        // printf("size = %d, x = %d, y = %d\n",size,x,y);
        cover(1,1,x,y,size);//调用算法
        print_save(size);//输出及保存结果
        flag = 1;
    }
    return 0;
}