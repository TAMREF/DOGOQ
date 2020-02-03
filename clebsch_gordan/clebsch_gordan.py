from sympy import S
from sympy.physics.quantum.cg import CG
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-s','--symbolic',help='parameter (j and ms) will be printed in symbol format',action='store_true')
parser.add_argument('-i','--integral',help='only deals with integral j values',action='store_true')

args = parser.parse_args()

max_j1 = int(2*float(input('Maximal value of j1 : ')) + 1e-9)

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
                    if args.symbolic:
                        print(S(j1)/2,S(m1)/2,S(j2)/2,S(m2)/2,S(J)/2,S(M)/2,CG(S(j1)/2,S(m1)/2,S(j2)/2,S(m2)/2,S(J)/2,S(M)/2).doit())
                    elif args.integral:
                        print((j1)//2,(m1)//2,(j2)//2,(m2)//2,(J)//2,(M)//2,CG(S(j1)/2,S(m1)/2,S(j2)/2,S(m2)/2,S(J)/2,S(M)/2).doit())
                    else:
                        print((j1)/2,(m1)/2,(j2)/2,(m2)/2,(J)/2,(M)/2,CG(S(j1)/2,S(m1)/2,S(j2)/2,S(m2)/2,S(J)/2,S(M)/2).doit())
