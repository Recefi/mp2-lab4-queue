#include <iostream>
#include "TQueue.h"

int main() {
	TQueue<int> q1(10);
	for (int i = 6; i <= 15; ++i)
		q1.push(i);

	std::cout << "Queue: " << q1 << '\n';
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Queue: " << q1 << '\n';
	q1.push(-5);
	q1.push(1);
	std::cout << "Queue: " << q1 << '\n';
	q1.clear();
	q1.push(4);
	q1.push(2);
	q1.push(3);
	q1.push(-7);
	std::cout << "Queue: " << q1 << '\n';
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Poped:" << q1.pop() << "\n";
	std::cout << "Queue1: " << q1 << '\n';

	TQueue<int> q2(10);
	q2.push(3);
	q2.push(-7);
	std::cout << "Queue2: " << q2 << '\n';

	if (q1 == q2)
		std::cout << "\nq1 == q2\n";
	else
		std::cout << "\nq1 != q2\n";

	return 0;
}