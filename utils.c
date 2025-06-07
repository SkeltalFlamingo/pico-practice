
unsigned short getNextCycleIndex(unsigned short index, unsigned short arrayLength) {
  return (index + 1 >= arrayLength) ? 0 : index + 1;
}