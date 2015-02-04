void partition(int L, int H)
{
	int i,j,pivot;
	//Neu chi co duoi 1 phan tu thi khong phai lam di
	if (L>=H) 
		return;
	i=L;j=H;
	srand(time(NULL));
	//Chon chot ngau nhien, tranh cac truong hop dac biet
	pivot=arr[L+rand()%(H-L+1)];

	while (i<=j)
	{
		//Tim phan tu lon hon hoac bang pivot tu trai sang
		while (arr[i]<pivot) 
			i++;
		//Tim phan tu lon hon hoac bang pivot tu phai sang
		while (arr[j]>pivot) 
			j--;

		if (i<=j)
		{
			//Neu tim thay va hai phan tu khac nhau thi doi cho
			if (i<j) 
				swap(arr[i],arr[j]); 
			i++; j--;
		}
	}
	//Tiep tuc voi day con trai
	partition(L,j);
	//Tiep tuc voi day con phai
	partition(i,H); 
}

  
void quickSort()
{
	partition(0,len-1);
}
