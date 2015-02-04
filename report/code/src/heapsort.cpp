void maxHeapify(int root, int endnode)
{
  int c, key;
  key = arr[root];
  //Khi nao root chua phai la la
  while ((root*2 + 1) <= endnode)
    {
      c=root * 2 + 1;
      //Neu con trai be hon con phai thi c=chi so con phai
      if ((c < endnode-1) && (arr[c] < arr[c+1]))
	c++;
      //Neu 2 con be hon root thi cay da la maxheap
      if (arr[c] <= key) 
	break;
      //Doi cho cho con lon hon
      arr[root] = arr[c];
      // Tiep tuc voi root tai vi tri moi
      root = c; 
    }
  //root ban dau nam dung vi tri  
  arr[root] = key; 
}

void heapSort()
{
  int r, i;
  // Xay dung dong tren toan bo cay
  for (r = (len/2 - 1); r >= 0; r--) 
    maxHeapify(r, len-1);
  for (i = len-1; i>0; i--)
    {
      //Doi cho nut lon nhat ve cuoi day
      swap(arr[0], arr[i]); 
      //Xay lai dong, ko kem nut vua hoan doi
      maxHeapify(0, i-1); 
    }
}

