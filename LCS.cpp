//找连续的相同字串
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
//str1为横向，str2为纵向
const string LCS(const string& str1,const string& str2){
    int xlen=str1.size();       //横向长度
    vector<int> tmp(xlen);        //保存矩阵的上一行
    vector<int> arr(tmp);     //当前行
    int ylen=str2.size();       //纵向长度
    int maxele=0;               //矩阵元素中的最大值
    int pos=0;                  //矩阵元素最大值出现在第几列
    for(int i=0;i<ylen;i++){
        string s=str2.substr(i,1);
        arr.assign(xlen,0);     //数组清0
        for(int j=0;j<xlen;j++){
            if(str1.compare(j,1,s)==0){
                if(j==0)
                    arr[j]=1;
                else
                    arr[j]=tmp[j-1]+1;
                if(arr[j]>maxele){
                    maxele=arr[j];
                    pos=j;
                }
            }       
        }
//      {
//          vector<int>::iterator iter=arr.begin();
//          while(iter!=arr.end())
//              cout<<*iter++;
//          cout<<endl;
//      }
        tmp.assign(arr.begin(),arr.end());
    }
    string res=str1.substr(pos-maxele+1,maxele);
    return res;
}
int main(){
    string str1("21232523311324");
    string str2("312123223445");
    string lcs=LCS(str1,str2);
    cout<<lcs<<endl;
    return 0;
}

//找不连续的最大字串
#include<iostream>
#include<cstring>
#include<stack>
#include<utility>
#define LEFTUP 0
#define LEFT 1
#define UP 2
using namespace std;
int Max(int a,int b,int c,int *max){            //找最大者时a的优先级别最高，c的最低.最大值保存在*max中
    int res=0;          //res记录来自于哪个单元格
    *max=a;
    if(b>*max){
        *max=b;
        res=1;
    }
    if(c>*max){
        *max=c;
        res=2;
    }
    return res;
}
//调用此函数时请注意把较长的字符串赋给str1,这主要是为了在回溯最长子序列时节省时间。如果没有把较长的字符串赋给str1不影响程序的正确执行。
string LCS(const string &str1,const string &str2){
    int xlen=str1.size();               //横向长度
    int ylen=str2.size();               //纵向长度
    if(xlen==0||ylen==0)                //str1和str2中只要有一个为空，则返回空
        return "";
    pair<int,int> arr[ylen+1][xlen+1];    //构造pair二维数组，first记录数据，second记录来源
    for(int i=0;i<=xlen;i++)         //首行清0
        arr[0][i].first=0;
    for(int j=0;j<=ylen;j++)         //首列清0
        arr[j][0].first=0;
    for(int i=1;i<=ylen;i++){
        char s=str2.at(i-1);
        for(int j=1;j<=xlen;j++){
            int leftup=arr[i-1][j-1].first;
            int left=arr[i][j-1].first;
            int up=arr[i-1][j].first;
            if(str1.at(j-1)==s)         //C1==C2
                leftup++;
            int max;
            arr[i][j].second=Max(leftup,left,up,&arr[i][j].first);
//          cout<<arr[i][j].first<<arr[i][j].second<<" ";
        }
//      cout<<endl;
    }       /*矩阵构造完毕*/
    //回溯找出最长公共子序列
    stack<int> st;
    int i=ylen,j=xlen;
    while(i>=0&&j>=0){
        if(arr[i][j].second==LEFTUP){
            if(arr[i][j].first==arr[i-1][j-1].first+1)
                st.push(i);
            --i;
            --j;
        }
        else if(arr[i][j].second==LEFT){
            --j;
        }
        else if(arr[i][j].second==UP){
            --i;
        }
    }
    string res="";
    while(!st.empty()){
        int index=st.top()-1;
        res.append(str2.substr(index,1));
        st.pop();
    }
    return res;
}
int main(){
    string str1="GCCCTAGCG";
    string str2="GCGCAATG";
    string lcs=LCS(str1,str2);
    cout<<lcs<<endl;
    return 0;
}