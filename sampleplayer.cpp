#include<stdio.h>
#include<iostream>
#include"parameter.h"

class sampleplayer
{
    private:
        char u,uu,uul,uur,d,dd,ddl,ddr,l,ll,r,rr,ul,ur,dl,dr,playerid,cob[100][100];
    private:
        int hdposy,hdposx,accdir,lf ;
             
        
     public:   
        sampleplayer(char id)
        {
            playerid=id;
        } 
   int chk_fen()
        {
            switch(accdir)
            {
                    case UP:
                        if((u==FENCE)&&(l==FENCE))
                        return RIGHT;
                        else if((u==FENCE)&&(r==FENCE))
                        return LEFT;
                    break;
                    case DOWN:
                        if((d==FENCE)&&(l==FENCE))
                        return RIGHT;
                        else if((d==FENCE)&&(r==FENCE))
                        return LEFT;
                    break;
                    case LEFT:
                        if((l==FENCE)&&(d==FENCE))
                        return UP;
                        else if((l==FENCE)&&(u==FENCE))
                        return DOWN;
                    break;
                    default:
                        if((r==FENCE)&&(d==FENCE))
                        return UP;
                        else if((r==FENCE)&&(u==FENCE))
                        return DOWN;
                    break;
            }            
            return -400;
        }
        
        
        char getdata(int a,int b)
        {
             return cob[a][b];
        }
        
        
        int chk_fen2()
        {
            printf("acc : %d\n",accdir); //Printing for reference
            switch(accdir)
            {
                    case UP:
                        printf("case up\n"); //Printing for reference
                        if((u==FENCE)|| (u>90))
                        {
                        if((r==BLANK))
                        return RIGHT;
                        else if(l==BLANK)
                        return LEFT;
                        }
                        else if((u==BLANK) || ((u==POWER_UP)&&(uu==BLANK))) 
                        return UP;
                        else
						{
						if(r>90)
                        return LEFT;
						else
						return RIGHT;
						}
                    break;
                    case DOWN:
                        printf("case down\n"); //Printing for reference
                        if((d==FENCE)|| (d>90))
                        {
                        if((r==BLANK))
                        return RIGHT;
                        else if(l==BLANK)
                        return LEFT;
                        }
                        else if((d==BLANK)|| ((d==POWER_UP)&&(dd==BLANK))) 
                        return DOWN;
                        else
						{
						if(r>90)
                        return LEFT;
						else
						return RIGHT;
						}
                    break;
                    case LEFT:
                        printf("case left\n"); //Printing for reference
                         if((l==FENCE)|| (l>90))
                        {
                        if((u==BLANK))
                        return UP;
						else if((d==BLANK))
						return DOWN;
                        }
                        else if((l==BLANK)|| ((l==POWER_UP)&&(ll==BLANK)))
                        return LEFT;
                        else
						{
						if(u>90)
                        return DOWN;
						else
						return UP;
						}
                    break;
                    case RIGHT:
                        printf("case right\n"); //Printing for reference
                        if((r==FENCE) || (r>90))
                        {
                        if((u==BLANK))
                        return UP;
                        }
                        else if((r==BLANK)|| ((r==POWER_UP)&&(rr==BLANK)))
                        return RIGHT;
                        else
						{
						if(u>90)
                        return DOWN;
						else
						return LEFT;
						}
                    break;
                    default:
                        printf("no case\n"); //Printing for reference
                        return -400;
                    break;
            }            
            return -400;
        }
        int rand_dir()
        {
            int s=rand()%4;
            switch(s)
            {
                case 0: return UP;
                case 1: return DOWN;
                case 2: return LEFT;
                case 3: return RIGHT;
            }    
        }
        int headon(int mve)
        {
            switch(mve)
            {
                       case UP:
                               if( (uu>=char(65)) && (uu<=char(90)) && (uu!=POWER_UP) && (uu!=FENCE) )
                               {
                                   if((l==BLANK)||(l==POWER_UP))
                                   return LEFT;
                                   else if((r==BLANK)||(r==POWER_UP))
                                   return RIGHT;
                               }
                               else
                               return mve;
                       break;
                       case DOWN:
                               if( (dd>=char(65)) && (dd<=char(90)) && (dd!=POWER_UP) && (dd!=FENCE) )
                               {
                                   if((l==BLANK)||(l==POWER_UP))
                                   return LEFT;
                                   else if((r==BLANK)||(r==POWER_UP))
                                   return RIGHT;
                               }
                               else
                               return mve;
                       break;
                       case LEFT:
                               if( (ll>=char(65)) && (ll<=char(90)) && (ll!=POWER_UP) && (ll!=FENCE) ) 
                               {
                                   if((u==BLANK)||(u==POWER_UP))
                                   return UP;
                                   else if((d==BLANK)||(d==POWER_UP))
                                   return DOWN;
                               }
                               else
                               return mve;
                       break;
                       case RIGHT:
                               if( (rr>=char(65)) && (rr<=char(90)) && (rr!=POWER_UP) && (rr!=FENCE) )
                               {
                                   if((u==BLANK)||(u==POWER_UP))
                                   return UP;
                                   else if((d==BLANK)||(d==POWER_UP))
                                   return DOWN;
                               }
                               else
                               return mve;
                       break;
                       default:
                               return mve;
                               break;
            }            
            return mve;
        }
        
        int chk(int x)//to chk for tail and heads
        {
            if( (x != BLANK) || (x != POWER_UP) )
            return 1;
            else
            return 0;
            
        }
        
        int line_chk()
        {
            switch(accdir)
            {
                 case UP:
                         printf("case up line_chk\n"); //Printing for reference
                         if( (l==FENCE) &&  (chk(r)) && ((chk(u)) || u==FENCE) )
                         return RIGHT;
                         else if( (r==FENCE) &&  (chk(l)) && (chk(u)) )
                         return LEFT;
                         else
                         return -400;
                 break;
                 case DOWN:
                         printf("case down line_chk\n"); //Printing for reference
                         if( (l==FENCE) &&  (chk(r)) && ((chk(d)) || d==FENCE) )
                         return RIGHT;
                         else if( (r==FENCE) &&  (chk(l)) && (chk(d)) )
                         return LEFT;
                         else
                         return -400;
                 break;
                 case LEFT:
                         printf("case left line_chk\n"); //Printing for reference
                         if( (d==FENCE) &&  ((chk(l)) || l==FENCE) && (chk(u)) )
                         return UP;
                         else if( (u==FENCE) &&  ((chk(l)) || d==FENCE) && (chk(d)) )
                         return DOWN;
                         else
                         return -400;
                 break;
                 case RIGHT:
                         printf("case right line_chk\n"); //Printing for reference
                         if( (d==FENCE) &&  ((chk(r)) || r==FENCE) && (chk(u)) )
                         return UP;
                         else if( (u==FENCE) &&  ((chk(r)) || r==FENCE) && (chk(d)) )
                         return DOWN;
                         else
                         return -400;
                 break;
                 default:
                         printf("No case line_chk\n"); //Printing for reference
                         return -400;
                 break;
            }
        }
        
           
        
        int getmove(char board[BOARD_LENGHT][BOARD_BREADTH],int head_positiony,int head_positionx ,int acc_direction,int life_left)// Funtion which will return the move by the player
        {
            int mve=-400; //storing -400 as an invalid move (I am refering that if mve=-400 we not yet decided our mve)
             //Making arguments global by storing them in private members
             hdposy=head_positiony;
             hdposx=head_positionx;
             accdir=acc_direction;
             lf=life_left;
             int j,k;
             for( j=0;j<BOARD_LENGHT;j++)
             {
                  for( k=0;k<BOARD_BREADTH;k++)
                  cob[j][k]=board[j][k]; //storing all elements of board in 'private' cob
             }  
             //u,d,l,r,ul,ur,dl,dr are up,down,left,right,upperleft,upperright,downleft,downright 
             //elements in board w.r.t. curr. position of our player's head
             u=getdata(hdposy+1,hdposx);
             d=getdata(hdposy-1,hdposx);
             l=getdata(hdposy,hdposx-1);
             r=getdata(hdposy,hdposx+1);
             ul=getdata(hdposy+1,hdposx-1);
             ur=getdata(hdposy+1,hdposx+1);
             dl=getdata(hdposy-1,hdposx-1);
             dr=getdata(hdposy-1,hdposx+1);
             //uu,dd,ll,rr are next to next elements of up,down,left,right in the board
             if(u==FENCE)
             uu='Z'; // Assuming a random head of player 'Z' for coding reasons
             else
             uu=getdata(hdposy+2,hdposx);
             
             if(d==FENCE)
             dd='Z'; // Assuming a random head of player 'Z' for coding reasons
             else
             dd=getdata(hdposy-2,hdposx);
             
             if(l==FENCE)
             ll='Z'; // Assuming a random head of player 'Z' for coding reasons
             else
             ll=getdata(hdposy,hdposx-2);
             
             if(r==FENCE)
             rr='Z'; // Assuming a random head of player 'Z' for coding reasons
             else
             rr=getdata(hdposy,hdposx+2);
             printf("u : %c \n d : %c \n l : %c \n r : %c \n present : %c \n",u,d,l,r,getdata(hdposy,hdposx)); //Printing for reference
             mve=chk_fen(); // if player reaches any corners of board then 2 dir. 
                            // are fenced one opp dir. is not possible to make and hence only one dir. is possible
                            // chk_fen find that single dir
             printf("mve value frm chk_fen is %d",mve); //Printing for reference
             if(mve!=-400)
             return mve; 
             mve=-400;
             mve=line_chk();
             if(mve!=-400)
             return mve;
             mve=-400; 
             mve=chk_fen2();
             if(mve!=-400)
             {
                 mve=headon(mve);   
                 return mve;
             }
             
             mve=rand_dir();
             return mve;
        }    
};    
