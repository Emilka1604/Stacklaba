#pragma once
#include <iostream> //sdhififhuihfiuf
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
	PE = 5;
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
		delete[] p;
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
		if ((Size = PE / 2) && (Size > 5)) {
			int i;
			PE = Size * 4 / 3;
			T* p = new T[PE];
			for (i = 0; i < Size; i++)
				p[i] = Conteiner[i];
			for (i = Size; i < PE; i++)
				p[i] = 0;
			delete[] Conteiner;
			Conteiner = p;
			delete[] p;
			Conteiner[Size - 1] = 0;
			Size--;
		}
		else {
			Conteiner[Size - 1] = 0;
			Size--;

		}
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
	int ind;
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
	if (st1.empty() && st2.empty()) {
		st1.push(value);
		ind = 1;
	}
	else {
		if (ind == 1) {
			int i;
			int s = st1.size();
			for (i = 0; i < s; i++) {
				st2.push(st1.top());
				st1.pop();
			}
			st2.push(value);
			ind = 2;
		}
		else
			st2.push(value);
	}
}
ochered::ochered(const ochered& och) {
	st1 = och.st1;
	st2 = och.st2;
	ind = och.ind;
}

void ochered::pop() {
	if (st1.empty() && st2.empty()) {
		throw "Îøèáêà";
	}
	else {
		if (ind == 1)
			st1.pop();

		else {
			int i;
			int s = st2.size();
			for (i = 0; i < s; i++) {
				st1.push(st2.top());
				st2.pop();
			}
			st1.pop();
			ind = 1;
		}
	}
}
int ochered::front() {

	if (st1.empty() && st2.empty()) {
		throw "Îøèáêà";
	}
	else {
		if (ind == 1)
			return(st1.top());

		else {
			int i;
			int s = st2.size();
			for (i = 0; i < s; i++) {
				st1.push(st2.top());
				st2.pop();
			}
			ind = 1;
			return(st1.top());
		}
	}
}
int ochered::back() {
	if (st1.empty() && st2.empty()) {
		throw "Îøèáêà";
	}
	else {
		if (ind == 2)
			st1.top();

		else {
			int i;
			int s = st1.size();
			for (i = 0; i < s; i++) {
				st2.push(st1.top());
				st1.pop();
			}
			st2.top();
			ind = 2;
		}
	}
}
bool ochered::empty() {
	return (st1.empty() && st2.empty());
}
ochered& ochered::operator=(const ochered& och) {
	st1 = och.st1;
	st2 = och.st2;
	ind = och.ind;
	return *this;
}
ochered::ochered() : st1(), st2() {
	ind = 1;
}
int ochered::size() {
	if (ind == 1)
		return st1.size();
	else
		return st2.size();
}


