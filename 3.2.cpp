#include <iostream>
#include <cmath>
using namespace std;

void fini(int * mas, int size)
{ int p;
   
    for (int i=0; i<size; i++)
    {   cout<<"vvedite "<<i+1<<"-y element massiva"<<endl;
        cin>>p;
         mas[i]=p;

    }
}

void fouti(int * mas,  int size)
{ 
  cout<<"\n\n"<<"massiv:\n";
    for (int i=0; i<size; i++)
    {
        cout<<mas[i]<<"\t";
    }
}
void fspu(int * mas, int size)
{
    for (int j=0; j<size; j++)
    {
      for (int i=0; i<size-1; i++)
      {
        if (mas[i]>mas[i+1]) 
        { 
          int d; d=mas[i];
          mas[i]=mas[i+1];
          mas[i+1]=d;
        }
      }
    }
}
void fspudost(int * mas, int size)
{
  for (int j=0; j<size; j++)
  {
    for (int i=0; i<size-1; i++)
    {
      if (mas[i]%10 > mas[i+1]%10)
      {
        int d; d=mas[i];
        mas[i]=mas[i+1];
        mas[i+1]=d;
      }
    }
  }

    for (int j=0; j<size; j++)
    {
      for (int i=0; i<size-1; i++)
      { bool t=0;
         bool *pt = &t;
           if ( t || mas[i]%10 == mas[i+1]%10)
           { 
            *(pt)=true;
              if (mas[i+1]%10 < mas[i+2]%10)//как сделать так,  чтобы ИФ переопределился на постоянно "ТРУЪ" после первого удачного выполнения 
              {
                int d; d=mas[i+1];
                mas[i+1]=mas[i+2];
                mas[i+2]=d;
              }
           }
      }
    }

}
void fsspu(int * mas1, int size)
{  int newsize;
    newsize = ((size/2)+1);
      int *mas2 = new int [newsize];
        for (int j=0;;)
        { 
          for(int i=0; i<=newsize; i++)
          {
            mas2[i]=mas1[j];
            j+=2;
          }
          break;
        }
          int mas3[newsize] {};
          int a, n, s;
            a=0; 
            s=0;
              for (int i=0; i<newsize; i++)
              {
                
                n=mas2[i];
                  while (n != 0)
                  {  
                    a=n%10;
                    n=n/10;
                    s=s+a;
                  }
                mas3[i]=s;
                s=0;
              }  
                  cout<<endl<<"================================================"<<endl;
                    fspu(mas3, newsize);
                      for (int i=0; i<newsize; i++)
                      {
                        cout<<mas3[i]<<"\t";
                      }
      delete [] mas2;     
}

int main()
{ 
  int c; 
    cout<<"viberite deystvie:\n 1-sortirovka po summe cifr\n 2-sortirovka po poslednemu znaku\n 3-EXIT"<<endl;
    cin>>c;
      switch (c)
      {
      case 1:
      {
        int size;
         cout<<"vvedite razmer masssiva\n";
          cin>>size;
            int * mas1 = new int [size];
              fini(mas1, size);
               fouti(mas1, size);
                cout<<"\n";
                 fsspu(mas1, size);
                  cout<<"\n\n"; 
            delete [] mas1;
      }
        break;
      case 2:
      {
        int size;
         cout<<"vvedite razmer masssiva\n";
          cin>>size;
            int * mas1 = new int [size];
              fini(mas1, size);
               fouti(mas1, size);
                 cout<<"\n\n";   
                   fspudost(mas1, size);
                    fouti(mas1, size);
                      cout<<endl;
                        
            delete [] mas1;
      }
      case 3:
      {
        break;
      }
      default:
        break;
      }
     
}
