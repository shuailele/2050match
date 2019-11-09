#include <iostream>
using namespace std;

struct Message
{
    int n;
    int m;
    int k;
    double a;
    double b;
    double c;
};

void input(Message *p);
double compare(Message *p);
void show(double price);

int main() {
    cout<<"将要输入几组数据:"<<endl;
    int n;
    cin>>n;
    Message *p=new Message[n];

    double price=0;
    for(int i=0; i<n; i++)
    {
        input(p+i);
    price=compare(p+i);
    show(price);
    }
    return 0;
}

void input(Message *p)
{
        cout<<"请分别输入男生人数，女生人数，情侣对数，双人间，三人间以及情侣房的价格"<<endl;
        cin>>p->n>>p->m>>p->k>>p->a>>p->b>>p->c;
}

double compare(Message *p)
{
    double price=0;
        if((p->c/2<p->a/2) && (p->c/2<p->b/3))
        {
            price+=p->k*p->c;
            if((p->a/2)<=(p->b/3))
            {
                if((p->n+p->k)%2!=0) price+=(p->n+p->k)/2*p->a+p->a;
                else price+=(p->n+p->k)/2*p->a;
                if(((p->m+p->k)%2!=0)) price+=(p->m+p->k)/2*p->a+p->a;
                else price+=(p->m+p->k)/2*p->a;
            }
            else
            {
                if((p->n+p->k)%3!=0)
                {
                    if(p->a<=p->b) price+=(p->n+p->k)/3*p->b+p->a;
                    if(p->a>p->b) price+=(p->n+p->k)/3*p->b+p->b;
                }
                else price+=(p->n+p->k)/3*p->b;
                if((p->m+p->k)%3!=0)
                {
                    if(p->a<=p->b) price+=(p->m+p->k)/3*p->b+p->a;
                    if(p->a>p->b) price+=(p->n+p->k)/3*p->b+p->b;
                }
            }
        }

        else if((p->b/3<=p->c/2) && (p->b/3<p->a/2))
        {
            price+=(p->n+p->k)/3*p->b;
            price+=(p->m+p->k)/3*p->b;
            int remain_n=(p->n+p->k)%3, remain_m=(p->m+p->k)%3;
            if((remain_n==1 && remain_m==0) || (remain_n==0 && remain_m==1))
            {
                if(p->c<=p->a && p->c<=p->b) price+=p->c;
                else if(p->b<=p->a && p->b<=p->c) price+=p->b;
                else if(p->a<=p->b && p->a<=p->c) price+=p->a;
            }
            else if((remain_n==2 && remain_m==0) || (remain_n==0 && remain_m==2))
            {
                if(2*p->c<=p->a && 2*p->c<=p->b) price+=p->c*2;
                else if(p->b<=p->a && p->b<=2*p->c) price+=p->b;
                else if(p->a<=p->b && p->a<=2*p->c) price+=p->a;
            }
            else if(remain_n==1 && remain_m==1)
            {
                if(p->c<=2*p->a && p->c<=2*p->b) price+=p->c;
                else if(2*p->b<=2*p->a && 2*p->b<=p->c) price+=p->b*2;
                else if(2*p->a<=2*p->b && 2*p->a<=p->c) price+=p->a*2;
            }
            else
            {
                if(2*p->c<=2*p->a && 2*p->c<=2*p->b) price+=p->c*2;
                else if(2*p->b<=2*p->a && 2*p->b<=2*p->c) price+=p->b*2;
                else if(2*p->a<=2*p->b && 2*p->a<=2*p->c) price+=p->a*2;
            }
        }

        else if(((p->a/2<=p->c/2) && (p->a/2<p->b/3))||((p->a/2<p->c/2) && (p->a/2<=p->b/3)))
        {
            price+=(p->n+p->k)/2*p->a;
            price+=(p->m+p->k)/2*p->a;
            int remain_n=(p->n+p->k)%2, remain_m=(p->m+p->k)%2;
            if((remain_n==1 && remain_m==0)||(remain_n==0 && remain_m==1)) price+=p->a;
            else if(remain_n==1&&remain_m==1)
            {
                if(2*p->a<p->c) price+=p->a*2;
                else price+=p->c;
            }
        }
        else if((p->a/2)==(p->b/3)==(p->c/2))
        {
            price+=(p->n+p->m+2*p->k)/2*p->a;
            if((p->n+p->m+2*p->k)%2!=0) price+=p->a;
        }
    return price;
}

void show(double price)
{
    cout<<"所有人住下来的最小花费为:";
    cout<<price<<endl<<endl;
}