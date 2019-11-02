#pragma once
#include <iostream>
template< class T >
class Stack {
	T* Conteiner;
	int Size;
	int PE;
public:
	Stack();
	Stack(const Stack& st);
	~Stack();
	void push(const T& value);
	int size();
	void pop();
	const T& top();
	bool empty();
	Stack& operator=(const Stack& st);
	bool operator==(Stack st);
 };
template <class T>
Stack< T >::Stack() {
	Size = 0;
	PE = 10;
	Conteiner = new T[PE];
	for (int i = 0; i < PE; i++)
		Conteiner[i] = 0;

}

template<class T>
Stack<T>::Stack(const Stack<T>& st) {
	int i;
	Size = st.Size;
	PE = st.PE;
	Conteiner = new T[PE];
	for (i = 0; i < Size; i++)
		Conteiner[i] = st.Conteiner[i];
	for (i = Size; i < PE; i++)
		Conteiner[i] = 0;
}

template<class T>
Stack<T>::~Stack() {
	delete[] Conteiner;
}
template<class T>
void Stack<T>::push(const T& value) {
	if (Size != PE) {
		Conteiner[Size] = value;
		Size++;
	}
	else {
		int i;
		PE = Size + Size / 3;
		T* p = new T[PE];
		for (i = 0; i < Size; i++)
			p[i] = Conteiner[i];
		for (i = Size; i < PE; i++)
			p[i] = 0;
		delete[] Conteiner;
		Conteiner = p;
		Conteiner[Size] = value;
		Size++;
	}


}
template<class T>
int Stack<T>::size() {
	return Size;
}
template<class T>
void Stack<T>::pop() {
	if (!(this->empty())) {
		int i;
		PE--;
		Size--;
		T* p = new T[PE];
		for (i = 0; i < Size; i++)
			p[i] = Conteiner[i];
		for (i = Size; i < PE; i++)
			p[i] = 0;
		delete[] Conteiner;
		Conteiner = p;
	}
	else
		throw "not correct";
}
template<class T>
const T& Stack<T>::top() {
	if (this->empty())
		throw "Not correct";
	else
		return Conteiner[Size - 1];
}
template<class T>
bool  Stack<T>::empty() {
	if (Size == 0)
		return true;
	else return false;
}
template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st) {
	if (this != &st) {
		int i;
		delete[] Conteiner;
		Size = st.Size;
		PE = st.PE;
		Conteiner = new T[PE];
		for (i = 0; i < Size; i++)
			Conteiner[i] = st.Conteiner[i];
		for (i = Size; i < PE; i++)
			Conteiner[i] = 0;
	}
	return *this;
}
template<class T>
bool Stack<T>::operator==(Stack<T> st) {
	if (this != &st) {
		bool tmp = false;
		if (Size == st.Size) {
			int sum = 0;
			for (int i = 0; i < Size; i++)
				if (Conteiner[i] == st.Conteiner[i])
					sum++;
			if (sum == Size)
				tmp = true;
		}
		return tmp;
	}
	else
		return true;
}
class ochered {
private:
	Stack<int> st1, st2;
public:
	ochered();
	ochered(const ochered&);
	void push(int value);
	void pop();
	int front();
	int back();
	bool empty();
	ochered& operator=(const ochered&);
	int size();
};
void ochered::push(int value) {
	if (st1.empty())
		st1.push(value);
	else {
		int i;
		int s = st1.size();
		for (i = 0; i < s; i++) {
			st2.push(st1.top());
			st1.pop();
		}
		st2.push(value);
		for (i = 0; i < s + 1; i++) {
			st1.push(st2.top());
			st2.pop();
		}
	}
}
ochered::ochered(const ochered& och) {
	st1 = och.st1;
}
void ochered::pop() {
	st1.pop();
}
int ochered::front() {
	return st1.top();
}
int ochered::back() {
	int i;
	int s = st1.size();
	for (i = 0; i < s; i++) {
		st2.push(st1.top());
		st1.pop();
	}
	int a = st2.top();
	for (i = 0; i < s; i++) {
		st1.push(st2.top());
		st2.pop();
	}
	return a;
}
bool ochered::empty() {
	return st1.empty();
}
ochered& ochered::operator=(const ochered& och) {
	st1 = och.st1;
	return *this;
}
ochered::ochered() : st1(), st2() {
}
int ochered::size() {
	return st1.size();
}


