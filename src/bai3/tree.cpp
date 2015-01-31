#include <iostream>
#include <fstream>
#include <string.h>
#define MAX_CHAR 50
#define MAX_LENGTH 1000
using namespace std;

class Node
{
  int page;
  Node *next;

  Node()
  {
    page = 0;
    next = NULL;
  }
    
  friend class Tree;
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

class Tree
{
  char key[MAX_CHAR];
  Node *P;
  Tree *left;
  Tree *right;
public:
  Tree()
  {
    bzero(key, MAX_CHAR);
    P = NULL;
    left = NULL;
    right = NULL;
  }

  bool Insert(Tree *&root, const char* keyword)
  {
    //Loai bo trung tu khoa
    if ((root != NULL) && (strcmp(root->key, keyword) ==0))
	return false;
    //Neu cay hien thoi rong thi tao nut moi va gan vao cay
    if (root == NULL)
      {
	Tree *tmp = new Tree;
	strcpy(tmp->key, keyword);
	root = tmp;
      }
    //Neu tu khoa be hon thi chen vao cay con ben trai
    else if (strcmp(keyword, root->key) < 0)
	Insert(root->left, keyword);
    //Nguoc lai chen vao cay con ben phai
    else
      Insert(root->right, keyword);
    return true;
  }
  //Danh chi muc
  bool IndexKey(Tree *root, const char* keyword, int page)
  {
    int a = 0;
    if (root == NULL)
      return false;
    //neu nut chua tu khoa, co gia tri bang keyword thi them page
    //vao danh sach tro boi root->P (root->P)
    if (strcmp(keyword, root->key) == 0)
      {
	if (root->P != NULL)
	  {
	    Node *tmp = new Node;
	    tmp->page = page;
	    tmp->next = root->P;
	    root->P = tmp;
	  }
	else
	  {
	    root->P = new Node;
	    root->P->page = page;
	    root->P->next = NULL;
	  }
      }
    //Neu tu khoa be hon xau trong nut hien tai thi tim trong cay con trai
    else if (strcmp(keyword, root->key) < 0)
      a += IndexKey(root->left, keyword, page);
    //Nguoc lai tim trong cay con phai
    else
      a +=IndexKey(root->right, keyword, page);
    return a;
  }

  bool ListIndex(Tree *root,const char* keyword)
  {
    if (root == NULL)
      return false;
    //Neu nut chua tu khoa
    if (strcmp(keyword, root->key) == 0)
      {
	//Neu khong co chi muc nao
	if (root->P == NULL)
	  return false;
	Node *p;
	for (p = root->P; p != NULL; p = p->next)
	  cout<<p->page<<' ';
	cout<<endl;
	return true;
      }
    //Tim trong cay con trai va cay con phai
    if (ListIndex(root->left, keyword) + ListIndex(root->right, keyword) == 0)
      return false;
    return true;
  }
  
  //Duyet cay theo thu tu giua
  void Inorder(Tree *root)
  {
    if (root == NULL)
      return;
    Inorder(root->left);
    cout<<root->key<<' ';
    Inorder(root->right);
  }
};

int main()
{
  Tree *a = NULL;
  ifstream inp("bai3.in"); //File luu danh sach cac tu.
  ifstream doc("document.in"); //File can danh chi muc.
  char *line = new char[MAX_LENGTH], *word, *tmp, KeyWord[MAX_CHAR];
  int n = 1;
  //Nhap danh sach tu khoa
  cout<<"BINARY SEARCH TREE VERSION\n--------------------------"<<endl;
  cout<<"Import keyword from \"bai3.in\"..."<<endl;
  while (!inp.eof())
    {
      inp>>KeyWord;
      a->Insert(a, KeyWord);
    }
  cout<<"Key word to be indexed: "<<endl;
  a->Inorder(a);
  cout<<endl;
  inp.close();

  //Danh chi muc cho tu khoa
  cout<<"Indexing"<<endl;
  while (!doc.eof())
    {
      doc.getline(line, MAX_LENGTH);
      tmp = line;
      while (strlen(tmp) > 0)
	{
	  split(tmp, word);
	  a->IndexKey(a, word, n);
	}
      n++;
    }
  delete [] line;
  doc.close();

  word = new char[MAX_CHAR];

  do
    {
      cout<<"Enter keywrod: ";
      cin>>word;
      if (strcmp(word, "QUIT") == 0)
	break;
      if (!a->ListIndex(a, word))
	cout<<"Keyword isn't in index list or not found in document"<<endl;
    }
  while (1);
  
  
  cout<<endl;
  return 0;
}
