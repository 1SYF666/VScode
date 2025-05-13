#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
};

static bool cmp1(Point a,Point b,int centerx,int centery)
{
    int dis_a = abs(a.x-centerx)+abs(a.y-centery);
    int dis_b = abs(b.x-centerx)+abs(b.y-centery);
    if(dis_a != dis_b)
    {
        return dis_a < dis_b;
    }
    else
    {
        if(a.x!=b.x)
            return a.x<b.x;
        else
            return a.y<b.y;
    }
}


int main()
{
    int w = 0,h= 0;
    int m = 0;
    int k = 0;

    cin>>w>>h;
    cin>>m;
    cin>>k;
    int image[h][w]={0};
    for(int i =0;i<h;i++)
    {
        for(int j =0;j<w;j++)
        {
            cin>>image[i][j];
        }
    }

    int centerx = (w-1)/2;
    int centery = (h-1)/2;
    vector<Point> m_image;
    for(int i = 0;i<h;i++)
    {
        for(int j = 0;j<w;j++)
        {
            if(image[i][j]==m)
            {
                Point point;
                point.x = j;
                point.y = i; 
                m_image.push_back(point);
            }
        }
    }
    cout<<m_image.size()<<endl;

    auto cmp = [centerx, centery](Point a, Point b) {
        int dis_a = abs(a.x - centerx) + abs(a.y - centery);
        int dis_b = abs(b.x - centerx) + abs(b.y - centery);
        if (dis_a != dis_b) {
            return dis_a < dis_b;
        } else {
            if (a.x != b.x)
                return a.x < b.x;
            else
                return a.y < b.y;
        }
    };


    sort(m_image.begin(),m_image.end(),cmp);
    int count = m_image.size();
    if(count > k)
    {
        count = k;
    }

    
    // 输出
    for(int i = 0;i<count;i++)
    {
        if(i<count-1)
        cout<<m_image[i].x<<" "<<m_image[i].y<<" ";
        else
        cout<<m_image[i].x<<" "<<m_image[i].y<<endl;
    }


    // for(int i =0;i<h;i++)
    // {
    //     for(int j = 0;j<w;j++)
    //     {
    //         if(j<w-1)
    //         {
    //             cout<<image[i][j]<<" ";
    //         }
    //         else
    //         cout<<image[i][j];
    //     }
    //     cout<<endl;
    // }

    







    return 0;
}



