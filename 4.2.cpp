#include <iostream>
#include <string>
using namespace std;

string fformat(const string a)
{
  int pos;
    pos = a.rfind("."); 
      for (int i=pos; i<a.size(); i++)
      {
        cout<<a[i];

      }
    cout<<endl;
  return "";
}

 string fname(const string a)
{
  int p;
    p = a.rfind("."); 
      for (int i=0; i<p; i++)
      {
        cout<<a[i];
      }
    cout<<endl;
  return "";
}

int main()
{
  int c;
  cout<<"viberite deystvie\n 1-nayti rasshirenie\n 2-nayti imya fayla\n 3-nayti raspolozhenie\n";
  cin>>c;
  switch(c)
  {
    case 1:
    {
      string a;

        cout<<"vvedite imya fayla s rasshireniem\n";

        cin>>a;

          fformat(a); 

            break;
    }
    case 2:
    {
      string a;

        cout<<"vvedite imya fayla s rasshireniem\n";

        cin>>a;

           fname(a);

            break;
    }
    default:
       break;
  }

  
  
  

  
}
