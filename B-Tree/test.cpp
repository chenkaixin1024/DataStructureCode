#include "BTree.h"


void TestBTree()
{
	BTree<int, 3> t;
	t.Insert(10);
	t.Insert(30);
	t.Insert(20);
	t.Insert(40);
	t.Insert(50);
	t.Insert(38);
	t.Insert(35);
	t.InOrder();
}

int main()
{
	TestBTree();
	return 0;
}



//
//#include <iostream>
//using namespace std;

//1. ���˰�һ������Ӥ��(һ��һĸ��Ϊһ��)�ŵ�һ���ĵ��ϣ�����֮����������һ��С�ã�֮��ʼÿ�궼������һ��С�á����µ�С���ֻ���ͬ���ķ�ʽ������ֳ��
//2. ���ӵ���������x(x>=3)�꣬�������������һ�겻��ֳ��
//3. ������ϵ����Ӷ���10�ԣ���ô���˻�ÿ������������ɷ�ֳ��������֮�󣬴ӵ��ϴ����������ϵ����ӡ�
//	����y��(y>=3)��ĵ������е����Ӽ�����������?(ע��, ������3ִ����֮��)
//
//����: ������������������������һ����x���ڶ�����y
//���: y���ĵ������е������������ܺ�

//#include <list>
//
////struct Rabbits
////{
////	int age;
////};
//
//int result(int x,int y)
//{
//	list<int> q;
//	q.push_back(0);
//	int year=0;
//	for(year=0;year<y;y++)
//	{
//		int idx=0;
//		int num=q.size();
//		if(num>10)
//		{
//			num-=2;
//			q.pop_front();
//			q.pop_front();
//		}
//		list<int>::iterator it=q.begin();
//
//		for(idx=0;idx<num;idx++)
//		{
//			int age=*it;
//			age/=2;
//			if(age>=3&&age<x)
//			{
//				q.push_back(0);
//			}
//			(*it)+=2;
//			it++;
//			if(q.size()>10)
//			{
//				q.pop_front();
//				q.pop_front();
//			}
//			if(age==x)
//				q.pop_front();
//		}
//	}
//
//	int i=0;
//	int ret=0;
//	list<int>::iterator it=q.begin();
//	for(i=0;i<q.size();i++)
//	{
//		ret+=*it;
//		it++;
//	}
//
//	return ret;
//}
//
//void funtest()
//{
//	int m=0;
//	int n=0;
//	cin>>m;
//	cin>>n;
//	cout<<result(m,n)<<endl;
//}
//
//int main()
//{
//	funtest();
//	return 0;
//}