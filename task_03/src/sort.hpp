#pragma once

#include <vector>

template <typename T>
std::vector<T> QuickSort(const std::vector<T>& data) {
  std::vector<T> result = data;
  if (data.empty())
    return result;
  std::vector<int> LeftAndRight = {0, int(data.size())-1};
  int i{0}, j{0}, right{0}, left{0};
  T midElem;
  do {
    right = LeftAndRight.back();
    LeftAndRight.pop_back();
    left = LeftAndRight.back();
    LeftAndRight.pop_back();

    i = left;
    j = right;
    
    midElem = result[(j + i) / 2];
    do{
      while (result[i] < midElem)
        ++i;
      while (result[j] > midElem)
        --j;
      if (i <= j){
        std::swap(result[i], result[j]);
        ++i;
        --j;
      }
    } while (i<=j);

    if (left < j){
      LeftAndRight.push_back(left);
      LeftAndRight.push_back(j);
    }

    if (right > i){
      LeftAndRight.push_back(i);
      LeftAndRight.push_back(right);
    }


  } while(!LeftAndRight.empty());

  return result;
}
