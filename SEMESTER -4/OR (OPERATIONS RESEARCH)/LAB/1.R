library(lpSolve)
obj=c(-1,2)
mat=matrix(c(-1,3,
             1,1,
             1,-1),nrow=3,byrow=TRUE)
cons=c(rep("<=",3))
rhs=c(10,6,2)
lp_soln=lp("min",obj,mat,cons,rhs)
lp_soln
lp_soln$solution
lp_soln$objval
 min_pt=data.frame(x=lp_soln$solution[1],y=lp_soln$solution[2])


library(ggplot2)


feasible_region=data.frame(x=c(0,0,2,4,2),y=c(0,(10/3),4,2,0))
f1=function(x) ((10+x)/3)
f2=function(x) (6-x)
f3=function(x) (x-2)

ggplot(data=data.frame(x=0,y=0),aes(x=x,y=y))+
  geom_vline(xintercept = 0)+
  geom_hline(yintercept = 0)+
  scale_x_continuous(breaks = seq(0,10,1),lim=c(0,10))+
  scale_y_continuous(breaks= seq(0,10,1),limits=c(0,10))+
  stat_function(colour="red",fun=f1)+
  stat_function(colour="red",fun=f2)+
  stat_function(colour="red",fun=f3)+
  geom_polygon(data=feasible_region,fill="lightblue")+
  geom_point(data=feasible_region)+
  geom_point(data=min_pt,size=5,color="yellow")

#-------------------------------------------------------------------------------------------------------------

library(lpSolve)
library(ggplot2)

obj=c(2,3)
mat=matrix(c(1,1,
             1,-1,
             0,1,
             1,0,
             0,1),nrow=5,byrow=TRUE)
cons=c("<=",">=",">=","<=","<=")
rhs=c(30,0,3,20,12)

lp_soln=lp("max",obj,mat,cons,rhs)
lp_soln
lp_soln$solution
max_pt=data.frame(x=lp_soln$solution[1],y=lp_soln$solution[2])

f1=function(x) (30-x)
f2=function(x) (x)
f3=function(x) (3)
f4=function(x) (12)

FR=data.frame(x=c(3,12,18,20,20),y=c(3,12,12,10,3))

ggplot(data=data.frame(x=0,y=0),aes(x=x,y=y))+
  geom_vline(xintercept=0)+
  geom_hline(yintercept=0)+
  scale_x_continuous(breaks=waiver(),lim=NULL)+
  scale_y_continuous(breaks=waiver(),lim=NULL)+
  stat_function(colour="red",fun=f1)+
  stat_function(colour="red",fun=f2)+
  stat_function(colour="red",fun=f3)+
  stat_function(colour="red",fun=f4)+
  geom_vline(xintercept = 20)+
  geom_polygon(data=FR,fill="lightblue")+
  geom_point(data=FR)+
  geom_point(data=max_pt,size=6,color="purple")

