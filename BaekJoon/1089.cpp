#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
using namespace std;
char number[10][5][3], inputNum[10][5][3];
int n;
double num = 0;
double sum = 0;
void convert(char number[10][5][3], vector<string> &data)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 4 * i; j < 4 * i + 3; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                number[i][k][j % 4] = data[k][j];
            }
        }
    }
}
vector<int> posNumber[10];
int main()
{
    //freopen("C:\\Users\\lee01\\VScode\\C++\\input.txt", "r+", stdin);
    //init
    vector<string> data = {
        "###...#.###.###.#.#.###.###.###.###.###",
        "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
        "#.#...#.###.###.###.###.###...#.###.###",
        "#.#...#.#.....#...#...#.#.#...#.#.#...#",
        "###...#.###.###...#.###.###...#.###.###"};
    convert(number, data);
    cin >> n;
    vector<string> input;
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        input.push_back(s);
    }
    convert(inputNum, input);
    //make pos list
    for (int level = 0; level < n; level++)
    {
        for (int i = 0; i < 10; i++)
        {
            int r, c;
            for (r = 0; r < 5; r++)
            {
                for (c = 0; c < 3; c++)
                {
                    if (number[i][r][c] == '.' && inputNum[level][r][c] == '#')
                    {
                        break;
                    }
                }
                if (c != 3)
                {
                    break;
                }
            }
            if (r == 5 && c == 3)
            {
                posNumber[level].push_back(i);
            }
        }
    }
    //check pos
    for(int i=0;i<n;i++){
        if(posNumber[i].size()==0){
            cout << -1;
            return 0;
        }
    }
    num=1;
    for(int i=0;i<n;i++){
        num*=posNumber[i].size();
    }
    sum=0;
    for(int i=0;i<n;i++){
        for(int t:posNumber[i]){
            sum+=t*num/posNumber[i].size()*pow(10,n-1-i);
        }
    }
    printf("%.10f",sum/num); 
}