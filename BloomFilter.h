#pragma once

#include "BitMap.h"
#include "HashFunc.h"


template<class K, class HashFun1=__HashFunc1<K>,
class HashFun2=__HashFunc2<K>,
class HashFun3=__HashFunc3<K>,
class HashFun4=__HashFunc4<K>,
class HashFun5=__HashFunc5<K>>
class BloomFilter
{
public:
	BloomFilter(size_t size)
		:_table(size)
		,_capacity(size)
		//,ref(size,0)
	{}

	void Set(const K& key)
	{
		size_t index1=HashFun1()(key);
		size_t index2=HashFun2()(key);
		size_t index3=HashFun3()(key);
		size_t index4=HashFun4()(key);
		size_t index5=HashFun5()(key);

		_table.Set(index1%_capacity);
		_table.Set(index2%_capacity);
		_table.Set(index3%_capacity);
		_table.Set(index4%_capacity);
		_table.Set(index5%_capacity);

		//ref[index1%_capacity]++;
		//ref[index2%_capacity]++;
		//ref[index3%_capacity]++;
		//ref[index4%_capacity]++;
		//ref[index5%_capacity]++;
	}

	//引用计数破坏位图节省空间的特性，因此在布隆过滤器中不支持删除
	//void ReSet(const K& key)
	//{
	//	size_t index1=HashFun1()(key);
	//	size_t index2=HashFun2()(key);
	//	size_t index3=HashFun3()(key);
	//	size_t index4=HashFun4()(key);
	//	size_t index5=HashFun5()(key);

	//	if(ref[index1%_capacity]>1)
	//		ref[index1%_capacity]--;
	//	else
	//	{
	//		ref[index1%_capacity]--;
	//		_table.ReSet(index1%_capacity);
	//	}

	//	if(ref[index2%_capacity]>1)
	//		ref[index2%_capacity]--;
	//	else
	//	{
	//		ref[index2%_capacity]--;
	//		_table.ReSet(index2%_capacity);
	//	}
	//	if(ref[index3%_capacity]>1)
	//		ref[index3%_capacity]--;
	//	else
	//	{
	//		ref[index3%_capacity]--;
	//		_table.ReSet(index3%_capacity);
	//	}
	//	if(ref[index4%_capacity]>1)
	//		ref[index4%_capacity]--;
	//	else
	//	{
	//		ref[index4%_capacity]--;
	//		_table.ReSet(index4%_capacity);
	//	}
	//	if(ref[index5%_capacity]>1)
	//		ref[index5%_capacity]--;
	//	else
	//	{
	//		ref[index5%_capacity]--;
	//		_table.ReSet(index5%_capacity);
	//	}
	//}

	bool IsIn(const K& key)
	{
		size_t index1=HashFun1()(key);
		if(!_table.Test(index1%_capacity))
			return false;

		size_t index2=HashFun2()(key);
		if(!_table.Test(index2%_capacity))
			return false;

		size_t index3=HashFun3()(key);
		if(!_table.Test(index3%_capacity))
			return false;

		size_t index4=HashFun4()(key);
		if(!_table.Test(index4%_capacity))
			return false;

		size_t index5=HashFun5()(key);
		if(!_table.Test(index5%_capacity))
			return false;

		return true;
	}
private:
	BitSet _table;
	//vector<int> ref;
	size_t _capacity;
};
