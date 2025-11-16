library(lpSolve)
assign.costs=matrix(c(11,8,9,14,10,6,6,11,7),3,3,byrow=TRUE)
Assign.costs
lp.assign(assign.costs)
lp.assign(assign.costs)$solution



library(lpSolve)
cm=matrix(0,nrow=3,ncol=3)
cm[1,1]=2
cm[1,2]=2
cm[1,3]=3
cm[2,1]=4
cm[2,2]=1
cm[2,3]=2
cm[3,1]=1
cm[3,2]=3
cm[3,3]=1
print("cost matrix")
print(cm)
row_signs=rep("<=",3)
row_rhs=c(10,15,40)
col_signs=rep(">=",3)
col_rhs=c(20,15,30)
lp_solution=lp.transport(cm,"min",row_signs,row_rhs,col_signs,col_rhs)
print("optimal transportation matrix")
print(lp_solution$solution)
print(paste("total cost:",lp_solution$objval))