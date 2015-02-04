void insertionsort()
{
  int i,j,tmp;
  
  for (i = 1; i < len; i++)
    {
      tmp = arr[i];
      //Chen phan tu arr[i] vao day da co thu tu
      j = i - 1;
      //Tim tu ben phai sang phan tu be hon arr[i]
      while ((j >= 0) && (arr[j] > tmp))
	{
	  //Don cac phan tu ve ben phai tao 1 cho chua cho arr[i]
	  arr[j+1] = arr[j]; 
	  j = j - 1;
	}
      //Chen phan tu vao dung vi tri,
      //Day arr[0]-->arr[i] la day tang dan
      arr[j+1] = tmp; 
    }
}
