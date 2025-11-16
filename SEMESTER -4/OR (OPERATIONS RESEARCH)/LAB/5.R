obj=c(3,2)
mat=matrix(c(-1,-1,
             1,1,
             1,2,
             0,1),nrow=4,byrow=TRUE)
cons=c(rep("<=",4))
rhs=c(-1,7,10,3)

p_soln=lp("max",obj,mat,cons,rhs)

p_soln$solution
p_soln

mat=matrix(c(-1,1,1,0,
             -1,1,2,1),nrow=2,byrow=TRUE)
cons=c(rep(">=",2))
d_soln=lp("min",rhs,mat,cons,obj)

d_soln$solution
d_soln