#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#define MAX_LENGTH 1000
#define MAX_CHAR 50

using namespace std;

//Luu danh sach chi muc
class Node
{
  int page;
  Node *next;

  Node()
  {
    next = NULL;
    page = 0;
  }

  friend class Cell;
};

//Luu cac tu khoa va con tro toi danh sach chi muc
class Cell
{
  char key[MAX_CHAR];
  Node *P;
  Cell *next;

  Cell(const char* word=NULL)
  {
    bzero(key, MAX_CHAR);
    if (word != NULL)
      strcpy(key, word);
    next = NULL;
    P = NULL;
  }

  //Them chi muc vao keyword trong Cell hien tai
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

  //In danh sach chi muc duoc tro boi P
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
  
  /*Chen phan tu vao bang bam
  Cac keyword khong duoc phep trung
  vi khong co theo tac kiem tra tu khoa
  truoc khi nhap vao bang bam*/
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
  bool IndexKey(const char* keyword, int page)
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
  //Hien danh sach chi muc cua tu khoa keyword
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
    
  /*Hien cac phan tu co cung ma bam
    Dung de kiem tra, debug*/
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
  char *line = new char[MAX_LENGTH], *word, *tmp;
  int n = 1;
  cout<<"HASH TABLE VERSION\n-----------------\n"<<endl;
  //Nhap danh sach tu khoa vao bang bam
  cout<<"Import keyword from \"bai3.in\"..."<<endl;
  while (!listWord.eof())
    {
      char keyWord[MAX_CHAR];
      listWord>>keyWord;
      Index.Insert(keyWord);
    }
  cout<<"Indexing...."<<endl;
  
    while (!document.eof())
    {
      document.getline(line,1000);
      tmp = line;
      while (strlen(tmp) > 0)
	{
	  split(tmp, word);
	  Index.IndexKey(word,n);
	}
      n++;
    }

    word = new char[MAX_CHAR];
   do
    {
      cout<<"\nEnter keyword: ";
      cin>>word;
      if (strcmp(word, "QUIT") == 0)
	break;
      cout<<word<<": ";
      if (!Index.ListIndex(word))
	cout<<"Keyword not found"<<endl;
    }
    while (1);
   delete [] line;
   delete[] word;
  listWord.close();
  document.close();
  cout<<endl;
  return 0;
}
