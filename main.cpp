#include<bits/stdc++.h>
using namespace std;

class coordinate{
    float xnum;
    float ynum;
public:
    coordinate(){
        xnum = 0.0;
        ynum = 0.0;
    }
    void setCoordinate(float x,float y){
        xnum = x;
        ynum = y;
    }
    void DisplayPoint(){
        cout<<"x-coordinate: "<<xnum<<endl;
        cout<<"y-coordinate: "<<ynum<<endl;
    }
    coordinate operator - (coordinate obj){
        coordinate temp;
        temp.xnum = xnum-obj.xnum;
        temp.ynum = ynum-obj.ynum;
        return temp;
    }
    coordinate operator ~(){
        xnum = float(abs(xnum));
        ynum = float(abs(ynum));
    }
    coordinate operator *(){
        xnum = xnum*xnum;
        ynum = ynum*ynum;
    }
    float operator +(){
        return xnum+ynum;
    }
    void DisplayLength(float ans){
        cout<<ans<<endl;
    }
};

void DisaplayMenu(){
    cout<<"enter 1 to set point :"<<endl;
    cout<<"enter 2 to display point : "<<endl;
    cout<<"enter 3 to display length : "<<endl;
    cout<<"enter 4 to Check right triangle : "<<endl;
    cout<<"enter 5 to exit : "<<endl;
}
void CheckRightTraingle(vector<float> &v){
    if(v[0] == v[1] == v[2] == 0){
        cout<<"All the given points coincide"<<endl;
        return;
    }
    if(v[0] == v[1] == 0){
        cout<<"The given points form a straight line not a right triangle"<<endl;
        return;
    }
    if(v[2] == v[1]+v[0]){
        cout<<"Yes,the given points form a right triangle"<<endl;
    }
    else{
        cout<<"The given points do not form a right triangle"<<endl;
    }
}
int main(){
    DisaplayMenu();
    coordinate pt1 = coordinate(),pt2 = coordinate(),pt3 = coordinate();
    int choice;
    cin>>choice;
    vector<float> v;
    while(true) {
        if (choice == 1) {
            int k;
            cout << "Enter 1 to set coordinate for 1st point" << endl;
            cout << "Enter 2 to set coordinate for 2nd point" << endl;
            cout << "Enter 3 to set coordinate for 3rd point" << endl;
            cin >> k;
            float x, y;
            cout << "Enter x-coordinate :" << endl;
            cin >> x;
            cout << "Enter y-coordinate :" << endl;
            cin >> y;
            if (k == 1) {
                pt1.setCoordinate(x, y);
                ~pt1;
            } else if (k == 2) {
                pt2.setCoordinate(x, y);
                ~pt2;
            } else {
                pt3.setCoordinate(x, y);
                ~pt3;
            }
            DisaplayMenu();
            cin >> choice;
        }
        if (choice == 2) {
            cout<<"Point-1 "<<endl;
            pt1.DisplayPoint();
            cout<<"Point-2 "<<endl;
            pt2.DisplayPoint();
            cout<<"Point-3 "<<endl;
            pt3.DisplayPoint();
            DisaplayMenu();
            cin >> choice;
        }
        if (choice == 3) {
            int k;
            cout << "Enter 1 to Display length of 1st and 2nd points" << endl;
            cout << "Enter 2 to Display length of 2nd and 3rd points" << endl;
            cout << "Enter 3 to Display length of 3rd and 1st points" << endl;
            cin >> k;
            if(k == 1){
                coordinate temp = pt1-pt2;
                temp.operator~();
                temp.operator*();
                float ans = temp.operator+();
                cout<<"Length between points 1 and 2: ";
                temp.DisplayLength(sqrt(ans));
            }
            else if(k == 2){
                coordinate temp = pt2-pt3;
                temp.operator~();
                temp.operator*();
                float ans = temp.operator+();
                cout<<"Length between points 2 and 3: ";
                temp.DisplayLength(sqrt(ans));
            }
            else{
                coordinate temp = pt3-pt1;
                temp.operator~();
                temp.operator*();
                float ans = temp.operator+();
                cout<<"Length between points 3 and 1: ";
                temp.DisplayLength(sqrt(ans));
            }
            DisaplayMenu();
            cin >> choice;
        }
        if (choice == 4) {
            coordinate temp1 = pt1-pt2;
            temp1.operator~();
            temp1.operator*();
            float ans1 = temp1.operator+();
            v.push_back(ans1);
            coordinate temp2 = pt2-pt3;
            temp2.operator~();
            temp2.operator*();
            float ans2 = temp2.operator+();
            v.push_back(ans2);
            coordinate temp3 = pt3-pt1;
            temp3.operator~();
            temp3.operator*();
            float ans3 = temp3.operator+();
            v.push_back(ans3);
            sort(v.begin(),v.end());
            CheckRightTraingle(v);
            DisaplayMenu();
            cin>>choice;
        }
        if (choice == 5) {
            return 0;
        }
    }


}

































