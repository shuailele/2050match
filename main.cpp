#include <iostream>
using namespace std;

int main() {
    cout<<"请输入数据组数:"<<endl;
    int z;
    cin>>z;
    for(int j=0; j<z; j++)
    {
    int n, m ,k;
    int *mp;            //用于存储n个学生的所属学校
    cout<<"请分别输入选手数量、学校数量以及k"<<endl;
    cin>>n>>m>>k;
    mp=new int[n];
    cout<<"请按照成绩从好到差给出"<<n<<"个选手所属学校"<<endl;
    for(int i=0; i<n; i++)
        cin>>mp[i];
    int PASS=0;
    int *np;           //用于存储每个学校的学生数量;
    np=new int[m];
    for(int i=0; i<m; i++)      //将每个学校的学生数初始化为0
        np[i]=0;
    for(int i=0; i<n; i++)         //计算出每个学校的学生数
        np[mp[i]-1]++;
    int *np_record;             //用于记录当前学校的学生位置
    np_record=new int[m];
    for(int i=0; i<m; i++)
        np_record[i]=0;
    for(int i=0; i<n/2; i++)
    {
        np_record[mp[i]-1]++;
        if(np_record[mp[i]-1]<=(np[mp[i]-1]/k)) PASS++;
    }
    cout<<"发出的PASS有"<<PASS<<"个"<<endl<<endl;
    delete []mp;
    delete []np;
    delete[]np_record;
    }
    return 0;
}