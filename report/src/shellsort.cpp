void shellSort()
{
    int i,j,h=len/2,tmp;
  
    while (h > 0) 
	{
	    for (i = h; i < len; i++) //Sap xep chen voi cac day con
		{
		    tmp = arr[i];
		    j = i - h;
		    while (j >= 0 && arr[j] > tmp)
			{
			    arr[j+h] = arr[j];
			    j = j - h;
			}
		    arr[j+h] = tmp;
		}
	    h = h/2; //Tang so day con
	}
}
