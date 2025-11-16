library(lpSolve)

M=1000
obj=c(5,3,0,0,0,-M)
mat=matrix(c(2,4,1,0,0,0,2,2,0,1,0,0,5,2,0,0,-1,1),nrow=3,byrow=TRUE)
cons=c("<=","<=",">=")
rhs=c(2,12,0)
lp("max",obj,mat,cons,rhs)



#------------------------------------------------------------
M=1000
obj=c(5,8,0,0,0,-M,-M)
mat=matrix(c(3,2,-1,0,0,1,0,
             1,4,0,-1,0,0,1,
             1,1,0,0,1,0,0),nrow=3,byrow=TRUE)
cons=c(">=",">=","<=")
rhs=c(3,4,5)
library(lpSolve)
lp("max",obj,mat,cons,rhs)