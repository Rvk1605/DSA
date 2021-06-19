    #include<iostream>
    #define SIZE 1000
    using namespace std;

    int top=-1;
    int stack[SIZE];
    void push(int val)
    {
      if(top==SIZE-1)
      return ;
      else
      {
        stack[++top]=val;
      }
    }

    void pop()
    {
      if(top==-1)
      return;
      else
      {
        stack[top--]=0;
      }
    }

    int max()
    {
      int max=0;
      if(top==-1)
      return 0;
      else
      {
      for(int i=0;i<=top;i++)
      {
        if(stack[i]>max)
        max=stack[i];
      }
      return max;
    }
    }

    int main()
    {
      int choice,data,m,n;
      cin>>n;
      while(n!=0)
      {
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
          scanf("%d",&data);
          push(data);
          break;
          case 2:
          pop();
          break;
          case 3:
          m=max();
          cout<<m<<endl;
        }
        n--;
      }

    }
