#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//Luu cac tu khoa
class Cell
{
  char key[30];
  Cell *next;

  Cell(const char* word=NULL)
  {
    bzero(key, 30);
    if (word != NULL)
      strcpy(key, word);
    next = NULL;
  }

  friend class HashTable;
};

class HashTable
{
  Cell **T; //Con tro toi dau moi danh sach keyword
  int m; //Kich thuoc cua bang bam

public:
  //Ham tao
  HashTable(int size=100)
  {
    m = size;
    T = new Cell*[m];
    for (int i =0 ; i < m; i++)
      T[i] = NULL;
  }
  //Ham bam
  int HashFunc(const char* keyword)
  {
    int S=0;
    for (int i = 0; i < strlen(keyword) - 1; i++)
      S += keyword[i];
    return S % 100;
  }
  //Ham huy
  ~HashTable()
  {
    for (int i = 0; i < m; i++)
      if (T[i] != NULL)
	{
	  for (Cell *p = T[i]; p != NULL; )
	    {
	      Cell *q = p;
	      p = p->next;
	      delete q;
	    }
	}
    delete [] T;
  }
  
  //Chen phan tu vao bang bam
  bool Insert(const char* keyword)
  {
    int k = HashFunc(keyword);
    if (T[k] == NULL)
      {
	T[k] = new Cell;
	strcpy(T[k]->key, keyword);
	return true;
      }
    else
      {
	Cell *tmp = new Cell;
	strcpy(tmp->key, keyword);
	tmp->next = T[k]->next;
	T[k]->next = tmp;
	return true;
      }
  }
  
  //Tim kiem phan tu trong bang bam
  Cell* Search(const char* keyword)
  {
    int k = HashFunc(keyword);
    Cell *p; 
    for (p = T[k]; p != NULL; p = p->next)
      if (strcmp(p->key, keyword) == 0)
	return p;
    return NULL;
  }
  
};
  
int main()
{
  HashTable Index;
  ifstream listWord("bai3.in");
  
  while (!listWord.eof())
    {
      char keyWord[30];
      listWord>>keyWord;
      Index.Insert(keyWord);
    }
  
  Index.Search("thong");
  return 0;
}
