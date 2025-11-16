init_c=6000
scrap=c(3000,1500,750,374,200,200)
mc=c(1000,1200,1400,1800,2300,2800)
tot=init_c-scrap+cumsum(mc)
avg=tot/(1:length(tot))
min(avg)
which.min(avg)



ini_cost=6000
scrap=c(3000,1500,750,375,200,200)
main.cost=c(1000,1200,1400,1800,2300,2800)
total=ini_cost-scrap+cumsum(main.cost)
avg_cost=total/(1:length(total))
optimal_year=which.min(avg_cost)
optimal_year
cat("average cost Rs. ",avg_cost[optimal_year])

i=9000
s=200
mc=c(200,2200,4200,6200,8200,10200)
tot=i-s+cumsum(mc)
tot
avg_tot=tot/(1:length(tot))
avg_tot

i=10000
s=400
mc=c(400,1200,2000,2800,3600,4400,5200,6000,6800)
tot=i-s+cumsum(mc)
tot
avg_tot=tot/(1:length(tot))
avg_tot

