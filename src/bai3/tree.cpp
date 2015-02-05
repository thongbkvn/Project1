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

    //Them phan tu vao cuoi danh sach
    void AddNode(int page)
	{
	    Node *tmp, *p = this;
	    tmp = new Node;
	    tmp->page = page;
	    while (p->next != NULL)
		p = p->next;
	    p->next = tmp;
	}
    //Xuat danh sach lien ket tro boi this->next
    int ListNode()
	{
	    Node *p;
	    int s = 0;//Bien luu so trang trong danh sach
	    for (p = next; p != NULL; p = p->next)
		{
		    cout<<p->page<<' ';
		    s++;
		}
	    cout<<endl;
	    return s;
	}
    friend class Tree;
};

class Tree
{
    char key[MAX_CHAR];
    Node P;
    Tree *left;
    Tree *right;
public:
    //Ham tao
    Tree()
	{
	    bzero(key, MAX_CHAR);
	    left = NULL;
	    right = NULL;
	}

    //Chen tu khoa vao cay
    bool Insert(Tree *&root, const char* keyword)
	{
	    //Loai bo trung tu khoa
	    if ((root != NULL) && (strcasecmp(root->key, keyword) ==0))
		return false;
	    //Neu cay hien thoi rong thi tao nut moi va gan vao cay
	    if (root == NULL)
		{
		    Tree *tmp = new Tree;
		    strcpy(tmp->key, keyword);
		    root = tmp;
		}
	    //Neu tu khoa be hon thi chen vao cay con ben trai
	    else if (strcasecmp(keyword, root->key) < 0)
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
	    if (strcasecmp(keyword, root->key) == 0)
		{
		    root->P.AddNode(page);
		}
	    //Neu tu khoa be hon xau trong nut hien tai thi tim trong cay con trai
	    else if (strcasecmp(keyword, root->key) < 0)
		a += IndexKey(root->left, keyword, page);
	    //Nguoc lai tim trong cay con phai
	    else
		a +=IndexKey(root->right, keyword, page);
	    return a;
	}

    //Hien thi danh sach tu khoa
    bool ListIndex(Tree *root,const char* keyword)
	{
	    if (root == NULL)
		return false;
	    //Neu nut chua tu khoa
	    if (strcasecmp(keyword, root->key) == 0)
		{
		    //Neu tu khoa do da duoc danh chi muc
		    if (root->P.ListNode() > 0) 
			return true;
		    return false;
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
    cout<<"List of keyword: "<<endl;
    //Hien thi danh sach tu khoa
    a->Inorder(a);
    cout<<endl;
    inp.close();

    //Danh chi muc cho tu khoa
    cout<<"\nIndexing...."<<endl;
    while (!doc.eof())
	{
	    //Doc file theo dong
	    doc.getline(line, MAX_LENGTH);
	    tmp = line;
	    while (strlen(tmp) > 0)
		{
		    //Chia cau thanh cac tu
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
	    cout<<"Enter keyword: ";
	    cin>>word;
	    if (strcmp(word, "QUIT") == 0)
		break;
	    if (!a->ListIndex(a, word))
		cout<<"Keyword isn't in the index list or not found in document"<<endl;
	}
    while (1);
  
  
    cout<<endl;
    return 0;
}
