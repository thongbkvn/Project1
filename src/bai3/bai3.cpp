#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Node
{
public:
  int page;
  Node *next;

  Node()
  {
    next = NULL;
    page = 0;
  }

  friend class Cell;
};
//Luu cac tu khoa
class Cell
{
  
public:
  char key[30];
  Node *P;
  Cell *next;

  Cell(const char* word=NULL)
  {
    bzero(key, 30);
    if (word != NULL)
      strcpy(key, word);
    next = NULL;
    P = NULL;
  }
  
  void AddIndex(int page)
  {
    if (P != NULL)
      {
	Node *tmp = new Node;
	tmp->page = page;
	tmp->next = P;
	P = tmp;
      }
    else
      {
	P = new Node;
	P->page = page;
	P->next = NULL;
      }
  }

  int List()
  {
    Node *p;
    for (p = P; p != NULL; p = p->next)
      cout<<p->page<<' ';
    cout<<endl;
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
    for (int i = 0; i < strlen(keyword); i++)
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
  //Cac keyword khong duoc phep trung
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
  bool Search(const char* keyword, int page)
  {
    int k = HashFunc(keyword);
    Cell *p; 
    for (p = T[k]; p != NULL; p = p->next)
      if (strcmp(p->key, keyword) == 0)
	{
	  p->AddIndex(page);
	  return true;
	}
    return false;
  }

  bool ListIndex(const char* keyword)
  {
    int k = HashFunc(keyword);
    Cell *p;
    for (p = T[k]; p != NULL; p = p->next)
      if (strcmp(p->key, keyword) == 0)
	{
	  p->List();
	  return true;
	}
    return false;
  }
    
  //Hien cac phan tu co cung ma bam
  int List(const char* keyword)
  {
    int k = HashFunc(keyword), n=0;
    Cell *p;
    for (p = T[k]; p != NULL; p = p->next)
      {
	cout<<p->key<<' ';
	n++;
      }
    cout<<endl;
    return n;
  }
};


void split(char* &sentence, char* &word)
{
  while (*sentence==' ')
    sentence++;
  word=sentence;
  while ((*sentence!=' ')&&(*sentence!='\0'))
    sentence++;
  if (*sentence==' ')
    {
      *sentence='\0';
      sentence++;
    }
}

int main()
{
  HashTable Index;
  ifstream listWord("bai3.in");//Danh sach tu khoa
  ifstream document("document.in");
  Cell *a;
  char *line = new char[1000], *word= new char[30];
  int n = 1;
  //Nhap danh sach tu khoa
  while (!listWord.eof())
    {
      char keyWord[30];
      listWord>>keyWord;
      Index.Insert(keyWord);
    }
  
  while (!document.eof())
    {
      document.getline(line,1000);
      while (strlen(line) > 0)
	{
	  split(line, word);
	  Index.Search(word,n);
	}
      n++;
    }
    
  Index.ListIndex("me");
  
  listWord.close();
  document.close();
  cout<<endl;
  return 0;
}
