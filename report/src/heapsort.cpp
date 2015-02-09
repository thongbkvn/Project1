
void maxHeapify(int root, int endnode)
{
    int c1, c2, bg;
    
  while (root <= endnode/2-1) //Khi nao root chua phai la la
    {
	c1 = 2*root + 1;//c1 = con trai
	c2 = 2*root +2;//c2 = con phai
	bg = c1; //con lon hon la c1
	//Neu con phai lon hon con trai thi gan biger cho con phai
	if ((c2 < len) && (arr[c2] > arr[bg]))
	    bg = c2;
	//Neu 1 trong 2 con lon hon root thi doi cho
      if (arr[bg] > arr[root]) 
	  swap(arr[root], arr[bg]); //Doi cho cho con lon hon
      //Tiep tuc voi vi tri da chuyen
      root = bg;
    }
}

void heapSort()
{
  int r, i;
  for (r = (len/2-1); r >= 0; r--) // Xay dung dong tren toan bo cay
    maxHeapify(r, len);

  for (i = len-1; i > 0; i--)
    {
      swap(arr[0], arr[i]); //Doi cho nut lon nhat ve cuoi day
      maxHeapify(0, i-1); //Xay lai dong, ko kem nut vua hoan doi
    }
}
