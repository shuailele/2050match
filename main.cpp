#include <iostream>
using namespace std;

int main() {
    cout<<"��������������:"<<endl;
    int z;
    cin>>z;
    for(int j=0; j<z; j++)
    {
    int n, m ,k;
    int *mp;            //���ڴ洢n��ѧ��������ѧУ
    cout<<"��ֱ�����ѡ��������ѧУ�����Լ�k"<<endl;
    cin>>n>>m>>k;
    mp=new int[n];
    cout<<"�밴�ճɼ��Ӻõ������"<<n<<"��ѡ������ѧУ"<<endl;
    for(int i=0; i<n; i++)
        cin>>mp[i];
    int PASS=0;
    int *np;           //���ڴ洢ÿ��ѧУ��ѧ������;
    np=new int[m];
    for(int i=0; i<m; i++)      //��ÿ��ѧУ��ѧ������ʼ��Ϊ0
        np[i]=0;
    for(int i=0; i<n; i++)         //�����ÿ��ѧУ��ѧ����
        np[mp[i]-1]++;
    int *np_record;             //���ڼ�¼��ǰѧУ��ѧ��λ��
    np_record=new int[m];
    for(int i=0; i<m; i++)
        np_record[i]=0;
    for(int i=0; i<n/2; i++)
    {
        np_record[mp[i]-1]++;
        if(np_record[mp[i]-1]<=(np[mp[i]-1]/k)) PASS++;
    }
    cout<<"������PASS��"<<PASS<<"��"<<endl<<endl;
    delete []mp;
    delete []np;
    delete[]np_record;
    }
    return 0;
}