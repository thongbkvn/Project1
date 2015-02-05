#include <iostream>
#include <fstream>
#include <string.h>
#define MAX_LENGTH 1000
#define MAX_CHAR 50
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
  void addNode(int page)
  {
    Node *tmp, *p = this;
    tmp = new Node;
    tmp->page = page;
    while (p->next != NULL)
      p = p->next;
    p->next = tmp;
  }
  //Xuat danh sach lien ket tro boi this->next
  int listNode()
  {
    Node *p;
    int s = 0;
    for (p = next; p != NULL; p = p->next)
      {
	cout<<p->page<<' ';
	s++;
      }
    cout<<endl;
    return s;
  }
  
  friend class List;
};


/*
  Cac phuong thuc:
  -Insert(): Them 1 tu khoa, neu da ton tai thi khong them vao nua.
  -IndexKey(): Them chi muc cho tu khoa.
  -ListIndex(): Hien thi danh sach chi muc cua tu khoa
*/
class List
{
  char key[MAX_CHAR];
  Node P;
  List *next;
public:
  List()
  {
    bzero(key, MAX_CHAR);
    next = NULL;
  }
  //Them tu khoa theo thu tu tu dien
  // neu tu khoa da ton tai thi khong them vao nua
  bool Insert(const char* keyword)
  {
    List *p = this;

    //Vong lap tim vi tri chen theo thu tu tang dan
    while (p->next != NULL)
      {
	if (strcasecmp(p->next->key, keyword) >= 0)
	  break;
	p = p->next;
      }
    //Chen them tu khoa luu y truong hop p->next == NULL neu co gang
    //truy xuat p->next->key se bi loi
    if ((p->next == NULL) || (strcasecmp(p->next->key, keyword) != 0))
      {
	List *tmp = new List;
	strcpy(tmp->key, keyword);
	tmp->next = p->next;
	p->next = tmp;
	return true;
      }
    return false;
  }
    
  //Danh chi muc cho tu khoa
  bool IndexKey(const char* keyword, int page)
  {
    List *p;
    //Tim trong danh sach tu khoa
    for (p = this; p != NULL; p = p->next)
      //Neu trung tu khoa trong danh sach
      if (strcasecmp(p->key, keyword) == 0)
	{
	  //Them page vao dslk tro boi p->next
	  p->P.addNode(page);
	  return true;
	}
    return false;
  }
    
  //Hien danh sach chi muc cua tu khoa
  bool ListIndex(const char* keyword)
  {
    List *p;
    //Tim vi tri xuat hien cua tu khoa
    for (p = this; (p != NULL) && (strcasecmp(p->key, keyword) != 0); p = p->next);
    //Neu den cuoi danh sach thi bao ko xuat hien tu khoa
    if (p == NULL)
      return false;
    //Neu co tu khoa trong danh sach nhung ko co tu khoa trong tai lieu thi bao loi
    if (p->P.next == NULL)
      return false;
    //Neu co danh sach chi muc thi in ra man hinh
    p->P.listNode();
    return true;
  }
    
  //Hien danh sach cac tu khoa duoc danh chi muc, dung de debug
  int ListKeyWord()
  {
    List *p;
    int n = 0;
    cout<<"List of keyword: "<<endl;
    //Hien thi cac tu khoa trong danh sach tro boi this->next
    for (p = this->next; p != NULL; p = p->next)
      {
	cout<<p->key<<' ';
	if (n%10 == 9)
	  cout<<endl;
	n++;
      }
    cout<<endl;
    return n;
  }
};


//Chia sentence thanh cac word, thay doi gia tri con tro cua sentence
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
  List a;
  ifstream ListWord("bai3.in"); //Danh sach tu khoa
  ifstream Document("document.in"); //File can danh chi muc
  char *line = new char[MAX_LENGTH], *word, *tmp, KeyWord[MAX_CHAR];
  int n = 1; //Bien dem so trang
  cout<<"LINK LIST VERSION\n------------------"<<endl;
    
  //Them tu khoa vao danh dach lien ket
  cout<<"Import keyword from \"bai3.in\"..."<<endl;
  while (!ListWord.eof())
    {
      //Luu tu khoa vao bien tam
      ListWord>>KeyWord;
      //Chen tu khoa vao danh sach
      a.Insert(KeyWord);
    }
  ListWord.close();
  //Hien thi danh sach tu khoa ra man hinh
  a.ListKeyWord();

  //Danh chi muc cho tu khoa
  cout<<"\nIndexing..."<<endl;
  while (!Document.eof())
    {
      //Ghi dong dang doc vao line
      Document.getline(line, MAX_LENGTH);
      //Bien tam thay the line, neu dung line thang vao ham
      //split() thi se bi loi ve sau do split nhan tham chieu
      tmp = line;
      while (strlen(tmp)>0)
	{
	  //Chi cau thanh cac tu nho
	  split(tmp, word);
	  //Danh chi muc cho tu khoa
	  a.IndexKey(word, n);
	}
      n++;
    }
  delete [] line;
  Document.close();
  
  word = new char[MAX_CHAR];
  do
    {
      cout<<"Enter keyword: ";
      cin>>word;
      //Neu nhap vao QUIT thi thoat chuong trinh
      if (strcmp(word, "QUIT") == 0)
	break;
      //Neu tu khoa khong ton tai hoac khong co chi muc thi thong bao cho nguoi dung
      if (!a.ListIndex(word))
	cout<<"Keyword isn't in the index list or not found in document"<<endl;
    } while (1);
  delete [] word;
    
  cout<<"\n------------\nExit program"<<endl;
  return 0;
}
  
  
  
