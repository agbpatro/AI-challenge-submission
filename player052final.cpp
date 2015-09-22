#include<stdio.h>
#include<iostream>
#include"parameter.h"

class player052
{
    private:
        char u,uu,uur,uul,d,dd,ddr,ddl,l,ll,llu,lld,r,rr,rru,rrd,ul,ur,dl,dr,playerid,cob[100][100];
    private:
        int hdposy,hdposx,accdir,lf ;
             
        
     public:   
        player052(char id)
        {
            playerid=id;
        }
        int chk(char x)//to chk for tail and heads
        {
            if( (x != BLANK) || (x != POWER_UP) )
            return 1;
            else
            return 0;
            
        }
        
        int chk1(char x)//to chk BLANKS
        {
            if( x == BLANK )
            return 1;
            else
            return 0;
            
        }
        
        int chk2(char x)//to chk tails
        {
            if( x >= 'a' && x<= 'z' )
            return 1;
            else
            return 0;
            
        } 
        
        int chk3(char x)//to chk HEADS
        {
            if( x >= 'A' && x<= 'Z' && x!=POWER_UP)
            return 0;
            else
            return 1;
            
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
            switch(accdir)
            {
                    case UP:
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
						return UP;
						}
                    break;
                    default:
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
                               if( (uu>=char(65)) && (uu<=char(90)) && (uu!=POWER_UP) && (uu!=FENCE) && (u!=FENCE))
                               {
                                   if(((l==BLANK)||(l==POWER_UP)) && chk3(dl))
                                   return LEFT;
                                   else if((r==BLANK)||(r==POWER_UP))
                                   return RIGHT;
                               }
                               else
                               return mve;
                       break;
                       case DOWN:
                               if( (dd>=char(65)) && (dd<=char(90)) && (dd!=POWER_UP) && (dd!=FENCE) && (d!=FENCE) )
                               {
                                   if(((l==BLANK)||(l==POWER_UP)) && chk3(ul))
                                   return LEFT;
                                   else if((r==BLANK)||(r==POWER_UP))
                                   return RIGHT;
                               }
                               else
                               return mve;
                       break;
                       case LEFT:
                               if( (ll>=char(65)) && (ll<=char(90)) && (ll!=POWER_UP) && (ll!=FENCE) && (l!=FENCE) ) 
                               {
                                   if(((u==BLANK)||(u==POWER_UP)) && chk3(ul))
                                   return UP;
                                   else if((d==BLANK)||(d==POWER_UP))
                                   return DOWN;
                               }
                               else
                               return mve;
                       break;
                       case RIGHT:
                               if( (rr>=char(65)) && (rr<=char(90)) && (rr!=POWER_UP) && (rr!=FENCE) && (r!=FENCE) )
                               {
                                   if(((u==BLANK)||(u==POWER_UP)) && chk3(ur))
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
       int cont()
       {
           switch(accdir)
           {
                 case UP:
                         if(u==BLANK || (u==POWER_UP && uu==BLANK))
                         return UP;
                 break;
                 case DOWN:
                         if(d==BLANK || (d==POWER_UP && dd==BLANK))
                         return DOWN;
                 break;
                 case LEFT:
                         if(l==BLANK || (l==POWER_UP && ll==BLANK))
                         return LEFT;
                 break;
                 case RIGHT:
                         if(r==BLANK || (r==POWER_UP && rr==BLANK))
                         return RIGHT;
                 break;
                 default:
                         return -400;
                 break;
            }
            return -400;
       
       }      
        int line_chk()
        {
            switch(accdir)
            {
                 case UP:
                         if( l==FENCE &&  chk(r) && chk(u))
                         return RIGHT;
                         else if( r==FENCE &&  chk(l) && chk(u))
                         return LEFT;
                         else
                         return -400;
                 break;
                 case DOWN:
                         if( l==FENCE &&  chk(r) && chk(d) )
                         return RIGHT;
                         else if( r==FENCE &&  chk(l) && chk(d) )
                         return LEFT;
                         else
                         return -400;
                 break;
                 case LEFT:
                         if( d==FENCE &&  chk(l) && chk(u) )
                         return UP;
                         else if( u==FENCE &&  chk(l) && chk(d) )
                         return DOWN;
                         else
                         return -400;
                 break;
                 case RIGHT:
                         if( d==FENCE &&  chk(r) && chk(u) )
                         return UP;
                         else if( u==FENCE &&  chk(r) && chk(d) )
                         return DOWN;
                         else
                         return -400;
                 break;
                 default:
                         return -400;
                 break;
            }
        }
        
        int rand_dir1(int x)
        {
            int y=rand()%3,z;
            if(x==1)
            {
                    switch(y)
                    {
                             case 0: z=UP;
                                     break;
                             case 1: z=LEFT;
                                     break;
                             default: z=RIGHT;
                                     break;
                    }
            }
            else if(x==2)
            {
                    switch(y)
                    {
                             case 0: z=DOWN;
                                     break;
                             case 1: z=LEFT;
                                     break;
                             default: z=RIGHT;
                                     break;
                    }
            }
            else if(x==3)
            {
                    switch(y)
                    {
                             case 0: z=DOWN;
                                     break;
                             case 1: z=UP;
                                     break;
                             default: z=RIGHT;
                                     break;
                    }
            }
            else 
            {
                    switch(y)
                    {
                             case 0: z=DOWN;
                                     break;
                             case 1: z=LEFT;
                                     break;
                             default: z=UP;
                                     break;
                    }
            }
            return z;
        }
        
        int any_dir()
        {
            switch(accdir)
            {
                          case UP:
                                  if( chk1(u) && chk1(l) && chk1(r) && chk1(ul) && chk1(ur) && chk1(uu) && chk1(uur) && chk1(uul))
                                  return rand_dir1(1);
                                  break;
                          case DOWN:
                                  if( chk1(d) && chk1(l) && chk1(r) && chk1(dl) && chk1(dr) && chk1(dd) && chk1(ddr) && chk1(ddl))
                                  return rand_dir1(2);
                                  break;
                          case LEFT:
                                  if( chk1(u) && chk1(d) && chk1(l) && chk1(ul) && chk1(dl) && chk1(ll) && chk1(llu) && chk1(lld))
                                  return rand_dir1(3);
                                  break;
                          default:
                                  if( chk1(u) && chk1(r) && chk1(d) && chk1(ur) && chk1(dr) && chk1(rr) && chk1(rru) && chk1(rrd))
                                  return rand_dir1(4);
                                  break;
            }
            return -400;
        }
        
        int chk_fen3(int mve)
        {
            switch(mve)
            {
                          case UP:
                                  if( u==FENCE )
                                  {
                                  if(l==FENCE || r==FENCE)
                                  line_chk();
                                  else if(l==BLANK)
                                  return LEFT;
                                  else 
                                  return RIGHT;
                                  }
                                  break;
                          case DOWN:
                                  if( d==FENCE )
                                  {
                                  if(l==FENCE || r==FENCE)
                                  line_chk();
                                  else if(l==BLANK)
                                  return LEFT;
                                  else 
                                  return RIGHT;
                                  }
                                  break;
                          case LEFT:
                                  if( l==FENCE )
                                  {
                                  if(u==FENCE || d==FENCE)
                                  line_chk();
                                  else if(u==BLANK)
                                  return UP;
                                  else 
                                  return DOWN;
                                  }
                                  break;
                          case RIGHT:
                                  if( d==FENCE )
                                  {
                                  if(u==FENCE || u==FENCE)
                                  line_chk();
                                  else if(u==BLANK)
                                  return UP;
                                  else 
                                  return DOWN;
                                  }
                                  break;
                          default:
                                  return -400;
                                  break;
            }
            return mve;
        }
        
        
        
        void setdirections()
        {
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
             {
             uu=playerid; // Assuming a random head of player 'Z' for coding reasons
             uul=playerid;
             uur=playerid;
             }
             else
             {
             uu=getdata(hdposy+2,hdposx);
             uul=getdata(hdposy+2,hdposx-1);
             uur=getdata(hdposy+2,hdposx+1);
             }
             if(d==FENCE)
             {
             dd=playerid; // Assuming a random head of player 'Z' for coding reasons
             ddl=playerid; // Assuming a random head of player 'Z' for coding reasons
             ddr=playerid; // Assuming a random head of player 'Z' for coding reasons
             }
             else
             {
             dd=getdata(hdposy-2,hdposx);
             ddl=getdata(hdposy-2,hdposx-1);
             ddr=getdata(hdposy-2,hdposx+1);
             }
             if(l==FENCE)
             {
             ll=playerid; // Assuming a random head of player 'Z' for coding reasons
             llu=playerid; // Assuming a random head of player 'Z' for coding reasons
             lld=playerid; // Assuming a random head of player 'Z' for coding reasons
             }
             else
             {
             ll=getdata(hdposy,hdposx-2);
             llu=getdata(hdposy+1,hdposx-2);
             lld=getdata(hdposy-1,hdposx-2);
             }
             if(r==FENCE)
             {
             rr=playerid; // Assuming a random head of player 'Z' for coding reasons
             rru=playerid; // Assuming a random head of player 'Z' for coding reasons
             rrd=playerid; // Assuming a random head of player 'Z' for coding reasons
             }
             else
             {
             rr=getdata(hdposy,hdposx+2);
             rru=getdata(hdposy+1,hdposx+2);
             rrd=getdata(hdposy-1,hdposx+2);
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
             setdirections();
             mve=-400;
             /*
             int j1=rand()%4;
             
             if(j1==1)
             mve=any_dir();             
             printf("mve any dir : %d \n",mve);
             if(mve!=-400)
             return mve; 
             
             else if(j1==2)
             */
             mve=cont();
             if(mve!=-400)
             {
                 mve=headon(mve);   
                 return mve;
             }
             
             mve=-400;
             mve=chk_fen(); // if player reaches any corners of board then 2 dir. 
                            // are fenced one opp dir. is not possible to make and hence only one dir. is possible
                            // chk_fen find that single dir
             if(mve!=-400)
             {
                 mve=headon(mve);   
                 return mve;
             }
             mve=-400;
             mve=line_chk();
             if(mve!=-400)
             {
               mve=chk_fen3(mve);
             if(mve!=-400)
             {
                 mve=headon(mve);   
                 return mve;
             }
             }
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
