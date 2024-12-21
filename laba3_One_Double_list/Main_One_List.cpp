#include <iostream>
#include <string>

using namespace std;

template <typename T>
class OneList {
public:
	OneList();

	bool empty();
	void push_back(T data);
	void push_front(T data);
	void print();
	void pop_front();
	void pop_back();
	int size() { return count; };
	void remove(T data);
	T& front();
	T& back();
	void insert(int index, T data);
	void processString();
	

private:

	template <typename T>
	class Elements {
	public:
		T data;
		Elements* next;

		Elements(T data = T(), Elements* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}

	};

	Elements<T>* begin;
	Elements<T>* end;
	int count;


	Elements<T>* Move(int index) {
		Elements<T>* p = begin;
		for (int i = 0; i < index; i++) {
			p = p->next;
		}
		return p;
	}

public:
	Elements<T>* operator[](const int index) {
		if (empty()) return nullptr;

		Elements<T>* p = begin;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}

};


template <typename T>
OneList<T>::OneList()
{
	count = 0;
	begin = nullptr;
	end = nullptr;
}


template<typename T>
bool OneList<T>::empty()
{
	return begin == nullptr;
}


template<typename T>
void OneList<T>::push_back(T data)
{
	Elements<T>* p = new Elements<T>(data);

	if (empty()) {
		begin = p;
		end = p;
		count++;
		return;
	}
	end->next = p;
	end = p;
	count++;

}


template<typename T>
void OneList<T>::push_front(T data)
{
	Elements<T>* p = new Elements<T>(data);

	if (empty()) {
		begin = p;
		end = p;
		count++;
	}
	p->next = begin;
	begin = p;
	count++;

}


template<typename T>
void OneList<T>::print()
{
	if (empty()) return;
	Elements<T>* p = begin;

	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


template<typename T>
void OneList<T>::pop_front()
{
	if (empty()) return;
	Elements<T>* p = begin;
	begin = p->next;
	delete p;
	count--;

}


template<typename T>
void OneList<T>::pop_back()
{
	if (empty()) return;
	if (begin == end) {
		return;
	}
	Elements<T>* p = begin;
	while (p->next != end) {
		p = p->next;
	}
	p->next = nullptr;
	delete end;
	end = p;
	count--;

}


template<typename T>
void OneList<T>::remove(T data)
{
	if (empty()) return;
	if (begin->data == data) {
		pop_front();
		return;
	}
	else if (end->data == data) {
		pop_back();
		return;
	}

	Elements<T>* slow = begin;
	Elements<T>* fast = begin->next;

	while (fast && fast->data != data) {
		fast = fast->next;
		slow = slow->next;
	}

	if (!fast) {
		cout << "Этот элемент не существует" << endl;
		return;
	}
	slow->next = fast->next;
	count--;
	delete fast;

}


template<typename T>
T& OneList<T>::front()
{
	return begin->data;
}


template<typename T>
T& OneList<T>::back()
{
	return end->data;
}


template<typename T>
void OneList<T>::insert(int index, T data)
{
	if (begin == nullptr) {
		OneList<T>::push_front(data);
	}
	else
	{
		if (index == 0) {
			OneList<T>::push_front(data);
		}
		else
		{
			Elements<T>* elem = new Elements<T>;
			elem->data = data;
			Elements<T>* elemPrev = Move(index - 1);
			elem->next = elemPrev->next;
			elemPrev->next = elem;
		}
	}
	count++;
}





template<typename T>
void OneList<T>::processString()
{
	int maxSpaces = 0;
	int currentSpaces = 0;
	int index = 0; //индекс первого пробела в наибольшей последовательности 
	int len = size(); // длина все строки
	int ilen = 1; // индекс текущего элемента
	Elements<T>* current = begin->next;
	Elements<T>* prev = begin;

	while (current != nullptr) {
		if (current->data == ' ') {
			while (current->data == ' ') {
				currentSpaces++;
				current = current->next;
				prev = prev->next;
				ilen++;
			}
		}
		if (currentSpaces > maxSpaces) {
			maxSpaces = currentSpaces;
			index = (ilen - maxSpaces) - 1;
		}
		currentSpaces = 0;
		current = current->next;
		prev = prev->next;
		ilen++;
	}
	if (maxSpaces % 3 == 0) {
		current = begin->next;
		prev = begin;
		Elements<T>* temp = new Elements<T>('*');
		for (int i = 0; i < len; i++) {
			if (current == nullptr) {
				break;
			}
			if (i == index) {
				current->data = temp->data;
				prev = current;
				current = current->next;
				for (int i = 0; i < maxSpaces - 1; i++) {
					Elements<T>* per = current;		
					current = current->next;
					delete per;
				}
				prev->next = current;
			}
			
			current = current->next;
			prev = prev->next;
		}
	}
	else {
		current = begin;
		Elements<T>* prev = nullptr; // Указатель на предыдущий элемент

		while (current != nullptr) {
			if (current->data == ' ') {
				Elements<T>* ter = current; // Сохраняем текущий элемент для удаления
				if (prev == nullptr) {
					// Если это первый элемент (begin), обновляем begin
					begin = current->next;
				}
				else {
					// Удаляем текущий элемент, обновляя указатель next предыдущего элемента
					prev->next = current->next;
				}
				current = current->next; // Переходим к следующему элементу
				delete ter; // Удаляем текущий элемент
			}
			else {
				prev = current; // Обновляем указатель на предыдущий элемент
				current = current->next; // Переходим к следующему элементу
			}
		}
	}	

}

//
//int main() {
//	setlocale(LC_ALL, "ru");
//	//string input;
//	//OneList<char> line;
//	//cout << "введите строку: \n";
//	//getline(cin, input);
//	//
//	//for (char c : input) {
//	//	line.push_back(c);
//	//}
//
//	//line.print();
//	//line.processString();
//	//line.print();
//	OneList<int> l;
//	l.insert(0, 5);
//	//l.print();
//	//cout << l[0]->data << endl;
//
//}