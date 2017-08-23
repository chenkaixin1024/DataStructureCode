#pragma once

#include <iostream>
using namespace std;

template<class K, size_t M>
struct BTreeNode
{
	//K _keys[M-1];     // 关键字的集合
	//BTreeNode<K, M> _pSub[M];    // 孩子的集合

	// 多给一个关键字：为简化分裂的逻辑
	K _keys[M];     // 关键字的集合
	BTreeNode<K, M>* _pSub[M+1];    // 孩子的集合
	BTreeNode<K, M>* _pParent;
	size_t _size; // 有效关键字的个数

	BTreeNode()
		: _size(0)
		, _pParent(NULL)
	{
		for (size_t idx = 0; idx < M+1; ++idx)
			_pSub[idx] = NULL;
	}
};


template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	BTree()
		: _pRoot(NULL)
	{}

	pair<Node*, int> Find(const K& key)
	{
		if(_pRoot==NULL)
			return pair<Node*,int>((Node*)NULL,-1);

		Node* pcur=_pRoot;
		Node* pNode=pcur;
		while(pcur)
		{
			int idx=0;
			for(idx=0;idx<pcur->_size;idx++)
			{
				if(pcur->_keys[idx]==key)
					return pair<Node*,int>(pcur,idx);
				else if(pcur->_keys[idx]>key)
				{
					break;
				}
			}

			pNode=pcur;
			pcur=pcur->_pSub[idx];
		}


		return pair<Node*,int>(pNode,-1);
	}

	bool Insert(const K& key)
	{
		if(_pRoot==NULL)
		{
			_pRoot=new Node;
			_pRoot->_keys[0]=key;
			_pRoot->_size=1;
			return true;
		}

		pair<Node*,int> p=Find(key);
		if(p.second!=-1)
			return false;

		Node* pcur=p.first;
		Node* pSub=NULL;
		K k=key;

		while(1)
		{
			_InsertKey(pcur,k,pSub);

			if(pcur->_size<M)
				return true;

			int mid=M>>1;
			Node* newnode=new Node;

			int idx=mid+1;
			for(;idx<M;idx++)
			{
				newnode->_keys[newnode->_size]=pcur->_keys[idx];
				newnode->_pSub[newnode->_size++]=pcur->_pSub[idx];
				if(pcur->_pSub[idx])
					pcur->_pSub[idx]->_pParent=newnode;
			}

			newnode->_pSub[newnode->_size]=pcur->_pSub[idx];
			if(pcur->_pSub[idx])
				pcur->_pSub[idx]->_pParent=newnode;

			pcur->_size=pcur->_size-newnode->_size-1;
			if(pcur==_pRoot)
			{
				_pRoot=new Node;
				_pRoot->_keys[0]=pcur->_keys[mid];
				_pRoot->_pSub[0]=pcur;
				_pRoot->_pSub[1]=newnode;
				_pRoot->_size=1;
				pcur->_pParent=_pRoot;
				newnode->_pParent=_pRoot;
				return true;
			}
			else
			{
				k=pcur->_keys[mid];
				pSub=newnode;
				pcur=pcur->_pParent;
			}

		}

		return true;
	}

	void InOrder()
	{
		cout<<" InOrder:";
		_InOrder(_pRoot);
		cout<<endl;
	}

private:
	void _InOrder(Node* pRoot)
	{
		if(pRoot==NULL)
			return ;

		int idx=0;
		for(;idx<pRoot->_size;idx++)
		{
			_InOrder(pRoot->_pSub[idx]);
			cout<<pRoot->_keys[idx]<<" ";
		}

		_InOrder(pRoot->_pSub[idx]);
	}


	void _InsertKey(Node* pCur, const K& key, Node* pSub)
	{
		int idx=pCur->_size-1;
		for(;idx>=0;idx--)
		{
			if(key<pCur->_keys[idx])
			{
				pCur->_keys[idx+1]=pCur->_keys[idx];
				pCur->_pSub[idx+2]=pCur->_pSub[idx+1];
			}
			else
				break;
		}

		pCur->_keys[idx+1]=key;
		pCur->_pSub[idx+2]=pSub;
		if(pSub)
			pSub->_pParent=pCur;
		pCur->_size++;
	}

private:
	Node* _pRoot;
};

