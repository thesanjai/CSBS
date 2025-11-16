lam=12/60
mu=1/6
s=2

rho=lam/(s*mu)

sum=0
fact=1
for(n in 0:(s-1)){
  sum=sum+ (((s*rho)^n)/fact)
  fact=fact*n+1
}
p0=sum+ (((s*rho)^s)/(factorial(s)*(1-rho)))
p0=1/p0

ps=((lam/mu)^s)*(p0/factorial(s))
ps
lq=ps* ((rho)/((1-rho)^2))

ls=lq+ (lam/mu)

ws=ls/lam
wq=lq/lam

rho
p0
ps
ls
lq
ws
wq

