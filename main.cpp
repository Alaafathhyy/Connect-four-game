#include <iostream>
using namespace std;
void boardprint (char **board,int row,int col)
{for(int i=0;i<row;i++)
    {for(int j =0;j<col;j++)
    {
        board[i][j]='-';
    }
    }
}
void print(char **board,int row,int col)
{
    for(int i=row-1;i>=0;i--)
    {for(int j=0;j<col;j++)
    {
        cout<<board[i][j]<<"   ";
    }
    cout<<endl;

    }

}

char winner (char **board,int col,int row)
{int count=0;
int count2=0;

//for vertical
for (int j = 0; j <col; j++){

				for (int i = 0; i <row; i++){

				if (board[i][j] == 'x') {count++;}
				else count = 0;
				if(board[i][j]== 'o'){count2++;}
				else {count2=0;}
				if (count == 4|| count2==4 )
				{
					return board[i][j];
				}
			}
		}

// for horizontal
count=0;
count2=0;
for(int i=0;i<row;i++){

for(int j=0;j<col;j++){
{
    if(board[i][j]=='x'){count++;}
    else {count=0;}
    if(board[i][j]=='o'){count2++;}
    else {count2=0;}
    if (count==4||count2==4)
    {return board[i][j];
    }}}}



//for diagonal
count=0;
count2=0;
for(int i=0,j=0;i<row&&j<col;i++,j++){
    if(board[i][j]=='x'){count++;}
    else count=0;
    if(board[i][j]=='o')count2++;
    else count2=0;
    if (count==4||count2==4)
    {return board[i][j];
}
}

count=0;
count2=0;
for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
    if(board[i][j]=='x'){count++;}
    else count=0;
    if(board[i][j]=='o')count2++;
    else count2=0;
    if (count==4||count2==4)
    {return board[i][j];
}}

count=0;
count2=0;
for(int i=row-1,j=0;i>=0&&j<col;i--,j++){
    if(board[i][j]=='x'){count++;}
    else count=0;
    if(board[i][j]=='o')count2++;
    else count2=0;
    if (count==4||count2==4)
    {return board[i][j];
}}
count=0;
count2=0;
for(int i=0,j=col-1;i<row&&j>=0;i++,j--){
    if(board[i][j]=='x'){count++;}
    else count=0;
    if(board[i][j]=='o')count2++;
    else count2=0;
    if (count==4||count2==4)
    {return board[i][j];}

}


}















int main()
{
    int row,col,numberofrow,nc,nr;char x;
    cout<<"enter the num of row";
    cin>>row;
    cout<<"enter the num of column";
    cin>>col;
    char **board=new char *[row];
    for(int i=0;i<row;i++)
        board[i]=new char [col];

boardprint(board,row,col);
    while (true)
    {numberofrow=0;
     print(board,row,col);
        cout<<"enter ch"<<endl;
        cin>>x;
        cout<<"enter the nc"<<endl;
        cin>>nc;

     while (board[numberofrow][nc]!='-')
     {
         numberofrow++;
     }
     char ch;
     board[numberofrow][nc]=x;

    ch=winner(board,col,row);
    if(ch=='x'||ch=='o')
       {
print(board,row,col);
        cout<<"the winner is  "<<ch;

        break;}


    }

for(int i=0;i<row;i++)
{delete[] board[i];}
delete [] board;

    return 0;





}
