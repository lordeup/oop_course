#pragma once
#include <vector>

template <typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	maxValue = arr[0];

	for (auto it = arr.begin() + 1; it != arr.end(); ++it)
	{
		if (less(maxValue, *it))
		{
			maxValue = *it;
		}
	}

	return true;
}
