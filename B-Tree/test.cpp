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

//1. 猎人把一对兔子婴儿(一公一母称为一对)放到一个荒岛上，两年之后，它们生下一对小兔，之后开始每年都会生下一对小兔。生下的小兔又会以同样的方式继续繁殖。
//2. 兔子的寿命都是x(x>=3)年，并且生命的最后一年不繁殖。
//3. 如果岛上的兔子多于10对，那么猎人会每年在兔子们完成繁殖或者仙逝之后，从岛上带走两对最老的兔子。
//	请问y年(y>=3)后荒岛上所有的兔子加起来多少岁?(注意, 在条件3执行完之后)
//
//输入: 从命令行输入两行整数，第一行是x，第二行是y
//输出: y年后荒岛上所有的兔子岁数的总和

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