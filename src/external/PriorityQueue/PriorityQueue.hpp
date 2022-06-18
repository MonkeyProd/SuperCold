#pragma once

#include <vector>

template <class T> class PriorityQueue {

  private:
	std::vector<std::pair<T, int>> elements;

  public:
	PriorityQueue() {}
	int size() { return elements.size(); }

	void enqueue(T item, int priority) {
		elements.push_back(std::make_pair(item, priority));
	}

	size_t size() const { return elements.size(); }

	bool empty() const { return size() == 0; }

	T dequeue() {
		int bestIndex = 0;

		for (int i = 0; i < elements.size(); i++) {
			if (elements[i].second < elements[bestIndex].second) {
				bestIndex = i;
			}
		}

		T bestItem = elements[bestIndex].first;
		elements[bestIndex].second = 100000;
		return bestItem;
	}
};
