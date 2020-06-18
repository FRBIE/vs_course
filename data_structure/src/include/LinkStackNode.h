﻿/*
*
* Create By Kaijin Cui,2018
*
*/


#pragma once

#include "basic.h"


template<typename T> struct LinkStackNode
{
	T data;
	LinkStackNode<T> *next;
};

template<typename T> void InitStack(LinkStackNode<T> *&s)
{
	s = new LinkStackNode<T>;
	s->next = 0;
}

template<typename T> void DestroyStack(LinkStackNode<T> *&s)
{
	LinkStackNode<T> *pre = s, *p = s->next;
	while (p != 0) {
		delete pre;
		pre = p;
		p = pre->next;
	}
	delete pre;
}

template<typename T> bool StackEmpty(LinkStackNode<T> *s)
{
	return(s->next == 0);
}

template<typename T> void Push(LinkStackNode<T> *&s, T e)
{
	LinkStackNode<T> *p = 0;
	p = new LinkStackNode<T>;
	p->data = e;
	p->next = s->next;
	s->next = p;
}

template<typename T> bool Pop(LinkStackNode<T>  *&s, T &e)
{
	LinkStackNode<T> *p;
	if (s->next== 0) {
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	delete p;
	return true;
}

template<typename T> bool GetTop(LinkStackNode<T>  *&s, T &e)
{
	if (s->next == 0) {
		return false;
	}
	e = s->next->data;
	return true;
}

/*
 *P86 Determine whether the parentheses in the string are symmetric.
 */ 

void Match(char const* exp, int n)
{
	int i = 0;
	char e;
	bool match = true;
	LinkStackNode<char> *st ;
	InitStack(st);
	while (i < n&&match) {
		if (exp[i] == '(') {
			Push(st, exp[i]);
		}
		else if (exp[i] == ')') {
			if (GetTop(st,e) == true) {
				if (e != '(') {
					match = false;
				}
				else {
					Pop(st,e);
				}
			}
			else {
				match = false;    //the stack is empty
			}
		}
		i++;
	}
	if (!StackEmpty(st)){	//the stack is not empty,so false
		match = false;
	}
	DestroyStack(st);
	if (match) {
		cout << "Yes" << endl;
	}
	else {
		cout << "Not" << endl;
	}
}


void LinkStackNodeExample()
{
	char const* a = "(This is a text)";
	char const* b = "(This is a text";
	int n = 16, m = 15;
	Match(a, n);
	Match(b, m);
}
