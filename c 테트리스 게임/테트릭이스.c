#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define frame_X 30*2	//Ʋ�� ���� ���� 
#define frame_Y 7

#define hold_X frame_X-(6+2)*2

#define next_X frame_X+(3 )*2

#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // �ܼ�â�� �ڵ����� �ޱ�

#define BLACK                SetConsoleTextAttribute(COL, 0x0000);        // ������ 0
#define DARK_BLUE         SetConsoleTextAttribute(COL, 0x0001);        // �Ķ��� 1
#define GREEN                SetConsoleTextAttribute(COL, 0x0002);        // ��� 2
#define BLUE_GREEN        SetConsoleTextAttribute(COL, 0x0003);        // û��� 3
#define BLOOD               SetConsoleTextAttribute(COL, 0x0004);        // �˺����� 4
#define PURPLE               SetConsoleTextAttribute(COL, 0x0005);        // ����� 5
#define GOLD                 SetConsoleTextAttribute(COL, 0x0006);        // �ݻ� 6
#define ORIGINAL            SetConsoleTextAttribute(COL, 0x0007);        // ���� ȸ�� 7 (ORIGINAL CONSOLE COLOR)
#define GRAY                 SetConsoleTextAttribute(COL, 0x0008);        // ȸ�� 8
#define BLUE                  SetConsoleTextAttribute(COL, 0x0009);        // �Ķ��� 9
#define HIGH_GREEN       SetConsoleTextAttribute(COL, 0x000a);        // ���λ� 10
#define SKY_BLUE           SetConsoleTextAttribute(COL, 0x000b);        // �ϴû� 11
#define RED                   SetConsoleTextAttribute(COL, 0x000c);        // ������ 12
#define PLUM                SetConsoleTextAttribute(COL, 0x000d);        // ���ֻ� 13
#define YELLOW             SetConsoleTextAttribute(COL, 0x000e);        // ����� 14
#define WHITE                SetConsoleTextAttribute(COL, 0x000f);        // ��� 15

void textcolor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x,int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

int block[11][4][4][4]={	//�̳�	
{{{0, 0, 0, 0},{1, 1, 1, 1},{0, 0, 0, 0},{0, 0, 0, 0}},	//0 �� i�� ���
 {{0, 0, 1, 0},{0, 0, 1, 0},{0, 0, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 1},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0}}},
 
{{{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}}, //1 �� o�� ���
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}}},
 
{{{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 1, 0},{0, 0, 0, 0}},	//2 �� T�� ���
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0}}},
 
{{{0, 0, 0, 0},{0, 0, 1, 0},{1, 1, 1, 0},{0, 0, 0, 0}},	//3 �� l�� ���
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{0, 1, 1, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{1, 0, 0, 0}},
 {{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0}}},
 
{{{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 1, 0},{0, 0, 0, 0}},	//4 �� J�� ���
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 0, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0}}},  
 
{{{0, 0, 0, 0},{0, 1, 1, 0},{1, 1, 0, 0},{0, 0, 0, 0}},	//5 �� s�� ���	
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{0, 1, 1, 0},{1, 1, 0, 0}},
 {{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0}}}, 
 
{{{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 1, 0},{0, 0, 0, 0}},	//6 �� z�� ���	
 {{0, 0, 0, 0},{0, 0, 1, 0},{0, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 1, 0}},
 {{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0}}}, 
 
{{{0, 0, 1, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},	// (����� ���) 7 �� d�� ���	
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 1},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{1, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}}}, 
 
{{{0, 1, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},	// (����� ���) 8 �� b�� ���	
 {{0, 0, 0, 0},{0, 1, 1, 1},{0, 1, 1, 0},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 0}}}, 
 
{{{1, 1, 1, 0},{0, 1, 0, 0},{0, 1, 0, 0},{0, 0, 0, 0}},	// (����� ���) 9 �� T�� ���
 {{0, 0, 1, 0},{1, 1, 1, 0},{0, 0, 1, 0},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{0, 1, 0, 0},{1, 1, 1, 0},{0, 0, 0, 0}},
 {{1, 0, 0, 0},{1, 1, 1, 0},{1, 0, 0, 0},{0, 0, 0, 0}}}, 
 
{{{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}},	// (����� ���) 10 �� +�� ���
 {{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}}},
};

bool col_rand=false, blo_Limit=false, blo_rand=false, Graduation=false;
bool t=true, t_hool=true, reset=true;

int block_color[11]={0};	// 	�������� ���� 
int block_P[4][4]={0};	//�÷��̾ ����� �� ���� 
int block_TMP[4][4]={0};	//ȸ���ϰ� ������ �迭 ���� 
int i,j,level=1,Tetromino=1,ax,ay,b_remove=0,score=0;
int a[50][50]={0};	//������ ������ 
int max_block=7;
int k, timee, floor_count=0, speed=10000, Hold, delay=0;	 
int max_rand, rrand[11]={0}, Next[3]={0};
int rota=0;
char ch; 

struct struct1{	// ��ǥ ����ü 
	short x;	// x��ǥ ����  ��  
	short y;	// y��ǥ ����  ��  
}blockxy,Mep={10,20};	//����� ��ǥ ����, ���� �� �� ��ǥ(ũ��) 

struct Lanking_data{
	char name[20];	// �̸�  
	int level;	// �ܰ�� 
	int score;	// ����  
}lank[10],player; //��ũ ���� ���� ����, �÷��̾� ���� ���� ���� 

void frame(int framex, int framey, int x, int y);	// ���� Ʋ ����� 
void Game_start();	// ���� ���� ȭ��
bool Game_end();	// ����   �� ȭ��  
void Game_screen();	// ���� �÷��� ȭ�� screen: ��ũ�� 
void Game_manual();	// ���� ���� ȭ�� manual: �޴��� 
void Game_ranking();// ���� ��ŷ ȭ�� ranking: ��ŷ 
void Game_settings();	// ���� ��� ���� settings: ���� 
void block_color_settings(); // ��ϸ��� �� ���� 
void rotation();	// �� ȸ�� rotation: ȸ�� 
void Keyboard_input(); // Ű���� �Է� 
void Graduation_text();	// ���ݹ��� ����Լ� 



int main(){
	//	timee: �ð�,	floor_count: �ٴ�,	Detect: �߰��ϴ�/�����ϴ�, End: ��, score: ����, Hold: ����, delay:���� level: ���� , reset:�ʱ�ȭ 
	
	srand(time(NULL));
	
	while( 1 ){
		if(reset){
			system("cls");	// ȭ�� �ʱ�ȭ 
			
			for(i=0;i<50;i++){	// �� ��ü �ʱ�ȭ 
				for(j=0;j<50;j++){
					a[i][j]=0;
				}
			}
			
			block_color_settings();	// ��� �� �ʱ�ȭ 
			speed=10000;	// �ӵ� �ʱ�ȭ  
			floor_count=0;	// �ٴ� �ʱ�ȭ  
			for(i=0;i<11;i++) rrand[i]=0;	// ���� ��� ����Ʈ �ʱ�ȭ  
			for(i=0;i<3;i++) Next[i]=0;	// �̸����� �ʱ�ȭ  
			level=1;	//���� �ʱ�ȭ  
			b_remove=score=0;	// �� ���� ����, ���� �ʱ�ȭ  
			t=t_hool=true;			// ��� �����, Ȧ�� �ʱ�ȭ  
			rota=0;
			reset=false;	
		}
		
		do{
			Game_start(); //���� ȭ�� 
			
			if(ay==1) Game_manual();
			else if(ay==2) Game_settings();
			else if(ay==3) Game_ranking();
			else if(ay==4) return 0; 
		}while(ay!=0);
		
		if(blo_Limit) max_rand=Hold=max_block=10;	// ��� ����Ʈ�� ���� ��� ���� �ʱ�ȭ 
		else max_rand=Hold=max_block=7;
		
		system("cls");
		
		frame(frame_X,frame_Y,20,10);
		gotoxy(frame_X+10,frame_Y+4);	printf("������ �� �����մϴ�");
		sleep(1);
		
		
		for(i=0; i<max_rand; i++) rrand[i]=i;
			 
		if(blo_rand==false){
			for(i=0;i<3;i++){				
				max_rand--;																	
				for(j=rand()%max_rand, Next[i]=rrand[j]; j<max_rand; j++){
					rrand[j]=rrand[j+1];						
				}
			}	
		}
		
		
		Game_screen();
		
		for(timee=1; 1 ; timee++){	// ���� ����		
		
				
				
			if(t){	// �� �� ����							 
				int ai,add=0;	
				
				
				//���� �ű��																												
				for(i=1;i<=Mep.y;i++){
					
					for(j=1;j<=Mep.x;j++){	// ���� ���� ������ �˻�
						if(a[i][j]%10!=5) break;	// ����� �� ä�����ٸ� ���� 			
					}
						
					if(j==Mep.x+1){	// �ʿ� 10���� �׾����ٸ� 
						if(col_rand==true && add==0)	for(k=0;k<max_block;k++)	block_color[k]=17*(1+rand()%15);	// ������ �� ������ �� ���� ������ ���� �ٲ� 
						
						b_remove++;	// ���� ä�ﶧ���� 1�� ���  
						score+=100+add*10;	//100�� �⺻���� ��ø�� �ɼ��� ū ���ʽ� ���� 
						add++;
						
						if((b_remove+1)%11==0){	// ������ 10���� ���� ������ ������  																
							if(speed<=200)	speed-=50;
							else if(speed<=1000)	speed-=200;									
							else if(speed<=3000) speed-=500;								
							else if(speed<=10000) speed-=1000;
							else speed-=2000;
							
							level++;
						} 
								
						gotoxy(hold_X+1, frame_Y+6+3);	printf("%2d",level);
						gotoxy(hold_X-1, frame_Y+6+5);	printf("%6d",score);
						gotoxy(hold_X+2, frame_Y+6+7);	printf("%3d",b_remove);	 
						
						ai=i;
						// ������ ���ֱ� ���� �� ���� �ִ� ������ ����ġ��
						for(i=Mep.y;i>1;i--){	  
							for(j=1;j<=Mep.x;j++){	
								if( ai>=i ) a[i][j]=a[i-1][j];	// ���� �� ������ �� ���� �ִ� ������ ����  
										
								gotoxy(frame_X+(j-1)*2,frame_Y+i-1);								
								if(a[i][j]%10==5){ 
									textcolor(block_color[a[i][j]/10]);
									printf("��");	// �ٲ� ������ ���---��-----------------------------------------------------------
									textcolor(7);
								}
								else if(Graduation) Graduation_text();
								else printf("  ");
							}							
						}								
					}	
				}
				
				//	������� ��Ʈ���� �̳��� ��Ģ�� ������ ���� �ڵ�						
				if(max_rand==0){	
					max_rand=max_block;
					for(i=0; i<max_rand; i++) rrand[i]=i;
				}
						
				Tetromino=Next[0];	// �̸������� ù��°�� ���� 
						
				for(i=0;i<2;i++){	// �̸����⸦ ��ĭ�� �մ�ܼ� 
					Next[i]=Next[i+1];	
				}
						
				Next[2]=rand()%max_rand;  // ���ο� ������ ���� 
				
				if(blo_rand==false){	// ���� ��� ��Ȱ��ȭ�� �񱸷糪���� �ϱ� 
					max_rand--;																								
							
					for(i=Next[2], Next[2]=rrand[Next[2]]; i<max_rand; i++){
						rrand[i]=rrand[i+1];						
					}
				}	
				
						
				for(k=0;k<3;k++){	// �̸������� �ð�ȭ 									
					for(i=0;i<4;i++){	
						for(j=0;j<4;j++){
							
							if(block[Next[k]][0][i][j]){
								textcolor(block_color[Next[k]]);
															
								gotoxy(next_X+(j+1+Mep.x)*2,frame_Y+i+k*4);
								printf("��");	
										
								textcolor(7);												
							}
							else{
								gotoxy(next_X+(j+1+Mep.x)*2,frame_Y+i+k*4);
								printf("  ");
							} 
						}
					}
				}	
								
				// ��� ����																							
				blockxy.x=Mep.x/2-1;	// ����� ��ġ �ʱ�ȭ  
				blockxy.y=1;
				
				rota=0;
				
				for(i=0;i<4;i++){						
					for(j=0;j<4;j++){	// ���ο� ��������� ��� �ʱ�ȭ 
						block_P[i][j] = block[Tetromino][rota][i][j];
					}
							
					for(j=0;j<4;j++){	// ������ �ڸ��� �̹� ���� ������ �ִ��� �˻� 		
						if(block_P[i][j]){																			
							if(a[i+blockxy.y][j+blockxy.x]%10==5){								
								if(Game_end()) reset=true;
								else return 0;
							}
						}
					}
				}
				
				if(reset) break;	// ���� �ٽ� ���� 
				
				for(i=0;i<4;i++){	// ���ο� �� ����  
					for(j=0;j<4;j++){
						if(block_P[i][j]){	
							textcolor(block_color[Tetromino]);	
												
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
							printf("��");
													
							textcolor(7);																
						}
					}
				}					
		
				t=false;	//  �� ���� ���� 
				t_hool=false;	// ���Ӱ� ����� ���������� Ȧ�� ��� ��� ���� 
				floor_count=0; 
			}
			
			if(timee%(speed/20) +1 == 1 ){ 	//���� ������ �ӵ�	
			
				// ���� ��ġ ��� �����  
				for(i=0;i<4;i++){	 
					for(j=0;j<4;j++){
						if(block_P[i][j]){					
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);	
							if(Graduation) Graduation_text();
							else printf("  ");	
						}
					}
				}	
					
				// ���� ��ġ ����							
				blockxy.x+=ax;	//	���� x��ǥ ���� ( ���� & ������) 
				blockxy.y+=ay;	//	���� y��ǥ ���� ( �Ʒ� )
				ay=ax=0; 
														
				if(timee>=speed){	//�Ʒ� �ٴ��� �ִٸ� ���� 
					// ��� �Ʒ� ��ֹ� Ȯ�� 
					for(i=0;i<4;i++){	//�Ʒ����� �˻� 
						for(j=0;j<4;j++){
							if(block_P[i][j]){					
								if(a[i+blockxy.y+1][j+blockxy.x]%10==5) break;		// �Ʒ� ��ֹ��� �ִٸ� ���´�																								
							}
						}
						
						if(j!=4) break;
					}		
					 
					gotoxy(hold_X-1, frame_Y+6+5);	printf("%6d",score);
														 
					timee=1;					
							
					if(i==4){	// �Ʒ� ��ֹ��� ���ٸ�  
						floor_count=0;	// �ٴڿ� �ִ� �ð��� �ʱ�ȭ   
						blockxy.y++;	//	���� y��ǥ ��ĭ �Ʒ��� ����
					}
					else{	// �Ʒ� ��ֹ��� �ִٸ�  
						floor_count++;	// �Ʒ� ��ֹ��� �ִٸ� �ٴڿ� �ִ� �ð��� 1�߰�
					}  
				}											
				 		
				if(floor_count%2==0) textcolor(block_color[Tetromino]);	// ��¦��¦ 												
				else textcolor(block_color[Tetromino]/17);
				
				for(i=0;i<4;i++){	
					for(j=0;j<4;j++){
						if(block_P[i][j]){					
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
							printf("��");
						}
					}
				} 
				
				if(floor_count>=6){	// �ٴڿ� �ִ� �ð��� 6�̻��̶��  
					textcolor(block_color[Tetromino]);
					
					for(i=0;i<4;i++){	
						for(j=0;j<4;j++){
							if(block_P[i][j]){					
								gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
								printf("��");
								
								a[i+blockxy.y][j+blockxy.x]=Tetromino*10+5;									
							}
						}
					}   
					
					floor_count=0;	// �ʱ�ȭ
					t=true;	// ��� �����  
				} 
				
				textcolor(7);
			}
			
			// �÷��̾��� �Է½� ������
			if(kbhit()){				
				Keyboard_input();
			} 	
		} 
	}
}



void rotation(){	// �� ȸ�� 
	//���� ��� ��ġ ���� 
	for(i=0;i<4;i++){	
		for(j=0;j<4;j++){
			if(block_P[i][j]){					
				gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
				if(Graduation) Graduation_text();
				else printf("  ");													
			}
		}
	}
	
	if(rota==3) rota=0;
	else rota++;
	
	int max,may;
	
	for(max=0;max<=2;max++){
		for(i=0;i<4;i++){												
			for(j=0;j<4;j++){
				if(block[Tetromino][rota][i][j]){																			
					if(a[i+blockxy.y][j+blockxy.x+max]%10==5) break;	//�÷��̾� ��ϰ� ��ġ�� �ٸ� ����� �ִ��� �˻�  													
				}
			}
			
			if(j!=4) break;
		}
		
		if(i==4) break; //���� ��ֹ��� ���ٸ� ����  
	}
	
	for(may=0;may<=2;may++){
		for(i=0;i<4;i++){		// ���� �÷��̾� ��ϰ� ��ġ�� �ٸ� ����� �ִ��� �˻�	
			for(j=0;j<4;j++){
				if(block[Tetromino][rota][i][j]){																			
					if(a[i+blockxy.y+may][j+blockxy.x]%10==5) break;	  													
				}
			}
			
			if(j!=4) break;
		}
		
		if(i==4) break; //���� ��ֹ��� ���ٸ� ����  
		
		for(i=0;i<4;i++){		// ������ �÷��̾� ��ϰ� ��ġ�� �ٸ� ����� �ִ��� �˻� 	
			for(j=0;j<4;j++){
				if(block[Tetromino][rota][i][j]){																			
					if(a[i+blockxy.y-may][j+blockxy.x]%10==5) break; 													
				}
			}
			
			if(j!=4) break;
		}
		
		if(i==4){
			may=-may;
			break; //���� ��ֹ��� ���ٸ� ����
		}  
	}	
	
	if(may==3) may=0;	// may �ݺ����� ������ ���Ҵٸ� ��ֹ��� ��� �����Ƿ� �Ⱥ��� 
	if(max==3) max=0;	// max �ݺ����� ������ ���Ҵٸ� ��ֹ��� ��� �����Ƿ� �Ⱥ��� 
	
	for(i=0;i<4;i++){		// ȸ���� �ڸ��� �̹� ���� ������ �ִ��� �˻� 											
		for(j=0;j<4;j++){
			if(block[Tetromino][rota][i][j]){																			
				if(a[i+blockxy.y+may][j+blockxy.x+max]%10==5) break;	//�÷��̾� ��ϰ� ��ġ�� �ٸ� ����� �ִ��� �˻�  													
			}
		}
		
		if(j!=4) break;
	}
	
	/* ȸ���� Ȯ�� 
	gotoxy(100,20+2);
	printf("ȸ���� �ٲ� x��ǥ:%d, y��ǥ:%d  ",max,may);
	*/
	if(i==4) {
		blockxy.x+=max;
		blockxy.y+=may;	
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				block_P[i][j]=block[Tetromino][rota][i][j];
			}
		}
	}
	else{
		if(rota==0) rota=3;
		else rota--;
	}		
		
	ax=ay=0;
}

void Game_start(){	//���� ȭ�� 	
	ch=ay=0;
	
	system("cls");
	
	frame(frame_X, frame_Y, 20, 20);
	
	gotoxy(frame_X+44,frame_Y+7);	printf("����Ű ��: ���� �̵�");
	gotoxy(frame_X+44,frame_Y+8);	printf("����Ű ��: �Ʒ��� �̵�");
	gotoxy(frame_X+44,frame_Y+10);	printf("�����̽��� : Ŭ��");

	gotoxy(frame_X+10-2,frame_Y+3);	printf("���ؽ�Ʈ ��Ʈ���� ���ӡ�");
	
	gotoxy(frame_X+10,frame_Y+7);	printf("1. ����");
	gotoxy(frame_X+10,frame_Y+9);	printf("2. ���");
	gotoxy(frame_X+10,frame_Y+11);	printf("3. ���");
	gotoxy(frame_X+10,frame_Y+13);	printf("4. ����");
	gotoxy(frame_X+10,frame_Y+15);	printf("5.������");
	
	
	
	while(ch!=32) {
		gotoxy(frame_X+18,frame_Y+7+ay*2);	printf("<--");
		
		ch=getch();
		
		gotoxy(frame_X+18,frame_Y+7+ay*2);	printf("   ");
		
		switch(ch){
			case 72:
				if(ay>0) ay--;
				break;
			case 80:
				if(ay<4) ay++;
				break;
		} 
	}
}

void frame(int framex, int framey, int x, int y){	// ���� Ʋ ����� 

	for(i=-1;i<y+1; i++){
		for(j=-1;j<x+1;j++){
			if(i==-1 || j==-1 || i==y || j==x){					
				gotoxy(framex+j*2,framey+i);
				printf("��");				
			}
		}
	} 
	
}

void Game_screen(){	// ���� ȭ�� 
	system("cls");
	
	gotoxy(hold_X+3,frame_Y-2);	//Ȧ�� ĭ ���� Holb��� 
	printf("����");
	
	gotoxy(next_X+(Mep.x)*2+1, frame_Y-2);	//�ؽ�Ʈ ĭ �� ���� Next��� 
	printf("�̸�����");
	
	textcolor(8);	//ĭ���� �� ���� 
	
	frame(hold_X, frame_Y,5,5);	//Ȧ�� ĭ ��� 	
	frame(hold_X-4, frame_Y+6+2,7,7);	// ����, ����, �׳��� �� �ڸ� 
	
	for(i=0;i<Mep.y+2; i++){
		for(j=0;j<Mep.x+2;j++){
			if(i==0 || j==0 || i==Mep.y+1 || j==Mep.x+1){					
				gotoxy(frame_X+(j-1)*2,frame_Y+i-1);
				printf("��");
				
				a[i][j]=5;				
			}
			else if(Graduation){
				gotoxy(frame_X+(j-1)*2,frame_Y+i-1);
				Graduation_text();
				textcolor(8);
			}
		}
	} 	 		
	
	frame(next_X+(Mep.x)*2, frame_Y, 5, 12);	// �̸����� ĭ ��� 
	
	textcolor(7);
	
	gotoxy(hold_X+1, frame_Y+6+3);	printf("%2d",level);	//  ����  
	gotoxy(hold_X+4, frame_Y+6+3);	printf("�ܰ�");
	
	gotoxy(hold_X-1, frame_Y+6+5);	printf("%6d",score);	//  ����
	gotoxy(hold_X+6, frame_Y+6+5);	printf("��");	 
	
	gotoxy(hold_X+2, frame_Y+6+7);	printf("%3d",b_remove);	//  �׳� 
	gotoxy(hold_X+6, frame_Y+6+7);	printf("��");
}
 
bool Game_end(){
	system("cls");
	
	frame(frame_X, frame_Y, 30, 20);

	gotoxy(frame_X+20,frame_Y+6);	printf("END");
	
	gotoxy(frame_X+14,frame_Y+7);	printf("����� ���� ������ %d�� �Դϴ�",score);
	gotoxy(frame_X+14,frame_Y+8);	printf("�����ϼ̽��ϴ�");
	
	Sleep(100);
	
	FILE* pt=fopen("TetrisLank.txt","r+");
 	
	
	
	
	if(pt=='\0'){	//������ �������� ���  
		gotoxy(frame_X+8,frame_Y+12);	printf("���� ��ũ������ ����, ������ ������ �� �����ϴ�");
	}
	else if(blo_Limit || col_rand || blo_rand || Mep.x!=10 || Mep.y!=20){
		gotoxy(frame_X+8,frame_Y+12);	printf("���� ��� ������, ������ ������ �� �����ϴ�");
		gotoxy(frame_X+16,frame_Y+14);	printf("--+ ����� ���+--"); 
		gotoxy(frame_X+2,frame_Y+15);
		if(Mep.x!=10 || Mep.y!=20) printf(" ������ Ȯ��,");
		if(blo_Limit) printf(" ��� Ȯ��,"); 
		if(col_rand) printf(" ���� ��,"); 
		if(blo_rand) printf(" ���� ���,");
		
		printf("\b "); 
	}	
	else{	
		gotoxy(frame_X+8,frame_Y+10);	printf("��ũ�� ������ �����Ͻðڽ��ϱ�(y/n)");
		do{	ch=getch();	}while(ch!='y' && ch!='n');
		
		if(ch=='y'){
			gotoxy(frame_X+8,frame_Y+10);	printf("��ũ�� ���ŵ� �г����� �Է����ּ���");
			gotoxy(frame_X+8,frame_Y+11);	printf("�г���:"); 
			scanf("%s",player.name);
			
			player.level=level;
			player.score=score;
			
			for(i=0; i < 10; i++){	
				fscanf(pt,"%s %d %d",&lank[i].name, &lank[i].level, &lank[i].score);
			}
			
			for(i=9;lank[i].score<player.score && i>=0;i--){
				if(i!=9) lank[i+1]=lank[i];
				lank[i]=player;
			}
			
			fseek(pt,0,SEEK_SET);
			for(i=0;i<10;i++){
				fprintf(pt,"%s %d %d\n",lank[i].name, lank[i].level, lank[i].score);
			}
			
			gotoxy(frame_X+8,frame_Y+14);	printf("������ �Ϸ�Ǿ����ϴ�."); 
		}
	}
	
	fclose(pt);
	
	gotoxy(frame_X+8,frame_Y+17);	printf("�κ�� �̵��Ͻðڽ��ϱ�? ( y:��, n:������)");
	
	do{
		ch=getch();
	}while(ch!='y' && ch!='n');
	
	if(ch=='y') return true;
	else return false;
	
} 

void Game_manual(){
	system("cls");
	
	frame(hold_X, frame_Y, 40, 30);

	gotoxy(hold_X+10+4,frame_Y+1);	printf("��� ����");
	
	gotoxy(hold_X+10,frame_Y+6);	printf("����Ű");
	
	gotoxy(hold_X+8,frame_Y+8);		printf("aŰ: �Ͻ�����, �Ͻ����� �� �ƹ� Ű �Է½� Ǯ��"); 
	gotoxy(hold_X+8,frame_Y+9);		printf("cŰ: Ȧ��(��� ����)"); 
	gotoxy(hold_X+8,frame_Y+11);	printf("�����̽���: �ٷ� ������"); 
	gotoxy(hold_X+8,frame_Y+13);	printf("����Ű(  ��  ): ��� ȸ��"); 
	gotoxy(hold_X+8,frame_Y+14);	printf("����Ű(����): ��� ����/ �Ʒ�/ ������ ��ĭ �̵�"); 
	
	gotoxy(hold_X+10,frame_Y+16);	printf("��Ģ");
	
	gotoxy(hold_X+6,frame_Y+18);	printf("1. ����� ����� ������ �������� �׾Ҵٸ� ���� ��"); 
	gotoxy(hold_X+6,frame_Y+20);	printf("2. ����Ű(��)�� �����̽��ٷ� ����� ����Ʈ���ٸ� �̵��Ÿ���ŭ +�߰� ����"); 
	gotoxy(hold_X+6,frame_Y+22);	printf("3. �ٸ��� ���Ž� ���� ȹ��, �Ѳ����� ���� �� ���Ž� +�߰� ����"); 
	gotoxy(hold_X+6,frame_Y+24);	printf("4. ������ ���� ������ �ű� "); 
	
	gotoxy(hold_X+40,frame_Y+28);	printf("�����̽��� = �ڷΰ���..");
	
	do{
		ch=getch();	
	}while(ch!=32);
}

void Game_settings(){
	Graduation=blo_Limit=col_rand=blo_rand=false;
	system("cls");
	
	frame(frame_X, frame_Y, 20, 20);

	gotoxy(frame_X+6,frame_Y+3);	printf("���� ��� (�ߺ� ���� ����)");
	gotoxy(frame_X+0,frame_Y+4);	printf("*���� ǥ�� �� ��� ����� ��ũ ���� �Ұ�");
	
	gotoxy(frame_X+10,frame_Y+7);	printf("������ Ȯ��");	// Mep.x,Mep.y
	gotoxy(frame_X+10,frame_Y+9);	printf("��� Ȯ��");	// blo_Limit
	gotoxy(frame_X+10,frame_Y+11);	printf("������ ��");	// col_rand
	gotoxy(frame_X+10,frame_Y+13);	printf("������ ���");	// blo_rand
	gotoxy(frame_X+10,frame_Y+15);	printf("���� ǥ��");	// Graduation
	gotoxy(frame_X+10,frame_Y+17);	printf("���� �Ϸ�");
	
	
	int set[5]={0}; 
	while(1) {
		gotoxy(frame_X+26,frame_Y+7+ay*2);	printf("<--");
			
		gotoxy(frame_X+44,frame_Y+10);			printf("                                          ");
		gotoxy(frame_X+44,frame_Y+11);			printf("                                          ");
		switch(ay){
			
			case 0:
				gotoxy(frame_X+44,frame_Y+10);	printf("�������� �о����ϴ�");
				gotoxy(frame_X+44,frame_Y+11);	printf("���� ��� �� �ֽ��ϴ�");
				break;
			case 1:
				gotoxy(frame_X+44,frame_Y+10);	printf("�ű��� ����� ��Ÿ���ϴ�");
				gotoxy(frame_X+44,frame_Y+11);	printf("������ ��������ϴ�");
				break;
			case 2:
				gotoxy(frame_X+44,frame_Y+10);	printf("���� ���� ������ ��� ���� �޶����ϴ�");
				gotoxy(frame_X+44,frame_Y+11);	printf("�������� ���մϴ�");
				break;
			case 3:
				gotoxy(frame_X+44,frame_Y+10);	printf("��� �� ���� �������� ���ɴϴ�");
				gotoxy(frame_X+44,frame_Y+11);	printf("������ ��������ϴ�");
				break;
			case 4:
				gotoxy(frame_X+44,frame_Y+10);	printf("�ʺ��ڸ� ���� �����Դϴ�");
				gotoxy(frame_X+44,frame_Y+11);	printf("������ ��Ȱ�����ϴ�");
				break;
		} 
		ch=getch();
		
		if(ch==32){	// �����̽��ٸ� ������ 
			if(ay==5) break;	// �����Ϸ��� �� 
			else{
				if(set[ay]==0){	 
					gotoxy(frame_X+6,frame_Y+7+ay*2);	printf("��");
					set[ay]=1;
				} 
				else{
					gotoxy(frame_X+6,frame_Y+7+ay*2);	printf("  ");
					set[ay]=0;
				}
			}
		}
		
		gotoxy(frame_X+26,frame_Y+7+ay*2);	printf("   ");
		
		switch(ch){
			case 72:
				if(ay>0) ay--;
				break;
			case 80:
				if(ay<5) ay++;
				break;
		} 
	}
	
	if(set[0]){
		Mep.x+=10;
		Mep.y+=10;
	}
	if(set[1]) blo_Limit=true;
	if(set[2]) col_rand=true;
	if(set[3]) blo_rand=true;
	if(set[4]) Graduation=true; 
}

void block_color_settings(){
	block_color[0]=17*11;
	block_color[1]=17*9;
	block_color[2]=17*3;
	block_color[3]=17*6;
	block_color[4]=17*10;
	block_color[5]=17*13;
	block_color[6]=17*12;
	block_color[7]=17*15;
	block_color[8]=17*1;
	block_color[9]=17*4;
	block_color[10]=17*14;
}

void Game_ranking(){
	FILE* fp=fopen("TetrisLank.txt","r");
	
	system("cls");
	
	frame(frame_X, frame_Y, 20, 30);
	
	if(fp=='\0'){
		gotoxy(frame_X+10,frame_Y+5);	printf("���� ��ũ������ ����");
		gotoxy(frame_X+8,frame_Y+6);	printf("������ Ȯ���� �� �����ϴ�");
	} 
	else{
		for(i=0; i < 10; i++){	
			fscanf(fp,"%s %d %d",&lank[i].name, &lank[i].level, &lank[i].score);
		}
		
		gotoxy(frame_X+4,frame_Y+3);	printf("����	�̸�	�ܰ�	����");
		for(i=0;i<10 && lank[i].level!=0;i++){
			gotoxy(frame_X+4,frame_Y+i*2+5);	printf("%2d��- %10s  %2d %8d",i+1,lank[i].name, lank[i].level, lank[i].score);
		}
	} 
	
	gotoxy(frame_X+15,frame_Y+28);	printf("�����̽��� = �ڷΰ���..");
	
	do{
		ch=getch();	
	}while(ch!=32);
}

void Keyboard_input(){
	switch(ch=getch()){
		case 72:	// ����Ű: �� (ȸ�� ���) 
						
			rotation();	// �� ȸ�� �Լ� 
						
			break;
		case 80:	// ����Ű: �Ʒ� (���� ���� ���) 
			for(i=0;i<4;i++){	
				for(j=0;j<4;j++){
					if(block_P[i][j]){																		
						if(a[i+blockxy.y+1][j+blockxy.x]%10==5 ) break;																												
					}
				}
				if(j!=4) break;
			}	
						
			if(i==4){ 
				score++;	//���� ���� 
				ay=1;	// �Ʒ��� ���,�ٴ��� ������ ��ĭ �� ������ �̵� 
			}
						
			break;
		case 75:	// ����Ű: ���� (��� ���� �̵�)		
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(block_P[i][j]){
						if( a[i+blockxy.y][j+blockxy.x-1]%10==5) break;																					
					} 							
				}
							
				if(j!=4) break;	//���ʿ� ��ֹ��� ������ �ٷ� ���� 						
			}		
																			 						
			if(i==4) ax=-1;	// ���� ���⿡ ����̳� ���� ������ �������� ��ĭ �̵� (�ٷ� ������� ������ ����)	
						
			break;
		case 77:	// ����Ű: ������ (��� ������ �̵�) 
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(block_P[i][j]){
						if( a[i+blockxy.y][j+blockxy.x+1]%10==5) break;																				
					} 							
				}
							
				if(j!=4) break;	//�����ʿ� ��ֹ��� ������ �ٷ� ���� 
			}	
							
			if(j==4) ax=1;	// ������ ���⿡ ���,���� ������ ���������� ��ĭ �̵� 	(�ٷ� ������� ������ ����)	
								
			break;
		case 32:	// �����̽��� (�ٷ� ����) 
						
			///��� ����� 
			for(i=0;i<4;i++){	
				for(j=0;j<4;j++){
					if(block_P[i][j]){					
						gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
						if(Graduation) Graduation_text();
						else printf("  ");		
					}
				}
			}
						
			while(i==4){	// �Ʒ��� ���� �ִٸ� �ݺ��� ���� 
				for(i=0;i<4;i++){	
					for(j=0;j<4;j++){
						if(block_P[i][j]){																		
							if(a[i+blockxy.y+1][j+blockxy.x]%10==5) break;																														
						}
					}
								
					if(j!=4) break;	// �Ʒ��ʿ� ��ֹ��� ������ �ٷ� ����
				}	
							
				if(i==4){ 
					score+=4;	// ���� �ι� ���� 
					blockxy.y++;	// �Ʒ��� �ƹ��͵� ������ ��� ��ġ �Ʒ��� ����	(�ٷ� ������� ������ ����)		
				}
			}
					
			floor_count=7;	// �ٷ� ����� ���� 
						 
			break;	
		case 99:	//cŰ (Ȧ�忡 ����� ���� / ������)				
			if(t_hool == false){	// Ȧ���� ����� �̹� ����߳� �˻� 
				int temp;	// Ȧ��ȿ� �ִ� �Ͱ� ���� ������ �ִ� �����͸� ��ȯ��Ű�� ����. 
							
				///��� ����� 
				for(i=0;i<4;i++){	
					for(j=0;j<4;j++){
						if(block_P[i][j]){					
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
							if(Graduation) Graduation_text();
							else printf("  ");		
						}
					}
				}
																			
				if(Hold==7){
					t=true;
				}
				else{
					blockxy.x=4;	// ��� ��ġ ó���������� �̵� 
					blockxy.y=1;
					
					rota=0;
					
					for(i=0;i<4;i++){							
						for(j=0;j<4;j++){
							block_P[i][j]=block[Hold][rota][i][j];	// hold�� �ִ� �̳��� �����͸� ���� 
						}																
					}
				}
											
				temp=Hold;	//Ȧ���� ���� �� ���� ����  
				Hold=Tetromino;	//Ȧ�忡 ���� ���� ���� 
				Tetromino=temp;	//���� �����ص� Ȧ���� ���� ���� ������ ���� 
							
				for(i=0;i<4;i++){	// holdĭ�� �ð������� ������ 	
					for(j=0;j<4;j++){																
						if(block[Hold][0][i][j]){					
							textcolor(block_color[Hold]);
										
							gotoxy(hold_X+(j+1)*2,frame_Y+i);
							printf("��");
										
							textcolor(7);
						}
						else{
							gotoxy(hold_X+(j+1)*2,frame_Y+i);
							printf("  ");
						}
					}
				}
							
				t_hool=true;	// Ȧ�� ����� ����ߴٰ� �˸�		
			}
																 
			break;	
		case 97:	//aŰ(�Ͻ�����)			
						
			do{
				ch=getch();
			}while(ch!='a');
			break;		
	}
}

void Graduation_text(){
	textcolor(16*8);
	printf("��");
	textcolor(7);
}

// 1000�� �ѱ�! 
