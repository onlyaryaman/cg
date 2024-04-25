#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main(){
    double a,b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    int gd=DETECT,gm,color; 
    initgraph(&gd, &gm,NULL);
    double x=0,y=b;
    double po=(a*a)/4 + b*b - (a*a)*b;
    vector<pair<int,int> > v;
    v.push_back({x,y});
    double dx=0,dy=2*a*a*b;
    while(dx<dy){
        if(po<0) {
            po=po + b*b*(2*x + 3);
            x++;
            v.push_back({x,y});
            v.push_back({x,-y});
            v.push_back({-x,y});
            v.push_back({-x,-y});
        } else {
            po=po + b*b*(2*x + 3) - a*a*(2*y - 2);
            x++;
            y--;
            v.push_back({x,y});
            v.push_back({x,-y});
            v.push_back({-x,y});
            v.push_back({-x,-y});
        }
        dx=2*b*b*x,dy=2*a*a*y;
    }
    po=(x*x)/(a*a) + (y*y)/(b*b) - 1;
    while(y>0){
        if(po<0){
            po=po + b*b*(2*x + 2) - a*a*(2*y - 3);
            x++;
            y--;
            v.push_back({x,y});
            v.push_back({x,-y});
            v.push_back({-x,y});
            v.push_back({-x,-y});
        }else{
            po=po - a*a*(2*y - 3);
            y--;
            v.push_back({x,y});
            v.push_back({x,-y});
            v.push_back({-x,y});
            v.push_back({-x,-y});
        }
        dx=2*b*b*x,dy=2*a*a*dx;
    }
    for(int i=0;i<v.size();i++){
        putpixel(200+v[i].first,200+v[i].second,color);
    }
    getch();  
    closegraph();
    return 0;
}