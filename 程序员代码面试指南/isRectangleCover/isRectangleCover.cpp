#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isRectangleCover(vector<vector<int> > rectangles)
{
    unordered_set<string> s;

    int minx = INT_MAX;
    int maxx = -1;

    int miny = INT_MAX;
    int maxy = -1;

    int leftx = -1;
    int lefty = -1;

    int rightx = -1;
    int righty = -1;

    int Area = 0;
    int tmparea = 0;
    int diffy = 0;
    int diffx = 0;
    int totalArea = 0;

    for(int i = 0; i < rectangles.size(); i++)
    {
        leftx = rectangles[i][0];
        lefty = rectangles[i][1];
        rightx = rectangles[i][2];
        righty = rectangles[i][3];
        diffy = max(lefty, righty) - min(lefty, righty);
        diffx = max(leftx, rightx) - min(leftx, rightx);

        maxx = max(maxx, max(leftx, rightx));
        maxy = max(maxy, max(lefty, righty));
        minx = min(minx, min(leftx, rightx));
        miny = min(minx, min(lefty, righty));
        tmparea = diffy * diffx;
        totalArea += tmparea;
        string s1 = to_string(leftx) + "_" + to_string(lefty);
        string s2 = to_string(leftx) + "_" + to_string(righty);
        string s3 = to_string(rightx) + "_" + to_string(righty);
        string s4 = to_string(rightx) + "_" + to_string(lefty);
        if(!s.count(s1))
        {
            s.insert(s1);
        }
        else
        {
            s.erase(s1);
        }
        if(!s.count(s2))
        {
            s.insert(s2);
        }
        else
        {
            s.erase(s2);
        }
        if(!s.count(s3))
        {
            s.insert(s3);
        }
        else
        {
            s.erase(s3);
        }
        if(!s.count(s4))
        {
            s.insert(s4);
        }
        else
        {
            s.erase(s4);
        }
    }
    string r1 = to_string(maxx) + "_" + to_string(maxy);
    string r2 = to_string(maxx) + "_" + to_string(miny);
    string r3 = to_string(minx) + "_" + to_string(maxy);
    string r4 = to_string(minx) + "_" + to_string(miny);



    if(s.count(r1)!=1 || s.count(r2)!=1 ||
       s.count(r3)!=1 || s.count(r4)!=1 ||
       s.size() != 4)
    {
        return false;
    }

    Area = (maxx-minx) * (maxy - miny);
    if(Area == totalArea)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int> > rect;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(3);
    rect.push_back(tmp);
    tmp.clear();

    tmp.push_back(3);
    tmp.push_back(1);
    tmp.push_back(4);
    tmp.push_back(2);
    rect.push_back(tmp);
    tmp.clear();

    tmp.push_back(3);
    tmp.push_back(2);
    tmp.push_back(4);
    tmp.push_back(4);
    rect.push_back(tmp);
    tmp.clear();

    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(2);
    tmp.push_back(4);
    rect.push_back(tmp);
    tmp.clear();

    tmp.push_back(2);
    tmp.push_back(3);
    tmp.push_back(3);
    tmp.push_back(4);
    rect.push_back(tmp);
    tmp.clear();

    cout << isRectangleCover(rect) << endl;


}


