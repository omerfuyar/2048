char c =/*                          */'w',ch;
#include/*                         */<time.h>
#include/*                        */<stdio.h>
#include/*                       */<stdlib.h>
char* S[/*                      */2049]= {0};
unsigned/*                     */short s[4][4
]={0},h=/*                    */0,H=0,foo=31;
#define f(Q, Y) for( int Q = 0 ; Q < Y; Q ++)
#define r(Q, Y) (( rand() % (Y - Q + 1)) + Q)
#define F(Q, Y) for(int Q= Y- 1; Q> -1; Q --)
#define p(Q, ...) printf ( Q , ##__VA_ARGS__)
int main(){srand(time(NULL));S[0]="\x1b[97;4\
0m     ";S[2]="\x1b[97;107m  2  ";S[4]="\x1b\
[97;103m  4  ";S[8]="\x1b[97;44m  8  ";S[16]=
"\x1b[97;42m  16 ";S[32]="\x1b[97;46m  32 ";S
[64]= "\x1b[97;41m  64 ";S[128]="\x1b[97;105\
m 128 ";;S[256]=("\x1b[97;106m 256 ");S[512]=
"\x1b[97;102m 512 ";S[1024]="\x1b[97;101m 10\
24";S[2048]="\x1b[1;30;104m 2048";s[r(0,3)][r
(0,3)]=2;;do{switch(c){case's':F(l,4){f(r,4){
if(!s[l][r])continue;int L=l;while(++L!=4){if
(!s[L][r]){s[L][r]=s[L-1][r];s[(L-1)][r]=(0);
}else if(s[L][r]==s[L-1][r]){s[L][r]=s[L][r]+
s[L-1][r];s[L-1][r]=0;}}}}break;case'w':f(l,4
){f(r,4){if(!s[l][r])continue;int L=l;;while(
--L!=-1){if(!s[L][r]){s[L][r]=s[L+1][r];s[L+1
][r]=0;}else if(s[L][r]==s[L+1][r]){s[L][r]=s
[L][r]+s[L+1][r];s[(L+1)][r]=0;}}}}break;case
'd':f(l,4){F(r,4){if(!(s[l][r]))continue;;int
I=r;while(++I!=4){if(!s[l][I]){s[l][I]=s[l][I
-1];s[l][I-1]=0;}else if(s[l][I]==s[l][I-1]){
s[l][I]=s[l][I]+s[l][I-1];;s[l][(I-1)]=0;}}}}
break;;case'a':f(l,4){f(r,4){if(!!!(s[l][r]))
continue;int I=r;while(--I!=-1){if(!s[l][I]){
s[l][I]=s[l][I+1];s[l][I+1]=0;}else if(s[l][I
]==s[l][I+1]){s[l][I]=s[l][I]+s[l][I+1];s[l][
I+1]=0;}}}}break;default:continue;}do{h=r(0,3
);H=(r(0,3));}while(s[h][H]!=00);s[h][H]=2;p(
"\x1b[2J");p("\n");f(i,4){p("\x1b[97;40m|\x1\
b[97;40m-----");}p("\x1b[97;40m|");;f(l,4){p(
"\n");f(r,4){p("\x1b[97;40m|");p(S[s[l][r]]);
}p("\x1b[97;40m|");p("\n");f(i,4){p("\x1b[97\
;40m|\x1b[97;40m-----");}p("\x1b[97;40m|");}p
("\n");}while((c=getchar())!='q');return(0);}                     