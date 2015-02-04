void bublesort()
{
  int i,j;
  for (i = 1; i < len; i++)
    for (j = len-1; j >= i; j--)
      //Neu arr[j] va arr[j-1] nguoc thu tu
      if (arr[j] < arr[j-1])
	{
	  //Doi cho ve dung vi tri
	  swap(arr[j], arr[j-1]);
	  s++;
	}
}
