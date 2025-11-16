obj=c(8,-2)
s1=c(-4,2)
s2=c(5,-4)
r1=1
r2=3

library(boot)
simplex(a=obj,
        A1=rbind(s1,s2),
        b1=c(r1,r2),maxi=F)


#z= -x1+2x2 (min)
#stc
#-x1+3x2<=10
#x1+x2<=6
#x1-x2<=2

obj=c(1,-2)
stc1=c(-1,3)
stc2=c(1,1)
stc3=c(1,-1)
rhs1=10
rhs2=6
rhs3=2

library(boot)

temp=simplex(a=obj,
             A1=rbind(stc1,stc2,stc3),
             b1=c(rhs1,rhs2,rhs3),maxi=T)

temp
temp =-temp$value

temp