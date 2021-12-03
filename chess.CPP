	 int j=0,a=100,b=400,cnt=0,utemp1=0,utemp2=0,guest=0;
	 int posarr[2]={0,0},x,y,z=1,cl;
	 char username[20],password[20],choicen;
	 #include<string.h>
	 #include<stdlib.h>
	 #include<iostream>
	 #include<graphics.h>
	 #include<stdio.h>
	 #include<conio.h>
	 #include<dos.h>
	 #include<process.h>
	 //#include<fstream.h>
	 union REGS in,out;
	 void changepos(void);
	 void undo();
	 void newuser();
	 void user();
	 void main1();
	 int valid();
	 void colorsquare();
//////////////////////////////////////////////////////////////////////////
	 class xycoord
	 {
	 public:
	 int x;
	 int y;
	 int player;           //structure to hold the x,y coordinates and the piece present in a particular square
	 char piece[3];
	 void intro()
	{
	int l=1,a=0,b=0,c=0,cnt=0,x=317,y=236,i,j;
	char name1[][2]={"S","A","I","C","H","A","R","A","N"," "," "};
	char name2[][2]={"A","N","D"," "," "};
	char name3[][2]={"A","R","Y","A","N"};
		while(1)
   {
		cleardevice();
		setlinestyle(0,0,3);
		settextstyle(2,HORIZ_DIR,4);
		setcolor(WHITE);
		outtextxy(300,230,"LOADING");
		setcolor(BLUE);
		arc(x,y,270+a,90+b,40);
		arc(x,y,270+a,90+b,40);
		setcolor(RED);
		arc(x,y,320-a,120-b,70);
		arc(x,y,320-a,120-b,72);
		setcolor(WHITE);
		arc(x,y,30+a,160+b,92);
		arc(x,y,30+a,160+b,94);
		setcolor(GREEN);
		arc(x,y,300-a,40-a,111);
		arc(x,y,300-a,40-a,113);
		setcolor(LIGHTMAGENTA);
		arc(x,y,300+c,140+c,131);
		arc(x,y,300+c,140+c,133);
		cnt++;
		if(cnt==80)
		break;
		else
		{

			a=a+random(10);
			b=b+random(10);
			c=c+random(10);
			randomize();
			delay(30);
		}
  }


	setcolor(RED);
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(250,380,"Press any key to continue");
getch();
setcolor(WHITE);
cleardevice();
settextstyle(3,HORIZ_DIR,4);
outtextxy(150,40,"GAME DESIGNED BY:-");
line(40,100,650,100);
settextstyle(3,HORIZ_DIR,5);
setcolor(WHITE);
for(int o=0;o<11; o++)
{
delay(100);
outtextxy(40+25*o,200,name1[o]);
}
for(int p=0;p<5; p++)
{
delay(100);
outtextxy(40+25*o+25*p,200,name2[p]);
}
for(int q=0;q<5; q++)
{
delay(100);
outtextxy(40+25*o+25*p+25*q,200,name3[q]);
}
delay(500);
setcolor(RED);
settextstyle(3,HORIZ_DIR,3);
outtextxy(300,420,"Press any key to continue");
setcolor(YELLOW);
getch();
cleardevice();
}
}sqrpos[65];

////////////////////////////////////////////////////////////////////////////////
	 int mousehide()
	   {
		  in.x.ax=2;             //Function to hide the mouse icon
		  int86(51,&in,&out);
		  return 1;
	   }
////////////////////////////////////////////////////////////////////////////////
	 void mainmenu();          //Function to display the main menu
////////////////////////////////////////////////////////////////////////////////
int pos1,pos2;
void assignpos(void)
{  int k=0;
   for(int m=0;m<8;m++)
	for(int l=0;l<8;l++)
	{                                         //Function to assign the initial positions of the pieces
		sqrpos[k].x=150+(m*40);
		sqrpos[k].y=150+(l*40);
											  //To arrange the chess board
		sqrpos[k].piece[0]='\0';
		sqrpos[k].player=0;
		k++;

	}

		  strcpy(sqrpos[0].piece," R ");
		  strcpy(sqrpos[1].piece," N ");
		  strcpy(sqrpos[2].piece," B ");
		  strcpy(sqrpos[3].piece," K ");
		  strcpy(sqrpos[4].piece," Q ");
		  strcpy(sqrpos[5].piece," B ");
		  strcpy(sqrpos[6].piece," N ");
		  strcpy(sqrpos[7].piece," R ");
		  strcpy(sqrpos[8].piece," P ");
		  strcpy(sqrpos[9].piece," P ");
		  strcpy(sqrpos[10].piece," P ");
		  strcpy(sqrpos[11].piece," P ");
		  strcpy(sqrpos[12].piece," P ");
		  strcpy(sqrpos[13].piece," P ");
		  strcpy(sqrpos[14].piece," P ");
		  strcpy(sqrpos[15].piece," P ");
		  strcpy(sqrpos[48].piece," P ");
		  strcpy(sqrpos[49].piece," P ");
		  strcpy(sqrpos[50].piece," P ");
		  strcpy(sqrpos[51].piece," P ");
		  strcpy(sqrpos[52].piece," P ");
		  strcpy(sqrpos[53].piece," P ");
		  strcpy(sqrpos[54].piece," P ");
		  strcpy(sqrpos[55].piece," P ");
		  strcpy(sqrpos[56].piece," R ");
		  strcpy(sqrpos[57].piece," N ");
		  strcpy(sqrpos[58].piece," B ");
		  strcpy(sqrpos[59].piece," K ");
		  strcpy(sqrpos[60].piece," Q ");
		  strcpy(sqrpos[61].piece," B ");
		  strcpy(sqrpos[62].piece," N ");
		  strcpy(sqrpos[63].piece," R ");

	for(int h=0;h<16;h++)
	{
		sqrpos[h].player=1;
		sqrpos[63-h].player=2;
	}

}
////////////////////////////////////////////////////////////////////////////////
void display()
{

	int i,j,k;
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(440,100,"Other Inputs");
	line(440,140,650,140);
	line(440,145,650,145);                            //To display the main screen during the game
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(440,150,"1000 - Queen side castle. ");
	outtextxy(440,170,"2000 - King side castle.");
	outtextxy(440,190,"5000 - Reset");
	outtextxy(440,210,"999 - Exit");
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,BROWN);
	for(i=100;i<460;i=i+40)
	{
		for(j=100;j<460;j=j+40)
		{       if(cnt==0)
		{
			line(i,i,i,j);
			delay(5);
			line(i,j,j,j);
			delay(5);
			line(j,j,j,i);
			delay(5);
			line(j,i,i,i);
			delay(5);
		}
		else
		{
			line(i,i,i,j);
			line(i,j,j,j);
			line(j,j,j,i);
			line(j,i,i,i);
		}
		}
	}

	settextstyle(2,HORIZ_DIR,3);
	for(i=100;i<420;i=i+80)
for(j=100;j<420;j=j+80)
			if(cnt==0)
			{
				floodfill(i+20,j+20,YELLOW);
				delay(25);
			}
			else
			floodfill(i+20,j+20,YELLOW);

	for(i=140;i<420;i=i+80)
		for(j=140;j<420;j=j+80)
			if(cnt==0)
			{
				floodfill(i+20,j+20,YELLOW);
				delay(25);
			}
			else
			floodfill(i+20,j+20,YELLOW);

	setcolor(YELLOW);
	j=0,k=0;
	for(i=1;i<65;i++)
	{

		char str[10];
		itoa(i,str,10);
		settextstyle(2,HORIZ_DIR,4);
		outtextxy(102+j,102+k,str);
		if(sqrpos[i-1].player==1)
		setcolor(WHITE);
		if(sqrpos[i-1].player==2)
		setcolor(CYAN);
		settextstyle(0,HORIZ_DIR,2);
		if(cnt==0)
		{
			outtextxy(97+j,115+k,sqrpos[i-1].piece);
			delay(10);
		}
		else
			   outtextxy(97+j,115+k,sqrpos[i-1].piece);
		j=j+40;
		if(i%8==0)
		 {	k=k+40;j=0;}
		for(int l=0;l<10;l++)str[l]='\0';
		setcolor(YELLOW);
	}

	rectangle(95,95,425,425);
	cnt++;
}
////////////////////////////////////////////////////////////////////////
void promo()
	{       		for(int r=0;r<8;r++)
		{
			if(strcmp(sqrpos[r].piece," P ")==0)           //To promote a pawn to a queen when it reaches the last rank
				strcpy(sqrpos[r].piece," Q ");
			if(strcmp(sqrpos[r].piece," P ")==0)
				strcpy(sqrpos[63-r].piece," Q ");
		}
	}
int validpawn()
{
	if((pos1!=pos2)&&pos1>=1&&pos1<=64&&pos2>=1&&pos2<=64&&sqrpos[pos2-1].player!=z)
	{
		int diff,i,flag=0;
		diff=pos2-pos1;
		if(z==1)
		{                                                       //To check the validity of the pawn
		if((diff==7||diff==9)&&sqrpos[pos2-1].player!=z&&sqrpos[pos2-1].player!=0)
		return 1;
		else if(diff==16&&sqrpos[pos2-1].player==0&&(pos1>=9&&pos1<=16))
		return 1;
		else if(diff==8)
			if(sqrpos[pos2-1].piece[0]!='\0')
				return 0;
			else
				return 1;
		else return 0;
		}
		else if (z==2)
		{
			if((diff==-7||diff==-9)&&sqrpos[pos2-1].player!=z&&sqrpos[pos2-1].player!=0)
		return 1;
		else if(diff==-16&&sqrpos[pos2-1].player==0&&(pos1>=49&&pos1<=56))
		return 1;
		else if(diff==-8)
			if(sqrpos[pos2-1].piece[0]!='\0')
				return 0;
			else
				return 1;
		else return 0;
		}

	}
	else
	return 0;
}
int validrook()  //To check the validity of the rook
{
	int flag=0,i,diff;
	if((pos1!=pos2)&&pos1>=1&&pos1<=64&&pos2>=1&&pos2<=64&&sqrpos[pos2-1].player!=z)
	{
		diff=abs(pos1-pos2);
		if(diff%8==0)
		{
			for(i=pos1+8;i<pos2;i+=8)
			if(sqrpos[i-1].piece[0]!='\0')
			  {	flag=1;
				break;
			  }
				if(flag==1)
			return 0;
			else
			return 1;
		}
		else if((pos1)/8==(pos2)/8)
		{
			if(pos1<pos2)
				{
					for(i=pos1;i<pos2-1;i++)
					if(sqrpos[i].piece[0]!='\0')
					{
					flag=1;
					break;
					}
					if(flag==1)
					return 0;
					else
					return 1;
				}
			else if(pos1>pos2)
			{
					for(i=pos1-2;i>pos2;i--)
					if(sqrpos[i].piece[0]!='\0')
					{
					flag=1;
					break;
					}
					if(flag==1)
					return 0;
					else
					return 1;
			}
		}
	}
		else
		return 0;
}

int validking()
{
	if((pos1!=pos2)&&pos1>=1&&pos1<=64&&pos2>=1&&pos2<=64&&sqrpos[pos2-1].player!=z)
	{
		int diff,i,flag=0;
		diff=abs(pos1-pos2);
		if(diff==8||diff==7||diff==9||diff==1)            //To check validity of the king
			if(sqrpos[pos2-1].player!=z)
				return 1;
			else
				return 0;
	}
	else
	return 0;
}
int castle()
{
	if(pos1==1000)
	{
		if(z==2)
		{
		if(sqrpos[62].piece[0]=='\0'&&sqrpos[61].piece[0]=='\0'&&sqrpos[60].piece[0]=='\0')
		return 1;
		else
		return 0;                               //To check the validity of castle
				}
		else if(z==1)
		{
		if(sqrpos[6].piece[0]=='\0'&&sqrpos[5].piece[0]=='\0'&&sqrpos[4].piece[0]=='\0')
		return 1;
		else
		return 0;
		}
		else
		return 0;
		}
		else if(pos1==2000)
		{
			if(z==2)
		{
		if(sqrpos[57].piece[0]=='\0'&&sqrpos[58].piece[0]=='\0')
		return 1;
		else
		return 0;
		}
		else if(z==1)
		{
		if(sqrpos[1].piece[0]=='\0'&&sqrpos[2].piece[0]=='\0')
		return 1;
		else
		return 0;
		}
		else
		return 0;
		}
		else
		return 0;
	}
	////////////////////////////////////////
int validknight()  //To check the validity of the knight
{
	if((pos1!=pos2)&&pos1>=1&&pos1<=64&&pos2>=1&&pos2<=64&&sqrpos[pos2-1].player!=z)
	{
		int diff,p1,p2;
		diff=abs(pos1-pos2);
		p1=pos1%8;
		p2=pos2%8;
		if(diff==1)
		return 0;
		if(p1==0&&p2==1)
		{		if((diff==15||diff==17||diff==10||diff==6)&&pos1/8!=pos2/8&&((pos1/8)-(pos2/8)!=2)&&((pos1/8)-(pos2/8)!=-2))
			return 1;
		}
		else if(p1==1&&p2==0)
			{
				if((diff==15||diff==17||diff==10||diff==6)&&pos1/8!=pos2/8&&((pos1/8)-(pos2/8)!=2)&&((pos1/8)-(pos2/8)!=-2))
				return 1;
			}
		else
		{
			if((diff==15||diff==17||diff==10||diff==6)&&pos1/8!=pos2/8&&(p1>=p2-2&&p2<=p1+2||p2>=p1-2&&p2<=p1+2))
			return 1;
		}
	}
	return 0;
}

int validbishop()
{
	if((pos1!=pos2)&&pos1>=1&&pos1<=64&&pos2>=1&&pos2<=64&&sqrpos[pos2-1].player!=z)
	{
		int i,diff,flag=1;
		diff=abs(pos1-pos2);         //To check the validity of the bishop
		if(diff==7||diff==9)
		return 1;
		else if(diff%7==0)
		{flag=0;
		for(i=pos1+7;i<pos2;i+=7)
		{
			if(sqrpos[i-1].piece[0]!='\0')
			  {	flag=1;
				break;
			  }

		}
		if(flag==1)
		return 0;
		else
		return 1;
		}
		else if(diff%9==0)
		   {  flag=0;
			for(i=pos1+9;i<pos2;i+=9)
		{
			if(sqrpos[i-1].piece[0]!='\0')
			   {	flag=1;
				break;
			}

		}
		   }

		if(flag==1)
		  return 0;
		return 1;
		}
		else return 0;
	}
void colorsquare()
{
	int x=0;
	for(int i=0;i<65;i++)
	{
		pos2=i+1;
		x=valid();
		if(x==1)
		{
			setcolor(YELLOW);
		setfillstyle(SOLID_FILL,GREEN);
			floodfill(sqrpos[i].y-20,sqrpos[i].x-20,YELLOW);


		}

	}
}
int validqueen()
{       int x;
	x=validbishop();    //To check validity of the king
	if(x==1)
	return x;
	else
	x=validrook();
	return x;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////



int validplayer()
{
	if(sqrpos[pos1-1].player==z)       //To check if the move is entered by the right player
	return 1;
	else
	return 0;
}

int valid()
{       int temp=0;
	char ch[3];                                 //To call the valid functions
	strcpy(ch,sqrpos[pos1-1].piece);
	if(pos1!=pos2)
	switch (ch[1])
	{
		case 'R':temp=validrook();
			 break;

		   case 'N':temp=validknight();
			   break;

		case 'B':temp=validbishop();
			   break;

		case 'K':temp=validking();;
		 break;

		case 'Q':temp=validqueen();
		   break;
		case 'P':temp=validpawn();
		break;
	}
	return temp;
}

void reset()
{
	assignpos();    //To reset the board
	z=1;
}

void getmove(void)
{
char as,choice,ch,str[5];                     //To take input from the user
int ll,nn;
settextstyle(0,HORIZ_DIR,0);
if(z==1)
	outtextxy(10,10,"PLAYER 1");
else if(z==2)
	outtextxy(10,10,"PLAYER 2");
	outtextxy(10,30,"Enter initial piece position  ");
for(int i=0;i>=0;i++)
			{

				ch=getch();
				if(ch==13)
				break;
				str[i]=ch;
				str[i+1]='\0';
				outtextxy(250,30,str);

				 if(ch==8)
				{
					str[i-1]='\0';
					setfillstyle(SOLID_FILL,BLACK);
					bar(240,20,300,40);
					outtextxy(250,30,str);
					i=i-2;

				}

			 }
pos1=atoi(str);
if(pos1==999&&guest==1)
exit(0);
else if(pos1==999&&guest==0)
{
	outtextxy(10,70,"Do you want to save?(Y/N)");
	choice=getch();
	if(choice=='y'||choice=='Y')
		{
			ofstream fout(username,ios::binary);
			for(int i=0;i<66;i++)
			fout.write((char*)&sqrpos[i],sizeof(xycoord));
			fout.close();
			newuser();
		 }
		 else
		 newuser();
}

else if(pos1==1000||pos1==2000)
{
	ll=castle();
	if(ll==1)
		changepos();
}
else if(pos1==5000)
reset();

else{colorsquare();
outtextxy(10,50,"Enter final piece position  ");
}
for(i=0;i>=0;i++)
			{

				ch=getch();
				if(ch==13)
				break;
				str[i]=ch;
				str[i+1]='\0';
				outtextxy(250,50,str);

				 if(ch==8)
				{
					str[i-1]='\0';
					setfillstyle(SOLID_FILL,BLACK);
					bar(240,40,300,60);
					outtextxy(250,50,str);
					i=i-2;

				}

			 }
			 pos2=atoi(str);

}





void changepos(void)
{
if(pos1==1000)                            //To move the pieces
{
	if(z==1)
	{
		strcpy(sqrpos[5].piece,sqrpos[3].piece);
		strcpy(sqrpos[3].piece,"");
		sqrpos[5].player=sqrpos[3].player;
		sqrpos[3].player=0;
		strcpy(sqrpos[4].piece,sqrpos[7].piece);
		strcpy(sqrpos[7].piece,"");
		sqrpos[4].player=sqrpos[7].player;
		sqrpos[7].player=0;
		z++;

	}
	else if(z==2)
	{
		strcpy(sqrpos[61].piece,sqrpos[59].piece);
		strcpy(sqrpos[59].piece,"");
		sqrpos[61].player=sqrpos[59].player;
		sqrpos[59].player=0;
		strcpy(sqrpos[60].piece,sqrpos[63].piece);
		strcpy(sqrpos[63].piece,"");
		sqrpos[60].player=sqrpos[63].player;
		sqrpos[63].player=0;
		z--;

	}
}
else if(pos1==2000)
{
	if(z==1)
	{
		strcpy(sqrpos[1].piece,sqrpos[3].piece);
		strcpy(sqrpos[3].piece,"");
		sqrpos[1].player=sqrpos[3].player;
		sqrpos[3].player=0;
		strcpy(sqrpos[2].piece,sqrpos[0].piece);
		strcpy(sqrpos[0].piece,"");
		sqrpos[2].player=sqrpos[0].player;
		sqrpos[0].player=0;
		z++;

	}
	else if(z==2)
	{
		strcpy(sqrpos[57].piece,sqrpos[59].piece);
		strcpy(sqrpos[59].piece,"");
		sqrpos[57].player=sqrpos[59].player;
		sqrpos[59].player=0;
		strcpy(sqrpos[58].piece,sqrpos[56].piece);
		strcpy(sqrpos[56].piece,"");
		sqrpos[58].player=sqrpos[56].player;
		sqrpos[56].player=0;
		z--;

	}

}
else
{
	strcpy(sqrpos[pos2-1].piece,sqrpos[pos1-1].piece);
	strcpy(sqrpos[pos1-1].piece,"");
	sqrpos[pos2-1].player=sqrpos[pos1-1].player;
	sqrpos[pos1-1].player=0;
}
}


////////////////////////////////////////////////////////////////////////////////

int  check(xycoord a[])
	 {                                //To check for checkmate
	 int flag1=0,flag2=0;
	 for(int c=0;c<64;c++)
	 if(strcmp(a[c].piece," K ")==0&&a[c].player==1)
	 flag1=1;
	 for(int i=0;i<64;i++)
	 if(strcmp(a[i].piece," K ")==0&&a[i].player==2)
	 flag2=1;
	 if(flag1==0)
	 return 2;
	 else if(flag2==0)
	 return 1;
	 else
	 return 0;
	 }
////////////////////////////////////////////////////////////////////////////////
	 int callmouse()
	  {
		 in.x.ax=1;                 //To display the mouse
		 int86(51,&in,&out);
		 return 1;
	  }
////////////////////////////////////////////////////////////////////////////////
	 void restrictmouseptr(int x1,int y1,int x2,int y2)
	  {
		 in.x.ax=7;
		 in.x.cx=x1;                   //To restrict the mouse pointer's movement within the rectangle
		 in.x.dx=x2;
		 int86(51,&in,&out);
		 in.x.ax=8;
		 in.x.cx=y1;
		 in.x.dx=y2;
		 int86(51,&in,&out);
	  }
////////////////////////////////////////////////////////////////////////////////
	  void mouseposi(int x[],int &xpos,int &ypos,int &click)
	   {
		  in.x.ax=3;               //To return the x and y coordinates of the mouse
		  int86(51,&in,&out);
		  click=out.x.bx;
		  xpos=out.x.cx;
		  ypos=out.x.dx;
		  if(!click)j=1;
		  if(click&&j==1)
		  {
		  x[0]=xpos;
		  x[1]=ypos;
		  }
	  }
//////////////////////////////////////////////////////////////////////////////////
	  void setposi(int &xpos,int &ypos)
	  {
		 in.x.ax=4;
		 in.x.cx=xpos;
		 in.x.dx=ypos;
		 int86(51,&in,&out);
	  }
////////////////////////////////////////////////////////////////////////////////
	   void rules()
	 {       mousehide();
		 cleardevice();
		 settextstyle(3,HORIZ_DIR,6);              //To display the rules
		 setcolor(CYAN);
		 outtextxy(230,20,"RULES");
		 rectangle(10,10,620,450);
		 rectangle(15,15,615,445);
		 restrictmouseptr(15,15,615,445);
		 settextstyle(0,HORIZ_DIR,4);
		 outtextxy(577,25,"X");
		 settextstyle(0,HORIZ_DIR,1);
		 outtextxy(50, 90,"1.  Each of the 6 different kinds of pieces moves differently.");
		 outtextxy(50,100,"    Pieces cannot move through other pieces and can never move onto a");
		 outtextxy(50,110,"    square with one of their own pieces.");
		 outtextxy(50,130,"2.  Pawns can only move forward one square at a time, except");
		 outtextxy(50,140,"    for their very first move where they can move forward two squares.");
		 outtextxy(50,150,"    Pawns can only capture one square diagonally in front of them.");
		 outtextxy(50,160,"    They can never move or capture backwards");
		 outtextxy(50,180,"3.  The rook may move as far as it wants, but only forward,");
		 outtextxy(50,190,"    backward, and to the sides.");
		 outtextxy(50,210,"4.  The bishop may move as far as it wants, but only diagonally.");
		 outtextxy(50,230,"5.  Knights move in a very different way from the other pieces ");
		 outtextxy(50,240,"    going two squares in one direction, and then one more move at a");
		 outtextxy(50,250,"    90 degree angle, just like the shape of an \"L\".");
		 outtextxy(50,270,"6.  The queen can move in any one straight direction - forward, ");
		 outtextxy(50,280,"    backward, sideways, or diagonally - as far as possible as long as");
		 outtextxy(50,290,"    she does not move through any of her own pieces.");
		 outtextxy(50,310,"7.  The king can only move one square in any direction - up, down,");
		 outtextxy(50,320,"    to the sides, and diagonally.");
		 outtextxy(50,340,"8.  To move the pieces, enter the number of the box of the initial");
		 outtextxy(50,350,"    position and the number of the box of the final position.");
		 outtextxy(50,370,"9.  Enter 1000 for queen side castle. ");
		 outtextxy(50,390,"10. Enter 2000 for king side castle.");
		 outtextxy(50,410,"11. Enter 999 to end the game");
		 outtextxy(50,430,"12. Enter 5000 to reset the board");
		 rectangle(615,15,565,60);
		 rectangle(610,20,570,55);
		 int m=0;
		 setposi(a,b);
		 callmouse();
		 while(m==0)
		 {
		 mouseposi(posarr,x,y,cl);
			gotoxy(1,2);
		 if(posarr[0]>=550&&posarr[0]<=615&&posarr[1]<=60&&posarr[1]>=15)
		 {cleardevice();
		  mainmenu();
		  m=1;  }

		  }
		  mousehide();
		   }
////////////////////////////////////////////////////////////////////////////////
void loadsave()
{
	cleardevice();
	xycoord blank[65];
	setcolor(WHITE);
	rectangle(10,10,620,450);
	rectangle(15,15,615,445);
	setcolor(CYAN);
	outtextxy(30,45,"Do you want to continue your previous game?(Y/N)");
	choicen=getch();

	if(choicen=='n'||choicen=='N')
	{assignpos();main1();}
	if(choicen=='Y'||choicen=='y')
	{
		ifstream fin(username,ios::binary);
		for(int j=0;j<66;j++)
		{fin.read((char*)&blank[j],sizeof(xycoord));}
		for(int i=0;i<66;i++)
		{sqrpos[i]=blank[i];}
		getch();
		main1();

   }
	else
	{cout<<"WRONG INPUT!!\n";
	loadsave();}
}
////////////////////////////////////////////////////////////////////////////////
void main1()
{
	int x=0,v=0,vp=0;
	if(guest==1)
	reset();				 //To control the flow of the program
	while(x==0)
	{
		cleardevice();
		display();
		if(z==1)
		{

			getmove();
			vp=validplayer();
			if(pos1!=1000&&pos1!=2000)
			{
			if(vp==1)
			v=valid();
			if(v==1)
			{
			changepos();
			z++;
			}
			else
			{ 	settextstyle(0,HORIZ_DIR,0);
				outtextxy(10,90,"WRONG INPUT");getch();}
			}
		}
		x=check(sqrpos);
		promo();
		v=0;
		vp=0;
		if(x!=0)
		{
			cleardevice();
			display();
			delay(50);
			cout<<"Player "<<x<<" Wins";
			getch();
			reset();
		}
		clrscr();
		cleardevice();
		display();
		if(z==2)
		{

			getmove();
			vp=validplayer();
			if(pos1!=1000&&pos2!=2000)
			{
			if(vp==1)
			v=valid();
			if(v==1)
			{
			changepos();
			z--;
			}
			else
			{settextstyle(0,HORIZ_DIR,0);
				outtextxy(10,90,"WRONG INPUT");getch();}
			}
		}
		x=check(sqrpos);
		promo();
		v=0;
		vp=0;
		if(x!=0)
		{
			cleardevice();
			display();
			delay(50);
			cout<<"Player "<<x<<" Wins";
			getch();
			reset();
		}
		clrscr();

}
cleardevice();
cout<<"PLAYER "<<x<<" WINS";

}
////////////////////////////////////////////////////////////////////////////////
	 void mainmenu()
	  {
		 char l[80];
		 int nn;
		 mousehide();
		 cleardevice();
		 callmouse();                   //To display the main menu
		 int k=0;
		 setcolor(RED);
		 callmouse();
		 settextstyle(4,HORIZ_DIR,6);
		 outtextxy(230,20,"CHESS");
		 rectangle(10,10,620,450);
		 rectangle(15,15,615,445);
		 restrictmouseptr(15,15,615,445);


		 setposi(a,b);
		 callmouse();
		 do
		 {
			settextstyle(3,HORIZ_DIR,4);
			mouseposi(posarr,x,y,cl);
			gotoxy(1,2);
			setcolor(LIGHTRED);
			rectangle(150,150,475,200);
			rectangle(155,155,470,195);
			setcolor(YELLOW);
			outtextxy(270,150,"PLAY");

			setcolor(LIGHTRED);
			rectangle(150,250,475,300);
			rectangle(155,255,470,295);
			setcolor(YELLOW);
			outtextxy(270,254,"RULES");

			setcolor(LIGHTRED);
			rectangle(150,355,475,400);
			rectangle(155,360,470,395);
			setcolor(YELLOW);
			outtextxy(270,355,"QUIT");

			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=350&&posarr[1]<=400)

			{
			newuser();
			}
			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]<=300&&posarr[1]>=250)
			{
			rules();
			cleardevice();
			}

			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=150&&posarr[1]<=200)
			{
			mousehide();
			cleardevice();
			main1();

			}


		 }while(k==0);

		 mousehide();

	 }
	 void login()
{
	char un[20],pass[20];
	int flag=0;
	ifstream fin;
	fin.open("LOGIN.TXT");

	while(!(fin.eof()))
	{
		fin>>un;
		fin>>pass;
		cout<<un;
		cout<<pass<<endl;
		if(strcmpi(un,username)==0&&strcmpi(pass,password)==0)
		{flag=1;break;}
	}
	if(flag==1)
	{cout<<"Valid user\n";loadsave();}
	else
	cout<<"Invalid user\n";

	getch();
	fin.close();
	newuser();
}
	 void admin()
	{
		 posarr[0]=0;
		 posarr[1]=0;
		 mousehide();
		 cleardevice();
		 char ch,us[20],pass[20],us1[20],nus[20],npass[20];
		 int k=0,x=0,y=0;
		 setcolor(WHITE);


		 rectangle(10,10,620,450);
		 rectangle(15,15,615,445);

		 settextstyle(3,HORIZ_DIR,4);



			rectangle(230,170,555,220);
			rectangle(235,175,550,215);
			outtextxy(30,175,"USERNAME");

			rectangle(230,240,555,290);
			rectangle(235,245,550,285);
			outtextxy(30,245,"PASSWORD");
			gotoxy(35,13);
			for(int i=0;i>=0;i++)
			{

				ch=getch();
				if(ch==13)
				break;
				us[i]=ch;
				us[i+1]='\0';
				outtextxy(260,170,us);

				 if(ch==8)
				{
					us[i-1]='\0';
					setfillstyle(SOLID_FILL,BLACK);
					bar(245,180,545,210);
					outtextxy(260,170,us);
					i=i-2;

				}

			 }
			gotoxy(35,17);
			for(i=0;;i++)
			{
				ch=getch();
				if(ch==13)
				break;
				pass[i]=ch;
				pass[i+1]='\0';
				outtextxy(260+(i*15),240,"*");

				if(ch==8)
				{
					pass[i-1]='\0';
					setfillstyle(SOLID_FILL,BLACK);
					bar(245,250,545,280);
					for(int n=0;n<i-1;n++)
					outtextxy(260+(n*15),240,"*");
					i=i-2;

				}
			 }
			 if(strcmpi(us,"Admin")==0&&strcmpi(pass,"Admin")==0)
			 {
			  char l[80];
		 int nn;
		 mousehide();
		 cleardevice();
		 callmouse();                   //To display the main menu
		 int k=0;
		 setcolor(RED);
		 callmouse();
		 settextstyle(4,HORIZ_DIR,6);
		 outtextxy(230,20,"CHESS");
		 rectangle(10,10,620,450);
		 rectangle(15,15,615,445);
		 restrictmouseptr(15,15,615,445);


		 setposi(a,b);
		 callmouse();
		 do
		 {

			settextstyle(3,HORIZ_DIR,4);
			mouseposi(posarr,x,y,cl);
			gotoxy(1,2);
			setcolor(LIGHTRED);
			rectangle(150,150,475,200);
			rectangle(155,155,470,195);
			setcolor(YELLOW);
			outtextxy(270,150,"UPDATE");

			setcolor(LIGHTRED);
			rectangle(150,250,475,300);
			rectangle(155,255,470,295);
			setcolor(YELLOW);
			outtextxy(270,254,"DELETE");

			setcolor(LIGHTRED);
			rectangle(150,355,475,400);
			rectangle(155,360,470,395);
			setcolor(YELLOW);
			outtextxy(270,355,"QUIT");

			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=350&&posarr[1]<=400)

			{
			newuser();
			}
			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]<=300&&posarr[1]>=250)
			{
			cleardevice();
			ifstream fin("LOGIN.TXT");
			ofstream fout("NEW.TXT");
			cout<<"Enter the username to be deleted"<<endl;
			cin>>us1;
			while(!fin.eof())
			{
				fin>>us;
				fin>>pass;
				if(strcmp(us,us1)!=0)
				{
					fout<<us<<endl;
					fout<<pass<<endl;
				 }
			}
			fin.close();
			fout.close();
			remove("LOGIN.TXT");
			rename("NEW.TXT","LOGIN.TXT");
			posarr[0]=0;
			posarr[1]=0;
			newuser();
			}

			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=150&&posarr[1]<=200)
			{
			cleardevice();
			cout<<"Enter the username to be updated"<<endl;
			cin>>us1;
			cout<<"Enter the new username"<<endl;
			cin>>nus;
			cout<<"Enter the new password"<<endl;
			cin>>npass;
			ifstream fin("LOGIN.TXT");
			ofstream fout("NEW.TXT");
			while(!fin.eof())
			{
				fin>>us;
				fin>>pass;
				if(strcmp(us,us1)!=0)
				{
					fout<<us<<endl;
					fout<<pass<<endl;
				 }
				if(strcmp(us,us1)==0)
				{
					fout<<nus<<endl;
					fout<<npass<<endl;
				 }
			 }
			fin.close();
			fout.close();
			remove("LOGIN.TXT");
			rename("NEW.TXT","LOGIN.TXT");
			posarr[0]=0;
			posarr[1]=0;
			newuser();

			admin();
			}


		 }while(k==0);

		 mousehide();

			 }
	}

	 void newuser()
	  {
		 posarr[0]=0;
		 posarr[1]=0;
		 mousehide();
		 cleardevice();
		 callmouse();
		 int k=0;
		 setcolor(RED);
		 callmouse();
		 settextstyle(4,HORIZ_DIR,6);
		 outtextxy(230,20,"CHESS");
		 rectangle(10,10,620,450);
		 rectangle(15,15,615,445);
		 restrictmouseptr(15,15,615,445);


		 setposi(a,b);
		 callmouse();
		 do
		 {
			settextstyle(3,HORIZ_DIR,4);
			mouseposi(posarr,x,y,cl);
			gotoxy(1,2);
			setcolor(LIGHTRED);
			rectangle(150,170,475,220);
			rectangle(155,175,470,215);
			setcolor(YELLOW);
			outtextxy(260,170,"GUEST");

			setcolor(LIGHTRED);
			rectangle(150,240,475,290);
			rectangle(155,245,470,285);
			setcolor(YELLOW);
			outtextxy(270,245,"USER");


			setcolor(LIGHTRED);
			rectangle(150,315,475,360);
			rectangle(155,320,470,355);
			setcolor(YELLOW);
			outtextxy(260,315,"ADMIN");


			setcolor(LIGHTRED);
			rectangle(150,385,475,430);
			rectangle(155,390,470,425);
			setcolor(YELLOW);
			outtextxy(275,385,"QUIT");

			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=390&&posarr[1]<=430)
			exit(0);
			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=170&&posarr[1]<=220)
			{guest=1; mainmenu(); }
			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=240&&posarr[1]<=290)
			user();
			if(posarr[0]>=150&&posarr[0]<=475&&posarr[1]>=320&&posarr[1]<=360)
			admin();


		 }while(k==0);

		 mousehide();

	 }
	 void user()
	  {
		 posarr[0]=0;
		 posarr[1]=0;
		 mousehide();
		 cleardevice();
		 char choice,ch;
		 int k=0;
		 setcolor(WHITE);

		 rectangle(10,10,620,450);
		 rectangle(15,15,615,445);

		 settextstyle(3,HORIZ_DIR,4);



			rectangle(230,170,555,220);
			rectangle(235,175,550,215);
			outtextxy(30,175,"USERNAME");

			rectangle(230,240,555,290);
			rectangle(235,245,550,285);
			outtextxy(30,245,"PASSWORD");
			gotoxy(35,13);
			for(int i=0;i>=0;i++)
			{

				ch=getch();
				if(ch==13)
				break;
				username[i]=ch;
				username[i+1]='\0';
				outtextxy(260,170,username);

				 if(ch==8)
				{
					username[i-1]='\0';
					setfillstyle(SOLID_FILL,BLACK);
					bar(245,180,545,210);
					outtextxy(260,170,username);
					i=i-2;

				}

			 }
			gotoxy(35,17);
			for(i=0;;i++)
			{
				ch=getch();
				if(ch==13)
				break;
				password[i]=ch;
				password[i+1]='\0';
				outtextxy(260+(i*15),240,"*");

				if(ch==8)
				{
					password[i-1]='\0';
					setfillstyle(SOLID_FILL,BLACK);
					bar(245,250,545,280);
					for(int n=0;n<i-1;n++)
					outtextxy(260+(n*15),240,"*");
					i=i-2;

				}
			 }
			if(strcmpi(password,"999")==0)
			exit(0);
			cleardevice();
			rectangle(10,10,620,450);
			rectangle(15,15,615,445);
			settextstyle(3,HORIZ_DIR,3);
			setcolor(3);
			outtextxy(30,45,"Are you a new user?(Y/N)");
			choice=getch();
			if(choice=='y'||choice=='Y')
			{
			char un[20],pass[20],flag=0;
			ifstream fin;
			fin.open("LOGIN.TXT");

	while(!(fin.eof()))
	{
		fin>>un;
		fin>>pass;
		if(strcmpi(un,username)==0)
		{flag=1;break;}
	}
	fin.close();
	if(flag==1)
	{outtextxy(30,75,"Username Taken!\n");getch();newuser();}
	else
	{		ofstream fout;
			fout.open("LOGIN.TXT",ios::app);
			fout<<username<<"\n";
			fout<<password<<"\n";
			fout.close();
			outtextxy(30,75,"User Registered. Press a key to log in.");
			getch();
	 }

	newuser();
	}
			else
			 {
			 char un[20],pass[20];
	int flag=0;
	ifstream fin;
	fin.open("LOGIN.TXT");

	while(!(fin.eof()))
	{
		fin>>un;
		fin>>pass;
		if(strcmpi(un,username)==0&&strcmpi(pass,password)==0)
		{flag=1;break;}
	}
	if(flag==1)
	{outtextxy(30,75,"Valid user"); loadsave();}
	else
	outtextxy(30,75,"Invalid user");

	getch();
	fin.close();
	newuser();
}



	 }

////////////////////////////////////////////////////////////////////////////////

	 void main()
	 {
	 int k=0;
	 int gd=DETECT,gm;
	 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	 ofstream fout("LOGIN.TXT",ios::app);
	 fout.close();
	 //sqrpos[0].intro();
	 if(k==0)
	 {
	newuser();
	k++;
	 }
}
