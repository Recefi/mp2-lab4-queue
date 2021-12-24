#include "..\Lab4\TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> q(15));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-7));
}

TEST(TQueue, can_push_and_pop)
{
	TQueue<int> q(5);

	ASSERT_NO_THROW(q.push(2));
	ASSERT_NO_THROW(q.push(5));
	ASSERT_NO_THROW(q.push(-7));

	int tmp;
	ASSERT_NO_THROW(tmp = q.pop());
	EXPECT_EQ(2, tmp);
	ASSERT_NO_THROW(tmp = q.pop());
	EXPECT_EQ(5, tmp);
	ASSERT_NO_THROW(tmp = q.pop());
	EXPECT_EQ(-7, tmp);
}

TEST(TQueue, cant_push_when_queue_is_full)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; ++i)
		q.push(3 * i + 2);

	ASSERT_TRUE(q.isFull());
	ASSERT_ANY_THROW(q.push(4));
}

TEST(TQueue, cant_pop_when_queue_is_empty)
{
	TQueue<int> q(5);

	ASSERT_TRUE(q.isEmpty());
	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, can_clear_queue)
{
	TQueue<int> q(5);
	for (int i = 0; i < 5; ++i)
		q.push(3 * i + 2);

	q.clear();
	ASSERT_TRUE(q.isEmpty());
}

TEST(TQueue, can_compare_queues)
{
	TQueue<int> q1(10);
	q1.push(4);
	q1.push(2);
	q1.push(-3);
	q1.pop();
	TQueue<int> q2(10);
	q2.push(2);
	q2.push(-3);
	ASSERT_TRUE(q1 == q2);
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q1(10);
	for (int i = 0; i < 10; ++i)
		q1.push(3 * i + 2);

	ASSERT_NO_THROW(TQueue<int>(q1));
	TQueue<int> q2(q1);
	EXPECT_EQ(q2, q1);
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
	TQueue<int> q1(10), q2(10);
	for (int i = 0; i < 10; ++i) {
		q1.push(3 * i + 2);
		q2.push(2 * i + 1);
	}

	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(q2, q1);
}

TEST(TQueue, can_assign_queues_of_different_size)
{
	TQueue<int> q1(10), q2(5);
	for (int i = 0; i < 10; ++i)
		q1.push(3 * i + 2);
	for (int i = 0; i < 5; ++i)
		q2.push(2 * i + 1);

	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(q2, q1);
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> q1(10);
	for (int i = 0; i < 10; ++i)
		q1.push(3 * i + 2);

	ASSERT_NO_THROW(q1 = q1);
}
