//
//  main.cpp
//  ChessKnight
//
//  Created by 陳柏廷 on 2021/3/1.
//

#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <fstream>


using namespace std;


int const chessboard_size=12;


// show a vector
void show_vec(vector<int> vec)
{
    cout<<"{";
    for (int i=0;i<vec.size();i++)
    {
        if (i<vec.size()-1)
        {cout<<vec[i]<<",";}
        else
        {cout<<vec[i]<<"}"<<endl;}
    }
}

// show a vector
void show_vec(vector<pair<int,int>> vec)
{
    cout<<"{";
    for (int i=0;i<vec.size();i++)
    {
        if (i<vec.size()-1)
        {cout<<"{"<<vec[i].first<<","<<vec[i].second<<"}"<<",";}
        else
        {cout<<"{"<<vec[i].first<<","<<vec[i].second<<"}}"<<endl;}
    }
}

// show a vector
void show_vec(vector<vector<int>> vec)
{
    cout<<"{";
    
    cout<<"{";
    for (int j=0;j<vec[0].size();j++)
    {
        if (j<vec[0].size()-1)
        {cout<<vec[0][j]<<",";}
        else
        {cout<<vec[0][j];}
    }
    cout<<"},"<<endl;
    
    for (int i=1;i<vec.size();i++)
    {
        cout<<" {";
        for (int j=0;j<vec[i].size();j++)
        {
            if (j<vec[i].size()-1)
            {cout<<vec[i][j]<<",";}
            else
            {cout<<vec[i][j];}
        }
        cout<<"}";
        if (i<vec.size()-1)
        {
            cout<<","<<endl;
        }
    }
    cout<<"}"<<endl;
}


int count_step(pair<int,int> start,pair<int,int> end,bool show=false,int input_size=chessboard_size)
{
    int initial=-1;
    vector<vector<int>> chessboard(input_size,vector<int> (input_size,initial));
    chessboard[start.first][start.second]=0;
    int i1,i2;
    for (int step=0;step<input_size;step++)
    {
        for (i1=0;i1<input_size;i1++)
        {
            for (i2=0;i2<input_size;i2++)
            {
                if (chessboard[i1][i2]==step)
                {
                    if (i1+1<input_size and i2+2<input_size and i1+1>=0 and i2+2>=0)
                    {
                        if (chessboard[i1+1][i2+2]==initial)
                        {
                            chessboard[i1+1][i2+2]=step+1;
                        }
                    }
                    if (i1+2<input_size and i2+1<input_size and i1+1>=0 and i2+2>=0)
                    {
                        if (chessboard[i1+2][i2+1]==initial)
                        {
                            chessboard[i1+2][i2+1]=step+1;
                        }
                    }
                    if (i1-1<input_size and i2+2<input_size and i1-1>=0 and i2+2>=0)
                    {
                        if (chessboard[i1-1][i2+2]==initial)
                        {
                            chessboard[i1-1][i2+2]=step+1;
                        }
                    }
                    if (i1-2<input_size and i2+1<input_size and i1-2>=0 and i2+1>=0)
                    {
                        if (chessboard[i1-2][i2+1]==initial)
                        {
                            chessboard[i1-2][i2+1]=step+1;
                        }
                    }
                    if (i1+1<input_size and i2-2<input_size and i1+1>=0 and i2-2>=0)
                    {
                        if (chessboard[i1+1][i2-2]==initial)
                        {
                            chessboard[i1+1][i2-2]=step+1;
                        }
                    }
                    if (i1+2<input_size and i2-1<input_size and i1+2>=0 and i2-1>=0)
                    {
                        if (chessboard[i1+2][i2-1]==initial)
                        {
                            chessboard[i1+2][i2-1]=step+1;
                        }
                    }
                    if (i1-1<input_size and i2-2<input_size and i1-1>=0 and i2-2>=0)
                    {
                        if (chessboard[i1-1][i2-2]==initial)
                        {
                            chessboard[i1-1][i2-2]=step+1;
                        }
                    }
                    if (i1-2<input_size and i2-1<input_size and i1-2>=0 and i2-1>=0)
                    {
                        if (chessboard[i1-2][i2-1]==initial)
                        {
                            chessboard[i1-2][i2-1]=step+1;
                        }
                    }
                }
            }
        }
    }
    if (show)
    {
        show_vec(chessboard);
    }
    return chessboard[end.first][end.second];
}


int main()
{
    srand((unsigned) time(NULL));
    int x1,y1,x2,y2,x3,y3,x4,y4;
    pair<int,int> pos1,pos2,pos3,pos4;
    int temp;
    
    vector<vector<int>> AllVec;
    time_t start=clock();
    for (int i=0;i<500000;i++)
    {
        x1=rand()%chessboard_size;
        y1=rand()%chessboard_size;
        x2=rand()%chessboard_size;
        y2=rand()%chessboard_size;
        x3=rand()%chessboard_size;
        y3=rand()%chessboard_size;
        x4=rand()%chessboard_size;
        y4=rand()%chessboard_size;
        pos1={x1,y1};
        pos2={x2,y2};
        pos3={x3,y3};
        pos4={x4,y4};
        temp=count_step(pos1,pos2)+count_step(pos1,pos3)+count_step(pos1,pos4)+count_step(pos2,pos3)+count_step(pos2,pos4)+count_step(pos3,pos4);
        AllVec.push_back({x1,y1,x2,y2,x3,y3,x4,y4,temp});
    }
    
    cout<<AllVec.size()<<endl;
    
    
    cout<<"writing csv..."<<endl;
    
    

    // write in csv
    long total_lines=AllVec.size();
    std::ofstream Chess("/Users/chenboting/Desktop/ChessKnight.csv");
    long lines;
    int words;
    for (lines=0;lines<total_lines;lines++)
    {
        for (words=0;words<9;words++)
        {
            if (words!=8)
            {
                Chess<<AllVec[lines][words]<<",";
            }
            else
            {
                Chess<<AllVec[lines][words];
            }
        }
        Chess<<"\n";
    }

    Chess.close();


    
    
    time_t end=clock();
    
    

    cout<<double(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
