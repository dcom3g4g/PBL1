#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<MMsystem.h>
#pragma comment(lib,"winmm.lib") ; 
int n,i,a[1000],k,j,m,l,cl,dph,hh,max,stt;  
struct nguoi
{
	char ht[20] ; 
	char gt[20] ; 
	int tuoi ; 
	int t; 
	char st1[20] ;
	char st2[20] ;
	char st3[20] ;
	char st4[20] ;
	char st5[20] ; 
	char test[20] ; 
	int dem ; 
	int u1,u2,u3,u4,u5; 
    char dc[50];
    char sdt[50] ; 
}; 
struct sthich
{
	char st[20]; 
};
sthich c[100] ; 
nguoi b[100];
int x,tg,tcl; 
char htg[20],gtg[20],st1g[20],st2g[20],st3g[20],st4g[20],st5g[20],h[20],d[20] ; 
FILE *f; 
void laydl(); 
void nhapten() ;
void inhoa(char x[20]) ; 
void dongbo(nguoi b[], int n) ; 
void sosanh(nguoi b[]) ; 
void xuat(int i) ; 
void in() ;  
int tinhdothichhop(int i) ; 
void doi(nguoi b[]); 
void TextColor(int x); 
void intheotuoi() ; 
void vett(int i) ; 
int main() { 
	f=fopen("C:\\thi\\sss.txt","r") ;  
	TextColor(6) ; 
	printf("\t			PBL1:DO AN TINH TOAN  				       \n");
	printf("\t DE TAI: Xay dung chuong trinh tinh kiem nua kia      \n"); 
	printf("\t Thanh vien: 				    Nguoi huong dan:   \n");
	printf("\t Tran Van Hai			           Nguyen Thi Minh Hy \n");
	printf("\t Nguyen Hoang Vu				       \n");
	do 
	{
		TextColor(3) ; 
		printf("          Chuong trinh tim kiem nua kia cua ban       \n") ;
		printf("1.Nhap thong tin\n") ; 
		printf("2.In ra danh sach nhung nguoi phu hop voi ban \n") ;
		printf("3.In ra nguoi trong do tuoi ban muon \n"); 
		printf("4.In ra 1 nguoi trung nhieu so thich voi ban nhat\n") ;
		printf("5.Test do phu hop cua ban voi nguoi ay \n");
		printf("0.Thoat chuong trinh\n") ; 	
		printf("Moi nhap lua chon cua ban\n") ;
		scanf("%d",&k) ; gets(d) ; 
		switch (k)
		{
			case 1: 
			{ 
				TextColor(10) ; 
				nhapten() ; l=1; 
				laydl() ; 
				dongbo(b,n) ;
				sosanh(b) ; 
			 
				break ; 
			}
			case 2: 
			{
				TextColor(10) ; 
				if(l==0) 
				{	PlaySound(TEXT("C:\\thi\\f.wav"), NULL,SND_ASYNC);
					printf("BAN CHUA NHAP DU LIEU NAO \n") ; 
					printf("YEU CAU BAN NHAP LAI \n") ; 
				}
				else 
				{
				m=0;
				for (i=1;i<=n;i++) 
					{
						if(b[i].dem>0) m=1; 
					}
				if (m==0) 
					{ 
						printf("KHONG CO AI PHU HOP VOI BAN\n"); 
						PlaySound(TEXT("C:\\thi\\ff.wav"), NULL,SND_ASYNC);
					} else {
						PlaySound(TEXT("C:\\thi\\1c.wav"), NULL,SND_ASYNC);
						doi(b) ; 
						printf("\n 		NHUNG NGUOI PHU HOP      \n") ; 
						in() ; 
							}
				} break;
			}
			case 4: 
			{ 
				TextColor(10) ; 
				if(l==0) 
				{	PlaySound(TEXT("C:\\thi\\f.wav"), NULL,SND_ASYNC);
					printf("BAN CHUA NHAP DU LIEU NAO \n") ; 
					printf("YEU CAU BAN NHAP LAI \n") ; 
				} else	
				{
				m=0;
				for (i=1;i<=n;i++) {	if(b[i].dem>0) m=1; }
				if (m==0) 
				{ 
					PlaySound(TEXT("C:\\thi\\ff.wav"), NULL,SND_ASYNC);
					printf("KHONG CO AI PHU HOP VOI BAN\n"); 
				} else 	{ 
					PlaySound(TEXT("C:\\thi\\1c.wav"), NULL,SND_ASYNC);
					doi(b) ; 
					printf("\n 	NGUOI PHU HOP VOI BAN NHAT\n") ; 
					xuat(1) ; 	
					}
				}
				 break;
			}
			case 3:
			{
				TextColor(10) ; 
				if(l==0) 
				{	PlaySound(TEXT("C:\\thi\\f.wav"), NULL,SND_ASYNC);
					printf("BAN CHUA NHAP DU LIEU NAO \n") ; 
					printf("YEU CAU BAN NHAP LAI \n") ; 
				} else {
					printf("Moi ban nhap do tuoi chenh lech ban muon ") ;
					scanf("%d",&tcl) ;   gets(d) ; 
					m=0;
					for (i=1;i<=n;i++) {	if(abs(tg-b[i].tuoi)<=tcl) m=1; }
					if (m==0) 
					{ 
						PlaySound(TEXT("C:\\thi\\ff.wav"), NULL,SND_ASYNC);
						printf("KHONG CO AI PHU HOP VOI BAN\n"); 
					} 
					else 
					{ 
						PlaySound(TEXT("C:\\thi\\1c.wav"), NULL,SND_ASYNC);
						doi(b) ; 
						printf("\n 	Danh sach nguoi sap sap theo do tuoi ban muon\n") ; 
						intheotuoi() ; 
					} 
						}
					break;
			}
			case 5: 
			{
				TextColor(10) ; 
				if(l==0) 
				{	PlaySound(TEXT("C:\\thi\\f.wav"), NULL,SND_ASYNC);
					printf("BAN CHUA NHAP DU LIEU NAO \n") ; 
					printf("YEU CAU BAN NHAP LAI \n") ; 
				}
				else 
				{
				m=0;
				for (i=1;i<=n;i++) 
					{
						if(b[i].dem>0) m=1; 
					}
				if (m==0) 
					{ 
						printf("KHONG CO AI PHU HOP VOI BAN\n"); 
						PlaySound(TEXT("C:\\thi\\ff.wav"), NULL,SND_ASYNC);
					} else {
						PlaySound(TEXT("C:\\thi\\1c.wav"), NULL,SND_ASYNC);
						doi(b) ; 
						printf("\n 		NHUNG NGUOI PHU HOP      \n") ; 
						in() ; 
						printf("Ban co muon xem ty le thanh cong cua nguoi ay voi ban khong\n") ; 
						printf("Neu co an phim 1, neu khong nhan phim 0 \n") ; 
						scanf("%d",&hh) ; 
						if(hh==1) 
						{	
							printf("Moi nhap so thu tu cua nguoi do\n") ; 
							scanf("%d",&stt) ;
							if (b[stt].dem>0)
							{
								vett(tinhdothichhop(stt)) ;  break;
							} else 
							{
								printf("\n Nguoi nay kh co so thich nao trung voi ban trong danh sach");
							}
							
						} else	break;
							}
				} break;
			}
			case 0:
			{ 
				break;
			}
			default: 
			{
				PlaySound(TEXT("C:\\thi\\f.wav"), NULL,SND_ASYNC);
				TextColor(10) ;
				printf("BAN DA NHAP SAI MOI BAN NHAP LAI\n");
			}	
		} 
	} while (k!=0) ; 
	return 0; 
};
void laydl() {
	fscanf(f,"%d",&n);
	fgets(h,20,f) ; 
	for (i=1;i<=n;i++)
	{
	fgets(b[i].ht,20,f) ; 
	fgets(b[i].gt,20,f) ;  
	fscanf(f,"%d",&b[i].tuoi) ; 
	fgets(b[i].test,20,f) ;
	fgets(b[i].st1,20,f) ;
	fgets(b[i].st2,20,f) ;
	fgets(b[i].st3,20,f) ;
	fgets(b[i].st4,20,f) ;
	fgets(b[i].st5,20,f) ;
	fgets(b[i].dc,50,f) ;
	fgets(b[i].sdt,50,f) ; 
	b[i].u1=0;
	b[i].u2=0;
	b[i].u3=0;
	b[i].u4=0;
	b[i].u5=0;
	}
}
void nhapten() {
	
	printf("Nhap ten:  ") ;
	gets(htg) ; 
	htg[strlen(htg)]='\n' ; 
	strupr(htg) ;
	//printf("%s  %d ",htg,strlen(htg)) ; 
	printf("Gioi tinh:  ") ; 
	gets(gtg) ; 
	gtg[strlen(gtg)]='\n' ; 
	strupr(gtg) ; 
	printf("Tuoi:  ") ; 
	scanf("%d",&tg) ; 
	printf("Nhap so so thich ") ;  
	scanf("%d",&x) ; 
	for (j=0;j<=x;j++) 
{	if (j!=0) printf("\nTen so thich %d  ",j);
	gets(c[j].st) ; 
	c[j].st[strlen(c[j].st)]='\n' ; 
	strupr(c[j].st) ; 
} }
void sosanh(nguoi b[]) { 
for (i=1;i<=n;i++) 
{
	b[i].dem=0; 
	if (strcmp(b[i].gt,gtg)!=0 ) {	
		for (j=1;j<=x;j++) {
			if (strcmp(c[j].st,b[i].st1)==0) 
				{b[i].dem=b[i].dem+1 ; b[i].u1=1;} 
			if (strcmp(c[j].st,b[i].st2)==0) 
				{b[i].dem=b[i].dem+1 ; b[i].u2=1;} 
			if (strcmp(c[j].st,b[i].st3)==0) 
				{b[i].dem=b[i].dem+1 ; b[i].u3=1;} 
			if (strcmp(c[j].st,b[i].st4)==0) 
				{b[i].dem=b[i].dem+1 ; b[i].u4=1;} 
			if (strcmp(c[j].st,b[i].st5)==0) 
				{b[i].dem=b[i].dem+1 ; b[i].u5=1;} 
	} 
							}
}
}

void doi(nguoi b[]) {
nguoi tam; 
	
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (b[i].dem>=b[j].dem) {
			tam=b[i] ; 
			b[i]=b[j] ; 
			b[j]=tam ;  
			}
		}
	}
}
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void xuat(int e) 
{
	printf("STT:%d  ",e) ; 
	printf("Ten  :  %s",b[e].ht) ;
	printf("Gioi tinh  %s",b[e].gt) ;
	printf("Tuoi:  %d \n",b[e].tuoi) ; 
	printf("CAC SO THICH TRUNG : \n") ; 
	if(b[e].u1==1) printf("%s",(b[e].st1)) ; 
	if(b[e].u2==1) printf("%s",b[e].st2) ; 
	if(b[e].u3==1) printf("%s",b[e].st3) ; 
	if(b[e].u4==1) printf("%s",b[e].st4) ; 
	if(b[e].u5==1) printf("%s",b[e].st5) ; 
	printf("So so thich giong nhau : %d \n",b[e].dem); 
	printf("%s",b[e].dc);
	printf("%s \n",b[e].sdt) ; 
	printf("---------------------\n") ; 
}
void in() {
	int j=0; 
	for (i=1;i<=n;i++) {
	if (b[i].dem!=0 ) { j++;
	xuat(i) ; 
	}
	} 
}
int tinhdothichhop(int i) 
{	int x ;
	j=rand() ; 
	x=b[i].dem*20+(j%21) ;
	if (x>100) x=x-(x-100)-1 ; 
	return x; 
}
void intheotuoi() {
	for (i=1;i<=n;i++) 
	{
		if (abs(tg-b[i].tuoi)<=tcl && b[i].dem>0) {
		xuat(i) ; 
		} ; 
	}
}
void dongbo(nguoi b[],int n) 
{
	for (int k=1;k<=n;k++)
	{
		strupr(b[k].ht) ;
		strupr(b[k].gt) ; 
		strupr(b[k].st1) ;
		strupr(b[k].st2) ; 
		strupr(b[k].st3) ; 
		strupr(b[k].st4) ; 
		strupr(b[k].st5) ;   
	}
}
void vett(int i) {
	char so[20] ; 
   initwindow(600,600) ;
    setcolor(14) ;
     itoa (i,so,10);
     settextstyle(0,0,2); 
    outtextxy(50,90,"TY LE THANH CONG CUA BAN         ");
     
    outtextxy(450,90,so);
    outtextxy(490,90,"%");
    setcolor(RED);
	setfillstyle(1, 4);
  	line(200,169,300,310);    
	line(400,169,300,310) ; 
    sector(250, 169, 0, 180, 50, 60);
    a[0]=300;
    a[1]=310; 
	a[2]=200; 
	a[3]=169; 
	a[4]=400; 
	a[5]=169;  
    sector(350, 169, 0, 180, 50,60);
	fillpoly(3,a) ; 
	  
  	//delay(100000) ; 
    getch() ; 
    closegraph();
}

