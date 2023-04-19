
#include "QueType.h"


template<class ItemType>

void RadixSort(ItemType values, int numValues, 
     int numPositions, int radix)
// Post: Elements in values are in order by key.
{
  QueType<int> queues[10];
  // With default constructor, each queue size is 500
  int whichQueue;

  for (int position = 1; position <= numPositions; position++)
  {
    for (int counter = 0; counter < numValues; counter++)
    {
      whichQueue = values[counter].SubKey(position);
      queues[whichQueue].Enqueue(values[counter]);

    }
    CollectQueues(values, queues, radix);
  }
}

template<class ItemType>
void CollectQueues(ItemType values[], QueType<ItemType> 
queues[], int radix)
// Post: queues are concatanated with queue[0]'s on top and 
//       queue[9]'s on the bottom and copied into values.
{
  int index = 0;
  ItemType item;

  for (int counter = 0; counter < radix; counter++)
  {
    while (!queues[counter].IsEmpty())
    {
      queues[counter].Dequeue(item);
      values[index] = item;
      index++;
    }
  
  }
}
