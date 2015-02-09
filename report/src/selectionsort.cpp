void selectionsort()
{
    int i, j, min;
    for (i = 0; i < len-1; i++)
	{
	    //Dat arr[i] lam phan tu be nhat
	    min = i;
	    //Tim phan tu be nhat trong day arr[i]-->arr[len-1]
	    for (j = i+1; j < len; j++) 
		if (arr[j] < arr[min])
		    min = j;
	    if (i != min)
		//Doi cho phan tu be nhat ve vi tri
		//Day arr[0]-->arr[i] la day tang dan
		swap(arr[i], arr[min]); 
	}
}
