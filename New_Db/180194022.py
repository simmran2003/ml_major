"""2022.11.09 20:53:34 JST"""
import sys
from functools import partial, reduce, lru_cache
from itertools import groupby, islice, tee, zip_longest


def main():
    class S:
        def __init__(self, s):
            self.s = s

        def __lt__(self, other):
            return self.s + other.s < other.s + self.s

    N = int(readline())
    A = [S(readline().rstrip()) for _ in range(N)]
    A.sort()
    print(concat(a.s for a in A))


# @formatter:off
"+-+-+-+ Constants +-+-+-+"
MOD = 10 ** 9 + 7
# MOD = 998_244_353
INF = (1 << 62) - 1
"+-+-+-+ Settings +-+-+-+"
# sys.setrecursionlimit(10 ** 6)
# if "pypyjit" in sys.builtin_module_names:import pypyjit;pypyjit.set_param("max_unroll_recursion=-1");
use_buffer_read = False
"+-+-+-+ Libraries +-+-+-+"

"+-+-+-+ Memorize +-+-+-+"
_imm={}
"+-+-+-+ Print +-+-+-+"
printd=partial(print,file=sys.stderr,flush=True)
printd_nospace=partial(print,sep='',file=sys.stderr,flush=True)
printd_line=partial(print,sep='\n',file=sys.stderr,flush=True)
printd_mat=lambda mat:[print(*v,file=sys.stderr,flush=True) for v in mat]
print_nospace=partial(print,sep='')
print_line=partial(print,sep='\n')
print_mat=lambda mat:[print(*v) for v in mat]
"+-+-+-+ Math +-+-+-+"
aseq_sum1=lambda a1,d,n:n*(2*a1+(n-1)*d)//2
aseq_sum2=lambda a1,an,n:n*(a1+an)//2
aseq_msum1=lambda a1,d,n:(n*(2*a1+(n-1)*d)*invmod(2))%MOD
aseq_msum2=lambda a1,an,n:(n*(a1+an)*invmod(2)) % MOD
gseq_sum=lambda a,r,n:a*(pow(r,n)-1)//(r-1) if r!=1 else a*n
gseq_msum=lambda a,r,n:a*(pow(r,n,MOD)-1)*invmod(r-1)%MOD if r!=1 else a*n%MOD
divceil=lambda x,y:(x+y-1)//y
invmod=lambda x:_imm.setdefault(x,pow(x,MOD-2,MOD))
powmod=partial(pow,mod=MOD)
"+-+-+-+ Iter +-+-+-+"
crange=lambda *args:range(args[0]+1) if len(args)==1 else range(args[0],args[1]+1,1 if len(args)==2 else args[2])
rrange=lambda *args:reversed(range(*args))
__de_Bruijn_sequence=[0,1,28,2,29,14,24,3,30,22,20,15,25,17,4,8,31,27,13,23,21,19,16,7,26,12,18,6,11,5,10,9]
def get_allbit32(x):
    while x:yield __de_Bruijn_sequence[(((x & -x) * 0x077CB531) >> 27) & 31];x = x & x - 1
"+-+-+-+ List +-+-+-+"
cst2l=lambda first,second,initial=0:[[initial]*second for _ in range(first)]
copy2l=lambda L:[r[:] for r in L]
"+-+-+-+ String +-+-+-+"
concat=lambda L,sep='':sep.join(L)
ston=lambda S,a=0:[(ord(c)|32)-(97-a) for c in S]
"+-+-+-+ Algorithms +-+-+-+"
ccomp=lambda A:{x:i for i,x in enumerate(sorted(set(A)))}
invert=lambda A,start=0:dict(zip(A,range(start,len(A)+start)))
lpartion = lambda L,b:[L[i:i+b] for i in range(0,len(L),b)]
nwise=lambda n,A:zip(*(islice(it,s,None) for it,s in zip(tee(A,n),range(n))))
runlength=lambda A:[[k,len(list(g))] for k,g in groupby(A)]
__c1=0x5555555555555555;__c2=0x3333333333333333;__c3=0xf0f0f0f0f0f0f0f;__c4=0xff00ff00ff00ff;__c5=0xffff0000ffff;__c6=0xffffffff;
def popcount(n):c=(n&__c1)+((n>>1)&__c1);c=(c&__c2)+((c>>2)&__c2);c=(c&__c3)+((c>>4)&__c3);c=(c&__c4)+((c>>8)&__c4);c=(c&__c5)+((c>>16)&__c5);c=(c&__c6)+((c>>32)&__c6);return c
"+-+-+-+ Read +-+-+-+"
__file=open(0)
read=__file.buffer.read if use_buffer_read else __file.read
readline=__file.buffer.readline if use_buffer_read else __file.readline
readlines=__file.buffer.readlines if use_buffer_read else __file.readlines
"+-+-+-+ Run +-+-+-+"
main()
# @formatter:on
