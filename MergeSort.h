#ifndef MERGESORT_H
#define MERGESORT_H

#include "BubbleSort.h"

template <class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast, ItemType tempArray[]);

template<class ItemType>
void MergeSort(ItemType values[], int startIndex, int endIndex)
{
  if (startIndex < endIndex)
  {
    int middleIndex = (startIndex + endIndex) / 2;
    MergeSort(values, startIndex, middleIndex);
    MergeSort(values, middleIndex + 1, endIndex);
    
    ItemType* tempArray = new ItemType[endIndex - startIndex + 1];
    Merge(values, startIndex, middleIndex, middleIndex + 1, endIndex, tempArray);
    delete[] tempArray;
  }
}

template <class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast, ItemType tempArray[]) {
  int index = leftFirst;
  int saveFirst = leftFirst;

  while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
    if (values[leftFirst] < values[rightFirst]) {
      tempArray[index] = values[leftFirst];
      leftFirst++;
    } else {
      tempArray[index] = values[rightFirst];
      rightFirst++;
    }
    index++;
  }

  while (leftFirst <= leftLast) {
    tempArray[index] = values[leftFirst];
    leftFirst++;
    index++;
  }

  while (rightFirst <= rightLast) {
    tempArray[index] = values[rightFirst];
    rightFirst++;
    index++;
  }

  for (index = saveFirst; index <= rightLast; index++)
    values[index] = tempArray[index];
}

#endif // MERGESORT_H
