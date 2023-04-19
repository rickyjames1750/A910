#ifndef SWAP_H
#define SWAP_H

template <typename ItemType> void Swap(ItemType &item1, ItemType &item2) {
  ItemType tempItem;

  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

#endif // SWAP_H
