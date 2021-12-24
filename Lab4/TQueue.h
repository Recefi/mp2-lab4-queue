#pragma once
#include <iostream>

template <class T>
class TQueue {
private:
	int maxSize;
	T* pArray;
	int head, tail, count;

public:
	TQueue(int _maxSize = 20) {
		if (_maxSize <= 0)
			throw _maxSize;

		maxSize = _maxSize;
		pArray = new T[maxSize];
		head = 0;
		tail = -1;
		count = 0;
	}

	TQueue(const TQueue& queue) {
		maxSize = queue.maxSize;
		pArray = new T[maxSize];
		for (int i = 0; i < maxSize; ++i)
			pArray[i] = queue.pArray[i];

		head = queue.head;
		tail = queue.tail;
		count = queue.count;
	}

	~TQueue() {
		delete[] pArray;
	}

	TQueue& operator=(const TQueue& queue) {
		if (this != &queue) {
			if (queue.maxSize != maxSize) {
				maxSize = queue.maxSize;
				delete[] pArray;
				pArray = new T[maxSize];
			}
			for (int i = 0; i < maxSize; ++i)
				pArray[i] = queue.pArray[i];

			head = queue.head;
			tail = queue.tail;
			count = queue.count;
		}

		return *this;
	}

	int getMaxSize() const { return maxSize; }
	int getHead() const { return head; }
	int getTail() const { return tail; }
	int getCount() const { return count; }

	bool isEmpty() const { return (count == 0); }
	bool isFull() const { return (count == maxSize); }

	bool operator==(const TQueue& queue) const {
		if (maxSize != queue.maxSize)
			return false;
		if (count != queue.count)
			return false;

		for (int i = head, j = queue.head, _count = count; _count > 0; _count--) {
			if (pArray[i] != queue.pArray[j]) 
				return false;
			i = (i + 1) % maxSize;
			j = (j + 1) % maxSize;
		}

		return true;
	}

	bool operator!=(const TQueue& queue) const {
		return !(*this == queue);
	}

	void push(T element) {
		if (isFull())
			throw "Queue is full";

		tail = (tail + 1) % maxSize;
		pArray[tail] = element;
		++count;
	}

	T pop() {
		if (isEmpty())
			throw "Queue is empty";

		int tmp = head;
		head = (head + 1) % maxSize;
		--count;

		return pArray[tmp];
	}

	void clear() {
		head = 0;
		tail = -1;
		count = 0;
	}

	friend std::ostream& operator<<(std::ostream& out, const TQueue& queue) {
		for (int i = queue.head, _count = queue.count; _count > 0; _count--) {
			out << queue.pArray[i] << " ";
			i = (i + 1) % queue.maxSize;
		}

		return out;
	}
};