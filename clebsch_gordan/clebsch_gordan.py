from sympy import S
from sympy.physics.quantum.cg import CG
import argparse
from datetime import datetime

parser = argparse.ArgumentParser()
parser.add_argument('-s','--symbolic',help='parameter (j and ms) will be printed in symbol format',action='store_true')
parser.add_argument('-i','--integral',help='only deals with integral j values',action='store_true')
                           
args = parser.parse_args()

max_j1 = int(2*float(input('Maximal value of j1 : ')) + 1e-9)

f = open('cg_{0:.1f}_{1:}.cgdata'.format(max_j1/2,datetime.now().strftime('%d_%b_%Y_%H:%M:%S')),'w')
f.write('#Clebsch-gordan database for DOGOQ\n')
f.write('#Maximum j1-value is {0:.1f}\n'.format(max_j1/2))
f.write('#Symbolic representation : {}, Integral-only : {}\n'.format(args.symbolic,args.integral))
f.write('#Only nonzero values are presented\n')

step = 1
if args.integral:
    step = 2

for j1 in range(0, max_j1 + 1, step):
    for m1 in range(-j1, j1+1, 2):
        for j2 in range(0, j1+1, step):
            for m2 in range(-j2, j2+1, 2):
                for J in range(j1-j2, j1+j2+1, 2):
                    #for M in range(-J, J+1, 2):
                    M = m1 + m2
                    res = CG(S(j1)/2,S(m1)/2,S(j2)/2,S(m2)/2,S(J)/2,S(M)/2).doit()
                    if res == S(0):
                        continue
                    if args.symbolic:
                        f.write('{0:}\t{1:\t{2:}\t{3:}\t{4:}\t{5:}\t{6:}\n'.format(S(j1)/2,S(m1)/2,S(j2)/2,S(m2)/2,S(J)/2,S(M)/2,res))
                    elif args.integral:
                        f.write('{0:}\t{1:}\t{2:}\t{3:}\t{4:}\t{5:}\t{6:}\n'.format((j1)//2,(m1)//2,(j2)//2,(m2)//2,(J)//2,(M)//2,res.evalf()))
                    else:
                        f.write('{0:.1f}\t{1:.1f}\t{2:.1f}\t{3:.1f}\t{4:.1f}\t{5:.1f}\t{6:}\n'.format((j1)/2,(m1)/2,(j2)/2,(m2)/2,(J)/2,(M)/2,res.evalf()))

f.close()
print('dogoq: success: \"Cha Jae-hyeon Huo-guo countable refill\", Wayne Kim (2019)\n')
