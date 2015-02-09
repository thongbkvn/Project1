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
	    int s = 0; //Bien luu so trang trong danh sach
	    for (p = next; p != NULL; p = p->next)
		{
		    cout<<p->page<<' ';
		    s++;
		}
	    cout<<endl;
	    return s;
	}

    friend class Cell;
};

//Luu cac tu khoa va con tro toi danh sach chi muc
class Cell
{
    char key[MAX_CHAR];//Mang luu tu khoa
    Node P;//Header cua dslk tuu danh sach cac trang 
    Cell *next;

    //Ham tao
    Cell(const char* word=NULL)
	{
	    bzero(key, MAX_CHAR);
	    if (word != NULL)
		strcpy(key, word);
	    next = NULL;
	}

    //Them chi muc vao keyword trong Cell hien tai
    void AddIndex(int page)
	{
	    P.AddNode(page);
	}

    //In danh sach chi muc duoc tro boi P
    int ListNode()
	{
	    return P.ListNode();
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
		S += tolower(keyword[i]);
	    return S % 100;
	}

    /*Chen phan tu vao bang bam
      Cac keyword khong duoc phep trung
      vi khong co theo tac kiem tra tu khoa
      truoc khi nhap vao bang bam*/
    bool Insert(const char* keyword)
	{
	    int k = HashFunc(keyword);
	    //Neu phan tu T[k] con rong thi tao moi va chen vao
	    if (T[k] == NULL)
		{
		    T[k] = new Cell;
		    strcpy(T[k]->key, keyword);
		    return true;
		}
	    //Neu khong thi chen vao dau dslk tro boi T[k]->next
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
	    //Tim tu khoa trong bang bam
	    for (p = T[k]; p != NULL; p = p->next)
		//Neu co them trang vao danh sach chi muc
		if (strcasecmp(p->key, keyword) == 0)
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
	    //Tim tu khoa trong bang bam
	    for (p = T[k]; p != NULL; p = p->next)
		//Neu co thi in ra danh sach chi muc
		if (strcasecmp(p->key, keyword) == 0)
		    {
			if (p->ListNode())
			    return true;
			return false;
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

//Chia cau thanh cac tu bang nhau
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
    ifstream input("bai3.in");//Danh sach tu khoa
    ifstream document("document.in");//Tai lieu can danh chi muc
    char *line = new char[MAX_LENGTH], *word, *tmp;
    char KeyWord[MAX_CHAR];
    int n = 1;
    cout<<"HASH TABLE VERSION\n-----------------\n"<<endl;
    
    //Nhap danh sach tu khoa vao bang bam
    cout<<"Import keyword from \"bai3.in\"..."<<endl;
    while (!input.eof())
	{
	    input>>KeyWord;
	    Index.Insert(KeyWord);
	}
    input.close();
    
    cout<<"Indexing...."<<endl;
    //Danh chi muc cho tu khoa
    while (!document.eof())
	{
	    //Doc tung cau
	    document.getline(line,1000);
	    tmp = line;
	    while (strlen(tmp) > 0)
		{
		    //Tach cau thanh cac tu
		    split(tmp, word);
		    Index.IndexKey(word,n);
		}
	    n++;
	}
    document.close();
    
    word = new char[MAX_CHAR];
    do
	{
	    cout<<"Enter keyword: ";
	    cin>>word;
	    if (strcmp(word, "QUIT") == 0)
		break;
	    if (!Index.ListIndex(word))
		cout<<"Keyword isn't in the index list or not found in document"<<endl;
	}
    while (1);
    delete [] line;
    delete[] word;
    cout<<endl;
    return 0;
}
