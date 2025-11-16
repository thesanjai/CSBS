library(lpSolve)
obj=c(10,15)
mat=matrix(c(2,1,
           2,4,
           -1,1),nrow=3,byrow=TRUE)
cons=c("<=","<=","<=")
rhs<- c(26,56,5)

A_var = ncol(mat)

obj_1=c(rep(0,length(obj)),rep(1,A_var))

lp_soln_1=lp("max",obj_1,mat,cons,rhs)

if(lp_soln_1 !=0){
  cat("no soln found")
}else{
  cat("soln found")
}

obj_2=obj

mat=mat[,1:length(obj)]


lp_soln2 =lp("max",obj_2,mat,cons,rhs)

lp_soln2$objval









#----------------------------------------------------------------------------------
obj=c(5,8)
mat=matrix(c(3,2,
             1,4,
             1,1),nrow=3,byrow=TRUE)
cons=c(">=",">=","<=")
rhs=c(3,4,5)
library(lpSolve)

A1=ncol(mat)
A2=ncol(mat)

obj_1=c(rep(0,length(obj)),rep(1,A1),rep(1,A2))
soln1=lp("max",obj_1,mat,cons,rhs)

if(soln1$status==0){
  print("soln found in phase 1")
  
}else{
  print("soln not found in phase 1")
}


mat=mat[,1:length(obj)]


soln2=lp("max",obj,mat,cons,rhs)

soln2$objval
soln2

